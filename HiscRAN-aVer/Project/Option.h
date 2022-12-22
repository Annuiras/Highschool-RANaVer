#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "MusicManager.h"

class COption :public CSceneBase
{
private:

	//フォント
	CFont			m_Font1;

	//下地
	CTexture		m_mount;

	//背景
	CTexture		m_BG;

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

	//説明
	CTexture		m_ExTexture;
	bool flag = false;


	//BGM音量
	double VolumeBGM;
	double VolumeSE;

	int OptionCnt = 0;

	//double
	//ボタン座標（y軸）
	double Botton_BGMPosy = 0;
	double Botton_SEPosy = 0;

	//BGM調整してるかしてないかフラグ
	bool flagBGM = false;

	//SE調整してるかしてないかフラグ
	bool flagSE = false;

	//画面サイズ調整してるかしてないかフラグ
	bool flagSC = false;

	//フルスクリーンか否か
	bool ScreenSize = false;

	//背景α値
	int m_BakAlph;

public:
	COption();
	~COption();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

