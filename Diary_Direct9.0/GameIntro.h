#pragma once

#include "MySprite.h"


class GameIntro : public CMySprite
{
protected:
	RECT m_Background[8];

	//0 메인화면 1 설명 2,3 게임화면 4 성공 5 오버
	int Game_Backgroung_Index;
	float m_interval;
public:
	GameIntro();
	virtual ~GameIntro();

	int Page_index;

	void Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height);
	void OnDraw();
	void OnUpdate(float time);

	void Set_BackGroung_Index(int x);
	void Game1_BackGround(float time);


};

