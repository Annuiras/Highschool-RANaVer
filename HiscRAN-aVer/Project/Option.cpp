///////////////////////////////////////////
//�@�I�v�V������ʂ̃v���O�����ł�   �@�@//
//								   �@�@�@//
//�@�쐬�ҁF���Y���H  �@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/17		   �@�@�@//
///////////////////////////////////////////

#include "Option.h"

COption::COption() :
	m_Font1(),
	m_BG(),
	m_mount(),
	m_Button1_1(),
	m_Button1_2(),
	m_Button2(),
	m_Button3_Win(),
	m_Button3_Full(),
	m_Select_BGM(),
	m_Select_SE(),
	m_Select_Screen(),
	m_Select_s(),
	m_ExTexture(),
	m_BackButton(),
	VolumeBGM(0.0),
	VolumeSE(0.0),
	Botton_BGMPosy(0.0),
	Botton_SEPosy(0.0),
	flagBGM(false),
	flagSE(false),
	flagSC(false),
	ScreenSize(false)
{

}

COption::~COption()
{

}

//�f�ޓǂݍ���
void COption::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Option");

	//�w�i
	if (!m_BG.Load("Option_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�y��
	if (!m_mount.Load("Option_mount.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//BGM�����{�^��
	if (!m_Button1_1.Load("Option_slide.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//SE�����{�^��
	if (!m_Button1_2.Load("Option_slide.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//SE�Đ��{�^��
	if (!m_Button2.Load("Option_Button_SE.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//Screen�T�C�Y�����{�^��
	if (!m_Button3_Win.Load("Option_Button_Win.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_Button3_Full.Load("Option_Button_Full.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�I��g
	if (!m_Select_BGM.Load("Option_Sbgm.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�I�����Ă邩���ĂȂ����摜
	if (!m_Select_SE.Load("Option_Sse.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�I�����Ă邩���ĂȂ����摜
	if (!m_Select_Screen.Load("Option_Sscreen.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//����
	if (!m_ExTexture.Load("Option_Ex.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�߂�{�^���I��g
	if (!m_Select_s.Load("BackButton_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�߂�{�^��
	if (!m_BackButton.Load("BackButton.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���[�h����
	b_LoadSitu = LOAD_COMP;
}


//������
void COption::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{

	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;

	//�f�ރ��[�h
	Load();
	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu != LOAD_ERROR) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}

	//�t�H���g
	m_Font1.Create(35, "UD �f�W�^�� ���ȏ��� N-B");

	//�{�����[���擾
	VolumeBGM = b_MusicManager->GetBGMVolume();
	VolumeSE = b_MusicManager->GetSEVolume();

	//BGM�ɑI��g�����킹�Ă���
	OptionCnt = 0;

	//BGM�Đ�
	b_MusicManager->BGMLoop(BGMT_MOOP, true);
	b_MusicManager->BGMStart(BGMT_MOOP);

	//��ԏ�ɃZ�b�g
	Botton_BGMPosy = 485.0;
	Botton_SEPosy = 485.0;

	//�{�^�����W������
	if (b_GameProgMamt->GetOption_Button_Pos(0) > 0)
	{
		Botton_BGMPosy = b_GameProgMamt->GetOption_Button_Pos(0);
	}
	if (b_GameProgMamt->GetOption_Button_Pos(1) > 0)
	{
		Botton_SEPosy = b_GameProgMamt->GetOption_Button_Pos(1);
	}
	
	//���݂̃V�[���Z�b�g
	m_NowScene = SCENENO_OPTION;

	//�t�F�[�h��Ԃ�ݒ�
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

}

//�X�V
void COption::Update(void)
{

	UpdateDebug();

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		b_GameProgMamt->SetOption_Button_Pos(Botton_BGMPosy, Botton_SEPosy);
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
		return;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
		return;
	}


	//�߂�{�^���Ń��[�h�Z���N�g��ʂ�
	//Enter�Ŗ߂邩�͌�����
	if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	//���L�[�E�őI�����E�ɍs���悤�ɂ���
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//���j���[�J�E���g���I�v�V�����J�E���g���傫���ABGM�ESE�E�X�N���[���T�C�Y�ύX���I���ɂȂ��Ă��Ȃ��ꍇ
		if (OptionCnt < MenuCnt - 1 && flagBGM == false && flagSE == false && flagSC == false)
		{
			//�E�ɍs�����Ƃ��ł���
			OptionCnt++;
		}
		else if (OptionCnt == 3)
		{
			OptionCnt = 0;
		}

	}
	//���L�[���ō��ɍs���悤�ɂ���
	else if (g_pInput->IsKeyPush(MOFKEY_LEFT) && flagBGM == false && flagSE == false && flagSC == false)
	{
		if (OptionCnt > 0)
		{
			OptionCnt--;
		}
		else if (OptionCnt == 0)
		{
			OptionCnt = 3;
		}
	}

	//�߂�{�^���ɃJ�[�\���������āA��{�^������������BGM�ɑI��g���s��
	if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_UP))
	{
		OptionCnt = 0;
	}
	//���{�^������������߂�{�^���ɍs��
	else if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		OptionCnt = 3;
	}


	//BGM���ʂ��グ��
	if (OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		b_MusicManager->BGMSetVolume(b_MusicManager->GetBGMVolume() + 0.01f);
		VolumeBGM = b_MusicManager->GetBGMVolume();
	}
	//���ʂ�������
	else if (OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		b_MusicManager->BGMSetVolume(b_MusicManager->GetBGMVolume() - 0.01f);
		VolumeBGM = b_MusicManager->GetBGMVolume();
	}

	//BGM���߃{�^���̏グ����
	if (OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_UP) && Botton_BGMPosy >= 242)
	{
		Botton_BGMPosy -= 3.0;
	}
	else if (OptionCnt == 0 && g_pInput->IsKeyHold(MOFKEY_DOWN) && Botton_BGMPosy <= 542)
	{
		Botton_BGMPosy += 3.0;
	}


	//SE�̉��ʂ��グ��
	if (b_MusicManager->GetSEVolume() < 1 && OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		b_MusicManager->SESetVolume(b_MusicManager->GetSEVolume() + 0.01f);
		VolumeSE = b_MusicManager->GetSEVolume();
	}
	//SE�̉��ʂ�������
	else if (b_MusicManager->GetSEVolume() > 0 && OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		b_MusicManager->SESetVolume(b_MusicManager->GetSEVolume() - 0.01f);
		VolumeSE = b_MusicManager->GetSEVolume();
	}

	//SE�����{�^���̏グ����
	if (OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_UP) && Botton_SEPosy >= 242)
	{
		Botton_SEPosy -= 3.0;
	}
	else if (OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_DOWN) && Botton_SEPosy <= 542)
	{
		Botton_SEPosy += 3.0;
	}

	//SE�Đ�
	if (OptionCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_MusicManager->SEStart(SE_T_OPTION_CHIME);
	}


	//�t���X�N���[��
	if (OptionCnt == 2 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		g_pGraphics->ChangeScreenMode();
		if (ScreenSize)
		{
			//�E�B���h�E����ɂ���
			ScreenSize = false;
		}
		else
		{
			//�t���X�N���[������ɂ���
			ScreenSize = true;
		}
	}
}

void COption::UpdateDebug(void) {

	//�����\��
	if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		if (flag == true)
		{
			flag = false;
		}
		else
		{
			flag = true;
		}
	}

}

//�`��
void COption::Render(void)
{
	//�w�i�摜
	m_BG.Render(0, 0);

	//�y��`��
	m_mount.Render(241, 116);

	//���ʃ{�^���`��
	m_Button1_1.Render(365, Botton_BGMPosy);
	m_Button1_2.Render(520, Botton_SEPosy);

	//SE�Đ��{�^���`��
	m_Button2.Render(622, 414);

	if (OptionCnt != 1)
	{
		m_Button2.Render(622, 414, MOF_ARGB(155, 20, 20, 20));
	}

	//�߂�{�^��
	m_BackButton.Render(60, 650);

	//����Screen�T�C�Y���t���X�N���[���Ȃ�
	if (ScreenSize)
	{
		//�t���X�N���[���{�^����\��
		m_Button3_Full.Render(803, 377);
	}
	//��������Ȃ����
	else if (!ScreenSize)
	{
		//���̂܂�
		m_Button3_Win.Render(803, 377);
	}

	//���j���[���e
	const char* MenuString[MenuCnt] =
	{
		"BGM����",
		"SE����",
		"Screen�T�C�Y"
	};

	////�������͌�����j���[�Ǝ��������Ŏ������܂��B
	//m_Font1.RenderString(267, 8, MOF_COLOR_BLACK, "�X�y�[�X�L�[�Œ������������ڂ�I���A�I���̉������ł��܂��B\n�㉺���łŃX���C�_�[���������܂��B\n�{�^���̓G���^�[�L�[�œ������܂��B\n�߂�Ń��[�h�Z���N�g��ʂɖ߂邱�Ƃ��ł��܂���B");
	//m_Font1.RenderString(260, 135, MOF_COLOR_BLACK, MenuString[0]);
	//m_Font1.RenderString(600, 135, MOF_COLOR_BLACK, MenuString[1]);
	//m_Font1.RenderString(880, 135, MOF_COLOR_BLACK, MenuString[2]);
	//m_Font1.RenderString(940, 325, MOF_COLOR_BLACK, "Full");
	//m_Font1.RenderString(950, 453, MOF_COLOR_BLACK, "Win");
	//m_Font1.RenderString(786, 620, MOF_COLOR_BLACK, "�@�B�͑�؂Ɉ����܂��傤�B\n�����ψ���");

	CRectangle redBGM(0, 0, 51, 20);
	CRectangle yellowBGM(0, 20, 51, 40);
	CRectangle redScreen(0, 0, 74, 19);
	CRectangle yellowScreen(0, 19, 74, 38);
	CRectangle redSE(0, 0, 28, 20);
	CRectangle yellowSE(0, 20, 28, 40);

	//������ϐ��ɂ���ĕς���
	switch (OptionCnt)
	{
		//BGM
	case 0:
		m_Select_BGM.Render(375, 181, yellowBGM);
		/*if (flagBGM == true)
		{
			m_Select_BGM.RenderLoad(375, 181,redBGM);
		}*/
		break;

		//SE
	case 1:
		m_Select_SE.Render(543, 183, yellowSE);
		/*if (OptionCnt==1)
		{
			m_Select_SE.RenderLoad(543, 183, redSE);
		}*/

		if (OptionCnt == 1 && g_pInput->IsKeyHold(MOFKEY_RETURN))
		{
			m_Button2.Render(622, 414, MOF_ARGB(155, 20, 20, 20));
		}
		break;

		//Screen�T�C�Y
	case 2:
		m_Select_Screen.Render(815, 340, yellowScreen);
		/*if (flagSC == true)
		{
			m_Select_Screen.RenderLoad(815, 340,redScreen);
		}*/
		break;

		//�߂�{�^��
	case 3:
		m_Select_s.Render(60, 650);
		break;

	}

	if (flag != false)
	{
		m_ExTexture.Render(0, 0);
	}

	//�t�F�[�h�p���w�i
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));

}

//�f�o�b�O
void COption::RenderDebug(void)
{
	if (flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, MOF_COLOR_BLACK, "BGM�M���Ă�");
	}
	else if (!flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, MOF_COLOR_BLACK, "BGM�M���ĂȂ�");
	}

	if (flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, MOF_COLOR_BLACK, "SE�M���Ă�");
	}
	else if (!flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, MOF_COLOR_BLACK, "SE�M���ĂȂ�");
	}

	if (flagSE && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CGraphicsUtilities::RenderString(10, 390, MOF_COLOR_BLACK, "SE�炵��");
	}
	else
	{
		CGraphicsUtilities::RenderString(10, 390, MOF_COLOR_BLACK, "SE�炵�ĂȂ�");
	}

	if (flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, MOF_COLOR_BLACK, "�X�N���[���M���Ă�");
	}
	else if (!flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, MOF_COLOR_BLACK, "�X�N���[���M���ĂȂ�");
	}

	if (ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, MOF_COLOR_BLACK, "�t���X�N���[��");
	}
	else if (!ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, MOF_COLOR_BLACK, "�E�B���h�E�T�C�Y");
	}

	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "�I�v�V�������");
	CGraphicsUtilities::RenderString(10, 40, MOF_COLOR_BLACK, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "0�L�[�Ń��[�h�Z���N�g��ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "BGM���ʁF%.2f", VolumeBGM);
	CGraphicsUtilities::RenderString(10, 130, MOF_COLOR_BLACK, "SE���ʁF%.2f", VolumeSE);

	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "BGM���� : %f", Botton_BGMPosy);
	CGraphicsUtilities::RenderString(10, 220, MOF_COLOR_BLACK, "SE���ʁF%f", Botton_SEPosy);
	CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_BLACK, "�X�N���[���T�C�Y");

	switch (OptionCnt)
	{

	case 2:
		CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_GREEN, "�X�N���[���T�C�Y");
		if (flagSC == true)
		{
			CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_RED, "�X�N���[���T�C�Y");
		}
		break;
	}
}


//�f�މ��
void COption::Release(void)
{
	b_MusicManager->BGMSetVolume(VolumeBGM);
	b_MusicManager->SESetVolume(VolumeSE);

	m_Button1_1.Release();
	m_Button1_2.Release();
	m_Button2.Release();
	m_Button3_Full.Release();
	m_Button3_Win.Release();
	m_mount.Release();
	m_Select_BGM.Release();
	m_Select_SE.Release();
	m_Select_Screen.Release();
	m_Select_s.Release();
	m_BackButton.Release();
	m_Font1.Release();
	m_BG.Release();
	m_ExTexture.Release();
	b_MusicManager->SEALLStop();
	b_MusicManager->BGMStop(BGMT_MOOP);

}