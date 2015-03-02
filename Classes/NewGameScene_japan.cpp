#include "NewGameScene_japan.h"
#include "HelloWorldScene.h"
#include "BackgroundLayer.h"
#include "simpleAudioEngine.h"
#include "Player.h"

#include "BackgroundLayer_japan.h"
#include "GameOver.h"


NewGameScene_japan::~NewGameScene_japan(){}


Scene* NewGameScene_japan::createScene()
{

	auto NewGameScene_japan = Scene::createWithPhysics();
	// 'scene' is an autorelease object
	Vect gravity(0, -0.5f);
	NewGameScene_japan->getPhysicsWorld()->setGravity(gravity);
	NewGameScene_japan->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	Size visibleSize = Director::getInstance()->getVisibleSize();


	auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto node = Node::create();
	node->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	node->setPhysicsBody(body);

	NewGameScene_japan->addChild(node);

	

	// 'layer' is an autorelease object
	auto layer = NewGameScene_japan::create();
	// add layer as a child to scene
	NewGameScene_japan->addChild(layer);

	return NewGameScene_japan;
}

bool NewGameScene_japan::init()
{
	if (!Layer::init()){
		return false;
	}
	//this->schedule(schedule_selector(TollgateScene::logic));
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//set up the border

	// position the label on the center of the screen
	auto label = Label::createWithTTF("Japan Mission!", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		label->getContentSize().height/2));

	// add the label as a child to this layer
	this->addChild(label, 6);

	



	//menu
	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(NewGameScene_japan::GoBack, this));
    menu_item_1->setScale(1.2);
    menu_item_1->setPosition(Vec2(visibleSize.width - menu_item_1->getContentSize().width - borderWidth/2,
                                  menu_item_1->getContentSize().height / 2));


	
	////background
	auto bg_sprite_1 = Sprite::create("japan/japan1.png");

	if (visibleSize.width / bg_sprite_1->getContentSize().width >= visibleSize.height / bg_sprite_1->getContentSize().height)
		bg_sprite_1->setScale(bg_scale = visibleSize.height / bg_sprite_1->getContentSize().height);
	else bg_sprite_1->setScale(bg_scale = visibleSize.width / bg_sprite_1->getContentSize().width);

	bg_sprite_1->setPosition(Point(visibleSize.width / 2, visibleSize.height/2));

	bg_origin = Vec2(bg_sprite_1->getBoundingBox().getMinX(), bg_sprite_1->getBoundingBox().getMinY());
	bg_size = Vec2(bg_sprite_1->getBoundingBox().size);

