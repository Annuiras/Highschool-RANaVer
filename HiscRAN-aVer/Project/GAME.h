//////////////////////////////////////////////
//	ゲーム管理のプログラムです　　　　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "Define_Music.h"
#include "Define_Menu.h"
#include "Player.h"
#include "Stage.h"



class CGAME :public CSceneBase
{

private:

	//DPと接触処理
	void UPdeteCollisionDP(int dpt);

	//プレイヤークラス
	CPlayer g_Player;

	//ステージクラス
	CStage g_Stage;

	//ステージ内で取得したDPの数
	int m_DPNum[DP_COUNT];

	//SPステージ中で取得したDPの数
	int m_SP_DPNum;


	//ゲーム開始時のカウントダウンテクスチャ　仮素材
	CTexture	m_StartThreeTexture;
	CTexture	m_StartTwoTexture;
	CTexture	m_StartOneTexture;
	CTexture	m_StartGoTexture;
	
	//ゲームクリア時のテキストテクスチャ
	CTexture   m_ClearTexture;
	//クリア用表示倍率
	float m_ClearScale;


	//ゲーム開始時のカウントダウン
	DWORD	m_StartTime;
	int m_StartCount = 0;
	//カウントダウン時のズーム倍率
	float m_StartScale;

	//DP目標設定画面で選んだDP番号
	int m_DPDeci;

	//フェード用アルファ値
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	//ゲームオーバーフラグ
	bool m_GameOverflg;
	//クリアフラグ
	bool m_GameClearflg;

	//ヒットストップの変数追加
	float			m_StopCount;
	bool			m_Stopflg;


public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void UpdateDebug(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);
};

