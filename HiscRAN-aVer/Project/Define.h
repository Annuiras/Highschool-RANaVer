#pragma once
#include	"Mof.h"

//��ʂ̃T�C�Y
#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720

//�}�b�v�p�^�[����
#define MAP_INFO_PATTERN 21

//�P�X�e�[�W���̃}�b�v�p�^�[����
#define SATAGE_MAP_PATTERN 15

//SP�A�C�e������}�b�v�p�^�[���̏o���ʒu(���}�b�v��)
#define MAP_SP_ITEM_PATTERN_NUM 100

//�X�e�[�W�ω�����w�i����
#define SATGE_CHANGE_BAK 200

//�X�e�[�W�N���A�̔w�i����
#define STAGE_CLEAR_BAK 31

//�X�e�[�W�X�N���[���X�s�[�h
#define STAGE_SPEED 7

//�d��
#define  GRAVITY	0.7f

//�n�ʍ���
#define GROUND_Y 700

//�t�F�[�h�A�E�g���x
#define FADE_OUT_SPEED 4

#pragma region DP�萔�Q

//DP1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ���DP���{1�j
#define DP_INFO_STRUCT 25

//DP�^�C�v��`
enum tag_DP_TYPE
{
	DP_SCHOLASTIC,		//�w��
	DP_ACTION,			//�s����
	DP_IMAGINATION,		//�z����
	DP_COMMUNICATION,	//�R�~����
	DP_CHARM,			//����
	DP_COUNT			//�����i�I�[�v�f�j	
};


#pragma endregion

#pragma region ��Q���萔�Q

//��Q���^�C�v��`
enum tag_OBTYPE
{
	OB_DESK,				//��
	OB_TWODESK,				//�Q�i��
	OB_TRACHCAN,			//���ݔ�
	OB_LOCKER,				//���b�J�[
	OB_TEXTBOOKNL,			//���ȏ�_����
	OB_TEXTBOOKMATH,		//���ȏ�_���w
	OB_TEXTBOOKCHEM,		//���ȏ�_����
	OB_TEXTBOOKSOC,			//���ȏ�_�Љ�
	OB_TEXTBOOKENG,			//���ȏ�_�p��
	OB_VAULTINGHORSE,		//���є�
	OB_SCOTCHTAPE,			//�Z���n���e�[�v
	OB_BLOACKBOARDERASER,	//������
	OB_SEAWEED,				//�X�e�B�b�N�̂�
	OB_SMARTPHONE1,			//�X�}�z�P
	OB_ERASER,				//�����S��
	OB_SMARTPHONEVERTICAL,	//�X�}�z�c
	OB_COUNT				//�����i�I�[�v�f�j
}; 

//�N���X��
#define OB_VOLUME 15

//��Q��1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ����Q�����{1�j
#define OB_INFO_STRUCT 10

//��Q�������蔻�荂�������p
#define OB_HITRECT_SPACE_Y 12

//�����`���荂��
#define OB_TOPBAR_HEIGHT 80


#pragma endregion

#pragma region �G�萔�Q

//�N���X��
#define		ENEMY_VOLUME 10

//�G1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ���G���{1�j
#define ENEMY_INFO_STRUCT 5

//�G�����蔻��
#define		ENEMY_SIZE_WIDTH	70	//��
#define		ENEMY_SIZE_HEIGHT	185	//�c


enum tag_ENEMY
{
	ENEMY_1,
	ENEMY_2, 
	ENEMY_COUNT,//�����i�I�[�v�f�j
};

#pragma endregion

#pragma region ����萔�Q

//�N���X��
#define BAR_VOLUME	5

//��
#define BAR_BIG_WIDTH	800
#define BAR_BIG_HEIGHT	40

//��
#define BAR_MEDIUM_WIDTH	500
#define BAR_MEDIUM_HEIGHT	25

//����^�C�v��`
enum tag_BAR
{
	BAR_BIG,		//��
	BAR_MEDIUM,		//��
	BAR_COUNT		//�����i�I�[�v�f�j
};

