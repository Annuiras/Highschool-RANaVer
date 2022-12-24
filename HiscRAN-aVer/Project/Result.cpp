#include "Result.h"

CResult::CResult():
	m_PosX_Bak(),
	m_PosY_Bak(),
	m_FadeSitu(FADE_NOT),
	m_Show(),
	m_Endflg(),
	m_Initializeflg(),
	m_Bak_MiddleResult(),
	m_Bak_LastResult(),
	m_MusicMgmt(),
	m_pEffectMgmt()
{
}

CResult::~CResult()
{
}

bool CResult::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Result");

	//���Ԍ��ʔw�i
	if (!m_Bak_MiddleResult.Load("tyukanrizaruto-0002.png")) {
		return false;
	}

	//�ŏI���ʔw�i
	if (!m_Bak_LastResult.Load("rizaruto-0001.png")) {
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//������
void CResult::Initialize(void)
{
	//�������ςŕ\���J�n���Ă��Ȃ��ꍇ�͖���
	if (m_Initializeflg) {
		return;
	}

	//�e�p�����[�^������
	m_PosX_Bak = 0;
	m_PosY_Bak = 0;
	m_Endflg = false;
	m_Show = false;

	m_Initializeflg = true;
}

//�\���J�n
void CResult::Start(void)
{
	m_PosX_Bak = 0;
	m_PosY_Bak = -3020;
	m_Endflg = false;
	m_Show = true;
	m_FadeSitu = FADE_IN;
	m_Initializeflg = false;
}

//�X�V
void CResult::Update(void)
{
	if (m_FadeSitu == FADE_NEXT) {
		return;
	}

	if (m_FadeSitu == FADE_IN) {

		m_PosY_Bak += 5;

		if (m_PosY_Bak >= 0) {
			m_PosY_Bak = 0;
			m_FadeSitu = FADE_NOT;
		}
	}


	if (m_FadeSitu == FADE_NOT) {

		//�t�F�[�h�A�E�g�t���O
		if (g_pInput->IsKeyPush(MOFKEY_RETURN)) {
			m_FadeSitu = FADE_OUT;
		}
	}

	if (m_FadeSitu == FADE_OUT) {

		m_PosY_Bak -= 5;

		if (m_PosY_Bak <= -720) {
			m_PosY_Bak = -720;
			m_Endflg = true;
			m_FadeSitu = FADE_NEXT;
		}
	}


}

//���ԕ񍐕`��
void CResult::RenderMiddleResult(void)
{
	if (!m_Show) {
		return;
	}
	m_Bak_MiddleResult.Render(m_PosX_Bak, m_PosY_Bak);
}

void CResult::RenderLastResult(void)
{
	if (!m_Show) {
		return;
	}
	m_Bak_LastResult.Render(m_PosX_Bak, m_PosY_Bak);
}

//�f�o�b�O�\��
void CResult::RenderDebugging(void)
{

}

//���
void CResult::Release(void)
{
	m_Bak_MiddleResult.Release();
}
