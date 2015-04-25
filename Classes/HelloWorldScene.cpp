#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "NewGameScene.h"
#include "NewGameScene_japan.h"
#include "NewGameScene_halloween.h"
#include "Setting.h"
#include "halloween.h"
#include "MenuSettings.h"
#include "HighScore.h"

USING_NS_CC;
HelloWorld::~HelloWorld(){}
Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
	
    return scene;
}


bool HelloWorld::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
	Size windowSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    m_bg1 = Sprite::create("bg.png");
    m_bg1->setTag(1);
    m_bg1->setPosition(Point(windowSize.width/2, windowSize.height/2));
    bg_scale = visibleSize.height / m_bg1->getContentSize().height;
    m_bg1->setScaleY(bg_scale);
    this->addChild(m_bg1);
    
    m_bg2 = Sprite::create("bg.png");
    m_bg2->setTag(2);
    m_bg2->setPosition(Point(m_bg1->getPositionX()-m_bg2->getContentSize().width, windowSize.height/2));
    m_bg2->setScaleY(bg_scale);
    this->addChild(m_bg2);
    

	//close button
    auto closeItem = MenuItemImage::create("Menu/pause.png",
                                           "Menu/pause1.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2*1.3 ,
                                origin.y + closeItem->getContentSize().height/2*1.3));
    //closeItem->setScale(1.5);
    auto menu_1 = Menu::create(closeItem, NULL);
    menu_1->setPosition(Vec2::ZERO);
    this->addChild(menu_1, 2);

	//title
    auto label = Label::createWithTTF("Hello Ninja!", "fonts/Marker Felt.ttf", 40);
    

    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 2);

	//add player logo
	Sprite_1 = Sprite::create("clumsy_ninja.png");
	Sprite_1->setScale(0.75);
	Sprite_1->setPosition(Point(100, 100));
	this->addChild(Sprite_1, 0);
	//auto Move_To = MoveTo::create(3, Point((visibleSize.width / 2) + 10 + origin.x, (visibleSize.height / 2) + 10 + origin.y));
	auto Jump_By = JumpBy::create(3, Point(100, 0), 50, 3);
	auto action = RepeatForever::create(Jump_By);
	//auto action1 = Repeat::create(Jump_By, 5);
	//auto seq = Sequence::create(Move_To, action1, nullptr);
	Sprite_1->runAction(action);

	//main menu
	auto menu_item_1 = MenuItemImage::create("Menu/Ocean1.png"			, "Menu/Ocean2.png"			, CC_CALLBACK_1(HelloWorld::Play		, this));
	
	auto menu_item_2 = MenuItemImage::create("Menu/Nihon1.png"			, "Menu/Nihon2.png"			, CC_CALLBACK_1(HelloWorld::Nihon	, this));

	auto menu_item_3 = MenuItemImage::create("Menu/Horror1.png"			, "Menu/Horror2.png"		, CC_CALLBACK_1(HelloWorld::Halloween, this));

	//auto menu_item_4 = MenuItemImage::create("Menu/Resume.png", "Menu/Resume_1.png", CC_CALLBACK_1(HelloWorld::Resume, this));

	//auto menu_item_5 = MenuItemImage::create("Menu/Highscores.png", "Menu/Highscores_1.png", CC_CALLBACK_1(HelloWorld::Highscores, this));

	auto menu_item_4 = MenuItemImage::create("Menu/option.png", "Menu/option1.png", CC_CALLBACK_1(HelloWorld::Settings, this));

    auto menu_item_5 = MenuItemImage::create("Menu/Highscores.png"			, "Menu/Highscores_1.png"		, CC_CALLBACK_1(HelloWorld::Highscores, this));
    
    menu_item_1->setScale(1.2);
    menu_item_2->setScale(1.2);
    menu_item_3->setScale(1.2);
    menu_item_4->setScale(1.2);
    menu_item_5->setScale(0.8);
	//menu_item_6->setScale(0.8);
	auto menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_5, menu_item_4, NULL);
	menu->alignItemsVertically();
	this->addChild(menu,3);

	//background music    
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/Ninja.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/Ninja.mp3", true);

	isPause = false;
	//playonloop.com

	//touch effects
	auto listener_1 = EventListenerTouchAllAtOnce::create();

	listener_1->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	listener_1->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
	listener_1->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_1, this);
	this->schedule(schedule_selector(HelloWorld::bgMv));
	return true;
}

