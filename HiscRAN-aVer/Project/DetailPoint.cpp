#include "DetailPoint.h"


DetailPoint::DetailPoint() :
	dp_PosX(0.0f),
	dp_PosY(0.0f),
	dp_Show(false),
	dp_hitboxX(0.0f),
	dp_hitboxY(0.0f),
	dp_value(0.0f),
	dp_Textuer_Scholastic(),
	dp_Type(0)
{};

DetailPoint::~DetailPoint() {



};

bool DetailPoint::Load() {

	//todo;�e�N�X�`���ǂݍ��݉��P�\��
	//���e�N�X�`���F�w��
	if (!dp_Textuer_Scholastic.Load("�n�C�X�N�f�ށ@DP �w�́@��.png")) {
		return false;
	}

	//���e�N�X�`���F�s����
	if (!dp_Textuer_Action.Load("�n�C�X�N�f�ށ@DP �s���́@��.png")) {
		return false;
	}

	//���e�N�X�`���F�z����
	if (!dp_Textuer_Imagination.Load("�n�C�X�N�f�ށ@DP �z���́@��.png")) {
		return false;
	}

	//���e�N�X�`���F�R�~����
	if (!dp_Textuer_Communication.Load("�n�C�X�N�f�ށ@DP �R�~���́@��.png")) {
		return false;
	}

	//���e�N�X�`���F����
	if (!dp_Textuer_Charm.Load("�n�C�X�N�f�ށ@DP ���́@��.png")) {
		return false;
	}

	return true;
}

//DP�̐��l������
void DetailPoint::Initialize(void) {

	dp_PosX = 0;
	dp_PosY = 0;
	dp_Type = 0;
	dp_hitboxX = 80;
	dp_hitboxY = 80;
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

	switch (dp_Type)
	{

	case 1:
		//�w��
		//���e�N�X�`���\���ł�
		dp_Textuer_Scholastic.Render(dp_PosX,dp_PosY);
		//CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(222, 184, 135));
		break;

	case 2:
		//�s����
		dp_Textuer_Action.Render(dp_PosX,dp_PosY);
		//CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_YELLOW);
		break;

	case 3:
		//�z����
		//dp_Textuer_Imagination.Render(GetRect());
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(0, 191, 255));
		break;

	case 4:
		//�R�~����
		//dp_Textuer_Communication.Render(GetRect());
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(255, 99, 71));
		break;

	case 5:
		//����
		//dp_Textuer_Charm.Render(GetRect());
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_XRGB(186, 85, 211));
		break;

	default:
		//�G���[
		CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_BLACK);
		break;
	}


}

void DetailPoint::RenderDebugging() {

	CGraphicsUtilities::RenderString(620, 660, MOF_XRGB(80, 80, 80), "�R�C����` X:%.1f Y:%.1f", dp_hitboxX, dp_hitboxY);

	CGraphicsUtilities::RenderString(620, 30, MOF_XRGB(80, 80, 80), "�X�e�[�^�X�㏸�l:%.2f", dp_value);

	//DP�i���o�[��\���ł��񂩂�
	//CGraphicsUtilities::RenderString(dp_PosX,dp_addY,dp_)
}

//�����[�X������ǉ��ł�
void DetailPoint::Release(void) {

	dp_Textuer_Scholastic.Release();
	dp_Textuer_Action.Release();
	dp_Textuer_Imagination.Release();
	dp_Textuer_Communication.Release();
	dp_Textuer_Charm.Release();
}