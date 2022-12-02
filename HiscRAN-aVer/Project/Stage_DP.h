#pragma once
#include "Stage.h"
#include "Define.h"
//vector���g�������I�z�񎎂������ǂ��܂��錾�ł��Ȃ�����


//s_stageAdp
//[]:�}�b�v�ꖇ�̏�񂪂������邩(���l�͏ȗ��\)
//[DP_INFO_STRUCT]:�}�b�v�ꖇ���̏��ɂ����\���̂����邩
//1���X�e�[�W��DP�z�u���

//�d�l��A�l�������ɂ��Ȃ��Ƃ��܂��\���ł��Ȃ�
//�X�N���[���l��0�ɂȂ�Ȃ�����0.0f�ŏo���̓G���[
//{0,0,100}->�I�[�����̖����A���̗v�f���Q�Ƃ���Ǝ��̃p�^�[���Ɉڍs
DP_info s_stageAdp[][DP_INFO_STRUCT] =
{
	//�}�b�v�p�^�[��0 S1
	{		
		{245.0f,336.0f,	DP_IMAGINATION},
		{611.0f,219.0f,	DP_CHARM},
		{1346.0f,339.0f,DP_ACTION},
		{1963.0f,207.0f,DP_SCHOLASTIC},
		{2402.0f,168.0f,DP_COMMUNICATION},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��1 S2
	{
		{253.0f,319.0f,DP_SCHOLASTIC},
		{820.0f,202.0f,DP_COMMUNICATION},
		{1253.0f,441.0f,DP_CHARM},
		{1291.0f,118.0f,DP_IMAGINATION},
		{1540.0f,513.0f,DP_CHARM},
		{1573.0f,188.0f,DP_IMAGINATION},
		{2009.0f,22.0f,DP_SCHOLASTIC},
		{2042.0f,486.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��2 S3
	{
		{328.0f,210.0f,DP_COMMUNICATION},
		{338.0f,536.0f,DP_ACTION},
		{1265.0f,48.0f,DP_SCHOLASTIC},
		{1258.0f,526.0f,DP_IMAGINATION},
		{1696.0f,526.0f,DP_CHARM},
		{2104.0f,196.0f,DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��3 S4
	{
		{104.0f,462.0f,	DP_IMAGINATION},
		{142.0f,270.0f,	DP_SCHOLASTIC},
		{268.0f,89.0f,	DP_SCHOLASTIC},
		{329.0f,549.0f,	DP_COMMUNICATION},
		{479.0f,119.0f,	DP_CHARM},
		{535.0f,360.0f,	DP_SCHOLASTIC},
		{737.0f,72.0f,	DP_ACTION},
		{803.0f,320.0f,	DP_COMMUNICATION},
		{843.0f,549.0f,	DP_CHARM},//
		{920.0f,17.0f,	DP_ACTION},
		{955.0f,320.0f,	DP_COMMUNICATION},
		{1287.0f,327.0f,DP_IMAGINATION},
		{1450.0f,327.0f,DP_IMAGINATION},
		{1509.0f,111.0f,DP_CHARM},
		{1509.0f,550.0f,DP_ACTION},
		{1623.0f,326.0f,DP_CHARM},
		{1935.0f,4.0f,	DP_SCHOLASTIC},
		{1962.0f,366.0f,DP_COMMUNICATION},
		{2218.0f,554.0f,DP_IMAGINATION},
		{2308.0f,88.0f,	DP_ACTION},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��4 S5
	{
		{58.0f,292.0f,	DP_IMAGINATION},
		{180.0f,25.0f,	DP_IMAGINATION},
		{278.0f,292.0f,	DP_COMMUNICATION},
		{400.0f,25.0f,	DP_COMMUNICATION},
		{499.0f,292.0f,	DP_SCHOLASTIC},
		{621.0f,25.0f,	DP_SCHOLASTIC},
		{720.0f,292.0f,	DP_ACTION},
		{842.0f,25.0f,	DP_ACTION},
		{939.0f,291.0f,	DP_CHARM},
		{1061.0f,24.0f,	DP_CHARM},
		{1485.0f,418.0f,DP_ACTION},
		{1605.0f,187.0f,DP_IMAGINATION},
		{1704.0f,471.0f,DP_CHARM},
		{1825.0f,187.0f,DP_SCHOLASTIC},
		{2046.0f,187.0f,DP_SCHOLASTIC},

		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��5
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��6
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��7
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��8
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��9
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��10
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��11
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��12
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��13
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
	//�}�b�v�p�^�[��14
	{
		{272.0f,341.0f,	DP_IMAGINATION},
		{756.0f,229.0f,	DP_CHARM},
		{1284.0f,222.0f,DP_ACTION},
		{1975.0f,231.0f,DP_COMMUNICATION},//DP_IMAGINATION�ꎞ�I�ȕύX
		{2462.0f,66.0f,	DP_SCHOLASTIC},
		{10000,0,DP_COUNT}
	},
		//�}�b�v�p�^�[��15  SP�A�C�e���o��
	{
		{300.0f, 350.0f, DP_SP_ITEM},	//����SP�A�C�e���̃e�N�X�`���͖��͂Ɠ����ɂ��Ă܂�
		{ 700.0f,229.0f,	DP_CHARM },
		{ 1500.0f,300.0f,DP_IMAGINATION },
		{ 1775.0f,231.0f,DP_COMMUNICATION },
		{ 2000.0f,66.0f,	DP_SCHOLASTIC },
		{ 10000,0,DP_COUNT }
	},
		//�}�b�v�p�^�[��16  SP�z�u1
	{
		{250.0f,350.0f,DP_CHARM},
		{536.0f,229.0f,	DP_CHARM},
		{884.0f,302.0f,DP_CHARM},
		{1775.0f,231.0f,DP_CHARM},
		{1862.0f,66.0f,	DP_CHARM},
		{10000,0,DP_COUNT}
	},
			//�}�b�v�p�^�[��17  SP�z�u2
	{
		{180.0f,350.0f,DP_ACTION},
		{556.0f,229.0f,	DP_ACTION},
		{584.0f,222.0f,DP_ACTION},
		{1675.0f,231.0f,DP_ACTION},
		{1762.0f,66.0f,	DP_ACTION},
		{10000,0,DP_COUNT}
	},
			//�}�b�v�p�^�[��18  SP�z�u3
	{
		{270.0f, 350.0f, DP_ACTION},
		{796.0f,229.0f,	DP_IMAGINATION },
		{984.0f,222.0f,DP_CHARM },
		{1375.0f,231.0f,DP_SCHOLASTIC },
		{2162.0f,66.0f,	DP_COMMUNICATION },
		{10000,0,DP_COUNT }
	},
			//�}�b�v�p�^�[��19  SP�z�u4
	{
		{ 270.0f, 350.0f, DP_IMAGINATION},
		{ 796.0f,229.0f,	DP_CHARM },
		{ 984.0f,222.0f,DP_ACTION },
		{ 1375.0f,231.0f,DP_COMMUNICATION},
		{ 2162.0f,66.0f,DP_ACTION },
		{ 10000,0,DP_COUNT }
	},
			//�}�b�v�p�^�[��20  SP�z�u5
	{
		{270.0f, 350.0f, DP_ACTION},
		{796.0f,229.0f,	DP_COMMUNICATION },
		{984.0f,222.0f,DP_CHARM},
		{1375.0f,231.0f,DP_IMAGINATION },
		{2162.0f,66.0f,	DP_SCHOLASTIC },
		{10000,0,DP_COUNT }
	}

};