#pragma once
#include "Stage.h"
#include "Define.h"

//vector���g�������I�z�񎎂������ǂ��܂��錾�ł��Ȃ�����

//�n�ʂɐݒu����`�Ȃ�v�Z�ŎZ�o�o���邩���ł������`���y�ɂȂ�
//s_stageAdp
//[]:�}�b�v�ꖇ�̏�񂪂������邩(���l�͏ȗ��\)
//[DP_INFO_STRUCT]:�}�b�v�ꖇ���̏��ɂ����\���̂����邩
//1���X�e�[�W��DP�z�u���
//��Q����ށi���j
//1:��
//2:�Q�i��
//�d�l��A�l�������ɂ��Ȃ��Ƃ��܂��\���ł��Ȃ�
//�X�N���[���l��0�ɂȂ�Ȃ�����0.0f�ŏo���̓G���[
//{0,0,100}->�I�[�����̖����A���̗v�f���Q�Ƃ���Ǝ��̃p�^�[���Ɉڍs
OB_info s_stageAOB[][OB_INFO_STRUCT] =
{
	//�}�b�v�p�^�[��0 S1
	{
		{316.0f,524.0f,OB_DESK},
		{447.0f,524.0f,OB_DESK},
		{578.0f,404.0f,OB_TWODESK},
		{709.0f,404.0f,OB_TWODESK},
		{1343.0f,524.0f,OB_DESK},
		{2091.0f,388.0f,OB_LOCKER},
		{2229.0f,388.0f,OB_LOCKER},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��1 S2
	{
		{288.0f,524.0f,OB_DESK},
		{419.0f,524.0f,OB_DESK},
		{550.0f,524.0f,OB_DESK},
		{680.0f,404.0f,OB_TWODESK},
		{810.0f,404.0f,OB_TWODESK},
		{940.0f,404.0f,OB_TWODESK},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��2 S3
	{
		{906.0f,524.0f,OB_DESK},
		{1038.0f,524.0f,OB_DESK},
		{2032.0f,404.0f,OB_TWODESK},
		{2166.0f,524.0f,OB_DESK},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��3 S4
	{
		{579.0f,519.0f,OB_TEXTBOOKCHEM},
		{710.0f,519.0f,OB_TEXTBOOKCHEM},
		{1747.0f,507.0f,OB_VAULTINGHORSE},
		{1964.0f,507.0f,OB_VAULTINGHORSE},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��4 S5
	{
		{548.0f,520.0f,OB_SCOTCHTAPE},
		{868.0f,520.0f,OB_SCOTCHTAPE},
		{1188.0f,398.0f,OB_TRACHCAN},
		{1319.0f,580.0f,OB_BLOACKBOARDERASER},
		{1569.0f,580.0f,OB_BLOACKBOARDERASER},

		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��5
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��6
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��7
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��8
	{
		{10000,0,OB_COUNT}

	},
	//�}�b�v�p�^�[��9
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��10
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��11
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��12
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��13
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��14
	{
		{10000,0,OB_COUNT}
	}

};