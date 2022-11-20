#pragma once
#include "Define.h"
#include	"Effect.h"

class CEffectManager
{

private:
	//エフェクトクラス
	CEffect		m_Effect[EFC_TYPECOUNT][EFFECT_MGMT_COUNT];

	//エフェクト画像
	CTexture	m_Texture[EFC_TYPECOUNT];

public:
	CEffectManager();
	~CEffectManager();
	bool Load(void);
	void Initialize(void);
	CEffect* Start(float px, float py, int type);
	void Update(CRectangle plrec);
	void Render(void);
	//デバッグ表示
	void RenderDebugging(void);
	void Release(void);
	
};

