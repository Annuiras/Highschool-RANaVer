#pragma once
#include "Mof.h"
#include "SceneBase.h"

class CGameOver :public CSceneBase
{
private:
	CTexture	m_BackTexture1;
	CTexture	m_BackTexture2;
	CTexture	m_BackTexture3;
	CTexture	m_UITexture;
	CTexture	m_SelectTexture;
	int			Rondom;

	//ToDo	ゲームオーバ時のフェードインフェードアウト用
	//アルファ値
	int			m_Alpha;
	bool		m_Over;


public:
	CGameOver();
	~CGameOver();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};

