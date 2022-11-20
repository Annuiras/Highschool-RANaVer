#include "Music.h"


CMusic::CMusic() :
	m_SoundBou()
{};

CMusic::~CMusic() {};

bool CMusic::Initialize() {

	//‰¹—Ê‚ÌÝ’è
	return true;
}

void CMusic::Start(int ty) {

	switch (ty)
	{

	case 0://Ô”š”­
		m_SoundBou->Play();
		break;

	case 1://Â”š”­
		m_SoundBou->Play();
		break;
	case 2://à
		m_SoundBou->Play();
		break;

	case 3://‚Û‚í[‚ñ
		m_SoundBou->Play();

		break;
	default:
		break;
	}

}

void CMusic::SetVolume(float volume)
{

	m_SoundBou->SetVolume(volume);
}

void CMusic::Release() {

	m_SoundBou->Release();

}
