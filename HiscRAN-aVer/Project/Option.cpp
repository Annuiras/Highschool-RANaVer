#include "Option.h"
#include "GameApp.h"

//�ύX����V�[���i�O���Q�ƁA���Ԃ�GameApp.cpp�j
extern int			gChangeScene;

Option::Option() {}

Option::~Option()
{

}

//������
void Option::Initialize(void)
{

}

//�X�V
void Option::Update(void)
{
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
	}
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}
}

//�`��
void Option::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�I�v�V�������");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");
}

//�f�ޓǂݍ���
void Option::Load(void)
{

}

//�f�މ��
void Option::Release(void)
{

}