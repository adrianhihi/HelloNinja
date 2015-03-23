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

	auto border_left = Sprite::create("border/Ocean_border.png");
	auto border_right = Sprite::create("border/Ocean_border2.png");
    borderWidth = border_left->getContentSize().width;

	border1 = createBorder_left(Point(border_left->getContentSize().width/2, visibleSize.height/2));
	this->addChild(border1);

    border3 = createBorder_left(Point(border_left->getContentSize().width/2, visibleSize.height/2 + border_left->getContentSize().height));
	this->addChild(border3);

    border2 = createBorder_right(Point(visibleSize.width - border_right->getContentSize().width/2, visibleSize.height/2));

	this->addChild(border2);

    border4 = createBorder_right(Point(visibleSize.width - border_right->getContentSize().width/2, visibleSize.height/2 + border_right->getContentSize().height));

	this->addChild(border4);
	

	return true;
}

Sprite* BackgroundLayer::createBorder_left(Point pos)
{
	auto border = Sprite::create("border/Ocean_border.png");
	Size borderSize = border->getContentSize();
	Size visibleSize = Director::getInstance()->getWinSize();

	border->setPosition(pos);

	return border;
}

Sprite* BackgroundLayer::createBorder_right(Point pos)
{
	auto border = Sprite::create("border/Ocean_border2.png");
	Size borderSize = border->getContentSize();

	border->setPosition(pos);

	return border;
}


void BackgroundLayer::logic(float dt) {
	int posY1 = border1->getPositionY();	
	int posY2 = border3->getPositionY();	

	int iSpeed = -20;


	posY1 += iSpeed;
	posY2 += iSpeed;

	auto myborder = Sprite::create("border/Ocean_border.png");

	Size borderSize = myborder->getContentSize();


	if (posY1 < -myborder->getContentSize().height/2) {
        posY1 = posY2 + myborder->getContentSize().height;
	}

	if (posY2 < -myborder->getContentSize().height/2) {
		posY2 = posY1 + myborder->getContentSize().height;
	}

	border1->setPositionY(posY1);
	border3->setPositionY(posY2);
	//-------------------------------------------------------------------------
	int posY3 = border2->getPositionY();
	int posY4 = border4->getPositionY();


	posY3 += iSpeed;
	posY4 += iSpeed;


    if (posY3 < -myborder->getContentSize().height/2) {
        posY3 = posY4 + myborder->getContentSize().height;
    }

    if (posY4 < -myborder->getContentSize().height/2) {
        posY4 = posY3 + myborder->getContentSize().height;
    }

	border2->setPositionY(posY3);
	border4->setPositionY(posY4);
}
