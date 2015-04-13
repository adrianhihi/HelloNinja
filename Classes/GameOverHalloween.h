//
//  GameOverHalloween.h
//  Ninja
//
//  Created by Haimo Bai on 4/2/15.
//
//

#ifndef __Ninja__GameOverHalloween__
#define __Ninja__GameOverHalloween__

#include <cocos2d.h>
USING_NS_CC;

class GameOverHalloween : public cocos2d::Layer
{
public:
    CREATE_FUNC(GameOverHalloween);
    bool init();
    float bg_scale;
    static cocos2d::Scene * createScene();
    void menuCallBack(cocos2d::Ref * pSender);
    void restart(cocos2d::Ref * pSender);
};


#endif /* defined(__Ninja__GameOverHalloween__) */
