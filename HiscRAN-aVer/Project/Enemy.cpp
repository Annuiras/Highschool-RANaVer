#include "Enemy.h"

//todo 敵

CEnemy::CEnemy() :
	ene_PosX(0),
	ene_PosY(0),
	ene_Show(false) {
}

CEnemy::~CEnemy()
{
}

//テクスチャをセット
void CEnemy::SetTexture(CTexture* enetex) {

	ene_Texture = enetex;

}

void CEnemy::SetAnime(CSpriteMotionController* eneanim)
{

	m_Motion = eneanim;
}

void CEnemy::Initialize()
{
	ene_PosX = 0;
	ene_PosY = 0;
	ene_SpeedY = 0;
	ene_Type = 0;
	ene_Show = false;
}

void CEnemy::Start(float posy, int type)
{
	//画面右端に生成
	ene_PosX = g_pGraphics->GetTargetWidth();

	ene_PosY = posy;

	ene_Type = type;

	ene_Show = true;

}

void CEnemy::Update(float over)
{
	//todo 敵が画面上にいる時、動く
	if (!ene_Show)
		return;
	
	if (m_Motion->GetMotionNo() != MOTION_MOVE) {
		m_Motion->ChangeMotion(MOTION_MOVE);
	}
	ene_PosX -= over * 1.5;		//*1.5は速さの値です

	//アニメーション再生
	m_Motion->AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion->GetSrcRect();

	//敵を反転させる
	float r = m_SrcRect.Right;
	m_SrcRect.Right = m_SrcRect.Left;
	m_SrcRect.Left = r;

	//重力反映
	ene_SpeedY += GRAVITY;

	//下降速度クリップ追加
	if (ene_SpeedY >= 10) {
		ene_SpeedY = 10 - 0.1f;
	}

	//スピード反映
	ene_PosY += ene_SpeedY;

	//地面よりも下か？
	if (ene_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {
		//地面よりも下に行かないように調整
		SetPosY(GROUND_Y);
	}

	//画面左端で消去
	if (ene_PosX + ENEMY_SIZE_WIDTH < 0) {
		ene_Show = false;
	}

}

void CEnemy::Render()
{
	if (!ene_Show) {
		return;
	}


	ene_Texture->Render(ene_PosX, ene_PosY, m_SrcRect);
}

void CEnemy::RenderDebug()
{
	if (!ene_Show) {
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
}

CRectangle CEnemy::GetRect(void)
{
	//タイプ別で大きさを変更
	switch (ene_Type)
	{
	case ENEMY_1://敵1		
		return CRectangle(ene_PosX, ene_PosY,
			ene_PosX + ENEMY_SIZE_WIDTH, ene_PosY + ENEMY_SIZE_HEIGHT);
		break;

	default:
		//エラーの場合
		return CRectangle(ene_PosX, ene_PosY,
			ene_PosX + ENEMY_SIZE_WIDTH, ene_PosY + ENEMY_SIZE_HEIGHT);
		break;
	}
}

void CEnemy::SetPosY(float y)
{
	ene_PosY = y - ENEMY_SIZE_HEIGHT;
	ene_SpeedY = 0;
}

void CEnemy::Release()
{
	ene_Texture->Release();
}