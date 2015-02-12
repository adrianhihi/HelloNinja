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
	//this->setScale(spriteScale);

	//this->setPosition(origin.x + this->getBoundingBox().size.width*0.5, origin.y + bgSize.y * 0.2);
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
	//playerSp->setPosition(size.width * 0.5f, size.height * 0.5f);
	auto body = PhysicsBody::createCircle(playerSp->getContentSize().width*0.03f);

	//body->getShape(0)->setFriction(0);
	//body->getShape(0)->setRestitution(1.0f);
	//body->setCategoryBitmask(1);    // 0001
	//body->setCollisionBitmask(1);   // 0001
	//body->setContactTestBitmask(1); // 0001
	//this->setPhysicsBody(body);


	this->addChild(playerSp);
	playerSp->setTag(0);
	Vector<SpriteFrame *> allframe;
	for (int i = 0; i < 4; i++){
		SpriteFrame * sf = SpriteFrame::create("player.png", Rect(i * 75, 0, 75, 100));
		allframe.pushBack(sf);
	}
	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.01);
	playerSp->runAction(RepeatForever::create(Animate::create(ani)));
	this->setTag(ObjectTag_Player);
	return true;
}

void Player::moveToRight()
{
	isInAir = true;
	isMovingLeft = false;
	flyingTime = 0.f;
	this->scheduleUpdate();
	//this->getPhysicsBody()->applyImpulse(Vect(15000, 0));
	CCLOG("------------>");
}
void Player::moveToLeft()
{
	isInAir = true;
	isMovingLeft = true;
	flyingTime = 0.f;
	this->scheduleUpdate();
	//this->getPhysicsBody()->applyImpulse(Vect(-15000, 0));
	CCLOG("<------------");
}
//void Player::quickMove()
//{
//
//	this->getPhysicsBody()->applyImpulse(Vect(0, 15000));
//	CCLOG("go");
//}
//
//void Player::moveDown()
//{
//
//	this->getPhysicsBody()->applyImpulse(Vect(0, -15000));
//	CCLOG("down");
//}

void Player::logic(float dt)
{
}

//void Player::beAtked(int iValue)
//{
//	if (iValue < 0)
//	{
//		cure(-iValue);
//	}
//	else
//	{
//		hurt(std::abs(iValue));
//	}
//}
//void Player::hurt(int iValue)
//{
//	setiHP(getiHP() - iValue);
//}
//void Player::cure(int iValue)
//{
//	setiHP(getiHP() + iValue);
//}
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
		/*
		else if (this->getPositionX() >= origin.x + bgSize.x / 2 && isLeft)
		{
		this->setScaleX((this->getScaleX()) * -1.f);
		isLeft = false;
		}
		*/

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
		/*
		else if (this->getPositionX() <= origin.x + bgSize.x / 2 && !isLeft)
		{
		this->setScaleX((this->getScaleX()) * -1.f);
		isLeft = true;
		}
		*/
	}
	return;



}


