//////////////////////////////////////////////
//	�Q�[���̏����Ǘ�����v���O�����ł��@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �@�@�@�@�@�@�@�@�@�@ �@  //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Game.h"
#include "Define_Clear.h"

//�Q�[�����󂯓n���N���X
class CGameProgMgmt
{

private:

	//�Q�[���N���A����DP�̎擾���ۑ��p
	//0:�w��
	//1:�s����
	//2:�z����
	//3:�R�~����
	//4:����
	int Game_DPNum[DP_COUNT];
	int Game_SP_DPNum;

	//�Q�[���I�[�o�[�����t���O
	bool Game_Over_HP;

	//DP�ڕW�ݒ��ʁF�I��DP�ԍ�
	int DPdec_type;

	//DP�ڕW�ݒ��ʁFSP����t���O
	bool DPdec_SPflg;

	//�I�v�V������ʁF�{�^���ʒu�ۑ�
	//0:BGM
	//1:SE
	float Option_Button_Pos[2];

	//�M�������[����󋵂�ۑ�
	bool Gallery_flg[15];

public:
	CGameProgMgmt(); 
	~CGameProgMgmt();

	//������
	void Initialize(void);

	//DP�ڕW�ݒ��ʁF�I��DP���Z�b�g
	void SetDPdec_type(int type);
	//�Q�[����ʁF�I��DP���Q�b�g
	int GetDPdec_type(void);

	//DP�I����ʉ�ʁFSP�t���O���Z�b�g
	void SetDPdec_SPflg(bool b);
	//�Q�[����ʁFSP�t���O���Q�b�g
	bool GetDPdec_SPflg(void);

	//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Z�b�g
	void SetGame_Over_HP(bool b);
	//�Q�[���I�[�o�[��ʁF�Q�[���I�[�o�[�����t���O�Q�b�g
	bool GetGame_Over_HP(void);

	//�Q�[����ʁFDP�擾�����Z�b�g
	void SetGame_DPNum(int DP[]);
	//�Q�[����ʁFSP_DP�擾�����Z�b�g
	void SetGame_SP_DPNum(int SPDP);

	//�N���A��ʁFDP�擾����Ԃ�
	int* Get_DPNum(void);

	//�N���A��ʁFSP_DP�擾����Ԃ�
	int Get_SP_DPNum(void);

	//�I�v�V������ʁF�{�^���ʒu���Z�b�g
	void SetOption_Button_Pos(float BGM,float SE);

	//�I�v�V������ʁF�{�^���ʒu���Q�b�g
	//0:BGM
	//1:SE
	float GetOption_Button_Pos(int i);

	//�M�������[��ʁF����󋵂��Z�b�g
	//i:�e�p�ԍ�
	//b:�Z�b�g����t���O
	void SetGallery_flg(int i, bool b);

	//�M�������[��ʁF����󋵂��Q�b�g
	//i:�e�p�ԍ�
	bool GetGallery_flg(int i);

};

