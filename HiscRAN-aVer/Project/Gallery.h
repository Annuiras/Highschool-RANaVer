#pragma once

#include	"Mof.h"
#include "SceneBase.h"

class CGallery :public CSceneBase
{
private:
	//�R���N�V������ʔw�i�e�N�X�`��
	CTexture	m_BackTexture;

	//����ςݍŏI�e�p�\��
	CTexture	m_LastApp;

	//������ŏI�e�p
	CTexture    m_NotLastApp[15];

	//�I�����̎l�p�`
	CTexture	m_SelectTexture;
	CTexture	m_SelectTexture_s;


	////�ŏI�e�p�̑䎆�e�N�X�`���i�o���j
	//CTexture	m_LastApp[15];

	//�t�H���g�ǂݍ���
	CFont		gFont1;
	CFont		gFont2;

	//�ŏI�e�p�̑䎆�e�N�X�`���i�o���j���W�i�[
	Vector2		pos[15] =
	{
		{60, 40},
		{180,40},
		{300,40},
		{420,40},
		{540,40},
		{60,240},
		{180,240},
		{300,240},
		{420,240},
		{540,240},
		{60,440},
		{180,440},
		{300,440},
		{420,440},
		{540,440}
	};

	//�ŏI�e�p�̑䎆�e�N�X�`���i�s�b�N�A�b�v�p�j
	CTexture	m_LastAppPic[15];

	CTexture	m_PickUp;
	CTexture	m_Text;
	CTexture	m_BackButton;

	bool LastAddFlag[15] =
	{
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
	};

public:
	CGallery();
	~CGallery();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};

