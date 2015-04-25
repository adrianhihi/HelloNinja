#ifndef __planegame__GameOver__
#define __planegame__GameOver__

#include <cocos2d.h>
USING_NS_CC;

class GameOver : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameOver);
	bool init();
    float bg_scale;
	static cocos2d::Scene * createScene();
	void menuCallBack(cocos2d::Ref * pSender);
    void restart(cocos2d::Ref * pSender);
};



#endif /* defined(__planegame__GameOver__) */
