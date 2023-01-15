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

tag_LoadSituation CMenu::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Menu");

	//�A�v���P�[�V�����I�����j���[
	if (!m_MenuEndTexture.Load("Menu_BGEND.png")) {

		return LOAD_ERROR;
	}

	//�Q�[���|�[�Y���j���[
	if (!m_MenuPauseTexture.Load("Menu_BGPause.png")) {
		return LOAD_ERROR;
	}

	//DP�I�����胁�j���[
	if (!m_MenuDPTexture.Load("Menu_DPDecision.png")) {
		return LOAD_ERROR;
	}

	//DP�I�����莞��DP��ނ܂Ƃ�
	if (!m_MenuDPTexTexture.Load("Menu_DPDecision_Text.png")) {
		return LOAD_ERROR;
	}

	//���j���[�I���`�F�b�N�}�[�N
	if (!m_MenuCheck.Load("Menu_Check.png")) {
		return LOAD_ERROR;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return LOAD_COMP;
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
void CMenu::Show(tag_MenuType Type)
{
	//��ʒ����ɕ`��
	m_cx = 371;
	m_cy = 159;

	//���
	m_Type = Type;

	m_bShow = true;
	m_bEnter = false;
	m_Select = 0;

	//��ނɂ���đI�����̐������߂�
	switch (m_Type)
	{
	case MENUT_END:
		m_Count = 2;
		break;
	case MENUT_GAME_END:
		m_Count = 2;
		break;
	case MENUT_DPCONFIRM:
		m_Count = 2;
		break;
	default:
		break;
	}
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

		//SE�Đ�
		m_MusicMamt->SEStart(SE_T_MOOP_CURSORMOVE);

		if (m_Select < 0)
		{
			m_Select = m_Count - 1;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		m_Select++;

		//SE�Đ�
		m_MusicMamt->SEStart(SE_T_MOOP_CURSORMOVE);

		if (m_Select >= m_Count)
		{
			m_Select = 0;
		}
	}

	//Enter�Ō���
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_MusicMamt->SEStart(SE_T_DECISION);
		m_bEnter = true;
	}
}

//�`��
void CMenu::Render(void)
{
	if (!m_bShow)
	{
		return;
	}

	//���j���[�̔w�i�`��
	switch (m_Type)
	{
		//�I�����j���[
		case MENUT_END:

			m_MenuEndTexture.Render(m_cx, m_cy);

			if (m_Select == 0)
			{
				m_MenuCheck.Render(526, 422);
			}
			else if (m_Select == 1)
			{
				m_MenuCheck.Render(770, 424);
			}
			break;

		//�Q�[����ʏI�����j���[
		case MENUT_GAME_END:
			CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));

			m_MenuPauseTexture.Render(m_cx, m_cy);

			if (m_Select == 0)
			{
				m_MenuCheck.Render(526, 422);
			}
			else if (m_Select == 1)
			{
				m_MenuCheck.Render(770, 424);
			}
			break;

		//DP�I���m�胁�j���[
		case MENUT_DPCONFIRM:
			m_MenuDPTexture.Render(m_cx,m_cy);
			if (m_Select == 0)
			{
				m_MenuCheck.Render(526, 422);
			}
			else if (m_Select == 1)
			{
				m_MenuCheck.Render(770, 424);
			}
			break;

		default:
			break;
	}
}

void CMenu::Render(int Type)
{
	//�I���摜��`
	//�z��̔ԍ���DP���̑Ή��͈ȉ��̒ʂ�ł��B
	//[0]���z����
	//[1]���R�~����
	//[2]������
	//[3]���s����
	//[4]���w��
	CRectangle recText[5] = {{0,246,256,307},{0,183,255,246},{0,120,210,183} ,{0,60,254,120},{0,0,214,60} };

	if (!m_bShow)
	{
		return;
	}

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));

	m_MenuDPTexture.Render(m_cx, m_cy);

	m_MenuDPTexTexture.Render(521, 275, recText[Type]);

	if (m_Select == 0)
	{
		m_MenuCheck.Render(526, 422);
	}
	else if (m_Select == 1)
	{
		m_MenuCheck.Render(770, 424);
	}
	
}
