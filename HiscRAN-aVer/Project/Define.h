#pragma once
#include	"Mof.h"

//todo:�}�b�v�p�^�[���̐���ǉ��ł�

//�}�b�vDP�p�^�[����
#define DP_INFO_PATTERN 15

//DP1�p�^�[���̗v�f��
#define DP_INFO_STRUCT 11

//�}�b�v��Q���p�^�[����
#define OB_INFO_PATTERN 15

//��Q��1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ����Q�����{1�j
#define OB_INFO_STRUCT 4

//�}�b�v����p�^�[����
#define BAR_INFO_PATTERN 15

//����1�p�^�[���̗v�f��
//�i1�}�b�v���ɂ��鑫�ꐔ�{1�j
#define BAR_INFO_STRUCT 4


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
