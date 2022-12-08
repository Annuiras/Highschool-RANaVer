#include "Option.h"
#include "Define.h"

//�ύX����V�[���i�O���Q�ƁA���Ԃ�GameApp.cpp�j
extern int			gChangeScene;

#define MenuCnt (4)

int OptionCnt = 0;

COption::COption() :
	m_Font1(),
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
	m_BackButton(),
	VolumeBGM(0.5),
	VolumeSE(0.5),
	y_1(407),
	y_2(407),
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
bool COption::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Option");

	//�y��
	if (!m_mount.Load("Option_mount.png"))
	{
		return false;
	}

	//BGM�����{�^��
	if (!m_Button1_1.Load("Option_slide.png"))
	{
		return false;
	}

	//SE�����{�^��
	if (!m_Button1_2.Load("Option_slide.png"))
	{
		return false;
	}

	//SE�Đ��{�^��
	if (!m_Button2.Load("Option_Button_SE.png"))
	{
		return false;
	}

	//Screen�T�C�Y�����{�^��
	if (!m_Button3_Win.Load("Option_Button_Win.png"))
	{
		return false;
	}

	if (!m_Button3_Full.Load("Option_Button_Full.png"))
	{
		return false;
	}

	//�I��g
	if (!m_Select_BGM.Load("Option_Sbgm.png"))
	{
		return false;
	}

	if (!m_Select_SE.Load("Option_Sse.png"))
	{
		return false;
	}

	if (!m_Select_Screen.Load("Option_Sscreen.png"))
	{
		return false;
	}


	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�������I��g
	if (!m_Select_s.Load("Select_s.png"))
	{
		return false;
	}

	//�߂�{�^��
	if (!m_BackButton.Load("BackButton.png"))
	{
		return false;
	}

	return true;
}


//������
void COption::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	Load();

	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//�t�H���g
	m_Font1.Create(35, "UD �f�W�^�� ���ȏ��� N-B");

	g_MusicManager->InitializeIn_middle(VolumeSE, VolumeBGM);
	//g_MusicManager->BGMLoop(BGMT_OP, true);
	//g_MusicManager->BGMStart(BGMT_OP);

	//BGM�ɑI��g�����킹�Ă���
	OptionCnt = 0;

	g_MusicManager->BGMStart(BGMT_MOOP);

}