//    bg_sprite_1->setScale(0.8);
	// position the sprite on the center of the screen
	

	auto Move_Down_1 = MoveTo::create(100, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
//	auto action_1 = RepeatForever::create(Move_Down_1);
	bg_sprite_1->runAction(Move_Down_1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_1, 4);

	auto bg_sprite_2 = Sprite::create("japan/japan2.png");
//    bg_sprite_2->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_2->setScale(bg_scale);
	bg_sprite_2->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
	auto Move_Down_2 = MoveTo::create(300, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
//	auto action_2 = RepeatForever::create(Move_Down_2);
	bg_sprite_2->runAction(Move_Down_2);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_2, 3);
	auto bg_sprite_3 = Sprite::create("japan/japan3.png");

	// position the sprite on the center of the screen
	bg_sprite_3->setScale(bg_scale);
	bg_sprite_3->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
	auto Move_Down_3 = MoveTo::create(500, Point(bg_size.width / 2 + bg_origin.x, -bg_size.height / 2));
//	auto action_3 = RepeatForever::create(Move_Down_3);
	bg_sprite_3->runAction(Move_Down_3);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_3, 2);
	auto bg_sprite_4 = Sprite::create("japan/japan4.png");

	

	// position the sprite on the center of the screen
	bg_sprite_4->setScale(bg_scale);
	bg_sprite_4->setPosition(Point(bg_size.width / 2 + bg_origin.x, bg_size.height / 2 + bg_origin.y));
	bg_sprite_4->setTag(1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_4, 1);


    // HP label
    
    auto labelHp = Label::createWithSystemFont(StringUtils::format("Hp: %d", HP), "fonts/Marker Felt.ttf", 40);
    labelHp->setColor(Color3B::RED);
    labelHp->setPosition(Vec2(origin.x + visibleSize.width / 2,
                              origin.y + visibleSize.height - label->getContentSize().height));
    labelHp->setTag(110);
    this->addChild(labelHp, 2);

	
	//height label
	score = 0;
	auto labelHeight = Label::createWithSystemFont(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 20);
	labelHeight->setColor(Color3B::WHITE);
	labelHeight->setPosition(Vec2(bg_origin.x + bg_size.width / 2,
		bg_origin.y + bg_size.height - labelHp->getContentSize().height - labelHeight->getContentSize().height));
	labelHeight->setTag(111);
	this->addChild(labelHeight, 2);



    
	//boarder

	{
		auto border1 = Sprite::create("border/border_j.png");
		auto border3 = Sprite::create("border/border_j.png");
		auto border2 = Sprite::create("border/border_j_2.png");
		auto border4 = Sprite::create("border/border_j_2.png");
		border1->setScale(bg_scale);
		border3->setScale(bg_scale);
		border2->setScale(bg_scale);
		border4->setScale(bg_scale);

		borderWidth = border1->getBoundingBox().size.width;

		border1->setPosition(Point(bg_origin.x + borderWidth / 2, bg_origin.y + bg_size.height / 2));
		this->addChild(border1, 10, Scene_Tag::border1);

		border3->setPosition(Point(bg_origin.x + borderWidth / 2, bg_origin.y + bg_size.height *3 / 2));
		this->addChild(border3, 10, Scene_Tag::border3);

		border2->setPosition(Point(bg_origin.x + bg_size.width - borderWidth / 2, bg_origin.y + bg_size.height / 2));
		this->addChild(border2, 10, Scene_Tag::border2);

		border4->setPosition(Point(bg_origin.x + bg_size.width - borderWidth / 2, bg_origin.y + bg_size.height *3 / 2));
		this->addChild(border4, 10, Scene_Tag::border4);

	}


	//player

	m_player = Player::create();
	m_player->setScale(bg_scale);
	m_player->playerWidth *= bg_scale;
	/*
	m_player->allframe.clear();
	for (int i = 1; i < 6; i++){
		auto sf = SpriteFrame::create(StringUtils::format("run/run_left%d.png", i), Rect(0, 0, m_player->playerWidth, m_player->playerWidth));
		m_player->allframe.pushBack(sf);
	}
	*/

	//m_player->spPlayer->setPosition(Point(bg_origin.x + borderWidth + m_player->playerWidth / 2, bg_origin.y + bg_size.height * 0.16f));
	//m_player->setTag(0);
	m_player->setPosition(Point(bg_origin.x + borderWidth + m_player->playerWidth / 2, bg_origin.y + bg_size.height * 0.16f));
    this->addChild(m_player, 11, 0);

	//skill button

	auto abilityButtonItem = MenuItemImage::create(
		"bang.png",
		"bang.png",
		CC_CALLBACK_1(NewGameScene_japan::playerAbility_Teleportation, this)
		);

	abilityButtonItem->setScale(bg_scale);

	abilityButtonItem->setPosition(bg_origin + abilityButtonItem->getBoundingBox().size/2);

	// create menu, it's an autorelease object
	auto *menu = Menu::create(menu_item_1, abilityButtonItem, NULL);

	menu->setPosition(Point(0, 0));
	//menu->setColor(Color3B::BLUE);
	this->addChild(menu, 20);

	//===================

	EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
	event->setSwallowTouches(true);
	event->onTouchBegan = CC_CALLBACK_2(NewGameScene_japan::onTouchBegan, this);
	event->onTouchMoved = CC_CALLBACK_2(NewGameScene_japan::onTouchMoved, this);
	event->onTouchEnded = CC_CALLBACK_2(NewGameScene_japan::onTouchEnded, this);
	event->onTouchCancelled = CC_CALLBACK_2(NewGameScene_japan::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);

    
    //
    enemyLeftRightDis = -1;
    
	//Enemy
    this->schedule(schedule_selector(NewGameScene_japan::logic)); // borderSpeed;
    this->schedule(schedule_selector(NewGameScene_japan::moveEnemyRoof)); // same as borderSpeed
    this->schedule(schedule_selector(NewGameScene_japan::moveEnemyFallen));
    this->schedule(schedule_selector(NewGameScene_japan::moveStar));
    this->schedule(schedule_selector(NewGameScene_japan::moveEnemyLeft));
    this->schedule(schedule_selector(NewGameScene_japan::moveEnemyRight));
    
    
    this->schedule(schedule_selector(NewGameScene_japan::newEnemy),1.5);

	//http://www.hawstein.com/posts/ctci-solutions-contents.html

	this->scheduleUpdate();



	return true;
}


