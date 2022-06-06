#pragma once
#include "MySprite.h"

class Study : public CMySprite
{
protected:
	RECT m_object;



	float m_interval;
	bool is_Draw;

public:
	Study();
	~Study();

	RECT m_rcCollision;
	POINT m_Pos;

	void Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height);
	void OnDraw();
	void OnUpdate(float time);

	void Loding();
	void reset(float tick);
	void move(float time);

};

