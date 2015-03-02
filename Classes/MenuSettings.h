//
//  MenuSettings.h
//  game
//
//  Created by Xu Wu on 3/1/15.
//
//

#ifndef _MenuSettings_H_
#define _MenuSettings_H_

#include "MenuSettings.h"
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
    
};

#endif