//�X�V
void COption::Update(void)
{
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//�߂�{�^���Ń��[�h�Z���N�g��ʂ�
	//Enter�Ŗ߂邩�͌�����
	if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
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
	}
	//���L�[���ō��ɍs���悤�ɂ���
	else if (g_pInput->IsKeyPush(MOFKEY_LEFT) && flagBGM == false && flagSE == false && flagSC == false)
	{
		if (OptionCnt > 0)
		{
			OptionCnt--;
		}
	}

	//�߂�{�^���ɃJ�[�\���������āA��{�^������������BGM�ɑI��g���s��
	if (OptionCnt == 3 && g_pInput->IsKeyPush(MOFKEY_UP) && flagBGM == false && flagSE == false && flagSC == false)
	{
		OptionCnt = 0;
	}
	//���{�^������������߂�{�^���ɍs��
	else if (g_pInput->IsKeyPush(MOFKEY_DOWN) && flagBGM == false && flagSE == false && flagSC == false)
	{
		OptionCnt = 3;
	}


	//BGM���ʐݒ�ɃJ�[�\��������������ԂŁA�X�y�[�X�L�[���������ꍇ
	if (OptionCnt == 0 && g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		if (flagBGM)
		{
			//�I���ς݂ɂȂ��Ă���ꍇ�͑I����������
			flagBGM = false;
		}
		else
		{
			//�I�������ɂȂ��Ă���ꍇ�͑I���ς݂ɂ���
			flagBGM = true;
		}
	}

	//SE���ʐݒ�ɃJ�[�\��������������ԂŁA�X�y�[�X�L�[���������ꍇ
	if (OptionCnt == 1 && g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		if (flagSE)
		{
			//�I���ς݂ɂȂ��Ă���ꍇ�͑I����������
			flagSE = false;
		}
		else
		{
			//�I�������ɂȂ��Ă���ꍇ�͑I���ς݂ɂ���
			flagSE = true;
		}
	}

	//�G���^�[�ŉ���炷
	if (OptionCnt == 1 && flagSE == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		g_MusicManager->SEStart(SE_T_OPTION_CHIME);
	}

	//BGM���ʐݒ�ɃJ�[�\��������������ԂŁA�X�y�[�X�L�[���������ꍇ
	if (OptionCnt == 2 && g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		if (flagSC)
		{
			//�I���ς݂ɂȂ��Ă���ꍇ�͑I����������
			flagSC = false;
		}
		else
		{
			//�I�������ɂȂ��Ă���ꍇ�͑I���ς݂ɂ���
			flagSC = true;
		}
	}


	//���ʂ��グ��
	if (flagBGM == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		g_MusicManager->BGMSetVolume(g_MusicManager->GetBGMVolume() + 0.01f);
		VolumeBGM = g_MusicManager->GetBGMVolume();
	}
	//���ʂ�������
	else if (flagBGM == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		g_MusicManager->BGMSetVolume(g_MusicManager->GetBGMVolume() - 0.01f);
		VolumeBGM = g_MusicManager->GetBGMVolume();
	}

	//BGM���߃{�^���̏グ����
	if (g_MusicManager->GetBGMVolume() < 1 && flagBGM == true && g_pInput->IsKeyHold(MOFKEY_UP) && y_1 >= 200)
	{
		y_1 -= 3.0;
	}
	else if (g_MusicManager->GetBGMVolume() > 0 && flagBGM == true && g_pInput->IsKeyHold(MOFKEY_DOWN) && y_1 <= 542)
	{
		y_1 += 3.0;
	}



	//SE�̉��ʂ��グ��
	if (g_MusicManager->GetSEVolume() < 1 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		g_MusicManager->SESetVolume(g_MusicManager->GetSEVolume() + 0.01f);
		VolumeSE = g_MusicManager->GetSEVolume();
	}
	//SE�̉��ʂ�������
	else if (g_MusicManager->GetSEVolume() > 0 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		g_MusicManager->SESetVolume(g_MusicManager->GetSEVolume() - 0.01f);
		VolumeSE = g_MusicManager->GetSEVolume();
	}

	//SE�����{�^���̏グ����
	if (g_MusicManager->GetSEVolume() < 1 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_UP) && y_2 >= 242)
	{
		y_2 -= 3.0;
	}
	else if (g_MusicManager->GetSEVolume() > 0 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_DOWN) && y_2 <= 542)
	{
		y_2 += 3.0;
	}

	//�t���X�N���[��
	if (flagSC == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
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

//�`��
void COption::Render(void)
{
	//�y��`��
	m_mount.Render(241, 116);

	//���ʃ{�^���`��
	m_Button1_1.Render(365, y_1);
	m_Button1_2.Render(520, y_2);

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
		if (flagBGM == true)
		{
			m_Select_BGM.Render(375, 181, redBGM);
		}
		break;

		//SE
	case 1:
		m_Select_SE.Render(543, 183, yellowSE);
		if (flagSE == true)
		{
			m_Select_SE.Render(543, 183, redSE);
		}

		if (flagSE == true && g_pInput->IsKeyHold(MOFKEY_RETURN))
		{
			m_Button2.Render(622, 414, MOF_ARGB(155, 20, 20, 20));
		}
		break;

		//Screen�T�C�Y
	case 2:
		m_Select_Screen.Render(815, 340, yellowScreen);
		if (flagSC == true)
		{
			m_Select_Screen.Render(815, 340, redScreen);
		}
		break;

		//�߂�{�^��
	case 3:
		m_Select_s.Render(60, 650);
		break;

	}
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
	CGraphicsUtilities::RenderString(100, 100, MOF_COLOR_BLACK, "SE���ʁF%f", y_1);

	CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_BLACK, "BGM����");
	CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_BLACK, "SE����");
	CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_BLACK, "�X�N���[���T�C�Y");

	switch (OptionCnt)
	{
	case 0:
		CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_GREEN, "BGM����");
		if (flagBGM == true)
		{
			CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_RED, "BGM����");
		}
		break;

	case 1:
		CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_GREEN, "SE����");
		if (flagSE == true)
		{
			CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_RED, "SE����");
		}
		break;

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
	g_MusicManager->BGMSetVolume(VolumeBGM);
	g_MusicManager->SESetVolume(VolumeSE);

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

	g_MusicManager->SEALLStop();
	g_MusicManager->BGMStop(BGMT_MOOP);

}