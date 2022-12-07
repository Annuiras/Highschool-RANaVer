#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "Define.h"
#include "GameApp.h"
#include "Player.h"
#include "Stage.h"


class CGAME :public CSceneBase
{

private:
	CMenu			gMenu;
	bool			Menuflag = false;
	int				gMenuItemCount = 2;

	//�v���C���[�N���X
	CPlayer g_Player;

	//�X�e�[�W�N���X
	CStage g_Stage;

	//�N���A�t���O

	bool Collosopn(CRectangle r1, CRectangle r2);
	//�Q�[���J�n���̃J�E���g�_�E���e�N�X�`���@���f��
	CTexture	gStartThreeTexture;
	CTexture	gStartTwoTexture;
	CTexture	gStartOneTexture;
	CTexture	gStartGoTexture;

	//�Q�[���J�n���̃J�E���g�_�E��
	DWORD	gStartTime;
	int gStartCount = 0;

	//ToDo	�t�F�[�h�C���t�F�[�h�A�E�g�p�A���t�@�l�i�Ó]�j
	int m_BlackAlpha;

	//�i���]�j
	int m_WhiteAlpha;

	//�f�o�b�O�p:�Q�[���I�[�o�[�t���O
	bool _GameOver;
	bool _GameClear;

public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);
};

