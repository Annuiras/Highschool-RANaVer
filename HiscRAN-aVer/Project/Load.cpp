#include "Load.h"

//ロード画面処理
CLoad::CLoad():
	m_WaitingTime(),
	m_LoadTimeEnd(false)
{
}

CLoad::~CLoad()
{
}

//初期化
//todo:ロード画面を呼び出すときに待機時間アルファ値を再設定したい
void CLoad::Initialize(int A, int time)
{
	//ロード中
	m_LoadTimeEnd = false;

	//最初は背景α値0
	m_WhiteAlpha = A;

	//最低待機時間
	m_WaitingTime = time;

	//フェードフラグ
	m_Fadein = false;
}

//素材ロード
bool CLoad::Load(void)
{
	if (!m_Bak.Load("ro-do-0001.png")) {
		return false;
	}

	if (!m_ErBak.Load("era--0003.png")) {
		return false;
	}

	return true;
}

//更新
void CLoad::Update()
{
	//フェードイン
	if (!m_Fadein && m_WhiteAlpha > 0) {
		m_WhiteAlpha -= FADE_OUT_SPEED;
		if (m_WhiteAlpha<0) {
			m_WhiteAlpha = 0;
		}
		return;
	}


	//待機時間減少
	if (m_WaitingTime >= 0) {
		m_WaitingTime--;
	}

	//透明かつ待機時間終了
	if (m_WhiteAlpha == 0 && m_WaitingTime < 0) {
		m_Fadein = true;
	}

	//フェードアウト
	if (m_Fadein && m_WhiteAlpha <= 255) {

		m_WhiteAlpha += FADE_OUT_SPEED;

		//隠れてから終了
		if (m_WhiteAlpha >= 255) {
			m_LoadTimeEnd = true;
		}
	}

}

void CLoad::RenderLoad()
{
	m_Bak.Render(0,0);
	CGraphicsUtilities::RenderString(0, 150, "最低待機時間:%d", m_WaitingTime);

	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_WhiteAlpha,0,0,0));
}

void CLoad::RenderError(void)
{
	m_ErBak.Render(0, 0);
}

void CLoad::RenderDebug()
{

}

void CLoad::Release()
{
	m_Bak.Release();
	m_ErBak.Release();
}

