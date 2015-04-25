//
//  GameOverSea.h
//  ninjaMidterm
//
//  Created by ZhaoLei on 4/19/15.
//
//

#ifndef __ninjaMidterm__GameOverSea__
#define __ninjaMidterm__GameOverSea__

#include <cocos2d.h>
USING_NS_CC;

class GameOverSea : public cocos2d::Layer
{
public:
    CREATE_FUNC(GameOverSea);
    bool init();
    float bg_scale;
    static cocos2d::Scene * createScene();
    void menuCallBack(cocos2d::Ref * pSender);
    void restart(cocos2d::Ref * pSender);
};

#endif /* defined(__ninjaMidterm__GameOverSea__) */
