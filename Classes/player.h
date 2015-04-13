#ifndef Player_H
#define Player_H
#include "cocos2d.h"
#include <sstream>

using namespace std;
using namespace cocos2d;
USING_NS_CC;

enum direction{
    DIR_LEFT,
    DIR_RIGHT
};
class Player : public Node
{
public:
    static Player* createPlayer(const char* fileName, float spriteScale, Vec2 _bgsize, Vec3 _origin);
    
    Player();
    ~Player();
    CCSprite* getSprite();
    void bindSprite(CCSprite* sprite);
    CREATE_FUNC(Player);
    virtual bool init();
    
    //	int score;
    bool isInAir;
    bool isMovingLeft;
    bool isLeft;
    bool shelled;
    bool speedUp;
    //	bool isDead;
	void logic();
    void logicRunning(float t);
    void logicflying(float t);
    //	void beAtked(int iValue);
    float playerWidth;
    direction m_dir;
    
    Sprite * spPlayer;
    Vector<SpriteFrame *> allframe;
    Vector<SpriteFrame *> allframeAir;
    Vector<SpriteFrame *> allframeAttack;
    Animate * ani;
    
private:
    
    
    
    
    
    
    void playerInit(float spriteScale);
    
    //	float flyingTime;
    
    
};
#endif