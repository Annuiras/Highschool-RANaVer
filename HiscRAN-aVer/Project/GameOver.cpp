#include "Define.h"
#include "GameOver.h"


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
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("GameOver");

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

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//������
void CGameOver::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//����ʕ\��
	m_Alpha = 255;

	//���ڏ��
	m_FadeOutflg = false;

	Rondom = CUtilities::Random(0, 3);
	Load();


}

//�X�V
void CGameOver::Update(void)
{

	//��ʊJ�n���t�F�[�h�C��
	if (!m_FadeOutflg) {
		//�l����
		m_Alpha -= FADE_OUT_SPEED+2;
		if (m_Alpha <= 0) {
			m_Alpha = 0;
			m_FadeOutflg = true;
		}
	}

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
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�͂��߂���̃{�^����ŃG���^�[�L�[�ŃQ�[����ʂ�
	if (GameOverCount == 0 && g_pInput->IsKeyHold(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAME;
	}

	//F1�L�[�Ń^�C�g����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
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

	//��ʑJ�ڗp�̍����
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_Alpha, 0, 0, 0));

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

