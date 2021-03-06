//
//  QimiPlatformAndroid.cpp
//  Pay
//
//  Created by Ben on 6/18/13.
//
//


#include "QimiPlatformAndroid.h"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "PlatformUtilityHelper.h"

#endif

bool QimiPlatformAndroid::init()
{
    
    return true;
}

void QimiPlatformAndroid::openWeb(std::string webUrl, bool isFullScene)
{
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    openWebJNI(webUrl.c_str(), isFullScene);
    
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
}

void QimiPlatformAndroid::openAlert(std::string title, std::string msg)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    openAlertJNI(title.c_str(), msg.c_str());
#endif
}

std::string QimiPlatformAndroid::getDeviceId()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        return std::string(getDeviceIdJNI());
    #endif
    return "";
}




