#pragma once
#include "Define.h"
#include <thread>

using namespace std;

//ロード画面クラス
class CLoad
{
private:

	//ロード背景
	CTexture m_Bak;

	//エラー背景
	CTexture m_ErBak;

	//ロード画面最低待機時間
	int m_WaitingTime;

	//ロード画面待機時間終了フラグ
	bool m_LoadTimeEnd;

	//明転用背景α値
	int m_WhiteAlpha;

	//推移開始フラグ
	bool m_Fadein;


public:

	CLoad();
	~CLoad();
	

	//初期化
	void Initialize(void);

	//素材ロード
	bool Load(void);

	//更新
	void Update();
	void RenderLoad(void);
	void RenderError(void);
	void RenderDebug(); 
	void Release();

	//素材ロードスレッド
	thread Thread_Load;

	//ロード画面終了?
	//true:終了
	bool IsLoadEnd(void) { return m_LoadTimeEnd; }


};

