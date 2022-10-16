#pragma once
#include	"Mof.h"
#include	"Player.h"

class CPlayerSkill
{
private:

	//todo�����ŐV�����v���C���[�Q����ĂȂ��H
	CPlayer		gPlayer;

	//���W
	float m_PosX;
	float m_PosY;
	//�Ռ��g����
	int m_CircleWait;

public:
	CPlayerSkill();
	~CPlayerSkill();
	void Initialize(void);

	void Update(void);
	void Render(void);
	void RenderDebug(void);

	//�Ռ��g�����蔻��
	CRectangle m_CircleRect() {
		return CRectangle(gPlayer.CircleX(), gPlayer.CircleY() + 350,
			gPlayer.CircleX() + 250, gPlayer.CircleY() + 650);
	}
};