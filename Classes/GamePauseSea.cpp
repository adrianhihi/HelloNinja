//
//  GamePauseSea.cpp
//  ninjaMidterm
//
//  Created by ZhaoLei on 4/19/15.
//
//

#include "GamePauseSea.h"
#include "SimpleAudioEngine.h"
#include "NewGameScene_japan.h"
#include "HelloWorldScene.h"


GamePauseSea::~GamePauseSea(){}



Scene* GamePauseSea::createScene()
{
    auto scene = Scene::create();
    auto layer = GamePauseSea::create();
    scene->addChild(layer);
    
    return scene;
}

bool GamePauseSea::init()
{
    CCLayer::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //background
    bg = Sprite::create("optionsBg.png");
    bg->setTag(1);
    bg->setPosition(Point(windowSize.width/2, windowSize.height/2));
    bg_scale = visibleSize.height / bg->getContentSize().height;
    bg->setScale(bg_scale);
    this->addChild(bg);
    
    auto backItem = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(GamePauseSea::goback, this));
    backItem->setScale(1.8f);
    
    auto continueItem=MenuItemImage::create("Menu/continue.png", "Menu/continue_1.png", CC_CALLBACK_1(GamePauseSea::resumegame, this));
    continueItem->setScale(1.8f);
    
    
    MenuItemImage *_turnOn, *_turnOff;
    _turnOn = MenuItemImage::create(
                                    "Menu/sound_on.png",
                                    "Menu/sound_on_1.png");
    _turnOff = MenuItemImage::create(
                                     "Menu/sound_off.png",
                                     "Menu/sound_off_1.png");
    MenuItemToggle *toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GamePauseSea::pauseMusicCallback, this), _turnOn, _turnOff, NULL);
    
    toggleItem->setScale(1.8f);
    
    auto restart = MenuItemImage::create("Menu/restart.png", "Menu/restart_1.png", CC_CALLBACK_1(GamePauseSea::restart, this));
    restart->setScale(1.8f);
    
    
    
    auto menu_2 = Menu::create(toggleItem, continueItem, backItem, restart, NULL);
    menu_2->alignItemsVertically();
    addChild(menu_2);
    
    
    return true;
}

void GamePauseSea:: goback(CCObject*)
{
    CCLOG("go back");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void GamePauseSea::resumegame(CCObject*)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->popScene();
}

void GamePauseSea::pauseMusicCallback(CCObject*)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    if (isPause == true)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        isPause = false;
    }
    else{
        
        CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        isPause = true;
    }
}

void GamePauseSea::recoverMusicCallback(CCObject*)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    isPause = true;
}
void GamePauseSea::restart(CCObject*){
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->replaceScene(NewGameScene::createScene());
    //Director::getInstance()->popScene();
}
