#pragma once
#include "MySprite.h"


class MouseFollow : public CMySprite
{
protected:
	RECT m_BlackGround[7];

	//·»´õ¸µ À§Ä¡
	POINT p_Eye;

	int Eye_index;
	float m_interval;
public:
	MouseFollow();
	~MouseFollow();

	int GameScore;

	void Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height);
	void OnDraw();
	void OnUpdate(float time);

	void CheckMouseMove(POINT pt);


};

