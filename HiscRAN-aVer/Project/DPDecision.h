///////////////////////////////////////////
//�@DP�I����ʂ̃v���O�����ł�   �@�@  �@//
//								   �@�@�@//
//�@�쐬�ҁF���Y���H  �@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/19		   �@�@�@//
///////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Music.h"
#include "Define_Menu.h"
#include "RandomValue.h"
#include "SceneBase.h"

//�I������
#define DPDECISION_MENUCNT 5

class CDPDecision :public CSceneBase
{
private:

	//��������
	RandomValue RandmuBak;

	//��ʐ���
	CTexture	m_Screen_Ex;

	//�w�i����
	CTexture	m_Back_BB;

	//���h��L����
	CTexture	m_BackChara_B;

	//��������
	CTexture	m_Target_Text;

	//�I��g
	CTexture	m_SelectTexture;
	
	//�}�O�l�b�g&���O
	CTexture	m_BackMagnet_Name;

	//�t�F�[�h�C���w�i�A���t�@�l
	int m_WhiteBakAlph;

	//�I�����ԍ�
	int DPDecCnt;

	//DP�I������\���t���O
	//true:�\����
	bool flagD;

	//SP�X�e�[�W����t���O
	//true�FSP����
	bool SP_flg;


public:
	CDPDecision();
	~CDPDecision();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);

	void UpdateDebug(void);

	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

