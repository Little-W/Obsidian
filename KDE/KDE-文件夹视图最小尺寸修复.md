# KDE 文件夹视图最小尺寸修复

## 现象

在 KDE Plasma 6.7.4 的桌面上添加“文件夹视图”（`org.kde.plasma.folder`）小组件后，虽然可以调整大小，但缩小到约 **3 列 × 2 行** 图标单元格时就无法继续缩小。

这不是用户配置或布局网格导致的限制，而是文件夹视图的 QML 布局代码把默认尺寸同时当成了最小尺寸。

## 定位

实际使用的界面实现来自桌面容器包：

```text
/usr/share/plasma/plasmoids/org.kde.desktopcontainment/contents/ui/main.qml
```

原始代码为：

```qml
dropArea.Layout.minimumWidth = Qt.binding(() => root.preferredWidth(root.isPopup))
dropArea.Layout.minimumHeight = Qt.binding(() => root.preferredHeight(root.isPopup))

dropArea.Layout.preferredWidth = Qt.binding(() => root.preferredWidth(false))
dropArea.Layout.preferredHeight = Qt.binding(() => root.preferredHeight(false))
```

`root.isPopup` 在桌面上的文件夹小组件中为 `false`，因此最小尺寸会使用 `preferredWidth(false)` 和 `preferredHeight(false)`：即默认的 **3 列 × 2 行**。而函数在传入 `true` 时会返回 1 个图标单元格的最小尺寸。

上游 Plasma Desktop 当前源码也保留了等价逻辑，因此此问题并非本机安装损坏。

## 修复方案

没有修改 `/usr` 下的系统文件，而是建立了用户级 KPackage 覆盖包：

```text
~/.local/share/plasma/plasmoids/org.kde.desktopcontainment/
```

修改后的布局绑定：

```qml
dropArea.Layout.minimumWidth = Qt.binding(() => root.preferredWidth(true))
dropArea.Layout.minimumHeight = Qt.binding(() => root.preferredHeight(true))

dropArea.Layout.preferredWidth = Qt.binding(() => root.preferredWidth(false))
dropArea.Layout.preferredHeight = Qt.binding(() => root.preferredHeight(false))
```

效果：

- 新增文件夹视图时，默认尺寸仍为约 3 列 × 2 行；
- 桌面文件夹视图可继续缩小至约 1 个图标单元格；
- 面板中的文件夹视图原有的最小尺寸逻辑不变；
- 开启标题/标签时，最小高度会额外包含标签高度。

## 应用与验证

安装后已刷新 KDE 的服务缓存，并重启 Plasma Shell：

```sh
systemctl --user restart plasma-plasmashell.service
```

验证加载路径：

```sh
kpackagetool6 --type Plasma/Applet --show org.kde.desktopcontainment
```

输出中的 `Path` 应为：

```text
/home/yusen/.local/share/plasma/plasmoids/org.kde.desktopcontainment/
```

## 撤销方法

删除用户级覆盖包并重启 Plasma Shell，即可恢复发行版原始行为：

```sh
kpackagetool6 --type Plasma/Applet --remove org.kde.desktopcontainment
systemctl --user restart plasma-plasmashell.service
```

## 后续维护

该覆盖包不会被系统包更新直接覆盖。未来升级 Plasma 后，如果上游已经修复此问题，可先执行上述“撤销方法”，再检查默认行为是否已满足需求。
