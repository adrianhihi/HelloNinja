#ifndef __NEWGAME_SCENE_H__
#define __NEWGAME_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d::ui;
//using namespace cocostudio;
USING_NS_CC;
class BackgroundLayer;
class Player;
class MonsterLayer;

class NewGame : public cocos2d::Layer
{
public:
	~NewGame();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual void onExit() override;
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	//void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event * event4);
	// implement the "static create()" method manually
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	CREATE_FUNC(NewGame);
	void GoBack(cocos2d::Ref* pSender);
	//__________________________________________________
private:
	void logic(float dt);
//	void createOprUI();
//	//void createTouch();
//	void moveToLeft(Ref* sender, TouchEventType type);
//	void moveToRight(Ref* sender, TouchEventType type);
//	void quickMove(Ref* sender, TouchEventType type);
//	void moveDown(Ref* sender, TouchEventType type);

	//int flag = 0;
	bool onContactBegin(PhysicsContact& contact);
	BackgroundLayer* m_backgroundLayer;
	Player* m_player;
	MonsterLayer* m_monsterLayer;
};

#endif // __NEWGAME_SCENE_H__

