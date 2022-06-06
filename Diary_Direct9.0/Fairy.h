#pragma once

#include "MySprite.h"

enum FLYTYPE
{
	FLY=0,
	CATCH=1
};

enum TYPE
{
	GOOD = 0,
	BAD = 1
};

class Fairy : public CMySprite
{
protected:
	RECT Good_Fairy[3];
	RECT Bad_Fairy[3];
	unsigned short m_nFrame;


	float m_interval;

	float m_xPos;
	float m_yPos;
	float m_moveInterval;
	float m_moveDuration;

	TYPE m_fairyType;
	FLYTYPE m_flyType;

	int Plus_Score;

public:
	Fairy();
	virtual ~Fairy();

	void Create(LPDIRECT3DDEVICE9 pDevice, char *filename, int width, int height);
	void OnDraw();
	void OnUpdate(float time);

	BOOL isCollision(POINT pt);
	RECT  m_rcCollision;

	void ChangeFlyType(FLYTYPE type);

	//���̵� ����_ ������
	void level_Change_count(int count);
	//���̵� ����_ �ð���
	float Game_time;
	void level_Change_time(float time);

	//������ �׾��ִ� ������ Ŭ�� ���ϰ� 
	BOOL Mouse_Click;

	void FairyReset();
	int Score();
	void reset();


};

