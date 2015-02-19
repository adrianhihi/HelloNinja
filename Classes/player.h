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

	int score;
	bool isInAir;
	bool isMovingLeft;
	bool isLeft;
	bool isDead;

	void logic();
	void beAtked(int iValue);
    int playerWidth;
    direction m_dir;
private:
    
    
    Vector<SpriteFrame *> allframe;
    Animate * ani;
    
    Sprite * spPlayer;
    
	void playerInit(float spriteScale);

	float flyingTime;


};
#endif
