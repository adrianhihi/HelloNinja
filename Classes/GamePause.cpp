//
//  GamePause.cpp
//  xuwutest
//
//  Created by Xu Wu on 3/6/15.
//
//

#include "GamePause.h"
#include "SimpleAudioEngine.h"
#include "NewGameScene_japan.h"
#include "HelloWorldScene.h"


GamePause::~GamePause(){}



Scene* GamePause::createScene()
{
    auto scene = Scene::create();
    auto layer = GamePause::create();
    scene->addChild(layer);
    
    return scene;
}

bool GamePause::init()
{
    CCLayer::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto backItem = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(GamePause::goback, this));
    backItem->setScale(0.8f);
    
    auto continueItem=MenuItemImage::create("Menu/continue.png", "Menu/contiune_1.png", CC_CALLBACK_1(GamePause::resumegame, this));
    continueItem->setScale(0.8f);
    
    
    MenuItemImage *_turnOn, *_turnOff;
    _turnOn = MenuItemImage::create(
                                    "Menu/sound_on.png",
                                    "Menu/sound_on_1.png");
    _turnOff = MenuItemImage::create(
                                     "Menu/sound_off.png",
                                     "Menu/sound_off_1.png");
    MenuItemToggle *toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GamePause::pauseMusicCallback, this), _turnOn, _turnOff, NULL);
    
    toggleItem->setScale(0.8f);
    
    
    
    auto menu_2 = Menu::create(toggleItem, continueItem, backItem, NULL);
    menu_2->alignItemsVertically();
    addChild(menu_2);
    
    
    return true;
}

void GamePause:: goback(CCObject*)
{
    CCLOG("go back");
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void GamePause::resumegame(CCObject*)
{
    Director::getInstance()->popScene();
}

void GamePause::pauseMusicCallback(CCObject*)
{
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

void GamePause::recoverMusicCallback(CCObject*)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    isPause = true;
}
