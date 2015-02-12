#include "BackgroundLayer_japan.h"
#include "ObjectTag.h"
//#include "ObjectTag.h"

BackgroundLayer_japan::BackgroundLayer_japan()
{
}

BackgroundLayer_japan::~BackgroundLayer_japan()
{
}

bool BackgroundLayer_japan::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*
	m_bg1 = Sprite::create("border/border1.png");
	Size borderSize = m_bg1->getContentSize();
	m_bg1->setPosition(Point(borderSize.width * 0.5f, borderSize.height * 0.5f));
	this->addChild(m_bg1);

	m_bg2 = Sprite::create("border/border1.png");
	m_bg2->setPosition(Point(borderSize.width * 0.5f, -borderSize.height * 0.5f));
	this->addChild(m_bg2);

	m_bg3 = Sprite::create("border/border2.png");
	m_bg4->setPosition(Point(borderSize.width * 0.5f, borderSize.height * 0.5f));
	this->addChild(m_bg1);

	m_bg4 = Sprite::create("border/border2.png");
	m_bg4->setPosition(Point(borderSize.width * 0.5f, -borderSize.height * 0.5f));
	this->addChild(m_bg2);

	*/
	auto border = Sprite::create("border/border_j.png");
	
	//border->setScale(0.5);
	auto bg = Sprite::create("city/city4.png");
	Size bgSize = bg->getContentSize();
	Size borderSize = border->getContentSize();

	border1 = createBorder_left(Point((visibleSize.width / 2 + bgSize.width / 4 - borderSize.width / 4 / 1.0556), visibleSize.height * 0.5f));
	this->addChild(border1);
	border3 = createBorder_left(Point((visibleSize.width / 2 + bgSize.width / 4 - borderSize.width / 4 / 1.0556), visibleSize.height * 1.5f));
	this->addChild(border3);
	border2 = createBorder_right(Point((visibleSize.width / 2 - bgSize.width / 4 + borderSize.width / 4 / 1.0556), visibleSize.height * 0.5f));
	border2->setFlippedX(true);
	this->addChild(border2);
	border4 = createBorder_right(Point((visibleSize.width / 2 - bgSize.width / 4 + borderSize.width / 4 / 1.0556), visibleSize.height * 1.5f));
	border4->setFlippedX(true);
	this->addChild(border4);


	//     border1->setTag(ObjectTag_Border);
	//     border2->setTag(ObjectTag_Border);
	//     border3->setTag(ObjectTag_Border);
	return true;
}

Sprite* BackgroundLayer_japan::createBorder_left(Point pos)
{
	auto border = Sprite::create("border/border_j.png");
	border->setScale(0.5 / 1.0556);
	Size borderSize = border->getContentSize();
	Size visibleSize = Director::getInstance()->getWinSize();

	int x = borderSize.height;
	int y = visibleSize.height;

	//log("%d  %d\n", x, y);
	//auto body = PhysicsBody::createBox(borderSize);
	//body->setDynamic(false);
	//body->setCategoryBitmask(1);    // 0001
	//body->setCollisionBitmask(1);   // 0001
	//body->setContactTestBitmask(1); // 0001
	//border->setPhysicsBody(body);
	border->setPosition(pos);

	border->setTag(ObjectTag_Border);
	return border;
}

Sprite* BackgroundLayer_japan::createBorder_right(Point pos)
{
	auto border = Sprite::create("border/border_j.png");
	border->setScale(0.5 / 1.0556);
	Size borderSize = border->getContentSize();

	//auto body = PhysicsBody::createBox(borderSize);
	//body->setDynamic(false);
	//body->setCategoryBitmask(1);    // 0001
	//body->setCollisionBitmask(1);   // 0001
	//body->setContactTestBitmask(1); // 0001
	//border->setPhysicsBody(body);
	border->setPosition(pos);

	border->setTag(ObjectTag_Border);
	return border;
}


void BackgroundLayer_japan::logic(float dt) {
	int posY1 = border1->getPositionY();
	int posY2 = border3->getPositionY();

	int iSpeed = -3;


	posY1 += iSpeed;
	posY2 += iSpeed;

	auto myborder = Sprite::create("border/border_j.png");

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
