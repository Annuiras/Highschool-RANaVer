#include "Load.h"

//ロード画面処理
CLoad::CLoad():
	m_Bak(),
	m_String(),
	m_ErBak(),
	m_WaitingTime(),
	m_Time(0),
	m_LoadTimeEnd(false),
	m_WhiteAlpha(),
	m_Fadein()
{
}

CLoad::~CLoad()
{
}

//初期化
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
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Load");

	if (!m_Bak.Load("ro-do-0001.png")) {
		return false;
	}

	if (!m_ErBak.Load("era--0003.png")) {
		return false;
	}

	if (!m_String.Load("ro-dostring.png")) {
		return false;
	}

	//表示矩形設定
	m_StringRec.SetValue(0, 0, m_String.GetWidth()-75, m_String.GetHeight());

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//更新
void CLoad::Update()
{

	if (m_LoadTimeEnd) {
		return;
	}

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

	//経過時間追加
	m_Time++;

	//点をすべて表示したら点をすべて消す
	if (m_Time% 120==0) {
		m_StringRec.Right -= 60;
	}

	//経過時間によって表示矩形を大きくして
	//点が増えるように見せる
	if (m_Time % 30 == 0) {
		m_StringRec.Right += 15;
	}

	//透明かつ待機時間終了
	if (m_WhiteAlpha == 0 &&!Thread_Load.joinable()&& m_WaitingTime < 0) {
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
	//背景
	m_Bak.Render(0,0);

	//右下文字
	m_String.Render(0, 0, m_StringRec);

	CGraphicsUtilities::RenderFillRect(0, 0, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT,
		MOF_ARGB(m_WhiteAlpha,255,255,255));
}

void CLoad::RenderError(void)
{
	//エラー背景
	m_ErBak.Render(0, 0);
}

void CLoad::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "最低待機時間:%d", m_WaitingTime);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "アルファ値:%d", m_WhiteAlpha);

	CGraphicsUtilities::RenderRect(m_StringRec, MOF_XRGB(80, 80, 80));

}


void CLoad::Release()
{
	m_Bak.Release();
	m_String.Release();
	m_ErBak.Release();
}

