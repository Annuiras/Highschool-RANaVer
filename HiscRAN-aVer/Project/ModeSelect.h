///////////////////////////////////////////
//�@���[�h�Z���N�g��ʂ̃v���O�����ł�   //
//								   �@�@�@//
//�@�쐬�ҁF���Y���H�@�@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/17		   �@�@�@//
///////////////////////////////////////////

#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "Define_Music.h"
#include "Define_Menu.h"

//�I������
#define MenuCnt (4)

//�X�N���[�����x
#define		SCROLL_SPEED	1;

//���[�h�Z���N�g���
class CModeSelect :public CSceneBase
{
private:

	//��I����Ԃ̑I�����܂Ƃ�
	CTexture		m_TutorialTextureSmall;

	//�I����Ԃ̑I�����܂Ƃ�
	CTexture		m_TutorialTextureBig;

	//�w�i�摜�܂Ƃ�
	CTexture		m_TutorialBG[4];

	//��ʉ��e�L�X�g�w�i
	CTexture		m_TutorialTextBox;

	//��ʉ��e�L�X�g
	CTexture		m_TutorialTextTexture;
	//��ʉ��e�L�X�g�X�N���[���l
	float			m_Scroll;

	//���[�h�Z���N�g�J�[�\���ʒu
	int MenuNow_Mode;

	//�t�F�[�h�A�E�g�p�A���t�@�l
	int m_BakAlph;

public:
	CModeSelect();
	~CModeSelect();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effecs, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);

};

