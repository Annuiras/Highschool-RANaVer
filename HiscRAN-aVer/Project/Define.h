#pragma once
#include	"Mof.h"
//////////////////////////////////////////////////////////
//�@�Q�[���S�̂Ŏg�p����萔�Ȃǂ�錾���Ă���ꏊ�ł��@//
//								   �@�@�@�@�@�@�@�@�@�@ //
//�@�쐬�ҁF�c���@  �@�@�@�@�@�@�@�@�@  �@�@�@�@�@�@�@//
//								   �@�@�@ �@�@�@�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@ �@�@�@�@�@�@�@//
//								   �@�@�@�@�@�@�@�@�@�@ //
//�@�ŏI�X�V�F2023/01/20		   �@�@�@ �@�@�@�@�@�@�@//
//////////////////////////////////////////////////////////


//�萔�錾

//��ʂ̃T�C�Y
#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720

//�t�F�[�h�A�E�g���x
#define FADE_OUT_SPEED 4

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
