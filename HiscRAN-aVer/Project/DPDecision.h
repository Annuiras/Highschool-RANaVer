#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "Menu.h"

class CDPDecision :public CSceneBase
{
private:

	CMenu		m_Menu;

	CTexture	m_ExTexture;

	//�w�i�e�N�X�`��
	CTexture	m_BackTextureA;
	CTexture	m_BackTextureC;

	//��������
	CTexture	m_TextTexture;

	//�I��g
	CTexture	m_SelectTexture;

	//�Ȃ��DP��I�񂾂��ǂ����̃t���O
	//True:�I�񂾁@False�F�I��łȂ�
	//[0]���z����
	//[1]���s����
	//[2]������
	//[3]���R�~����
	//[4]���w��
	bool m_SelectDP[5];
	
	//�t�F�[�h�C���w�i�A���t�@�l
	int m_WhiteBakAlph;


public:
	CDPDecision();
	~CDPDecision();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

