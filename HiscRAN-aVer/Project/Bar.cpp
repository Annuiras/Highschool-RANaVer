#pragma once
#include "Bar.h"

Bar::Bar() :
	b_PosX(0.0f),
	b_PosY(0.0f),
	b_HitWidth(0.0f),
	b_Show(true),
	b_Type(0),
	bar_texture()
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
	bar_texture = NULL;
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
	case BAR_BIG://��
		b_HitWidth = BAR_BIG_WIDTH;
		break;

	case BAR_MEDIUM://��
		b_HitWidth = BAR_MEDIUM_WIDTH;
		break;

	case BAR_SMALL://��
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

	bar_texture->Render(b_PosX, b_PosY);

	
	//����`��
	CGraphicsUtilities::RenderRect(GetRect(b_Type), MOF_COLOR_GREEN);

}

CRectangle Bar::GetRect(int type) {
	

	//�^�C�v�ʂő傫����ύX
	//����̑傫�����������m�肵�Ă��Ȃ��̂ŉ��u��
	switch (type)
	{

	case BAR_BIG://��
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_BIG_WIDTH, b_PosY + BAR_BIG_HEIGHT);
		break;

	case BAR_MEDIUM://��
		return CRectangle(b_PosX, b_PosY,
			b_PosX + BAR_MEDIUM_WIDTH, b_PosY + BAR_MEDIUM_HEIGHT);
		break;

	case BAR_SMALL://��
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

void Bar::SetTexture(CTexture* bartex)
{

	bar_texture = bartex;

}






