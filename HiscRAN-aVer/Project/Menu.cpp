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

//生成
void CMenu::Create(int cnt)
{
	//古いデータの解放
	Release();

	//リソース配置ディレクトリの設定
	if (!CUtilities::SetCurrentDirectoryA("Menu"))
		 false;

	m_MenuEndTexture.Load("Menu_BGEND.png");
	m_MenuPauseTexture.Load("Menu_BGPause.png");
	m_MenuCheck.Load("Menu_Check.png");

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//引数の変更を保存
	m_Count = cnt;
}

//解放
void CMenu::Release(void)
{
	m_Count = 0;
	m_MenuEndTexture.Release();
	m_MenuPauseTexture.Release();
	m_MenuCheck.Release();
}

//表示
void CMenu::Show(float cx, float cy)
{
	m_cx = 371;
	m_cy = 159;
	m_bShow = true;
	m_bEnter = false;
	m_Select = 0;
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
		if (m_Select < 0)
		{
			m_Select = m_Count - 1;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		m_Select++;
		if (m_Select >= m_Count)
		{
			m_Select = 0;
		}
	}

	//Enterで決定
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnter = true;
	}
}

//描画
void CMenu::Render(int cnt)
{
	if (!m_bShow)
	{
		return;
	}

	//メニューの背景描画
	if (cnt == 1)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_MenuEndTexture.Render(m_cx, m_cy);

		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}
	else if (cnt == 2)
	{
		m_MenuPauseTexture.Render(m_cx, m_cy);


		if (m_Select == 0)
		{
			m_MenuCheck.Render(526, 422);
		}
		else if (m_Select == 1)
		{
			m_MenuCheck.Render(770, 424);
		}
	}

}