void NewGameScene_japan::onExit()
{
	Layer::onExit();

	_eventDispatcher->removeEventListenersForTarget(this);
}


void NewGameScene_japan::GoBack(cocos2d::Ref *pSender){
	CCLOG("go back");
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void NewGameScene_japan::logic(float t) {
	int posY1 = this->getChildByTag(Scene_Tag::border1)->getPositionY();
	int posY2 = this->getChildByTag(Scene_Tag::border3)->getPositionY();


	posY1 += iSpeed;
	posY2 += iSpeed;

	auto myborder = Sprite::create("border/border_j.png");

	if (posY1 < -bg_size.height / 2) {
		posY1 = posY2 + bg_size.height;
	}

	if (posY2 < -bg_size.height / 2) {
		posY2 = posY1 + bg_size.height;
	}

	this->getChildByTag(Scene_Tag::border1)->setPositionY(posY1);
	this->getChildByTag(Scene_Tag::border3)->setPositionY(posY2);
	//-------------------------------------------------------------------------
	int posY3 = this->getChildByTag(Scene_Tag::border2)->getPositionY();
	int posY4 = this->getChildByTag(Scene_Tag::border4)->getPositionY();


	posY3 += iSpeed;
	posY4 += iSpeed;


	if (posY3 < -bg_size.height / 2) {
		posY3 = posY4 + bg_size.height;
	}

	if (posY4 < -bg_size.height / 2) {
		posY4 = posY3 + bg_size.height;
	}

	this->getChildByTag(Scene_Tag::border2)->setPositionY(posY3);
	this->getChildByTag(Scene_Tag::border4)->setPositionY(posY4);
}


bool NewGameScene_japan::onTouchBegan(Touch *touch, Event *unsured_event){
	
	auto my_player = (Player *) this->getChildByTag(0);

	if (touch->getLocation().x >= bg_origin.x + borderWidth&&touch->getLocation().x <= bg_origin.x + bg_size.width - borderWidth)
	{
		if (!my_player->isInAir && my_player->isLeft == false){

			my_player->isInAir = true;
			my_player->isMovingLeft = true;

			//my_player-> runAction(MoveTo::create(0.5, Point(x_left, size.height * 0.16f)));
			my_player->m_dir = DIR_LEFT;
			my_player->isLeft = true;
			my_player->logic();
		}
		else if (!my_player->isInAir && my_player->isLeft == true){
			//my_player-> runAction(MoveTo::create(0.5, Point(x_right, size.height * 0.16f)));
			my_player->isInAir = true;
			my_player->isMovingLeft = false;


			my_player->m_dir = DIR_RIGHT;
			my_player->isLeft = false;
			my_player->logic();
		}
	
	}

	
	return true;
}

void NewGameScene_japan::onTouchMoved(Touch * touch, Event *unsured_event){

}

void NewGameScene_japan::onTouchEnded(Touch *touch, Event *unused_event){
}

void NewGameScene_japan::onTouchCancelled(Touch *touch, Event *unused_event){

}


//move enemy roof
void NewGameScene_japan::moveEnemyRoof(float t) {

	
	for (int i = 0; i < allEnemyRoof.size(); i++) 
	{
		auto enemy = allEnemyRoof.at(i);
		enemy->setPositionY(enemy->getPositionY() + iSpeed);
		if (enemy->getPositionY() < 0) 
		{
			enemy->removeFromParent();
            allEnemyRoof.eraseObject(enemy);
			i--;
		}
	}
};

void NewGameScene_japan::moveEnemyFallen(float t) 
{

	for (int i = 0; i < allEnemyFallen.size(); i++)
	{
		auto enemy = allEnemyFallen.at(i);
		enemy->setPositionY(enemy->getPositionY() + iSpeed);
		if (enemy->getPositionY() < 0)
		{
			enemy->removeFromParent();
			allEnemyFallen.eraseObject(enemy);
			i--;
		}
	}
};

void NewGameScene_japan::moveStar(float t) 
{

	for (int i = 0; i < allStar.size(); i++)
	{
		auto enemy = allStar.at(i);
		enemy->setPositionY(enemy->getPositionY() + iSpeed);
		if (enemy->getPositionY() < 0)
		{
			enemy->removeFromParent();
			allStar.eraseObject(enemy);
			i--;
		}
	}

};

void NewGameScene_japan::moveEnemyLeft(float t) {
    auto size = Director::getInstance()->getWinSize();
//    for(auto enemyLeftCrow: allEnemyLeftCrow) {
    for (int i = 0; i < allEnemyLeftCrow.size(); i++) {
        auto enemyLeftCrow = allEnemyLeftCrow.at(i);
        if (enemyLeftCrow->getPositionY() > size.height - 200) {
			enemyLeftCrow->setPositionY(enemyLeftCrow->getPositionY() + iSpeed);
        }
        else {
            enemyLeftCrow->runAction(Sequence::create(MoveBy::create(1, Point(0,0)) , MoveBy::create(15, Point(640, -850)), NULL));
        }
        
        if (enemyLeftCrow->getPositionY() < 0 || enemyLeftCrow->getPositionX() > size.width) {
            enemyLeftCrow->removeFromParent();
            allEnemyLeftCrow.eraseObject(enemyLeftCrow);
            i--;
        }
    }
}

void NewGameScene_japan::moveEnemyRight(float t) {
    auto size = Director::getInstance()->getWinSize();
    for (int i = 0; i < allEnemyRightCrow.size(); i++) {
        auto enemyRightCrow = allEnemyRightCrow.at(i);
        if (enemyRightCrow->getPositionY() > size.height - 300) {
			enemyRightCrow->setPositionY(enemyRightCrow->getPositionY() + iSpeed);
        }
        else {
            enemyRightCrow->runAction(Sequence::create(MoveBy::create(1, Point(0,0)) , MoveBy::create(15, Point(-640, -850)), NULL));
        }
        
        if (enemyRightCrow->getPositionY() < 0 || enemyRightCrow->getPositionX() < 0) {
            enemyRightCrow->removeFromParent();
            allEnemyRightCrow.eraseObject(enemyRightCrow);
            i--;
        }
    }
    
}

void NewGameScene_japan::killMe(Node * pSender) {
	pSender->removeFromParentAndCleanup(true);
};

void NewGameScene_japan::jumpToMenu(){
	Director::getInstance()->replaceScene(HelloWorld::createScene());

};



void NewGameScene_japan::newEnemy(float t) {
    auto size = Director::getInstance()->getWinSize();
    auto border = Sprite::create("border/border_j.png");
    auto border_width = border->getContentSize().width;
    auto roof = Sprite::create("japan/roof_r.png");
    int roofWidth = roof->getContentSize().width;
    
    
    Sprite * enemy;
    Sprite * star;
    Sprite * crow;
    Vector<SpriteFrame *> crowFram;
    
    enemyNum ++;
    
    switch (enemyNum) {
            
        case 0: {
            enemy = Sprite::create("aaa.png");
            int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width -roofWidth - enemy->getContentSize().width/2);
            enemy->setPosition(Point(x, size.height+100));
            allEnemyFallen.pushBack(enemy);
            this->addChild(enemy, 7);
        }
            break;
        case 1: {
            enemy = Sprite::create("japan/roof_r.png");
            enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2, size.height + 100));
            this -> addChild(enemy, 7);
            allEnemyRoof.pushBack(enemy);
        }
            break;
        case 2: {
            enemy = Sprite::create("japan/roof_l.png");
            enemy->setPosition(Point(border_width + enemy->getContentSize().width/2, size.height + 100));
            this -> addChild(enemy, 7);
            allEnemyRoof.pushBack(enemy);
        }
            break;
        case 3: {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
            auto ani = Animation::createWithSpriteFrames(crowFram, 0.03);
            crow = Sprite::create();
            crow->runAction(RepeatForever::create(Animate::create(ani)));
            crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
            this->addChild(crow, 7);
            allEnemyLeftCrow.pushBack(crow);
        }
            break;
        case 4: {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
            crow = Sprite::create();
            crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.03))));
            crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 30, size.height + 100);
            this->addChild(crow, 7);
            allEnemyRightCrow.pushBack(crow);
            
            int RandNum = random(0, 2);
