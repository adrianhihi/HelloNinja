#include "BackgroundLayer_japan.h"
#include "NewGameScene_japan.h"
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
	auto parent = (NewGameScene_japan*)this->getParent();
	Size visibleSize = parent->bg_size;
	Vec2 origin = parent->bg_origin;

	auto border = Sprite::create("border/border_j.png");
	border->setScale(parent->bg_scale);
	
	borderWidth = border->getBoundingBox().size.width;

	border1 = createBorder_left(Point(origin.x + borderWidth / 2, origin.y + visibleSize.height / 2));
    this->addChild(border1);
    
	border3 = createBorder_left(Point(origin.x + borderWidth / 2, origin.y + visibleSize.height * 3 / 2 ));
    this->addChild(border3);
    
	border2 = createBorder_right(Point(origin.x + visibleSize.width - borderWidth / 2, visibleSize.height / 2));
    
    this->addChild(border2);
    
	border4 = createBorder_right(Point(origin.x + visibleSize.width - borderWidth / 2, visibleSize.height * 3 / 2));
    
    this->addChild(border4);


	return true;
}

Sprite* BackgroundLayer_japan::createBorder_left(Point pos)
{
	auto parent = (NewGameScene_japan*)getParent();
	auto border = Sprite::create("border/border_j.png");
	border->setScale(parent->bg_scale);

	border->setPosition(pos);

	return border;
}

Sprite* BackgroundLayer_japan::createBorder_right(Point pos)
{
	auto parent = (NewGameScene_japan*)getParent();
	auto border = Sprite::create("border/border_j_2.png");
	border->setScale(parent->bg_scale);

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
