#include "MusicManager.h"

//制作者：田中 環

CMusicMgmt::CMusicMgmt()
{}

CMusicMgmt::~CMusicMgmt()
{}

tag_LoadSituation CMusicMgmt::Load(void) {

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("SE");

	//SEの読み込み
	char* sename[] = {
	#pragma region ゲーム,オーバー,クリア画面
		//ジャンプ系
		"Jump.mp3",
		"great_jump.mp3",
		"jumpLanding.mp3",

		//ヒット系
		//"DP_GET候補1.mp3",
		//"DP_GET候補2.mp3",
		"DP_GET.mp3",
		//"DP_GET候補4.mp3",

		//"障害物ロッカ_候補1.mp3",
		//"障害物机_候補1.mp3",
		//"障害物机_候補2.mp3",
		//"障害物机_候補3.mp3",
		//"被弾_候補1.mp3",
		//"被弾_候補3.mp3",
		"hit.mp3",

		//ゲームオーバー系
		//"Gameover_候補1_エコー要.mp3",
		//"Gameover_候補2.mp3",
		"Gameover.mp3",
		//"Gameover_候補4.mp3",
		//"オーバー画面_候補5.mp3",

		//ゲームクリア系
		"Clear.mp3",
		//"クリア_候補2.mp3",
		//"クリア_候補3.mp3",
		//"クリア_候補4.mp3",
	#pragma endregion

	#pragma region DP選択画面
		"DPDecision_dec.mp3",
	#pragma endregion

	#pragma region ギャラリー画面
		"Gallery_Cursor_Move.mp3",
	#pragma endregion

	#pragma region モードセレクト,オプション画面
		"Mode_Select_Cursor_Move.mp3",
		//"カーソル移動_候補2.mp3",
		//"カーソル移動_候補3.mp3",
		//"カーソル移動_候補4.mp3",
		//"カーソル移動_候補5.mp3",
		"Decision.mp3",
		"Chime-Announce07-1.mp3",

	#pragma endregion

	};

	for (int type = 0; type < SE_TYPE_COUNT; type++)
	{
		//同時再生数設定
		//m_Music_SE[SET_CHIME].SetBufferCount(5);

		if (!m_Music_SE[type].Load(sename[type]))
		{
			return tag_LoadSituation::LOAD_ERROR;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("BGM");

	//bgmの読み込み
	char* bgmname[] = {

	#pragma region タイトル画面
		//"Title_候補 (1).mp3",
		"Title.mp3",
		//"Title_候補 (3).mp3",
		//"Title_候補 (4).mp3",
		//"Title_候補 (5).mp3",
		//"Title_候補 (6).mp3",
		//"Title_候補 (7).mp3",
		//"Title_候補 (8).mp3",
		//"Title_候補 (9).mp3",
	#pragma endregion

	#pragma region チュートリアル画面
		"Tutorial.mp3",
	#pragma endregion


	#pragma region ゲーム,オーバー,クリア画面
		//"Stage_候補 (1).mp3",
		"Stage.mp3",
		//"Stage_候補 (3).mp3",
		//"Stage_候補 (4).mp3",
		//"Stage_候補 (5).mp3",
		//"Stage_候補 (6).mp3",
		//"Stage_候補 (7).mp3",
		//"Stage_候補 (8).mp3",
		//"Stage_候補 (9).mp3",
		//"Stage_候補 (10).mp3",
		//"Stage_候補 (11).mp3",
		//"Stage_候補 (12).mp3",
		//"SP中_候補1.mp3",
		"clear.mp3",
	#pragma endregion

	#pragma region DP選択画面
		"DPDecision_BGM.mp3",
	#pragma endregion


	#pragma region ギャラリー画面
		"Gallery.mp3",
	#pragma endregion
		
	#pragma region モードセレクト,オプション画面
		"ModeOption.mp3",
	#pragma endregion

	};
	for (int type = 0; type < BGM_TYPE_COUNT; type++)
	{
		if (!m_Music_BGM[type].Load(bgmname[type]))
		{
			return tag_LoadSituation::LOAD_ERROR;
		}
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return tag_LoadSituation::LOAD_COMP;
}

//初期化
void CMusicMgmt::Initialize(float bgmv, float sev) {	

	//ボリュームセット
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//画面推移時の初期化命令
void CMusicMgmt::InitializeIn_middle(float bgmv, float sev)
{
	//ボリュームセット
	BGMSetVolume(bgmv);
	SESetVolume(sev);
}

//SE再生
CSoundBuffer* CMusicMgmt::SEStart(tag_SE_TYPE type) {

	m_Music_SE[type].Play();
	return &m_Music_SE[type];

}

//SE停止
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

//SEボリュームセット
void CMusicMgmt::SESetVolume(float sev)
{	
	//SEの基礎設定
	//種類の数
	for (int type = 0; type < SE_TYPE_COUNT; type++)
	{
		m_Music_SE[type].SetVolume(sev);	
	}

}
//SEが再生されているか取得
bool CMusicMgmt::SEisPlay(tag_SE_TYPE type)
{
	if (m_Music_SE[type].IsPlay())
		return true;

	return false;
}

//BGMスタート
CSoundBuffer* CMusicMgmt::BGMStart(tag_BGM_TYPE type)
{
	if (!m_Music_BGM[type].IsPlay())
	{	
		m_Music_BGM[type].Play();
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
	for (int type = 0; type < BGM_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].SetVolume(bgmv);
	}

}

//SEをすべて停止
void CMusicMgmt::SEALLStop(void)
{
	for (int mgmt = 0; mgmt < SE_MGMT_COUNT; mgmt++)
	{
		if (m_Music_SE[mgmt].IsPlay())
		{
			m_Music_SE[mgmt].Stop();
		}
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
	return m_Music_SE[0].GetVolume();
}

//BGMボリュームゲット
//BGMのボリュームはすべて同じなので一つのみ取得
float CMusicMgmt::GetBGMVolume()
{
	return 	m_Music_BGM->GetVolume();
}

//解放
void CMusicMgmt::Release() {

	for (int type = 0; type < SE_TYPE_COUNT; type++)
	{
		m_Music_SE[type].Release();
	}

	for (int type = 0; type < BGM_TYPE_COUNT; type++)
	{
		m_Music_BGM[type].Release();
	}

}