#include "Tutorial.h"
#include "GameApp.h"

//�ύX����V�[���i�O���Q�ƁA���Ԃ�GameApp.cpp�j
extern int		gChangeScene;

Tutorial::Tutorial()
{

}

Tutorial::~Tutorial()
{

}

//������
void Tutorial::Initialize(void)
{

}

//�X�V
void Tutorial::Update(void)
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
void Tutorial::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�`���[�g���A�����");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");
}

//�f�ޓǂݍ���
void Tutorial::Road(void)
{

}

//�f�މ��
void Tutorial::Release(void)
{

}
