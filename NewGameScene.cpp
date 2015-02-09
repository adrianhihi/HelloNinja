#include "NewGameScene.h"
#include "HelloWorldScene.h"
#include "BackgroundLayer.h"
#include "Setting.h"
#include "Player.h"

#include "ObjectTag.h"

#include "SimpleAudioEngine.h"

NewGame::~NewGame(){}


Scene* NewGame::createScene()
{
	auto NewGame_scene = Scene::createWithPhysics();
	// 'scene' is an autorelease object
	//auto NewGame_scene = Scene::create();
	Vect gravity(0, -0.5f);
	NewGame_scene->getPhysicsWorld()->setGravity(gravity);
	NewGame_scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	Size visibleSize = Director::getInstance()->getWinSize();


	auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto node = Node::create();
	node->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	node->setPhysicsBody(body);

	NewGame_scene->addChild(node);

	auto backgroundLayer = BackgroundLayer::create();
	NewGame_scene->addChild(backgroundLayer, 4);

	// 'layer' is an autorelease object
	auto layer = NewGame::create();
	// add layer as a child to scene
	NewGame_scene->addChild(layer);
	layer->m_backgroundLayer = backgroundLayer;

	//add the monster layer
	//auto monsterLayer = MonsterLayer::create();
	//NewGame_scene->addChild(monsterLayer, 5);

	//layer->m_monsterLayer = monsterLayer;
	
	return NewGame_scene;
}

bool NewGame::init()
{
	if (!Layer::init()){
		return false;
	}
	//this->schedule(schedule_selector(TollgateScene::logic));
	Size visibleSize = Director::getInstance()->getWinSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//set up the border

	


	// position the label on the center of the screen
	auto label = Label::createWithTTF("Hello Ninja!", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);



	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(NewGame::GoBack, this));
	menu_item_1->setPosition(Vec2(origin.x + visibleSize.width - menu_item_1->getContentSize().width / 2 - 200,
		origin.y + menu_item_1->getContentSize().height / 2 - 280));


	auto *menu = Menu::create(menu_item_1, NULL);
	menu->setScale(0.5);
	//menu->setPosition(Vec2(origin.x + visibleSize.width / 2 + 380, origin.y + visibleSize.height - label->getContentSize().height - 300));
	//auto *menu = Menu::create(menu_item_1, NULL);
	menu -> setPosition(Point(0, 0));

	this->addChild(menu, 6);

	auto bg_sprite_1 = Sprite::create("seaworld/s1.png");
	bg_sprite_1->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_1 = MoveTo::create(100, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	auto action_1 = RepeatForever::create(Move_Down_1);
	bg_sprite_1->runAction(action_1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_1, 3);

	auto bg_sprite_2 = Sprite::create("seaworld/s2.png");
	bg_sprite_2->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_2 = MoveTo::create(200, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	auto action_2 = RepeatForever::create(Move_Down_2);
	bg_sprite_2->runAction(action_2);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_2, 2);
	auto bg_sprite_3 = Sprite::create("seaworld/s3.png");
	bg_sprite_3->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_3 = MoveTo::create(500, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	auto action_3 = RepeatForever::create(Move_Down_3);
	bg_sprite_3->runAction(action_3);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_3, 1);
	auto bg_sprite_4 = Sprite::create("seaworld/s4.png");
	bg_sprite_4->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_4->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_4, 0);

	this->schedule(schedule_selector(NewGame::logic));

	//player
	auto bg_width = bg_sprite_4->getContentSize().width;
	m_player = Player::create();
	auto player_width = m_player->getContentSize().width;
	m_player->setPosition(Point((visibleSize.width - 0.5 * bg_width) * 0.5f + 50, visibleSize.height * 0.36f));
	m_player->setTag(110);
	this->addChild(m_player, 5);

	//score
	//auto size = bg_sprite_4->getContentSize();
	auto labelScore = Label::createWithTTF("score:0", "fonts/Marker Felt.ttf", 35);
	labelScore->setPosition(Point(visibleSize.width / 2, visibleSize.height - 100));
	labelScore->setColor(Color3B::RED);
	labelScore->setTag(120);

	//createOprUI();


	//auto listener_1 = EventListenerTouchAllAtOnce::create();

	//listener_1->onTouchesBegan = CC_CALLBACK_2(NewGame::onTouchesBegan, this);

	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_1, this);
	//
	//
	//
	//

	//_____________________________________________________________

	EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
	event->setSwallowTouches(true);
	event->onTouchBegan = CC_CALLBACK_2(NewGame::onTouchBegan, this);
	event->onTouchMoved = CC_CALLBACK_2(NewGame::onTouchMoved, this);
	event->onTouchEnded = CC_CALLBACK_2(NewGame::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);

	this->scheduleUpdate();
	//_____________________________________________________________


	///*contact listener*/
	//auto contactListener = EventListenerPhysicsContact::create();
	//contactListener->onContactBegin = CC_CALLBACK_1(NewGame::onContactBegin, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	//this->schedule(schedule_selector(NewGame::logic));

	return true;
}


