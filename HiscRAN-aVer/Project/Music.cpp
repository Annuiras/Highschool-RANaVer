#include "Music.h"


CMusic::CMusic() :
	m_SoundBou()
{};

CMusic::~CMusic() {};

bool CMusic::Initialize() {
	return true;
}

void CMusic::Start(int ty) {

	switch (ty)
	{

	case 0://�Ԕ���
		m_SoundBou->Play();
		break;

	case 1://����
		m_SoundBou->Play();
		break;
	case 2://��
		m_SoundBou->Play();
		break;

	case 3://�ۂ�[��
		m_SoundBou->Play();

		break;
	default:
		break;
	}

}

void CMusic::Release() {

	m_SoundBou->Release();

}
