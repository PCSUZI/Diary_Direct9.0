#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "GameIntro.h"
#include "GameUI.h"
#include "Fairy.h"
#include "MyRect.h"
#include "MouseFollow.h"
#include "Time.h"
#include "Suzi.h"
#include "Study.h"

#define WIN_GAME_1_SCORE 10
#define WIN_GAME_2_SCORE 5

#define GAME_1_GAMETIME 30
#define GAME_2_GAMETIME 10

enum class EState { Intro = 0, GameSelect = 1, GameLoding = 2, Game = 3, GameWin = 4, GameOver = 5, NextGameOver = 6 , SubGame=7};
enum class EGame { Null_Game = 0, MainGame = 1, SubGame = 2 };

LPDIRECT3DDEVICE9  g_pd3dDevice = NULL;

//GameState
EState State;
EGame Game;

//GameManger
GameIntro g_Main;
GameUI g_UI;
Time Gametime_Manger;

//Game1
Fairy g_aniSprite[5];
MouseFollow g_Eye;

//Game2
Suzi g_Suzi;
Study g_work[3];

//Function
void ImageCreate();
void Reset();

//폰트
LPD3DXFONT			 g_pd3dxFont = NULL;
char c_count[65] = { "0" };
char c_game[65] = { "0" };
RECT TimeRect;
RECT destRect1;
RECT destRect2;

void GameInit()
{
	State = EState::Intro;
	Game = EGame::Null_Game;

	ImageCreate();

	g_work[1].m_Pos.x = 100; g_work[1].m_Pos.y = 100;
	g_work[2].m_Pos.x = 300; g_work[2].m_Pos.y = -100;

}

