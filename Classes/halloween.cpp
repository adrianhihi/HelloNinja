#include "halloween.h"
#include "HelloWorldScene.h"
#include "BackgroundLayer.h"
//#include "BgLayer.h"
#include "simpleAudioEngine.h"
#include "Player.h"
#include "ObjectTag.h"
#include "BackgroundLayer_halloween.h"
#include "GameOver.h"


Halloween::~Halloween(){}


Scene* Halloween::createScene()
{

	auto Halloween = Scene::createWithPhysics();
	Vect gravity(0, -0.5f);
	Halloween->getPhysicsWorld()->setGravity(gravity);
	Halloween->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	Size visibleSize = Director::getInstance()->getVisibleSize();


	auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width, visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto node = Node::create();
	node->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	node->setPhysicsBody(body);

	Halloween->addChild(node);

	auto backgroundLayer = BackgroundLayer_halloween::create();
	Halloween->addChild(backgroundLayer, 4);

	// 'layer' is an autorelease object
	auto layer = Halloween::create();
	// add layer as a child to scene
	Halloween->addChild(layer);
	layer->m_backgroundLayer = backgroundLayer;
	backgroundLayer->setTag(9);
	//add the monster layer
	//auto monsterLayer = MonsterLayer::create();
	//NewGame_scene->addChild(monsterLayer, 5);

	//layer->m_monsterLayer = monsterLayer;

	return Halloween;
}

