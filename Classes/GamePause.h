
#ifndef xuwutest_GamePause_h
#define xuwutest_GamePause_h
#include "cocos2d.h"
#include "NewGameScene_japan.h"

USING_NS_CC;

class GamePause : public cocos2d::Layer
{
public:
    
    ~GamePause();
    static cocos2d::Scene* createScene();
    bool init();
    void goback(CCObject*);
    void resumegame(CCObject*);
    CREATE_FUNC(GamePause);
    void pauseMusicCallback(CCObject* pSender);
    void recoverMusicCallback(CCObject* pSender);
    void restart(CCObject* pSender);
    bool isPause = false;
    float bg_scale;
private:
    
    Sprite *bg;
};


#endif
