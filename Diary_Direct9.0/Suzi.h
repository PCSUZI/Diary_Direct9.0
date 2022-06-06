#pragma once
#include "MySprite.h"

class Suzi : public CMySprite
{
protected:
	RECT m_Suzi;

	POINT p_Eye;
	
	int m_yPos;



public:
	Suzi();
	~Suzi();

	RECT m_rcCollision;

	void Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height);
	void OnDraw();
	void OnUpdate(float time);

	void CheckMouseMove(POINT pt);
};

