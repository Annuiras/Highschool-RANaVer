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

////DP�̏o���ʒu���p�\����
typedef struct tag_DP_POS
{
	float Scroll;	//DP�o���X�N���[���l
	float Pos_y;	//DP�o��Y���W
	tag_DP_TYPE	Type;		//DP�^�C�v

} DP_info;

//��Q���̏o���ʒu���p�\����
typedef struct tag_OBSTAClE_POS
{	
	float Scroll;	//��Q���o���X�N���[���l
	float Pos_y;	//��Q���o��Y���W
	tag_OBTYPE	Type;		//��Q���^�C�v

} OB_info;


//����̏o���ʒu���p�\����
typedef struct tag_BAR_POS
{	
	float Scroll;	//����o���X�N���[���l
	float Pos_y;	//����o��Y���W
	tag_BAR	Type;		//����^�C�v�i���j

} BAR_info;

//�G�̏o���ʒu���\����
typedef struct tag_ENEMY_POS
{
	float Scroll;
	float Pos_y;
	int	  Type;
} ENEMY_info;

//���[�V������ޒ�`
enum tag_ENEMY_MOTION {
	ENEMY_MOTION_MOVE,

	ENEMY_MOTION_COUNT,
};

class CStage
{
private:

	//��������
	RandomValue RandmuBak;

	//�G�t�F�N�g�}�l�[�W���[
	CEffectMgmt* m_pEffectMgmt;

	//SE�EBGM�}�l�[�W���[
	CMusicMgmt* m_MusicMgmt;


	#pragma region �X�e�[�W�e�N�X�`��

	//�L���n�܂�
	CTexture m_BakStart;

	//�E��
	CTexture m_BakRdoor;
	
	//�E��
	CTexture m_BakRwall;

	//����
	CTexture m_Bakldoor;

	//����
	CTexture m_Baklwall;

	//��
	CTexture m_BakWindow;

	//�K�i
	CTexture m_BakStairs;

	//�L���I���
	CTexture m_BakEnd;

	//SP�X�e�[�W�n�܂�
	CTexture m_SPBak_Start;

	//SP�X�e�[�W�P
	CTexture m_SPBak_1;

	//SP�X�e�[�W�Q
	CTexture m_SPBak_2;

	//SP�X�e�[�W�I���
	CTexture m_SPBak_End;

#pragma endregion

	#pragma region DP�e�N�X�`��

	//��DP�e�N�X�`���F�w��
	CTexture dp_Textuer_Scholastic;

	//��DP�e�N�X�`���F�s����
	CTexture dp_Textuer_Action;

	//��DP�e�N�X�`���F�z����
	CTexture dp_Textuer_Imagination;

	//��DP�e�N�X�`���F�R�~����
	CTexture dp_Textuer_Communication;

	//��DP�e�N�X�`���F����
	CTexture dp_Textuer_Charm;


#pragma endregion

	#pragma region ��Q���e�N�X�`��

	//�e�N�X�`���F��
	CTexture ob_Textuer_Desk;

	//�e�N�X�`���F�Q�i��
	CTexture ob_Textuer_TwoDesk;

	//�e�N�X�`���F���ݔ�
	CTexture ob_Textuer_TrachCan;

	//�e�N�X�`���F���b�J�[
	CTexture ob_Textuer_Locker;

	//�e�N�X�`���F���ȏ�_����
	CTexture ob_Textuer_TextBookNL;

	//�e�N�X�`���F���ȏ�_���w
	CTexture ob_Textuer_TextBookMATH;

	//�e�N�X�`���F���ȏ�_����
	CTexture ob_Textuer_TextBookCHEM;

	//�e�N�X�`���F���ȏ�_�Љ�
	CTexture ob_Textuer_TextBookSOC;

	//�e�N�X�`���F���ȏ�_�p��
	CTexture ob_Textuer_TextBookENG;

	//�e�N�X�`���F���є�
	CTexture ob_Textuer_VaultingHorse;

	//�e�N�X�`���F�Z���n���e�[�v
	CTexture ob_Textuer_ScotchTape;

	//�e�N�X�`���F������
	CTexture ob_Textuer_BloackboardEraser;

	//�e�N�X�`���F�X�e�B�b�N�̂�
	CTexture ob_Seaweed;

	//�e�N�X�`���F�X�}�z�P
	CTexture ob_Smartphone1;

	//�e�N�X�`���F�����S��
	CTexture ob_Eraser;

	//�e�N�X�`���F�X�}�z�c
	CTexture ob_SmartphoneVertical;

#pragma endregion

	#pragma region ����e�N�X�`��

	//���e�N�X�`���F�����
	CTexture bar_Textuer_Big;

	//���e�N�X�`���F���ꒆ
	CTexture bar_Textuer_Medium;

#pragma endregion

	#pragma region �G�e�N�X�`��

	//�G�e�N�X�`�� : �G1
	CTexture ene_Texture_1;
	//�G�e�N�X�`�� : �G2
	CTexture ene_Texture_2;

#pragma endregion

	//�G�A�j���[�V����
	CSpriteMotionController Enemy_Motion;

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
	//�i�s�x�\���p
	int m_BarProgress;

	//�w�N�摜�\���̈ʒu
	float	m_GradeOffset;

	//�}�b�v�p�^�[���Y����
	int m_MapNo;

	//�X�e�[�W�\�������߂�z��
	int m_StageComposition[SATAGE_MAP_PATTERN] = { 1 };


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
	bool					m_Startflg;

public:
	CStage();
	~CStage();

	//spflg:SP����t���O
	//dptype:DP�ڕW�ݒ��ʂőI��DP�ԍ�
	void Initialize(bool spflg,int dptype);

	//SP����DP�z�u�����邽�߂̊֐�
	void SPInitialize(void);


	void Update(CRectangle plrect);

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