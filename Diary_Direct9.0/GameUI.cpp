#include "GameUI.h"
#include "MyRect.h"


GameUI::GameUI()
{
	m_start_Index = 0;
	m_Intro_Index = 0;
	m_Exit_Index = 0;

	p_start.x = 170;
	p_start.y = 450;

	p_Intro.x = 170;
	p_Intro.y = 530;

	p_Exit.x = 170;
	p_Exit.y = 620;

}


GameUI::~GameUI()
{
}

void GameUI::Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height)
{
	CMySprite::Create(pDevice, filename, width, height);

	SetRect(&m_start[0], 0, 42, 170, 84);
	SetRect(&m_start[1], 0, 0, 170, 42);

	SetRect(&m_Intro[1], 0, 85, 170, 130);
	SetRect(&m_Intro[0], 0, 130, 170, 180);

	SetRect(&m_Exit[1], 0, 180, 170, 222);
	SetRect(&m_Exit[0], 0, 222, 170, 254);

}
void GameUI::Intro_Draw()
{
	p_start.x = 170;
	p_start.y = 450;

	p_Intro.x = 170;
	p_Intro.y = 530;

	p_Exit.x = 170;
	p_Exit.y = 620;

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 vCenter_start(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_start(p_start.x, p_start.y, 0.0f);

	D3DXVECTOR3 vCenter_intro(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_intro(p_Intro.x, p_Intro.y, 0.0f);

	D3DXVECTOR3 vCenter_Exit(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_Exit(p_Exit.x, p_Exit.y, 0.0f);

	m_pSprite->Draw(m_pTexture,
		&m_start[m_start_Index],
		&vCenter_start,
		&vPosition_start,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->Draw(m_pTexture,
		&m_Intro[m_Intro_Index],
		&vCenter_intro,
		&vPosition_intro,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->Draw(m_pTexture,
		&m_Exit[m_Exit_Index],
		&vCenter_Exit,
		&vPosition_Exit,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->End();
}
void GameUI::OnUpdate(float time)
{

}
UICleck GameUI::CheckMouseClick(POINT pt) //마우스 클릭시 들어옴
{
	if (MyRect::Collision(pt.x, pt.y, p_start.x, p_start.y, 170, 42))
		return UICleck::START;


	if (MyRect::Collision(pt.x, pt.y, p_Intro.x, p_Intro.y, 170, 42))
		return UICleck::INTRO;

	if (MyRect::Collision(pt.x, pt.y, p_Exit.x, p_Exit.y, 170, 42))
		return UICleck::EXIT;

}
void GameUI::CheckMouseMove(POINT pt) //마우스 이동 시 들어옴
{
	if (MyRect::Collision(pt.x, pt.y, p_start.x, p_start.y, 170, 42))
		m_start_Index = 1;
	else
		m_start_Index = 0;

	if (MyRect::Collision(pt.x, pt.y, p_Intro.x, p_Intro.y, 170, 42))
		m_Intro_Index = 1;
	else
		m_Intro_Index = 0;

	if (MyRect::Collision(pt.x, pt.y, p_Exit.x, p_Exit.y, 170, 42))
		m_Exit_Index = 1;
	else
		m_Exit_Index = 0;

}


void GameUI::Select_Draw()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	p_start.x = 300;
	p_start.y = 700;

	p_Exit.x = -10;
	p_Exit.y = 710;

	D3DXVECTOR3 vCenter_start(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_start(p_start.x, p_start.y, 0.0f);

	D3DXVECTOR3 vCenter_Exit(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_Exit(p_Exit.x, p_Exit.y, 0.0f);

	m_pSprite->Draw(m_pTexture,
		&m_start[m_start_Index],
		&vCenter_start,
		&vPosition_start,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->Draw(m_pTexture,
		&m_Exit[m_Exit_Index],
		&vCenter_Exit,
		&vPosition_Exit,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->End();
}

void GameUI::ReGame_Draw()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	p_start.x = 150;
	p_start.y = 600;


	D3DXVECTOR3 vCenter_start(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_start(p_start.x, p_start.y, 0.0f);

	D3DXVECTOR3 vCenter_Exit(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition_Exit(p_Exit.x, p_Exit.y, 0.0f);

	m_pSprite->Draw(m_pTexture,
		&m_start[m_start_Index],
		&vCenter_start,
		&vPosition_start,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));



	m_pSprite->End();
}