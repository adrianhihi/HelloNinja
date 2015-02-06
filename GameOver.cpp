

#include "GameOver.h"
#include "HelloWorldScene.h"

Scene * GameOver::createScene() {
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
};

bool GameOver::init() {
	if (!Layer::init()) {
		return false;
	}
	//add back ground
	auto size = Director::getInstance()->getWinSize();
	auto spbk = Sprite::create("end.png");
	//this picture is too big for me, but suitable for you I think, so you can delete it.
	spbk->setScale(0.5);
	//put the background picture on the middle
	spbk->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(spbk);
	//add Back item
	auto menuItemBack = MenuItemFont::create("Back", CC_CALLBACK_1(GameOver::menuCallBack, this));
	menuItemBack->setColor(Color3B::BLACK);
	auto menu = Menu::create(menuItemBack, NULL);
	menu->setPosition(size.width * 0.5f, 50);
	this->addChild(menu);

	return true;
};

void GameOver::menuCallBack(cocos2d::Ref * pSender) {
	Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, HelloWorld::createScene()));
};

