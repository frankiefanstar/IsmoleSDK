//
//  QimiPlatform.h
//  Pay
//
//  Created by Ben on 6/18/13.
//
//

#ifndef __Pay__QimiPlatform__
#define __Pay__QimiPlatform__


#include "cocos2d.h"

class QimiPlatformIOS;
class QimiPlatformAndroid;
class QimiUserModel;

class QimiPlatform : public cocos2d::CCObject
{
public:
    static QimiPlatform* shareQimiPlatform();
    bool initialize();
    /* 打开论坛的接口参数说明
     * 该接口可以在游戏中打开web网页
     * webUrl string 类型 网站网址。
     */
    void openGameWeb(std::string webUrl);
    
    /* 支付接口参数说明：
     * uId int类型 游戏的uId;
     * sId int类型 游戏的sId;
     * key string类型 游戏的key;
     * money int类型 需要支付的初始费用，进入支付系统后，可以再修改;
     */
    void openPayDailog(int uId, int sId, std::string key ,int money);
    
    /* 提示窗口
     * msg std::string 系统提示信息显示内容；
     * title 弹窗标题
     */
    void openAlertDailog(std::string title, std::string msg);
    
    /*
     * 获取用户id,uId;
     */
    int getUserId();
    
    /**
     * 登录和注册奇米平台
     */
    void QimiRegister();
    void QimiLogin();
    
    /*存入游戏的KEY值*/
    void setQimiGameKey(std::string key){m_key = key;};
    /*存入游戏的UId*/
    void setQimiGameUId(int uID){m_uId = uID;};
    /*存入游戏的sId*/
    void setQimiGameSId(int sID){m_sId = sID;};
    /*存入游戏的appId*/
    void setQimiGameAppId(int appId){m_appid = appId;};
    /*退出登录*/
    void loginOut();
    /*检测是否已登录*/
    bool isLogined();
    
    
    /*获得游戏的KEY值*/
    std::string getQimiGameKey(){ return m_key;};
    /*获得游戏的UId*/
    int getQimiGameUId(){return m_uId;};
    /*获得游戏的sId*/
    int getQimiGameSId(){return m_sId;};
    /*获得游戏的appId*/
    int getQimiGameAppId(){return m_appid;};
    
    //qimi
    QimiUserModel* getQimiUserModel(){return m_pQimiUserModel;};
    void setQimiUserModel(QimiUserModel* model){m_pQimiUserModel = model;};
    
private:
    QimiPlatformIOS*     m_pQimiPlatformIOS;
    QimiPlatformAndroid* m_pQimiPlatformAndroid;
    QimiUserModel*       m_pQimiUserModel;
    std::string          m_key; //游戏的KEY值
    int                  m_uId; //uid
    int                  m_sId; //用户ID
    int                  m_appid; //游戏的APPID
    
private:

    
    
    
    
};

#endif /* defined(__Pay__QimiPlatform__) */
