#include "Player.h"
#include "ObjectTag.h"
#include "cocos2d.h"
#include "BackgroundLayer_japan.h"

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

	playerWidth = 150;

    m_dir = DIR_LEFT;
    
    for (int i = 1; i < 6; i++){
		auto sf = SpriteFrame::create(StringUtils::format("run/run_left%d.png", i), Rect(0, 0, playerWidth, playerWidth));
        allframe.pushBack(sf);
    }
    
    Animation * animation = Animation::createWithSpriteFrames(allframe);
    animation->setDelayPerUnit(0.08);
    ani = Animate::create(animation);
    spPlayer = Sprite::create();

    spPlayer->setTag(110);
    spPlayer->runAction(RepeatForever::create(ani));
    this->addChild(spPlayer);
   


	return true;
}





void Player::logic()
{
//    while (allframe.size() != 0) {
//        allframe.eraseObject(allframe.at(0));
//    }
    
    for (int i = 0; i < allframe.size(); i++) {
        allframe.eraseObject(allframe.at(i));
        i--;
    }
    
    spPlayer->stopAllActions();
    
    switch (m_dir) {
        case DIR_LEFT:
            for (int i = 1; i < 6; i++){
				auto sf = SpriteFrame::create(StringUtils::format("run/run_left%d.png", i), Rect(0, 0, 150, 150));
                allframe.pushBack(sf);
            }
            break;
        
        case DIR_RIGHT:
            for (int i = 1; i < 6; i++){
				auto sf = SpriteFrame::create(StringUtils::format("run/run_right%d.png", i), Rect(0, 0, 150, 150));
                allframe.pushBack(sf);
            }
            break;
            
        default:
            break;
    }
    
    Animation * animation = Animation::createWithSpriteFrames(allframe);
    animation->setDelayPerUnit(0.08);
    ani = Animate::create(animation);
    spPlayer->runAction(RepeatForever::create(ani));


}


