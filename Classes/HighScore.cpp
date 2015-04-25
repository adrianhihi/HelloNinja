//
//  HighScore.cpp
//  ninjaMidterm
//
//  Created by ZhaoLei on 4/22/15.
//
//
#include "HelloWorldScene.h"
#include "HighScore.h"
#include "NewGameScene.h"
#include "NewGameScene_halloween.h"
#include "NewGameScene_japan.h"
#include "SimpleAudioEngine.h"
#include <iostream>

Scene * HighScore::createScene(){
    auto scene = Scene::create();
    auto layer = HighScore::create();
    scene->addChild(layer);
    
    return scene;
}

bool HighScore::init(){
    if (!Layer::init()) {
        return false;
    }
    
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = Label::createWithBMFont("fonts/futura-48.fnt", "High Score");
    label->setPosition(Point(windowSize.width/2, windowSize.height - windowSize.height* 0.1));
    label->setScale(1.5);
    this->addChild(label);
    
    auto menuItem = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(HighScore::goback, this));
    menuItem->setScale(1.2);
    auto menu = Menu::create(menuItem, NULL);
    menu -> setPosition(Point(windowSize.width - windowSize.width*0.1, windowSize.height * 0.1));
    this->addChild(menu);
    
    this->setHighScore(0);
    
    return true;
}

void HighScore:: goback(cocos2d::Ref *pSender)
{
    CCLOG("go back");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->popScene();
}

void HighScore::setHighScore(int currentScore) {
    Size size = Director::getInstance()->getWinSize();
    score[0] = UserDefault::getInstance()->getIntegerForKey("score0", 0);
    score[1] = UserDefault::getInstance()->getIntegerForKey("score1", 0);
    score[2] = UserDefault::getInstance()->getIntegerForKey("score2", 0);
    score[3] = UserDefault::getInstance()->getIntegerForKey("score3", 0);
    score[4] = UserDefault::getInstance()->getIntegerForKey("score4", 0);
    
    if (currentScore > score[0]) {
        UserDefault::getInstance()->setIntegerForKey("score0", currentScore);
        UserDefault::getInstance()->setIntegerForKey("score1", score[0]);
        UserDefault::getInstance()->setIntegerForKey("score2", score[1]);
        UserDefault::getInstance()->setIntegerForKey("score3", score[2]);
        UserDefault::getInstance()->setIntegerForKey("score4", score[3]);
        UserDefault::getInstance()->flush();
    }
    else if (currentScore > score[1]){
        UserDefault::getInstance()->setIntegerForKey("score1", currentScore);
        UserDefault::getInstance()->setIntegerForKey("score2", score[1]);
        UserDefault::getInstance()->setIntegerForKey("score3", score[2]);
        UserDefault::getInstance()->setIntegerForKey("score4", score[3]);
        UserDefault::getInstance()->flush();
    }
    else if (currentScore > score[2]){
        UserDefault::getInstance()->setIntegerForKey("score2", currentScore);
        UserDefault::getInstance()->setIntegerForKey("score3", score[2]);
        UserDefault::getInstance()->setIntegerForKey("score4", score[3]);
        UserDefault::getInstance()->flush();
    }
    else if (currentScore > score[3]){
        UserDefault::getInstance()->setIntegerForKey("score3", currentScore);
        UserDefault::getInstance()->setIntegerForKey("score4", score[3]);
        UserDefault::getInstance()->flush();
    }
    else if (currentScore > score[4]){
        UserDefault::getInstance()->setIntegerForKey("score4", currentScore);
        UserDefault::getInstance()->flush();
    }
    
    auto score0 = Label::createWithBMFont("fonts/futura-48.fnt", StringUtils::format("1. %d", score[0]));
    auto score1 = Label::createWithBMFont("fonts/futura-48.fnt", StringUtils::format("2. %d", score[1]));
    auto score2 = Label::createWithBMFont("fonts/futura-48.fnt", StringUtils::format("3. %d", score[2]));
    auto score3 = Label::createWithBMFont("fonts/futura-48.fnt", StringUtils::format("4. %d", score[3]));
    auto score4 = Label::createWithBMFont("fonts/futura-48.fnt", StringUtils::format("5. %d", score[4]));
    score0->setAnchorPoint(Point::ZERO);
    score1->setAnchorPoint(Point::ZERO);
    score2->setAnchorPoint(Point::ZERO);
    score3->setAnchorPoint(Point::ZERO);
    score4->setAnchorPoint(Point::ZERO);
    score0 ->setPosition(Point(size.width * 0.1, size.height - size.height * 0.25));
    score1 ->setPosition(Point(size.width * 0.1, size.height - size.height * 0.4));
    score2 ->setPosition(Point(size.width * 0.1, size.height - size.height * 0.55));
    score3 ->setPosition(Point(size.width * 0.1, size.height - size.height * 0.7));
    score4 ->setPosition(Point(size.width * 0.1, size.height - size.height * 0.85));
    
    this->addChild(score0);
    this->addChild(score1);
    this->addChild(score2);
    this->addChild(score3);
    this->addChild(score4);
}

//Vector<int> HighScore::getHighScore() {
//    int score0 = UserDefault::getInstance()->getIntegerForKey("score0", 0);
//    score.pushBack(score0);
//    int score1 = UserDefault::getInstance()->getIntegerForKey("score1", 0);
//    score.pushBack(score1);
//    int score2 = UserDefault::getInstance()->getIntegerForKey("score2", 0);
//    score.pushBack(score2);
//    int score3 = UserDefault::getInstance()->getIntegerForKey("score3", 0);
//    score.pushBack(score3);
//    int score4 = UserDefault::getInstance()->getIntegerForKey("score4", 0);
//    score.pushBack(score4);
//    
//    return score;
//}