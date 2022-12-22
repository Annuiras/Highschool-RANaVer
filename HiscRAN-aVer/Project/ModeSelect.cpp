#include "ModeSelect.h"


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
void  CModeSelect::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_Scroll = 0;
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;
	//���j���[�̐���
	gMenu.Create(gMenuItemCount);

	g_MusicManager->BGMStart(BGMT_MOOP);

	m_NowScene = SCENENO_SELECTMODE;

	Load();
}

//���[�h
bool CModeSelect::Load()
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("ModeSelect");

	if (!m_TutorialTextureSmall.Load("ModeSelect_Min.png"))
	{
		return false;
	}
	
	if (!m_TutorialTextureBig.Load("ModeSelect_Big.png")) 
	{
		return false;
	}

	if (!m_TutorialTextTexture.Load("ModeSelect_Text.png"))
	{
		return false;
	}

	if (!m_TutorialTextBox.Load("ModeSelect_TextBox.png")) 
	{
		return false;
	}

	if (!m_TutorialTextTexture.Load("ModeSelect_Text.png"))
		return false;
		
	if (!m_TutorialBG[0].Load("ModeSelect_AddmissionEx_BG.png")) 
	{
		return false;
	}

	if (!m_TutorialBG[1].Load("ModeSelect_Addmission_BG.png"))
	{
		return false;
	}
	
	if (!m_TutorialBG[2].Load("ModeSelect_Library_BG.png"))
	{
		return false;
	}

	if (!m_TutorialBG[3].Load("ModeSelect_Broadcasting_BG.png"))
	{
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//�X�V
void CModeSelect::Update()
{
	m_Scroll -= SCROLL_SPEED;

	//���L�[���őI����������悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		g_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode < MenuCnt - 1)
		{
			++MenuNow_Mode;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		g_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode > 0)
		{
			--MenuNow_Mode;
		}
	}

	//�G���^�[����������e��ʂֈړ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		g_MusicManager->SEStart(SE_T_DECISION);

		switch (MenuNow_Mode)
		{
		case 0:
			m_bEnd = true;
			m_NextScene = SCENENO_TUTORIAL;
			break;

		case 1:
			m_bEnd = true;
			m_NextScene = SCENENO_DPDECISION;
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
	CRectangle recTutorialTex(0, 0, 1845, 41);
	CRectangle recGameTex(0, 45, 1845, 85);
	CRectangle recGalleryTex(0, 90, 1845, 130);
	CRectangle recOptionTex(0, 135, 1845, 175);
	

	//���j���[�\���p�摜�̋�`(��)
	CRectangle recTutorialSelbig(0, 0, 477, 188);
	CRectangle recGameSelbig(0, 188, 477, 371);
	CRectangle recGallerySelbig(0, 371, 477, 568);
	CRectangle recOptionSelbig(0, 568, 477, 750);


		//���j���[�\���p�摜�̋�`(��)
	CRectangle recTutorialSelmin(0, 168, 413, 350);
	CRectangle recGameSelmin(0, 0, 413, 168);
	CRectangle recOptionSelmin(0, 350, 413, 523);
	CRectangle recGallerySelmin(0, 523, 413, 700);
	
	//�w�i�`��
	//����switch���ɓ��ꍞ�ނƃ��C���[���̉����Ń��j���[�\�������x���`�悵�Ȃ��Ƃ����Ȃ��Ȃ�̂�
	//�����ŕ��򂳂��Ă܂��B

	//�X�N���[��
	int W = m_TutorialTextTexture.GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	switch (MenuNow_Mode)
	{
	case 0:
		//�w�i�摜
		m_TutorialBG[0].Render(0, 0);

		//�`���[�g���A���摜(��)
		m_TutorialTextureBig.Render(803, 35, recTutorialSelbig);

		//�Q�[���{�҉摜(��)
		m_TutorialTextureSmall.Render(867, 190, recGameSelmin);

		//�M�������[�摜(��)
		m_TutorialTextureSmall.Render(867, 337, recGallerySelmin);

		//�I�v�V�����摜(��)
		m_TutorialTextureSmall.Render(867, 489, recOptionSelmin);

		//���ɏo���e�L�X�g�̉��n
		m_TutorialTextBox.Render(0, 612);

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recTutorialTex);
		}
		break;

	case 1:
		//�w�i�摜
		m_TutorialBG[1].Render(0, 0);

		//�`���[�g���A���摜(��)
		m_TutorialTextureSmall.Render(867, 45, recTutorialSelmin);

		//�Q�[���{�҉摜(��)
		m_TutorialTextureBig.Render(803, 181, recGameSelbig);

		//�M�������[�摜(��)
		m_TutorialTextureSmall.Render(867, 337, recGallerySelmin);

		//�I�v�V�����摜(��)
		m_TutorialTextureSmall.Render(867, 489, recOptionSelmin);

		//���ɏo���e�L�X�g�̉��n
		m_TutorialTextBox.Render(0, 612);

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recGameTex);
		}
		break;

	case 2:
		
		//�w�i�摜
		m_TutorialBG[2].Render(0, 0);

		//�`���[�g���A���摜(��)
		m_TutorialTextureSmall.Render(867, 45, recTutorialSelmin);

		//�Q�[���{�҉摜(��)
		m_TutorialTextureSmall.Render(867, 190, recGameSelmin);

		//�M�������[�摜(��)
		m_TutorialTextureBig.Render(803, 330, recGallerySelbig);

		//�I�v�V�����摜(��)
		m_TutorialTextureSmall.Render(867, 489, recOptionSelmin);

		//���ɏo���e�L�X�g�̉��n
		m_TutorialTextBox.Render(0, 612);

	
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recGalleryTex);
		}
		break;

	case 3:
		//�w�i�摜
		m_TutorialBG[3].Render(0, 0);

		//�`���[�g���A���摜(��)
		m_TutorialTextureSmall.Render(867, 45, recTutorialSelmin);

		//�Q�[���{�҉摜(��)
		m_TutorialTextureSmall.Render(867, 190, recGameSelmin);

		//�M�������[�摜(��)
		m_TutorialTextureSmall.Render(867, 337, recGallerySelmin);

		//�I�v�V�����摜(��)
		m_TutorialTextureBig.Render(803, 481, recOptionSelbig);

		//���ɏo���e�L�X�g�̉��n
		m_TutorialTextBox.Render(0, 612);

	
		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_TutorialTextTexture.Render(x, 644, recOptionTex);
		}

		
		break;
	}
}

void CModeSelect::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "���[�h�Z���N�g���");
	CGraphicsUtilities::RenderString(10, 40, "Enter�L�[�ŉ�ʑJ��");
}

void CModeSelect::Release(void)
{
	m_TutorialTextureSmall.Release();
	m_TutorialTextureBig.Release();
	for (int i = 0; i < 4; i++) 
	{
		m_TutorialBG[i].Release();
	}
	m_TutorialTextTexture.Release();
	m_TutorialTextBox.Release();
	gMenu.Release();

	g_MusicManager->BGMStop(BGMT_MOOP);

}