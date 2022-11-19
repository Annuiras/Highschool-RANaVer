#pragma once
#include "Define.h"
#include	"Effect.h"

class CEffectManager
{

private:
	//�G�t�F�N�g�N���X
	CEffect		m_Effect[EFFECTCOUNT][EFC_TYPECOUNT];

	//�G�t�F�N�g�摜
	CTexture	m_Texture[EFC_TYPECOUNT];

public:
	CEffectManager();
	~CEffectManager();
	bool Load(void);
	void Initialize(void);
	CEffect* Start(float px, float py, int type);
	void Update(void);
	void Render(void);
	void Release(void);
	
};