//����1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ��鑫�ꐔ�{1�j
#define BAR_INFO_STRUCT 10



#pragma endregion

#pragma region �v���C���[�萔�Q

//HP
#define START_HP 5

//���G����
#define INVINCIBLE_TIME 60

//��W�����v�l
#define  BIGJUMP -17.0f
//���W�����v�l
#define  SMALLJUMP	-15.0f

//�ő�X���C�f�B���O�l
#define  SLIDING	100
//�X���C�f�B���O�N�[���^�C��
#define  SLIDINGCOOL 60

//�v���C���[�����蔻��
#define PLAYER_HIT_X 70
#define PLAYER_HIT_Y 185

//�������蔻��
#define PLAYER_LEGS_Y 100

//�����蔻�蒲����
#define PLAYER_ADMENT_SPACE 80

//�v���C���[�����ʒu
#define PLAYER_START_POS_X 50
#define PLAYER_START_POS_Y GROUND_Y - PLAYER_HIT_Y


#pragma endregion

#pragma region �N���A��ʒ萔�Q

#define CHART_SIZE 248			// �`���[�g���a
#define CHART_CENTER_X 325	    // �`���[�g���S���W X
#define CHART_CENTER_Y 478	    // �`���[�g���S���W Y

#define MAX_STATUS 100			// �X�e�[�^�X�ő�l
#define ITEM_NUM 5				// �X�e�[�^�X��

#define DIFFERENCE_NUM 15		// ��_�˔j�p,2�ʂƂ̍�����ȏ�̏ꍇ��_�˔j

#pragma endregion 

//�ŏI�e�p�ԍ�
enum tag_LAST_TEXTURE_TYPE
{
	LT_ANEGO,		//�o��
	LT_NINKIMONO,	//�N���X�̐l�C��
	LT_GYARU,		//�M����
	LT_OUEN,		//�����c��
	LT_TOSYO,		//�}�����̒�
	LT_OTAKU,		//�I�^�N
	LT_INFLUENCER,	//�C���t���G���T�[
	LT_IINTYOU,		//�ψ���
	LT_TAKANE,		//����̉�
	LT_YABKI,		//�����L�[
	LT_SUPERLADY,	//�X�[�p�[���f�B
	LT_OTYOUSI,		//�����q��
	LT_BUNGAKU,		//���w����
	LT_TYUNI,		//�~��a
	LT_KAMITAIOU,	//�_�Ή�
};

//�Ǘ��G�t�F�N�g�̐�
#define		EFFECT_MGMT_COUNT 5

//�Ǘ�SE�̐�
#define		SE_MGMT_COUNT 5

//DP�I�����:�I������
#define DPDECISION_MENUCNT 5

//SE��ޗ�
enum tag_SE_TYPE {

	//�Q�[��,�I�[�o�[,�N���A���
	SE_T_JUMP,			//�W�����v���
	SE_T_GREAT_JUMP,	//�O���[�g�W�����v
	SE_T_JUMP_LANDING,	//�W�����v���n
	SE_T_HALLDASH,		//�w�Z�̘L���𑖂�
	SE_T_DP_HIT,		//DP_GET���
	//SE_T_HIT_LOCKER,	//��Q�����b�J_���1
	//SE_T_HIT_DESK1,		//��Q����_���1
	//SE_T_HIT_DESK2,		//��Q����_���2
	//SE_T_HIT_DESK3,		//��Q����_���3
	//SE_T_HIT_1,			//��e_���1
	SE_T_HIT,			//��e_���
	SE_T_GAMEOVER,		//Gameover_���
	SE_T_GAMECLEAR,		//�N���A_���

	//�M�������[���
	SE_T_GALL_CURSORMOVE,		//�M�������[_�J�[�\���ړ����1
	SE_T_UNOPENED,			//���J���I����_���1

