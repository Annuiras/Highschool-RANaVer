#include "Music.h"


CMusic::CMusic() :
	m_SoundBou()
{};

CMusic::~CMusic() {};

bool CMusic::Initialize() {

	//���ʂ̐ݒ�
	return true;
}

void CMusic::Start(void) {

	m_SoundBou->Play();

}

void CMusic::Stop(void)
{
	m_SoundBou->Stop();
}

void CMusic::SetLoop(bool b)
{
	m_SoundBou->SetLoop(b);
}

void CMusic::SetVolume(float volume)
{
	m_SoundBou->SetVolume(volume);
}

float CMusic::GetVolume(void)
{
	return 	m_SoundBou->GetVolume();
}

void CMusic::Release() {

	m_SoundBou->Release();

}
