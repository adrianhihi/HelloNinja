#ifndef __NEWGAME_SCENE_H__
#define __NEWGAME_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d::ui;
//using namespace cocostudio;
USING_NS_CC;

class Player;




class NewGameScene : public cocos2d::Layer
{
public:
    ~NewGameScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    //virtual void onExit() override;
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);
    // implement the "static create()" method manually
    CREATE_FUNC(NewGameScene);
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
        menu = 2001,
        skill_button = 2002,
        item_0 = 2003,
        item_1 = 2004,
        player = 0,
    };
    
    int iSpeed = -10;
    int score;
    
    int item_Array[2];
    enum item_type :int
    {
        none_item = 0,
        star = 1,
    };
    int current_skill;
    enum skill_type :int
    {
        none_skill = 0,
        teleport = 1,
    };
    
    //Sprite * item0;
    //Sprite * item1;
    
    void create_skill(cocos2d::Ref* pSender);
    void use_skill(cocos2d::Ref* pSender);
    
    void playerAbility_Teleportation();
    void push_item(int item);
    void clear_item();
    
    //__________________________________________________
private:
    int enemyNum;
    int speedTime;
    
    int enemyLeftRightDis;
    void logic(float t);
    void fadeOut(float t);
    Player* m_player;
    bool onContactBegin(PhysicsContact& contact);
    
    Vector<Sprite *> allEnemyFallen;
    Vector<Sprite *> allEnemyRoof;
    Vector<Sprite *> allStar;
    Vector<Sprite *> allEnemyLeftCrow;
    Vector<Sprite *> allEnemyRightCrow;
    
    Sprite * LeftWarning;
    Sprite * RightWarning;
    float LeftWarningLifeTimer;
    float RightWarningLifeTimer;
    
    
    void newEnemy(float t);
    void newEnemy_speedUp(float t);
    void moveEnemyRoof(float t);
    void moveEnemyFallen(float t);
    void moveStar(float t);
    void moveEnemyRight(float t);
    void moveEnemyLeft(float t);
    
    void timeController(float t);
    
    void EnemyFlip();
    void update(float t);
    void killMe(Node * pSender);
    void jumpToMenu();
    float start_point;
    int HP = 2;
    
    int enemy_killed = 0;
    
    cocos2d::Vec2 testTouchBegin;
    float sweep_angle;
    bool valid_touch;
    bool abilityButtonTouched = false;
    
    
};


//class BackgroundLayer;
//class Player;
//class MonsterLayer;
//
//class NewGame : public cocos2d::Layer
//{
//public:
//	~NewGame();
//	// there's no 'id' in cpp, so we recommend returning the class instance pointer
//	static cocos2d::Scene* createScene();
//	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
//	virtual bool init();
//	virtual void onExit() override;
//	// a selector callback
//	void menuCloseCallback(cocos2d::Ref* pSender);
//	//void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event * event4);
//	// implement the "static create()" method manually
//	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
//	virtual void onTouchMoved(Touch *touch, Event *unused_event);
//	virtual void onTouchEnded(Touch *touch, Event *unused_event);
//	CREATE_FUNC(NewGame);
//	void GoBack(cocos2d::Ref* pSender);
//	//__________________________________________________
//private:
//    int borderWidth;
//	void logic(float dt);
//
//	//int flag = 0;
//	bool onContactBegin(PhysicsContact& contact);
//	BackgroundLayer* m_backgroundLayer;
//	Player* m_player;
//	MonsterLayer* m_monsterLayer;
//};

#endif // __NEWGAME_SCENE_H__

