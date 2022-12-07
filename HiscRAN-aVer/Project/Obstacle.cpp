#pragma once
#include "Obstacle.h"


CObstacle::CObstacle() :

	ob_PosX(0.0f),
	ob_PosY(0.0f),
	ob_Show(false),
	ob_Type(0),
	ob_HitWidth(0.0f),
	ob_Textuer()

{};

CObstacle::~CObstacle() {

}


//������
void  CObstacle::Initialize() {

	ob_PosX = 0;
	ob_PosY = 0;
	ob_Show = false;
	ob_HitWidth = 0;
	ob_Type = 0;

}


void CObstacle::Start(float posy, int type) {

	ob_PosX = g_pGraphics->GetTargetWidth();

	ob_PosY = posy;

	ob_Type = type;

	ob_Show = true;

	ob_HitWidth = ob_Textuer->GetWidth();
}

void CObstacle::Update(float over) {

	//�\�����Ɏ��s
	if (ob_Show)
	{
		ob_PosX -= over;

		//��ʍ��[�ŏ���
		if (ob_PosX + ob_HitWidth < 0)
			ob_Show = false;

	}
}

void CObstacle::SetTexture(CTexture* obtex) {

	ob_Textuer = obtex;

}

void CObstacle::Render() {

	//�\�����H
	if (!ob_Show) {
		return;
	}
	if (ob_Textuer == NULL) {
		//�e�N�X�`�����Ȃ��ꍇ�͕`�悵�Ȃ�
	}
	else
	{
		ob_Textuer->Render(ob_PosX, ob_PosY);
	}
	
}

//�f�o�b�O�\��
void CObstacle::RenderDebugging(void) {

	if (!ob_Show) {
		return;
	}

	//�_���[�W����
	CGraphicsUtilities::RenderRect(GetRect(ob_Type), MOF_COLOR_YELLOW);

	//��ɏ��锻��
	CGraphicsUtilities::RenderRect(GetTopBarRect(ob_Type), MOF_COLOR_GREEN);
}


//�_���[�W��`�擾
CRectangle CObstacle::GetRect(int type){

	//�^�C�v�ő傫���ύX����ꍇ
	switch (type)
	{
	//	//���b�J�[
	//case OB_LOCKER:
	//	return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y,
	//		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + ob_Textuer->GetHeight());
	//	break;


	default:
		break;
	}

	return CRectangle(ob_PosX, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y,
		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + ob_Textuer->GetHeight());

}

//��Q����ɏ��铖���蔻��擾
CRectangle CObstacle::GetTopBarRect(int type) {

	//�^�C�v�ʂő傫����ύX
	switch (type)
	{

	//case OB_DESK://��
	//	return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_Y,
	//		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y);
	//	break;

	default:
		break;
	}
	return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_Y,
		ob_PosX + ob_Textuer->GetWidth(), ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y);

}
