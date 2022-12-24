#pragma once
#include "MusicManager.h"
#include "EffectManager.h"
#include "Define.h"

//ゲーム画面中のリザルトクラス
class CResult
{
private:

	//中間結果位置
	float m_PosX_Bak;
	float m_PosY_Bak;

	//フェード状況を記録
	tag_SceneSituation m_FadeSitu;

	//表示フラグ
	//true:表示中
	bool m_Show;

	//リザルト終了フラグ
	//true:終了
	bool m_Endflg;

	//初期化済フラグ
	bool m_Initializeflg;

	//中間結果背景
	CTexture m_Bak_MiddleResult;

	//3年時結果背景
	CTexture m_Bak_LastResult;

	//SE・BGMマネージャー
	CMusicMgmt* m_MusicMgmt;

	//エフェクトマネージャー
	CEffectMgmt* m_pEffectMgmt;


public:

	CResult();
	~CResult();

	//素材ロード
	bool Load(void);

	//初期化
	void Initialize(void);

	//表示開始
	void Start(void);

	//更新
	void Update(void);

	//中間報告描画
	void RenderMiddleResult(void);

	//最終報告描画
	void RenderLastResult(void);

	//デバッグ表示
	void RenderDebugging(void);

	//解放
	void Release(void);

	//SE・BGMマネージャーセット
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//エフェクトマネージャーセット
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }

	//表示中フラグ
	bool GetShow(void) { return m_Show; }

	//終了フラグを渡す
	bool GetEndflg(void) { return m_Endflg; }
};

