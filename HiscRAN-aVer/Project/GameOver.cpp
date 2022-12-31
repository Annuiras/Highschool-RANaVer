#include "GameOver.h"


#define MenuCnt (2)

int GameOverCount = 0;

//�R���X�g���N�^
CGameOver::CGameOver() :
	m_BackTexture(),
	m_BackButton(),
	m_StartButton(),
	m_TextBack(),
	m_TextStart(),
	Rondom(0.0f)
{
}

//�f�X�g���N�^
CGameOver::~CGameOver()
{

}

//�f�ރ��[�h
void CGameOver::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("GameOver");

	if (!m_BackTexture.Load("GameOver_BG.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_BackButton.Load("GameOver_Button_End.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_StartButton.Load("GameOver_Button_Beginning.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_TextBack.Load("GameOver_Text_End.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_TextStart.Load("GameOver_Text_Beginning.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!m_ENDText.Load("GameOver_Text_flavor.png"))
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
void CGameOver::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//�e�}�l�[�W���[�Z�b�g
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

	//����ʕ\��
	m_BlackBakAlph = 255;
	m_WhiteBakAlph = 0;
	b_Fadein = FADE_IN;

	Rondom = CUtilities::Random(0, 3);

	//���݂̃V�[���Z�b�g
	m_NowScene = SCENENO_GAMEOVER;

	//�Q�[���I�[�o�[�������Z�b�g
	DPEND = b_GameProgMamt->GetGame_Over_HP();

}

//�X�V
void CGameOver::Update(void)
{

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_BlackBakAlph = FadeIn(m_BlackBakAlph, true);
		return;
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {
		m_bEnd = true;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {

		switch (m_NextScene)
		{
		case SCENENO_SELECTMODE:
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
			break;
		case SCENENO_GAME:
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
			break;
		default:
			break;
		}
		return;
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
		b_Fadein = FADE_OUT;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�͂��߂���̃{�^����ŃG���^�[�L�[�ŃQ�[����ʂ�
	if (GameOverCount == 0 && g_pInput->IsKeyHold(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
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
	m_BackTexture.Render(0, 0);

	if (HPEND)
	{
		m_ENDText.Render(PosXHPEND[Rondom], 140, recHPENDTex[Rondom]);
	}
	else 
	{
		m_ENDText.Render(PosXDPEND[Rondom], 140, recDPENDTex[Rondom]);
	}

	if (GameOverCount == 0)
	{
		m_StartButton.Render(133, 260);
		m_TextStart.Render(168, 618);
	}
	else if (GameOverCount == 1)
	{
		m_BackButton.Render(133, 260);
		m_TextBack.Render(168, 618);
	}

	//�t�F�[�h�A�E�g�Ó]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BlackBakAlph, 0, 0, 0));

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}

void CGameOver::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 10, MOF_COLOR_BLACK, "�Q�[���I�[�o�[���");
	CGraphicsUtilities::RenderString(10, 40, MOF_COLOR_BLACK, "�G���^�[�Ń��[�h�Z���N�g");
	CGraphicsUtilities::RenderString(10, 70, MOF_COLOR_BLACK, "F1�Ń^�C�g��");
}

void CGameOver::Release(void)
{
	m_BackButton.Release();
	m_BackTexture.Release();
	m_StartButton.Release();
	m_TextBack.Release();
	m_TextStart.Release();
	m_ENDText.Release();
}