void NewGame::onExit()
{
	Layer::onExit();

	_eventDispatcher->removeEventListenersForTarget(this);
}
void NewGame::logic(float dt)
{
	m_backgroundLayer->logic(dt);
	//m_monsterLayer->logic(dt);
}

void NewGame::GoBack(cocos2d::Ref *pSender){
	CCLOG("go back");
	Director::getInstance()->popScene();
}

void NewGame::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
//void NewGame::createOprUI()
//{
//	//Size visibleSize = Director::getInstance()->getWinSize();
//	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("OprUI_1.ExportJson");
//	
//
//	this->addChild(UI,5);
//
//	Button* rightBtn = (Button*)Helper::seekWidgetByName(UI, "rightBtn");
//	Button* quickMoveBtn = (Button*)Helper::seekWidgetByName(UI, "quickMoveBtn");
//	Button* leftBtn = (Button*)Helper::seekWidgetByName(UI, "leftBtn");
//	Button* moveDownBtn = (Button*)Helper::seekWidgetByName(UI, "moveDownBtn");
//	leftBtn->addTouchEventListener(this, toucheventselector(NewGame::moveToLeft));
//	rightBtn->addTouchEventListener(this, toucheventselector(NewGame::moveToRight));
//	quickMoveBtn->addTouchEventListener(this, toucheventselector(NewGame::quickMove));
//	moveDownBtn->addTouchEventListener(this, toucheventselector(NewGame::moveDown));
//}

//void NewGame::moveToLeft(Ref* sender, TouchEventType type)
//{
//	Size visibleSize = Director::getInstance()->getWinSize();
//	auto bg_sprite_4 = Sprite::create("seaworld/s4.png");
//	bg_sprite_4->setScale(0.5);
//	auto bg_width = bg_sprite_4->getContentSize().width;
//	auto sp_width = m_player->getContentSize().width;
//	auto Move_By = MoveTo::create(2, Point((visibleSize.width) * 0.5f, visibleSize.height * 0.36f));
//	switch (type)
//	{
//	case TOUCH_EVENT_ENDED:
//		m_player->runAction(Move_By);
//		//m_player->moveToLeft();
//		break;
//	}
//	//m_player->moveToLeft();
//	
//}
//
//void NewGame::moveToRight(Ref* sender, TouchEventType type)
//{
//	Size visibleSize = Director::getInstance()->getWinSize();
//	auto bg_sprite_4 = Sprite::create("seaworld/s4.png");
//	bg_sprite_4->setScale(0.5);
//	auto bg_width = bg_sprite_4->getContentSize().width;
//	auto sp_width = m_player->getContentSize().width;
//	auto Move_By = MoveTo::create(2, Point((visibleSize.width) * 0.5f, visibleSize.height * 0.36f));
//	switch (type)
//	{
//	case TOUCH_EVENT_ENDED:
//		m_player->runAction(Move_By);
//		//m_player->moveToRight();
//		break;
//	}
//	//m_player->moveToRight();
//	//CCLOG("------------>");
//}

