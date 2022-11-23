#include "Define.h"
#include "Title.h"

//�ύX����V�[���i�O���Q�ƁB���Ԃ�GameApp.cpp�j
extern int gChangeScene;

//�R���X�g���N�^
CTitle::CTitle() :
	m_BackTexture1(),
	m_BackTexture2(),
	m_BackTexture3(),
	m_TitleTexture(),
	m_TiTleUITexture(),
	m_Scroll(0.0f),
	Rondom(0.0f)
{

}

//�f�X�g���N�^
CTitle::~CTitle()
{

}

//�f�ރ��[�h
bool CTitle::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Title");

	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BackTexture1.Load("TitleBG1.png"))
	{
		return false;
	}

	if (!m_BackTexture2.Load("TitleBG2.png"))
	{
		return false;
	}

	if (!m_BackTexture3.Load("TitleBG3.png"))
	{
		return false;
	}

	if (!m_TitleTexture.Load("GameLogo_s.png"))
	{
		return false;
	}

	if (!m_TiTleUITexture.Load("TitleUI.png"))
	{
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;

}

//������
void CTitle::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_Scroll = 0;
	Rondom = CUtilities::Random(0, 3);
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;
	Load();
}

//�X�V
void CTitle::Update(void)
{
	m_Scroll -= SCROLL_SPEED;

	//�G���^�[�L�[�ŃZ���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}
}

//�`��
void CTitle::Render(void)
{
	if (Rondom == 0)
	{
		//�e�N�X�`���̕`��
		int W = m_BackTexture1.GetWidth();
		int scw = g_pGraphics->GetTargetWidth();

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_BackTexture1.Render(x, 0.0f);
		}
	}
	else if (Rondom == 1)
	{
		//�e�N�X�`���̕`��
		int W = m_BackTexture2.GetWidth();
		int scw = g_pGraphics->GetTargetWidth();

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_BackTexture2.Render(x, 0.0f);
		}
	}
	else if (Rondom == 2)
	{
		//�e�N�X�`���̕`��
		int W = m_BackTexture3.GetWidth();
		int scw = g_pGraphics->GetTargetWidth();

		for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
		{
			m_BackTexture3.Render(x, 0.0f);
		}
	}



	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500);

}

void CTitle::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�^�C�g�����");
	CGraphicsUtilities::RenderString(10, 40, "Enter�L�[�ŉ�ʑJ��");
}

void CTitle::Release(void)
{
	m_BackTexture1.Release();
	m_BackTexture2.Release();
	m_BackTexture3.Release();
	m_TitleTexture.Release();
	m_TiTleUITexture.Release();
	gFont.Release();
	gFont2.Release();
}