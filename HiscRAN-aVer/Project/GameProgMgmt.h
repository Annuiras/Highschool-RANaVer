#pragma once
#include "Define.h"

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

	//�Q�[���I�[�o�[�����t���O
	bool Game_Over_HP;

public:
	CGameProgMgmt(); 
	~CGameProgMgmt();

	//������
	void Initialize(void);

	//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Z�b�g
	void SetGame_Over_HP(bool b);
	//�Q�[����ʁF�Q�[���I�[�o�[�����t���O�Q�b�g
	bool GetGame_Over_HP(void);

	//�Q�[����ʁFDP�擾�����Z�b�g
	void SetGame_DPNum(int DP[]);

	//�Q�[����ʁFDP�擾�����Q�b�g
	int* GetGame_DPNum(void);

};

