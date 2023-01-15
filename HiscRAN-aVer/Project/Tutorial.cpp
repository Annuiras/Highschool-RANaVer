#include "Tutorial.h"

CTutorial::CTutorial() :
	BGTexture(),
	CurtainBGTexture(),
	BackButton(),
	ButtonSelect(),
	gPosX(),
	m_Cursor(0.0f),
	MoveX(0.0f),
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

	//�����e�N�X�`��
	char* name[PAGES_NUM] =
	{
		"����685_20230113163526.png",
		"setumei.png",
		"����685_20230113163526.png",
		"setumei.png",
		"����685_20230113163526.png",
		"setumei.png",
		"����685_20230113163526.png",
	};

	for (int i = 0; i < PAGES_NUM; i++)
	{
		if (!ExTextTexture[i].Load(name[i]))
		{
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	//�w�i�e�N�X�`��
	if (!BGTexture.Load("Tutorial_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�X�N���[���e�N�X�`��
	if (!ScreenTexture.Load("Tutorial_Screen.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�J�[�e�������e�N�X�`��
	if (!CurtainBGTexture.Load("Tutorial_Mak.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�J�[�e�������e�N�X�`����
	if (!CurtainBGTextureLeft.Load("Tutorial_MakLef.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�J�[�e�������e�N�X�`���E
	if (!CurtainBGTextureRight.Load("Tutorial_MakRig.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�J�[�e�������e�N�X�`����
	if (!CurtainBGTextureTop.Load("Tutorial_MakTop.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�߂�{�^��
	if (!BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�߂�{�^���I��g
	if (!ButtonSelect.Load("BackButton_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���[�h����
	b_LoadSitu = LOAD_COMP;

}

//������
void CTutorial::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//������
	m_Cursor = 0;
	Is_Move = false;
	MoveX = 0;
	TMenuCnt = false;

	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;

	//��Ԃ�ݒ�
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//�f�ރ��[�h
	Load();

	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu != LOAD_ERROR) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}


	for (int i = 0; i < PAGES_NUM; i++)
	{
		//�����ʒu�Z�b�g
		//300:�y�[�W�ƃy�[�W�̌���
		gPosX[i] = PAGES_X + ExTextTexture[0].GetWidth()+300;
	}

	//�ŏ��̃y�[�W���Z���^�[��
	gPosX[0] = PAGES_X;

	//���݂̃V�[���Z�b�g
	m_NowScene = SCENENO_TUTORIAL;

}

//�X�V
void CTutorial::Update(void)
{

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}

	//BGM�Đ�
	b_MusicManager->BGMStart(BGMT_TUTORIAL);

	//�ړ������H
	if (Is_Move) {

		//�X�N���[��
		//�ړ������m�F
		if (MoveX > 0) {

			//�E�ړ�
			//�Œ���߂�����
			if (gPosX[m_Cursor] <= PAGES_X) {

				//�Œ�
				gPosX[m_Cursor] = PAGES_X;

				//�ړ��I��
				Is_Move = false;

				//����
				MoveX = 0;

			}
			else
			{
				//�ړ�
				gPosX[m_Cursor] -= MoveX;
				gPosX[m_Cursor - 1] -= MoveX;
			}

		}
		else
		{
			//���ړ�
			//�Œ���߂�����
			if (gPosX[m_Cursor] >= PAGES_X)
			{
				//�Œ�
				gPosX[m_Cursor] = PAGES_X;

				//�ړ��I��
				Is_Move = false;

				//����
				MoveX = 0;
			}
			else
			{
				//�ړ�
				gPosX[m_Cursor] -= MoveX;
				gPosX[m_Cursor + 1] -= MoveX;
			}

		}

	}
	else
	{
		//�ړ����łȂ�
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			//�E�Ɉړ�
			if (m_Cursor != PAGES_NUM - 1) {
				Is_Move = true;
				MoveX = PAGES_SPEED;
				m_Cursor++;
			}
		}
		else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
		{
			//���Ɉړ�
			if (m_Cursor != 0) {
				Is_Move = true;
				MoveX = -PAGES_SPEED;
				m_Cursor--;
			}
		}

		//���L�[�������������A�߂�{�^���ɃJ�[�\�������킹��
		else if (!TMenuCnt&& g_pInput->IsKeyPush(MOFKEY_DOWN))
		{
			TMenuCnt = true;
		}
		//���L�[������������A�J�[�\�����O��
		else if (TMenuCnt && g_pInput->IsKeyPush(MOFKEY_UP))
		{
			TMenuCnt = false;
		}

	}

	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (TMenuCnt&& g_pInput->IsKeyPush(MOFKEY_RETURN))
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

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_COLOR_WHITE);

	//�Z���^�[�ɗ���摜
	ExTextTexture[m_Cursor].Render(gPosX[m_Cursor], PAGES_Y);

	//�ړ����̕\��
	if (MoveX > 0) {

		//�E�ɔ����Ă����摜
		ExTextTexture[m_Cursor - 1].Render(gPosX[m_Cursor - 1], PAGES_Y);

	}
	else if (MoveX < 0)
	{
		//���ɔ����Ă����摜
		ExTextTexture[m_Cursor + 1].Render(gPosX[m_Cursor + 1], PAGES_Y);
	}

	//�w�i�摜�`��
	BGTexture.Render(0, 0);

	//Screen�摜�`��
	ScreenTexture.Render(0, 0);

	//���`��
	CurtainBGTexture.Render(0, 0);

	//����
	CurtainBGTextureLeft.Render(-646, 0);

	//���E
	CurtainBGTextureRight.Render(646, 0);

	//����
	CurtainBGTextureTop.Render(0, 0);

	//�߂�{�^��
	BackButton.Render(60, 650);


	if (TMenuCnt)
	{
		//�߂�{�^���Ƀn�C���C�g
		ButtonSelect.Render(60, 650);
	}

	//�t�F�[�h�p���w�i
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));

}

void CTutorial::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�`���[�g���A�����");
	//CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	//CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");
	//CGraphicsUtilities::RenderString(10, 100, "0�������摜�J�[�\���@�@5���E���摜�J�[�\��");
	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "�y�[�W��:%d", m_Cursor);

	for (int i = 0; i < PAGES_NUM; i++)
	{
		if (m_Cursor == i) {
			CGraphicsUtilities::RenderString(0, 200 + (30 * i),MOF_COLOR_RED, "X:%d", gPosX[i]);

		}
		else
		{
			CGraphicsUtilities::RenderString(0, 200 + (30 * i), "X:%d", gPosX[i]);

		}
	}

}



//�f�މ��
void CTutorial::Release(void)
{
	//BGM��~
	b_MusicManager->BGMStop(BGMT_TUTORIAL);

	for (int i = 0; i < PAGES_NUM; i++)
	{
		ExTextTexture[i].Release();
	}
	BGTexture.Release();
	ScreenTexture.Release();
	CurtainBGTexture.Release();
	CurtainBGTextureLeft.Release();
	CurtainBGTextureRight.Release();
	CurtainBGTextureTop.Release();
	BackButton.Release();
	ButtonSelect.Release();
}
