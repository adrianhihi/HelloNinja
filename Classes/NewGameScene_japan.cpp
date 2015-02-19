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
		label->getContentSize().height/2));

	// add the label as a child to this layer
	this->addChild(label, 6);
    auto border = BackgroundLayer_japan::create();
    borderWidth = border->borderWidth;


	//menu
	auto menu_item_1 = MenuItemFont::create("Go Back", CC_CALLBACK_1(NewGameScene_japan::GoBack, this));
    menu_item_1->setScale(1.2);
    menu_item_1->setPosition(Vec2(visibleSize.width - menu_item_1->getContentSize().width - borderWidth/2,
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


    // HP label
    
    auto labelHp = Label::createWithSystemFont(StringUtils::format("Hp: %d", HP), "fonts/Marker Felt.ttf", 40);
    labelHp->setColor(Color3B::RED);
    labelHp->setPosition(Vec2(origin.x + visibleSize.width / 2,
                              origin.y + visibleSize.height - label->getContentSize().height));
    labelHp->setTag(110);
    this->addChild(labelHp, 2);
    
	//player

	m_player = Player::create();
	m_player->setTag(0);
    m_player->setPosition(Point(borderWidth * 0.75 + m_player->playerWidth/2, visibleSize.height * 0.16f));
    this->addChild(m_player, 5, 0);

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
    m_backgroundLayer->logic(t);
}


bool NewGameScene_japan::onTouchBegan(Touch *touch, Event *unsured_event){
	
	auto my_player = (Player *) this->getChildByTag(0);

	Size size = Director::getInstance()->getWinSize();
	
	// add the label as a child to this layer



	int player_x = my_player->getPosition().x;

    
    int x_right = size.width - borderWidth * 0.75 - my_player->playerWidth/2;
    int x_left = borderWidth * 0.75 + my_player->playerWidth/2;

	if (player_x == x_right){


        my_player-> runAction(MoveTo::create(0.5, Point(x_left, size.height * 0.16f)));
        my_player->m_dir = DIR_LEFT;
        my_player->logic();
	}
	else if (player_x == x_left){
        my_player-> runAction(MoveTo::create(0.5, Point(x_right, size.height * 0.16f)));
        
        my_player->m_dir = DIR_RIGHT;
        my_player->logic();
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

		for (auto enemy : allEnemyRoof) {
			enemy->setPositionY(enemy->getPositionY() + m_backgroundLayer->iSpeed);
			if (enemy->getPositionY() < 0) {
				enemy->removeFromParent();
                allEnemyRoof.eraseObject(enemy);
			}
		}
};

void NewGameScene_japan::moveEnemyFallen(float t) {
    
    for (auto enemy : allEnemyFallen) {
        enemy->setPositionY(enemy->getPositionY() + m_backgroundLayer->iSpeed);
        if (enemy->getPositionY() < 0) {
            enemy->removeFromParent();
            allEnemyFallen.eraseObject(enemy);
        }
    }
};

void NewGameScene_japan::moveStar(float t) {
    
    for (auto star : allStar) {
        star->setPositionY(star->getPositionY() - 10);
        if (star->getPositionY() < 0) {
            star->removeFromParent();
            allStar.eraseObject(star);
        }
    }
};

void NewGameScene_japan::moveEnemyLeft(float t) {
    auto size = Director::getInstance()->getWinSize();
//    for(auto enemyLeftCrow: allEnemyLeftCrow) {
    for (int i = 0; i < allEnemyLeftCrow.size(); i++) {
        auto enemyLeftCrow = allEnemyLeftCrow.at(i);
        if (enemyLeftCrow->getPositionY() > size.height - 200) {
            enemyLeftCrow->setPositionY(enemyLeftCrow->getPositionY() + m_backgroundLayer->iSpeed);
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
            enemyRightCrow->setPositionY(enemyRightCrow->getPositionY() + m_backgroundLayer->iSpeed);
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

	Sprite * enemy;
    Sprite * star;
    Sprite * crow;
    
    int RandNum = random(0, 13);
    
    if (enemyLeftRightDis < 12 && enemyLeftRightDis > 9) {
        while (enemyLeftRightDis == RandNum) {
            RandNum = random(0, 13);
        }
        
        if (enemyLeftRightDis < 12 && enemyLeftRightDis > 9){
            enemyLeftRightDis = RandNum;
        }
    }
    
    auto roof = Sprite::create("japan/roof_r.png");
    int roofWidth = roof->getContentSize().width;
    
    if (RandNum < 3) {
        enemy = Sprite::create("japan/roof_r.png");
        enemy->setPosition(Point(size.width - border_width - enemy->getContentSize().width/2, size.height + 100));
    }
    else if (RandNum < 6) {
        enemy = Sprite::create("japan/roof_l.png");
        enemy->setPosition(Point(border_width + enemy->getContentSize().width/2, size.height + 100));
    }
    else if (RandNum < 9) {
        if (RandNum < 8) {
           enemy = Sprite::create("aaa.png");
        }
        else{
           enemy = Sprite::create("ccc.png");
        }
        int x = random(border_width + enemy->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - enemy->getContentSize().width/2);
        enemy->setPosition(Point(x, size.height+100));
    }
    else if (RandNum == 9) {
        star = Sprite::create("star.png");
        int x = random(border_width + star->getContentSize().width/2 + roofWidth, size.width- border_width - roofWidth - star->getContentSize().width/2);
        star->setPosition(Point(x, size.height+100));
    }
    else if (RandNum < 12) {
        Vector<SpriteFrame *> crowFram;
        if (RandNum == 10) {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_left.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }

        }
        else {
            for (int i = 0; i < 4; i++) {
                auto sf = SpriteFrame::create("japan/crow_right.png", Rect(i*300/4, 0, 300/4, 63));
                crowFram.pushBack(sf);
            }
        }
        auto ani = Animation::createWithSpriteFrames(crowFram, 0.03);
        crow = Sprite::create();
        crow->runAction(RepeatForever::create(Animate::create(ani)));
    }
		
    
    if (RandNum < 6 && allEnemyRightCrow.size() == 0 && allEnemyLeftCrow.size() == 0) {
        this->addChild(enemy, 7);
        allEnemyRoof.pushBack(enemy);
    }
    else if (RandNum < 9 && allEnemyRightCrow.size() == 0 && allEnemyLeftCrow.size() == 0) {
        this->addChild(enemy, 7);
        allEnemyFallen.pushBack(enemy);
    }
    else if (RandNum == 9) {
        this->addChild(star, 7);
        allStar.pushBack(star);
    }
    else if (RandNum < 12) {
        if (RandNum == 10 && allEnemyLeftCrow.size() == 0) {
            crow->setPosition(size.width - borderWidth - crow->getContentSize().width/2, size.height + 100);
            allEnemyRightCrow.pushBack(crow);
            this->addChild(crow, 7);
        }
        else if (RandNum == 11 && allEnemyRightCrow.size() == 0){
            crow->setPosition(borderWidth + crow->getContentSize().width/2, size.height + 100);
            allEnemyLeftCrow.pushBack(crow);
            this->addChild(crow, 7);
        }
        
    }
	
}

void NewGameScene_japan::update(float t) {
	
	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto plane = this->getChildByTag(0);
	Rect pp(plane->getPositionX(), plane->getPositionY(), 100, 100);
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
    
    
};
