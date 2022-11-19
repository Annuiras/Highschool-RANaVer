#pragma once
#include	"Mof.h"
#include "SceneBase.h"
#include "Define.h"

//�X�N���[�����x
#define		SCROLL_SPEED	1;

class CTitle :public CSceneBase
{
private:
	//�w�i�̃e�N�X�`��
	CTexture	m_BackTexture1;
	CTexture	m_BackTexture2;
	CTexture	m_BackTexture3;


	//�^�C�g���̃e�N�X�`��
	CTexture	m_TitleTexture;

	//TitleUI�̃e�N�X�`��
	CTexture	m_TiTleUITexture;

	//font�N���X
	CFont		gFont;
	CFont		gFont2;

	//�X�N���[���l
	float		m_Scroll;

	//�����_���p
	int			Rondom;

public:
	CTitle();
	~CTitle();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);

};

