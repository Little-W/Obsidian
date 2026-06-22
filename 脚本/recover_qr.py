from __future__ import annotations

import argparse
import base64
import ctypes
import os
import queue
import threading
import time
import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext, ttk

import cv2
import numpy as np

try:
    import zxingcpp
except Exception:
    zxingcpp = None


VIDEO = "vnc.mp4"
OUTPUT = "changes.7z"
DEFAULT_RECORDING = "screen_record.mp4"
DEFAULT_FPS = 5.0
DEFAULT_LIVE_INTERVAL = 0.12

try:
    import mss
except Exception:
    mss = None


def create_mss_instance():
    if mss is None:
        return None

    mss_factory = getattr(mss, "MSS", None)
    if mss_factory is None:
        mss_factory = getattr(mss, "mss")
    return mss_factory()


def log_print(message: str) -> None:
    print(message)


def list_available_monitors() -> list[tuple[int | None, str]]:
    if mss is not None:
        with create_mss_instance() as screenshotter:
            items = [(0, "全部屏幕")]
            for monitor_index, monitor in enumerate(screenshotter.monitors[1:], start=1):
                width = monitor.get("width", 0)
                height = monitor.get("height", 0)
                left = monitor.get("left", 0)
                top = monitor.get("top", 0)
                items.append((monitor_index, f"屏幕 {monitor_index} ({width}x{height} @ {left},{top})"))
            return items

    if os.name == "nt":
        return [(None, "主屏幕（安装 mss 后可选择其他屏幕）")]

    return [(None, "当前屏幕")]


class ScreenCaptureSource:
    def __init__(self, monitor_index: int | None = None) -> None:
        self.monitor_index = monitor_index
        self._mss = None
        self._monitor = None
        self._backend = None

        if mss is not None:
            self._mss = create_mss_instance()
            self._backend = "mss"
            if monitor_index is None:
                self._monitor = self._mss.monitors[1]
            else:
                if monitor_index < 0 or monitor_index >= len(self._mss.monitors):
                    self.close()
                    raise RuntimeError(f"无效的屏幕索引: {monitor_index}")
                self._monitor = self._mss.monitors[monitor_index]
            return

        if os.name != "nt":
            raise RuntimeError("当前录屏实现仅支持 Windows，或安装 mss 后再试")

        self._backend = "gdi"
        self._user32 = ctypes.windll.user32
        self._gdi32 = ctypes.windll.gdi32
        self._srccopy = 0x00CC0020

        self._width = self._user32.GetSystemMetrics(0)
        self._height = self._user32.GetSystemMetrics(1)
        self._screen_dc = self._user32.GetDC(0)
        self._memory_dc = self._gdi32.CreateCompatibleDC(self._screen_dc)
        self._bitmap = self._gdi32.CreateCompatibleBitmap(self._screen_dc, self._width, self._height)
        self._old_bitmap = self._gdi32.SelectObject(self._memory_dc, self._bitmap)
        self._buffer_size = self._width * self._height * 4
        self._buffer = ctypes.create_string_buffer(self._buffer_size)

    def grab(self) -> np.ndarray:
        if self._backend == "mss":
            image = np.array(self._mss.grab(self._monitor))
            return cv2.cvtColor(image, cv2.COLOR_BGRA2BGR)

        if self._backend != "gdi":
            raise RuntimeError("录屏源未初始化")

        if not self._gdi32.BitBlt(self._memory_dc, 0, 0, self._width, self._height, self._screen_dc, 0, 0, self._srccopy):
            raise RuntimeError("屏幕拷贝失败")

        copied = self._gdi32.GetBitmapBits(self._bitmap, self._buffer_size, self._buffer)
        if copied <= 0:
            raise RuntimeError("读取屏幕像素失败")

        frame = np.frombuffer(self._buffer, dtype=np.uint8).reshape((self._height, self._width, 4))
        return cv2.cvtColor(frame, cv2.COLOR_BGRA2BGR)

    def close(self) -> None:
        if self._backend == "mss" and self._mss is not None:
            close_method = getattr(self._mss, "close", None)
            if callable(close_method):
                close_method()
            self._mss = None
            self._monitor = None
            return

        if self._backend == "gdi":
            if getattr(self, "_gdi32", None) is not None:
                self._gdi32.SelectObject(self._memory_dc, self._old_bitmap)
                self._gdi32.DeleteObject(self._bitmap)
                self._gdi32.DeleteDC(self._memory_dc)
                self._user32.ReleaseDC(0, self._screen_dc)

            self._backend = None


