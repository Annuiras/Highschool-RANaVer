#include "Obstacle.h"


CObstacle::CObstacle() :

	ob_PosX(0.0f),
	ob_PosY(0.0f),
	ob_Show(false),
	ob_hitboxX(0.0f),
	ob_hitboxY(0.0f),
	ob_addX(0.0f),
	ob_addY(0.0f)

{};

CObstacle::~CObstacle() {

}

//������
void  CObstacle::Initialize() {

	ob_PosX = 0;
	ob_PosY = 0;
	ob_Show = false;
	ob_hitboxX = 30;
	ob_hitboxY = 30;
	ob_addX = 0;
	ob_addY = 0;

}


void CObstacle::Start(float posy) {

	ob_PosX = g_pGraphics->GetTargetWidth();

	ob_PosY = posy;

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

	CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_RED);
}

