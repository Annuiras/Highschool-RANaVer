//////////////////////////////////////////////
//	�Q�[���Ǘ��̃v���O�����ł��@�@�@�@�@�@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "Define_Music.h"
#include "Define_Menu.h"
#include "Player.h"
#include "Stage.h"



class CGAME :public CSceneBase
{

private:

	//DP�ƐڐG����
	void UPdeteCollisionDP(int dpt);

	//�v���C���[�N���X
	CPlayer g_Player;

	//�X�e�[�W�N���X
	CStage g_Stage;

	//�X�e�[�W���Ŏ擾����DP�̐�
	int m_DPNum[DP_COUNT];

	//SP�X�e�[�W���Ŏ擾����DP�̐�
	int m_SP_DPNum;


	//�Q�[���J�n���̃J�E���g�_�E���e�N�X�`���@���f��
	CTexture	m_StartThreeTexture;
	CTexture	m_StartTwoTexture;
	CTexture	m_StartOneTexture;
	CTexture	m_StartGoTexture;
	
	//�Q�[���N���A���̃e�L�X�g�e�N�X�`��
	CTexture   m_ClearTexture;
	//�N���A�p�\���{��
	float m_ClearScale;


	//�Q�[���J�n���̃J�E���g�_�E��
	DWORD	m_StartTime;
	int m_StartCount = 0;
	//�J�E���g�_�E�����̃Y�[���{��
	float m_StartScale;

	//DP�ڕW�ݒ��ʂőI��DP�ԍ�
	int m_DPDeci;

	//�t�F�[�h�p�A���t�@�l
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	//�Q�[���I�[�o�[�t���O
	bool m_GameOverflg;
	//�N���A�t���O
	bool m_GameClearflg;

	//�q�b�g�X�g�b�v�̕ϐ��ǉ�
	float			m_StopCount;
	bool			m_Stopflg;


public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void UpdateDebug(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);
};

