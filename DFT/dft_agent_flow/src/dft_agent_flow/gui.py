from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any, Callable

import qtawesome as qta

from .agent import run_agent
from .config import available_circuits
from .dftc_labs import DftcLabTutor
from .external_projects import ExternalDftProjectRunner


try:  # Keep the command-line and test-only installation usable without Qt.
    from PyQt6.QtCore import QObject, Qt, QThread, pyqtSignal
    from PyQt6.QtGui import QAction, QColor, QPalette
    from PyQt6.QtWidgets import (
        QApplication,
        QComboBox,
        QDoubleSpinBox,
        QFormLayout,
        QFrame,
        QHBoxLayout,
        QHeaderView,
        QLabel,
        QMainWindow,
        QMessageBox,
        QPlainTextEdit,
        QSplitter,
        QSpinBox,
        QStatusBar,
        QTableWidget,
        QTableWidgetItem,
        QTabWidget,
        QToolButton,
        QVBoxLayout,
        QWidget,
    )
except ImportError as exc:  # pragma: no cover - exercised only without GUI extra
    _QT_IMPORT_ERROR = exc
else:
    _QT_IMPORT_ERROR = None


if _QT_IMPORT_ERROR is None:

    class _Worker(QObject):
        finished = pyqtSignal(object)
        failed = pyqtSignal(str)

        def __init__(self, action: Callable[[], dict[str, Any]]) -> None:
            super().__init__()
            self._action = action

        def run(self) -> None:
            try:
                self.finished.emit(self._action())
            except Exception as exc:  # GUI boundary: show complete exception text to the operator.
                self.failed.emit(f"{type(exc).__name__}: {exc}")


    class DftAgentWindow(QMainWindow):
        """Operational UI over the same constrained Agent and evidence APIs as the CLI."""

        def __init__(self, tutor: DftcLabTutor | None = None) -> None:
            super().__init__()
            self.tutor = tutor or DftcLabTutor()
            self.external_runner = ExternalDftProjectRunner()
            self._thread: QThread | None = None
            self._worker: _Worker | None = None
            self._lab_rows: list[dict[str, Any]] = []
            self._syncing_lab_selection = False
            self._configure_window()
            self._build_actions()
            self._build_layout()
            self.refresh()

        def _configure_window(self) -> None:
            self.setWindowTitle("DFT Agent Studio")
            self.setMinimumSize(1080, 720)
            self.resize(1440, 900)

        @staticmethod
        def _flat_icon(name: str, color: str):
            return qta.icon(name, color=color, color_active="#ffffff")

        def _build_actions(self) -> None:
            self.refresh_action = QAction(
                self._flat_icon("fa5s.sync-alt", "#168aad"), "刷新", self
            )
            self.refresh_action.setToolTip("重新读取 Lab 状态与工作区证据")
            self.refresh_action.triggered.connect(self.refresh)
            self.run_action = QAction(
                self._flat_icon("fa5s.play", "#2563eb"), "运行目标", self
            )
            self.run_action.setToolTip("让本地 Agent 执行当前结构化目标")
            self.run_action.triggered.connect(self.run_goal)
            self.verify_action = QAction(
                self._flat_icon("fa5s.check-double", "#16a34a"), "复核", self
            )
            self.verify_action.setToolTip("对选中的已存证据重新执行两轮只读交叉验证")
            self.verify_action.triggered.connect(self.verify_selected_evidence)
            self.quit_action = QAction(self._flat_icon("fa5s.power-off", "#ef4444"), "退出", self)
            self.quit_action.triggered.connect(self.close)

            toolbar = self.addToolBar("工作流")
            toolbar.setMovable(False)
            toolbar.addAction(self.refresh_action)
            toolbar.addAction(self.run_action)
            toolbar.addAction(self.verify_action)
            toolbar.addSeparator()
            toolbar.addAction(self.quit_action)
            menu = self.menuBar().addMenu("工作流")
            menu.addAction(self.refresh_action)
            menu.addAction(self.run_action)
            menu.addAction(self.verify_action)
            menu.addSeparator()
            menu.addAction(self.quit_action)

        def _build_layout(self) -> None:
            central = QWidget(self)
            root = QVBoxLayout(central)
            root.setContentsMargins(14, 12, 14, 12)
            root.setSpacing(10)

            header = QFrame(central)
            header.setObjectName("appHeader")
            header.setStyleSheet(
                "QFrame { background-color: #0f766e; border: 0; border-radius: 7px; }"
                "QLabel { color: #dffaf7; border: 0; }"
            )
            header_layout = QHBoxLayout(header)
            header_layout.setContentsMargins(14, 10, 14, 10)
            mark = QLabel(header)
            mark.setPixmap(self._flat_icon("fa5s.microchip", "#ffffff").pixmap(28, 28))
            header_layout.addWidget(mark)
            heading = QVBoxLayout()
            summary = QLabel("DFT Agent Studio")
            summary.setObjectName("sectionTitle")
            summary.setStyleSheet("color: #ffffff; font-size: 19px; font-weight: 700;")
            heading.addWidget(summary)
            subtitle = QLabel("目标编排 · 受控执行 · 双轮证据验证")
            subtitle.setStyleSheet("color: #dffaf7;")
            heading.addWidget(subtitle)
            header_layout.addLayout(heading)
            header_layout.addStretch(1)
            policy = QLabel("仅 Agent 工具可执行")
            policy.setObjectName("policyBadge")
            policy.setStyleSheet(
                "background-color: #f59e0b; color: #17212b; font-weight: 700; "
                "border: 0; border-radius: 10px; padding: 5px 9px;"
            )
            header_layout.addWidget(policy)
            root.addWidget(header)

            splitter = QSplitter(Qt.Orientation.Horizontal, central)
            splitter.setChildrenCollapsible(False)
            splitter.addWidget(self._build_lab_panel())
            splitter.addWidget(self._build_operation_panel())
            splitter.setSizes([500, 940])
            root.addWidget(splitter, 3)
            root.addWidget(self._build_evidence_panel(), 2)
            self.setCentralWidget(central)

            status = QStatusBar(self)
            self.status_label = QLabel("就绪")
            status.addWidget(self.status_label)
            self.setStatusBar(status)

        def _build_lab_panel(self) -> QWidget:
            panel = QFrame(self)
            panel.setFrameShape(QFrame.Shape.StyledPanel)
            layout = QVBoxLayout(panel)
            layout.setContentsMargins(10, 10, 10, 10)
            layout.setSpacing(8)
            layout.addWidget(QLabel("课程 Lab"))
            self.lab_table = QTableWidget(0, 4, panel)
            self.lab_table.setHorizontalHeaderLabels(["Lab", "记录状态", "主题", "可用技能"])
            self.lab_table.setSelectionBehavior(QTableWidget.SelectionBehavior.SelectRows)
            self.lab_table.setSelectionMode(QTableWidget.SelectionMode.SingleSelection)
            self.lab_table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)
            self.lab_table.verticalHeader().setVisible(False)
            self.lab_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.ResizeMode.ResizeToContents)
            self.lab_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeMode.ResizeToContents)
            self.lab_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeMode.Stretch)
            self.lab_table.horizontalHeader().setSectionResizeMode(3, QHeaderView.ResizeMode.ResizeToContents)
            self.lab_table.itemSelectionChanged.connect(self._selected_lab_changed)
            layout.addWidget(self.lab_table)
            return panel

        def _build_operation_panel(self) -> QWidget:
            panel = QFrame(self)
            panel.setFrameShape(QFrame.Shape.StyledPanel)
            layout = QVBoxLayout(panel)
            layout.setContentsMargins(10, 10, 10, 10)
            layout.setSpacing(8)

            self.goal_tabs = QTabWidget(panel)
            self.goal_tabs.addTab(self._build_dftc_goal_tab(), self._flat_icon("fa5s.sitemap", "#0f766e"), "DFTC Lab")
            self.goal_tabs.addTab(self._build_fan_goal_tab(), self._flat_icon("fa5s.chart-line", "#ea580c"), "FAN ATPG")
            self.goal_tabs.addTab(self._build_external_goal_tab(), self._flat_icon("fa5s.code-branch", "#7c3aed"), "开源 RTL")
            self.goal_tabs.addTab(self._build_custom_goal_tab(), self._flat_icon("fa5s.sliders-h", "#7c3aed"), "自定义目标")
            self.goal_tabs.currentChanged.connect(self._goal_tab_changed)
            layout.addWidget(self.goal_tabs)

            controls = QHBoxLayout()
            self.run_button = QToolButton(panel)
            self.run_button.setDefaultAction(self.run_action)
            self.run_button.setToolButtonStyle(Qt.ToolButtonStyle.ToolButtonTextBesideIcon)
            self.run_button.setObjectName("primaryAction")
            self.verify_button = QToolButton(panel)
            self.verify_button.setDefaultAction(self.verify_action)
            self.verify_button.setToolButtonStyle(Qt.ToolButtonStyle.ToolButtonTextBesideIcon)
            self.verify_button.setObjectName("verifyAction")
            controls.addWidget(self.run_button)
            controls.addWidget(self.verify_button)
            controls.addStretch(1)
            layout.addLayout(controls)

            layout.addWidget(QLabel("Agent 与验证输出"))
            self.output = QPlainTextEdit(panel)
            self.output.setReadOnly(True)
            self.output.setLineWrapMode(QPlainTextEdit.LineWrapMode.NoWrap)
            self.output.setPlaceholderText("运行、失败或双轮验证结果会显示在这里。")
            layout.addWidget(self.output, 1)
            return panel

        def _build_dftc_goal_tab(self) -> QWidget:
            tab = QWidget(self)
            form = QFormLayout(tab)
            form.setContentsMargins(10, 10, 10, 10)
            form.setSpacing(8)
            self.dftc_mode = QComboBox(tab)
            self.dftc_mode.addItem("执行并双重验证", "execute")
            self.dftc_mode.addItem("执行完整课程", "course")
            self.dftc_mode.addItem("审计运行副本", "audit")
            self.dftc_mode.addItem("查看课程指导", "teach")
            self.dftc_mode.addItem("比较兼容性改动", "diff")
            self.dftc_mode.setToolTip("执行模式只暴露经过批准的 Agent 技能")
            self.dftc_mode.currentIndexChanged.connect(self._update_dftc_goal)
            form.addRow("目标类型", self.dftc_mode)
            self.goal_lab_selector = QComboBox(tab)
            self.goal_lab_selector.currentIndexChanged.connect(self._goal_lab_changed)
            form.addRow("目标 Lab", self.goal_lab_selector)
            self.skill_selector = QComboBox(tab)
            self.skill_selector.setToolTip("当前 Lab 可由 Agent 调用的受控技能")
            self.skill_selector.currentIndexChanged.connect(self._update_dftc_goal)
            form.addRow("受控技能", self.skill_selector)
            self.dftc_goal_editor = QPlainTextEdit(tab)
            self.dftc_goal_editor.setFixedHeight(82)
            self.dftc_goal_editor.setToolTip("可补充判读要求；工具边界仍由 Agent 运行策略强制执行")
            form.addRow("生成的目标", self.dftc_goal_editor)
            return tab

        def _build_fan_goal_tab(self) -> QWidget:
            tab = QWidget(self)
            form = QFormLayout(tab)
            form.setContentsMargins(10, 10, 10, 10)
            form.setSpacing(8)
            self.fan_circuit = QComboBox(tab)
            for circuit in available_circuits():
                self.fan_circuit.addItem(circuit)
            self.fan_circuit.currentIndexChanged.connect(self._update_fan_goal)
            form.addRow("电路", self.fan_circuit)
            self.fan_coverage = QDoubleSpinBox(tab)
            self.fan_coverage.setRange(0.0, 100.0)
            self.fan_coverage.setDecimals(2)
            self.fan_coverage.setSingleStep(0.5)
            self.fan_coverage.setValue(94.5)
            self.fan_coverage.setSuffix(" %")
            self.fan_coverage.valueChanged.connect(self._update_fan_goal)
            form.addRow("最低 fault coverage", self.fan_coverage)
            self.fan_patterns = QSpinBox(tab)
            self.fan_patterns.setRange(0, 100000)
            self.fan_patterns.setSpecialValueText("不限制")
            self.fan_patterns.setValue(5)
            self.fan_patterns.valueChanged.connect(self._update_fan_goal)
            form.addRow("最大 pattern 数", self.fan_patterns)
            self.fan_goal_editor = QPlainTextEdit(tab)
            self.fan_goal_editor.setFixedHeight(82)
            self.fan_goal_editor.setToolTip("由 coverage 和 pattern 控件生成，可添加任务说明")
            form.addRow("生成的目标", self.fan_goal_editor)
            self._update_fan_goal()
            return tab

        def _build_external_goal_tab(self) -> QWidget:
            tab = QWidget(self)
            form = QFormLayout(tab)
            form.setContentsMargins(10, 10, 10, 10)
            form.setSpacing(8)
            self.external_project = QComboBox(tab)
            for project in self.external_runner.list_projects()["projects"]:
                self.external_project.addItem(
                    f"{project['title']}  -  {project['top']}", project["id"]
                )
            self.external_project.currentIndexChanged.connect(self._update_external_goal)
            form.addRow("项目", self.external_project)
            self.external_action = QComboBox(tab)
            self.external_action.addItem("从零执行并双重验证", "run")
            self.external_action.addItem("诊断最近证据", "diagnose")
            self.external_action.currentIndexChanged.connect(self._update_external_goal)
            form.addRow("受控动作", self.external_action)
            self.external_goal_editor = QPlainTextEdit(tab)
            self.external_goal_editor.setFixedHeight(82)
            self.external_goal_editor.setReadOnly(True)
            form.addRow("生成的目标", self.external_goal_editor)
            self._update_external_goal()
            return tab

        def _build_custom_goal_tab(self) -> QWidget:
            tab = QWidget(self)
            layout = QVBoxLayout(tab)
            layout.setContentsMargins(10, 10, 10, 10)
            layout.setSpacing(8)
            layout.addWidget(QLabel("受控自定义目标"))
            self.custom_goal_editor = QPlainTextEdit(tab)
            self.custom_goal_editor.setPlaceholderText("例如：审计 lab12_dftmax 的运行时证据，并列出所有阻塞项。")
            self.custom_goal_editor.setToolTip("自然语言目标仍只能调用已注册的 Python 工具")
            self.custom_goal_editor.textChanged.connect(self._update_run_enabled)
            layout.addWidget(self.custom_goal_editor)
            return tab

        def _build_evidence_panel(self) -> QWidget:
            panel = QFrame(self)
            panel.setFrameShape(QFrame.Shape.StyledPanel)
            layout = QVBoxLayout(panel)
            layout.setContentsMargins(10, 8, 10, 10)
            layout.setSpacing(6)
            layout.addWidget(QLabel("已存执行证据"))
            self.evidence_table = QTableWidget(0, 5, panel)
            self.evidence_table.setHorizontalHeaderLabels(["Lab", "技能", "执行", "交叉验证", "工作区"])
            self.evidence_table.setSelectionBehavior(QTableWidget.SelectionBehavior.SelectRows)
            self.evidence_table.setSelectionMode(QTableWidget.SelectionMode.SingleSelection)
            self.evidence_table.setEditTriggers(QTableWidget.EditTrigger.NoEditTriggers)
            self.evidence_table.verticalHeader().setVisible(False)
            for column in range(4):
                self.evidence_table.horizontalHeader().setSectionResizeMode(column, QHeaderView.ResizeMode.ResizeToContents)
            self.evidence_table.horizontalHeader().setSectionResizeMode(4, QHeaderView.ResizeMode.Stretch)
            layout.addWidget(self.evidence_table)
            return panel

        def refresh(self) -> None:
            labs = self.tutor.list_labs()["labs"]
            skills = self.tutor.list_skills()["skills"]
            skills_by_lab: dict[str, list[dict[str, Any]]] = {}
            for skill in skills:
                skills_by_lab.setdefault(skill["lab"], []).append(skill)
            self._lab_rows = labs
            current_lab = self.selected_lab_id()
            configured_lab = self.goal_lab_selector.currentData()
            self.goal_lab_selector.blockSignals(True)
            self.goal_lab_selector.clear()
            for lab in labs:
                self.goal_lab_selector.addItem(f"{lab['id']}  -  {lab['topic']}", lab["id"])
            configured_index = self.goal_lab_selector.findData(configured_lab or current_lab)
            self.goal_lab_selector.setCurrentIndex(max(configured_index, 0))
            self.goal_lab_selector.blockSignals(False)
            self.lab_table.setRowCount(len(labs))
            for row, lab in enumerate(labs):
                names = [skill["id"] for skill in skills_by_lab.get(lab["id"], [])]
                values = (lab["id"], lab["state"], lab["topic"], ", ".join(names) or "待添加")
                for column, value in enumerate(values):
                    item = QTableWidgetItem(value)
                    item.setData(Qt.ItemDataRole.UserRole, lab["id"])
                    if column == 1:
                        color = self._state_color(lab["state"])
                        item.setBackground(QColor(color))
                    self.lab_table.setItem(row, column, item)
            self._populate_evidence()
            if labs:
                selected_row = next((index for index, lab in enumerate(labs) if lab["id"] == current_lab), 0)
                self.lab_table.selectRow(selected_row)
            self._set_dftc_skills(self.goal_lab_selector.currentData())
            self._update_dftc_goal()
            self.status_label.setText(f"已读取 {len(labs)} 个课程 Lab 与 {len(skills)} 个受控技能")

        def _populate_evidence(self) -> None:
            records = self.tutor.list_execution_evidence()["records"]
            self.evidence_table.setRowCount(len(records))
            for row, record in enumerate(records):
                values = (
                    record["lab"],
                    record["skill"],
                    record["skill_status"],
                    record["verification_status"],
                    record["workspace"],
                )
                for column, value in enumerate(values):
                    item = QTableWidgetItem(value)
                    item.setData(Qt.ItemDataRole.UserRole, record["evidence_file"])
                    if column == 3:
                        item.setBackground(QColor("#d1fae5" if value == "verified" else "#fef3c7"))
                    self.evidence_table.setItem(row, column, item)

        @staticmethod
        def _state_color(state: str) -> str:
            if state == "verified":
                return "#d1fae5"
            if "warning" in state or "review_items" in state:
                return "#fef3c7"
            if "review" in state:
                return "#dbeafe"
            return "#fee2e2"

        def selected_lab_id(self) -> str | None:
            selected = self.lab_table.selectedItems()
            return selected[0].data(Qt.ItemDataRole.UserRole) if selected else None

        def _selected_lab_changed(self) -> None:
            lab_id = self.selected_lab_id()
            if not lab_id:
                return
            if not self._syncing_lab_selection:
                self._syncing_lab_selection = True
                index = self.goal_lab_selector.findData(lab_id)
                if index >= 0:
                    self.goal_lab_selector.setCurrentIndex(index)
                self._syncing_lab_selection = False
            self._set_dftc_skills(lab_id)
            self._update_dftc_goal()

        def _goal_lab_changed(self) -> None:
            lab_id = self.goal_lab_selector.currentData()
            if lab_id and not self._syncing_lab_selection:
                self._syncing_lab_selection = True
                row = next((index for index, lab in enumerate(self._lab_rows) if lab["id"] == lab_id), -1)
                if row >= 0:
                    self.lab_table.selectRow(row)
                self._syncing_lab_selection = False
            self._set_dftc_skills(lab_id)
            self._update_dftc_goal()

        def _set_dftc_skills(self, lab_id: str | None) -> None:
            current = self.skill_selector.currentData()
            skills = [skill for skill in self.tutor.list_skills()["skills"] if skill["lab"] == lab_id]
            self.skill_selector.blockSignals(True)
            self.skill_selector.clear()
            for skill in skills:
                label = skill["id"] + ("  (推荐)" if skill.get("recommended") else "")
                self.skill_selector.addItem(label, skill["id"])
            index = self.skill_selector.findData(current)
            self.skill_selector.setCurrentIndex(max(index, 0))
            self.skill_selector.blockSignals(False)

        def _update_dftc_goal(self) -> None:
            lab_id = self.goal_lab_selector.currentData()
            mode = self.dftc_mode.currentData()
            skill_id = self.skill_selector.currentData()
            if not lab_id:
                return
            templates = {
                "execute": (
                    f"执行 {lab_id} 的受控技能 {skill_id} 并进行双重交叉验证。使用中文，只报告工具返回的证据。"
                    if skill_id
                    else f"审计 {lab_id} 的运行时证据，说明当前尚无可执行受控技能。"
                ),
                "course": "执行完整 DFTC 课程的全部 Lab 并逐项双重交叉验证。使用中文，只报告工具返回的证据；任何阻塞项均不得称为通过。",
                "audit": f"审计 {lab_id} 的运行时证据。列出验收检查、阻塞证据和允许的结论。",
                "teach": f"讲解 {lab_id} 的目标、现代兼容性处理和验收标准。不要声称执行。",
                "diff": f"比较 {lab_id} 的官方脚本与运行时兼容性改动，只报告工具返回的差异。",
            }
            self.dftc_goal_editor.setPlainText(templates[mode])
            self._update_run_enabled()

        def _update_fan_goal(self) -> None:
            circuit = self.fan_circuit.currentText()
            coverage = self.fan_coverage.value()
            patterns = self.fan_patterns.value()
            pattern_text = "不限制" if patterns == 0 else str(patterns)
            self.fan_goal_editor.setPlainText(
                f"对 {circuit} 执行 ATPG，fault coverage 至少 {coverage:.2f}%，pattern 不超过 {pattern_text}，给出最优可验证配置。"
            )

        def _update_external_goal(self) -> None:
            project = self.external_project.currentData()
            action = self.external_action.currentData()
            if not project:
                return
            if action == "run":
                text = (
                    f"对开源 {project} 从头执行 DFT flow，必须调用受控工具并双重交叉验证；"
                    "中文仅报告工具证据。"
                )
            else:
                text = f"诊断开源 {project} 最近一次 DFT 基线证据，只列出批准动作或工程师审查结论。"
            self.external_goal_editor.setPlainText(text)
            self._update_run_enabled()

        def _goal_tab_changed(self) -> None:
            self._update_run_enabled()

        def _update_run_enabled(self) -> None:
            if self._thread is not None:
                return
            if self.goal_tabs.currentIndex() == 0:
                enabled = self.dftc_mode.currentData() != "execute" or bool(self.skill_selector.currentData())
            elif self.goal_tabs.currentIndex() == 1:
                enabled = bool(self.fan_circuit.currentText())
            elif self.goal_tabs.currentIndex() == 2:
                enabled = bool(self.external_project.currentData())
            else:
                enabled = bool(self.custom_goal_editor.toPlainText().strip())
            self.run_action.setEnabled(enabled)

        def _current_goal(self) -> str:
            if self.goal_tabs.currentIndex() == 0:
                return self.dftc_goal_editor.toPlainText().strip()
            if self.goal_tabs.currentIndex() == 1:
                return self.fan_goal_editor.toPlainText().strip()
            if self.goal_tabs.currentIndex() == 2:
                return self.external_goal_editor.toPlainText().strip()
            return self.custom_goal_editor.toPlainText().strip()

        def run_goal(self) -> None:
            goal = self._current_goal()
            if not goal:
                QMessageBox.information(self, "设置目标", "先设置一个可由受控工具完成的目标。")
                return
            label = self.goal_tabs.tabText(self.goal_tabs.currentIndex())
            self._start_worker(lambda: run_agent(goal), f"Agent 正在执行 {label} 目标")

        def verify_selected_evidence(self) -> None:
            selected = self.evidence_table.selectedItems()
            if not selected:
                QMessageBox.information(self, "选择证据", "先在下方表格选择一个 skill_result.json。")
                return
            evidence_file = Path(selected[0].data(Qt.ItemDataRole.UserRole))
            self._start_worker(
                lambda: self.tutor.cross_validate_evidence(evidence_file),
                f"正在复核 {evidence_file.parent.name}",
            )

        def _start_worker(self, action: Callable[[], dict[str, Any]], status: str) -> None:
            if self._thread is not None:
                return
            self.status_label.setText(status)
            self.run_action.setEnabled(False)
            self.verify_action.setEnabled(False)
            self._thread = QThread(self)
            self._worker = _Worker(action)
            self._worker.moveToThread(self._thread)
            self._thread.started.connect(self._worker.run)
            self._worker.finished.connect(self._worker_finished)
            self._worker.failed.connect(self._worker_failed)
            self._worker.finished.connect(self._thread.quit)
            self._worker.failed.connect(self._thread.quit)
            self._thread.finished.connect(self._thread_finished)
            self._thread.start()

        def _worker_finished(self, payload: dict[str, Any]) -> None:
            self.output.setPlainText(json.dumps(payload, ensure_ascii=False, indent=2))
            self.status_label.setText("操作完成；请查看工具返回的证据。")
            self.refresh()

        def _worker_failed(self, message: str) -> None:
            self.output.setPlainText(message)
            self.status_label.setText("操作失败；未产生通过结论。")

        def _thread_finished(self) -> None:
            if self._thread is not None:
                self._thread.deleteLater()
            if self._worker is not None:
                self._worker.deleteLater()
            self._thread = None
            self._worker = None
            self.verify_action.setEnabled(True)
            self._selected_lab_changed()


    def _apply_palette(app: QApplication) -> None:
        app.setStyle("Fusion")
        palette = QPalette()
        palette.setColor(QPalette.ColorRole.Window, QColor("#f4f6f8"))
        palette.setColor(QPalette.ColorRole.Base, QColor("#ffffff"))
        palette.setColor(QPalette.ColorRole.AlternateBase, QColor("#edf2f7"))
        palette.setColor(QPalette.ColorRole.Text, QColor("#17212b"))
        palette.setColor(QPalette.ColorRole.WindowText, QColor("#17212b"))
        palette.setColor(QPalette.ColorRole.Button, QColor("#e5edf1"))
        palette.setColor(QPalette.ColorRole.ButtonText, QColor("#17212b"))
        palette.setColor(QPalette.ColorRole.Highlight, QColor("#167d8d"))
        palette.setColor(QPalette.ColorRole.HighlightedText, QColor("#ffffff"))
        app.setPalette(palette)
        app.setStyleSheet(
            "QMainWindow { background: #f4f6f8; }"
            "QFrame { border: 1px solid #cfd8df; border-radius: 6px; }"
            "QFrame#appHeader { background: #0f766e; border: 0; border-radius: 7px; }"
            "QFrame#appHeader QLabel { color: #dffaf7; border: 0; }"
            "QHeaderView::section { background: #e5edf1; border: 0; border-bottom: 1px solid #c3d0d8; padding: 7px; font-weight: 600; }"
            "QTableWidget { background: #ffffff; gridline-color: #d9e2e8; selection-background-color: #b8e1e4; selection-color: #17212b; border-radius: 4px; }"
            "QTabBar::tab { background: #e7edf1; color: #45606d; border: 0; border-top-left-radius: 5px; border-top-right-radius: 5px; padding: 8px 13px; margin-right: 3px; }"
            "QTabBar::tab:selected { background: #ffffff; color: #0f4c5c; font-weight: 600; }"
            "QTabWidget::pane { border: 1px solid #cfd8df; border-radius: 4px; background: #ffffff; }"
            "QComboBox, QSpinBox, QDoubleSpinBox, QPlainTextEdit { background: #ffffff; border: 1px solid #c5d2da; border-radius: 4px; padding: 5px; }"
            "QComboBox:focus, QSpinBox:focus, QDoubleSpinBox:focus, QPlainTextEdit:focus { border: 2px solid #168aad; }"
            "QToolButton { border: 0; border-radius: 5px; padding: 7px 11px; font-weight: 600; }"
            "QToolButton#primaryAction { background: #2563eb; color: #ffffff; }"
            "QToolButton#primaryAction:hover { background: #1d4ed8; }"
            "QToolButton#verifyAction { background: #dcfce7; color: #166534; border: 1px solid #86efac; }"
            "QToolButton#verifyAction:hover { background: #bbf7d0; }"
            "QToolButton:disabled { background: #e5e7eb; color: #94a3b8; }"
            "QToolBar { background: #ffffff; border-bottom: 1px solid #cfd8df; spacing: 5px; padding: 4px; }"
            "#sectionTitle { font-size: 19px; font-weight: 700; color: #ffffff; }"
            "#policyBadge { background: #f59e0b; color: #17212b; font-weight: 700; border: 0; border-radius: 10px; padding: 5px 9px; }"
        )


    def main(argv: list[str] | None = None) -> int:
        del argv
        app = QApplication(sys.argv)
        _apply_palette(app)
        window = DftAgentWindow()
        window.show()
        return app.exec()


else:

    def main(argv: list[str] | None = None) -> int:  # pragma: no cover - error path
        del argv
        raise RuntimeError("PyQt6 is required for the GUI. Install the project with the gui extra.") from _QT_IMPORT_ERROR


if __name__ == "__main__":  # pragma: no cover
    raise SystemExit(main())
