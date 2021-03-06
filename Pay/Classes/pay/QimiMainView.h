//
//  QimiMainView.h
//  Pay
//
//  Created by Ben on 6/24/13.
//
//

#ifndef __Pay__QimiMainView__
#define __Pay__QimiMainView__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "json.h"

USING_NS_CC;
USING_NS_CC_EXT;

class QimiMainView : public cocos2d::CCLayer
{
public:
    QimiMainView();
    ~QimiMainView();
    CREATE_FUNC(QimiMainView);
    bool init();
    
    void initView(std::string uId, int sId, std::string key, int money);
    void onRequestData();
    
    
private:
    
    std::string m_uId;
    int m_sId;
    std::string m_key;
    int m_money;
    int m_cash;
    std::string m_gameInfo;
    
    CCLabelTTF* m_pPassThroughNumTxt;
    CCLabelTTF* m_pMcashNumTxt;
    CCLabelTTF* m_pProductNameTxt;
    CCLabelTTF* m_pGameNameTxt ;
    CCLabelTTF* m_pMcashNumLastTxt;
    CCLabelTTF* m_pProductNameLastTxt;
    
    CCControlButton* m_pQimiPayBtn;
    std::string m_oderId;
    
private:
    
    void onLoadRequestSucssful(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
    void qimiConsumeMcashRequestSucssful(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
    void onUpdataView();
    void openPrepaidCard(int kind);
    void alipayOnClick(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void SzOnClick(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void LtOnClick(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void DxOnClick(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void backOnClick(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void qimiPay(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void qimiCz(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    void qimiHelp(cocos2d::CCNode* pSender, cocos2d::extension::CCControlEvent* pCCControlEvent);
    
    void rechargeOnClick();
    void onLoadOrderSucssful(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response);
    void loadAlixPay();
    
};

#endif /* defined(__Pay__QimiMainView__) */