def capture_screen_frame(monitor_index: int | None = None) -> np.ndarray:
    source = ScreenCaptureSource(monitor_index)
    try:
        return source.grab()
    finally:
        source.close()


def _normalize_qr_payload(data: str) -> tuple[int, int, str] | None:
    try:
        header, payload = data.split(":", 1)
        idx_text, total_text = header.split("/")
        idx = int(idx_text)
        total = int(total_text)
    except Exception:
        return None

    return idx, total, payload


def _qr_candidate_images(frame: np.ndarray) -> list[np.ndarray]:
    candidates: list[np.ndarray] = []
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    _, dark_mask = cv2.threshold(gray, 115, 255, cv2.THRESH_BINARY_INV)
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
    dark_mask = cv2.morphologyEx(dark_mask, cv2.MORPH_OPEN, kernel)

    contours, _ = cv2.findContours(dark_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    height, width = gray.shape[:2]
    frame_area = height * width

    boxes: list[tuple[int, int, int, int]] = []
    for contour in contours:
        x, y, w, h = cv2.boundingRect(contour)
        area = w * h
        if area < frame_area * 0.03:
            continue
        if w < 120 or h < 120:
            continue
        if w / h > 3.0 or h / w > 3.0:
            continue
        boxes.append((x, y, w, h))

    boxes.sort(key=lambda box: box[2] * box[3], reverse=True)
    for x, y, w, h in boxes[:4]:
        for pad_ratio in (0.01, 0.04, 0.08, 0.14):
            pad = int(max(w, h) * pad_ratio)
            x1 = max(0, x - pad)
            y1 = max(0, y - pad)
            x2 = min(width, x + w + pad)
            y2 = min(height, y + h + pad)
            crop = frame[y1:y2, x1:x2]
            if crop.size:
                candidates.append(crop)

    return candidates


def _decode_qr_variants(detector: cv2.QRCodeDetector, frame: np.ndarray) -> list[str]:
    """
    尝试对一帧进行多种方式解码，返回所有二维码内容，去重。
    """
    decoded_payloads: list[str] = []
    seen_payloads: set[str] = set()

    def _collect(decoded_text: str | None) -> None:
        if decoded_text and decoded_text not in seen_payloads:
            seen_payloads.add(decoded_text)
            decoded_payloads.append(decoded_text)

    def _try_image(image: np.ndarray) -> None:
        data, _, _ = detector.detectAndDecode(image)
        _collect(data)

        try:
            ok, decoded_infos, _, _ = detector.detectAndDecodeMulti(image)
            if ok and decoded_infos is not None:
                for item in decoded_infos:
                    if isinstance(item, str):
                        _collect(item)
        except Exception:
            pass

    _try_image(frame)
    if decoded_payloads:
        return decoded_payloads

    for candidate in _qr_candidate_images(frame):
        _try_image(candidate)
        if decoded_payloads:
            return decoded_payloads

        gray = cv2.cvtColor(candidate, cv2.COLOR_BGR2GRAY)
        gray_variants = [gray]

        for threshold in (95, 115, 135, 160, 190):
            _, binary = cv2.threshold(gray, threshold, 255, cv2.THRESH_BINARY)
            gray_variants.append(binary)

        try:
            adaptive = cv2.adaptiveThreshold(
                gray,
                255,
                cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                cv2.THRESH_BINARY,
                31,
                3,
            )
            gray_variants.append(adaptive)
        except Exception:
            pass

        for gray_image in gray_variants:
            for border in (0, 24, 64, 120):
                bordered = cv2.copyMakeBorder(
                    gray_image,
                    border,
                    border,
                    border,
                    border,
                    cv2.BORDER_CONSTANT,
                    value=255,
                )
                for scale in (0.75, 1.0, 1.25, 1.5, 2.0):
                    resized = cv2.resize(
                        bordered,
                        None,
                        fx=scale,
                        fy=scale,
                        interpolation=cv2.INTER_NEAREST,
                    )
                    _try_image(cv2.cvtColor(resized, cv2.COLOR_GRAY2BGR))
                    if decoded_payloads:
                        return decoded_payloads

    return decoded_payloads

    # 1. 原始彩色
    data, _, _ = detector.detectAndDecode(frame)
    _collect(data)

    # 2. 多二维码检测
    try:
        ok, decoded_infos, _, _ = detector.detectAndDecodeMulti(frame)
        if ok and decoded_infos is not None:
            for item in decoded_infos:
                if isinstance(item, str):
                    _collect(item)
    except Exception:
        pass

    # 3. 灰度 + 放大
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    resized = cv2.resize(gray, None, fx=2.0, fy=2.0, interpolation=cv2.INTER_LINEAR)
    data, _, _ = detector.detectAndDecode(cv2.cvtColor(resized, cv2.COLOR_GRAY2BGR))
    _collect(data)

    try:
        ok, decoded_infos, _, _ = detector.detectAndDecodeMulti(cv2.cvtColor(resized, cv2.COLOR_GRAY2BGR))
        if ok and decoded_infos is not None:
            for item in decoded_infos:
                if isinstance(item, str):
                    _collect(item)
    except Exception:
        pass

    return decoded_payloads

def _largest_run(indices: np.ndarray) -> tuple[int, int] | None:
    if indices.size == 0:
        return None

    best_start = start = previous = int(indices[0])
    best_end = int(indices[0])
    for value in indices[1:]:
        current = int(value)
        if current == previous + 1:
            previous = current
            continue

        if previous - start > best_end - best_start:
            best_start, best_end = start, previous
        start = previous = current

    if previous - start > best_end - best_start:
        best_start, best_end = start, previous

    return best_start, best_end


def _crop_qr_region(frame: np.ndarray) -> np.ndarray | None:
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    dark_mask = gray < 140
    height, width = gray.shape[:2]

    rows = np.where(dark_mask.sum(axis=1) > width * 0.03)[0]
    cols = np.where(dark_mask.sum(axis=0) > height * 0.03)[0]
    row_run = _largest_run(rows)
    col_run = _largest_run(cols)
    if row_run is None or col_run is None:
        return None

    y1, y2 = row_run
    x1, x2 = col_run
    if (x2 - x1) < 120 or (y2 - y1) < 120:
        return None

    pad = int(max(x2 - x1, y2 - y1) * 0.03) + 8
    return frame[
        max(0, y1 - pad) : min(height, y2 + pad + 1),
        max(0, x1 - pad) : min(width, x2 + pad + 1),
    ]


def _decode_qr_frame(detector: cv2.QRCodeDetector, frame: np.ndarray) -> list[str]:
    decoded: list[str] = []
    seen: set[str] = set()

    def collect(text: str | None) -> None:
        if text and text not in seen:
            seen.add(text)
            decoded.append(text)

    images = [frame]
    crop = _crop_qr_region(frame)
    if crop is not None:
        images.insert(0, crop)

    for image in images:
        if zxingcpp is not None:
            for result in zxingcpp.read_barcodes(image):
                collect(result.text)
            if decoded:
                return decoded

        data, _, _ = detector.detectAndDecode(image)
        collect(data)
        if decoded:
            return decoded

    return decoded


def _write_missing_list(missing: list[int], missing_list_path: str, log=log_print) -> str:
    with open(missing_list_path, "w", encoding="utf-8") as file_handle:
        for idx in missing:
            file_handle.write(f"{idx}\n")

    log(f"[*] Missing list saved: {missing_list_path}")
    return missing_list_path


def _write_recovered_payload(
    frames: dict[int, str],
    total_frames: int,
    output_path: str,
    missing_list_path: str = "missing_frames.txt",
    log=log_print,
) -> str:
    missing = [i for i in range(1, total_frames + 1) if i not in frames]
    if missing:
        log("")
        log("Missing frames:")
        log(str(missing))
        _write_missing_list(missing, missing_list_path, log=log)
        raise RuntimeError("Missing frames, cannot recover complete data")

    log("")
    log("[*] All frames recovered")

    all_b64 = "".join(frames[i] for i in range(1, total_frames + 1))
    all_b64 = all_b64.rstrip("_")
    binary = base64.b64decode(all_b64)

    with open(output_path, "wb") as file_handle:
        file_handle.write(binary)

    log("")
    log(f"[*] Saved: {output_path}")
    return output_path


def recover_qr_from_video(
    video_path: str,
    output_path: str,
    missing_list_path: str = "missing_frames.txt",
    progress_callback=None,
    log=log_print,
) -> str:
    detector = cv2.QRCodeDetector()
    cap = cv2.VideoCapture(video_path)

    if not cap.isOpened():
        raise RuntimeError(f"无法打开视频: {video_path}")

    frames = {}
    total_frames = None
    read_frames = 0

    while True:
        ret, frame = cap.read()
        if not ret:
            break
        read_frames += 1

        for data in _decode_qr_frame(detector, frame):
            parsed = _normalize_qr_payload(data)
            if parsed is None:
                continue

            idx, total, payload = parsed

            if total_frames is None:
                total_frames = total
            elif total_frames != total:
                raise RuntimeError(f"二维码总帧数不一致: {total_frames} vs {total}")

            if idx not in frames:
                frames[idx] = payload
                log(f"[+] Frame {idx}/{total}")
                if progress_callback is not None:
                    progress_callback(total, set(frames))

            if total_frames is not None and len(frames) >= total_frames:
                break

        if total_frames is not None and len(frames) >= total_frames:
            break

    cap.release()

    log("")
    log(f"Recovered: {len(frames)}")

    if total_frames:
        log(f"Expected : {total_frames}")
        missing = [i for i in range(1, total_frames + 1) if i not in frames]
        if missing:
            log("Missing frames:")
            log(str(missing))
            _write_missing_list(missing, missing_list_path, log=log)

    if read_frames == 0:
        raise RuntimeError(
            "视频已打开但没有读到任何画面帧，请换用可被 OpenCV 解码的视频格式/编码后再试"
        )

    if not total_frames:
        raise RuntimeError("没有从视频中识别到任何二维码帧")

    missing = [i for i in range(1, total_frames + 1) if i not in frames]
    if missing:
        log("")
        log("Missing frames:")
        log(str(missing))
        raise RuntimeError("存在缺失帧，无法恢复完整数据")

    log("")
    log("[*] All frames recovered")

    all_b64 = "".join(frames[i] for i in range(1, total_frames + 1))
    all_b64 = all_b64.rstrip("_")
    binary = base64.b64decode(all_b64)

    with open(output_path, "wb") as file_handle:
        file_handle.write(binary)

    log("")
    log(f"[*] Saved: {output_path}")
    return output_path


def recover_qr_from_screen(
    output_path: str,
    monitor_index: int | None = None,
    interval: float = DEFAULT_LIVE_INTERVAL,
    stop_event: threading.Event | None = None,
    missing_list_path: str = "missing_frames.txt",
    progress_callback=None,
    log=log_print,
) -> str:
    detector = cv2.QRCodeDetector()
    frames: dict[int, str] = {}
    total_frames = None
    interval = max(float(interval), 0.03)
    source = ScreenCaptureSource(monitor_index)

    try:
        log("[*] Live screen decoding started")
        while stop_event is None or not stop_event.is_set():
            loop_started = time.perf_counter()
            frame = source.grab()

            for data in _decode_qr_frame(detector, frame):
                parsed = _normalize_qr_payload(data)
                if parsed is None:
                    continue

                idx, total, payload = parsed
                if total_frames is None:
                    total_frames = total
                    log(f"[*] Expected frames: {total_frames}")
                elif total_frames != total:
                    raise RuntimeError(f"浜岀淮鐮佹€诲抚鏁颁笉涓€鑷? {total_frames} vs {total}")

                if idx not in frames:
                    frames[idx] = payload
                    log(f"[+] Frame {idx}/{total}")
                    if progress_callback is not None:
                        progress_callback(total, set(frames))

                if total_frames is not None and len(frames) >= total_frames:
                    return _write_recovered_payload(frames, total_frames, output_path, missing_list_path, log=log)

            sleep_time = interval - (time.perf_counter() - loop_started)
            if sleep_time > 0:
                time.sleep(sleep_time)
    finally:
        source.close()

    log("")
    log(f"Recovered: {len(frames)}")
    if total_frames:
        log(f"Expected : {total_frames}")
    raise RuntimeError("实时解码已停止，尚未收齐全部二维码帧")


class ScreenRecorder:
    def __init__(self, output_path: str, fps: float, monitor_index: int | None = None, log=log_print) -> None:
        self.output_path = output_path
        self.fps = max(float(fps), 1.0)
        self.monitor_index = monitor_index
        self.log = log
        self._stop_event = threading.Event()
        self._thread = None
        self._error = None
        self._capture_source = None

    @property
    def error(self):
        return self._error

    @property
    def is_running(self) -> bool:
        return self._thread is not None and self._thread.is_alive()

    def start(self) -> None:
        self._capture_source = ScreenCaptureSource(self.monitor_index)
        first_frame = self._capture_source.grab()
        height, width = first_frame.shape[:2]

        fourcc = cv2.VideoWriter_fourcc(*"mp4v")
        writer = cv2.VideoWriter(self.output_path, fourcc, self.fps, (width, height))
        if not writer.isOpened():
            raise RuntimeError(f"无法创建录像文件: {self.output_path}")

        self._thread = threading.Thread(
            target=self._record_loop,
            args=(writer, first_frame),
            daemon=True,
        )
        self._thread.start()

    def stop(self) -> None:
        self._stop_event.set()
        if self._thread is not None:
            self._thread.join(timeout=5.0)
        self._close_capture_source()

    def _close_capture_source(self) -> None:
        if self._capture_source is not None:
            self._capture_source.close()
            self._capture_source = None

    def _record_loop(self, writer: cv2.VideoWriter, first_frame: np.ndarray) -> None:
        frame_interval = 1.0 / self.fps
        next_frame_time = time.perf_counter()
        frame = first_frame

        try:
            self.log(f"[*] Recording started: {self.output_path}")

            while not self._stop_event.is_set():
                now = time.perf_counter()
                if now < next_frame_time:
                    time.sleep(next_frame_time - now)
                    continue

                now = time.perf_counter()
                repeat_count = max(1, int((now - next_frame_time) / frame_interval) + 1)

                for _ in range(repeat_count):
                    writer.write(frame)
                    next_frame_time += frame_interval

                frame = self._capture_source.grab()
        except Exception as exc:
            self._error = exc
            self.log(f"[!] Recording failed: {exc}")
        finally:
            writer.release()
            self._close_capture_source()
            self.log(f"[*] Recording saved: {self.output_path}")


class QRRecoveryApp(tk.Tk):
    def __init__(self) -> None:
        super().__init__()
        self.title("QR Recovery Tool")
        self.geometry("920x680")
        self.minsize(820, 600)

        self.queue = queue.Queue()
        self.recorder = None
        self.recovery_thread = None
        self.live_thread = None
        self.live_stop_event = None
        self.last_missing_frames: list[int] = []
        self.current_total_frames: int | None = None
        self.current_received_frames: set[int] = set()
        self.missing_list_path = "missing_frames.txt"

        self.input_var = tk.StringVar(value=VIDEO)
        self.output_var = tk.StringVar(value=OUTPUT)
        self.record_var = tk.StringVar(value=DEFAULT_RECORDING)
        self.fps_var = tk.StringVar(value=str(DEFAULT_FPS))
        self.monitor_var = tk.StringVar()
        self.status_var = tk.StringVar(value="Ready")
        self.monitor_choices = list_available_monitors()
        self.monitor_map = {label: index for index, label in self.monitor_choices}

        self._build_ui()
        self.after(100, self._drain_queue)

    def _build_ui(self) -> None:
        root = tk.Frame(self, padx=14, pady=14)
        root.pack(fill="both", expand=True)

        title = tk.Label(root, text="QR Recovery Tool", font=("Segoe UI", 18, "bold"))
        title.pack(anchor="w")

        subtitle = tk.Label(
            root,
            text="录屏后可直接恢复二维码中的 base64 数据，或选择已有视频文件进行解析。",
            fg="#555555",
        )
        subtitle.pack(anchor="w", pady=(4, 12))

        form = tk.Frame(root)
        form.pack(fill="x")

        self._add_path_row(form, "输入视频", self.input_var, self._browse_input, 0)
        self._add_path_row(form, "输出文件", self.output_var, self._browse_output, 1)
        self._add_path_row(form, "录屏文件", self.record_var, self._browse_record_output, 2)

        fps_row = tk.Frame(form)
        fps_row.grid(row=3, column=0, columnspan=3, sticky="ew", pady=(6, 0))
        tk.Label(fps_row, text="录屏帧率").pack(side="left")
        tk.Entry(fps_row, textvariable=self.fps_var, width=10).pack(side="left", padx=(8, 0))
        tk.Label(fps_row, text="fps", fg="#555555").pack(side="left", padx=(6, 0))

        monitor_row = tk.Frame(form)
        monitor_row.grid(row=4, column=0, columnspan=3, sticky="ew", pady=(8, 0))
        tk.Label(monitor_row, text="录制屏幕").pack(side="left")

        self.monitor_combo = ttk.Combobox(
            monitor_row,
            textvariable=self.monitor_var,
            state="readonly",
            width=42,
            values=[label for _, label in self.monitor_choices],
        )
        self.monitor_combo.pack(side="left", padx=(8, 0), fill="x", expand=True)
        self.monitor_combo.bind("<<ComboboxSelected>>", self._on_monitor_selected)

        self.refresh_monitors_button = tk.Button(monitor_row, text="刷新", command=self._refresh_monitors, width=8)
        self.refresh_monitors_button.pack(side="left", padx=(8, 0))

        if self.monitor_choices:
            self.monitor_var.set(self.monitor_choices[0][1])

        button_bar = tk.Frame(root)
        button_bar.pack(fill="x", pady=(14, 8))

        self.record_button = tk.Button(button_bar, text="开始录屏", command=self._start_recording)
        self.record_button.pack(side="left")

        self.stop_button = tk.Button(button_bar, text="停止录屏", command=self._stop_recording, state="disabled")
        self.stop_button.pack(side="left", padx=(8, 0))

        self.recover_button = tk.Button(button_bar, text="恢复二维码", command=self._start_recovery)
        self.recover_button.pack(side="left", padx=(8, 0))

        self.live_button = tk.Button(button_bar, text="Live Decode", command=self._start_live_decode)
        self.live_button.pack(side="left", padx=(8, 0))

        self.stop_live_button = tk.Button(button_bar, text="Stop Live", command=self._stop_live_decode, state="disabled")
        self.stop_live_button.pack(side="left", padx=(8, 0))

        self.export_missing_button = tk.Button(
            button_bar,
            text="Export Missing",
            command=self._export_missing_frames,
        )
        self.export_missing_button.pack(side="left", padx=(8, 0))

        self.clear_button = tk.Button(button_bar, text="清空日志", command=self._clear_log)
        self.clear_button.pack(side="right")

        status_row = tk.Frame(root)
        status_row.pack(fill="x", pady=(0, 8))
        tk.Label(status_row, text="状态:").pack(side="left")
        tk.Label(status_row, textvariable=self.status_var, fg="#1f5aa6").pack(side="left", padx=(8, 0))

        self.log_box = scrolledtext.ScrolledText(root, height=22, state="disabled", wrap="word")
        self.log_box.pack(fill="both", expand=True)

    def _add_path_row(self, parent, label_text, variable, browse_command, row: int) -> None:
        row_frame = tk.Frame(parent)
        row_frame.grid(row=row, column=0, columnspan=3, sticky="ew", pady=(0, 6))
        row_frame.columnconfigure(1, weight=1)

        tk.Label(row_frame, text=label_text, width=12, anchor="w").grid(row=0, column=0, sticky="w")
        tk.Entry(row_frame, textvariable=variable).grid(row=0, column=1, sticky="ew", padx=(0, 8))
        tk.Button(row_frame, text="浏览...", command=browse_command, width=10).grid(row=0, column=2)

    def _browse_input(self) -> None:
        path = filedialog.askopenfilename(
            title="选择视频文件",
            filetypes=[("Video files", "*.mp4 *.avi *.mkv *.mov *.flv"), ("All files", "*.*")],
        )
        if path:
            self.input_var.set(path)

    def _browse_output(self) -> None:
        path = filedialog.asksaveasfilename(
            title="选择输出文件",
            defaultextension=".gz",
            filetypes=[("GZip files", "*.gz"), ("All files", "*.*")],
        )
        if path:
            self.output_var.set(path)

    def _browse_record_output(self) -> None:
        path = filedialog.asksaveasfilename(
            title="选择录屏保存路径",
            defaultextension=".mp4",
            filetypes=[("MP4 video", "*.mp4"), ("All files", "*.*")],
        )
        if path:
            self.record_var.set(path)

    def _refresh_monitors(self) -> None:
        self.monitor_choices = list_available_monitors()
        self.monitor_map = {label: index for index, label in self.monitor_choices}
        self.monitor_combo.configure(values=[label for _, label in self.monitor_choices])
        if self.monitor_choices:
            current = self.monitor_var.get()
            if current not in self.monitor_map:
                self.monitor_var.set(self.monitor_choices[0][1])

    def _on_monitor_selected(self, _event=None) -> None:
        selected = self.monitor_var.get()
        if selected not in self.monitor_map and self.monitor_choices:
            self.monitor_var.set(self.monitor_choices[0][1])

    def _selected_monitor_index(self) -> int | None:
        return self.monitor_map.get(self.monitor_var.get())

    def _clear_log(self) -> None:
        self.log_box.configure(state="normal")
        self.log_box.delete("1.0", "end")
        self.log_box.configure(state="disabled")

    def _load_missing_frames_from_file(self) -> list[int]:
        if not os.path.exists(self.missing_list_path):
            return []

        frames: list[int] = []
        with open(self.missing_list_path, "r", encoding="utf-8") as file_handle:
            for line in file_handle:
                line = line.split("#", 1)[0].replace(",", " ")
                for item in line.split():
                    if item.isdigit():
                        frames.append(int(item))

        return sorted(set(frames))

    def _current_missing_frames(self) -> list[int]:
        if not self.current_total_frames or not self.current_received_frames:
            return []
        return [
            idx
            for idx in range(1, self.current_total_frames + 1)
            if idx not in self.current_received_frames
        ]

    def _export_missing_frames(self) -> None:
        frames = self._current_missing_frames() or self.last_missing_frames or self._load_missing_frames_from_file()
        if not frames:
            messagebox.showinfo("Export Missing", "当前没有可导出的缺失帧列表。")
            return

        path = filedialog.asksaveasfilename(
            title="导出缺失帧列表",
            initialfile="missing_frames.txt",
            defaultextension=".txt",
            filetypes=[("Text files", "*.txt"), ("All files", "*.*")],
        )
        if not path:
            return

        _write_missing_list(frames, path, log=self._enqueue_log)
        self.last_missing_frames = frames
        self.missing_list_path = path
        messagebox.showinfo("Export Missing", f"已导出 {len(frames)} 个缺失帧。")

    def _append_log(self, message: str) -> None:
        self.log_box.configure(state="normal")
        self.log_box.insert("end", message + "\n")
        self.log_box.see("end")
        self.log_box.configure(state="disabled")

    def _enqueue_log(self, message: str) -> None:
        self.queue.put(("log", message))

    def _remember_missing_frames(self) -> None:
        frames = self._current_missing_frames() or self._load_missing_frames_from_file()
        if frames:
            self.last_missing_frames = frames
            self._enqueue_log(f"[*] Current missing frames: {frames}")

    def _enqueue_progress(self, total_frames: int, received_frames: set[int]) -> None:
        self.queue.put(("progress", (total_frames, sorted(received_frames))))

    def _set_status(self, message: str) -> None:
        self.queue.put(("status", message))

    def _start_recording(self) -> None:
        if self.recorder and self.recorder.is_running:
            messagebox.showinfo("录屏中", "当前已经在录屏。")
            return

        try:
            fps = float(self.fps_var.get())
            if fps <= 0:
                raise ValueError
        except ValueError:
            messagebox.showerror("参数错误", "录屏帧率必须是大于 0 的数字。")
            return

        output_path = self.record_var.get().strip()
        if not output_path:
            messagebox.showerror("参数错误", "请先选择录屏输出文件。")
            return

        try:
            self.recorder = ScreenRecorder(
                output_path,
                fps,
                monitor_index=self._selected_monitor_index(),
                log=self._enqueue_log,
            )
            self.recorder.start()
        except Exception as exc:
            messagebox.showerror("录屏失败", str(exc))
            return

        self.record_button.configure(state="disabled")
        self.stop_button.configure(state="normal")
        self._set_status("Recording")
        self._enqueue_log(f"[*] Recording started: {output_path}")

    def _stop_recording(self) -> None:
        if not self.recorder or not self.recorder.is_running:
            return

        self.recorder.stop()
        self.record_button.configure(state="normal")
        self.stop_button.configure(state="disabled")
        self.input_var.set(self.record_var.get().strip())
        self._set_status("Recording stopped")
        self._enqueue_log("[*] Recording stopped")

        if self.recorder.error is not None:
            messagebox.showerror("录屏错误", str(self.recorder.error))

    def _start_recovery(self) -> None:
        if self.recovery_thread and self.recovery_thread.is_alive():
            messagebox.showinfo("处理中", "二维码恢复正在进行中。")
            return

        video_path = self.input_var.get().strip()
        output_path = self.output_var.get().strip()

        if not video_path:
            messagebox.showerror("参数错误", "请先选择输入视频。")
            return

        if not output_path:
            messagebox.showerror("参数错误", "请先选择输出文件。")
            return

        self.recover_button.configure(state="disabled")
        self._set_status("Recovering")
        self._enqueue_log(f"[*] Recovering from: {video_path}")

        def worker() -> None:
            try:
                self.last_missing_frames = []
                self.current_total_frames = None
                self.current_received_frames = set()
                recovered_path = recover_qr_from_video(
                    video_path,
                    output_path,
                    missing_list_path=self.missing_list_path,
                    progress_callback=self._enqueue_progress,
                    log=self._enqueue_log,
                )
                self.queue.put(("recovery_done", recovered_path))
            except Exception as exc:
                self._remember_missing_frames()
                self.queue.put(("recovery_error", str(exc)))

        self.recovery_thread = threading.Thread(target=worker, daemon=True)
        self.recovery_thread.start()

    def _start_live_decode(self) -> None:
        if self.live_thread and self.live_thread.is_alive():
            messagebox.showinfo("Live Decode", "Live screen decoding is already running.")
            return

        output_path = self.output_var.get().strip()
        if not output_path:
            messagebox.showerror("参数错误", "请先选择输出文件。")
            return

        self.live_stop_event = threading.Event()
        self.live_button.configure(state="disabled")
        self.stop_live_button.configure(state="normal")
        self.recover_button.configure(state="disabled")
        self.record_button.configure(state="disabled")
        self._set_status("Live decoding")
        self._enqueue_log("[*] Live decoding from screen")

        def worker() -> None:
            try:
                self.last_missing_frames = []
                self.current_total_frames = None
                self.current_received_frames = set()
                recovered_path = recover_qr_from_screen(
                    output_path,
                    monitor_index=self._selected_monitor_index(),
                    stop_event=self.live_stop_event,
                    missing_list_path=self.missing_list_path,
                    progress_callback=self._enqueue_progress,
                    log=self._enqueue_log,
                )
                self.queue.put(("live_done", recovered_path))
            except Exception as exc:
                self._remember_missing_frames()
                self.queue.put(("live_error", str(exc)))

        self.live_thread = threading.Thread(target=worker, daemon=True)
        self.live_thread.start()

    def _stop_live_decode(self) -> None:
        if self.live_stop_event is not None:
            self.live_stop_event.set()
        self.stop_live_button.configure(state="disabled")
        self._set_status("Stopping live decode")

    def _drain_queue(self) -> None:
        while True:
            try:
                kind, payload = self.queue.get_nowait()
            except queue.Empty:
                break

            if kind == "log":
                self._append_log(str(payload))
            elif kind == "status":
                self.status_var.set(str(payload))
            elif kind == "progress":
                total_frames, received_frames = payload
                self.current_total_frames = int(total_frames)
                self.current_received_frames = set(int(item) for item in received_frames)
                self.last_missing_frames = self._current_missing_frames()
            elif kind == "live_done":
                self.live_button.configure(state="normal")
                self.stop_live_button.configure(state="disabled")
                self.recover_button.configure(state="normal")
                self.record_button.configure(state="normal")
                self._set_status("Ready")
                self._append_log(f"[*] Saved: {payload}")
                messagebox.showinfo("完成", f"实时解码完成：{payload}")
            elif kind == "live_error":
                self.live_button.configure(state="normal")
                self.stop_live_button.configure(state="disabled")
                self.recover_button.configure(state="normal")
                self.record_button.configure(state="normal")
                self._set_status("Ready")
                self._append_log(f"[!] Live decode failed: {payload}")
                messagebox.showerror("实时解码失败", str(payload))
            elif kind == "recovery_done":
                self.recover_button.configure(state="normal")
                self._set_status("Ready")
                self._append_log(f"[*] Saved: {payload}")
                messagebox.showinfo("完成", f"恢复完成：{payload}")
            elif kind == "recovery_error":
                self.recover_button.configure(state="normal")
                self._set_status("Ready")
                self._append_log(f"[!] Recovery failed: {payload}")
                messagebox.showerror("恢复失败", str(payload))

        self.after(100, self._drain_queue)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Recover QR payloads from a recorded video, with GUI and screen recording."
    )
    parser.add_argument("--input", default=None, help="输入视频文件")
    parser.add_argument("--output", default=None, help="输出文件")
    parser.add_argument("--gui", action="store_true", help="启动图形界面")
    parser.add_argument("--record", action="store_true", help="启动图形界面并优先用于录屏")
    parser.add_argument("--live", action="store_true", help="直接抓屏实时解码")
    parser.add_argument("--monitor", type=int, default=None, help="实时解码/录屏使用的屏幕编号")
    parser.add_argument("--interval", type=float, default=DEFAULT_LIVE_INTERVAL, help="实时抓屏间隔秒数")
    parser.add_argument("--missing-list", default="missing_frames.txt", help="缺失帧列表输出路径")
    return parser.parse_args()


def main() -> None:
    args = parse_args()

    if args.live:
        output_path = args.output or OUTPUT
        recover_qr_from_screen(
            output_path,
            monitor_index=args.monitor,
            interval=args.interval,
            missing_list_path=args.missing_list,
        )
        return

    if args.gui or args.record or (args.input is None and args.output is None):
        app = QRRecoveryApp()
        if args.input:
            app.input_var.set(args.input)
        if args.output:
            app.output_var.set(args.output)
        app.mainloop()
        return

    input_path = args.input or VIDEO
    output_path = args.output or OUTPUT
    recover_qr_from_video(input_path, output_path, missing_list_path=args.missing_list)


if __name__ == "__main__":
    main()
