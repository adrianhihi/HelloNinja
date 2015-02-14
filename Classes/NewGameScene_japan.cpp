#include "NewGameScene_japan.h"
#include "HelloWorldScene.h"
#include "BackgroundLayer.h"
//#include "BgLayer.h"
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

	auto backgroundLayer = BackgroundLayer_japan::create();
	NewGameScene_japan->addChild(backgroundLayer, 4);


	// 'layer' is an autorelease object
	auto layer = NewGameScene_japan::create();
	// add layer as a child to scene
	NewGameScene_japan->addChild(layer);
	layer->m_backgroundLayer = backgroundLayer;
	backgroundLayer->setTag(9);


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
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 2);
    auto border = BackgroundLayer_japan::create();
    borderWidth = border->borderWidth;


	//menu
	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(NewGameScene_japan::GoBack, this));
    menu_item_1->setScale(1.2);
    menu_item_1->setPosition(Vec2(visibleSize.width - menu_item_1->getContentSize().width / 2 -borderWidth,
                                  menu_item_1->getContentSize().height / 2));


	auto *menu = Menu::create(menu_item_1, NULL);

	menu->setPosition(Point(0, 0));
	menu->setColor(Color3B::BLUE);
	this->addChild(menu, 6);

	////background
	auto bg_sprite_1 = Sprite::create("japan/japan1.png");
