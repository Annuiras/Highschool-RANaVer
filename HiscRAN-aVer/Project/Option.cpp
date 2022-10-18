#include "Option.h"
#include "Define.h"

//�ύX����V�[���i�O���Q�ƁA���Ԃ�GameApp.cpp�j
extern int			gChangeScene;

#define MenuCnt (3)

int OptionCnt = 0;
double VolumeBGM = 0;
double VolumeSE = 0;

double y_1 = 224;
double y_2 = 224;

bool flagBGM = false;
bool flagSE = false;
bool flagSC = false;

bool ScreenSize = false;

Option::Option() :
	m_BGM(),
	m_SE(),
	m_mount(),
	m_Stick1(),
	m_Stick2(),
	m_Button1_1(),
	m_Button1_2(),
	m_Button2(),
	m_Button3(),
	m_Select()
{

}

Option::~Option()
{

}

//�f�ޓǂݍ���
bool Option::Load(void)
{
	if (!m_BGM.Load("makiba no kaze.mp3"))
	{
		return false;
	}

	if (!m_SE.Load("Chime-Announce07-1.mp3"))
	{
		return false;
	}

	if (!m_mount.Load("Option_mount.png"))
	{
		return false;
	}

	if (!m_Stick1.Load("Option_stick.png"))
	{
		return false;
	}

	if (!m_Stick2.Load("Option_stick.png"))
	{
		return false;
	}

	if (!m_Button1_1.Load("Option_Button1.png"))
	{
		return false;
	}

	if (!m_Button1_2.Load("Option_Button1.png"))
	{
		return false;
	}

	if (!m_Button2.Load("Option_Button2.png"))
	{
		return false;
	}

	if (!m_Button3.Load("Option_Button3.png"))
	{
		return false;
	}

	if (m_Select.Load("Option_Select.png"))
	{
		return false;
	}

	return true;
}


//������
void Option::Initialize(void)
{
	m_BGM.SetLoop(TRUE);
	m_BGM.Play();
	VolumeBGM = m_BGM.GetVolume();
	VolumeSE = m_SE.GetVolume();
}

//�X�V
void Option::Update(void)
{
	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
		m_BGM.Stop();
	}
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		gChangeScene = SCENENO_SELECTMODE;
		m_BGM.Stop();

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

	if (OptionCnt == 1 && flagSE == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SE.Play();
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
		m_BGM.SetVolume(m_BGM.GetVolume() + 0.01f);
		VolumeBGM = m_BGM.GetVolume();
	}
	//���ʂ�������
	else if (flagBGM == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		m_BGM.SetVolume(m_BGM.GetVolume() - 0.01f);
		VolumeBGM = m_BGM.GetVolume();
	}

	if (m_BGM.GetVolume() < 1 && flagBGM == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		y_1 -= 2.5;
	}
	else if (m_BGM.GetVolume() > 0 && flagBGM == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		y_1 += 2.5;
	}



	//���ʂ��グ��
	if (flagSE == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		m_SE.SetVolume(m_SE.GetVolume() + 0.01f);
		VolumeSE = m_SE.GetVolume();
	}
	//���ʂ�������
	else if (flagSE == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		m_SE.SetVolume(m_SE.GetVolume() - 0.01f);
		VolumeSE = m_SE.GetVolume();
	}

	if (m_SE.GetVolume() < 1 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_UP))
	{
		y_2 -= 2.5;
	}
	else if (m_SE.GetVolume() > 0 && flagSE == true && g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		y_2 += 2.5;
	}

	//�t���X�N���[��
	if (flagSC == true && g_pInput->IsKeyPush(MOFKEY_1))
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
void Option::Render(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�I�v�V�������");
	CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 70, "0�L�[�Ń��[�h�Z���N�g��ʂ֑J��");
	CGraphicsUtilities::RenderString(10, 100, "BGM���ʁF%.2f", VolumeBGM);
	CGraphicsUtilities::RenderString(10, 130, "SE���ʁF%.2f", VolumeSE);
	CGraphicsUtilities::RenderString(100, 100, "SE���ʁF%f", y_1);


	m_mount.Render(145, 126);
	m_Stick1.Render(187, 206);
	m_Button1_1.Render(178, y_1);
	m_Stick2.Render(512, 206);
	m_Button1_2.Render(503, y_2);
	m_Button2.Render(639, 429);
	m_Button3.Render(912, 287);


	const char* MenuString[MenuCnt] =
	{
		"BGM����",
		"SE����",
		"Screen�T�C�Y"
	};

	CGraphicsUtilities::RenderString(10, 160, MenuString[0]);
	CGraphicsUtilities::RenderString(100, 160, MenuString[1]);
	CGraphicsUtilities::RenderString(500, 160, MenuString[2]);

	if (flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, "BGM�M���Ă�");
	}
	else if (!flagBGM)
	{
		CGraphicsUtilities::RenderString(10, 300, "BGM�M���ĂȂ�");
	}

	if (flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, "SE�M���Ă�");
	}
	else if (!flagSE)
	{
		CGraphicsUtilities::RenderString(10, 330, "SE�M���ĂȂ�");
	}

	if (flagSE && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CGraphicsUtilities::RenderString(10, 390, "SE�炵��");
	}
	else
	{
		CGraphicsUtilities::RenderString(10, 390, "SE�炵�ĂȂ�");
	}

	if (flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, "�X�N���[���M���Ă�");
	}
	else if (!flagSC)
	{
		CGraphicsUtilities::RenderString(10, 360, "�X�N���[���M���ĂȂ�");
	}

	if (ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, "�t���X�N���[��");
	}
	else if (!ScreenSize)
	{
		CGraphicsUtilities::RenderString(10, 420, "�E�B���h�E�T�C�Y");
	}



	switch (OptionCnt)
	{
	case 0:
		m_Select.Render(145, 126);
		CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_GREEN, MenuString[0]);
		if (flagBGM == true)
		{
			m_Select.Render(145, 126, MOF_COLOR_RED);
			CGraphicsUtilities::RenderString(10, 160, MOF_COLOR_RED, MenuString[0]);
		}
		break;

	case 1:
		m_Select.Render(475, 126);
		CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_GREEN, MenuString[1]);
		if (flagSE == true)
		{
			m_Select.Render(475, 126, MOF_COLOR_RED);
			CGraphicsUtilities::RenderString(100, 160, MOF_COLOR_RED, MenuString[1]);
		}
		break;

	case 2:
		m_Select.Render(805, 126);
		CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_GREEN, MenuString[2]);
		if (flagSC == true)
		{
			m_Select.Render(805, 126, MOF_COLOR_RED);
			CGraphicsUtilities::RenderString(500, 160, MOF_COLOR_RED, MenuString[2]);
		}
		break;

	}
}


//�f�މ��
void Option::Release(void)
{
	m_BGM.Release();
	m_SE.Release();
	m_Stick1.Release();
	m_Stick2.Release();
	m_Button1_1.Release();
	m_Button1_2.Release();
	m_Button2.Release();
	m_Button3.Release();
	m_mount.Release();
	m_Select.Release();
}