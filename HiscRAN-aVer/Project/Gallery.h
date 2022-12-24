#pragma once

#include "Define.h"
#include "SceneBase.h"
#include <thread>

using namespace std;

class CGallery :public CSceneBase
{
private:

	//�R���N�V������ʔw�i�e�N�X�`��
	CTexture	m_BackTexture;

	//����ςݍŏI�e�p�I��:�{�I�e�N�X�`��
	CTexture	m_LastApp;

	//�I�����̎l�p�`�i�ŏI�e�p�j
	CTexture	m_SelectTexture;

	//�I�����̎l�p�`�i�߂�{�^���j
	CTexture	m_SelectTexture_s;

	//�ŏI�e�p�p�����[�^�\����
	typedef struct LastTexture
	{
		//�ŏI�e�p�e�N�X�`���i�s�b�N�A�b�v�p�j
		CTexture s_LastAppPic;

		//�ŏI�e�p�̑䎆�e�N�X�`���i�o���j���W�i�[
		Vector2 s_Mount_Pos;

		//�e�L�X�g�{�b�N�X�̕\����`
		CRectangle s_TextBoxRect;

		//���J���t���O
		bool s_LastAddFlag;

		//������{�e�N�X�`��
		CTexture s_NotLastApp;
	};

	//�錾
	LastTexture S_LastParameter[16];


	//�ŏI�e�p�䎆
	CTexture	m_PickUp;

	//����ςݍŏI�e�p�e�L�X�g
	CTexture	m_PickUpText;

	//������ŏI�e�p�e�L�X�g
	CTexture	m_NotPickUpText;

	//�e�L�X�g�{�b�N�X�w�i
	CTexture	m_Text;

	//�߂�{�^��
	CTexture	m_BackButton;

	int m_BakAlph;

	//�\���̂ɒl���Z�b�g
	struct LastTexture SetLastParameter(Vector2 Pos, CRectangle textrec, bool b)
	{
		LastTexture ps;

		ps.s_Mount_Pos = Pos;
		ps.s_LastAddFlag = b;
		ps.s_TextBoxRect = textrec;

		return ps;
	}

public:
	CGallery();
	~CGallery();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