//            CCLOG("RandNum %d", RandNum);
            switch (RandNum) {
                case 0:
                    enemyNum = -1;
                    break;
                    
                case 1:
                    enemyNum = 4;
                    break;
                    
                case 2:
                    enemyNum = 9;
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        case 5: {
            star = Sprite::create("star.png");
            int x = random(border_width + star->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - star->getContentSize().width/2);
            star->setPosition(Point(x, size.height+100));
            this->addChild(star, 7);
            allStar.pushBack(star);
        }
            break;
        case 6: {
            enemy = Sprite::create("japan/roof_l.png");
            enemy->setPosition(Point(border_width + enemy->getContentSize().width/2, size.height + 100));
            this -> addChild(enemy, 7);
            allEnemyRoof.pushBack(enemy);
        }
            break;
        case 7: {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
            auto ani = Animation::createWithSpriteFrames(crowFram, 0.03);
            crow = Sprite::create();
            crow->runAction(RepeatForever::create(Animate::create(ani)));
            crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
            this->addChild(crow, 7);
            allEnemyLeftCrow.pushBack(crow);
        }
            break;
        case 8: {
            enemy = Sprite::create("japan/roof_r.png");
            enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2, size.height + 100));
            this -> addChild(enemy, 7);
            allEnemyRoof.pushBack(enemy);
        }
            break;
        case 9: {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
            crow = Sprite::create();
            crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.03))));
            crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 30, size.height + 100);
            this->addChild(crow, 7);
            allEnemyRightCrow.pushBack(crow);
            int RandNum = random(0, 2);
            CCLOG("RandNum %d", RandNum);
            switch (RandNum) {
                case 0:
                    enemyNum = -1;
                    break;
                    
                case 1:
                    enemyNum = 4;
                    break;
                    
                case 2:
                    enemyNum = 9;
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        case 10: {
            enemy = Sprite::create("ccc.png");
            int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width -roofWidth - enemy->getContentSize().width/2);
            enemy->setPosition(Point(x, size.height+100));
            allEnemyFallen.pushBack(enemy);
            this->addChild(enemy, 7);
        }
            break;
        case 11: {
            enemy = Sprite::create("japan/roof_l.png");
            enemy->setPosition(Point(border_width + enemy->getContentSize().width/2, size.height + 100));
            this -> addChild(enemy, 7);
            allEnemyRoof.pushBack(enemy);
        }
            break;
        case 12: {
            enemy = Sprite::create("japan/roof_r.png");
            enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2, size.height + 100));
            this -> addChild(enemy, 7);
            allEnemyRoof.pushBack(enemy);
        }
            break;
        case 13: {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
            crow = Sprite::create();
            crow->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(crowFram, 0.03))));
            crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2 - 30, size.height + 100);
            this->addChild(crow, 7);
            allEnemyRightCrow.pushBack(crow);
        }
            break;
        case 14: {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
            auto ani = Animation::createWithSpriteFrames(crowFram, 0.03);
            crow = Sprite::create();
            crow->runAction(RepeatForever::create(Animate::create(ani)));
            crow->setPosition(borderWidth + crow->getContentSize().width/2 + 30, size.height + 100);
            this->addChild(crow, 7);
            allEnemyLeftCrow.pushBack(crow);
            int RandNum = random(0, 2);
            CCLOG("RandNum %d", RandNum);
            switch (RandNum) {
                case 0:
                    enemyNum = -1;
                    break;
                    
                case 1:
                    enemyNum = 4;
                    break;
                    
                case 2:
                    enemyNum = 9;
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
            
        default:
            break;
    }
//	auto size = Director::getInstance()->getWinSize();
//	auto border = Sprite::create("border/border_j.png");
//	auto border_width = border->getContentSize().width*bg_scale;
//
//	Sprite * enemy;
//    Sprite * star;
//    Sprite * crow;
//    
//    int RandNum = random(0, 6);
//    
//    if (enemyLeftRightDis < 12 && enemyLeftRightDis > 9) {
//        while (enemyLeftRightDis == RandNum) {
//            RandNum = random(0, 13);
//        }
//        
//        if (enemyLeftRightDis < 12 && enemyLeftRightDis > 9){
//            enemyLeftRightDis = RandNum;
//        }
//    }
//    
//    auto roof = Sprite::create("japan/roof_r.png");
//    int roofWidth = roof->getContentSize().width * bg_scale;
//    
//    if (RandNum < 3) {
//        enemy = Sprite::create("japan/roof_r.png");
//		enemy->setScale(bg_scale);
//		enemy->setPosition(Point(bg_origin.x + bg_size.width - border_width - roofWidth/2, size.height + 100));
//    }
//    else if (RandNum < 6) {
//        enemy = Sprite::create("japan/roof_l.png");
//		enemy->setScale(bg_scale);
//		enemy->setPosition(Point(bg_origin.x + border_width + roofWidth / 2, size.height + 100));
//    }
//    else if (RandNum < 9) {
//        if (RandNum < 8) {
//           enemy = Sprite::create("aaa.png");
//        }
//        else{
//           enemy = Sprite::create("ccc.png");
//        }
//        int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - enemy->getContentSize().width/2);
//        enemy->setPosition(Point(x, size.height+100));
//    }
//    else if (RandNum == 9) {
//        star = Sprite::create("star.png");
//        int x = random(border_width + star->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - star->getContentSize().width/2);
//        star->setPosition(Point(x, size.height+100));
//    }
//    else if (RandNum < 12) {
//        Vector<SpriteFrame *> crowFram;
//        if (RandNum == 10) {
//            for (int i = 0; i < 4; i++) {
//                auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
//                crowFram.pushBack(sf);
//            }
//
//        }
//        else {
//            for (int i = 0; i < 4; i++) {
//                auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
//                crowFram.pushBack(sf);
//            }
//        }
//        auto ani = Animation::createWithSpriteFrames(crowFram, 0.03);
//        crow = Sprite::create();
//        crow->runAction(RepeatForever::create(Animate::create(ani)));
//    }
//		
//    
//    if (RandNum < 6 && allEnemyRightCrow.size() == 0 && allEnemyLeftCrow.size() == 0) {
//        this->addChild(enemy, 7);
//        allEnemyRoof.pushBack(enemy);
//    }
//    else if (RandNum < 9 && allEnemyRightCrow.size() == 0 && allEnemyLeftCrow.size() == 0) {
//        this->addChild(enemy, 7);
//        allEnemyFallen.pushBack(enemy);
//    }
//    else if (RandNum == 9) {
//        this->addChild(star, 7);
//        allStar.pushBack(star);
//    }
//    else if (RandNum < 12) {
//        if (RandNum == 10 && allEnemyLeftCrow.size() == 0) {
//            crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2, size.height + 100);
//            allEnemyRightCrow.pushBack(crow);
//            this->addChild(crow, 7);
//        }
//        else if (RandNum == 11 && allEnemyRightCrow.size() == 0){
//            crow->setPosition(borderWidth + crow->getContentSize().width/2, size.height + 100);
//            allEnemyLeftCrow.pushBack(crow);
//            this->addChild(crow, 7);
//        }
//        
//    }
	
}

