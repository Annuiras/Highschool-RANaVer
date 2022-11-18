#pragma once

#include	"Mof.h"
#include "Define.h"

//�G�t�F�N�g��ޗ�
enum tag_EFFECTTYPE {
	EFC_GET_DP,						//DP�擾
	//EFC_EXPLOSION01,				//�G���j
	//EFC_EXPLOSION02,				//�v���C���[���j

	EFC_TYPECOUNT,
};


class CEffect
{	
private:
	CTexture* m_pTexture;
	CSpriteMotionController	m_Motion;
	float					m_PosX;
	float					m_PosY;
	bool					m_bShow;
	CRectangle				m_SrcRect;
	//CSoundBuffer	m_Sound;
public:
	CEffect();
	~CEffect();
	void Initialize(int type);
	void Start(float px, float py);
	void Update(void);
	void Render(void);
	void Release(void);

	//�e�N�X�`���̃|�C���^���󂯎��
	void SetTexture(CTexture* pt) { m_pTexture = pt; }
	bool GetShow(void) { return m_bShow; }
	
};

