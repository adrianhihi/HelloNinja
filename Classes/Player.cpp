#include "Player.h"
#include "ObjectTag.h"
#include "cocos2d.h"
#include "BackgroundLayer_japan.h"

//#include “CocoStudio.h”

//using namespace cocostudio;
Player::Player()
{
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
    shelled = false;
    speedUp = false;
    
    
    auto size = Director::getInstance()->getWinSize();
    
    playerWidth = 150;
    
    m_dir = DIR_LEFT;
    
    for (int i = 1; i < 7; i++){
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
    this->schedule(schedule_selector(Player::logicRunning), 0.15);
    this->schedule(schedule_selector(Player::logicflying));
    
    
    return true;
}



void Player::logicflying(float t) {
    auto size = Director::getInstance()->getWinSize();
    
    if (speedUp) {
        if (this->isInAir) {
            spPlayer->stopAllActions();
            for (int i = 0; i < allframeAir.size(); i++) {
                allframeAir.eraseObject(allframeAir.at(i));
                i--;
            }
            
            switch (m_dir) {
                case DIR_LEFT:
                {
                    if (this->getPositionX() > size.width/2) {
                        auto sf1 = SpriteFrame::create("unbeatable/run_right7.png", Rect(0, 0, 150, 150));
                        allframeAir.pushBack(sf1);
                    }
                    else {
                        auto sf1 = SpriteFrame::create("unbeatable/run_right8.png", Rect(0, 0, 150, 150));
                        allframeAir.pushBack(sf1);
                    }
                }
                    break;
                    
                case DIR_RIGHT:
                {
                    if (this->getPositionX() < size.width/2) {
                        auto sf1 = SpriteFrame::create("unbeatable/run_left7.png", Rect(0, 0, 150, 150));
                        allframeAir.pushBack(sf1);
                    }
                    else {
                        auto sf1 = SpriteFrame::create("unbeatable/run_left8.png", Rect(0, 0, 150, 150));
                        allframeAir.pushBack(sf1);
                    }
                }
                    break;
                    
                default:
                    break;
            }
            auto animationAttack = Animation::createWithSpriteFrames(Player::allframeAir);
            animationAttack->setDelayPerUnit(0.02);
            auto aniAttack = Animate::create(animationAttack);
            spPlayer->runAction(aniAttack);
    }
    }
    
    else {
        if (shelled) {
            if (this->isInAir) {
                spPlayer->stopAllActions();
                for (int i = 0; i < allframeAir.size(); i++) {
                    allframeAir.eraseObject(allframeAir.at(i));
                    i--;
                }
                
                switch (m_dir) {
                    case DIR_LEFT:
                    {
                        if (this->getPositionX() > size.width/2) {
                            auto sf1 = SpriteFrame::create("SHELLED/right7.png", Rect(0, 0, 200, 200));
                            allframeAir.pushBack(sf1);
                        }
                        else {
                            auto sf1 = SpriteFrame::create("SHELLED/right8.png", Rect(0, 0, 200, 200));
                            allframeAir.pushBack(sf1);
                        }
                    }
                        break;
                        
                    case DIR_RIGHT:
                    {
                        if (this->getPositionX() < size.width/2) {
                            auto sf1 = SpriteFrame::create("SHELLED/7.png", Rect(0, 0, 200, 200));
                            allframeAir.pushBack(sf1);
                        }
                        else {
                            auto sf1 = SpriteFrame::create("SHELLED/8.png", Rect(0, 0, 200, 200));
                            allframeAir.pushBack(sf1);
                        }
                    }
                        break;
                        
                    default:
                        break;
                }
                auto animationAttack = Animation::createWithSpriteFrames(Player::allframeAir);
                animationAttack->setDelayPerUnit(0.02);
                auto aniAttack = Animate::create(animationAttack);
                spPlayer->runAction(aniAttack);
                
            }
        }
        
        else {
            if (this->isInAir) {
                spPlayer->stopAllActions();
                for (int i = 0; i < allframeAir.size(); i++) {
                    allframeAir.eraseObject(allframeAir.at(i));
                    i--;
                }
                
                switch (m_dir) {
                    case DIR_LEFT:
                    {
                        if (this->getPositionX() > size.width/2) {
                            auto sf1 = SpriteFrame::create("run/run_right7.png", Rect(0, 0, 150, 150));
                            allframeAir.pushBack(sf1);
                        }
                        else {
                            auto sf1 = SpriteFrame::create("run/run_right8.png", Rect(0, 0, 150, 150));
                            allframeAir.pushBack(sf1);
                        }
                    }
                        break;
                        
                    case DIR_RIGHT:
                    {
                        if (this->getPositionX() < size.width/2) {
                            auto sf1 = SpriteFrame::create("run/run_left7.png", Rect(0, 0, 150, 150));
                            allframeAir.pushBack(sf1);
                        }
                        else {
                            auto sf1 = SpriteFrame::create("run/run_left8.png", Rect(0, 0, 150, 150));
                            allframeAir.pushBack(sf1);
                        }
                    }
                        break;
                        
                    default:
                        break;
                }
                auto animationAttack = Animation::createWithSpriteFrames(Player::allframeAir);
                animationAttack->setDelayPerUnit(0.02);
                auto aniAttack = Animate::create(animationAttack);
                spPlayer->runAction(aniAttack);
            }
        }
    }
    
   
    
    

    
}

void Player::logicRunning(float t)
{
    
    if (this->speedUp) {
        if (!this->isInAir) {
            spPlayer->stopAllActions();
            for (int i = 0; i < allframe.size(); i++) {
                allframe.eraseObject(allframe.at(i));
                i--;
            }
            
            switch (m_dir) {
                case DIR_LEFT:
                {
                    for (int i = 1; i < 7; i++){
                        auto sf = SpriteFrame::create(StringUtils::format("unbeatable/run_left%d.png", i), Rect(0, 0, 150, 150));
                        allframe.pushBack(sf);
                    }
                }
                    break;
                    
                case DIR_RIGHT:
                {
                    for (int i = 1; i < 7; i++){
                        auto sf = SpriteFrame::create(StringUtils::format("unbeatable/run_right%d.png", i), Rect(0, 0, 150, 150));
                        allframe.pushBack(sf);
                    }
                }
                    break;
                    
                default:
                    break;
            }
            
        }
    }

    else {
        if (shelled) {
            if (!this->isInAir) {
                spPlayer->stopAllActions();
                for (int i = 0; i < allframe.size(); i++) {
                    allframe.eraseObject(allframe.at(i));
                    i--;
                }
                
                switch (m_dir) {
                    case DIR_LEFT:
                    {
                        for (int i = 1; i < 7; i++){
                            auto sf = SpriteFrame::create(StringUtils::format("SHELLED/%d.png", i), Rect(0, 0, 200, 200));
                            allframe.pushBack(sf);
                        }
                    }
                        break;
                        
                    case DIR_RIGHT:
                    {
                        for (int i = 1; i < 7; i++){
                            auto sf = SpriteFrame::create(StringUtils::format("SHELLED/right%d.png", i), Rect(0, 0, 200, 200));
                            allframe.pushBack(sf);
                        }
                    }
                        break;
                        
                    default:
                        break;
                }
                
                
            }
        }
        
        else {
            if (!this->isInAir) {
                spPlayer->stopAllActions();
                for (int i = 0; i < allframe.size(); i++) {
                    allframe.eraseObject(allframe.at(i));
                    i--;
                }
                
                switch (m_dir) {
                    case DIR_LEFT:
                    {
                        for (int i = 1; i < 7; i++){
                            auto sf = SpriteFrame::create(StringUtils::format("run/run_left%d.png", i), Rect(0, 0, 150, 150));
                            allframe.pushBack(sf);
                        }
                    }
                        break;
                        
                    case DIR_RIGHT:
                    {
                        for (int i = 1; i < 7; i++){
                            auto sf = SpriteFrame::create(StringUtils::format("run/run_right%d.png", i), Rect(0, 0, 150, 150));
                            allframe.pushBack(sf);
                        }
                    }
                        break;
                        
                    default:
                        break;
                }
                
            }
        }
    }
    
    
    auto animation = Animation::createWithSpriteFrames(allframe);
    animation->setDelayPerUnit(0.08);
    ani = Animate::create(animation);
    spPlayer->runAction(ani);

    
    
}


