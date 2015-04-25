//
//  HighScore.h
//  ninjaMidterm
//
//  Created by ZhaoLei on 4/22/15.
//
//

#ifndef __ninjaMidterm__HighScore__
#define __ninjaMidterm__HighScore__

#include <cocos2d.h>
USING_NS_CC;

class HighScore: public cocos2d::Layer
{
public:
    CREATE_FUNC(HighScore);
    bool init();
    static cocos2d::Scene * createScene();
    void setHighScore(int currentScore);
    int score[5];

private:
    void goback(cocos2d::Ref *pSender);
    
};

#endif /* defined(__ninjaMidterm__HighScore__) */
