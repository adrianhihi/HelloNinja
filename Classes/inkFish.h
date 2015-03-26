//
//  inkFish.h
//  HelloNinja
//
//  Created by 黑眼圈笨 on 15/3/11.
//
//

#ifndef __HelloNinja__inkFish__
#define __HelloNinja__inkFish__

#include "cocos2d.h"

using namespace cocos2d::ui;

USING_NS_CC;


class InkFish : public cocos2d::Layer
{
public:
    ~InkFish();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    virtual bool init();
    int borderWidth;
    
    float bg_scale;
    Size bg_size;
    Point bg_origin;
    
    enum Scene_Tag :int
    {
        border1 = 1000,
        border2 = 1001,
        border3 = 1002,
        border4 = 1003,
        player = 0,
    };
    
    //const int iSpeed = -10;
    //int score;
    
    void playerAbility_Teleportation(cocos2d::Ref* pSender);private:
    void logic(float dt);
    
};

#endif /* defined(__HelloNinja__inkFish__) */
