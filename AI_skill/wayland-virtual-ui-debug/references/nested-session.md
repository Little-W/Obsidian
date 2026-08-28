# Nested Wayland session

Use this procedure for isolated Qt Quick/QML visual checks on a machine where the
user is still using their normal Wayland desktop.

## Preconditions

- Build with the project's normal release command. Confirm the output binary's
  modification time after the build; QML resource changes are often embedded in
  the executable.
- Require `Xvfb`, `weston`, ImageMagick (`import` or `magick import`), and
  `busctl` when the application obtains a local daemon WebSocket port through
  D-Bus.
- Pick an unused X display. The example uses `:98`; choose another one when it
  is already occupied.

## Start an isolated session

Keep every mutable artifact in a temporary directory. `setsid` makes each test
process independently stoppable without matching unrelated processes.

```bash
test_runtime=$(mktemp -d /tmp/app-wayland-test.XXXXXX)
mkdir -p "$test_runtime/config" "$test_runtime/cache"

setsid Xvfb :98 -screen 0 1280x800x24 \
  >"$test_runtime/xvfb.log" 2>&1 < /dev/null &
printf '%s\n' "$!" >"$test_runtime/xvfb.pid"

setsid env DISPLAY=:98 XDG_RUNTIME_DIR="$test_runtime" \
  weston --backend=x11 --renderer=gl --socket=app-wayland-test \
  --width=1280 --height=800 --idle-time=0 --no-config \
  --log="$test_runtime/weston.log" \
  >"$test_runtime/weston.stdout.log" 2>&1 < /dev/null &
printf '%s\n' "$!" >"$test_runtime/weston.pid"

# Poll for the compositor socket instead of waiting a long fixed interval.
for _ in $(seq 1 40); do
  test -S "$test_runtime/app-wayland-test" && break
  sleep 0.25
done
test -S "$test_runtime/app-wayland-test"
```

If the application needs the existing local daemon, obtain its port without
restarting or altering that daemon. Substitute the actual D-Bus names for other
projects.

```bash
ws_port=$(busctl --user get-property \
  org.waywallen.waywallen.Daemon \
  /org/waywallen/waywallen/Daemon \
  org.waywallen.waywallen.Daemon1 WsPort | awk '{print $2}')
```

Run the newly built client in the nested session. Temporary XDG configuration
and cache locations prevent its window-size persistence, UI preferences, and
cache writes from touching the user's main session.

```bash
setsid env \
  XDG_RUNTIME_DIR="$test_runtime" \
  XDG_CONFIG_HOME="$test_runtime/config" \
  XDG_CACHE_HOME="$test_runtime/cache" \
  WAYLAND_DISPLAY=app-wayland-test \
  QT_QPA_PLATFORM=wayland \
  /absolute/path/to/app-ui --ws-port "$ws_port" \
  >"$test_runtime/ui.log" 2>&1 < /dev/null &
printf '%s\n' "$!" >"$test_runtime/ui.pid"
```

Wait only until the initial page is loaded, then capture the **Xvfb root**:

```bash
DISPLAY=:98 import -window root "$test_runtime/desktop.png"
rg -n 'ReferenceError|TypeError|Cannot assign|failed to load|module .*not installed' \
  "$test_runtime/ui.log" || true
```

Inspect `desktop.png` with the environment's image-viewing capability. A clean
log plus an image from the freshly timestamped binary is the minimum evidence.

## Responsive and blur checks

To check a narrow layout, stop only `ui.pid`, edit the temporary config's
window width, and restart the UI with the same isolated environment. For Qt
`Settings` using the `window` category, a temporary INI typically contains:

```ini
[window]
width=560
height=632
```

Capture both desktop and compact screenshots. Verify that expected effects
appear in each, and inspect the QML source or effect diagnostics for any
condition that makes a `ShaderEffectSource` or `MultiEffect` invisible during
resize/transition states.

Do not use `QT_QPA_PLATFORM=offscreen` for this class of issue: it does not
exercise the real Wayland scene graph or the GPU effect path. Also do not rely
on `xdotool` alone for client-resize evidence; it interacts with Xvfb, whereas
the application is a Wayland client inside Weston.

## Cleanup

Only stop PIDs that were written by this test. Never use broad `pkill` patterns
for `weston`, the application name, or the daemon.

```bash
for pid_file in "$test_runtime/ui.pid" \
                "$test_runtime/weston.pid" \
                "$test_runtime/xvfb.pid"; do
  if test -r "$pid_file"; then
    test_pid=$(<"$pid_file")
    kill -0 "$test_pid" 2>/dev/null && kill "$test_pid" || true
  fi
done
```

Retain the test directory until screenshots and logs have been reviewed; remove
only that explicit directory when the evidence is no longer needed.
