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

	switch (type)
	{
	case OB_DESK://��
		ob_HitWidth = OB_DESK_WIDTH;
		break;

	case OB_TWODESK://�Q�i��
		ob_HitWidth = OB_DESK_WIDTH;
		break;

	case OB_LOCKER://���b�J�[
		ob_HitWidth = OB_LOCKER_WIDTH;
		break;

	default:
		break;
	}

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

	//�^�C�v�ʂő傫����ύX
	switch (type)
	{
		//��
	case OB_DESK:
		return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_DESK_HEIGHT);
		break;

		//�Q�i��
	case OB_TWODESK:
		return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_,
			ob_PosX + OB_TOWDESK_WIDTH, ob_PosY + OB_TOWDESK_HEIGHT);
		break;

		//���b�J�[
	case OB_LOCKER:
		return CRectangle(ob_PosX, ob_PosY+ OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_,
			ob_PosX + OB_LOCKER_WIDTH, ob_PosY + OB_LOCKER_HEIGHT);
		break;


	default:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);

		break;
	}
}

//�����Q����ɏ��铖���蔻��擾
CRectangle CObstacle::GetTopBarRect(int type) {

	//�^�C�v�ʂő傫����ύX
	switch (type)
	{

	case OB_DESK://��
		return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_);
		break;


	case OB_TWODESK://�Q�i��
		return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_);
		break;

		
	case OB_LOCKER://���b�J�[
		return CRectangle(ob_PosX, ob_PosY + OB_HITRECT_SPACE_,
			ob_PosX + OB_LOCKER_WIDTH, ob_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_);
		break;


	default:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);

		break;
	}
}
