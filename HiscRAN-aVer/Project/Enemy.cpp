#include "Enemy.h"

//////////////////////////////////////////////
//	敵のプログラムです			　　　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

CEnemy::CEnemy() :
	m_PosX(0),
	m_PosY(0),
	m_MoveY(),
	m_Texture(),
	m_Motion(),
	m_Show(false) {
}

CEnemy::~CEnemy()
{
}

//テクスチャをセット
void CEnemy::SetTexture(CTexture* enetex) {

	m_Texture = enetex;

}

//アニメーションをセット
void CEnemy::SetAnime(CSpriteMotionController* eneanim)
{
	m_Motion = eneanim;
}

//初期化
void CEnemy::Initialize()
{
	m_PosX = 0;
	m_PosY = 0;
	m_MoveY = 0;
	m_Show = false;
}

//生成
void CEnemy::Start(float posy, int type)
{
	//画面右端に生成
	m_PosX = g_pGraphics->GetTargetWidth();

	m_PosY = posy;

	m_Show = true;

}

//scroll:ステージスクロール値
void CEnemy::Update(float scroll)
{
	//敵が画面上にいる時、動く
	if (!m_Show)
		return;
	
	//移動モーション
	if (m_Motion->GetMotionNo() != MOTION_MOVE) {
		m_Motion->ChangeMotion(MOTION_MOVE);
	}

	//敵を左に進ませる
	m_PosX -= scroll * 1.5;

	//アニメーション再生
	m_Motion->AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion->GetSrcRect();

	//敵を反転させる
	float r = m_SrcRect.Right;
	m_SrcRect.Right = m_SrcRect.Left;
	m_SrcRect.Left = r;

	//重力反映
	m_MoveY += GRAVITY;

	//下降速度クリップ追加
	if (m_MoveY >= 10) {
		m_MoveY = 10 - 0.1f;
	}

	//スピード反映
	m_PosY += m_MoveY;

	//地面よりも下か？
	if (m_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {
		//地面よりも下に行かないように調整
		SetPosY(GROUND_Y);
	}

	//画面左端で消去
	if (m_PosX + ENEMY_SIZE_WIDTH < 0) {
		m_Show = false;
	}

}

void CEnemy::Render()
{
	if (!m_Show) {
		return;
	}

	m_Texture->Render(m_PosX, m_PosY, m_SrcRect);
}

void CEnemy::RenderDebug()
{
	if (!m_Show) {
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
}

CRectangle CEnemy::GetRect(void)
{
	return CRectangle(m_PosX, m_PosY,
		m_PosX + ENEMY_SIZE_WIDTH, m_PosY + ENEMY_SIZE_HEIGHT);
}

//Y座標を調整
//y:調整するＹ座標
void CEnemy::SetPosY(float y)
{
	m_PosY = y - ENEMY_SIZE_HEIGHT;
	m_MoveY = 0;
}

void CEnemy::Release()
{
	m_Texture->Release();
}