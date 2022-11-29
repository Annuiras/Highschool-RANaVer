#include "MusicManager.h"

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}

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
		//�����Đ����ݒ�
		m_Music_SE[SET_CHIME].SetBufferCount(5);

		if (!m_Music_SE[type].Load(sename[type]))
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
		if (!m_Music_BGM[type].Load(bgmname[type]))
		{
			return false;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//������
void CMusicMgmt::Initialize(float bgmv, float sev) {

	Load();
	
	//�{�����[���Z�b�g
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//��ʐ��ڎ��̏���������
void CMusicMgmt::InitializeIn_middle(float bgmv, float sev)
{
	//�{�����[���Z�b�g
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//SE�Đ�
CSoundBuffer* CMusicMgmt::SEStart(tag_SE_TYPE type) {

	//if (!m_Music_SE[type].IsPlay()) {
		m_Music_SE[type].Play();
	//}
	return &m_Music_SE[type];

}

//SE��~
void CMusicMgmt::SEStop(tag_SE_TYPE type)
{
	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[type].IsPlay())
		{
			m_Music_SE[type].Stop();
		}
	}
}

//SE�{�����[���Z�b�g
void CMusicMgmt::SESetVolume(float sev)
{	
	//SE�̊�b�ݒ�
	//��ނ̐�
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		m_Music_SE[type].SetVolume(sev);	
	}

}

//BGM�X�^�[�g
CSoundBuffer* CMusicMgmt::BGMStart(tag_BGM_TYPE type)
{
	if (!m_Music_BGM[type].IsPlay())
	{	
		m_Music_BGM[type].Play();
		return &m_Music_BGM[type];
	}
	
	return NULL;
}

//BGM��~
void CMusicMgmt::BGMStop(tag_BGM_TYPE type)
{
	if (m_Music_BGM[type].IsPlay())
	{
		m_Music_BGM[type].Stop();
	}

}

//BGM�{�����[���Z�b�g
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
void CMusicMgmt::BGMLoop(tag_BGM_TYPE type, bool b)
{
	m_Music_BGM[type].SetLoop(b);

}

//SE�{�����[���Q�b�g
//SE�̃{�����[���͂��ׂē����Ȃ̂ň�̂ݎ擾
float CMusicMgmt::GetSEVolume()
{
	return m_Music_SE[0].GetVolume();
}

//BGM�{�����[���Q�b�g
//BGM�̃{�����[���͂��ׂē����Ȃ̂ň�̂ݎ擾
float CMusicMgmt::GetBGMVolume()
{
	return 	m_Music_BGM->GetVolume();
}

//���
void CMusicMgmt::Release() {

	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		m_Music_SE[type].Release();
	}

	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].Release();
	}

}