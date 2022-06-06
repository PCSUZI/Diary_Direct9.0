#pragma once
#include "MySprite.h"

enum UICleck
{
	START,
	INTRO,
	EXIT

};

class GameUI : public CMySprite
{
protected:
	RECT m_start[2];
	RECT m_Intro[2];
	RECT m_Exit[2];

	int m_start_Index;
	int m_Intro_Index;
	int m_Exit_Index;

	//·»´õ¸µ À§Ä¡
	POINT p_start;
	POINT p_Intro;
	POINT p_Exit;


public:
	GameUI();
	~GameUI();

	void Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height);
	void Intro_Draw();
	void OnUpdate(float time);

	UICleck CheckMouseClick(POINT pt);
	void CheckMouseMove(POINT pt);


	void Select_Draw();
	void ReGame_Draw();
};

