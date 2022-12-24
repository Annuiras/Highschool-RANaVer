#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "Define.h"
#include "Player.h"
#include "Stage.h"
#include "Result.h"

#include <thread>
using namespace std;

//ゲーム画面クラス
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

	CResult g_Result;

	//ステージ内で取得したDPの数
	//[0]：1年
	//[1]：2年
	//[2]：3年
	//[3]：合計
	//[][0]:学力
	//[][1]:行動力
	//[][2]:想像力
	//[][3]:コミュ力
	//[][4]:魅力
	int m_DPNum[4][DP_COUNT];

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

	//DP目標設定画面で選んだDP番号
	int m_DPDeci;

	//現在の学年数
	int m_SchoolYear;

	//フェード用アルファ値
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	//ゲームオーバーフラグ
	bool m_GameOverflg;
	//クリアフラグ
	bool m_GameClearflg;



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

