

#ifndef _MenuSettings_H_
#define _MenuSettings_H_

#include "HelloWorldScene.h"
#include "cocos2d.h"

USING_NS_CC;
class MenuSettings : public cocos2d::Layer
{
public:
    
    ~MenuSettings();
    static cocos2d::Scene* createScene();
    bool init();
    void goback(CCObject*);
    CREATE_FUNC(MenuSettings);
    void pauseMusicCallback(CCObject* pSender);
    void recoverMusicCallback(CCObject* pSender);
	bool isPause = false;
};

#endif
