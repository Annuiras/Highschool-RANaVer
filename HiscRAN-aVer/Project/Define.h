#pragma once
#include	"Mof.h"

//��ʂ̃T�C�Y
#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720


//�}�b�v�p�^�[���̐���ǉ��ł�

//todo:�����蔻�蒲�����ł�
//�����蔻�蒲���p
#define ITIZI_GENSUI_Y 12
#define ITIZI_GENSUI_Y2 

//todo:�X�e�[�W���𓝍������̂�DP�����ł͂悭�Ȃ�
//�}�b�vDP�p�^�[����
#define DP_INFO_PATTERN 15

//DP1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ���DP���{1�j
#define DP_INFO_STRUCT 15


//DP�^�C�v��`
enum tag_DP_TYPE
{
	DP_SCHOLASTIC,		//�w��
	DP_ACTION,			//�s����
	DP_IMAGINATION,		//�z����
	DP_COMMUNICATION,	//�R�~����
	DP_CHARM			//����

};

#pragma region ��Q���萔�Q

//��Q���^�C�v��`
enum tag_OBTYPE
{
	OB_DESK,		//��
	OB_TWODESK,		//�Q�i��
	OB_LOCKER		//���b�J�[
}; 

//�N���X��
#define OB_VOLUME 15

//�����E�c��
#define OB_DESK_WIDTH 131
#define OB_DESK_HEIGHT 172

//��i�����E�c��
#define OB_TOWDESK_WIDTH 131
#define OB_TOWDESK_HEIGHT 292

//���b�J�[���E�c��
#define OB_LOCKER_WIDTH 138
#define OB_LOCKER_HEIGHT 308

//�����`���荂��
#define OB_TOPBAR_HEIGHT 20+60


#pragma endregion




//����^�C�v��`
enum tag_BAR
{
	BAR_BIG,		//��
	BAR_MEDIUM,		//��
	BAR_SMALL		//��
};

//�n�ʍ���
#define GROUND_Y 700

//�}�b�v��Q���p�^�[����
#define OB_INFO_PATTERN 15

//��Q��1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ����Q�����{1�j
#define OB_INFO_STRUCT 10

//�}�b�v����p�^�[����
#define BAR_INFO_PATTERN 15

//����1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ��鑫�ꐔ�{1�j
#define BAR_INFO_STRUCT 10


//���݂���V�[��
enum tag_SCENENO {
	//�^�C�g�����
	SCENENO_TITLE,

	//���[�h�Z���N�g���
	SCENENO_SELECTMODE,

	//�Q�[���{��
	SCENENO_GAME,

	//�`���[�g���A�����
	SCENENO_TUTORIAL,

	//�I�v�V�������
	SCENENO_OPTION,

	//�M�������[���
	SCENENO_GALLERY,
};
