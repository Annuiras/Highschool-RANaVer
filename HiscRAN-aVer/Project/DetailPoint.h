#pragma once
#include "Mof.h"
#define DP_VOLUME	50

class DetailPoint
{
private:

	float dp_PosX;
	float dp_PosY;

	bool dp_Show;

	//DP�^�C�v
	//�P�F�w��
	//�Q�F�s����
	//�R�F�z����
	//�S�F�R�~����
	//�T�F����
	int dp_Type;

	//�X�e�[�^�X�㏸�l
	float dp_value;

	//�����蔻��
	float	dp_hitboxX;
	float	dp_hitboxY;

	//�X�s�[�h
	float dp_SpeedX;
	float dp_SpeedY;


	//DP������
	bool dp_attraction;


public:

	DetailPoint();
	~DetailPoint();

	void Render(void);
	void Initialize(void);

	void Start(float posy, int type);

	//[over]�F�v���C���[�̃I�[�o�[�l
	void Update(float over);
	void DebuggingRender(void);

	//DP���v���C���[�֔�΂�
	void UpdateAtraction(float px, float py);
	//DP������
	void UpdateFire(float sx, float sy);


	//DP�i�|�C���g�j�����蔻��
	bool CollosopnDP(CRectangle r);

	CRectangle GetRect(void) {

		return CRectangle(dp_PosX, dp_PosY,
			dp_PosX + dp_hitboxX, dp_PosY + dp_hitboxY);
	}

	//DP�̎�ނ��擾
	int Gettype(void) { return dp_Type; }

	//�\��true�F��\��false�t���O
	bool Getshow(void) { return dp_Show; }

	float Getvalue(void) { return dp_value; }

	//DP�̕\���؂�ւ�
	void Setshow(bool b) { dp_Show = b; }

};

