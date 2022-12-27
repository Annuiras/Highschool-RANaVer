#pragma once
#include "Define.h"
#include "SceneBase.h"

class CGameOver :public CSceneBase
{
private:
	CTexture	m_BackTexture;
	CTexture	m_BackButton;
	CTexture	m_StartButton;
	CTexture	m_TextBack;
	CTexture	m_TextStart;
	CTexture	m_ENDText;
	int			Rondom;

	CRectangle recHPENDTex[5] = { {0,0,720,61} , {0,61,360,122},{0,122,841,195},{0,195,480,266},{0,266,1020,334} };
	CRectangle recDPENDTex[5] = { {0,334,664,403}, {0,403,600,471},{0,471,780,542},{0,542,360,612},{0,612,601,680} };
	int		   PosXHPEND[5] = { 276,453,218,396,124 };
	int		   PosXDPEND[5] = { 304,337,259,458,350 };
	
	//ゲームオーバ時のフェードインフェードアウト用
	//アルファ値
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	//ゲームオーバー原因フラグ
	bool HPEND = false;
	bool DPEND = false;

public:
	CGameOver();
	~CGameOver();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

