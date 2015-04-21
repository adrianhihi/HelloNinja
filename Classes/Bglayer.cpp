#include "BgLayer.h"
#include "ObjectTag.h"
//#include "ObjectTag.h"

BgLayer::BgLayer()
{
}

BgLayer::~BgLayer()
{
}

bool BgLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	m_bg1 = Sprite::create("bg.png");
	m_bg1->setScale(0.8);
	Size borderSize = m_bg1->getContentSize();
	m_bg1->setPosition(Point(borderSize.width * 0.5f, visibleSize.height / 2 + origin.y));
	this->addChild(m_bg1);

	m_bg2 = Sprite::create("bg.png");
	m_bg2->setScale(0.8);
	m_bg2->setPosition(Point(-borderSize.width * 0.5f, visibleSize.height / 2 + origin.y));
	this->addChild(m_bg2);

	return true;
}



void BgLayer::logic(float dt) {
	int posY1 = m_bg1->getPositionX();
	int posY2 = m_bg2->getPositionX();

	int iSpeed = -3;


	posY1 += iSpeed;
	posY2 += iSpeed;

	auto myborder = Sprite::create("bg.png");

	Size borderSize = myborder->getContentSize();

	int iVisibleWidth = (Director::getInstance()->getVisibleSize().width);


	if (posY1 < -iVisibleWidth * 0.5f) {
		posY2 = iVisibleWidth * 0.5f;
		posY1 = iVisibleWidth * 1.5f;
	}

	if (posY2 < -iVisibleWidth * 0.5f) {
		posY1 = iVisibleWidth * 0.5f;
		posY2 = iVisibleWidth * 1.5f;
	}

	m_bg1->setPositionX(posY1);
	m_bg2->setPositionX(posY2);
	//-------------------------------------------------------------------------

}
