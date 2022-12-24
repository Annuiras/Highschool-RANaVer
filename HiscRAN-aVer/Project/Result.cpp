#include "Result.h"

CResult::CResult():
	m_PosX_Bak(),
	m_PosY_Bak(),
	m_FadeSitu(FADE_NOT),
	m_Show(),
	m_Endflg(),
	m_Initializeflg(),
	m_Bak_MiddleResult(),
	m_Bak_LastResult(),
	m_MusicMgmt(),
	m_pEffectMgmt()
{
}

CResult::~CResult()
{
}

bool CResult::Load(void)
{
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Result");

	//中間結果背景
	if (!m_Bak_MiddleResult.Load("tyukanrizaruto-0002.png")) {
		return false;
	}

	//最終結果背景
	if (!m_Bak_LastResult.Load("rizaruto-0001.png")) {
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//初期化
void CResult::Initialize(void)
{
	//初期化済で表示開始していない場合は無視
	if (m_Initializeflg) {
		return;
	}

	//各パラメータ初期化
	m_PosX_Bak = 0;
	m_PosY_Bak = 0;
	m_Endflg = false;
	m_Show = false;

	m_Initializeflg = true;
}

//表示開始
void CResult::Start(void)
{
	m_PosX_Bak = 0;
	m_PosY_Bak = -3020;
	m_Endflg = false;
	m_Show = true;
	m_FadeSitu = FADE_IN;
	m_Initializeflg = false;
}

//更新
void CResult::Update(void)
{
	if (m_FadeSitu == FADE_NEXT) {
		return;
	}

	if (m_FadeSitu == FADE_IN) {

		m_PosY_Bak += 5;

		if (m_PosY_Bak >= 0) {
			m_PosY_Bak = 0;
			m_FadeSitu = FADE_NOT;
		}
	}


	if (m_FadeSitu == FADE_NOT) {

		//フェードアウトフラグ
		if (g_pInput->IsKeyPush(MOFKEY_RETURN)) {
			m_FadeSitu = FADE_OUT;
		}
	}

	if (m_FadeSitu == FADE_OUT) {

		m_PosY_Bak -= 5;

		if (m_PosY_Bak <= -720) {
			m_PosY_Bak = -720;
			m_Endflg = true;
			m_FadeSitu = FADE_NEXT;
		}
	}


}

//中間報告描画
void CResult::RenderMiddleResult(void)
{
	if (!m_Show) {
		return;
	}
	m_Bak_MiddleResult.Render(m_PosX_Bak, m_PosY_Bak);
}

void CResult::RenderLastResult(void)
{
	if (!m_Show) {
		return;
	}
	m_Bak_LastResult.Render(m_PosX_Bak, m_PosY_Bak);
}

//デバッグ表示
void CResult::RenderDebugging(void)
{

}

//解放
void CResult::Release(void)
{
	m_Bak_MiddleResult.Release();
}
