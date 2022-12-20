#include "Load.h"

//���[�h��ʏ���
CLoad::CLoad():
	m_WaitingTime(),
	m_LoadTimeEnd(false)
{
}

CLoad::~CLoad()
{
}

//������
//todo:���[�h��ʂ��Ăяo���Ƃ��ɑҋ@���ԃA���t�@�l���Đݒ肵����
void CLoad::Initialize(int A, int time)
{
	//���[�h��
	m_LoadTimeEnd = false;

	//�ŏ��͔w�i���l0
	m_WhiteAlpha = A;

	//�Œ�ҋ@����
	m_WaitingTime = time;

	//�t�F�[�h�t���O
	m_Fadein = false;
}

//�f�ރ��[�h
bool CLoad::Load(void)
{
	if (!m_Bak.Load("ro-do-0001.png")) {
		return false;
	}

	if (!m_ErBak.Load("era--0003.png")) {
		return false;
	}

	return true;
}

//�X�V
void CLoad::Update()
{
	//�t�F�[�h�C��
	if (!m_Fadein && m_WhiteAlpha > 0) {
		m_WhiteAlpha -= FADE_OUT_SPEED;
		if (m_WhiteAlpha<0) {
			m_WhiteAlpha = 0;
		}
		return;
	}


	//�ҋ@���Ԍ���
	if (m_WaitingTime >= 0) {
		m_WaitingTime--;
	}

	//�������ҋ@���ԏI��
	if (m_WhiteAlpha == 0 && m_WaitingTime < 0) {
		m_Fadein = true;
	}

	//�t�F�[�h�A�E�g
	if (m_Fadein && m_WhiteAlpha <= 255) {

		m_WhiteAlpha += FADE_OUT_SPEED;

		//�B��Ă���I��
		if (m_WhiteAlpha >= 255) {
			m_LoadTimeEnd = true;
		}
	}

}

void CLoad::RenderLoad()
{
	m_Bak.Render(0,0);
	CGraphicsUtilities::RenderString(0, 150, "�Œ�ҋ@����:%d", m_WaitingTime);

	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_WhiteAlpha,0,0,0));
}

void CLoad::RenderError(void)
{
	m_ErBak.Render(0, 0);
}

void CLoad::RenderDebug()
{

}

void CLoad::Release()
{
	m_Bak.Release();
	m_ErBak.Release();
}

