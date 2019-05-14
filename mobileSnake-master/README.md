# 贪吃蛇
源代码地址：https://github.com/jiaoshibo/mobileSnake
* 在手机浏览器上的显示效果

![images text](https://raw.githubusercontent.com/jiaoshibo/images/master/img/snake.png)
## 贪吃蛇的基本框架
首先确定蛇的移动区域，由一组'ul'标签构成，给予'ul'一个宽高，就组成了蛇的活动区域。'li'标签构成了蛇的身体和行进路线，以及蛇的食物，由不同的色块进行区分。'li'标签是在js文件里进行添加的，这个后面再提。
```html
<div class="bigbox" id="box">
    <ul id="ulBox"></ul>
</div>
```
接下来设置游戏的难度选项，用一组"select"标签和三个"option"标签构成了游戏的三个不同的难度等级。游戏的分数记录以及开始、暂停等按键我们也一并设置。

```html
<div class="pp">
    <p>最高分：<span id="max">0</span></p>
    <p>当前得分：<span id="now">0</span></p>
</div>
<select name="" id="level">
    <option value="">简单</option>
    <option value="">中等</option>
    <option value="">困难</option>
</select>
<input type="button" id="start" value="START">
<input type="button" id="timeOut" value="TIME OUT">
```
为了适配移动端各种屏幕分辨率，我们在 css 里使用媒体查询。
```css
@media screen and (min-width: 320px) {
    html {
        font-size: 100px;
    }
}

@media screen and (min-width: 360px) {
    html {
        font-size: 112px;
    }
}
/* 以最小宽度320px为基准 */
ul{
    width: 3.18rem;
    height: 3.18rem;
    border: 0.01rem solid #8312D5;
}
li{
    width: 0.159rem;
    height: 0.159rem;
    float: left;
}
```
> 贪吃蛇的框架补全
在'ul'里添加'li'要创建400个'li'来作为贪吃蛇的活动场所。使用for循环将'li'添加到'ul'中

```javascript
var lis=[];
function initSpace(){
    var frag=document.createDocumentFragment();
    for(var i=0;i<400;i++){
        var lidom=document.createElement("li");
        lidom.innerHTML=i//显示坐标
        ulBox.appendChild(lidom);
    }
    ulBox.appendChild(frag)
    lis=ulBox.children
}
```
* 下面是效果

![images text](https://raw.githubusercontent.com/jiaoshibo/images/master/img/img1.PNG)

> 初始化蛇的位置以及蛇的食物
```javascript
var snake=[{pos:0,color:"#666"},{pos:1,color:"blue"},{pos:2,color:"green"},{pos:3,color:"red"},{pos:4,color:"#82286c"}]

var food={pos:0,color:"red"}
```
> 初始化蛇的状态
```javascript
function randColor(){
    return "rgb("+Math.floor(Math.random()*256)+","+Math.floor(Math.random()*256)+","+Math.floor(Math.random()*256)+")";
}

function initSnake(){
    for(var i=0;i<snake.length;i++){
        lis[snake[i].pos].style.backgroundColor=snake[i].color;
    }
}
```
> 初始化蛇的食物。食物的位置随机生成的，我们还要保证食物生成的时候不会出现在蛇的身体内，就需要进行判定.
```javascript
function isinSnake(index){
    for(var i=0;i<snake.length;i++){
        if(snake[i].pos===index){
            return true;
            break;
        }
    }return false;
}

function initFood(){
    var index = Math.floor(Math.random()*400);
    //判定：如果 food 的值在 snake 的数组里，则直接生成一个新的随机值
    while(isinSnake(food)){
        index=Math.floor(Math.random()*400);
    }
    food={pos:index,color:randColor()};
    lis[food.pos].style.backgroundColor=food.color;
}
```
> 设置蛇的运动

```javascript
function snakeMove(){
    var snakeHead = snake.slice(-1)[0].pos;//确定蛇头的位置
    var sankeTail = snake.slice(0,1)[0].pos;//蛇尾
    lis[snakeTail].style.backgroundColor = "#fff";
    for(var i=0,l=snake.length;i<l-1;i++){
        snake[i].pos=snake[i+1].pos;
    }
}

start.onclick=function(){
    snakeMove();
}
initSnake();
```
> 控制蛇的运动方向。
```javascript
var fangxiang = 39 //39 right;40 down;37 left; 38 up;
//键位的绑定
document.addEventListener("keydown",function(a){
    a = a||window.event;
    switch(a.keyCode){
        case 37:{
            //left
            if(fangxiang==39)return false;
            fangxiang=a.keyCode;
            break;
            
        }
        case 38:{
            //up
            if(fangxiang==40)return false;
            fangxiang=a.keyCode;
            break;
        }
        case 39:{
            //right
            if(fangxiang==37)return false;
            fangxiang=a.keyCode;
            break;
        }
        case 40:{
            //down
            if(fangxiang==38)return false;
            fangxiang=a.keyCode;
            break;
        }
    }
},false);
```
为了能在移动设备上运行，我们还需要引入‘touch.js’，添加滑动操作
```javascript
box.touch({
    swipeDown:function(){
       sw(40);
    },
    swipeLeft:function(){
       sw(37);
    },
    swipeUp:function(){
        sw(38);
    },
    swipeRight:function(){
        sw(39)
    }
})

function sw(e){
    switch(e){
        case 40:{
            if(fangxiang==38)return false;
            fangxiang=e;
            break;
        }
        case 37:{
            if(fangxiang==39)return false;
            fangxiang=e;
            break;
        }
        case 38:{
            if(fangxiang==40)return false;
            fangxiang=e;
            break;
        }
        case 39:{
            if(fangxiang==37)return false;
            fangxiang=e;
            break;
        }
    }
}
```
> 控制蛇的运动方向，以及蛇吃食物
```javascript
function snakeMove(){
     if(fangxiang==40){//down
        snake[l-1].pos=snake[l-1].pos+20
    }else if(fangxiang==37){//left
        snake[l-1].pos=snake[l-1].pos-1
    }else if(fangxiang==38){//up
        snake[l-1].pos=snake[l-1].pos-20
    }else if(fangxiang==39){//right
        snake[l-1].pos=snake[l-1].pos+1
    }
    snakeHead=snake[l-1].pos;

    if(snakeHead==food.pos){
        snake.unshift({pos:snakeTail,color:food.color});
        initFood();
    }
}
```
> 蛇的碰撞检测，包括边界检测和自身碰撞检测

```javascript
function snakeMove(){
    var snakeHead = snake.slice(-1)[0].pos;
    //墙的碰撞检测
    if((snakeHead+1)%20==0&&fangxiang==39){//右边界的判断
        alert("GAME OVER!!!");
        location.reload();
        return false;
    }else if((snakeHead+20)>399&&fangxiang==40){//下边界的判断
        alert("GAME OVER!!!");
        location.reload();
        return false;
    }else if(snakeHead<20&&fangxiang==38){//上边界的判断
        alert("GAME OVER!!!");
        location.reload();
        return false;
    }else if(snakeHead%20==0&&fangxiang==37){//左边界检测
        alert("GAME OVER!!!");
        location.reload();
        return false;
    }

    //自身碰撞检测
    for(var i=0,l=snake.length;i<l-1;i++){
        if(snake[i].pos==snakeHead){
            alert("GAME OVER!!!");
            location.reload();
            return false;
        }
    }
}
```

### 扫尾工作
> 分数的计算。蛇每次吃食物就加一份，gameover的时候计算最高分
```javascript
// 初始化最高分
var score = localStorage.getItem("score")||0;
max.innerHTML=score;
// 最高分
var l=sanke.length;
if((l-5)>score){
    localStorage.setItem("score",l-5);
}
```
> 设置游戏难度。利用‘option’的value值来控制游戏的难度
```html
<option value="500">简单</option>
<option value="300">中等</option>
<option value="200">困难</option>
```
* 初始化速度为500
```javascript
var speed = 500;
```
* 按下开始按钮启动一个定时器，蛇就可以自动往前运动了。
```javascript
var timer=null
start.onclick=function(){//开始游戏
    //难度等级
    speed=level.value;
    //蛇的运动
    clearInterval(timer);
    timer=setInterval(snakeMove,speed);
    //背景音乐
    bgm.play();
}
timeOut.onclick=function(){//暂停游戏
    clearInterval(timer);
}
```
就酱，我们的贪吃蛇小游戏就编辑完成啦。
