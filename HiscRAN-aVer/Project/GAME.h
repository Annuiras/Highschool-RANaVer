#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "Define.h"
#include "Player.h"
#include "Stage.h"


class CGAME :public CSceneBase
{

private:
	

	//DPと接触処理
	void UPdeteCollisionDP(int dpt);

	//メニュークラス
	CMenu			m_Menu;
	int				m_MenuItemCount = 2;

	//プレイヤークラス
	CPlayer g_Player;

	//ステージクラス
	CStage g_Stage;

	//ステージ内で取得したDPの数
	int	m_Scholastic;		//学力
	int	m_Action;			//行動力
	int	m_Imagination;		//想像力
	int	m_Communication;	//コミュ力
	int	m_Charm;			//魅力

	//ゲーム開始時のカウントダウンテクスチャ　仮素材
	CTexture	m_StartThreeTexture;
	CTexture	m_StartTwoTexture;
	CTexture	m_StartOneTexture;
	CTexture	m_StartGoTexture;

	//ゲーム開始時のカウントダウン
	DWORD	m_StartTime;
	int m_StartCount = 0;
	//カウントダウン時のズーム倍率
	float m_StartScale;


	//フェードインフェードアウト用アルファ値（暗転）
	int m_BlackAlpha;

	//（明転）
	int m_WhiteAlpha;

	//デバッグ用
	//ゲームオーバーフラグ
	bool _GameOver;
	//クリアフラグ
	bool _GameClear;



public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);
};

