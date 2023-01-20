///////////////////////////////////////////
//�@�^�C�g����ʂ̃v���O�����ł�   �@�@�@//
//								   �@�@�@//
//�@�쐬�ҁF���Y���H  �@�@�@�@�@�@�@�@�@ //
//								   �@�@�@//
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@//
//								   �@�@�@//
//�@�ŏI�X�V�F2023/01/17		   �@�@�@//
///////////////////////////////////////////

#include "Title.h"

//�R���X�g���N�^
CTitle::CTitle() :
	m_BackTexture(),
	m_TitleTexture(),
	m_TiTleUITexture(),
	m_Scroll(0.0f),
	Rondom(0.0f),
	gAlpha(),
	isStop(),
	m_BakAlph(),
	m_Bak_Type()
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
	CUtilities::SetCurrentDirectoryA("Game/StageBak");

	//�w�i�e�N�X�`���̓ǂݍ���
	char* name[BACK_TYPE] =
	{
		"Stairs.png",
		"Wall_L.png",
		"Window_2.png",
		"Door_R.png",
		"Door_L.png"
	};

	for (int i = 0; i < BACK_TYPE; i++)
	{
		if (!m_BackTexture[i].Load(name[i]))
		{
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}


	CUtilities::SetCurrentDirectoryA("../../");

	CUtilities::SetCurrentDirectoryA("Title");

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
void CTitle::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;


	//������
	m_Scroll =200 /*m_BackTexture->GetWidth()*/;

	//��Ԃ�ݒ�
	b_Fadein = FADE_IN;
	m_BakAlph = 255;

	isStop = false;
	gAlpha = 0;

	//�����_�����l���擾
	for (int i = 0; i < 3; i++)
	{
		m_Bak_Type[i] = RandmuBak.GetRandomNumbe(0, BACK_TYPE - 1);
	}

	//���݂̃V�[��
	m_NowScene = SCENENO_TITLE;	
}

//�X�V
void CTitle::Update(void)
{

	//���ɃX�N���[�����Ă���
	m_Scroll -= SCROLL_SPEED;		
	//m_Scroll -=  + 10;

	
	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BakAlph = FadeIn(m_BakAlph, true);
		return;
	}

	//BGM�Đ�
	b_MusicManager->BGMStart(BGMT_TITLE);

	//���l�ύX����
	//�������������Ă�
	if (!isStop)
	{
		gAlpha += 3;

		if (gAlpha >= 255)
		{
			isStop = true;
		}
	}
	else
	{
		gAlpha -= 3;
		if (gAlpha <= 0)
		{
			isStop = false;
		}
	}

	//�G���^�[�L�[�ŃZ���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_BakAlph = FadeOut(m_BakAlph, true);
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		//���[�h�Z���N�g�ֈړ�
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

}

void CTitle::UpdateDebug(void)
{
}

//�`��
void CTitle::Render(void)
{
	//�e�N�X�`���̕`��
	int W = m_BackTexture->GetWidth();
	int scw = g_pGraphics->GetTargetWidth();

	if (m_Scroll <= 0) {

		//0�ȉ��ŏ�����
		m_Scroll = m_BackTexture->GetWidth();

		//���̔w�i��p��
		m_Bak_Type[0] = m_Bak_Type[1];
		m_Bak_Type[2] = RandmuBak.GetRandomNumbe(0, BACK_TYPE - 1);
		m_Bak_Type[1] = m_Bak_Type[2];

	}

	//�w�i�X�N���[������
	for (float x = ((int)m_Scroll % W) - W; x < scw; x += W)
	{
		if (x > 0)
		{
			m_BackTexture[m_Bak_Type[1]].Render(x, 0.0f);

		}
		else
		{
			m_BackTexture[m_Bak_Type[0]].Render(x, 0.0f);
		}
	}
	

	//�^�񒆂�Logo�`��
	m_TitleTexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 40);

	//�^�񒆂�UI�`��
	m_TiTleUITexture.Render(g_pGraphics->GetTargetWidth() * 0.5 - m_TitleTexture.GetWidth() * 0.5, 500, MOF_ARGB(gAlpha, 255, 255, 255));


	//�t�F�[�h�p���w�i
	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_BakAlph, 255, 255, 255));
}

void CTitle::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, "�^�C�g�����");
	CGraphicsUtilities::RenderString(10, 40, "Scroll%f",m_Scroll);
	CGraphicsUtilities::RenderLine(m_Scroll, 0, m_Scroll, WINDOWSIZE_HEIGHT,MOF_COLOR_BLUE);

}

void CTitle::Release(void)
{
	//�f�މ��
	for (int i = 0; i < BACK_TYPE; i++)
	{
		m_BackTexture[i].Release();
	}	
	
	m_TitleTexture.Release();
	m_TiTleUITexture.Release();
	gFont.Release();
	gFont2.Release();

	//BGM��~
	b_MusicManager->BGMStop(BGMT_TITLE);
}