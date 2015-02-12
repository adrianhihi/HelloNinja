#ifndef Player_H
#define Player_H
#include "cocos2d.h"
#include <sstream>

using namespace std;
using namespace cocos2d;
USING_NS_CC;
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
	void moveToRight();
	void moveToLeft();
	Vec2 TouchBegin;

	int score;
	bool isInAir;
	bool isMovingLeft;
	bool isLeft;
	bool isDead;

	Vec2 origin;
	Vec2 bgSize;
	//void quickMove();
	//void moveDown();
	void logic(float dt);

	void beAtked(int iValue);
private:
	//CC_SYNTHESIZE(int, m_iHP, iHP);

	//void hurt(int iValue);

	//void cure(int iValue);

	//CCSprite* m_sprite;

	void playerInit(float spriteScale);

	void update(float time);
	float flyingTime;

	//virtual void onExit();

};
#endif
