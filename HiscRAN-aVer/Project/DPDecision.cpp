#include "DPDecision.h"
#include "Define.h"



#define DPDecisionMenuCnt (6)

int DPDecCnt = 0;

int	DPDecMenuItemCnt = 2;

bool flagD = true;


//�R���X�g���N�^
CDPDecision::CDPDecision() :
	m_BackTextureA(),
	m_BackTextureC(),
	m_TextTexture(),
	m_SelectTexture()
{

}

//�f�X�g���N�^
CDPDecision::~CDPDecision()
{

}

//�f�ރ��[�h
void CDPDecision::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("DPDecision");

	if (!m_BackTextureA.Load("DPDecision_BGA.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_SelectTexture.Load("DPDecision_Select.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_BackTextureC.Load("DPDecision_BGC.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_TextTexture.Load("DPDecision_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_ExTexture.Load("DPDecision_ExText.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	b_LoadSitu = LOAD_COMP;

}

//������
void CDPDecision::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	for (int i = 0; i < 5; i++)
	{
		//m_SelectDP[i] = false;
	}

	//�f�ރ��[�h
	Load();
	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu != LOAD_ERROR) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}

	DPDecCnt = 0;
	flagD = true;

	//�t�F�[�h�C��
	m_WhiteBakAlph = 255;
	b_Fadein = FADE_IN;
}

//�X�V
void CDPDecision::Update(void)
{

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph,true);
		return;
	}


	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		//�߂�{�^��
		if (DPDecCnt == 5) {
			m_bEnd = true;
			m_NextScene = SCENENO_SELECTMODE;
		}
		else
		{
			//���ڂ�I��ł���
			m_bEnd = true;
			m_NextScene = SCENENO_GAME;
		}

	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}

	//�߂�{�^���ɃJ�[�\���������āA�G���^�[�Ń��[�h�Z���N�g��ʂ�
	if (DPDecCnt == 5 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}

	if (flagD == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		flagD = false;
	}
	else if (b_MenuMamt->IsShow())
	{
		b_MenuMamt->Update();
		if (b_MenuMamt->IsEnter())
		{
			if (b_MenuMamt->GetSelect() == 0)
			{
				//�����Ńt���O���Q�[���Ɏ󂯓n���H
				b_Fadein = FADE_OUT;
				b_GameProgMamt->SetDPdec_type(DPDecCnt);
				//����
				b_MenuMamt->Hide();
			}
			else if (b_MenuMamt->GetSelect() == 1)
			{
				//������
				for (int i = 0; i < 5; i++)
				{
					//m_SelectDP[i] = false;
				}
				b_MenuMamt->Hide();
			}

		}
	}
	else if (DPDecCnt == 0 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[0] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[1] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 2 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[2] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 3 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[3] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else if (DPDecCnt == 4 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//m_SelectDP[4] = true;
		b_MenuMamt->Show(MENUT_DPCONFIRM);
	}
	else
	{
		//���L�[�E�őI�����E�ɍs���悤�ɂ���
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			if (DPDecCnt < DPDecisionMenuCnt - 1)
			{
				DPDecCnt++;
			}
		}
		//���L�[���őI�������ɍs���悤�ɂ���
		else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
		{
			if (DPDecCnt > 0)
			{
				DPDecCnt--;
			}
		}
		//���L�[���őI����������悤�ɂ���
		//���ɉ����遁�R��̂��̂ɂȂ�
		if (g_pInput->IsKeyPush(MOFKEY_DOWN))
		{
			if (DPDecCnt < DPDecisionMenuCnt - 1 && DPDecCnt < 3)
			{
				DPDecCnt += 3;
			}
			else if (DPDecCnt == 3)
			{
				DPDecCnt = 3;
			}
		}

		//���L�[��őI�����オ��悤�ɂ���
		//��ɏオ�遁�R�O�̂��̂ɂȂ�
		if (g_pInput->IsKeyPush(MOFKEY_UP))
		{
			if (DPDecCnt > 0 && DPDecCnt - 3 >= 0)
			{
				DPDecCnt -= 3;
			}
		}

	}
}

//�`��
void CDPDecision::Render(void)
{
	//�z��̔ԍ���DP���̑Ή��͈ȉ��̒ʂ�ł��B
	//[0]���z����
	//[1]���s����
	//[2]������
	//[3]���R�~����
	//[4]���w��

	//�I���摜��`
	CRectangle recSelect[5] = { {0,0,300,300},{300,0,600,301},{600,0,900,300},{0,301,300,601},{300,301,600,601} };

	//�I���摜�\���ʒuX
	int	PosSelectX[5] = { 93,488,885,94,489 };
	//�I���摜�\���ʒuY
	int PosSelectY[5] = { 46,45,46,371,375 };

	//����������`
	CRectangle recExText[5] = { {0,0,343,259},{344,0,687,259},{688,0,1031,259},{0,259,344,518},{343,259,708,519} };

	//���������\���ʒuX
	int	PosTextX[5] = { 867,867,867,867,850 };
	//���������\���ʒuY
	int PosTextY = 397;

	m_BackTextureA.Render(0, 0);

	m_SelectTexture.Render(PosSelectX[DPDecCnt], PosSelectY[DPDecCnt], recSelect[DPDecCnt]);

	m_BackTextureC.Render(0, 0);

	m_TextTexture.Render(PosTextX[DPDecCnt], PosTextY, recExText[DPDecCnt]);

	if (flagD == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_ExTexture.Render(0, 200);
	}

	//���j���[�̕`��
	b_MenuMamt->Render(DPDecCnt);

	//�t�F�[�h�A�E�g
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}

//�f�o�b�N�`��
void CDPDecision::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 300, "DPDecCnt:%d", DPDecCnt);
}

void CDPDecision::Release(void)
{
	m_BackTextureA.Release();
	m_BackTextureC.Release();
	m_TextTexture.Release();
	m_SelectTexture.Release();
	m_ExTexture.Release();
}