void NewGameScene_japan::update(float t) {
	
	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto plane = (Player *) this->getChildByTag(0);

	Rect pp(plane->getPositionX(), plane->getPositionY(), plane->playerWidth, plane->playerWidth);
	auto p_x = this->getPositionX();
	auto p_y = this->getPositionY();


    //enemy roof
	for (int i = 0; i < allEnemyRoof.size(); i++) {
		auto enemy = allEnemyRoof.at(i);
		Rect er(enemy->getPositionX(), enemy->getPositionY(), 115, 103);
		auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 8.0f));
		auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 8.0f));

		auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));

		if (pp.intersectsRect(er) && HP > 1) {
				HP--;
				enemy->removeFromParent();
				allEnemyRoof.eraseObject(enemy);
                i--;
				this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));


				auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
				label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
				auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
				auto action_3 = RepeatForever::create(Move_Down_3);
				label->setColor(Color3B::RED);
				label->runAction(action_3);
				this->addChild(label, 8);
				
		}
		else if (pp.intersectsRect(er) && HP == 1){

			enemy->removeFromParent();
			allEnemyRoof.eraseObject(enemy);
            i--;
			this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));

            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
            
			this->pause();
			Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, GameOver::createScene()));


		}
	}
    
    //enemy fallen
    for (int i = 0; i < allEnemyFallen.size(); i++) {
        auto enemy = allEnemyFallen.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 40, 50);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 8.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 8.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        
        if (pp.intersectsRect(er) && HP > 1) {


            HP--;
            enemy->removeFromParent();
            allEnemyFallen.eraseObject(enemy);
            i--;
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            
            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
            
        }
        else if (pp.intersectsRect(er) && HP == 1){
            
            enemy->removeFromParent();
            allEnemyFallen.eraseObject(enemy);
            i--;
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            
            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);

            this->pause();
            Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, GameOver::createScene()));
        }
    }
    
    //enemy left crow
    for (int i = 0; i < allEnemyLeftCrow.size(); i++) {
        auto enemy = allEnemyLeftCrow.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 75, 63);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 8.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 8.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        
        if (pp.intersectsRect(er) && HP > 1) {
            
            
            HP--;
            enemy->removeFromParent();
            allEnemyLeftCrow.eraseObject(enemy);
            i--;
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            
            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
            
        }
        else if (pp.intersectsRect(er) && HP == 1){
            
            enemy->removeFromParent();
            allEnemyLeftCrow.eraseObject(enemy);
            i--;
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            
            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
            
            this->pause();
            Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, GameOver::createScene()));
        }
    }
    
    //enemy right crow
    for (int i = 0; i < allEnemyRightCrow.size(); i++) {
        auto enemy = allEnemyRightCrow.at(i);
        Rect er(enemy->getPositionX(), enemy->getPositionY(), 75, 63);
        auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 8.0f));
        auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 8.0f));
        
        auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));
        
        if (pp.intersectsRect(er) && HP > 1) {
            
            
            HP--;
            enemy->removeFromParent();
            allEnemyRightCrow.eraseObject(enemy);
            i--;
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            
            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
            
        }
        else if (pp.intersectsRect(er) && HP == 1){
            
            enemy->removeFromParent();
            allEnemyRightCrow.eraseObject(enemy);
            i--;
            this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
            
            auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
            
            this->pause();
            Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, GameOver::createScene()));
        }
    }
    
    auto labelHp = (Label *) this->getChildByTag(110);
    labelHp->setString(StringUtils::format("Hp: %d", HP));

	//score height

	auto labelHeight = (Label *) this->getChildByTag(111);
	if (score < 10000000)score++;
	labelHeight->setString(StringUtils::format("%d", score));
    
    //star
    for (int i = 0; i < allStar.size(); i++) {
        auto star = allStar.at(i);
        Rect er(star->getPositionX(), star->getPositionY(), 40, 50);
        
        if (pp.intersectsRect(er)) {
            HP++;
            star->removeFromParent();
            allStar.eraseObject(star);
            i--;
            auto label = Label::createWithTTF("HP +1", "fonts/Marker Felt.ttf", 24);
            label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
            auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
            auto action_3 = RepeatForever::create(Move_Down_3);
            label->setColor(Color3B::RED);
            label->runAction(action_3);
            this->addChild(label, 8);
        }
    }
    
    labelHp->setString(StringUtils::format("Hp: %d", HP));
    
	{
		
		auto my_player = (Player *) this->getChildByTag(0);
		
		float a = -0.1*bg_size.height / (0.25 * (bg_size.width - my_player->playerWidth - 2 * borderWidth) * (bg_size.width - my_player->playerWidth - 2 * borderWidth));

		if (my_player->isInAir&&!my_player->isMovingLeft)
		{


			my_player->setPositionX(my_player->getPositionX() + 10);
			float y = a * (my_player->getPositionX() - bg_origin.x - borderWidth - 0.5 * my_player->playerWidth)*(my_player->getPositionX() - bg_origin.x + borderWidth - bg_size.width + 0.5 * my_player->playerWidth);
			my_player->setPositionY(y + bg_size.height*0.16);

			if (my_player->getPositionX() >= bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2)
			{
				my_player->isInAir = false;
				my_player->setPosition(bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth / 2, bg_origin.y + bg_size.height*0.16);

			}
			/*
			else if (this->getPositionX() >= origin.x + bgSize.x / 2 && isLeft)
			{
			this->setScaleX((this->getScaleX()) * -1.f);
			isLeft = false;
			}
			*/

		}
		else if (my_player->isInAir&&my_player->isMovingLeft)
		{

			my_player->setPosition(my_player->getPositionX() - 10, bg_origin.y + bg_size.height*0.16);
			float y = a * (my_player->getPositionX() - bg_origin.x - borderWidth - 0.5 * my_player->playerWidth)*(my_player->getPositionX() - bg_origin.x + borderWidth - bg_size.width + 0.5 * my_player->playerWidth);
			my_player->setPositionY(y + bg_size.height*0.16);

			if (my_player->getPositionX() <= bg_origin.x + borderWidth + my_player->playerWidth / 2)
			{
				my_player->isInAir = false;
				my_player->setPosition(bg_origin.x + borderWidth + my_player->playerWidth / 2, bg_origin.y + bg_size.height*0.16);
				

			}
			/*
			else if (this->getPositionX() <= origin.x + bgSize.x / 2 && !isLeft)
			{
			this->setScaleX((this->getScaleX()) * -1.f);
			isLeft = true;
			}
			*/
		}


	}   
}

void NewGameScene_japan::playerAbility_Teleportation(cocos2d::Ref *pSender)
{
	Player *my_player = (Player *)(this->getChildByTag(Scene_Tag::player));

	if (!my_player->isInAir&&my_player->isLeft)
	{
		my_player->isLeft = false;
		my_player->m_dir = DIR_RIGHT;
		my_player->logic();
		my_player->setPositionX(bg_origin.x + bg_size.width - borderWidth - my_player->playerWidth/2);
	}
	else if (!my_player->isInAir&&!my_player->isLeft)
	{
		my_player->isLeft = true;
		my_player->m_dir = DIR_LEFT;
		my_player->logic();
		my_player->setPositionX(bg_origin.x + borderWidth + my_player->playerWidth / 2);
	}
}


