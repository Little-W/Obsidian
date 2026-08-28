---
name: wayland-virtual-ui-debug
description: Debug and visually validate Qt Quick/QML applications in an isolated nested Wayland session. Use when a Wayland UI change needs screenshots, logs, or compact-layout checks without disrupting the user's active desktop; do not use as a general build or desktop-automation skill.
---

# Wayland Virtual UI Debug

Use a nested Weston compositor hosted in Xvfb when an application must run with a real
Wayland scene graph but its normal desktop session must remain untouched.

## Workflow

1. Build the application's normal release artifact first. Record its timestamp or
   checksum and do not draw conclusions from an older binary.
2. For an isolated Wayland session, follow
   [the nested-session procedure](references/nested-session.md). Keep the runtime,
   configuration, cache, screenshots, logs, and PID files under one `mktemp -d`
   directory.
3. Capture the Xvfb root window and inspect the resulting image. Scan the new UI
   log for QML load errors before treating a screenshot as validation.
4. Exercise both the ordinary and compact layout when a responsive component is
   involved. Use a temporary settings directory to set startup dimensions rather
   than modifying the user's real application settings.
5. Stop only the processes recorded in that test directory. Leave the user's
   compositor, daemon, and existing application instances alone.

## Interpretation limits

- Nested Weston verifies Qt Quick rendering, QML geometry, shader/effect loading,
  and screenshot-visible material behavior. It does **not** prove KWin-specific
  native effects such as `BlurBehind`; validate those once in the real KDE session.
- `xdotool` addresses the Xvfb host, not individual Wayland clients. Do not claim
  in-motion resize validation merely because it moved the nested compositor's
  host window. Use a compositor-aware test hook when one exists, or validate
  discrete temporary startup sizes and keep the result qualified.
- A UI connected to a real daemon may issue read-only status requests. Avoid clicks
  or keyboard actions that could apply wallpapers, change settings, or otherwise
  mutate the user's running system.
