#include "Fairy.h"
#include <time.h>



Fairy::Fairy()
{
	m_nFrame = 0;
	m_interval = 0.0f;

	m_xPos = 400.0f;
	m_yPos = 300.0f;
	m_moveInterval = 0.0f;
	m_moveDuration = 2.0f;

	m_flyType = FLYTYPE::FLY;
	Mouse_Click = TRUE;

	m_fairyType = (TYPE)(rand() % 2);
	Plus_Score = 0;
	srand(time(NULL));
}


Fairy::~Fairy()
{
}

void Fairy::Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height)
{
	CMySprite::Create(pDevice, filename,width,height);

	SetRect(&Good_Fairy[0], 0, 0, 132, 85);
	SetRect(&Good_Fairy[1], 132, 0, 264, 85);
	SetRect(&Good_Fairy[2], 264, 0, 398, 85);

	SetRect(&Bad_Fairy[0], 0, 85, 132, 170);
	SetRect(&Bad_Fairy[1], 132, 85, 264, 170);
	SetRect(&Bad_Fairy[2], 264, 85, 398, 170);

}

void Fairy::OnDraw()
{
	RECT srcRect = Good_Fairy[m_nFrame];
	srcRect.bottom = srcRect.top + Good_Fairy[m_nFrame].bottom;
	srcRect.right = srcRect.left + Good_Fairy[m_nFrame].right;

	D3DXVECTOR3 vCenter(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vPosition(m_xPos, m_yPos, 0.0f);

	m_rcCollision.left = (int)m_xPos;
	m_rcCollision.top = (int)m_yPos;
	m_rcCollision.right = m_rcCollision.left + Good_Fairy[m_nFrame].right;
	m_rcCollision.bottom = m_rcCollision.top + Good_Fairy[m_nFrame].bottom;

	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	switch (m_fairyType)
	{
	case GOOD:

		Plus_Score = 1;

		m_pSprite->Draw(m_pTexture,
			&Good_Fairy[m_nFrame],
			&vCenter,
			&vPosition,
			D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));
		break;
	case BAD:

		Plus_Score = -1;

		m_pSprite->Draw(m_pTexture,
			&Bad_Fairy[m_nFrame],
			&vCenter,
			&vPosition,
			D3DCOLOR_COLORVALUE(1.0f, 1.0f, 1.0f, 1.0f));
		break;
	default:
		break;
	}
	

	m_pSprite->End();
}

void Fairy::OnUpdate(float time)
{

	if (m_flyType == FLYTYPE::FLY)
	{
		m_interval += time;
		if (m_interval > 0.1f)
		{
			m_nFrame++;
			if (m_nFrame > 1) m_nFrame = 0;

			m_interval = 0.0f;
		}
	
		m_moveInterval += time;
		if (m_moveInterval >= m_moveDuration)
		{
			m_moveInterval = 0.0f;
			m_xPos = (float)(rand() % 400);
			m_yPos = (float)(rand() % 700);
			m_fairyType = (TYPE)(rand() % 2);
		}
	}
	else
	{
		m_nFrame = 2;
		Mouse_Click = FALSE;

		m_moveInterval += time;
		if (m_moveInterval >= 1.5f)
		{
			ChangeFlyType(FLYTYPE::FLY);
			Mouse_Click = TRUE;
			FairyReset();
			m_moveInterval = 0.0f;
		}
	}

	OnDraw();
}

BOOL Fairy::isCollision(POINT pt) //충돌 검사
{
	return ::PtInRect(&m_rcCollision, pt);

}



void Fairy::ChangeFlyType(FLYTYPE type)
{
	if (m_flyType == type)
		return;

	m_flyType = type;
}



void Fairy::level_Change_count(int count)
{

	switch (count)
	{
	case 2:
		m_moveDuration = 1.5f;
		break;
	case 4:
		m_moveDuration = 1.0f;
		break;
	case 6:
		m_moveDuration = 0.5f;
		break;
	default:
		break;
	}

}

void Fairy::level_Change_time(float time)
{
	Game_time += time;
	if (m_moveDuration>=0.8f && Game_time>=2.0f)
	{
		m_moveDuration -= 0.1;
		Game_time = 0;
	}

}

int Fairy::Score()
{
	return Plus_Score;
}

void Fairy::FairyReset()
{
	m_xPos = (float)(rand() % 400);
	m_yPos = (float)(rand() % 700);
	m_fairyType = (TYPE)(rand() % 2);
}


void Fairy::reset()
{
	m_moveDuration = 2.0f;
}