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
	Vect gravity(0, -0.5);
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


    auto border = BackgroundLayer::create();
    borderWidth = border->borderWidth;

	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(NewGame::GoBack, this));
    menu_item_1->setScale(1.2);
	menu_item_1->setPosition(Vec2(visibleSize.width - menu_item_1->getContentSize().width -borderWidth/2,
                                  menu_item_1->getContentSize().height / 2));


	auto *menu = Menu::create(menu_item_1, NULL);

	menu -> setPosition(Point(0, 0));

	this->addChild(menu, 6);

	auto bg_sprite_1 = Sprite::create("seaworld/s1.png");
	bg_sprite_1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_1 = MoveTo::create(100, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
	bg_sprite_1->runAction(Move_Down_1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_1,3);

	auto bg_sprite_2 = Sprite::create("seaworld/s2.png");

	bg_sprite_2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    bg_sprite_2->runAction(MoveTo::create(300, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2)));

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_2,2);
	auto bg_sprite_3 = Sprite::create("seaworld/s3.png");

	bg_sprite_3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    bg_sprite_3->runAction(MoveTo::create(500, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2)));

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_3,1);
	auto bg_sprite_4 = Sprite::create("seaworld/s4.png");
	bg_sprite_4->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_4, 0);

	this->schedule(schedule_selector(NewGame::logic));

	//player
    auto m_player = Player::create();
    m_player->setPosition(Point(borderWidth + m_player->playerWidth/2, visibleSize.height * 0.16f));
	this->addChild(m_player, 5, 0);

	//score
	//auto size = bg_sprite_4->getContentSize();
	auto labelScore = Label::createWithTTF("score:0", "fonts/Marker Felt.ttf", 35);
	labelScore->setPosition(Point(visibleSize.width / 2, visibleSize.height - 100));
	labelScore->setColor(Color3B::RED);
	labelScore->setTag(120);



	EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
	event->setSwallowTouches(true);
	event->onTouchBegan = CC_CALLBACK_2(NewGame::onTouchBegan, this);
	event->onTouchMoved = CC_CALLBACK_2(NewGame::onTouchMoved, this);
	event->onTouchEnded = CC_CALLBACK_2(NewGame::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);

	this->scheduleUpdate();

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
}

void NewGame::GoBack(cocos2d::Ref *pSender){
	CCLOG("go back");
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}




bool NewGame::onTouchBegan(Touch *touch, Event *unsured_event){

    auto my_player = dynamic_cast<Player*>(this->getChildByTag(0));
    
    Size size = Director::getInstance()->getWinSize();
    
    // add the label as a child to this layer
    
    
    
    int player_x = my_player->getPosition().x;
    
    
    int x_right = size.width - borderWidth - my_player->playerWidth/2;
    int x_left = borderWidth + my_player->playerWidth/2;
    
    if (player_x == x_right){
        
        my_player->isLeft = true;
        
        my_player-> runAction(MoveTo::create(0.5, Point(x_left, size.height * 0.16f)));
    }
    else if (player_x == x_left){
        my_player-> runAction(MoveTo::create(0.5, Point(x_right, size.height * 0.16f)));
        my_player->isLeft = false;
    }
    return true;
}

void NewGame::onTouchMoved(Touch * touch, Event *unsured_event){

	
}

void NewGame::onTouchEnded(Touch *touch, Event *unused_event){

}
