// function myFunction(that)
// {
//   // console.log(that.href)
//   var flag=false;
//   var x="",y="";
//   x=document.getElementById("user").value;
//   y=document.getElementById("password").value;
//   var tip=document.getElementById("tipMsg");
//   if(x==""||y==""){
//     tip.innerHTML="用户名或密码不能为空!";
//   }else if(x=="admin"&& y=="123456") {
//     tip.innerHTML="";
//     flag=true;
//
//     that.href="garde.html";
//   }else{
//     tip.innerHTML="用户名或密码错误!";
//   }
//   return flag;
// }


function myFunction()
{
  var flag=false;
  var x="",y="";
  x=document.getElementById("user").value;
  y=document.getElementById("password").value;
  var tip=document.getElementById("tipMsg");
  if(x==""||y==""){
    tip.innerHTML="用户名或密码不能为空!";
  }else if(x=="admin"&& y=="123456") {
    tip.innerHTML="";
    flag=true;
    document.getElementById("btn").href="timeTable.html";
  }else{
    tip.innerHTML="用户名或密码错误!";
  }
  return flag;
}
