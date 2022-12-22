#pragma once
#include "SceneBase.h"
#include "Define.h"

//スクロール速度
#define		SCROLL_SPEED	1;

class CTitle :public CSceneBase
{
private:

	//背景のテクスチャタイプ1
	CTexture	m_BackTexture1;

	//背景のテクスチャタイプ2
	CTexture	m_BackTexture2;

	//背景のテクスチャタイプ3
	CTexture	m_BackTexture3;

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

	//背景α値
	int m_BakAlph;

public:
	CTitle();
	~CTitle();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);

	void Load(void);

	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);

};

