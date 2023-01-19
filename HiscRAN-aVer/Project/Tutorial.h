///////////////////////////////////////////
//�@�`���[�g���A���̃v���O�����ł�   �@�@//
//								   �@�@�@//
//�@�쐬�ҁF���Y���H  �@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/17		   �@�@�@//
///////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Music.h"
#include "SceneBase.h"

//�y�[�W��
#define PAGES_NUM 7

//�����摜�Œ�ʒu
#define PAGES_X 243
#define PAGES_Y 94

//�X�N���[���X�s�[�h
#define PAGES_SPEED 20


class CTutorial:public CSceneBase
{
private:

	//�����e�N�X�`��
	CTexture ExTextTexture[PAGES_NUM];

	//�w�i�e�N�X�`��
	CTexture BGTexture;

	//�X�N���[���e�N�X�`��
	CTexture ScreenTexture;

	//�J�[�e�������e�N�X�`��
	CTexture CurtainBGTexture;

	//�J�[�e�������e�N�X�`����
	CTexture CurtainBGTextureLeft;

	//�J�[�e�������e�N�X�`���E
	CTexture CurtainBGTextureRight;

	//�J�[�e����
	CTexture CurtainBGTextureTop;

	//�߂�{�^���e�N�X�`��
	CTexture BackButton;

	//�I��g
	CTexture ButtonSelect;

	//�y�[�W���Ƃ�X���W
	int gPosX[PAGES_NUM];

	//���݂̃y�[�W
	int m_Cursor;

	//�ړ����t���O
	bool Is_Move;

	//
	int MoveX;

	//�߂�{�^���ɃJ�[�\�������邩�Ȃ���
	bool TMenuCnt;

	//�w�i���l
	int m_BakAlph;


public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

