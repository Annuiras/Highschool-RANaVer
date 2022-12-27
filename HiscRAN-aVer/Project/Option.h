#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "MusicManager.h"

class COption :public CSceneBase
{
private:

	//�t�H���g
	CFont			m_Font1;

	//���n
	CTexture		m_mount;

	//�w�i
	CTexture		m_BG;

	//���ʃ{�^���iBGM�j
	CTexture		m_Button1_1;
	//���ʃ{�^���iSE�j
	CTexture		m_Button1_2;

	//SE�炷�{�^��
	CTexture		m_Button2;

	//�t���X�N���[�����ۂ��{�^��
	CTexture		m_Button3_Win;
	CTexture		m_Button3_Full;

	//�I���l�p�`
	CTexture		m_Select_BGM;
	CTexture		m_Select_SE;
	CTexture		m_Select_Screen;
	CTexture		m_Select_s;

	//�߂�{�^��
	CTexture	m_BackButton;

	//����
	CTexture		m_ExTexture;
	bool flag = false;


	//BGM����
	double VolumeBGM;
	double VolumeSE;

	int OptionCnt = 0;

	//double
	//�{�^�����W�iy���j
	double Botton_BGMPosy = 0;
	double Botton_SEPosy = 0;

	//BGM�������Ă邩���ĂȂ����t���O
	bool flagBGM = false;

	//SE�������Ă邩���ĂȂ����t���O
	bool flagSE = false;

	//��ʃT�C�Y�������Ă邩���ĂȂ����t���O
	bool flagSC = false;

	//�t���X�N���[�����ۂ�
	bool ScreenSize = false;

	//�w�i���l
	int m_BakAlph;

public:
	COption();
	~COption();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

