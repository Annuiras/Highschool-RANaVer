#include "Effect.h"
//制作者：田中 環、仲田 匠吾

/**
 * コンストラクタ
 *
 */
CEffect::CEffect() :
	m_pTexture(NULL),
	m_Motion(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_bShow(false),
	m_SrcRect() {
}

/**
 * デストラクタ
 *
 */
CEffect::~CEffect() {
}

/**
 * 開始
 * パラメーターや座標を初期化する。
 *
 * 引数
 * [in]			type				タイプ
 */
void CEffect::Initialize(int type) {
	m_PosX = 0.0f;
	m_PosY = 0.0f;
	m_bShow = false;

	float DP_coma = 2.8;

	switch (type)
	{
		//各DP
		case EFC_GET_SCHOLASTIC:		
		case EFC_GET_ACTION:
		case EFC_GET_IMAGINATION:
		case EFC_GET_COMMUNICATION:
		case EFC_GET_CHARM:

		case EFC_GET_SCHOLASTIC_AROOW:
		case EFC_GET_ACTION_AROOW:
		case EFC_GET_IMAGINATION_AROOW:
		case EFC_GET_COMMUNICATION_AROOW:
		case EFC_GET_CHARM_AROOW:
		{
			//アニメーションを作成
			SpriteAnimationCreate anim[] = {

				//DP取得エフェクト
				{
					"エフェクト",
					0,0,
					200,200,
					FALSE,{{DP_coma,0,0},{DP_coma,1,0},{DP_coma,2,0},{DP_coma,3,0},{DP_coma,4,0},{DP_coma,0,1},{DP_coma,1,1},{DP_coma,2,1},{DP_coma,3,1},{DP_coma,4,1},{DP_coma,0,2},{DP_coma,1,2},}
				},
			};
			m_Motion.Create(anim, 1);
			break;
		}
	}
}

//画面推移時の初期化
void CEffect::InitializeIn_middle(void)
{
	m_PosX = 0.0f;
	m_PosY = 0.0f;
	m_bShow = false;
}

/**
 * 開始
 * 座標を設定してモーションを開始する。
 *
 * 引数
 * [in]			px					X座標
 * [in]			py					Y座標
 */
void CEffect::Start(float px, float py) {
	m_SrcRect = m_Motion.GetSrcRect();
	m_PosX = px;
	m_PosY = py;
	m_bShow = true;
	m_Motion.ChangeMotion(0);
}

/**
 * 更新
 *
 */
void CEffect::UpdateDP(CRectangle plrec) {

	m_PosX = plrec.Left-80;
	m_PosY = plrec.Top;

	//アニメーションの更新
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
	//アニメーションの終了で非表示にする
	if (m_Motion.IsEndMotion())
	{
		m_bShow = false;
	}
}

/**
 * 描画
 *
 */
void CEffect::Render() {
	//非表示
	if (!m_bShow)
	{
		return;
	}
	//テクスチャの描画
	m_pTexture->Render(m_PosX, m_PosY, m_SrcRect);
}

//デバッグ表示
void CEffect::RenderDebugging(void)
{
	if (!m_bShow)
	{
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_HGREEN);
}


/**
 * 解放
 *
 */
void CEffect::Release(void) {
	m_Motion.Release();
}

CRectangle CEffect::GetRect(void)
{
	
	return CRectangle(m_PosX, m_PosY,
		m_PosX + 200, m_PosY + 200);
	
}

