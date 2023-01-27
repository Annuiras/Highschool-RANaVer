//////////////////////////////////////////////
//	�X�e�[�W�Ǘ��̃v���O�����ł�			//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "RandomValue.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "EffectManager.h"
#include "MusicManager.h"


class CStage
{
private:

	//��������
	RandomValue RandmuBak;

	//�G�t�F�N�g�}�l�[�W���[
	CEffectMgmt* m_pEffectMgmt;

	//SE�EBGM�}�l�[�W���[
	CMusicMgmt* m_MusicMgmt;

	//�X�e�[�W�e�N�X�`��
	CTexture m_BakTex[STAGE_BAKT_COUNT];

	//DP�e�N�X�`��
	CTexture m_DPTex[DP_COUNT];

	//��Q���e�N�X�`��
	CTexture ob_Textuer[OB_COUNT];

	#pragma region ����e�N�X�`��

	//���e�N�X�`���F�����
	CTexture bar_Textuer_Big;

	//���e�N�X�`���F���ꒆ
	CTexture bar_Textuer_Medium;

#pragma endregion

	#pragma region �G�e�N�X�`��

	//�G�e�N�X�`�� : �G1
	CTexture ene_Texture_1;

	//�G�A�j���[�V����
	CSpriteMotionController Enemy_Motion;
#pragma endregion

	//�i�s�x�o�[
	CTexture m_BarTextuer;
	//�i�s�x���A�C�R��
	CTexture m_CharaProgressTextuer;
	//�L�����A�C�R���̕\��
	CTexture m_CharaIconTexture;
	//�w�N�̕\��
	CTexture m_GradeOneTexture;
	CTexture m_GradeTwoTexture;
	CTexture m_GradeThreeTexture;

	CTexture m_DPDEcisionTexture[DP_COUNT];


	//�i�s�x�\���p
	int m_BarProgress;

	//�w�N�摜�\���̈ʒu
	float	m_GradeOffset;

	//�}�b�v�p�^�[���Y����
	int m_MapNo;

	//�X�e�[�W�\�������߂�z��
	int m_StageComposition[SATAGE_MAP_PATTERN + 1];

	//�\���ς�DP��
	int m_dpcount;

	//�\���Ϗ�Q��
	int m_obcount;

	//�\���ςݑ��ꐔ
	int m_barcount;

	//�\���ςݓG��
	int m_enecount;

	//�w�i�p�X�N���[���l
	float	m_BakScroll;

	//�X�e�[�W�p�X�N���[��
	float	m_StageScroll;

	//�i�s�x�v�Z�p
	int m_BarProgressCount;

	//�w�i�\��
	int m_BakComposition[(SATAGE_MAP_PATTERN * 2)+1];
	//�w�i�J�E���g
	int m_countbak;


	//���Ԕw�i�p�����_�����l
	//����
	int m_RandamuBakLeft;
	//�E��
	int m_RandamuBakRight;
	//�ۑ��p
	int m_RandamuBakRightSave;

	//�g�p�ς݃p�^�[���ԍ��L�^�p�z��
	int	m_AlreadyUsedArray[MAP_INFO_PATTERN];

	//�̗p�σJ�E���g
	int m_AdoptCount;


	//�X�N���[���X�s�[�h
	float m_Scroll_Speed;

	//�X�e�[�W�ω�
	bool				v_StageChangeflg;//�ω��t���O true:�ω���

	//SP����t���O
	//true:����
	bool SP_flg;

	//�w�i���l
	int m_BakAVal;

	//SP�X�e�[�W
	//SP�̏�Ԃ�����
	tag_StageSituation	m_SPSitua;

	int					m_SPcountbak;

	//DP�ڕW�ݒ��ʂőI��DP�ԍ�
	int DP_Deci_Type;

	//SP�t�F�[�h�A�E�g�t���O
	bool				m_SPflg;

	//�N���A�t���O
	bool m_bClear;

	//�Q�[���J�n�t���O
	//true:�J�n��
	bool					m_Startflg;

public:
	CStage();
	~CStage();

	//spflg:SP����t���O
	//dptype:DP�ڕW�ݒ��ʂőI��DP�ԍ�
	void Initialize(bool spflg,int dptype);

	void Update(CRectangle plrect);

	//�f�o�b�N�X�V
	void UpdateDebug(void);

	//�f�ރ��[�h
	bool Load(void);

	void Render(void);
	void Release(void);
	void RenderDebugging(void);

	//�}�b�v�p�^�[��
	void MapChange(void);

	//���ꐶ��
	void OccurrenceBar(void);

	//DP����
	void OccurrenceDP(void);

	//��Q������
	void OccurrenceOB(void);

	//�G����
	void OccurrenceENE(void);

	//�N���A����̎擾
	bool GetClear(void);

	//SE�EBGM�}�l�[�W���[�Z�b�g
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//�G�t�F�N�g�}�l�[�W���[�Z�b�g
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }

	//��Q��
	CObstacle ob_array[OB_VOLUME];

	//����N���X
	Bar	b_bar[BAR_VOLUME];

	//���ʂɕ\������DP�̐������p��
	//DP�N���X
	DetailPoint dp_array[DP_VOLUME];

	//�G�N���X
	CEnemy ene_array[ENEMY_VOLUME];

	//�Q�[����~�F�Đ��؂�ւ�
	void GameStopPlayChange();

	//�X�e�[�W�������Ă��邩�擾
	bool GetGameStopPlay();

	//SP�̏�Ԃ��Z�b�g
	void SetSPSitua(tag_StageSituation i) { m_SPSitua = i; }


};