#include "Menu.h"

//コンストラクタ
CMenu::CMenu() :
	m_cx(0.0f),
	m_cy(0.0f),
	m_Count(0),
	m_Select(0),
	m_bShow(false),
	m_bEnter(false),
	m_Rect()
{

}

//デストラクタ
CMenu::~CMenu()
{

}

tag_LoadSituation CMenu::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Menu");

	//アプリケーション終了メニュー
	if (!m_MenuEndTexture.Load("Menu_BGEND.png")) {

		return LOAD_ERROR;
	}

	//ゲームポーズメニュー
	if (!m_MenuPauseTexture.Load("Menu_BGPause.png")) {
		return LOAD_ERROR;
	}

	//DP選択決定メニュー
	if (!m_MenuDPTexture.Load("Menu_DPDecision.png")) {
		return LOAD_ERROR;
	}

	//DP選択決定時のDP種類まとめ
	if (!m_MenuDPTexTexture.Load("Menu_DPDecision_Text.png")) {
		return LOAD_ERROR;
	}

	//メニュー選択チェックマーク
	if (!m_MenuCheck.Load("Menu_Check.png")) {
		return LOAD_ERROR;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return LOAD_COMP;
}


//解放
void CMenu::Release(void)
{
	m_Count = 0;
	m_MenuEndTexture.Release();
	m_MenuPauseTexture.Release();
	m_MenuDPTexture.Release();
	m_MenuDPTexTexture.Release();
	m_MenuCheck.Release();
}

//表示
void CMenu::Show(tag_MenuType Type)
{
	//画面中央に描画
	m_cx = 371;
	m_cy = 159;

	//種類
	m_Type = Type;

	m_bShow = true;
	m_bEnter = false;
	m_Select = 0;

	//種類によって選択肢の数を決める
	switch (m_Type)
	{
	case MENUT_END:
		m_Count = 2;
		break;
	case MENUT_GAME_END:
		m_Count = 2;
		break;
	case MENUT_DPCONFIRM:
		m_Count = 2;
		break;
	default:
		break;
	}
}

//更新
void CMenu::Update(void)
{
	if (!m_bShow)
	{
		return;
	}

	//左右のキーで選択
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		m_Select--;

		//SE再生
		m_MusicMamt->SEStart(SE_T_MOOP_CURSORMOVE);

		if (m_Select < 0)
		{
			m_Select = m_Count - 1;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		m_Select++;

		//SE再生
		m_MusicMamt->SEStart(SE_T_MOOP_CURSORMOVE);

		if (m_Select >= m_Count)
		{
			m_Select = 0;
		}
	}

	//Enterで決定
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_MusicMamt->SEStart(SE_T_DECISION);
		m_bEnter = true;
	}
}

//描画
void CMenu::Render(void)
{
	if (!m_bShow)
	{
		return;
	}

	//メニューの背景描画
	switch (m_Type)
	{
		//終了メニュー
		case MENUT_END:

			m_MenuEndTexture.Render(m_cx, m_cy);

			if (m_Select == 0)
			{
				m_MenuCheck.Render(526, 422);
			}
			else if (m_Select == 1)
			{
				m_MenuCheck.Render(770, 424);
			}
			break;

		//ゲーム画面終了メニュー
		case MENUT_GAME_END:
			CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));

			m_MenuPauseTexture.Render(m_cx, m_cy);

			if (m_Select == 0)
			{
				m_MenuCheck.Render(526, 422);
			}
			else if (m_Select == 1)
			{
				m_MenuCheck.Render(770, 424);
			}
			break;

		//DP選択確定メニュー
		case MENUT_DPCONFIRM:
			m_MenuDPTexture.Render(m_cx,m_cy);
			if (m_Select == 0)
			{
				m_MenuCheck.Render(526, 422);
			}
			else if (m_Select == 1)
			{
				m_MenuCheck.Render(770, 424);
			}
			break;

		default:
			break;
	}
}

void CMenu::Render(int Type)
{
	//選択画像矩形
	//配列の番号とDP名の対応は以下の通りです。
	//[0]→想像力
	//[1]→コミュ力
	//[2]→魅力
	//[3]→行動力
	//[4]→学力
	CRectangle recText[5] = {{0,246,256,307},{0,183,255,246},{0,120,210,183} ,{0,60,254,120},{0,0,214,60} };

	if (!m_bShow)
	{
		return;
	}

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));

	m_MenuDPTexture.Render(m_cx, m_cy);

	m_MenuDPTexTexture.Render(521, 275, recText[Type]);

	if (m_Select == 0)
	{
		m_MenuCheck.Render(526, 422);
	}
	else if (m_Select == 1)
	{
		m_MenuCheck.Render(770, 424);
	}
	
}
