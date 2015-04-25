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
    //virtual void onExit() override;
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
    Player* m_player;
    bool onContactBegin(PhysicsContact& contact);
    BackgroundLayer_japan* m_backgroundLayer;
    
    Vector<Sprite *> allEnemyFallen;
    Vector<Sprite *> allEnemyRoof;
    Vector<Sprite *> allStar;
    Vector<Sprite *> allEnemyLeftCrow;
    Vector<Sprite *> allEnemyRightCrow;
    
    void newEnemy(float t);
    void newEnemy_speedUp(float t);
    void moveEnemyRoof(float t);
    void moveEnemyFallen(float t);
    void moveStar(float t);
    void moveEnemyRight(float t);
    void moveEnemyLeft(float t);
    
    void timeController(float t);
    
    void fadeOut(float t);
    
    void EnemyFlip();
    void update(float t);
    void killMe(Node * pSender);
    void jumpToMenu();
    float start_point;
    int HP = 2;
    
    int enemy_killed = 0;
    MonsterLayer* m_monsterLayer;
    cocos2d::Vec2 testTouchBegin;
    float sweep_angle;
    bool valid_touch;
    bool abilityButtonTouched = false;
    
    
};

#endif // __NEWGAMESCENE_JHAPAN_SCENE_H__
