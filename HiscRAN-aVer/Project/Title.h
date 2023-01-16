#pragma once
#include "SceneBase.h"
#include "RandomValue.h"
#include "Define.h"

//�X�N���[�����x
#define		SCROLL_SPEED	1;

//�w�i���
#define BACK_TYPE 5

class CTitle :public CSceneBase
{
private:

	//��������
	RandomValue RandmuBak;

	//�w�i�̃e�N�X�`��
	CTexture	m_BackTexture[BACK_TYPE];

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

	//UI�A���t�@�l
	int gAlpha;

	//UI�t�F�[�h�t���O
	bool isStop;

	//�w�i���l
	int m_BakAlph;

	//�w�i���ʔԍ�
	int m_Bak_Type[3];

public:
	CTitle();
	~CTitle();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);

	void Load(void);

	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);

};

