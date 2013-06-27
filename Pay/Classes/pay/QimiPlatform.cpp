//
//  QimiPlatform.cpp
//  Pay
//
//  Created by Ben on 6/18/13.
//
//

#include "QimiPlatform.h"
#include "QimiPlatformIOS.h"
#include "QimiPlatformAndroid.h"
#include "QimiParamInfo.h"
#include "StageScene.h"
#include "IntObject.h"
#include "QimiMainView.h"
#include "QimiLoginView.h"
#include "QimiRegisterView.h"
#include "QimiUserModel.h"

#include "md5c.h"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)


#endif // CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)


#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID


static QimiPlatform* s_pQimiPlatform = NULL;

QimiPlatform* QimiPlatform::shareQimiPlatform()
{
    if (s_pQimiPlatform == NULL)
    {
        s_pQimiPlatform = new QimiPlatform();
        s_pQimiPlatform->initialize();
    }
    return s_pQimiPlatform;
}

bool QimiPlatform::initialize()
{   
    m_appid         = 0;
    m_sId           = 0;
    m_key           = "";
    m_uId           = "";
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pQimiPlatformIOS = QimiPlatformIOS::create();
    m_pQimiPlatformIOS->retain();
    #endif

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    m_pQimiPlatformAndroid = QimiPlatformAndroid::create();
    m_pQimiPlatformAndroid->retain();
    #endif
    return true;
}

void QimiPlatform::setParamInfo(QimiParamInfo *pQimiParamInfo)
{
    m_appid = pQimiParamInfo->getAppID();
    m_sId   = pQimiParamInfo->getSID();
    m_key   = pQimiParamInfo->getAppKey();
}


void QimiPlatform::openGameWeb(std::string webUrl)
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pQimiPlatformIOS->openWeb(webUrl);
    #endif
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    m_pQimiPlatformAndroid->openWeb(webUrl);
    #endif
}


void QimiPlatform::openAlertDailog(std::string title, std::string msg)
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pQimiPlatformIOS->openAlert(title, msg);
    #endif
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    m_pQimiPlatformAndroid->openAlertDailog(title, msg);
    #endif
}

void QimiPlatform::openPayDailog(std::string uId, int sId, std::string key, int money)
{
    QimiMainView* qimiManView = QimiMainView::create();
    StageScene::shareStageScene()->m_DialogContainer->addChild(qimiManView);
    qimiManView->initView(uId, sId, key, money);
}

void QimiPlatform::QimiRegister()
{
    QimiRegisterView* pRegisterView = QimiRegisterView::create();
    StageScene::shareStageScene()->m_DialogContainer->addChild(pRegisterView);
    pRegisterView->setPosition(ccp(0, 0));
}

void QimiPlatform::QimiLogin()
{
    QimiLoginView* pLoginView = QimiLoginView::create();
    StageScene::shareStageScene()->m_DialogContainer->addChild(pLoginView);
    pLoginView->setPosition(ccp(0, 0));
}

void QimiPlatform::loginOut()
{
    if (m_pQimiUserModel !=NULL) {
        m_pQimiUserModel->release();
        m_pQimiUserModel = NULL;
    }
    QimiPlatform::shareQimiPlatform()->openAlertDailog("系统提示", "退出登录成功！");
}

void QimiPlatform::registerPayCallBack(cocos2d::CCObject* target, cocos2d::SEL_CallFuncO call)
{
    m_PayTarget = target;
    m_payCall   = call;
}

void QimiPlatform::registerLoginCallBack(cocos2d::CCObject* target, cocos2d::SEL_CallFuncO call)
{
    m_LoginTarget = target;
    m_LoginCall   = call;
}

void QimiPlatform::registerRegCallBack(cocos2d::CCObject* target, cocos2d::SEL_CallFuncO call)
{
    m_RegTarget = target;
    m_RegCall = call;
}

void QimiPlatform::callPayBack(CCObject* obj)
{
    if (m_payCall && m_PayTarget)
    {
        (m_PayTarget->* m_payCall)(obj);
    }
}

void QimiPlatform::callLoginBack(cocos2d::CCObject*obj)
{
    if (m_LoginCall && m_LoginTarget)
    {
        (m_LoginTarget->* m_LoginCall)(obj);
    }
}

void QimiPlatform::callRegBack(cocos2d::CCObject* obj)
{
    if (m_RegCall && m_RegTarget)
    {
        (m_RegTarget->* m_RegCall)(obj);
    }
}

/*检测是否已登录*/
bool QimiPlatform::isLogined()
{
    if (m_pQimiUserModel!=NULL && !m_pQimiUserModel->getuID().empty())
    {
        return true;
    }
    return false;
}

bool QimiPlatform::isCheckAppId()
{
    return m_appid ? true : false;
}
//检查是否获得APP ID

bool QimiPlatform::isCheckAppKey()
{
    return m_key.empty() ? false : true;
}//检查是否已获得APP KEY

