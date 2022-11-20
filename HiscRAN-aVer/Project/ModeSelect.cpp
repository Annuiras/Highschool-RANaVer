#include "ModeSelect.h"
#include "Define.h"


#define MenuCnt (4)

int MenuNow_Mode = 0;

//�R���X�g���N�^
CModeSelect::CModeSelect() :
	m_TutorialTextTexture(),
	m_Scroll(0.0f)
{

}

//�f�X�g���N�^
CModeSelect::~CModeSelect()
{

}

//������
void  CModeSelect::Initialize(CGameProgMgmt* mamt)
{
	m_Scroll = 0;
	m_GameProgMamt = mamt;
	//���j���[�̐���
	gMenu.Create(gMenuItemCount);

	Load();
}

//���[�h
bool CModeSelect::Load()
{
	if (!m_TutorialTextTexture.Load("ModeSelectTexture.png"))
	{
		return false;
	}

	if (!m_Illustrat.Load("ModeSelectIllust.png"))
	{
		return false;
	}

	return true;
}

//�X�V
void CModeSelect::Update()
{
	m_Scroll -= SCROLL_SPEED;

	//���L�[���őI����������悤�ɂ���
	if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		if (MenuNow_Mode < MenuCnt - 1)
		{
			++MenuNow_Mode;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_UP))
	{
		if (MenuNow_Mode > 0)
		{
			--MenuNow_Mode;
		}
	}

	//�G���^�[����������e��ʂֈړ�
	if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{

		switch (MenuNow_Mode)
		{
		case 0:
			m_bEnd = true;
			m_NextScene = SCENENO_TUTORIAL;
			break;

		case 1:
			m_bEnd = true;
			m_NextScene = SCENENO_GAME;
			break;

		case 2:
			m_bEnd = true;
			m_NextScene = SCENENO_GALLERY;
			break;

		case 3:
			m_bEnd = true;
			m_NextScene = SCENENO_OPTION;
			break;
		}
	}

	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}
	//F2�L�[�Ń`���[�g���A����ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TUTORIAL;
	}
	//F3�L�[�ŃQ�[����ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAME;
	}
	//F4�L�[�ŃM�������[��ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F4))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GALLERY;
	}
	//F5�L�[�ŃI�v�V������ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F5))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_OPTION;
	}


	//���j���[�̍X�V
	if (gMenu.IsShow())
	{
		gMenu.Update();
		if (gMenu.IsEnter())
		{
			if (gMenu.GetSelect() == 0)
			{
				PostQuitMessage(0);
			}
			gMenu.Hide();
		}
	}
	//�G�X�P�[�v�L�[�ŏI�����j���[��\��
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		Menuflag = true;
		gMenu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else
	{
		Menuflag = false;
	}
}

void CModeSelect::Render(void)
{
	//�摜��؂��邽�߂̋�`
	//���ɏo���������̉摜��`
	CRectangle recTutorialTex(0, 0, 1780, 45);
	CRectangle recGameTex(0, 45, 1780, 90);
	CRectangle recGalleryTex(0, 90, 1780, 135);
	CRectangle recOptionTex(0, 135, 1780, 180);
	CRectangle recTextile(0, 180, 1280, 234);

	//���j���[�\���p�摜�̋�`
	CRectangle recGameSel(0, 234, 498, 329);
	CRectangle recGallerySel(0, 328, 498, 424);
	CRectangle recOptionSel(0, 423, 498, 519);
	CRectangle recTutorialSel(0, 519, 498, 614);

	//�C���X�g�\���p��`
	CRectangle recAdmissionExIll(533, 613, 1066, 1226);
	CRectangle recAdmissionIll(0, 0, 533, 613);
	CRectangle recLibraryIll(533, 0, 1066, 613);
	CRectangle reccastingIll(0, 613, 533, 1226);

	//�`���[�g���A���摜
	m_TutorialTextTexture.Render(782, 44, recTutorialSel);

	//�Q�[���{�҉摜
	m_TutorialTextTexture.Render(782, 201, recGameSel);

	//�M�������[�摜
	m_TutorialTextTexture.Render(782, 359, recGallerySel);

	//�I�v�V�����摜
	m_TutorialTextTexture.Render(782, 518, recOptionSel);

	//���ɏo���e�L�X�g�̉��n
	m_TutorialTextTexture.Render(0, 654, recTextile);


	int W = m_TutorialTextTexture.GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	switch (MenuNow_Mode)
	{
	case 0:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recTutorialTex);
		}

		m_TutorialTextTexture.RenderScale(560, 23, 1.5f, recTutorialSel);
		m_Illustrat.Render(11, 22, recAdmissionExIll);

		break;

	case 1:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recGameTex);
		}

		m_TutorialTextTexture.RenderScale(560, 180, 1.5f, recGameSel);
		m_Illustrat.Render(11, 22, recAdmissionIll);

		break;

	case 2:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recGalleryTex);
		}

		m_TutorialTextTexture.RenderScale(560, 338, 1.5f, recGallerySel);
		m_Illustrat.Render(11, 22, recLibraryIll);

		break;

	case 3:
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 659, recOptionTex);
		}

		m_TutorialTextTexture.RenderScale(560, 496, 1.5f, recOptionSel);
		m_Illustrat.Render(11, 22, reccastingIll);
		break;
	}

	//���j���[�̕`��
	gMenu.Render(1);


}

void CModeSelect::RenderDebug(void)
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

	color[MenuNow_Mode] = MOF_COLOR_HRED;

	//�����`��
	for (int i = 0; i < MenuCnt; ++i)
	{
		CGraphicsUtilities::RenderString(400, 300 + 40 * i, color[i], MenuString[i]);
	}
}

void CModeSelect::Release(void)
{
	m_TutorialTextTexture.Release();
	m_Illustrat.Release();
	gMenu.Release();
}