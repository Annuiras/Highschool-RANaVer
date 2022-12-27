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

	//����ςݍŏI�e�p�\��
	CTexture	m_LastApp;

	//������ŏI�e�p
	CTexture    m_NotLastApp[15];

	//�I�����̎l�p�`�i�ŏI�e�p�j
	CTexture	m_SelectTexture;

	//�I�����̎l�p�`�i�߂�{�^���j
	CTexture	m_SelectTexture_s;


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

	//�e�L�X�g�{�b�N�X�̋�`
	CRectangle RecTextBox[15] =
	{
		{0,0,400,189},
		{400,0,800,189},
		{800,0,1200,189},
		{0,189,400,378},
		{400,189,800,378},
		{800,189,1200,378},
		{0,378,400,567},
		{400,378,800,567},
		{800,378,1200,567},
		{0,567,400,756},
		{400,567,800,756},
		{800,567,1200,756},
		{0,756,400,945},
		{400,756,800,945},
		{800,756,1200,945}
	};


	//�ŏI�e�p�̑䎆�e�N�X�`���i�s�b�N�A�b�v�p�j
	CTexture	m_LastAppPic[15];

	//�ŏI�e�p�䎆
	CTexture	m_PickUp;

	//����ςݍŏI�e�p�e�L�X�g
	CTexture	m_PickUpText;

	//������ŏI�e�p�e�L�X�g
	CTexture	m_NotPickUpText;

	//�e�L�X�g�{�b�N�X
	CTexture	m_Text;

	//�߂�{�^��
	CTexture	m_BackButton;

	int m_BakAlph;

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
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