//그리기 담당 함수
void My_Game_Draw(float time)
{

	switch (State)
	{
	case EState::Intro:
		g_Main.Set_BackGroung_Index((int)EState::Intro);
		g_Main.OnUpdate(time);
		g_UI.Intro_Draw();

		break;
	case EState::GameSelect:
		g_Main.Set_BackGroung_Index((int)EState::GameSelect);
		g_Main.OnUpdate(time);
		g_UI.Select_Draw();
		break;
	case EState::GameLoding:
		g_Main.Set_BackGroung_Index((int)EState::Game);
		Gametime_Manger.setGameTime(GAME_1_GAMETIME);
		Reset();
		State = EState::Game;
		break;
	case EState::Game:
		g_Main.OnUpdate(time);
		g_Main.Game1_BackGround(time);

		for (int i = 0; i < 5; i++)
		{
			g_aniSprite[i].OnUpdate(time);
			g_aniSprite[i].level_Change_time(time);		//난이도 조절 : 시간별로 올라가기 , 너무 빨라지지 않도록 막음 
		}
	
		g_Eye.OnUpdate(time);

		Gametime_Manger.GameTime(time); //시간 매니저

		SetRect(&TimeRect, 10, 10, 0, 0);

		itoa(Gametime_Manger.g_time, c_game, 10);

		g_pd3dxFont->DrawText(NULL, c_game, -1, &TimeRect, DT_NOCLIP,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));


		SetRect(&destRect2, 320, 10, 0, 0);

	
		SetRect(&destRect1, 370, 10, 0, 0);

		g_pd3dxFont->DrawText(NULL, "/10 마리 ", -1, &destRect1, DT_NOCLIP,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		g_pd3dxFont->DrawText(NULL, c_count, -1, &destRect2, DT_NOCLIP,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		if (Gametime_Manger.Game_over || g_Eye.GameScore <0) //게임 종료 조건
			State = EState::NextGameOver;

		if (g_Eye.GameScore == WIN_GAME_1_SCORE)
			State = EState::GameWin;

		break;
	case EState::GameWin:
		g_Main.Set_BackGroung_Index((int)EState::GameWin);
		g_Main.OnUpdate(time);
		break;
	case EState::GameOver:
		g_Main.Set_BackGroung_Index((int)EState::GameOver);
		g_Main.OnUpdate(time);
		break;
	case EState::NextGameOver:
		g_Main.Set_BackGroung_Index((int)EState::NextGameOver);
		g_Main.OnUpdate(time);
		g_UI.ReGame_Draw();

		Gametime_Manger.setGameTime(GAME_2_GAMETIME);
		Reset();
		break;
	case EState::SubGame:
		//이미지
		g_Main.Set_BackGroung_Index((int)EState::SubGame);
		g_Main.OnUpdate(time);
		for(int i=0; i<3 ; i++)
		g_work[i].OnUpdate(time);
		g_Suzi.OnUpdate(time);

		Gametime_Manger.GameTime(time); //시간 매니저

		for (int i = 0; i<3; i++)
		if (MyRect::RectCollision(g_Suzi.m_rcCollision, g_work[i].m_rcCollision))
		{
			g_Eye.GameScore += 1;
			itoa(g_Eye.GameScore, c_count, 10);
			g_work[i].reset(time);
		}

		//폰트
		SetRect(&TimeRect, 55, 50, 0, 0);
		itoa(Gametime_Manger.g_time, c_game, 10);
		g_pd3dxFont->DrawText(NULL, c_game, -1, &TimeRect, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
		SetRect(&destRect2, 330, 10, 0, 0);
		SetRect(&destRect1, 360, 10, 0, 0);
		g_pd3dxFont->DrawText(NULL, "개 완료 ", -1, &destRect1, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
		g_pd3dxFont->DrawText(NULL, c_count, -1, &destRect2, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));


		//게임 상태
		if (Gametime_Manger.Game_over) //게임 종료 조건
			State = EState::GameOver;

		if (g_Eye.GameScore == WIN_GAME_2_SCORE)
			State = EState::GameWin;

		break;
	default:
		break;
	}
}

//마우스 값 
void MouseMove(POINT pt)
{
	switch (State)
	{
	case EState::Intro:
		g_UI.CheckMouseMove(pt);
		break;
	case EState::GameSelect:
		g_UI.CheckMouseMove(pt);
		break;
	case EState::GameLoding:
		break;
	case EState::Game:
		g_Eye.CheckMouseMove(pt);
		break;
	case EState::GameWin:
		break;
	case EState::GameOver:
		break;
	case EState::NextGameOver:
		g_UI.CheckMouseMove(pt);
		break;
	case EState::SubGame:
		g_Suzi.CheckMouseMove(pt);
		break;
	default:
		break;
	}

}
void MouseClick(POINT pt)
{
	switch (State)
	{
	case EState::Intro:
		if (g_UI.CheckMouseClick(pt) == UICleck::START)
			State = EState::GameLoding;
		if (g_UI.CheckMouseClick(pt) == UICleck::INTRO)
			State = EState::GameSelect;
		if (g_UI.CheckMouseClick(pt) == UICleck::EXIT)
				exit(0);
			
		break;
	case EState::GameSelect:
		if (g_UI.CheckMouseClick(pt) == UICleck::START)
			State = EState::GameLoding;
		if (g_UI.CheckMouseClick(pt) == UICleck::EXIT)
			State = EState::Intro;
		break;
	case EState::GameLoding:
		break;
	case EState::Game:
		for (int i = 0; i < 5; i++)
		{
			if (g_aniSprite[i].Mouse_Click == TRUE)
			{
				if (g_aniSprite[i].isCollision(pt) == TRUE)
				{
					g_Eye.GameScore += g_aniSprite[i].Score();
					itoa(g_Eye.GameScore, c_count, 10);
					g_aniSprite[i].ChangeFlyType(FLYTYPE::CATCH);
					
				}
			}
		}
		break;
	case EState::GameWin:
		g_Eye.GameScore = 0;
		State = EState::Intro;
		break;
	case EState::GameOver:
		g_Eye.GameScore = 0;
		State = EState::Intro;
		break;
	case EState::NextGameOver:
		if (g_UI.CheckMouseClick(pt) == UICleck::START)
			State = EState::SubGame;
		break;
	case EState::SubGame:

		break;
	default:
		break;
	}
}

void ImageCreate()
{
	for (int i = 0; i < 5; i++)
		g_aniSprite[i].Create(g_pd3dDevice, "Fairy.png", 398, 170);


	g_Main.Create(g_pd3dDevice, "background.png", 1000, 3200);
	g_UI.Create(g_pd3dDevice, "GameUI.png", 170, 254);
	g_Eye.Create(g_pd3dDevice, "Eye.png", 2000, 3200);
	g_Suzi.Create(g_pd3dDevice, "수지.png", 150, 150);

	for (int i = 0; i<3; i++)
	g_work[i].Create(g_pd3dDevice, "book.png", 120, 80);
}

//초기화
void Reset()
{
	Gametime_Manger.Game_over = false;
	g_Eye.GameScore = 0;
	itoa(g_Eye.GameScore, c_count, 10);
	for (int i = 0; i < 5; i++)
		g_aniSprite[i].reset();

	g_work[0].m_Pos.x = 250; g_work[0].m_Pos.y = 450;
	g_work[1].m_Pos.x = 100; g_work[1].m_Pos.y = 100;
	g_work[2].m_Pos.x = 300; g_work[2].m_Pos.y = -100;
}
