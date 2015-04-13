#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d::ui;
//using namespace cocostudio;
USING_NS_CC;
class BackgroundLayer_japan;

class Setting : public cocos2d::Layer
{
public:
    ~Setting();
//	// there's no 'id' in cpp, so we recommend returning the class instance pointer
//	static cocos2d::Scene* createScene();
//	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//	virtual bool init();
//	virtual void onExit() override;
//	// a selector callback
//	void menuCloseCallback(cocos2d::Ref* pSender);
//
//	// implement the "static create()" method manually
    CREATE_FUNC(Setting);
//	void GoBack(cocos2d::Ref* pSender);
//	//__________________________________________________
//private:
//	void logic(float dt);
//	BackgroundLayer_japan* m_backgroundLayer;
    int sceneNumber = 0;
};

#endif // __SETTING_SCENE_H__