void HelloWorld::Play(cocos2d::Ref *pSender){
	CCLOG("Play");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	auto scene = NewGameScene::createScene();
	Director::getInstance()->replaceScene(scene);


}
void HelloWorld::Resume(cocos2d::Ref *pSender){
	CCLOG("Resume");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
}
void HelloWorld::Highscores(cocos2d::Ref *pSender){
	CCLOG("HS");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    auto scene = HighScore::createScene();
    Director::getInstance()->pushScene(scene);
}
void HelloWorld::Nihon(cocos2d::Ref *pSender){
	CCLOG("Nihon");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	auto scene = NewGameScene_japan::createScene();
	Director::getInstance()->replaceScene(scene);

}

void HelloWorld::Halloween(cocos2d::Ref *pSender){
	CCLOG("HalloWeen");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	auto scene = NewGameScene_halloween::createScene();
	Director::getInstance()->replaceScene(scene);

}

void HelloWorld::Settings(cocos2d::Ref *pSender){
	CCLOG("Settings");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/swordClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	auto scene = MenuSettings::createScene();
	Director::getInstance()->pushScene(scene);

}




void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event6){
	CCLOG("touches Eneded");
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event5){
	CCLOG("touches moved");
}


void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event4){

	//Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite_1 = Sprite::create("clumsy_ninja.png");
	Sprite_1->setScale(0.7);
	Sprite_1->setPosition(Point(100, 100));
	this->addChild(Sprite_1, 1);
	//auto Move_To = MoveTo::create(3, Point((visibleSize.width / 2) + 10 + origin.x, (visibleSize.height / 2) + 10 + origin.y));
	auto Jump_By = JumpBy::create(3, Point(100, 0), 50, 3);


	auto action = RepeatForever::create(Jump_By);
	//auto action1 = Repeat::create(Jump_By, 5);

	//auto action = Repeat::create(RotateBy::create(2, 15), 5);
	//auto seq = Sequence::create(Move_To, action1, nullptr);
	Sprite_1->runAction(action);

}

void HelloWorld::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event *event3){

	CCLOG("onTouchEnded x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);

}

void HelloWorld::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event *event2){

	CCLOG("onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	
}

bool HelloWorld::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event *event1){
	CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite_1 = Sprite::create("clumsy_ninja.png");
	Sprite_1->setScale(0.8);
	Sprite_1->setPosition(Point(100, 100));
	this->addChild(Sprite_1, 1);
	//auto Move_To = MoveTo::create(3, Point((visibleSize.width / 2) + 10 + origin.x, (visibleSize.height / 2) + 10 + origin.y));
	auto Jump_By = JumpBy::create(3, Point(100, 0), 50, 3);


	auto action = RepeatForever::create(Jump_By);
	//auto action1 = Repeat::create(Jump_By, 5);

	//auto action = Repeat::create(RotateBy::create(2, 15), 5);
//	auto seq = Sequence::create(Move_To, action1, nullptr);
	Sprite_1->runAction(action);

	
	return true;
}
	
void HelloWorld::PauseMusic(float dt){
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}
void HelloWorld::ResumeMusic(float dt){
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void HelloWorld::StopMusic(float dt){
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


//http://blog.csdn.net/musicvs/article/details/24928929
void HelloWorld::bgMv(float t) {
    auto size = Director::getInstance()->getWinSize();
    auto bk1 = this->getChildByTag(1);
    auto bk2 = this->getChildByTag(2);
    bk1->setPositionX(bk1->getPositionX() - 10);
    bk2->setPositionX(bk2->getPositionX() - 10);
    if (bk1->getPositionX() < -bk1->getContentSize().width/2) {
        bk1->setPositionX(bk2->getPositionX()+bk2->getContentSize().width);
    }
    else if(bk2->getPositionX() < -bk2->getContentSize().width/2 ) {
        bk2->setPositionX(bk1->getPositionX()+bk1->getContentSize().width);
    }
}
