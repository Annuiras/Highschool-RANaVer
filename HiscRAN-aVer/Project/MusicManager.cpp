#include "MusicManager.h"

CMusicManager::CMusicManager()
{}

CMusicManager::~CMusicManager()
{}


bool CMusicManager::Load(void) {


	//SE‚Ì“Ç‚İ‚İ
	char* name[] = {
		"bomb.mp3",//Â”š”­
		"–‚‰¤°  ”š”­03 (1).mp3",//Â”š”­
		"strange_bell.mp3",//à
		"strange_wave.mp3"//‚Û‚í[‚ñ

	};
	for (int i = 0; i < SET_TYPECOUNT; i++)
	{
		if (!m_SE[i].Load(name[i]))
		{
			return false;
		}
	}


	return true;

}

void CMusicManager::Initialize(void) {

	//SE‚ÌŠî‘bİ’è

	//í—Ş‚Ì”
	for (int syu = 0; syu < SET_TYPECOUNT; syu++)
	{
		//ŠÇ—‚·‚é”
		for (int y = 0; y < SE_COUNT; y++)
		{

			m_Music[y][syu].SetSE(&m_SE[syu]);
		}
	}


}

CMusic* CMusicManager::Start(int type) {

	for (int i = 0; i < SE_COUNT; i++)
	{
		if (m_Music[i][type].IsPlay())
		{
			continue;
		}
		m_Music[i][type].Start(type);
		return &m_Music[i][type];
	}
	return NULL;

}

void CMusicManager::Release() {

	for (int y = 0; y < SE_COUNT; y++)
	{
		for (int x = 0; x < SET_TYPECOUNT; x++)
		{

			m_Music[y][x].Release();

		}
	}

}