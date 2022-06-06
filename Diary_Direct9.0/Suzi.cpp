#include "Suzi.h"



Suzi::Suzi()
{
	p_Eye.x = 250;
	p_Eye.y = 450;

	m_yPos = 630;
}


Suzi::~Suzi()
{
}

void Suzi::Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height)
{
	CMySprite::Create(pDevice, filename, width, height);

	SetRect(&m_Suzi, 0, 0, 150, 150);
}
void Suzi::OnDraw()
{
	m_rcCollision.left = (int)p_Eye.x;
	m_rcCollision.top = (int)m_yPos;
	m_rcCollision.right = m_rcCollision.left + 150;
	m_rcCollision.bottom = m_rcCollision.top + 150;

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 vCenter(75.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition(p_Eye.x, m_yPos, 0.0f);

	m_pSprite->Draw(m_pTexture,
		&m_Suzi,
		&vCenter,
		&vPosition,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->End();
}
void Suzi::OnUpdate(float time)
{
	OnDraw();
}

void Suzi::CheckMouseMove(POINT pt)
{
	p_Eye = pt;
}