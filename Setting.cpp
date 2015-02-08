#include "NewGameScene.h"
#include "Setting.h"
#include "HelloWorldScene.h"
#include "BackgroundLayer.h"
//#include "BgLayer.h"
#include "Player.h"
#include "BackgroundLayer_japan.h"

Setting::~Setting(){}


Scene* Setting::createScene()
{
	//auto Setting = Scene::create();
	//// 'scene' is an autorelease object
	////auto NewGame_scene = Scene::create();
	//auto layer = Setting::create();
	//Size visibleSize = Director::getInstance()->getWinSize();

	//Setting->addChild(layer, 1);
	//Setting->addChild(node);
	//// add layer as a child to scene
	//

	////auto bgLayer = BgLayer::create();
	////Setting->addChild(bgLayer, 0);
	////// 'layer' is an autorelease object
	////layer->m_backgroundLayer = bgLayer;
	//
	//auto backgroundLayer = BackgroundLayer_japan::create();
	//Setting->addChild(backgroundLayer, 4);

	//// 'layer' is an autorelease object
	////auto layer = Setting::create();
	//// add layer as a child to scene
	//Setting->addChild(layer);
	//layer->m_backgroundLayer = backgroundLayer;

	//return Setting;
	auto Setting = Scene::createWithPhysics();
	// 'scene' is an autorelease object
	//auto NewGame_scene = Scene::create();
	Vect gravity(0, -0.5f);
	Setting->getPhysicsWorld()->setGravity(gravity);
	Setting->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	Size visibleSize = Director::getInstance()->getWinSize();


	auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto node = Node::create();
	node->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	node->setPhysicsBody(body);

	Setting->addChild(node);

	auto backgroundLayer = BackgroundLayer_japan::create();
	Setting->addChild(backgroundLayer, 4);

	// 'layer' is an autorelease object
	auto layer = Setting::create();
	// add layer as a child to scene
	Setting->addChild(layer);
	layer->m_backgroundLayer = backgroundLayer;

	//add the monster layer
	//auto monsterLayer = MonsterLayer::create();
	//NewGame_scene->addChild(monsterLayer, 5);

	//layer->m_monsterLayer = monsterLayer;

	return Setting;
}

bool Setting::init()
{
	if (!Layer::init()){
		return false;
	}
	//this->schedule(schedule_selector(TollgateScene::logic));
	Size visibleSize = Director::getInstance()->getWinSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//set up the border

	// position the label on the center of the screen
	auto label = Label::createWithTTF("Setting!", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);
	if (!Layer::init()){
		return false;
	}
	//this->schedule(schedule_selector(TollgateScene::logic));
	//set up the border

	// position the label on the center of the screen

	//menu
	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(Setting::GoBack, this));
	menu_item_1->setPosition(Vec2(origin.x + visibleSize.width - menu_item_1->getContentSize().width / 2 - 180,
		origin.y + menu_item_1->getContentSize().height / 2 - 280));
	auto *menu = Menu::create(menu_item_1, NULL);
	menu->setScale(0.5);
	//menu->setPosition(Vec2(origin.x + visibleSize.width / 2 + 380, origin.y + visibleSize.height - label->getContentSize().height - 300));
	//auto *menu = Menu::create(menu_item_1, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu, 6);

	////background
	auto bg_sprite_1 = Sprite::create("japan/japan1.png");
	bg_sprite_1->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_1 = MoveTo::create(100, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	auto action_1 = RepeatForever::create(Move_Down_1);
	bg_sprite_1->runAction(action_1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_1, 4);

	auto bg_sprite_2 = Sprite::create("japan/japan2.png");
	bg_sprite_2->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_2 = MoveTo::create(200, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	auto action_2 = RepeatForever::create(Move_Down_2);
	bg_sprite_2->runAction(action_2);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_2, 3);
	auto bg_sprite_3 = Sprite::create("japan/japan3.png");
	bg_sprite_3->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_3 = MoveTo::create(500, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	auto action_3 = RepeatForever::create(Move_Down_3);
	bg_sprite_3->runAction(action_3);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_3, 2);
	auto bg_sprite_4 = Sprite::create("japan/japan4.png");
	bg_sprite_4->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_4->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_4, 1);









	this->schedule(schedule_selector(Setting::logic));

	return true;
}


void Setting::onExit()
{
	Layer::onExit();

	_eventDispatcher->removeEventListenersForTarget(this);
}


void Setting::GoBack(cocos2d::Ref *pSender){
	CCLOG("go back");
	Director::getInstance()->popScene();
}

void Setting::menuCloseCallback(Ref* pSender)
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
void Setting::logic(float dt)
{
	m_backgroundLayer->logic(dt);
}



