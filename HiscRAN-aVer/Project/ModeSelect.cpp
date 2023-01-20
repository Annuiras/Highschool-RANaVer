///////////////////////////////////////////
//�@���[�h�Z���N�g��ʂ̃v���O�����ł�   //
//								   �@�@�@//
//�@�쐬�ҁF���Y���H�@�@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/17		   �@�@�@//
///////////////////////////////////////////

#include "ModeSelect.h"

//�R���X�g���N�^
CModeSelect::CModeSelect() :
	m_TutorialTextureSmall(),
	m_TutorialTextureBig(),
	m_TutorialBG(),
	m_TutorialTextBox(),
	m_TutorialTextTexture(),
	MenuNow_Mode(),
	m_BakAlph(),
	m_Scroll(0.0f)
{

}

//�f�X�g���N�^
CModeSelect::~CModeSelect()
{

}

//���[�h
void CModeSelect::Load()
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("ModeSelect");

	if (!m_TutorialTextureSmall.Load("ModeSelect_Min.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	
	if (!m_TutorialTextureBig.Load("ModeSelect_Big.png")) 
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialTextTexture.Load("ModeSelect_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialTextBox.Load("ModeSelect_TextBox.png")) 
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialBG[0].Load("ModeSelect_AddmissionEx_BG.png")) 
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialBG[1].Load("ModeSelect_Addmission_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	
	if (!m_TutorialBG[2].Load("ModeSelect_Library_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TutorialBG[3].Load("ModeSelect_Broadcasting_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���[�h����
	b_LoadSitu = LOAD_COMP;
}

//������
void  CModeSelect::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//��ʉ������X�N���[���l������
	m_Scroll = 500;
	
	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//�f�ރ��[�h
	Load();

	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu == LOAD_COMP) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}

	//���݂̃V�[��
	m_NowScene = SCENENO_SELECTMODE;

	//�t�F�[�h�C���p������
	m_BakAlph = 255;

	//�t�F�[�h���
	b_Fadein = FADE_IN;


}


//�X�V
void CModeSelect::Update()
{
	//BGM�Đ�
	b_MusicManager->BGMStart(BGMT_MOOP);

	//���Z�b�g
	if (m_Scroll <= -1845) {
		m_Scroll = 1845;
	}
	//��ʉ������X�N���[��
	m_Scroll -= SCROLL_SPEED;

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}


	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {
		switch (MenuNow_Mode)
		{
		case 0:
			//���w�������
			m_bEnd = true;
			m_NextScene = SCENENO_TUTORIAL;
			break;

		case 1:
			//���w
			m_bEnd = true;
			m_NextScene = SCENENO_DPDECISION;
			break;

		case 2:
			//�}����
			m_bEnd = true;
			m_NextScene = SCENENO_GALLERY;
			break;

		case 3:
			//������
			m_bEnd = true;
			m_NextScene = SCENENO_OPTION;
			break;
		}
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}


	//���j���[�̍X�V
	if (b_MenuMamt->IsShow())
	{
		//�X�V
		b_MenuMamt->Update();

		//���ڑI����
		if (b_MenuMamt->IsEnter())
		{
			if (b_MenuMamt->GetSelect() == 0)
			{
				//�A�v���P�[�V�����I��
				PostQuitMessage(0);
			}

			//���j���[��\��
			b_MenuMamt->Hide();
		}

		return;
	}
	//�G�X�P�[�v�L�[�ŏI�����j���[��\��
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		b_MenuMamt->Show(MENUT_END);
	}


	//���L�[���őI����������悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		b_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode < MenuCnt - 1)
		{
			++MenuNow_Mode;
		}
	}
	//���L�[��őI�����オ��悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		b_MusicManager->SEStart(SE_T_MOOP_CURSORMOVE);
		if (MenuNow_Mode > 0)
		{
			--MenuNow_Mode;
		}
	}

	//�G���^�[����������e��ʂֈړ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_MusicManager->SEStart(SE_T_DECISION);
		b_Fadein = FADE_OUT;
	}
}


void CModeSelect::UpdateDebug(void)
{

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

	b_MenuMamt->Render();

	//�t�F�[�h�A�E�g
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BakAlph, 255, 255, 255));


}

void CModeSelect::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "���[�h�Z���N�g���");
	CGraphicsUtilities::RenderString(10, 40, "Enter�L�[�ŉ�ʑJ��");
	CGraphicsUtilities::RenderString(10, 70, "Scroll%f",m_Scroll);

	CGraphicsUtilities::RenderLine(m_Scroll, 0, m_Scroll, WINDOWSIZE_HEIGHT, MOF_COLOR_BLUE);
}

//���
void CModeSelect::Release(void)
{
	//�f�ފJ��
	m_TutorialTextureSmall.Release();
	m_TutorialTextureBig.Release();
	for (int i = 0; i < 4; i++) 
	{
		m_TutorialBG[i].Release();
	}
	m_TutorialTextTexture.Release();
	m_TutorialTextBox.Release();

	//BGM�X�g�b�v
	b_MusicManager->BGMStop(BGMT_MOOP);

}

