#include "Tutorial.h"

CTutorial::CTutorial() :
	BGTexture(),
	ScreenBGTexture(),
	CurtainBGTexture(),
	BackButton(),
	ButtonSelect(),
	m_Scroll(0.0f),
	gPosX(0.0f),
	count(0.0f),
	MoveX(0.0f),
	bShow(false),
	TMenuCnt(0)
{

}

CTutorial::~CTutorial()
{

}

//�f�ޓǂݍ���
void CTutorial::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Tutorial");

	//�w�i�e�N�X�`��
	if (!BGTexture.Load("tutorialBG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�w�i���i����폜�j
	if (!CurtainBGTexture.Load("TutorialMak.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�`���[�g���A���摜
	if (!ScreenBGTexture.Load("tutorialScreen.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	if (!BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!ButtonSelect.Load("Select_s.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���[�h����
	b_LoadSitu = LOAD_DONE;

}

//������
void CTutorial::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CLoad* loma)
{
	//������
	m_Scroll = 0;
	count = 0;
	MoveX = 0;
	gPosX = 0;
	bShow = false;
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//��Ԃ�ݒ�
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//�f�ރ��[�h
	Load();


	m_NowScene = SCENENO_TUTORIAL;

}

//�X�V
void CTutorial::Update(void)
{

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph);
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph);
		return;
	}
	//�߂�{�^���ɃJ�[�\�����킹��K�v����܂�Ȃ������ˁ`
	//Enter�Ŗ߂�ł�������

	//�`���[�g���A���摜�ő喇���ȉ�
	//�����Ă���t���O��FALSE�i�����Ă��Ȃ��Ƃ����Ӗ��ɂȂ�j
	//�E���L�[�������Ă���
	//��������A�J�E���g���ăy�[�W���肷��
	if (bShow == false && g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		switch (count)
		{
		case -1:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			break;

		case 0:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			break;

		case 1:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			break;

		case 2:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			break;

		case 3:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			break;

		case 4:
			count = count + 1;
			MoveX = -20;
			bShow = true;
			break;

		case 5:
			TMenuCnt = 1;
			break;
		}
	}
	else if (bShow == false && g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		switch (count)
		{
		case -1:
			TMenuCnt = 1;
			break;

		case 0:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			break;

		case 1:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			break;

		case 2:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			break;

		case 3:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			break;

		case 4:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			break;

		case 5:
			count = count - 1;
			MoveX = 20;
			bShow = true;
			break;
		}
	}
	//���L�[�������������A�߂�{�^���ɃJ�[�\�������킹��
	else if (TMenuCnt == 0 && g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		TMenuCnt = 1;
	}
	//���L�[������������A�J�[�\�����O��
	else if (TMenuCnt == 1 && g_pInput->IsKeyPush(MOFKEY_UP))
	{

		TMenuCnt = 0;

		if (count == 5)
		{
			count = count - 1;
			MoveX = 20;
			bShow = true;
		}
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

	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (TMenuCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

}

//�`��
void CTutorial::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�`���[�g���A�����");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");

	//�w�i�摜�`��
	BGTexture.Render(gPosX, 0);

	//Screen�摜�`��
	ScreenBGTexture.Render(0, 0);

	//���`��i����폜�j
	CurtainBGTexture.Render(0, 0);

	//�߂�{�^��
	BackButton.Render(60, 650);

	//����TMenuCnt��1�Ȃ�
	if (TMenuCnt == 1)
	{
		//�߂�{�^���ɃJ�[�\�������킹��
		ButtonSelect.Render(60, 650);
	}

	//�t�F�[�h�p���w�i
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 0, 0, 0));

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
	ScreenBGTexture.Release();
	BGTexture.Release();
	CurtainBGTexture.Release();
	BackButton.Release();
	ButtonSelect.Release();
}
