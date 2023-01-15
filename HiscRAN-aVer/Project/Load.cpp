#include "Load.h"

//���[�h��ʏ���
CLoad::CLoad():
	m_Bak(),
	m_String(),
	m_ErBak(),
	m_WaitingTime(),
	m_Time(0),
	m_LoadTimeEnd(false),
	m_WhiteAlpha(),
	m_Fadein()
{
}

CLoad::~CLoad()
{
}

//������
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
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Load");

	if (!m_Bak.Load("ro-do-0001.png")) {
		return false;
	}

	if (!m_ErBak.Load("era--0003.png")) {
		return false;
	}

	if (!m_String.Load("ro-dostring.png")) {
		return false;
	}

	//�\����`�ݒ�
	m_StringRec.SetValue(0, 0, m_String.GetWidth()-75, m_String.GetHeight());

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//�X�V
void CLoad::Update()
{

	if (m_LoadTimeEnd) {
		return;
	}

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

	//�o�ߎ��Ԓǉ�
	m_Time++;

	//�_�����ׂĕ\��������_�����ׂď���
	if (m_Time% 120==0) {
		m_StringRec.Right -= 60;
	}

	//�o�ߎ��Ԃɂ���ĕ\����`��傫������
	//�_��������悤�Ɍ�����
	if (m_Time % 30 == 0) {
		m_StringRec.Right += 15;
	}

	//�������ҋ@���ԏI��
	if (m_WhiteAlpha == 0 &&!Thread_Load.joinable()&& m_WaitingTime < 0) {
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
	//�w�i
	m_Bak.Render(0,0);

	//�E������
	m_String.Render(0, 0, m_StringRec);

	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_WhiteAlpha,255,255,255));
}

void CLoad::RenderError(void)
{
	//�G���[�w�i
	m_ErBak.Render(0, 0);
}

void CLoad::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "�Œ�ҋ@����:%d", m_WaitingTime);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "�A���t�@�l:%d", m_WhiteAlpha);

	CGraphicsUtilities::RenderRect(m_StringRec, MOF_XRGB(80, 80, 80));

}


void CLoad::Release()
{
	m_Bak.Release();
	m_String.Release();
	m_ErBak.Release();
}

