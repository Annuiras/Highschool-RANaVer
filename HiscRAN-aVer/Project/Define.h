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
#define MAP_SP_ITEM_PATTERN_NUM 1

//�X�e�[�W�ω�����w�i����
#define SATGE_CHANGE_BAK 20

//�X�e�[�W�N���A�̔w�i����
#define STAGE_CLEAR_BAK 31

//�X�e�[�W�X�N���[���X�s�[�h
#define STAGE_SPEED 7

//�d��
#define  GRAVITY	0.7f

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
	DP_SP_ITEM,			//SP�A�C�e��
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
	OB_TEXTBOOKCHEM,		//���ȏ�_����
	OB_VAULTINGHORSE,		//���є�
	OB_SCOTCHTAPE,			//�Z���n���e�[�v
	OB_BLOACKBOARDERASER,	//������
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

#pragma region ����萔�Q

//����^�C�v��`
enum tag_BAR
{
	BAR_BIG,		//��
	BAR_MEDIUM,		//��
	BAR_SMALL,		//��
	BAR_COUNT		//�����i�I�[�v�f�j
};

//����1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ��鑫�ꐔ�{1�j
#define BAR_INFO_STRUCT 10


#pragma endregion

#pragma region �v���C���[�萔�Q

//�v���C���[�����ʒu
#define PLAYER_START_POS_X 50
#define PLAYER_START_POS_Y 500


//��W�����v�l
#define  BIGJUMP -17.0f
//���W�����v�l
#define  SMALLJUMP	-17.0f

//�ő�X���C�f�B���O�l
#define  SLIDING	100
//�X���C�f�B���O�N�[���^�C��
#define  SLIDINGCOOL 60

//�v���C���[�����蔻��
#define PLAYER_HIT_X 130
#define PLAYER_HIT_Y 185

//�������蔻��
#define PLAYER_LEGS_Y 100

//�����蔻�蒲����
#define PLAYER_ADMENT_SPACE 80

#pragma endregion

#pragma region �ŏI�e�p��ʒ萔�Q

#define CHART_SIZE 248			// �`���[�g���a
#define CHART_CENTER_X 325	    // �`���[�g���S���W X
#define CHART_CENTER_Y 478	    // �`���[�g���S���W Y

#define MAX_STATUS 100			// �X�e�[�^�X�ő�l
#define ITEM_NUM 5				// �X�e�[�^�X��

#pragma endregion


//�n�ʍ���
#define GROUND_Y 700

//�Ǘ��G�t�F�N�g�̐�
#define		EFFECT_MGMT_COUNT 5

//�Ǘ�SE�̐�
#define		SE_MGMT_COUNT 5


//SE��ޗ�
enum tag_SE_TYPE {

	SET_PAWANN,		//�ۂ�[��
	SET_CHIME,		//�`���C��
	SET_TYPE_COUNT,	//����
};

//BGM��ޗ�
enum tag_BGM_TYPE
{
	BGMT_OP,	//�I�v�V�������BGM

	BGMT_TYPE_COUNT
};

//�G�t�F�N�g��ޗ�
enum tag_EFFECTTYPE {
	EFC_GET_DP,						//DP�擾

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

//���݂���V�[��
enum tag_SCENENO {
	//�^�C�g�����
	SCENENO_TITLE,

	//���[�h�Z���N�g���
	SCENENO_SELECTMODE,

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
};
