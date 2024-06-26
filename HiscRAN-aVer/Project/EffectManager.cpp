//////////////////////////////////////////////
//	エフェクトマネージャーのプログラムです　//
//									　　　　//
//　作成者：田中 環、仲田 匠吾		　　　　//
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#include "EffectManager.h"

/**
 * コンストラクタ
 *
 */
CEffectMgmt::CEffectMgmt():
	m_Effect(),
	m_Texture()
{
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
tag_LoadSituation CEffectMgmt::Load(void) {

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Effect");

	//テクスチャの読み込み
	char* name[] = {
		"Scholastic_UP.png",
		"Action_UP.png",
		"Imagination_UP.png",
		"Communication_UP.png",
		"Charm_UP.png",

		"Scholastic_UP_Arrow.png",
		"Action_UP_Arrow.png",
		"Imagination_UP_Arrow.png",
		"Communication_UP_Arrow.png",
		"Charm_UP_Arrow.png",

		"Sweat_Motion.png",

	};

	for (int i = 0; i < EFC_TYPE_COUNT; i++)
	{
		if (!m_Texture[i].Load(name[i]))
		{
			return LOAD_ERROR;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return LOAD_COMP;
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

//画面推移時の初期化命令
void CEffectMgmt::InitializeIn_middle(void)
{
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].InitializeIn_middle();
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
 * [in]			type				エフェクトタイプ
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
			//非表示の場合無視
			if (!m_Effect[type][mgmt].GetShow()) {
				continue;
			}
			switch (type)
			{
				//各DPの場合
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
				m_Effect[type][mgmt].UpdateDP(plrec);
				break;

				case EFC_DAMAGE_HIT:
					m_Effect[type][mgmt].UpdateDP(plrec);
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
