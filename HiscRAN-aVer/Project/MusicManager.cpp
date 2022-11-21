#include "MusicManager.h"

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}

//todo;�Ăяo������ʂɂ���ă��[�h�̓��e�ς���H
bool CMusicMgmt::Load(void) {

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("SE");

	//SE�̓ǂݍ���
	char* sename[] = {
		"strange_wave.mp3",//�ۂ�[��
		"Chime-Announce07-1.mp3",//�`���C��


	};
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		if (!m_SE[type].Load(sename[type]))
		{
			return false;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("BGM");

	//bgm�̓ǂݍ���
	char* bgmname[] = {
		"makiba no kaze.mp3"//�I�v�V�������BGM
	};
	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		if (!m_BGM[type].Load(bgmname[type]))
		{
			return false;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

void CMusicMgmt::Initialize(float bgmv, float sev) {

	//SE�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		//�Ǘ����鐔
		for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
		{
			m_Music_SE[type][mgmt].SetMusic(&m_SE[type]);
			m_Music_SE[type][mgmt].Initialize();
		}
	}

	//BGM�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].SetMusic(&m_BGM[type]);
		m_Music_BGM[type].Initialize();
		
	}
	
	//�{�����[���Z�b�g
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//SE�Đ�
CMusic* CMusicMgmt::SEStart(int type) {

	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[type][mgmt].IsPlay())
		{
			continue;
		}
		m_Music_SE[type][mgmt].Start();
		return &m_Music_SE[type][mgmt];
	}
	return NULL;

}

void CMusicMgmt::SEStop(int type)
{
	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[type][mgmt].IsPlay())
		{
			m_Music_SE[type][mgmt].Start();
		}
	}
}

void CMusicMgmt::SESetVolume(float sev)
{	
	//SE�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		//�Ǘ����鐔
		for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
		{
			m_Music_SE[type][mgmt].SetVolume(sev);
		}
	}

}

CMusic* CMusicMgmt::BGMStart(int type)
{
	if (!m_Music_BGM[type].IsPlay())
	{	
		m_Music_BGM[type].Start();
		return &m_Music_BGM[type];
	}
	
	return NULL;
}

void CMusicMgmt::BGMStop(int type)
{
	if (m_Music_BGM[type].IsPlay())
	{
		m_Music_BGM[type].Stop();
	}

}

void CMusicMgmt::BGMSetVolume(float bgmv)
{	
	//BGM�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].SetVolume(bgmv);
	}

}

//BGM���[�v�ݒ�
void CMusicMgmt::BGMLoop(int type, bool b)
{
	m_Music_BGM[type].SetLoop(b);

}

float CMusicMgmt::GetSEVolume()
{
	return m_Music_SE[0][0].GetVolume();
}

float CMusicMgmt::GetBGMVolume()
{
	return 	m_Music_BGM->GetVolume();
}

void CMusicMgmt::Release() {

	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
		{
			m_Music_SE[type][mgmt].Release();
		}
	}

	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].Release();
	}

}