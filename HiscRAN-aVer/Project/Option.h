#pragma once
#include	"Mof.h"
#include "SceneBase.h"
#include "MusicManager.h"

class COption :public CSceneBase
{
private:

	//�t�H���g
	CFont			m_Font1;

	//���n
	CTexture		m_mount;

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

	//BGM����
	float VolumeBGM = 0;
	float VolumeSE = 0;
	//double
	//�{�^�����W�iy���j
	double y_1 = 0;
	double y_2 = 0;

	//BGM�������Ă邩���ĂȂ����t���O
	bool flagBGM = false;

	//SE�������Ă邩���ĂȂ����t���O
	bool flagSE = false;

	//��ʃT�C�Y�������Ă邩���ĂȂ����t���O
	bool flagSC = false;

	//�t���X�N���[�����ۂ�
	bool ScreenSize = false;



public:
	COption();
	~COption();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};

