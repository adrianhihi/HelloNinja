//
//  MenuSettings.cpp
//  game
//
//  Created by Xu Wu on 3/1/15.
//
//

#include "MenuSettings.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Credits.h"

USING_NS_CC;
MenuSettings::~MenuSettings(){}



Scene* MenuSettings::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuSettings::create();
    scene->addChild(layer);
    
    return scene;
}

bool MenuSettings::init()
{
    CCLayer::init();
    
    //background
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    bg = Sprite::create("optionsBg.png");
    bg->setTag(1);
    bg->setPosition(Point(windowSize.width/2, windowSize.height/2));
    bg_scale = visibleSize.height / bg->getContentSize().height;
    bg->setScale(bg_scale);
    this->addChild(bg);
	
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    //Size windowSize = Director::getInstance()->getWinSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();
	menuItem = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(MenuSettings::goback, this));
    
    
	menuItem->setScale(1.8f);
	


	
	_turnOn = MenuItemImage::create(
		"Menu/sound_on.png",
		"Menu/sound_on_1.png");
	_turnOff = MenuItemImage::create(
		"Menu/sound_off.png",
		"Menu/sound_off_1.png");
	MenuItemToggle *toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MenuSettings::pauseMusicCallback, this), _turnOn, _turnOff, NULL);
    toggleItem->setTag(110);
    
     //creditItem = MenuItemFont::create("Credits", CC_CALLBACK_1(MenuSettings::credits, this));

	toggleItem->setScale(1.8f);
    
    creditItem = MenuItemImage::create("Menu/credits.png", "Menu/credits1.png", CC_CALLBACK_1(MenuSettings::credits, this));
    
    
    creditItem->setScale(1.8f);

	auto menu_2 = Menu::create(toggleItem, menuItem, creditItem, NULL);
	menu_2->alignItemsVertically();
	addChild(menu_2);

    
    return true;
}

void MenuSettings:: goback(cocos2d::Ref *pSender)
{
	CCLOG("go back");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	Director::getInstance()->popScene();
}

void MenuSettings::pauseMusicCallback(cocos2d::Ref *pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    if (isPause == true)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
//        MenuItemToggle * toggleItem = (MenuItemToggle *)this->getChildByTag(110);
//        toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MenuSettings::pauseMusicCallback, this), _turnOff, _turnOn, NULL);
//        auto menu_2 = Menu::create(toggleItem, menuItem, creditItem, NULL);
//        menu_2->alignItemsVertically();
//        addChild(menu_2);
		isPause = false;
	}
	else{
	
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		isPause = true;

	}
}

void MenuSettings::recoverMusicCallback(cocos2d::Ref *pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	isPause = true;
}
void MenuSettings::credits(cocos2d::Ref *pSender){
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->replaceScene(Credits::createScene());
}



