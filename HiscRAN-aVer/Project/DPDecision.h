#pragma once
#include "Define.h"
#include "SceneBase.h"

class CDPDecision :public CSceneBase
{
private:

	CTexture	m_ExTexture;

	//背景テクスチャ
	CTexture	m_BackTextureA;
	CTexture	m_BackTextureC;

	//説明文字
	CTexture	m_TextTexture;

	//選択枠
	CTexture	m_SelectTexture;

	//なんのDPを選んだかどうかのフラグ
	//True:選んだ　False：選んでない
	//[0]→想像力
	//[1]→行動力
	//[2]→魅力
	//[3]→コミュ力
	//[4]→学力
	//bool m_SelectDP[5];
	
	//フェードイン背景アルファ値
	int m_WhiteBakAlph;


public:
	CDPDecision();
	~CDPDecision();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

