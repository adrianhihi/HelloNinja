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

	auto border = Sprite::create("border/border_j.png");
	
	borderWidth = border->getContentSize().width;

    border1 = createBorder_left(Point(border->getContentSize().width/2, visibleSize.height/2));
    this->addChild(border1);
    
    border3 = createBorder_left(Point(border->getContentSize().width/2, visibleSize.height/2 + border->getContentSize().height));
    this->addChild(border3);
    
    border2 = createBorder_right(Point(visibleSize.width - border->getContentSize().width/2, visibleSize.height/2));
    
    this->addChild(border2);
    
    border4 = createBorder_right(Point(visibleSize.width - border->getContentSize().width/2, visibleSize.height/2 + border->getContentSize().height));
    
    this->addChild(border4);


	return true;
}

Sprite* BackgroundLayer_japan::createBorder_left(Point pos)
{
	auto border = Sprite::create("border/border_j.png");
	Size borderSize = border->getContentSize();
	Size visibleSize = Director::getInstance()->getWinSize();


	border->setPosition(pos);

	return border;
}

Sprite* BackgroundLayer_japan::createBorder_right(Point pos)
{
	auto border = Sprite::create("border/border_j_2.png");
	Size borderSize = border->getContentSize();

	border->setPosition(pos);

	return border;
}


void BackgroundLayer_japan::logic(float dt) {
    int posY1 = border1->getPositionY();
    int posY2 = border3->getPositionY();
    
    iSpeed = -10;
    
    
    posY1 += iSpeed;
    posY2 += iSpeed;
    
    auto myborder = Sprite::create("border/border_j.png");
    
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
