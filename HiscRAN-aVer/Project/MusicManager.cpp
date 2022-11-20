#include "MusicManager.h"

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}


bool CMusicMgmt::Load(void) {


	//SEÌÇÝÝ
	char* name[] = {
		"bomb.mp3",//Â­
		"¤°  ­03 (1).mp3",//Â­
		"strange_bell.mp3",//à
		"strange_wave.mp3"//Ûí[ñ

	};
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		if (!m_SE[type].Load(name[type]))
		{
			return false;
		}
	}
	return true;
}

void CMusicMgmt::Initialize(float sev/*,float bgnv*/) {

	//SEÌîbÝè
	//íÞÌ
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		//Ç·é
		for (int mgmt = 0; mgmt < SE_COUNT; mgmt++)
		{
			m_Music_SE[type][mgmt].SetSE(&m_SE[type]);
			m_Music_SE[type][mgmt].Initialize();
			m_Music_SE[type][mgmt].SetVolume(sev);
		}
	}


}

CMusic* CMusicMgmt::Start(int type) {

	for (int mgmt = 0; mgmt < SE_COUNT; mgmt++)
	{
		if (m_Music_SE[type][mgmt].IsPlay())
		{
			continue;
		}
		m_Music_SE[type][mgmt].Start(type);
		return &m_Music_SE[type][mgmt];
	}
	return NULL;

}

void CMusicMgmt::Release() {

	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < SE_COUNT; mgmt++)
		{
			m_Music_SE[type][mgmt].Release();
		}
	}

}