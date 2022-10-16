#pragma once
#include	"Mof.h"
#include	"Player.h"

class CPlayerSkill
{
private:

	//todoここで新しいプレイヤー２作ってない？
	CPlayer		gPlayer;

	//座標
	float m_PosX;
	float m_PosY;
	//衝撃波時間
	int m_CircleWait;

public:
	CPlayerSkill();
	~CPlayerSkill();
	void Initialize(void);

	void Update(void);
	void Render(void);
	void RenderDebug(void);

	//衝撃波当たり判定
	CRectangle m_CircleRect() {
		return CRectangle(gPlayer.CircleX(), gPlayer.CircleY() + 350,
			gPlayer.CircleX() + 250, gPlayer.CircleY() + 650);
	}
};