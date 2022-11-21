#pragma once
#include "Define.h"
#include	"Effect.h"

//エフェクト管理クラス
class CEffectMgmt
{

private:
	//エフェクトクラス
	CEffect		m_Effect[EFC_TYPE_COUNT][EFFECT_MGMT_COUNT];

	//エフェクト画像
	CTexture	m_Texture[EFC_TYPE_COUNT];

public:
	CEffectMgmt();
	~CEffectMgmt();
	bool Load(void);
	void Initialize(void);
	CEffect* Start(float px, float py, int type);
	void Update(CRectangle plrec);
	void Render(void);
	//デバッグ表示
	void RenderDebugging(void);
	void Release(void);
	
};

