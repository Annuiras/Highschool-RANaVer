#include "MusicManager.h"

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}

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

//初期化
void CMusicMgmt::Initialize(float bgmv, float sev) {


	Load();
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
CMusic* CMusicMgmt::SEStart(tag_SE_TYPE type) {

	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		//todo:同じSEを重ねて再生出来ない？
		//なら複数用意する必要ない二次元配列じゃなくていい
		if (m_Music_SE[type][mgmt].IsPlay())
		{
			continue;
		}
		m_Music_SE[type][mgmt].Start();
		return &m_Music_SE[type][mgmt];
	}
	return NULL;

}

//SE停止
void CMusicMgmt::SEStop(tag_SE_TYPE type)
{
	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[type][mgmt].IsPlay())
		{
			m_Music_SE[type][mgmt].Start();
		}
	}
}

//SEボリュームセット
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

//BGMスタート
CMusic* CMusicMgmt::BGMStart(tag_BGM_TYPE type)
{
	if (!m_Music_BGM[type].IsPlay())
	{	
		m_Music_BGM[type].Start();
		return &m_Music_BGM[type];
	}
	
	return NULL;
}

//BGM停止
void CMusicMgmt::BGMStop(tag_BGM_TYPE type)
{
	if (m_Music_BGM[type].IsPlay())
	{
		m_Music_BGM[type].Stop();
	}

}

//BGMボリュームセット
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
void CMusicMgmt::BGMLoop(tag_BGM_TYPE type, bool b)
{
	m_Music_BGM[type].SetLoop(b);

}

//SEボリュームゲット
//SEのボリュームはすべて同じなので一つのみ取得
float CMusicMgmt::GetSEVolume()
{
	return m_Music_SE[0][0].GetVolume();
}

//BGMボリュームゲット
//BGMのボリュームはすべて同じなので一つのみ取得
float CMusicMgmt::GetBGMVolume()
{
	return 	m_Music_BGM->GetVolume();
}

//解放
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