#include "Tutorial.h"
#include "Define.h"

CTutorial::CTutorial() :
	Texture(),
	ScreenTexture(),
	BGTexture(),
	BackButton(),
	ButtonSelect(),
	m_Scroll(0.0f),
	gPosX(0.0f),
	count(0.0f),
	MoveX(0.0f),
	bShow(false)
{

}

CTutorial::~CTutorial()
{

}

//�f�ޓǂݍ���
bool CTutorial::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Tutorial");

	if (!Texture.Load("tutorialBG.png"))
	{
		return false;
	}

	if (!BGTexture.Load("TutorialMak.png"))
	{
		return false;
	}

	if (!ScreenTexture.Load("tutorialScreen.png"))
	{
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	if (!BackButton.Load("BackButton.png"))
	{
		return false;
	}

	if (!ButtonSelect.Load("Select_s.png"))
	{
		return false;
	}

	return true;

}

//������
void CTutorial::Initialize(CGameProgMgmt* mamt)
{
	m_Scroll = 0;
	count = 0;
	MoveX = 0;
	gPosX = 0;
	bShow = false;
	m_GameProgMamt = mamt;
	Load();
}

//�X�V
void CTutorial::Update(void)
{

	//�`���[�g���A���摜�ő喇���ȉ�
	//�����Ă���t���O��FALSE�i�����Ă��Ȃ��Ƃ����Ӗ��ɂȂ�j
	//�E���L�[�������Ă���
	//��������A�J�E���g���ăy�[�W���肷��
	if (count < 5 && bShow == false && g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		count = count + 1;
		MoveX = -20;
		bShow = true;
	}

	//-1�ȏ�i�ϐ��̊֌W��A0��1���ڂ̈Ӗ��ɂȂ邽�߁j
	//�����Ă���t���O��FALSE�i�����Ă��Ȃ��j
	//�����L�[�������Ă���
	//��������A�J�E���g���ăy�[�W���肷��
	else if (count > -1 && bShow == false && g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		count = count - 1;
		MoveX = 20;
		bShow = true;
	}

	//���ۂɍ��W�𓮂���
	m_Scroll += MoveX;
	gPosX += MoveX;

	//1280�~�J�E���g�̐��l�Ŏ~�߂�
	//�J�E���g��-1��������4�̏ꍇ�́A�߂�{�^���ɔ�Ԃ̂ł��������ړ����Ȃ�
	if (m_Scroll == -1280 * count || m_Scroll == 1280 * count || count == -1 || count == 5)
	{
		MoveX = 0;
		bShow = false;

		if (count == -1 || count == 0)
		{
			gPosX = 0;
		}
		else if (count == 4 || count == 5)
		{
			gPosX = -5120;
		}
	}

	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (count == 5 && g_pInput->IsKeyPush(MOFKEY_RETURN) || count == -1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

}

//�`��
void CTutorial::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�`���[�g���A�����");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");

	Texture.Render(gPosX, 0);

	ScreenTexture.Render(0, 0);
	BGTexture.Render(0, 0);

	BackButton.Render(60, 650);

	if (count == 5 || count == -1)
	{
		ButtonSelect.Render(60, 650);
	}

}

void CTutorial::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�`���[�g���A�����");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 100, "0�������摜�J�[�\���@�@5���E���摜�J�[�\��");
	if (bShow == true)
	{
		CGraphicsUtilities::RenderString(10, 130, MOF_COLOR_BLACK, "�t���OTrue");
	}
	else if (bShow == false)
	{
		CGraphicsUtilities::RenderString(10, 130, MOF_COLOR_BLACK, "�t���OFalse");
	}
	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "�y�[�W��:%d", count);
}



//�f�މ��
void CTutorial::Release(void)
{
	ScreenTexture.Release();
	Texture.Release();
	BGTexture.Release();
	BackButton.Release();
	ButtonSelect.Release();
}
