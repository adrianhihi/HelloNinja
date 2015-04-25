//
//  Credits.cpp
//  xuwutest
//
//  Created by Xu Wu on 3/6/15.
//
//

#include "Credits.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
Credits::~Credits(){}



Scene* Credits::createScene()
{
    auto scene = Scene::create();
    auto layer = Credits::create();
    scene->addChild(layer);
    
    return scene;
}

bool Credits::init()
{
    CCLayer::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
//    
//    bg = Sprite::create("optionsBg.png");
//    bg->setTag(1);
//    bg->setPosition(Point(windowSize.width/2, windowSize.height/2));
//    bg_scale = visibleSize.height / bg->getContentSize().height;
//    bg->setScale(bg_scale);
//    this->addChild(bg);

    auto menu_item_1 = MenuItemFont::create("Haimo Bai\n");
    auto menu_item_2 = MenuItemFont::create("Lei Zhao\n");
    auto menu_item_3 = MenuItemFont::create("Chi-Yen Teng\n");
    auto menu_item_4 = MenuItemFont::create("Xu Wu\n");
    auto menu_item_5 = MenuItemFont::create("He Yin\n");
    auto menu_item_6 = MenuItemFont::create("Xuyang Wang\n\n\n");
    
    auto menu_item_7 = MenuItemFont::create("SPECIAL THANKS\n     Jianan Du");
    
    menu_item_1->setScale(1.8);
    menu_item_2->setScale(1.8);
    menu_item_3->setScale(1.8);
    menu_item_4->setScale(1.8);
    menu_item_5->setScale(1.8);
    menu_item_6->setScale(1.8);
    menu_item_7->setScale(1.8);
    
    auto closeItem = MenuItemImage::create(
                                           "Menu/restart.png",
                                           "Menu/restart_1.png",
                                           CC_CALLBACK_1(Credits::closeCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    closeItem->setScale(1.8);
    auto menu = Menu::create(menu_item_1,menu_item_2,menu_item_3,menu_item_4,menu_item_5,menu_item_6,menu_item_7,closeItem, NULL);
    menu->alignItemsVertically();
    this->addChild(menu,3);

    

  
 
    
    
    return true;
}

void Credits:: closeCallback(CCObject*)
{
    CCLOG("go back");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->popScene();
}

