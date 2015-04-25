#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class BgLayer;
class HelloWorld : public cocos2d::Layer
{
public:
	~HelloWorld();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void clickStart(cocos2d::Ref* pSender);
	void clickResume(cocos2d::Ref* pSender);
	void clickOptions(cocos2d::Ref* pSender);
	void clickLevel(cocos2d::Ref* pSender);





	void Play(cocos2d::Ref* pSender);
	void Highscores(cocos2d::Ref* pSender);
	void Settings(cocos2d::Ref* pSender);
	void Resume(cocos2d::Ref* pSender);
	void Nihon(cocos2d::Ref* pSender);
	void Halloween(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	cocos2d::Sprite * Sprite_1;

	void StopMusic(float dt);
	void PauseMusic(float dt);
	void ResumeMusic(float dt);

	bool isPause;
    float bg_scale;

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event1);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event2);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event3);

	void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event * event4);
	void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event * event5);
	void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event * event5);

private:
    Sprite* m_bg1;
    Sprite* m_bg2;
    void bgMv(float t);
};

#endif // __HELLOWORLD_SCENE_H__
