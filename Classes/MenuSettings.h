

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
    void goback(cocos2d::Ref *pSender);
    
    void pauseMusicCallback(cocos2d::Ref *pSender);
    void recoverMusicCallback(cocos2d::Ref *pSender);
    void credits(cocos2d::Ref *pSender);
    
    CREATE_FUNC(MenuSettings);
	bool isPause;
    float bg_scale;
    MenuItemImage *_turnOn, *_turnOff, *menuItem, *creditItem;
    //MenuItemFont *creditItem;
private:
    Sprite* bg;
};

#endif
