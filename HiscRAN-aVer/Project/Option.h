#pragma once
#include	"Mof.h"
#include "SceneBase.h"
#include "MusicManager.h"

class COption :public CSceneBase
{
private:

	//フォント
	CFont			m_Font1;

	//下地
	CTexture		m_mount;

	//音量ボタン（BGM）
	CTexture		m_Button1_1;
	//音量ボタン（SE）
	CTexture		m_Button1_2;

	//SE鳴らすボタン
	CTexture		m_Button2;

	//フルスクリーンか否かボタン
	CTexture		m_Button3_Win;
	CTexture		m_Button3_Full;

	//選択四角形
	CTexture		m_Select_BGM;
	CTexture		m_Select_SE;
	CTexture		m_Select_Screen;
	CTexture		m_Select_s;

	//戻るボタン
	CTexture	m_BackButton;

	//BGM音量
	float VolumeBGM = 0;
	float VolumeSE = 0;
	//double
	//ボタン座標（y軸）
	double y_1 = 0;
	double y_2 = 0;

	//BGM調整してるかしてないかフラグ
	bool flagBGM = false;

	//SE調整してるかしてないかフラグ
	bool flagSE = false;

	//画面サイズ調整してるかしてないかフラグ
	bool flagSC = false;

	//フルスクリーンか否か
	bool ScreenSize = false;



public:
	COption();
	~COption();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};

