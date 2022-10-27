#include "Obstacle.h"


CObstacle::CObstacle() :

	ob_PosX(0.0f),
	ob_PosY(0.0f),
	ob_Show(false),
	ob_hitboxX(0.0f),
	ob_hitboxY(0.0f),
	ob_Type(0)

{};

CObstacle::~CObstacle() {

}

//������
void  CObstacle::Initialize() {

	ob_PosX = 0;
	ob_PosY = 0;
	ob_Show = false;
	ob_hitboxX = 0;
	ob_hitboxY = 0;
	ob_Type = 0;
}


void CObstacle::Start(float posy, int type) {

	ob_PosX = g_pGraphics->GetTargetWidth();

	ob_PosY = posy;

	ob_Type = type;

	ob_Show = true;
}

void CObstacle::Update(float over) {

	//�\�����Ɏ��s
	if (ob_Show)
	{
		ob_PosX -= over;

		//��ʍ��[�ŏ���
		if (ob_PosX + ob_hitboxX < 0)
			ob_Show = false;

	}
}

void CObstacle::Render() {

	//�\�����H
	if (!ob_Show) {
		return;
	}

	CGraphicsUtilities::RenderFillRect(GetRect(ob_Type), MOF_COLOR_RED);
}

CRectangle CObstacle::GetRect(int type){

	//todo:�^�C�v�ʂő傫����ύX
	switch (type)
	{

	case 1:
		return CRectangle(ob_PosX, ob_PosY,
		ob_PosX + 30 , ob_PosY + 60);
		break;

	case 2:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 60, ob_PosY + 30);
		break;

	case 3:
		return CRectangle(ob_PosX, ob_PosY,
			ob_PosX + 30, ob_PosY + 30);
		break;

	default:
		break;
	}
}