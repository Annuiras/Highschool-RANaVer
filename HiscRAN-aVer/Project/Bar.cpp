#include "Bar.h"

Bar::Bar() :
	b_PosX(0.0f),
	b_PosY(0.0f),
	b_Show(true)
{};


Bar::~Bar() {


};

//������
void Bar::Initialize() {

	b_PosX = 0;
	b_PosY = 0;
	b_Show = false;
}

//�\���̂��ߏ���
//posy:Y���W
void Bar::Start(float posy) {

	b_PosX = g_pGraphics->GetTargetWidth();
	b_PosY = posy;
	b_Show = true;

}

void Bar::Update(float over) {


	//�\�����̂�
	if (b_Show)
	{
		b_PosX -= over;

		if (b_PosX + BAR_WIDTH < 0) {
			b_Show = false;
		}
	}



}

void Bar::Render(void) {

	if (!b_Show) {
		return;
	}

	//����`��
	CGraphicsUtilities::RenderFillRect(GetRect(), MOF_COLOR_RED);

}





