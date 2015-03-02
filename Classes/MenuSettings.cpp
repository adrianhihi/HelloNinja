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
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto closeItem = MenuItemFont::create("go back", this,menu_selector(MenuSettings::goback));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    auto menu_1 = Menu::create(closeItem, NULL);
    menu_1->setPosition(Vec2::ZERO);
    this->addChild(menu_1, 2);

    
    auto pauseBG=MenuItemFont::create("pause",this,menu_selector(MenuSettings::pauseMusicCallback));
    auto recoverBG=MenuItemFont::create("recover",this,menu_selector(MenuSettings::recoverMusicCallback));
    auto menu_2=Menu::create(pauseBG,recoverBG,NULL);
    menu_2->alignItemsVertically();
    addChild(menu_2);
    
    
    return true;
}

void MenuSettings:: goback(CCObject*)
{
    Director::getInstance()->popScene();
}

void MenuSettings::pauseMusicCallback(CCObject*)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void MenuSettings::recoverMusicCallback(CCObject*)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}




