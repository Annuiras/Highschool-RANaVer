#pragma once

#include "Define.h"
#include "SceneBase.h"
//����ҁF���Y ���H �A�c�� ��

//�M�������[��ʃN���X
class CGallery :public CSceneBase
{
private:

	//�ŏI�e�p�w�i���
	enum tag_BAKLAST_TYPE {

		//�m�[�}��
		BL_NORMAL,

		//�X�[�p�[���f�B
		BL_SUPERLADY,

		//�����q��
		BL_OTYOUSI,

		//���w����
		BL_BUNGAKU,

		//����a
		BL_TYUNI,

		//�_�Ή�
		BL_KAMITAIOU,

		//����
		BL_COUNT
	}; 

	//�R���N�V������ʔw�i�e�N�X�`��
	CTexture	m_BackTexture;

	//����ςݍŏI�e�p�I��:�{�I�e�N�X�`��
	CTexture	m_LastApp;

	//�I�����̎l�p�`�i�ŏI�e�p�j
	CTexture	m_SelectTexture;

	//�I�����̎l�p�`�i�߂�{�^���j
	CTexture	m_SelectTexture_s;

	//�ŏI�e�p�w�i
	CTexture m_BakLastAp;

	//�ŏI�e�p�p�����[�^�\����
	//�\���̒�`
	typedef struct LastTexture
	{
		//�ŏI�e�p�e�N�X�`���i�s�b�N�A�b�v�p�j
		CTexture s_LastAppPic;

		//���J���t���O
		bool s_LastAddFlag;

		//������{�e�N�X�`��
		CTexture s_NotLastApp;
	};

	//�ŏI�e�p�p�����[�^�\����
	LastTexture S_LastParameter[16];

	//�ŏI�e�p�w�i�\����`
	CRectangle m_BakLastRect[BL_COUNT];

	//����ςݍŏI�e�p�e�L�X�g
	CTexture	m_PickUpText;

	//������ŏI�e�p�e�L�X�g
	CTexture	m_NotPickUpText;

	//�e�L�X�g�{�b�N�X�w�i
	CTexture	m_Text;

	//�߂�{�^��
	CTexture	m_BackButton;

	//�t�F�[�h�A�E�g�p�A���t�@�l
	int m_BakAlph;

	//�J�[�\���ԍ�
	int galleryCnt = 0;

public:
	CGallery();
	~CGallery();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

