#pragma once
#include "Bar.h"

Bar::Bar() :
	b_PosX(0.0f),
	b_PosY(0.0f),
	b_HitWidth(0.0f),
	b_Show(true),
	b_Type(0)
{};


Bar::~Bar() {


};

//������
void Bar::Initialize() {

	b_PosX = 0;
	b_PosY = 0;
	b_Type = 0;
	b_HitWidth = 0.0f;
	b_Show = false;
}

//�\���̂��ߏ���
//posy:Y���W
void Bar::Start(float posy, int type) {

	b_PosX = g_pGraphics->GetTargetWidth();
	b_PosY = posy;

	//�^�C�v������
	b_Type = type;

	b_Show = true;

	switch (type)
	{
	case 1://��
		b_HitWidth = BAR_BIG_WIDTH;
		break;

	case 2://��
		b_HitWidth = BAR_MEDIUM_WIDTH;
		break;

	case 3://��
		b_HitWidth = BAR_SMALL_WIDTH;
		break;

	default:
		break;
	}

}

void Bar::Update(float over) {


	//�\�����̂�
	if (b_Show)
	{
		b_PosX -= over;

		//�����^�C�v�ʂɔ���
		if (b_PosX + b_HitWidth < 0) {
			b_Show = false;
		}
	}



}

void Bar::Render(void) {

	if (!b_Show) {
		return;
	}

	//����`��
	CGraphicsUtilities::RenderFillRect(GetRect(b_Type), MOF_COLOR_GREEN);

}

CRectangle Bar::GetRect(int type) {
	

	//�^�C�v�ʂő傫����ύX
	//����̑傫�����������m�肵�Ă��Ȃ��̂ŉ��u��
	switch (type)
	{

	case 1://��
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_BIG_WIDTH, b_PosY + BAR_BIG_HEIGHT);
		break;

	case 2://��
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_MEDIUM_WIDTH, b_PosY + BAR_MEDIUM_HEIGHT);
		break;

	case 3://��
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_SMALL_WIDTH, b_PosY + BAR_SMALL_HEIGHT);
		break;

	default:
		//�G���[�̏ꍇ
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_BIG_WIDTH, b_PosY + BAR_BIG_HEIGHT);

		break;
	}
	
}






