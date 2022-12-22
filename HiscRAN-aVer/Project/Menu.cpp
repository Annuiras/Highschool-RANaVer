#include "Menu.h"

//�R���X�g���N�^
CMenu::CMenu() :
	m_cx(0.0f),
	m_cy(0.0f),
	m_Count(0),
	m_Select(0),
	m_bShow(false),
	m_bEnter(false),
	m_Rect()
{

}

//�f�X�g���N�^
CMenu::~CMenu()
{

}

//����
void CMenu::Create(int cnt)
{
	//�Â��f�[�^�̉��
	Release();

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	if (!CUtilities::SetCurrentDirectoryA("Menu"))
		 false;

	m_MenuEndTexture.Load("Menu_BGEND.png");
	m_MenuPauseTexture.Load("Menu_BGPause.png");
	m_MenuDPTexture.Load("Menu_DPDecision.png");
	m_MenuDPTexTexture.Load("Menu_DPDecision_Text.png");
	m_MenuCheck.Load("Menu_Check.png");

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�����̕ύX��ۑ�
	m_Count = cnt;
}

//���
void CMenu::Release(void)
{
	m_Count = 0;
	m_MenuEndTexture.Release();
	m_MenuPauseTexture.Release();
	m_MenuDPTexture.Release();
	m_MenuDPTexTexture.Release();
	m_MenuCheck.Release();
}

//�\��
void CMenu::Show(float cx, float cy)
{
	m_cx = 371;
	m_cy = 159;
	m_bShow = true;
	m_bEnter = false;
	m_Select = 0;
}

//�X�V
void CMenu::Update(void)
{
	if (!m_bShow)
	{
		return;
	}

	//���E�̃L�[�őI��
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		m_Select--;
		if (m_Select < 0)
		{
			m_Select = m_Count - 1;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		m_Select++;
		if (m_Select >= m_Count)
		{
			m_Select = 0;
		}
	}

	//Enter�Ō���
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnter = true;
	}
}

//�`��
void CMenu::Render(int cnt)
{
	if (!m_bShow)
	{
		return;
	}

	//���j���[�̔w�i�`��
	if (cnt == 1)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuEndTexture.Render(m_cx, m_cy);

		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
	else if (cnt == 2)
	{
		m_MenuPauseTexture.Render(m_cx, m_cy);


		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}

}

void CMenu::RenderB(bool flag1, bool flag2, bool flag3, bool flag4, bool flag5)
{
	//�I���摜��`
	//�z��̔ԍ���DP���̑Ή��͈ȉ��̒ʂ�ł��B
	//[0]���w��
	//[1]���R�~����
	//[2]������
	//[3]���s����
	//[4]���z����
	CRectangle recText[5] = { {0,0,214,60},{0,60,254,120},{0,120,210,183},{0,183,255,246},{0,246,256,307} };

	if (!m_bShow)
	{
		return;
	}

	if (flag1 == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuDPTexture.Render(m_cx, m_cy);
		m_MenuDPTexTexture.Render(521, 275, recText[4]);

		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
	else if (flag2 == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuDPTexture.Render(m_cx, m_cy);
		m_MenuDPTexTexture.Render(523, 273, recText[3]);


		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
	else if (flag3 == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuDPTexture.Render(m_cx, m_cy);
		m_MenuDPTexTexture.Render(540, 275, recText[2]);


		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
	else if (flag4 == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuDPTexture.Render(m_cx, m_cy);
		m_MenuDPTexTexture.Render(521, 275, recText[1]);


		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
	else if (flag5 == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuDPTexture.Render(m_cx, m_cy);
		m_MenuDPTexTexture.Render(543, 275, recText[0]);


		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
}