//void NewGame::quickMove(Ref* sender, TouchEventType type)
//{
//	//auto Move_By = MoveBy::create(3, Vect(-50, 0));
//	switch (type)
//	{
//	case TOUCH_EVENT_ENDED:
//		//m_player->runAction(Move_By);
//		m_player->quickMove();
//		break;
//	}
//	//m_player->quickMove();
//	//CCLOG("go!");
//}
//void NewGame::moveDown(Ref* sender, TouchEventType type)
//{
//	//auto Move_By = MoveBy::create(3, Vect(-50, 0));
//	switch (type)
//	{
//	case TOUCH_EVENT_ENDED:
//		//m_player->runAction(Move_By);
//		m_player->moveDown();
//		break;
//	}
//	//m_player->quickMove();
//	//CCLOG("go!");
//}
//
//bool NewGame::onContactBegin(PhysicsContact& contact)
//{
//	auto nodeA = (Sprite*)contact.getShapeA()->getBody()->getNode();
//	auto nodeB = (Sprite*)contact.getShapeB()->getBody()->getNode();
//	if (nodeA == NULL || nodeB == NULL)
//	{
//		return true;
//	}
//
//	Node* playerNode = NULL;    
//	Node* other = NULL;        
//
//	if (nodeA->getTag() == ObjectTag_Player)
//	{
//		playerNode = nodeA;
//		other = nodeB;
//	}
//	else if (nodeB->getTag() == ObjectTag_Player)
//	{
//		playerNode = nodeB;
//		other = nodeA;
//	}
//	else
//	{
//	
//		return true;
//	}
//
//	Player* player = (Player*)playerNode;
//
//
//	if (other->getTag() == ObjectTag_Border)
//	{
//
//		player->beAtked(-1);
//
//		log("player cur HP:%d", player->getiHP());
//	}
//	else if (other->getTag() == ObjectTag_Monster)
//	{
//
//		Monster* monster = (Monster*)other;
//
//		if (monster->getiAtk() != 0)
//		{
//
//			player->beAtked(monster->getiAtk());
//
//			monster->removeFromParent();
//		}
//	}
//	return true;
//}


//
//void NewGame::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event4){
//	CCLOG("touches->");
//	createOprUI();
//
//}

bool NewGame::onTouchBegan(Touch *touch, Event *unsured_event){
	int px = touch->getLocation().x;
	int py = touch->getLocation().y;

	auto my_player = this->getChildByTag(110);

	Size visibleSize = Director::getInstance()->getWinSize();
	auto bg_sprite_4 = Sprite::create("seaworld/s4.png");
	bg_sprite_4->setScale(0.5);
	auto bg_width = bg_sprite_4->getContentSize().width;
	auto sp_width = m_player->getContentSize().width;

	int player_x = my_player->getPosition().x;
	int player_y = my_player->getPosition().y;

	int x_right = (visibleSize.width + 0.5 * bg_width) * 0.5f - 50;
	int x_left	= (visibleSize.width - 0.5 * bg_width) * 0.5f + 50;

	auto MoveToRight = MoveTo::create(0.5, Point(x_right, visibleSize.height * 0.36f));
	auto  MoveToLeft = MoveTo::create(0.5, Point(x_left , visibleSize.height * 0.36f));

	if (player_x == x_right){
		my_player->runAction(MoveToLeft);
	}
	else if (player_x == x_left){
		my_player->runAction(MoveToRight);
	}
	return true;
}

void NewGame::onTouchMoved(Touch * touch, Event *unsured_event){

	
}

void NewGame::onTouchEnded(Touch *touch, Event *unused_event){

}
