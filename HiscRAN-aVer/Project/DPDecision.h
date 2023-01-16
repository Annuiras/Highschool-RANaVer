#pragma once
#include "Define.h"
#include "RandomValue.h"
#include "SceneBase.h"

//����ҁF���Y ���H �A�c�� ��
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
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

