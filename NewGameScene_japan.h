#ifndef __NEWGAMESCENE_JHAPAN_SCENE_H__
#define __NEWGAMESCENE_JHAPAN_SCENE_H__

#include "cocos2d.h"
#include "Player.h"


using namespace cocos2d::ui;
//using namespace cocostudio;
USING_NS_CC;
class BackgroundLayer_japan;
class Player;
class MonsterLayer;

//class MonsterLayer_japan;

class NewGameScene_japan : public cocos2d::Layer
{
public:
	~NewGameScene_japan();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual void onExit() override;
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
	// implement the "static create()" method manually
	CREATE_FUNC(NewGameScene_japan);
	void GoBack(cocos2d::Ref* pSender);
	//__________________________________________________
private:
	void logic(float dt);
	Player* m_player;
	bool onContactBegin(PhysicsContact& contact);
	BackgroundLayer_japan* m_backgroundLayer;

	Vector<Sprite *> allEnemy;
	void newEnemy_left(float t);
	void newEnemy_right(float t);
	void newEnemy_crow(float t);
	void moveEnemy(float t);
	void update(float t);
	void killMe(Node * pSender);
	void jumpToMenu();
	float start_point;
	int HP = 5;
	MonsterLayer* m_monsterLayer;
	cocos2d::Vec2 testTouchBegin;
};

#endif // __NEWGAMESCENE_JHAPAN_SCENE_H__
