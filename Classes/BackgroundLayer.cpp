#include "BackgroundLayer.h"
#include "ObjectTag.h"


BackgroundLayer::BackgroundLayer()
{
}

BackgroundLayer::~BackgroundLayer()
{
}

bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto border_left = Sprite::create("border/border_1.png");
	auto border_right = Sprite::create("border/border_2.png");
	//border->setScale(0.5);
	auto bg = Sprite::create("city/city4.png");
	Size bgSize = bg->getContentSize();
	Size borderSize_left = border_left->getContentSize();
	Size borderSize_right = border_right->getContentSize();
	border1 = createBorder_left(Point((visibleSize.width / 2 - bgSize.width / 4 + borderSize_left.width / 4 / 1.0556), visibleSize.height * 0.5f));
	this->addChild(border1);
	border3 = createBorder_left(Point((visibleSize.width / 2 - bgSize.width / 4 + borderSize_left.width / 4 / 1.0556), visibleSize.height * 1.5f));
	this->addChild(border3);
	border2 = createBorder_right(Point((visibleSize.width / 2 + bgSize.width / 4 - borderSize_right.width / 4 / 1.0556), visibleSize.height * 0.5f));

	this->addChild(border2);
	border4 = createBorder_right(Point((visibleSize.width / 2 + bgSize.width / 4 - borderSize_right.width / 4 / 1.0556), visibleSize.height * 1.5f));

	this->addChild(border4);
	

	return true;
}

Sprite* BackgroundLayer::createBorder_left(Point pos)
{
	auto border = Sprite::create("border/border_1.png");
	border->setScale(0.5/1.0556);
	Size borderSize = border->getContentSize();
	Size visibleSize = Director::getInstance()->getWinSize();
	
	int x = borderSize.height;
	int y = visibleSize.height;

	log("%d  %d\n", x, y);

	border->setPosition(pos);

	border->setTag(ObjectTag_Border);
	return border;
}

Sprite* BackgroundLayer::createBorder_right(Point pos)
{
	auto border = Sprite::create("border/border_2.png");
	border->setScale(0.5 / 1.0556);
	Size borderSize = border->getContentSize();

	border->setPosition(pos);

	border->setTag(ObjectTag_Border);
	return border;
}


void BackgroundLayer::logic(float dt) {
	int posY1 = border1->getPositionY();	
	int posY2 = border3->getPositionY();	

	int iSpeed = -3;	


	posY1 += iSpeed;
	posY2 += iSpeed;

	auto myborder = Sprite::create("border/border_1.png");

	Size borderSize = myborder->getContentSize();

	int iVisibleHeight = (Director::getInstance()->getVisibleSize().height);


	if (posY1 < -iVisibleHeight * 0.5f) {
		posY2 = iVisibleHeight * 0.5f;
		posY1 = iVisibleHeight * 1.5f;
	}

	if (posY2 < -iVisibleHeight * 0.5f) {
		posY1 = iVisibleHeight * 0.5f;
		posY2 = iVisibleHeight * 1.5f;
	}

	border1->setPositionY(posY1);
	border3->setPositionY(posY2);
	//-------------------------------------------------------------------------
	int posY3 = border2->getPositionY();
	int posY4 = border4->getPositionY();


	posY3 += iSpeed;
	posY4 += iSpeed;


	if (posY3 < -iVisibleHeight * 0.5f) {
		posY4 = iVisibleHeight * 0.5f;
		posY3 = iVisibleHeight * 1.5f;
	}

	if (posY4 < -iVisibleHeight * 0.5f) {
		posY3 = iVisibleHeight * 0.5f;
		posY4 = iVisibleHeight * 1.5f;
	}

	border2->setPositionY(posY3);
	border4->setPositionY(posY4);
}
