#ifndef BackgroundLayer_halloween_H
#define BackgroundLayer_halloween_H

#include "cocos2d.h"
USING_NS_CC;

class BackgroundLayer_halloween : public Layer
{
public:
	BackgroundLayer_halloween();
	~BackgroundLayer_halloween();
	CREATE_FUNC(BackgroundLayer_halloween);
	virtual bool init();

	void logic(float dt);
    int borderWidth;
private:
	Sprite* m_bg1;
	Sprite* m_bg2;
	Sprite* m_bg3;
	Sprite* m_bg4;
	Sprite* border1;
	Sprite* border2;
	Sprite* border3;
	Sprite* border4;

	Sprite* createBorder_left(Point pos);
	Sprite* createBorder_right(Point pos);
};

#endif