bool Halloween::init()
{
	if (!Layer::init()){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// position the label on the center of the screen
	auto label = Label::createWithTTF("Halloween Mission!", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 2);
    auto border = BackgroundLayer_halloween::create();
    borderWidth = border->borderWidth;


	//menu
	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(Halloween::GoBack, this));
    menu_item_1->setScale(1.2);
    menu_item_1->setPosition(Vec2(visibleSize.width - menu_item_1->getContentSize().width / 2 -borderWidth,
                                  menu_item_1->getContentSize().height / 2));


	auto *menu = Menu::create(menu_item_1, NULL);
	menu->setPosition(Point(0, 0));
	menu->setColor(Color3B::BLUE);
	this->addChild(menu, 6);

	////background
	auto bg_sprite_1 = Sprite::create("halloween/Halloween1.png");
	// position the sprite on the center of the screen
	bg_sprite_1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_1 = MoveTo::create(100, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
//	auto action_1 = RepeatForever::create(Move_Down_1);
	bg_sprite_1->runAction(Move_Down_1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_1, 4);

	auto bg_sprite_2 = Sprite::create("halloween/Halloween2.png");
	// position the sprite on the center of the screen
	bg_sprite_2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_2 = MoveTo::create(300, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
//	auto action_2 = RepeatForever::create(Move_Down_2);
	bg_sprite_2->runAction(Move_Down_2);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_2, 3);
	auto bg_sprite_3 = Sprite::create("halloween/Halloween3.png");
	// position the sprite on the center of the screen
	bg_sprite_3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Move_Down_3 = MoveTo::create(500, Point(visibleSize.width / 2 + origin.x, -visibleSize.height / 2));
//	auto action_3 = RepeatForever::create(Move_Down_3);
	bg_sprite_3->runAction(Move_Down_3);

	// add the sprite as a child to this layer
	this->addChild(bg_sprite_3, 2);
	auto bg_sprite_4 = Sprite::create("halloween/Halloween4.png");
	// position the sprite on the center of the screen
	bg_sprite_4->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	bg_sprite_4->setTag(1);
	// add the sprite as a child to this layer
	this->addChild(bg_sprite_4, 1);
	this->schedule(schedule_selector(Halloween::logic));

	//player

    auto m_player = Player::create();
    m_player->setPosition(Point(borderWidth * 0.6 + m_player->playerWidth/2, visibleSize.height * 0.16f));
	m_player->setTag(0);
	this->addChild(m_player, 5, 0);

	EventListenerTouchOneByOne * event = EventListenerTouchOneByOne::create();
	event->setSwallowTouches(true);
	event->onTouchBegan = CC_CALLBACK_2(Halloween::onTouchBegan, this);
	event->onTouchMoved = CC_CALLBACK_2(Halloween::onTouchMoved, this);
	event->onTouchEnded = CC_CALLBACK_2(Halloween::onTouchEnded, this);
	event->onTouchCancelled = CC_CALLBACK_2(Halloween::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);

	//Enemy
	float random_number_1 = rand() % 2 + 1;
	float random_number_2 = rand() % 3 + 1;
	float random_number_3 = rand() % 4 + 1;
	this->schedule(schedule_selector(Halloween::newEnemy_left), random_number_1);
	this->schedule(schedule_selector(Halloween::moveEnemy), 0.01f);
	this->schedule(schedule_selector(Halloween::newEnemy_right), random_number_2);
	this->schedule(schedule_selector(Halloween::moveEnemy), 0.01f);
	this->schedule(schedule_selector(Halloween::newEnemy_crow), random_number_3);
	this->schedule(schedule_selector(Halloween::moveEnemy), 0.01f);
	//http://www.hawstein.com/posts/ctci-solutions-contents.html

	this->scheduleUpdate();



	return true;
}


void Halloween::onExit()
{
	Layer::onExit();

	_eventDispatcher->removeEventListenersForTarget(this);
}


void Halloween::GoBack(cocos2d::Ref *pSender){
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void Halloween::menuCloseCallback(Ref* pSender)
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
void Halloween::logic(float dt)
{
	m_backgroundLayer->logic(dt);
	//m_monsterLayer->logic(dt);
}

bool Halloween::onTouchBegan(Touch *touch, Event *unsured_event){

	auto my_player = dynamic_cast<Player*>(this->getChildByTag(0));
	Size visibleSize = Director::getInstance()->getWinSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add the label as a child to this layer




	int player_x = my_player->getPosition().x;

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

void Halloween::onTouchMoved(Touch * touch, Event *unsured_event){

	cocos2d::log("touch moved");
}

void Halloween::onTouchEnded(Touch *touch, Event *unused_event){

}

void Halloween::onTouchCancelled(Touch *touch, Event *unused_event){
	cocos2d::log("touch cancelled");
}


//enemy
void Halloween::moveEnemy(float t) {
	auto size = Director::getInstance()->getWinSize();
	//if (auto identifier = this->getChildByTag(110)){

	//	//identifier->setPositionX(identifier->getPositionX() + 10);
	//	identifier->setPositionX(identifier->getPositionY() - 3);
	//	if (identifier->getPositionY() < 0) {
	//		identifier->removeFromParent();
	//	}
	//	
	//}
	//else{
	for (auto enemy : allEnemy) {
		enemy->setPositionY(enemy->getPositionY() - 3);
		if (enemy->getPositionY() < 0) {
			enemy->removeFromParent();
			//allEnemy.eraseObject(enemy);
		}
	}
	//}
};
void Halloween::killMe(Node * pSender) {
	pSender->removeFromParentAndCleanup(true);
};

void Halloween::jumpToMenu(){
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(HelloWorld::createScene());

};

void Halloween::newEnemy_left(float t) {
	auto size = Director::getInstance()->getWinSize();
	auto bg_sprite_4 = Sprite::create("halloween/Halloween4.png");
	auto border = Sprite::create("border/border_h_1.png");
	auto bg_width = 0.5f * (bg_sprite_4->getContentSize().width);
	auto border_width = border->getContentSize().width;

	Sprite * enemy;
	int num = rand() % 10;
	if (num < 5) {
		enemy = Sprite::create("aaa.png");
		enemy->setTag(100);
	}
	else if (num == 6){
		enemy = Sprite::create("star.png");
		enemy->setScale(0.5);
		enemy->setTag(101);
	}
	else {
		enemy = Sprite::create("ccc.png");
		enemy->setTag(100);
	}
	auto sp_width = enemy->getContentSize().width;

	auto random_number = rand() % 600;
	auto max_number = size.width * 0.5f;
	auto min_number = size.width * 0.5f - 0.5f * bg_width + border_width;

	enemy->setPosition(Point(random_number % (int)(max_number - min_number) + min_number, size.height));

	//log("*****%f*****\n", random_number % (int)(max_number - min_number) + min_number);
	this->addChild(enemy, 7);
	allEnemy.pushBack(enemy);
}

void Halloween::newEnemy_right(float t) {
	auto size = Director::getInstance()->getWinSize();
	auto bg_sprite_4 = Sprite::create("halloween/Halloween4.png");
	auto border = Sprite::create("border/border_h_1.png");
	auto bg_width = 0.5f * (bg_sprite_4->getContentSize().width);
	auto border_width = border->getContentSize().width;

	Sprite * enemy;
	int num = rand() % 10;
	if (num < 8) {
		enemy = Sprite::create("ccc.png");
		enemy->setScale(0.5);
		enemy->setTag(100);
	}
	else {
		enemy = Sprite::create("aaa.png");

		enemy->setTag(100);
	}
	auto sp_width = enemy->getContentSize().width * 0.5f;

	/*auto random_number = rand() % 600;
	auto min_number = size.width * 0.5f;
	auto max_number = size.width * 0.5f + 0.5f * bg_width - border_width;

	enemy->setPosition(Point(random_number % (int)(max_number - min_number) + min_number, size.height));*/

	enemy->setPosition(Point(size.width * 0.5f + bg_width * 0.5f - border_width, size.height));
	this->addChild(enemy, 7);
	allEnemy.pushBack(enemy);
}
void Halloween::newEnemy_crow(float t){
	auto size = Director::getInstance()->getWinSize();
	auto crow = Sprite::create();
	auto bg_sprite_4 = Sprite::create("halloween/Halloween4.png");
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
void Halloween::update(float t) {

	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto plane = this->getChildByTag(0);
	auto bg = this->getChildByTag(1);
	auto bg_border = this->getChildByTag(9);
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
