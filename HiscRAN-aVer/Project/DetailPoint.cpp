#pragma once
#include "DetailPoint.h"


DetailPoint::DetailPoint() :
	dp_PosX(0.0f),
	dp_PosY(0.0f),
	dp_Show(false),
	dp_hitboxX(0.0f),
	dp_hitboxY(0.0f),
	dp_value(0.0f),
	dp_SpeedX(0.0f),
	dp_SpeedY(0.0f),
	dp_attraction(false),
	dp_texture(NULL),
	dp_Type(0)
{};

DetailPoint::~DetailPoint() {



};

//�e�N�X�`�����Z�b�g
void DetailPoint::SetTexture(CTexture* dptex) {

	dp_texture = dptex;

}


//DP�̐��l������
void DetailPoint::Initialize(void) {

	dp_PosX = 0;
	dp_PosY = 0;
	dp_Type = 0;
	dp_hitboxX = 0;
	dp_hitboxY = 0;
	dp_value = 0.5;
	dp_Show = false;
}


//�\�����߂̏���
void DetailPoint::Start(float posy, int type) {

	dp_PosX = g_pGraphics->GetTargetWidth();

	dp_PosY = posy;

	//�R�C�����
	dp_Type = type;

	//�\���t���O
	dp_Show = true;

	//todo:�摜�T�C�Y�ƍ��킹��
	dp_hitboxX = dp_texture->GetWidth();
	dp_hitboxY = dp_texture->GetHeight();


}


void DetailPoint::Update(float over) {

	//�\�����Ɏ��s
	if (dp_Show)
	{
		dp_PosX -= over;

		//��ʍ��[�ŏ���
		if (dp_PosX + dp_hitboxX < 0) {
			dp_Show = false;
		}
	}

	//V�������Ƃ��؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		//DP�z���񂹃t���O
		if (!dp_attraction)
		{
			dp_attraction = true;
		}
		else
		{
			dp_attraction = false;
		}
	}


}


void DetailPoint::UpdateFire(float sx, float sy)
{
	dp_SpeedX = sx;
	dp_SpeedY = sy;
	//*30�͑��x����Ȃ����ߎg���Ă܂�
	dp_PosX -= dp_SpeedX * 30;
	dp_PosY -= dp_SpeedY * 30;
}



//�Q�[��PG�̋��ȏ��TP100�Q��
//px,py�F�v���C���[��XY���W
void DetailPoint::UpdateAtraction(float px, float py)
{
	//�e�̔��ˈʒu
	float stx = dp_PosX;
	float sty = dp_PosY;

	//�J�n�n�_ - �v���C���[�̈ʒu �����v�Z
	float dx = stx - px;
	float dy = sty - py;

	//�����v�Z
	float d = sqrt(dx * dx + dy * dy);
	if (d <= 0)
	{
		return;
	}
	//���K���Ő�����1�ɂ��邱�Ƃő��x����
	dx /= d;
	dy /= d;
	if (dp_attraction)
	{
		UpdateFire(dx, dy);
	}
}



//DP�Ɠ����蔻��
bool DetailPoint::CollosopnDP(CRectangle r) {

	if (GetRect().CollisionRect(r)) {
		return true;
	}

	return false;
}


void DetailPoint::Render(void) {

	if (!dp_Show) {
		return;
	}

	dp_texture->Render(dp_PosX, dp_PosY);

}

void DetailPoint::RenderDebugging() {
	
	if (!dp_Show) {
		return;
	}

	CGraphicsUtilities::RenderRect(dp_PosX, dp_PosY, dp_PosX + dp_hitboxX, dp_PosY + dp_hitboxY, MOF_COLOR_YELLOW);


}

