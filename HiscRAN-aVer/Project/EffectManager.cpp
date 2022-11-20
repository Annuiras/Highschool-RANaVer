#include "EffectManager.h"

#include	"EffectManager.h"

/**
 * コンストラクタ
 *
 */
CEffectManager::CEffectManager() {
}

/**
 * デストラクタ
 *
 */
CEffectManager::~CEffectManager() {
}

/**
 * 読み込み
 * 利用するテクスチャを読み込む。
 */
bool CEffectManager::Load(void) {
	//テクスチャの読み込み
	char* name[] = {
		"エフェクト仮.png"
	};


	for (int i = 0; i < EFC_TYPECOUNT; i++)
	{
		if (!m_Texture[i].Load(name[i]))
		{
			return false;
		}
	}
	return true;
}

/**
 * 初期化
 * パラメーターや座標を初期化する。
 */
void CEffectManager::Initialize(void) {
	//エフェクトの基礎設定
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].SetTexture(&m_Texture[type]);
			m_Effect[type][mgmt].Initialize(type);
		}
	}
}

/**
 * 開始
 * 座標を設定してモーションを開始する。
 *
 * 引数
 * [in]			px					X座標
 * [in]			py					Y座標
 * [in]			mgmt				エフェクトタイプ
 */
CEffect* CEffectManager::Start(float px, float py, int type) {
	for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
	{
		if (m_Effect[type][mgmt].GetShow())
		{
			continue;
		}
		m_Effect[type][mgmt].Start(px, py);
		return &m_Effect[type][mgmt];
	}
	return NULL;
}

/**
 * 更新
 *
 */
void CEffectManager::Update(CRectangle plrec) {
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			switch (type)
			{

			case EFC_GET_DP:
				m_Effect[type][mgmt].Update(plrec);

				break;
			default:
				break;
			}
		}
	}
}

/**
 * 描画
 *
 */
void CEffectManager::Render(void) {
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Render();
		}
	}
}

//デバッグ表示
void CEffectManager::RenderDebugging(void)
{
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].RenderDebugging();
		}
	}

}

/**
 * 解放
 *
 */
void CEffectManager::Release(void) {
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Release();
		}
		m_Texture[type].Release();
	}
}
