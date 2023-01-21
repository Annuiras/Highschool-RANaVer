#pragma once

////////////////////////////////////////////////////////
//�@�Q�[���{�҂Ŏg�p����萔��錾���Ă���ꏊ�ł��@  //
//								   �@�@�@�@�@�@�@�@�@ //
//�@�쐬�ҁF�c���@  �@�@�@�@�@�@�@�@�@  �@�@�@�@�@  //
//								   �@�@�@ �@�@�@�@�@  //
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@ �@�@�@�@�@  //
//								   �@�@�@�@�@�@�@�@   //
//�@�ŏI�X�V�F2023/01/20		   �@�@�@ �@�@�@�@�@  //
////////////////////////////////////////////////////////

//�}�b�v�p�^�[����
#define MAP_INFO_PATTERN 21

//�P�X�e�[�W���̃}�b�v�p�^�[����
#define SATAGE_MAP_PATTERN 15

//SP�J�n�}�b�v�p�^�[����(���p�^�[����)
#define MAP_SP_START_PATTERN 1

//SP�X�e�[�W�p�^�[����
#define MAP_SP_LENGTH 2

//�X�e�[�W�N���A�̔w�i����
#define STAGE_CLEAR_BAK 31

//�X�e�[�W�X�N���[���X�s�[�h
#define STAGE_SPEED 7

//�d��
#define  GRAVITY	0.7f

//�n�ʍ���
#define GROUND_Y 700

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

//�G���
enum tag_ENEMY
{
	ENEMY_1,
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

#pragma region DP�萔�Q

//DP1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ���DP���{1�j
#define DP_INFO_STRUCT 50

//DP�^�C�v��`
enum tag_DP_TYPE
{
	DP_SCHOLASTIC,		//�w��
	DP_ACTION,			//�s����
	DP_IMAGINATION,		//�z����
	DP_COMMUNICATION,	//�R�~����
	DP_CHARM,			//����

	DP_COUNT,			//��ޑ����i�I�[�v�f�j	

	DP_SP_SCHOLASTIC,	//SP�w��
	DP_SP_ACTION,		//SP�s����
	DP_SP_IMAGINATION,	//SP�z����
	DP_SP_COMMUNICATION,//SP�R�~����
	DP_SP_CHARM,		//SP����

};


#pragma endregion

//�X�e�[�W�̏�Ԃ��`
enum class  tag_StageSituation
{
	STAGE_SP_YET,			//SP�łȂ�
	STAGE_SP_STILL,			//SP�̓r��
};
