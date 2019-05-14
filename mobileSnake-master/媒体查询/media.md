# Bootstrap媒体查询
在栅格系统中，我们在Less文件中使用以下媒体查询（media query）来创建关键的分界点阈值。
```css
/* 超小屏幕（手机，小于768px）*/
/* 没有任何媒体查询相关的代码，因为这在 Bootstrap 中是默认的 */

/* 小屏幕（平板，大于等于 768px） */
@media (min-width: @screen-sm-min) { ... }

/* 中等屏幕（桌面显示器，大于等于 992px） */
@media (min-width: @screen-md-min) { ... }

/* 大屏幕（大桌面显示器，大于等于 1200px） */
@media (min-width: @screen-lg-min) { ... }

```

我们偶尔也会在媒体查询代码中包含 max-width 从而将 CSS 的影响限制在更小范围的屏幕大小之内。

```css
@media (max-width: @screen-xs-max) { ... }
@media (min-width: @screen-sm-min) and (max-width: @screen-sm-max) { ... }
@media (min-width: @screen-md-min) and (max-width: @screen-md-max) { ... }
@media (min-width: @screen-lg-min) { ... }
```
# 栅格参数
通过下图可以详细查看 Bootstrap 的栅格系统是如何在多种屏幕设备上工作的。

![images text](https://raw.githubusercontent.com/jiaoshibo/mobileSnake/master/%E5%AA%92%E4%BD%93%E6%9F%A5%E8%AF%A2/media.PNG)