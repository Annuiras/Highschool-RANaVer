#pragma once
#include "Define.h"

//�Q�[�����󂯓n���N���X
class CGameProgMgmt
{

private:

	//�Q�[���N���A����DP�̍��v�擾���ۑ��p
	//0:�w��
	//1:�s����
	//2:�z����
	//3:�R�~����
	//4:����
	int Game_DPNum[DP_COUNT];

	//�Q�[���I�[�o�[�����t���O
	bool Game_Over_HP;

	//DP�ڕW�ݒ��ʁF�I��DP�ԍ�
	int DPdec_type;

	//�I�v�V������ʁF�{�^���ʒu�ۑ�
	//0:BGM
	//1:SE
	float Option_Button_Pos[2];

public:
	CGameProgMgmt(); 
	~CGameProgMgmt();

	//������
	void Initialize(void);

	//DP�ڕW�ݒ��ʁF�I��DP���Z�b�g
	void SetDPdec_type(int type);
	//DP�ڕW�ݒ��ʁF�I��DP���Q�b�g
	int GetDPdec_type(void);

	//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Z�b�g
	void SetGame_Over_HP(bool b);
	//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Q�b�g
	bool GetGame_Over_HP(void);

	//�Q�[����ʁFDP���v�擾�����Z�b�g
	void SetGame_DPNum(int DP[]);
	//�Q�[����ʁFDP���v�擾�����Q�b�g
	int* GetGame_DPNum(void);

	//�I�v�V������ʁF�{�^���ʒu���Z�b�g
	void SetOption_Button_Pos(float BGM,float SE);

	//�I�v�V������ʁF�{�^���ʒu���Q�b�g
	//0:BGM
	//1:SE
	float GetOption_Button_Pos(int i);

};

