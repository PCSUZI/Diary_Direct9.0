#include "Study.h"



Study::Study()
{
	m_Pos.x = 250;
	m_Pos.y = 450;


	is_Draw = true;
}


Study::~Study()
{
}

void Study::Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height)
{
	CMySprite::Create(pDevice, filename, width, height);

	SetRect(&m_object, 0, 0, 120, 80);
}
void Study::OnDraw()
{
	m_rcCollision.left = (int)m_Pos.x;
	m_rcCollision.top = (int)m_Pos.y;
	m_rcCollision.right = m_rcCollision.left + 120;
	m_rcCollision.bottom = m_rcCollision.top + 80;

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 vCenter(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition(m_Pos.x, m_Pos.y, 0.0f);

	if (is_Draw == true)
	{
		m_pSprite->Draw(m_pTexture,
			&m_object,
			&vCenter,
			&vPosition,
			D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));
	}
	m_pSprite->End();
}
void Study::OnUpdate(float time)
{
	OnDraw();
	move(time);

	if (m_Pos.y == 800)
		reset(time);
}

void Study::Loding()
{
	is_Draw = true;

	m_Pos.x = (rand() % 440);
	m_Pos.y = 200;
}
void Study::reset(float tick)
{
	m_Pos.x = (rand() % 440);

	is_Draw = true;

	m_Pos.y = -200;
}
void Study::move(float time)
{
	m_interval += time;
	if (m_interval > 0.001f)
	{
		m_Pos.y += 1;

		m_interval = 0.0f;
	}
}