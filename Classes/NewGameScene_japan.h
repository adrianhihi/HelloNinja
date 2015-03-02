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
    int borderWidth;
	//__________________________________________________
private:
    
    int enemyNum;
    int enemyLeftRightDis;
    void logic(float t);
	Player* m_player;
	bool onContactBegin(PhysicsContact& contact);
	BackgroundLayer_japan* m_backgroundLayer;

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
	MonsterLayer* m_monsterLayer;
	cocos2d::Vec2 testTouchBegin;
};

#endif // __NEWGAMESCENE_JHAPAN_SCENE_H__
