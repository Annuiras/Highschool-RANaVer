#include "Menu.h"

//�R���X�g���N�^
CMenu::CMenu() :
	m_MenuTexture(),
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

	m_MenuTexture.Load("Menu.png");

	m_MenuText.Load("Menu_text.png");

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�����̕ύX��ۑ�
	m_Count = cnt;
}

//���
void CMenu::Release(void)
{
	m_Count = 0;
	m_Rect = CRectangle(0, 0, 0, 0);
	m_MenuTexture.Release();
	m_MenuText.Release();
}

//�\��
void CMenu::Show(float cx, float cy)
{
	m_cx = cx;
	m_cy = cy;
	m_bShow = true;
	m_bEnter = false;
	m_Select = 0;
	float w = m_MenuTexture.GetWidth();
	float h = m_MenuTexture.GetHeight();

	m_Rect.Top = m_cy - h * 0.5f;
	m_Rect.Bottom = m_Rect.Top + h;
	m_Rect.Left = m_cx - w * 0.5f;
	m_Rect.Right = m_Rect.Left + w;
}

//�X�V
void CMenu::Update(void)
{
	if (!m_bShow)
	{
		return;
	}

	//�㉺�̃L�[�őI��
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		m_Select--;
		if (m_Select < 0)
		{
			m_Select = m_Count - 1;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_DOWN))
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

	//��`�ݒ�
	CRectangle MenuTitle1(0, 0, 495, 116);
	CRectangle MenuTitle2(0, 116, 396, 230);

	CRectangle MenuSelecttex1(0, 232, 163, 328);
	CRectangle MenuSelecttex2(0, 328, 348, 430);

	CRectangle MenuSelecttex3(0, 430, 261, 532);
	CRectangle MenuSelecttex4(222, 225, 569, 326);

	CRectangle MenuExtex1(0, 532, 490, 590);
	CRectangle MenuExtex2(0, 590, 637, 648);
	CRectangle MenuExtex3(0, 648, 440, 706);

	//���j���[�̔w�i�`��
	m_MenuTexture.Render(258, 61);

	if (cnt == 1)
	{
		m_MenuText.Render(393, 71, MenuTitle1);


		if (m_Select == 0)
		{
			m_MenuText.Render(558, 247, MenuSelecttex1);
			m_MenuText.Render(466, 403, MenuSelecttex2, MOF_ARGB(135, 20, 20, 20));
			m_MenuText.Render(395, 588, MenuExtex1);
		}
		else if (m_Select == 1)
		{
			m_MenuText.Render(466, 403, MenuSelecttex2);
			m_MenuText.Render(558, 247, MenuSelecttex1, MOF_ARGB(135, 20, 20, 20));
			m_MenuText.Render(322, 588, MenuExtex2);

		}
	}
	else if (cnt == 2)
	{
		m_MenuText.Render(460, 71, MenuTitle2);


		if (m_Select == 0)
		{
			m_MenuText.Render(504, 243, MenuSelecttex3);
			m_MenuText.Render(470, 403, MenuSelecttex4, MOF_ARGB(135, 20, 20, 20));
			m_MenuText.Render(322, 588, MenuExtex2);
		}
		else if (m_Select == 1)
		{
			m_MenuText.Render(470, 403, MenuSelecttex4);
			m_MenuText.Render(504, 243, MenuSelecttex3, MOF_ARGB(135, 20, 20, 20));
			m_MenuText.Render(396, 588, MenuExtex3);

		}
	}


}

