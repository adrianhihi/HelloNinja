//
//  Credits.h
//  xuwutest
//
//  Created by Xu Wu on 3/6/15.
//
//

#ifndef xuwutest_Credits_h
#define xuwutest_Credits_h

#include "cocos2d.h"
#include "NewGameScene_japan.h"
#include "MenuSettings.h"

USING_NS_CC;

class Credits : public cocos2d::Layer
{
public:
    
    ~Credits();
    static cocos2d::Scene* createScene();
    bool init();
    CREATE_FUNC(Credits);
    void closeCallback(CCObject*);
    float bg_scale;
private:
    Sprite *bg;
  
};


#endif
