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
	m_SelectTexture(),
	m_SelectDP()
{

}

//�f�X�g���N�^
CDPDecision::~CDPDecision()
{

}

//�f�ރ��[�h
bool CDPDecision::Load(void)
{

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("DPDecision");

	if (!m_BackTextureA.Load("DPDecision_BGA.png"))
	{
		return false;
	}

	if (!m_SelectTexture.Load("DPDecision_Select.png"))
	{
		return false;
	}

	if (!m_BackTextureC.Load("DPDecision_BGC.png"))
	{
		return false;
	}

	if (!m_TextTexture.Load("DPDecision_Text.png"))
	{
		return false;
	}

	if (!m_ExTexture.Load("DPDecision_ExText.png"))
	{
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;

}

//������
void CDPDecision::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{

	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	for (int i = 0; i < 5; i++)
	{
		m_SelectDP[i] = false;
	}
	Load();

	DPDecCnt = 0;

	m_Menu.Create(DPDecMenuItemCnt);

	flagD = true;

}

//�X�V
void CDPDecision::Update(void)
{
	//�߂�{�^���ɃJ�[�\���������āA�G���^�[�Ń��[�h�Z���N�g��ʂ�
	if (DPDecCnt == 5 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	if (flagD == true && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		flagD = false;
	}
	else if (m_Menu.IsShow())
	{
		m_Menu.Update();
		if (m_Menu.IsEnter())
		{
			if (m_Menu.GetSelect() == 0)
			{
				//�����Ńt���O���Q�[���Ɏ󂯓n���H

				//�Q�[����ʂ�
				m_bEnd = true;
				m_NextScene = SCENENO_GAME;

				//����
				m_Menu.Hide();
			}
			else if (m_Menu.GetSelect() == 1)
			{
				//������
				for (int i = 0; i < 5; i++)
				{
					m_SelectDP[i] = false;
				}
				m_Menu.Hide();
			}

		}
	}
	else if (DPDecCnt == 0 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SelectDP[0] = true;
		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else if (DPDecCnt == 1 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SelectDP[1] = true;
		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else if (DPDecCnt == 2 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SelectDP[2] = true;
		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else if (DPDecCnt == 3 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SelectDP[3] = true;
		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else if (DPDecCnt == 4 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_SelectDP[4] = true;
		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
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


	m_Menu.RenderB(m_SelectDP[0], m_SelectDP[1], m_SelectDP[2], m_SelectDP[3], m_SelectDP[4]);
}

//�f�o�b�N�`��
void CDPDecision::RenderDebug(void)
{
	for (int i = 0; i < 5; i++)
	{
		if (m_SelectDP[i] == true)
		{
			CGraphicsUtilities::RenderString(10, 50 * i, "m_SelectDP[%d]:True", i);
		}
		else if (m_SelectDP[i] == false)
		{
			CGraphicsUtilities::RenderString(10, 50 * i, "m_SelectDP[%d]:False", i);
		}
	}

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