#pragma once

//�~���[�W�b�N�萔

//�Ǘ�SE�̐�
#define		SE_MGMT_COUNT 5

//SE��ޗ�
enum tag_SE_TYPE {

	//�Q�[��,�I�[�o�[,�N���A���
	SE_T_JUMP,			//�W�����v���
	SE_T_GREAT_JUMP,	//�O���[�g�W�����v
	SE_T_JUMP_LANDING,	//�W�����v���n
	SE_T_DP_HIT,		//DP_GET���
	SE_T_HIT,			//��e_���
	SE_T_GAMEOVER,		//Gameover_���
	SE_T_GAMECLEAR,		//�N���A_���

	//DP�I�����
	SE_T_SE_DEC,	//DP�J�[�\���ړ���

	//�M�������[���
	SE_T_GALL_CURSORMOVE,		//�M�������[_�J�[�\���ړ����1

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

	//���w�������
	BGMT_TUTORIAL,

	//�Q�[��,�N���A���
	BGMT_STAGE,		//���
	//BGMT_STAGE_SP_1,	//SP���
	BGMT_CLEAR,			//�N���A���

	//DP�I�����
	BGMT_DPDECISION,

	//�M�������[���
	BGMT_GALLERY,		//���

	//���[�h�Z���N�g,�I�v�V�������
	BGMT_MOOP,			//���

	BGM_TYPE_COUNT		//����
};
