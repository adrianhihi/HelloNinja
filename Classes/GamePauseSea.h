//
//  GamePauseSea.h
//  ninjaMidterm
//
//  Created by ZhaoLei on 4/19/15.
//
//

#ifndef __ninjaMidterm__GamePauseSea__
#define __ninjaMidterm__GamePauseSea__

#include "cocos2d.h"
#include "NewGameScene.h"

USING_NS_CC;

class GamePauseSea : public cocos2d::Layer
{
public:
    
    ~GamePauseSea();
    static cocos2d::Scene* createScene();
    bool init();
    void goback(CCObject*);
    void resumegame(CCObject*);
    CREATE_FUNC(GamePauseSea);
    void pauseMusicCallback(CCObject* pSender);
    void recoverMusicCallback(CCObject* pSender);
    void restart(CCObject* pSender);
    bool isPause = false;
    float bg_scale;
private:
    
    Sprite *bg;
};

#endif /* defined(__ninjaMidterm__GamePauseSea__) */
