# KDE Kinetic Squash 首次最小化动画热补丁

## 现象

在 KDE Plasma 6.7.4 / KWin Wayland 中，窗口在以下情况的**首次最小化**经常直接消失、不播放 Kinetic Squash 动画：

- 切换到另一个虚拟桌面后；
- 新窗口刚打开后。

后续最小化通常恢复正常。

## 定位

当前启用的最小化特效是用户目录中的第三方 KWin JavaScript 效果 `kinetic_squash`，不是 KWin 内置的最小化效果：

```text
~/.local/share/kwin/effects/kinetic_squash/
```

原始脚本在读取 `window.iconGeometry` 后包含以下逻辑：

```js
var iconRect = window.iconGeometry;
if (iconRect.width == 0 || iconRect.height == 0) {
    return;
}
```

`iconGeometry` 由任务管理器提供。窗口刚建立或切换虚拟桌面后，任务管理器可能尚未上报图标位置；脚本于是直接退出，动画被跳过。这与“首次最小化丢动画”的现象完全一致。

## 热补丁

修改文件：

```text
~/.local/share/kwin/effects/kinetic_squash/contents/code/main.js
```

补丁保留正常情况：有有效 `iconGeometry` 时，窗口仍精确飞向任务栏图标。

当图标位置不存在时，改为使用窗口所在屏幕的**底部中央**作为 1×1 像素动画目标：

```js
function fallbackIconRect(window) {
    var screen = window.screen || effects.activeScreen;
    var screenRect = screen ? screen.geometry : effects.virtualScreenGeometry;

    return {
        x: screenRect.x + (screenRect.width - 1) / 2,
        y: screenRect.y + screenRect.height - 1,
        width: 1,
        height: 1
    };
}

function iconTargetRect(window) {
    var iconRect = window.iconGeometry;
    if (iconRect && iconRect.width > 0 && iconRect.height > 0) {
        return iconRect;
    }
    return fallbackIconRect(window);
}
```

效果：

- 正常时：飞向准确的任务栏图标；
- 图标几何位置暂不可用时：飞向该屏幕底部中央；
- 不再因为空几何值直接丢失最小化或恢复动画。

## 让补丁生效

不需要重启 Plasma 桌面，也不建议在 Wayland 会话中重启 KWin 合成器。

KWin 会在收到 `Plugins/*Enabled` 的配置变更通知时卸载并重新加载该特效。仅调用 `qdbus6 org.kde.KWin /KWin reconfigure` 不保证重建 JavaScript 引擎，因此需要使用 `kwriteconfig6 --notify` 来切换一次：

```sh
kwriteconfig6 --file kwinrc --group Plugins --key kinetic_squashEnabled --type bool --notify false
sleep 1
kwriteconfig6 --file kwinrc --group Plugins --key kinetic_squashEnabled --type bool --notify true
```

验证特效已重新加载：

```sh
qdbus6 org.kde.KWin /KWin supportInformation | grep kinetic_squash
```

预期输出包含：

```text
kinetic_squash
```

## 验证场景

1. 切换到另一个虚拟桌面，然后首次最小化窗口；
2. 新打开一个窗口，然后首次最小化；
3. 若任务栏图标位置尚未准备好，观察窗口缩向当前屏幕底部中央而不是瞬间消失。

## 回滚

修改前备份位于：

```text
~/.local/share/kwin/effects/kinetic_squash/contents/code/main.pre-icon-geometry-fallback.js
```

恢复原始脚本并热重载：

```sh
cp -p ~/.local/share/kwin/effects/kinetic_squash/contents/code/main.pre-icon-geometry-fallback.js \
  ~/.local/share/kwin/effects/kinetic_squash/contents/code/main.js

kwriteconfig6 --file kwinrc --group Plugins --key kinetic_squashEnabled --type bool --notify false
sleep 1
kwriteconfig6 --file kwinrc --group Plugins --key kinetic_squashEnabled --type bool --notify true
```
