#include "EffectManager.h"

#include	"EffectManager.h"

/**
 * コンストラクタ
 *
 */
CEffectMgmt::CEffectMgmt() {
}

/**
 * デストラクタ
 *
 */
CEffectMgmt::~CEffectMgmt() {
}

/**
 * 読み込み
 * 利用するテクスチャを読み込む。
 */
bool CEffectMgmt::Load(void) {
	//テクスチャの読み込み
	char* name[] = {
		"エフェクト仮.png"
	};

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Effect");


	for (int i = 0; i < EFC_TYPE_COUNT; i++)
	{
		if (!m_Texture[i].Load(name[i]))
		{
			return false;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

/**
 * 初期化
 * パラメーターや座標を初期化する。
 */
void CEffectMgmt::Initialize(void) {
	//エフェクトの基礎設定
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
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
CEffect* CEffectMgmt::Start(float px, float py, tag_EFFECTTYPE type) {
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
void CEffectMgmt::Update(CRectangle plrec) {
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
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
void CEffectMgmt::Render(void) {
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Render();
		}
	}
}

//デバッグ表示
void CEffectMgmt::RenderDebugging(void)
{
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
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
void CEffectMgmt::Release(void) {
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Release();
		}
		m_Texture[type].Release();
	}
}
