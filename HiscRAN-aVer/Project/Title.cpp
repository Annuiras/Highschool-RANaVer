#include "GameApp.h"
#include "Title.h"

//�ύX����V�[���i�O���Q�ƁB���Ԃ�GameApp.cpp�j
extern int gChangeScene;

//�R���X�g���N�^
Title::Title() :
	m_BackTexture(),
	m_TitleTexture(),
	m_TiTleUITexture(),
	m_Scroll(0.0f)
{

}

//�f�X�g���N�^
Title::~Title()
{

}

//�f�ރ��[�h
bool Title::Load(void)
{
	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BackTexture.Load("rouka.png"))
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

	return true;

}

//������
void Title::Initialize(void)
{
	m_Scroll = 0;

}

//�X�V
void Title::Update(void)
{
	m_Scroll -= SCROLL_SPEED;

	//�G���^�[�L�[�ŃZ���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}

	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gChangeScene = SCENENO_GAME;
	}
}

//�`��
void Title::Render(void)
{
	//�e�N�X�`���̕`��
	int W = m_BackTexture.GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
	{
		m_BackTexture.Render(x, 0.0f);
	}

	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500);


	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "�^�C�g�����");
	CGraphicsUtilities::RenderString(10, 40,MOF_COLOR_BLACK, "Enter�L�[�ŉ�ʑJ��");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "F1�L�[�ŃQ�[����ʑJ��");
}

void Title::Release(void)
{
	m_BackTexture.Release();
	m_TitleTexture.Release();
	m_TiTleUITexture.Release();
	gFont.Release();
	gFont2.Release();
}