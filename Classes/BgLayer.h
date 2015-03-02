#ifndef BgLayer_H
#define BgLayer_H
#include "cocos2d.h"
USING_NS_CC;
class BgLayer : public Layer
{
public:
	BgLayer();
	~BgLayer();
	CREATE_FUNC(BgLayer);
	virtual bool init();
	void logic(float dt);
private:
	Sprite* m_bg1;
	Sprite* m_bg2;
};
#endif
