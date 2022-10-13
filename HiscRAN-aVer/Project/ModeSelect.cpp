#include "ModeSelect.h"
#include "GameApp.h"

//�ύX����V�[���i�O���Q�ƁA���Ԃ�GameApp.cpp�j
extern int	gChangeScene;

#define MenuCnt (4)

int MenuNow = 0;

//�R���X�g���N�^
ModeSelect::ModeSelect() {}

//�f�X�g���N�^
ModeSelect::~ModeSelect()
{

}

//������
void  ModeSelect::Initialize()
{

}

//���[�h
void ModeSelect::Load()
{

}

//�X�V
void ModeSelect::Update()
{
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
	}
	//F2�L�[�Ń`���[�g���A����ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		gChangeScene = SCENENO_TUTORIAL;
	}
	//F3�L�[�ŃQ�[����ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		gChangeScene = SCENENO_GAME;
	}
	//F4�L�[�ŃM�������[��ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F4))
	{
		gChangeScene = SCENENO_GALLERY;
	}
	//F5�L�[�ŃI�v�V������ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F5))
	{
		gChangeScene = SCENENO_OPTION;
	}

	//���L�[���őI����������悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		if (MenuNow < MenuCnt - 1)
		{
			++MenuNow;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		if (MenuNow > 0)
		{
			--MenuNow;
		}
	}

	//�G���^�[����������e��ʂֈړ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		switch (MenuNow)
		{
		case 0:
			gChangeScene = SCENENO_TUTORIAL;
			break;

		case 1:
			gChangeScene = SCENENO_GAME;
			break;

		case 2:
			gChangeScene = SCENENO_GALLERY;
			break;

		case 3:
			gChangeScene = SCENENO_OPTION;
		}
	}
}

void ModeSelect::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "���[�h�Z���N�g���");
	CGraphicsUtilities::RenderString(10, 40, "Enter�L�[�ŉ�ʑJ��");
	CGraphicsUtilities::RenderString(10, 70, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 100, "F2�L�[�Ń`���[�g���A����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 130, "F3�L�[�ŃQ�[����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 160, "F4�L�[�ŃM�������[��ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 190, "F5�L�[�ŃI�v�V������ʂ֑J��");


	const char* MenuString[MenuCnt] =
	{
		"�`���[�g���A��(���w����)",
		"�Q�[���J�n�i���w�j",
		"�M�������[�i�}�����j",
		"�I�v�V�����i�z�[�����[���j",
	};

	MofU32 color[MenuCnt];

	for (int i = 0; i < MenuCnt; i++)
	{
		color[i] = MOF_COLOR_BLACK;
	}

	color[MenuNow] = MOF_COLOR_HRED;

	//�����`��
	for (int i = 0; i < MenuCnt; ++i)
	{
		CGraphicsUtilities::RenderString(400, 300 + 40 * i, color[i], MenuString[i]);
	}
}

void ModeSelect::Release(void)
{

}