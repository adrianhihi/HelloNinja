//#ifndef __HALLOWEEN_SCENE_H__
//#define __HALLOWEEN_SCENE_H__
//
//#include "cocos2d.h"
//#include "Player.h"
//
//
//
//USING_NS_CC;
//class BackgroundLayer_halloween;
//class Player;
//
//
//class Halloween : public cocos2d::Layer
//{
//public:
//	~Halloween();
//	// there's no 'id' in cpp, so we recommend returning the class instance pointer
//	static cocos2d::Scene* createScene();
//	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//	virtual bool init();
//	virtual void onExit() override;
//	// a selector callback
//	void menuCloseCallback(cocos2d::Ref* pSender);
//	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
//	virtual void onTouchMoved(Touch *touch, Event *unused_event);
//	virtual void onTouchEnded(Touch *touch, Event *unused_event);
//	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
//	// implement the "static create()" method manually
//	CREATE_FUNC(Halloween);
//	void GoBack(cocos2d::Ref* pSender);
//    int borderWidth;
//	//__________________________________________________
//private:
//	void logic(float dt);
//	Player* m_player;
//	bool onContactBegin(PhysicsContact& contact);
//	BackgroundLayer_halloween* m_backgroundLayer;
//
//	Vector<Sprite *> allEnemy;
//	void newEnemy_left(float t);
//	void newEnemy_right(float t);
//	void newEnemy_crow(float t);
//	void moveEnemy(float t);
//	void update(float t);
//	void killMe(Node * pSender);
//	void jumpToMenu();
//	float start_point;
//	int HP = 5;
//
//	cocos2d::Vec2 testTouchBegin;
//};
//
//#endif // __HALLOWEEN_SCENE_H__
#ifndef __NEWGAMESCENE_Halloween_SCENE_H__
#define __NEWGAMESCENE_Halloween_SCENE_H__

#include "cocos2d.h"
#include "Player.h"


using namespace cocos2d::ui;
//using namespace cocostudio;
USING_NS_CC;
class BackgroundLayer_halloween;
class Player;
class MonsterLayer;

//class MonsterLayer_japan;

class Halloween : public cocos2d::Layer
{
public:
	~Halloween();
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
	CREATE_FUNC(Halloween);
	void GoBack(cocos2d::Ref* pSender);
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

	const int iSpeed = -10;
	int score;

	void playerAbility_Teleportation(cocos2d::Ref* pSender);

	//__________________________________________________
private:
	int enemyNum;

	int enemyLeftRightDis;
	void logic(float t);
	Player* m_player;
	bool onContactBegin(PhysicsContact& contact);
	BackgroundLayer_halloween* m_backgroundLayer;

	Vector<Sprite *> allEnemyFallen;
	Vector<Sprite *> allEnemyRoof;
	Vector<Sprite *> allStar;
	Vector<Sprite *> allEnemyLeftCrow;
	Vector<Sprite *> allEnemyRightCrow;
	void newEnemy(float t);
	//	void newEnemy_crow(float t);
	void moveEnemyRoof(float t);
	void moveEnemyFallen(float t);
	void moveStar(float t);
	void moveEnemyRight(float t);
	void moveEnemyLeft(float t);
	void EnemyFlip();
	void update(float t);
	void killMe(Node * pSender);
	void jumpToMenu();
	float start_point;
	int HP = 3;
    int enemy_killed = 0;
	MonsterLayer* m_monsterLayer;
	cocos2d::Vec2 testTouchBegin;
    bool abilityButtonTouched = false;


};

#endif // __NEWGAMESCENE_Halloween_SCENE_H__
