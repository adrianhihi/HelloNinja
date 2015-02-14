#include "Player.h"
#include "ObjectTag.h"
#include "cocos2d.h"

//#include “CocoStudio.h”

//using namespace cocostudio;
Player::Player()
{
	//m_iHP = 100;
}
Player::~Player()
{
}

void Player::playerInit(float spriteScale)
{
	
}

bool Player::init()
{
	isInAir = false;
	isMovingLeft = false;
	isLeft = true;
	isDead = false;
	score = 0;
	flyingTime = 0;

	auto size = Director::getInstance()->getWinSize();
	auto playerSp = Sprite::create();

    playerWidth = 75;

	this->addChild(playerSp);
	playerSp->setTag(0);
	Vector<SpriteFrame *> allframe;
	for (int i = 0; i < 4; i++){
		SpriteFrame * sf = SpriteFrame::create("player.png", Rect(i * 75, 0, 75, 100));
		allframe.pushBack(sf);
	}
	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.01);
	playerSp->runAction(RepeatForever::create(Animate::create(ani)));
	return true;
}

void Player::moveToRight()
{
	isInAir = true;
	isMovingLeft = false;
	flyingTime = 0.f;
	this->scheduleUpdate();
	CCLOG("------------>");
}
void Player::moveToLeft()
{
	isInAir = true;
	isMovingLeft = true;
	flyingTime = 0.f;
	this->scheduleUpdate();
	CCLOG("<------------");
}


void Player::logic(float dt)
{
}


void Player::update(float time)
{
	flyingTime += time;



	float a = -0.2*bgSize.y / (0.25 * (bgSize.x - this->boundingBox().size.width) * (bgSize.x - this->boundingBox().size.width));

	if (isInAir&&!isMovingLeft)
	{


		this->setPositionX(this->getPositionX() + 10);
		float y = a * (this->getPositionX() - origin.x - 0.5 * this->boundingBox().size.width)*(this->getPositionX() - origin.x - bgSize.x + 0.5 * this->boundingBox().size.width);
		this->setPositionY(y + bgSize.y*0.2);

		if (this->getPositionX() >= origin.x + bgSize.x - this->boundingBox().size.width / 2)
		{
			isInAir = false;
			this->setPosition(origin.x + bgSize.x - this->boundingBox().size.width / 2, origin.y + bgSize.y*0.2);
			this->unscheduleUpdate();

		}

	}
	else if (isInAir&&isMovingLeft)
	{

		this->setPosition(this->getPositionX() - 10, origin.y + bgSize.y*0.2);
		float y = a * (this->getPositionX() - origin.x - 0.5 * this->boundingBox().size.width)*(this->getPositionX() - origin.x - bgSize.x + 0.5 * this->boundingBox().size.width);
		this->setPositionY(y + bgSize.y*0.2);

		if (this->getPositionX() <= origin.x + this->boundingBox().size.width / 2)
		{
			isInAir = false;
			this->setPosition(origin.x + this->boundingBox().size.width / 2, origin.y + bgSize.y*0.2);
			this->unscheduleUpdate();

		}

	}
	return;



}


