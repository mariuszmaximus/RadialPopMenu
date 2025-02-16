# RadialPopMenu
放射式弹出菜单

![popmenu](https://github.com/user-attachments/assets/53a60501-f0ac-4b06-a73e-8cfeddef706a)

## 支持特性：

* 可设置弹出选项的起始角度与角度范围

* 按住中心按钮，可以拖拽窗口

* 动画支持，可以设置动画时间、选项的延迟弹出

* 设置菜单的布局对齐、边距，方便根据场景放置在各个位置

## 未完善部分

* 动画仅支持线性动画
  
* 使用QToolButton实现了圆形按钮，没有支持默认样式，需要自行实现

* 展开角度等于2PI时，首尾会重叠，考虑到不同场景的需求，不特殊处理

## 动画的实现原理

为了支持菜单项弹出时延迟间隔，使用了一个QVariantAnimation触发[0,1]范围的值变化，动画范围包含了从点击开始到所有菜单项弹出后的动画时间，这点与实际设置的动画duration有差异

当动画的值变化时，获取动画的当前时刻，减掉各个菜单项的延迟时间，就得到了该菜单项的实际动画时刻

使用QTimeLine获取指定时刻的进度，再换算到坐标

尽管QTimeLine的接口更丰富，但默认情况下，动画的精度要比QVariantAnimation更差，能明显看出卡顿，因此使用QVariantAnimation实现进度变化，使用QTimeLine计算实际的坐标

# RadialPopMenu
Radial Popup Menu

![popmenu](https://github.com/user-attachments/assets/53a60501-f0ac-4b06-a73e-8cfeddef706a)

## Supported Features:

* The starting angle and angle range of popup options can be set.

* Holding the center button allows dragging the window.

* Animation support, with configurable animation duration and delayed popup of options.

* Menu layout alignment and margins can be adjusted for flexible placement in different scenarios.

## Incomplete Parts

* The animation currently only supports linear animation.

* The circular button is implemented using `QToolButton`, but it does not support the default style and needs to be customized manually.

* When the expansion angle equals `2PI`, the first and last items overlap. This is not specially handled to accommodate different use cases.

## Animation Implementation Principle

To support delayed intervals when menu items pop up, a `QVariantAnimation` is used to trigger value changes in the range `[0,1]`. The animation duration covers the entire time from clicking the button to all menu items being fully expanded, which differs from the actual animation duration setting.

When the animation value changes, the current animation time is obtained. Subtracting the delay time of each menu item gives the actual animation time for that item.

A `QTimeLine` is used to get the progress at a specific moment and convert it into coordinates.

Although `QTimeLine` provides richer interfaces, its default animation precision is lower than `QVariantAnimation`, resulting in noticeable lag. Therefore, `QVariantAnimation` is used to control the progress change, while `QTimeLine` is used to calculate the actual coordinates.
