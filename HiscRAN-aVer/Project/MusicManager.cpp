#include "MusicManager.h"

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}

//todo;呼び出される画面によってロードの内容変える？
bool CMusicMgmt::Load(void) {

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("SE");

	//SEの読み込み
	char* sename[] = {
		"strange_wave.mp3",//ぽわーん
		"Chime-Announce07-1.mp3",//チャイム


	};
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		if (!m_SE[type].Load(sename[type]))
		{
			return false;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("BGM");

	//bgmの読み込み
	char* bgmname[] = {
		"makiba no kaze.mp3"//オプション画面BGM
	};
	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		if (!m_BGM[type].Load(bgmname[type]))
		{
			return false;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

void CMusicMgmt::Initialize(float bgmv, float sev) {

	//SEの基礎設定
	//種類の数
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		//管理する数
		for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
		{
			m_Music_SE[type][mgmt].SetMusic(&m_SE[type]);
			m_Music_SE[type][mgmt].Initialize();
		}
	}

	//BGMの基礎設定
	//種類の数
	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].SetMusic(&m_BGM[type]);
		m_Music_BGM[type].Initialize();
		
	}
	
	//ボリュームセット
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//SE再生
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
	//SEの基礎設定
	//種類の数
	for (int type = 0; type < SET_TYPE_COUNT; type++)
	{
		//管理する数
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
	//BGMの基礎設定
	//種類の数
	for (int type = 0; type < BGMT_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].SetVolume(bgmv);
	}

}

//BGMループ設定
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