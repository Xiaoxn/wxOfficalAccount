/*
 *  说明：数据字典类
 */

#ifndef CONSTDATA_H
#define CONSTDATA_H

#include <QString>
#include <QStringList>

// 网络响应异常
const QString c_sNetError = QStringLiteral("网络连接异常");
const QString c_sServerJsonError = QStringLiteral("服务器数据异常");

//接口类型
const QString c_sWinXinRequestUrl = "https://api.weixin.qq.com";    //微信端请求域名
const QString c_sHttpGetAccessTokenAction = "/cgi-bin/token";       //获取token验证接口
const QString c_SHttpCreateMenuAction = "https://api.weixin.qq.com/cgi-bin/menu/create?access_token=";   //创建小程序菜单接口

//消息类型
const QString c_sEvent = "event";    //事件推送
const QString c_sMsg = "text";       //信息推送

//事件推送类型
const QString c_sSubscribe = "subscribe";   //关注事件
const QString c_sUnsubscribe = "unsubscribe";  //取关事件
const QString c_sClicked = "CLICK";           //点击事件

//自定义回复内容
static QStringList c_sMsgRecList = {
    QStringLiteral("亲爱的同学，你好啊欢迎关注涉外公众号，实时掌握学院最新动态。"),
    QStringLiteral("如需帮助，请点击右下方的联系我们."),
    QStringLiteral("今天天气晴."),
    QStringLiteral("周二晚上六弦在芙蓉湖旁边卖唱.")
};

#endif // CONSTDATA_H
