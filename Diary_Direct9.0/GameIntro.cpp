#include "GameIntro.h"



GameIntro::GameIntro()
{
	Game_Backgroung_Index = 0;
	m_interval = 0;
}


GameIntro::~GameIntro()
{
}

void GameIntro::Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height)
{
	CMySprite::Create(pDevice, filename, width, height);
	SetRect(&m_Background[0], 500, 0, 1000, 800); //인터페이스
	SetRect(&m_Background[1], 500, 800, 1000,1600);
	SetRect(&m_Background[2], 0, 1600, 500, 2400); //인 게임 배경 1
	SetRect(&m_Background[3], 500, 1600, 1000, 2400);//인 게임 배경 2
	SetRect(&m_Background[5], 0, 0, 500, 800); //게임 아웃 
	SetRect(&m_Background[4], 0, 800, 500, 1600); //게임 성공
	SetRect(&m_Background[6], 0, 2400, 500, 3200); //다음 게임
	SetRect(&m_Background[7], 500, 2400, 1000, 3200); //서브 게임
}
void GameIntro::OnDraw()
{

	D3DXVECTOR3 vCenter(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition(0.0f, 0.0f, 0.0f);

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	m_pSprite->Draw(m_pTexture,
		&m_Background[Game_Backgroung_Index],
		&vCenter,
		&vPosition,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->End();
}
void GameIntro::OnUpdate(float time)
{
	OnDraw();
}

void GameIntro::Set_BackGroung_Index(int x)
{
	Game_Backgroung_Index = x;
}

void GameIntro::Game1_BackGround(float time)
{
	m_interval += time;
	if (m_interval > 0.1f)
	{
		Game_Backgroung_Index++;
		if (Game_Backgroung_Index > 3) Game_Backgroung_Index = 2;

		m_interval = 0.0f;
	}
}