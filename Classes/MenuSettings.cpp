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
	
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	menuItem = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(MenuSettings::goback, this));
	//closeItem->setScale(0.8f);
    
    //closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                            origin.y + closeItem->getContentSize().height/2));

	

	//auto menu_item_2 = MenuItemImage::create("Menu/Nihon1.png", "Menu/Nihon2.png", CC_CALLBACK_1(HelloWorld::Nihon, this));


	//if (musicIsOn == true){		
	//	auto menu_2 = Menu::create(pauseBG, NULL);
	//	menu_2->alignItemsVertically();
	//	menu_2->setScale(0.8);
	//	addChild(menu_2);
	//}
	//if (musicIsOn == false){
	//	auto menu_2 = Menu::create(recoverBG, NULL);
	//	menu_2->alignItemsVertically();
	//	menu_2->setScale(0.8);
	//	addChild(menu_2);
	//}
	


	
	_turnOn = MenuItemImage::create(
		"Menu/sound_on.png",
		"Menu/sound_on_1.png");
	_turnOff = MenuItemImage::create(
		"Menu/sound_off.png",
		"Menu/sound_off_1.png");
	MenuItemToggle *toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MenuSettings::pauseMusicCallback, this), _turnOn, _turnOff, NULL);
    toggleItem->setTag(110);
    
     creditItem = MenuItemFont::create("Credits", CC_CALLBACK_1(MenuSettings::credits, this));

	//toggleItem->setScale(0.8f);
	//toggleItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	//MenuItemImage *_musicOn, *_musicOff;
	//_turnOn = MenuItemImage::create(
	//	"Menu/music_on.png",
	//	"Menu/music_on_1.png");
	//_turnOff = MenuItemImage::create(
	//	"Menu/music_off.png",
	//	"Menu/music_off_1.png");
	//MenuItemToggle *musicItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MenuSettings::recoverMusicCallback, this), _musicOn, _musicOff, NULL);

	//musicItem->setScale(0.8f);
	//auto musicItem = MenuItemImage::create("Menu/music_on.png", "Menu/music_on_1.png", CC_CALLBACK_1(MenuSettings::recoverMusicCallback, this));

	auto menu_2 = Menu::create(toggleItem, menuItem, creditItem, NULL);
	menu_2->alignItemsVertically();
	addChild(menu_2);
	//auto pauseBG = MenuItemImage::create("Menu/MusicIsOff.png", "Menu/MusicIsOn.png", CC_CALLBACK_1(MenuSettings::pauseMusicCallback, this));
	//auto recoverBG = MenuItemImage::create("Menu/MusicIsOn.png", "Menu/MusicIsOff.png", CC_CALLBACK_1(MenuSettings::recoverMusicCallback, this));
 //   auto menu_2=Menu::create(pauseBG,recoverBG,NULL);
 //   menu_2->alignItemsVertically();
 //   addChild(menu_2);

    
    return true;
}

void MenuSettings:: goback(cocos2d::Ref *pSender)
{
	CCLOG("go back");
	Director::getInstance()->popScene();
}

void MenuSettings::pauseMusicCallback(cocos2d::Ref *pSender)
{
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
//        MenuItemToggle * toggleItem = (MenuItemToggle *)this->getChildByTag(110);
//        toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MenuSettings::pauseMusicCallback, this), _turnOn, _turnOff, NULL);
//        auto menu_2 = Menu::create(toggleItem, menuItem, creditItem, NULL);
//        menu_2->alignItemsVertically();
//        addChild(menu_2);
	}
}

void MenuSettings::recoverMusicCallback(cocos2d::Ref *pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	isPause = true;
}
void MenuSettings::credits(cocos2d::Ref *pSender){
    Director::getInstance()->replaceScene(Credits::createScene());
}



