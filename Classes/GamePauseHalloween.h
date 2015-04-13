//
//  GamePauseHalloween.h
//  Ninja
//
//  Created by Haimo Bai on 4/2/15.
//
//

#ifndef __Ninja__GamePauseHalloween__
#define __Ninja__GamePauseHalloween__

#include "cocos2d.h"
#include "NewGameScene_halloween.h"

USING_NS_CC;

class GamePauseHalloween : public cocos2d::Layer
{
public:
    
    ~GamePauseHalloween();
    static cocos2d::Scene* createScene();
    bool init();
    void goback(CCObject*);
    void resumegame(CCObject*);
    CREATE_FUNC(GamePauseHalloween);
    void pauseMusicCallback(CCObject* pSender);
    void recoverMusicCallback(CCObject* pSender);
    void restart(CCObject* pSender);
    bool isPause = false;
    float bg_scale;
private:
    
    Sprite *bg;
};


#endif
