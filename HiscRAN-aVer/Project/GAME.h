#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "Define.h"
#include "Player.h"
#include "Stage.h"
#include <thread>

using namespace std;

class CGAME :public CSceneBase
{

private:

	//DP�ƐڐG����
	void UPdeteCollisionDP(int dpt);

	//���j���[�N���X
	//CMenu			m_Menu;
	//int				m_MenuItemCount = 2;

	//�v���C���[�N���X
	CPlayer g_Player;

	//�X�e�[�W�N���X
	CStage g_Stage;

	//�X�e�[�W���Ŏ擾����DP�̐�
	//0:�w��
	//1:�s����
	//2:�z����
	//3:�R�~����
	//4:����
	int m_DPNum[DP_COUNT];

	//SP�X�e�[�W���Ŏ擾����DP�̐�
	int m_SP_DPNum;


	//�Q�[���J�n���̃J�E���g�_�E���e�N�X�`���@���f��
	CTexture	m_StartThreeTexture;
	CTexture	m_StartTwoTexture;
	CTexture	m_StartOneTexture;
	CTexture	m_StartGoTexture;

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



public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);
};

