//
//  GameOverSeaSea.cpp
//  ninjaMidterm
//
//  Created by ZhaoLei on 4/19/15.
//
//

#include "GameOverSea.h"
#include "HelloWorldScene.h"
#include "NewGameScene.h"
#include "SimpleAudioEngine.h"

Scene * GameOverSea::createScene() {
    auto scene = Scene::create();
    auto layer = GameOverSea::create();
    scene->addChild(layer);
    return scene;
};

bool GameOverSea::init() {
    Size visibleSize = Director::getInstance()->getWinSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    if (!Layer::init()) {
        return false;
    }
    //add back ground
    auto size = Director::getInstance()->getWinSize();
    auto spbk = Sprite::create("seaworld/lose.png");
    
    
    if(visibleSize.width / spbk->getContentSize().width >= visibleSize.height / spbk->getContentSize().height){
        bg_scale = visibleSize.height / spbk->getContentSize().height;
    }else{
        bg_scale = visibleSize.width / spbk->getContentSize().width;
    }
    
    spbk->setScale(bg_scale);
    //this picture is too big for me, but suitable for you I think, so you can delete it.
    //put the background picture on the middle
    spbk->setPosition(Point(size.width / 2, size.height / 2));
    this->addChild(spbk);
    //add Back item
    auto menuItemBack = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(GameOverSea::menuCallBack, this));
    //menuItemBack->setColor(Color3B::BLACK);
    menuItemBack->setScale(1.8f);
    auto restart = MenuItemImage::create("Menu/restart.png", "Menu/restart_1.png", CC_CALLBACK_1(GameOverSea::restart, this));
    restart->setScale(1.8f);
    auto menu = Menu::create(menuItemBack, restart, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(origin.x + visibleSize.width - menu->getContentSize().width / 2,
                           origin.y + menu->getContentSize().height / 2));
    this->addChild(menu, 1);
    
    return true;
};

void GameOverSea::menuCallBack(cocos2d::Ref * pSender) {
    Director::getInstance()->replaceScene(TransitionCrossFade::create(2, HelloWorld::createScene()));
};

void GameOverSea::restart(cocos2d::Ref * pSender){
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    Director::getInstance()->replaceScene(NewGameScene::createScene());
}
