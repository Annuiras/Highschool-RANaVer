#pragma once

#include "Define.h"
#include "SceneBase.h"
#include <thread>

using namespace std;

class CGallery :public CSceneBase
{
private:

	//コレクション画面背景テクスチャ
	CTexture	m_BackTexture;

	//解放済み最終容姿選択:本棚テクスチャ
	CTexture	m_LastApp;

	//選択時の四角形（最終容姿）
	CTexture	m_SelectTexture;

	//選択時の四角形（戻るボタン）
	CTexture	m_SelectTexture_s;

	//最終容姿パラメータ構造体
	typedef struct LastTexture
	{
		//最終容姿テクスチャ（ピックアップ用）
		CTexture s_LastAppPic;

		//最終容姿の台紙テクスチャ（バラ）座標格納
		Vector2 s_Mount_Pos;

		//テキストボックスの表示矩形
		CRectangle s_TextBoxRect;

		//未開放フラグ
		bool s_LastAddFlag;

		//未解放本テクスチャ
		CTexture s_NotLastApp;
	};

	//宣言
	LastTexture S_LastParameter[16];


	//最終容姿台紙
	CTexture	m_PickUp;

	//解放済み最終容姿テキスト
	CTexture	m_PickUpText;

	//未解放最終容姿テキスト
	CTexture	m_NotPickUpText;

	//テキストボックス背景
	CTexture	m_Text;

	//戻るボタン
	CTexture	m_BackButton;

	int m_BakAlph;

	//構造体に値をセット
	struct LastTexture SetLastParameter(Vector2 Pos, CRectangle textrec, bool b)
	{
		LastTexture ps;

		ps.s_Mount_Pos = Pos;
		ps.s_LastAddFlag = b;
		ps.s_TextBoxRect = textrec;

		return ps;
	}

public:
	CGallery();
	~CGallery();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

