//////////////////////////////////////////////
//	��Q���̔z�u���ł�			�@�@�@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "Stage.h"

//�X�e�[�W�̏�Q���z�u���

//�d�l:�l�������ɂ��Ȃ��Ƃ��܂��\���ł��܂���
//�X�N���[���l��0�ɂȂ�Ȃ�����0.0f�ŏo���̓G���[
//{10000,0,OB_COUNT}->�I�[�����̖����A���̗v�f���Q�Ƃ���Ǝ��̃p�^�[���Ɉڍs
OB_info s_stageOB[][OB_INFO_STRUCT] =
{
	//�}�b�v�p�^�[��0 S1
	{
		{889.0f,398.0f,OB_TRACHCAN},
		{1020.0f,398.0f,OB_TRACHCAN},
		{1151.0f,398.0f,OB_TRACHCAN},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��1 S2
	{
		{360.0f,519.0f,OB_TEXTBOOKSOC},
		{491.0f,519.0f,OB_TEXTBOOKSOC},
		{622.0f,519.0f,OB_TEXTBOOKENG},
		{1274.0f,519.0f,OB_TEXTBOOKNL},
		{1956.0f,519.0f,OB_TEXTBOOKCHEM},
		{2087.0f,519.0f,OB_TEXTBOOKMATH},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��2 S3
	{
		{948.0f,520.0f,OB_SCOTCHTAPE},
		{1268.0f,520.0f,OB_SCOTCHTAPE},
		{1588.0f,396.0f,OB_SEAWEED},
		{1698.0f,396.0f,OB_SEAWEED},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��3 S4
	{
		{660.0f,460.0f,OB_SMARTPHONE1},
		{1090.0f,570.0f,OB_ERASER},
		{1290.0f,570.0f,OB_ERASER},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��4 S5
	{
		{1771.0f,383.0f,OB_LOCKER},
		{1909.0f,507.0f,OB_VAULTINGHORSE},

		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��5 S6
	{
		{650.0f,580.0f,OB_BLOACKBOARDERASER},
		{900.0f,580.0f,OB_BLOACKBOARDERASER},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��6 S7
	{
		{311.0f,520.0f,OB_TEXTBOOKMATH},
		{902.0f,520.0f,OB_TEXTBOOKMATH},
		{1033.0f,520.0f,OB_TEXTBOOKMATH},
		{1587.0f,520.0f,OB_SCOTCHTAPE},
		{1907.0f,395.0f,OB_SEAWEED},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��7 S8
	{
		{434.0f,508.0f,OB_VAULTINGHORSE},
		{651.0f,508.0f,OB_VAULTINGHORSE},
		{1007.0f,579.0f,OB_BLOACKBOARDERASER},
		{1257.0f,579.0f,OB_BLOACKBOARDERASER},
		{1507.0f,398.0f,OB_TRACHCAN},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��8 S9
	{
		{320.0f,519.0f,OB_TEXTBOOKNL},
		{452.0f,519.0f,OB_TEXTBOOKMATH},
		{583.0f,519.0f,OB_TEXTBOOKENG},
		{1123.0f,570.0f,OB_ERASER},
		{1324.0f,570.0f,OB_ERASER},
		{10000,0,OB_COUNT}

	},
	//�}�b�v�p�^�[��9 S10
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��10 S11
	{
		{1221.0f,460.0f,OB_SMARTPHONE1},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��11 S12
	{
		{629,519,OB_SCOTCHTAPE},
		{949,519,OB_SCOTCHTAPE},
		{1269,382,OB_LOCKER},
		{1408,382,OB_LOCKER},
		{1546,382,OB_LOCKER},
		{1684,259,OB_SMARTPHONEVERTICAL},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��12 S13
	{

		{438,507,OB_VAULTINGHORSE},
		{1526,507,OB_VAULTINGHORSE},
		{1743,570,OB_ERASER},
		{1943,570,OB_ERASER},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��13 S14
	{

		{474,382,OB_LOCKER},
		{612,459,OB_SMARTPHONE1},
		{1042,579,OB_BLOACKBOARDERASER},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��14 S15
	{
		{1259.0f,519.0f,OB_TEXTBOOKSOC},
		{1390.0f,519.0f,OB_TEXTBOOKCHEM},
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��15 SP1
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��16 SP2
	{
		{10000,0,OB_COUNT}
	},
	//�}�b�v�p�^�[��17 �Ō�
	{
		{10000,0,OB_COUNT}
	},
};