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

bool CEnemy::Load()
{
	////仮置き
	//float Encoma = 2;
	////アニメーション
	//SpriteAnimationCreate EneAnim[] =
	//{
	//	{
	//		"移動",
	//		0, 320,
	//		160, 485,
	//		TRUE,{ {Encoma,0,0},{Encoma,1,0},{Encoma,2,0},{Encoma,3,0},{Encoma,4,0},{Encoma,5,0},{Encoma,6,0},{Encoma,7,0},{Encoma,8,0},{Encoma,9,0},{Encoma,10,0}
	//		,{Encoma,11,0},{Encoma,12,0},{Encoma,13,0},{Encoma,14,0},{Encoma,15,0},{Encoma,16,0} }

	//	},
	//};
	//m_Motion.Create(EneAnim, MOTION_COUNT);
	return true;
}

void CEnemy::Initialize()
{
	ene_PosX = 0;
	ene_PosY = 0;
	ene_Type = 0;
	ene_Show = false;
}

void CEnemy::Start(float posy, int type)
{
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
	float r = m_SrcRect.Right;
	m_SrcRect.Right = m_SrcRect.Left;
	m_SrcRect.Left = r;

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
	CGraphicsUtilities::RenderRect(GetRect(ene_Type), MOF_COLOR_RED);
}

CRectangle CEnemy::GetRect(int type)
{
	//タイプ別で大きさを変更
	switch (type)
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

void CEnemy::Release()
{
	ene_Texture->Release();
}