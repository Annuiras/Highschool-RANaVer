#pragma once
#include "Mof.h"

//���ʂɑ��݂���ő�DP
#define DP_VOLUME	20

class DetailPoint
{
private:

	float dp_PosX;
	float dp_PosY;

	bool dp_Show;

	//DP�e�N�X�`��
	CTexture* dp_texture;

	//DP�^�C�v
	//0�F�w��
	//1�F�s����
	//2�F�z����
	//3�F�R�~����
	//4�F����
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

	//DP�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* dptex);

	//�\���J�n
	void Start(float posy, int type);

	//[over]�F�v���C���[�̃I�[�o�[�l
	void Update(float over);
	void RenderDebugging(void);

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

