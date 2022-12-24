#include "Title.h"


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
void CTitle::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Title");

	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BackTexture1.Load("TitleBG1.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_BackTexture2.Load("TitleBG2.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_BackTexture3.Load("TitleBG3.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�^�C�g�����S�ǂݍ���
	if (!m_TitleTexture.Load("GameLogo_s.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//�^�C�g��UI�ǂݍ���
	if (!m_TiTleUITexture.Load("TitleUI.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	b_LoadSitu = LOAD_COMP;
}

//������
void CTitle::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	//�e�}�l�[�W���[�Z�b�g
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;


	//������
	m_Scroll = 0;

	//��Ԃ�ݒ�
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	//�����_�����l���擾
	Rondom = CUtilities::Random(0, 3);

	//���݂̃V�[��
	m_NowScene = SCENENO_TITLE;	
}

//�X�V
void CTitle::Update(void)
{


	//���ɃX�N���[�����Ă���
	m_Scroll -= SCROLL_SPEED;

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, FADE_OUT_SPEED);
		return;
	}

	//BGM�Đ�
	g_MusicManager->BGMStart(BGMT_TITLE);

	//�G���^�[�L�[�ŃZ���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, FADE_OUT_SPEED);
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		//���[�h�Z���N�g�ֈړ�
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

}

//�`��
void CTitle::Render(void)
{
	//�����_���̒l���ƂɃe�N�X�`����ς���
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


	//�^�񒆂�Logo�`��
	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	//�^�񒆂�UI�`��
	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500);

	//�t�F�[�h�p���w�i
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));
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

	g_MusicManager->BGMStop(BGMT_TITLE);
}