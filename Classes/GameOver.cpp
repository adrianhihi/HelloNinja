

#include "GameOver.h"
#include "HelloWorldScene.h"

Scene * GameOver::createScene() {
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
};

bool GameOver::init() {
    Size visibleSize = Director::getInstance()->getWinSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    if (!Layer::init()) {
		return false;
	}
	//add back ground
	auto size = Director::getInstance()->getWinSize();
	auto spbk = Sprite::create("end.png");
    
    
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
	auto menuItemBack = MenuItemImage::create("Menu/menu.png", "Menu/menu_1.png", CC_CALLBACK_1(GameOver::menuCallBack, this));
	//menuItemBack->setColor(Color3B::BLACK);
	auto menu = Menu::create(menuItemBack, NULL);
    menu->setPosition(Vec2(origin.x + visibleSize.width - menu->getContentSize().width / 2,
                           origin.y + menu->getContentSize().height / 2));
	this->addChild(menu, 1);

	return true;
};

void GameOver::menuCallBack(cocos2d::Ref * pSender) {
	Director::getInstance()->replaceScene(TransitionCrossFade::create(2, HelloWorld::createScene()));
};