//    bg_sprite_1->setScale(0.8);
	// position the sprite on the center of the screen
	bg_sprite_1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_1 = MoveTo::create(100, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
//	auto action_1 = RepeatForever::create(Move_Down_1);
	bg_sprite_1->runAction(Move_Down_1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_1, 4);

	auto bg_sprite_2 = Sprite::create("japan/japan2.png");
//    bg_sprite_2->setScale(0.5);
	// position the sprite on the center of the screen
	bg_sprite_2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_2 = MoveTo::create(300, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
//	auto action_2 = RepeatForever::create(Move_Down_2);
	bg_sprite_2->runAction(Move_Down_2);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_2, 3);
	auto bg_sprite_3 = Sprite::create("japan/japan3.png");
//    bg_sprite_3->setScale(0.3);

	// position the sprite on the center of the screen
	bg_sprite_3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_3 = MoveTo::create(500, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
//	auto action_3 = RepeatForever::create(Move_Down_3);
	bg_sprite_3->runAction(Move_Down_3);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_3, 2);
	auto bg_sprite_4 = Sprite::create("japan/japan4.png");
	// position the sprite on the center of the screen
	bg_sprite_4->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	bg_sprite_4->setTag(1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_4, 1);
	this->schedule(schedule_selector(NewGameScene_japan::logic));

	//player

	m_player = Player::create();
    m_player->setPosition(Point(borderWidth * 0.6 + m_player->playerWidth/2, visibleSize.height * 0.16f));
	m_player->setTag(0);
	this->addChild(m_player, 5, 0);

	EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
	event->setSwallowTouches(true);
	event->onTouchBegan = CC_CALLBACK_2(NewGameScene_japan::onTouchBegan, this);
	event->onTouchMoved = CC_CALLBACK_2(NewGameScene_japan::onTouchMoved, this);
	event->onTouchEnded = CC_CALLBACK_2(NewGameScene_japan::onTouchEnded, this);
	event->onTouchCancelled = CC_CALLBACK_2(NewGameScene_japan::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);

	//Enemy
	float random_number_1 = rand() % 2 + 1;
	float random_number_2 = rand() % 3 + 1;
	float random_number_3 = rand() % 4 + 1;
	this->schedule(schedule_selector(NewGameScene_japan::newEnemy_left), random_number_1);
	this->schedule(schedule_selector(NewGameScene_japan::moveEnemy), 0.01f);
	this->schedule(schedule_selector(NewGameScene_japan::newEnemy_right), random_number_2);
	this->schedule(schedule_selector(NewGameScene_japan::moveEnemy), 0.01f);
	this->schedule(schedule_selector(NewGameScene_japan::newEnemy_crow), random_number_3);
	this->schedule(schedule_selector(NewGameScene_japan::moveEnemy), 0.01f);
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

void NewGameScene_japan::menuCloseCallback(Ref* pSender)
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
void NewGameScene_japan::logic(float dt)
{

}

bool NewGameScene_japan::onTouchBegan(Touch *touch, Event *unsured_event){
	
	auto my_player = dynamic_cast<Player*>(this->getChildByTag(0));

	Size visibleSize = Director::getInstance()->getWinSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	// add the label as a child to this layer



//	auto bg_sprite_4 = Sprite::create("japan/japan4.png");
//	bg_sprite_4->setScale(0.5);
//	auto bg_width = bg_sprite_4->getContentSize().width;

	int player_x = my_player->getPosition().x;

//	int x_right = (visibleSize.width + 0.5 * bg_width) * 0.5f - 75;
//	int x_left = (visibleSize.width - 0.5 * bg_width) * 0.5f + 75;
    
    int x_right = visibleSize.width - borderWidth*0.6 - my_player->playerWidth/2;
    int x_left = borderWidth * 0.6 + my_player->playerWidth/2;

	auto MoveToRight = MoveTo::create(0.5, Point(x_right, visibleSize.height * 0.16f));
	auto  MoveToLeft = MoveTo::create(0.5, Point(x_left, visibleSize.height * 0.16f));

	if (player_x == x_right){

		my_player->isLeft = true;



		my_player->runAction(MoveToLeft);
	}
	else if (player_x == x_left){


		my_player->runAction(MoveToRight);
		my_player->isLeft = false;
	}
	testTouchBegin = touch->getLocation();
	return true;
}

void NewGameScene_japan::onTouchMoved(Touch * touch, Event *unsured_event){

}

void NewGameScene_japan::onTouchEnded(Touch *touch, Event *unused_event){
}

void NewGameScene_japan::onTouchCancelled(Touch *touch, Event *unused_event){

}


//enemy
void NewGameScene_japan::moveEnemy(float t) {
	auto size = Director::getInstance()->getWinSize();

		for (auto enemy : allEnemy) {
			enemy->setPositionY(enemy->getPositionY() - 3);
			if (enemy->getPositionY() < 0) {
				enemy->removeFromParent();
			}
		}
};
void NewGameScene_japan::killMe(Node * pSender) {
	pSender->removeFromParentAndCleanup(true);
};

void NewGameScene_japan::jumpToMenu(){
	Director::getInstance()->replaceScene(HelloWorld::createScene());

};

void NewGameScene_japan::newEnemy_left(float t) {
	auto size = Director::getInstance()->getWinSize();
	auto bg_sprite_4 = Sprite::create("japan/japan4.png");
	auto border = Sprite::create("border/border_j.png");
	auto bg_width = 0.5f * (bg_sprite_4->getContentSize().width);
	auto border_width = border->getContentSize().width;
	
	Sprite * enemy;
	int num = rand() % 10;
	if (num < 5) {
		enemy = Sprite::create("aaa.png");
		enemy->setTag(100);
	}
	else if(num == 6){
		enemy = Sprite::create("star.png");
		enemy->setScale(0.5);
		enemy->setTag(101);
	}
	else {
		enemy = Sprite::create("ccc.png");
		enemy->setTag(100);
	}
	
	auto random_number = rand() % 600;
	auto max_number = size.width * 0.5f;
	auto min_number = size.width * 0.5f - 0.5f * bg_width + border_width;

	enemy->setPosition(Point(random_number % (int)(max_number - min_number) + min_number, size.height));

	this->addChild(enemy, 7);
	allEnemy.pushBack(enemy);
}

void NewGameScene_japan::newEnemy_right(float t) {
	auto size = Director::getInstance()->getWinSize();
	auto bg_sprite_4 = Sprite::create("japan/japan4.png");
	auto border = Sprite::create("border/border_j.png");
	auto bg_width = 0.5f * (bg_sprite_4->getContentSize().width);
	auto border_width = border->getContentSize().width;

	Sprite * enemy;
	int num = rand() % 10;
	if (num < 8) {
		enemy = Sprite::create("japan/roof.png");
		enemy->setScale(0.5);
		enemy->setTag(100);
	}
	else {
		enemy = Sprite::create("aaa.png");
		
		enemy->setTag(100);
	}

	enemy->setPosition(Point(size.width * 0.5f + bg_width * 0.5f - border_width, size.height));
	this->addChild(enemy, 7);
	allEnemy.pushBack(enemy);
}
void NewGameScene_japan::newEnemy_crow(float t){
	auto size = Director::getInstance()->getWinSize();
	auto crow = Sprite::create();
	auto bg_sprite_4 = Sprite::create("japan/japan4.png");
	auto bg_width = bg_sprite_4->getContentSize().width * 0.5f;
	crow->setTag(110);
	Vector<SpriteFrame *> allframe;
	for (int i = 0; i < 4; i++){
		SpriteFrame *sf = SpriteFrame::create("japan/crow.png", Rect(i * 347 / 4, 0, 347 / 4, 73));
		allframe.pushBack(sf);
	}
	Animation * ani = Animation::createWithSpriteFrames(allframe, 0.1);
	crow->runAction(RepeatForever::create(Animate::create(ani)));
	crow->setPosition(Point(start_point, 0.8f * size.height));

	auto Move_2 = MoveBy::create(4, Vec2(bg_width, 0));
	crow->runAction(Move_2);
	this->addChild(crow, 7);
	allEnemy.pushBack(crow);
}
void NewGameScene_japan::update(float t) {
	
	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto plane = this->getChildByTag(0);
	Rect pp(plane->getPositionX(), plane->getPositionY(), 40, 50);
	auto p_x = this->getPositionX();
	auto p_y = this->getPositionY();


	for (int i = 0; i < allEnemy.size(); i++) {
		auto enemy = allEnemy.at(i);
		Rect er(enemy->getPositionX(), enemy->getPositionY(), 40, 50);
		auto shake1 = MoveTo::create(0.01, Point(p_x, p_y - 8.0f));
		auto shake2 = MoveTo::create(0.01, Point(p_x, p_y + 8.0f));

		auto shake3 = MoveTo::create(0.01, Point(p_x, p_y));

		//test
		if (pp.intersectsRect(er) && HP >= 0) {

			if (auto identifier = this->getChildByTag(101)){
				HP++;
				enemy->removeFromParent();
				allEnemy.eraseObject(enemy);
				auto label = Label::createWithTTF("HP +1", "fonts/Marker Felt.ttf", 24);
				label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
				auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
				auto action_3 = RepeatForever::create(Move_Down_3);
				label->setColor(Color3B::RED);
				label->runAction(action_3);
				this->addChild(label, 8);

				
			}
			else{
				HP--;
				enemy->removeFromParent();
				allEnemy.eraseObject(enemy);
				this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));
				//AudioServicePlaySystemSound(kSystemSoundID_Vibrate);

				//in ios/SimpleAudioEngine.mm, add 
				//void SimpleAudioEngine::vibrate(){
				//	AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
				//}

				auto label = Label::createWithTTF("HP -1", "fonts/Marker Felt.ttf", 24);
				label->setPosition(Point(origin.x + visibleSize.width / 2, 0));
				auto Move_Down_3 = MoveBy::create(1, Vec2(0, visibleSize.height / 2));
				auto action_3 = RepeatForever::create(Move_Down_3);
				label->setColor(Color3B::RED);
				label->runAction(action_3);
				this->addChild(label, 8);
				
			}
		}
		else if (pp.intersectsRect(er) && HP < 0){

			enemy->removeFromParent();
			allEnemy.eraseObject(enemy);
			this->runAction(Sequence::create(shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, shake1, shake2, shake3, NULL));

			this->pause();
			Director::getInstance()->replaceScene(TransitionJumpZoom::create(2, GameOver::createScene()));


		}
	}
};
