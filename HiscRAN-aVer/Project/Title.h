#pragma once
#include	"Mof.h"

#define		SCROLL_SPEED	1;

class Title
{
private:
	//�w�i�̃e�N�X�`��
	CTexture	m_BackTexture;

	//�^�C�g���̃e�N�X�`��
	CTexture	m_TitleTexture;

	//TitleUI�̃e�N�X�`��
	CTexture	m_TiTleUITexture;

	//font�N���X
	CFont		gFont;
	CFont		gFont2;

	//�X�N���[���l
	float		m_Scroll;
public:
	Title();
	~Title();
	void Initialize(void);
	void Update(void);
	void Render(void);
	bool Load(void);
	void Release(void);

};