	//���[�h�Z���N�g,�I�v�V�������
	SE_T_MOOP_CURSORMOVE,	//���[�h�Z���N�g�A�I�v�V������ʃJ�[�\���ړ�_���
	SE_T_DECISION,			//����_���
	SE_T_OPTION_CHIME,		//�I�v�V�����`���C��

	SE_TYPE_COUNT,		//����
};

//BGM��ޗ�
enum tag_BGM_TYPE
{
	//�^�C�g�����
	BGMT_TITLE,//���

	//�Q�[��,�I�[�o�[,�N���A���
	BGMT_STAGE,		//���
	//BGMT_STAGE_SP_1,	//SP���
	BGMT_CLEAR,			//�N���A���

	//�M�������[���
	BGMT_GALLERY,		//���

	//���[�h�Z���N�g,�I�v�V�������
	BGMT_MOOP,			//���

	BGM_TYPE_COUNT		//����
};

//�G�t�F�N�g��ޗ�
enum tag_EFFECTTYPE {

	EFC_GET_SCHOLASTIC,		//DP�w�͎擾
	EFC_GET_ACTION,			//DP�s���͎擾
	EFC_GET_IMAGINATION,	//DP�z���͎擾
	EFC_GET_COMMUNICATION,	//DP�R�~���͎擾
	EFC_GET_CHARM,			//DP���͎擾

	EFC_GET_SCHOLASTIC_AROOW,		//DP�w�͎擾�����
	EFC_GET_ACTION_AROOW,			//DP�s���͎擾�����
	EFC_GET_IMAGINATION_AROOW,		//DP�z���͎擾�����
	EFC_GET_COMMUNICATION_AROOW,	//DP�R�~���͎擾�����
	EFC_GET_CHARM_AROOW,			//DP���͎擾�����

	EFC_TYPE_COUNT,
};

//�X�e�[�W�̏�Ԃ��`
enum class  tag_StageSituation
{
	STAGE_SP_YET,			//�܂�SP�X�e�[�W�łȂ�
	STAGE_SP_START,			//SP���n�܂�����
	STAGE_SP_STILL,			//SP�̓r��
	STAGE_SP_IMMEDIATELY,	//SP���I��������
	STAGE_SP_ALREADY		//SP���I��������
};

//���j���[�̎�ނ��`
enum tag_MenuType 
{
	MENUT_END,		//�I�����j���[
	MENUT_GAME_END,	//�Q�[����ʏI�����j���[
	MENUT_DPCONFIRM,//DP�I���m�胁�j���[
};

//���[�h��Ԃ��`
enum tag_LoadSituation {

	LOAD_YET,		//���[�h�O
	LOAD_COMP,		//���[�h����
	LOAD_DONE,		//���[�h��:��������
	LOAD_ERROR,		//���[�h�G���[
};

//�V�[�����ڏ�
enum tag_SceneSituation
{
	FADE_IN,		//�t�F�[�h�C��
	FADE_OUT,		//�t�F�[�h�A�E�g	
	FADE_NOT,		//���ڂȂ�
	FADE_NEXT		//���̃V�[����
	
};

//���[�h���K�v�V�[��
//���݂���V�[��
enum tag_SCENENO {
	//�^�C�g�����
	SCENENO_TITLE,

	//���[�h�Z���N�g���
	SCENENO_SELECTMODE,

	//DP�ڕW�ݒ���
	SCENENO_DPDECISION,

	//�Q�[���{��
	SCENENO_GAME,

	//�Q�[���I�[�o�[���
	SCENENO_GAMEOVER,

	//�Q�[���N���A���
	SCENENO_GAMECLEAR,

	//�`���[�g���A�����
	SCENENO_TUTORIAL,

	//�I�v�V�������
	SCENENO_OPTION,

	//�M�������[���
	SCENENO_GALLERY,

	//�G�t�F�N�g
	RESOURCE_EFFECT,

	//�~���[�W�b�N
	RESOURCE_MUSIC,

	//����
	SCENE_COUNT
};
