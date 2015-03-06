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

    auto menu_item_1 = MenuItemFont::create("Haimo Bai");
    auto menu_item_2 = MenuItemFont::create("Lei Zhao");
    auto menu_item_3 = MenuItemFont::create("Chi-Yen Teng");
    auto menu_item_4 = MenuItemFont::create("Xu Wu");
    auto menu_item_5 = MenuItemFont::create("He Yin");
    auto menu_item_6 = MenuItemFont::create("Xuyang Wang");
    menu_item_1->setScale(0.8);
    menu_item_2->setScale(0.8);
    menu_item_3->setScale(0.8);
    menu_item_4->setScale(0.8);
    menu_item_5->setScale(0.8);
    menu_item_6->setScale(0.8);
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Credits::closeCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    auto menu = Menu::create(menu_item_1,menu_item_2,menu_item_3,menu_item_4,menu_item_5,menu_item_6,closeItem, NULL);
    menu->alignItemsVertically();
    this->addChild(menu,3);

    

  
 
    
    
    return true;
}

void Credits:: closeCallback(CCObject*)
{
    CCLOG("go back");
    Director::getInstance()->popScene();
}

