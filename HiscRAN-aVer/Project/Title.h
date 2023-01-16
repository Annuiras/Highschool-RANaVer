#pragma once
#include "SceneBase.h"
#include "RandomValue.h"
#include "Define.h"

//スクロール速度
#define		SCROLL_SPEED	1;

//背景種類
#define BACK_TYPE 5

class CTitle :public CSceneBase
{
private:

	//乱数生成
	RandomValue RandmuBak;

	//背景のテクスチャ
	CTexture	m_BackTexture[BACK_TYPE];

	//タイトルのテクスチャ
	CTexture	m_TitleTexture;

	//TitleUIのテクスチャ
	CTexture	m_TiTleUITexture;

	//fontクラス
	CFont		gFont;
	CFont		gFont2;

	//スクロール値
	float		m_Scroll;
	//ランダム用
	int			Rondom;

	//UIアルファ値
	int gAlpha;

	//UIフェードフラグ
	bool isStop;

	//背景α値
	int m_BakAlph;

	//背景識別番号
	int m_Bak_Type[3];

public:
	CTitle();
	~CTitle();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);

	void Load(void);

	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);

};

