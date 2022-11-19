#include "Define.h"
#include "GameOver.h"


//�ύX����V�[���i�O���Q�ƁB���Ԃ�GameApp.cpp�j
extern int gChangeScene;

#define MenuCnt (2)

int GameOverCount = 0;

//�R���X�g���N�^
CGameOver::CGameOver() :
	m_BackTexture1(),
	m_BackTexture2(),
	m_BackTexture3(),
	m_UITexture(),
	m_SelectTexture(),
	Rondom(0.0f)
{

}

//�f�X�g���N�^
CGameOver::~CGameOver()
{

}

//�f�ރ��[�h
bool CGameOver::Load(void)
{
	if (!m_BackTexture1.Load("GameOverBG1.png"))
	{
		return false;
	}
	if (!m_BackTexture2.Load("GameOverBG2.png"))
	{
		return false;
	}
	if (!m_BackTexture3.Load("GameOverBG3.png"))
	{
		return false;
	}
	if (!m_UITexture.Load("GameOverUI.png"))
	{
		return false;
	}
	if (!m_SelectTexture.Load("GameOverSelect.png"))
	{
		return false;
	}

	return true;
}

//������
void CGameOver::Initialize(void)
{
	Rondom = CUtilities::Random(0, 3);
	Load();
}

//�X�V
void CGameOver::Update(void)
{
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		if (GameOverCount < MenuCnt - 1)
		{
			GameOverCount++;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		if (GameOverCount > 0)
		{
			GameOverCount--;
		}
	}


	//��߂�̃{�^����ŃG���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (GameOverCount == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}

	//�͂��߂���̃{�^����ŃG���^�[�L�[�ŃQ�[����ʂ�
	if (GameOverCount == 0 && g_pInput->IsKeyHold(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_GAME;
	}

	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_TITLE;
	}
}

//�`��
void CGameOver::Render(void)
{
	CRectangle Button1(0, 0, 479, 111);
	CRectangle Button2(0, 111, 479, 224);
	CRectangle Extex1(0, 224, 809, 293);
	CRectangle Extex2(0, 293, 809, 362);

	if (Rondom == 0)
	{
		m_BackTexture1.Render(0, 0);
	}
	else if (Rondom == 1)
	{
		m_BackTexture2.Render(0, 0);
	}
	else if (Rondom == 2)
	{
		m_BackTexture3.Render(0, 0);
	}

	m_UITexture.Render(140, 407, Button1);
	m_UITexture.Render(668, 407, Button2);

	if (GameOverCount == 0)
	{
		m_UITexture.Render(236, 629, Extex1);
		m_SelectTexture.Render(140, 407);
	}
	else if (GameOverCount == 1)
	{
		m_UITexture.Render(236, 629, Extex2);
		m_SelectTexture.Render(668, 407);
	}
}

void CGameOver::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "�Q�[���I�[�o�[���");
	CGraphicsUtilities::RenderString(10, 40, MOF_COLOR_BLACK, "�G���^�[�Ń��[�h�Z���N�g");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "F1�Ń^�C�g��");
}

void CGameOver::Release(void)
{
	m_BackTexture1.Release();
	m_BackTexture2.Release();
	m_BackTexture3.Release();
	m_UITexture.Release();
	m_SelectTexture.Release();
}
