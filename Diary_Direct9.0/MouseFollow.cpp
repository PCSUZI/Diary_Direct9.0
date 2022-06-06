#include "MouseFollow.h"



MouseFollow::MouseFollow()
{
	p_Eye.x = 250;
	p_Eye.y = 450;
	Eye_index = 0;
	GameScore = 0;
}


MouseFollow::~MouseFollow()
{
}

void MouseFollow::Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height)
{
	CMySprite::Create(pDevice, filename, width, height);

	SetRect(&m_BlackGround[0], 0, 0, 1000, 1600);
	SetRect(&m_BlackGround[1], 1000, 0, 2000, 1600);
	SetRect(&m_BlackGround[2], 0, 1600, 1000, 3200);
	SetRect(&m_BlackGround[3], 1000, 1600, 2000, 3200);
	SetRect(&m_BlackGround[6], 0, 0, 1000, 1600);
	SetRect(&m_BlackGround[5], 1000, 0, 2000, 1600);
	SetRect(&m_BlackGround[4], 0, 1600, 1000, 3200);
}
void MouseFollow::OnDraw()
{

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	D3DXVECTOR3 vCenter(500.0f, 750.0f, 0.0f);
	D3DXVECTOR3 vPosition(p_Eye.x, p_Eye.y, 0.0f);

	m_pSprite->Draw(m_pTexture,
		&m_BlackGround[Eye_index],
		&vCenter,
		&vPosition,
		D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));

	m_pSprite->End();

}
void MouseFollow::OnUpdate(float time)
{
	m_interval += time;
	if (m_interval > 0.1f)
	{
		Eye_index++;
		if (Eye_index > 6) Eye_index = 0;

		m_interval = 0.0f;
	}
	OnDraw();
}

void MouseFollow::CheckMouseMove(POINT pt)
{
	p_Eye = pt;
}
