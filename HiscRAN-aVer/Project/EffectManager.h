#pragma once
#include "Define.h"
#include	"Effect.h"

//�G�t�F�N�g�Ǘ��N���X
class CEffectMgmt
{

private:
	//�G�t�F�N�g�N���X
	CEffect		m_Effect[EFC_TYPE_COUNT][EFFECT_MGMT_COUNT];

	//�G�t�F�N�g�摜
	CTexture	m_Texture[EFC_TYPE_COUNT];

public:
	CEffectMgmt();
	~CEffectMgmt();
	bool Load(void);
	void Initialize(void);
	CEffect* Start(float px, float py, int type);
	void Update(CRectangle plrec);
	void Render(void);
	//�f�o�b�O�\��
	void RenderDebugging(void);
	void Release(void);
	
};

