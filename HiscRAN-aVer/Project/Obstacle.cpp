#include "Obstacle.h"


CObstacle::CObstacle() :

	ob_PosX(0.0f),
	ob_PosY(0.0f),
	ob_Show(false),
	ob_Type(0)

{};

CObstacle::~CObstacle() {

}


//todo:���[�h�ǉ��ł�
bool CObstacle::Load(void) {

	//���e�N�X�`���F��
	if (!ob_Textuer_Desk.Load("")) {
		return false;
	}

	return true;
}

//������
void  CObstacle::Initialize() {

	ob_PosX = 0;
	ob_PosY = 0;
	ob_Show = false;
	ob_HitWidth = 0;
	ob_Type = 0;

	Load();
}


void CObstacle::Start(float posy, int type) {

	ob_PosX = g_pGraphics->GetTargetWidth();

	ob_PosY = posy;

	ob_Type = type;

	ob_Show = true;

	switch (type)
	{
	case 1://��
		ob_HitWidth = OB_DESK_WIDTH;
		break;

	case 2://�Q�i��
		ob_HitWidth = OB_DESK_WIDTH;
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

void CObstacle::Render() {

	//�\�����H
	if (!ob_Show) {
		return;
	}

	//ob_Textuer_Desk.Render(GetRect(ob_Type));
	
	CGraphicsUtilities::RenderFillRect(GetRect(ob_Type), MOF_COLOR_RED);
}

CRectangle CObstacle::GetRect(int type){

	//todo:�^�C�v�ʂő傫����ύX
	switch (type)
	{
	
	case 1://��
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + OB_DESK_WIDTH, ob_PosY + OB_DESK_HEIGHT);
		break;

		
	case 2://�Q�i��
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 137, ob_PosY + 306);
		break;

	default:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);

		break;
	}
}