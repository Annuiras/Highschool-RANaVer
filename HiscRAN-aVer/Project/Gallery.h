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

	//解放済み最終容姿表示
	CTexture	m_LastApp;

	//未解放最終容姿
	CTexture    m_NotLastApp[15];

	//選択時の四角形（最終容姿）
	CTexture	m_SelectTexture;

	//選択時の四角形（戻るボタン）
	CTexture	m_SelectTexture_s;


	//最終容姿の台紙テクスチャ（バラ）座標格納
	Vector2		pos[15] =
	{
		{60, 40},
		{180,40},
		{300,40},
		{420,40},
		{540,40},
		{60,240},
		{180,240},
		{300,240},
		{420,240},
		{540,240},
		{60,440},
		{180,440},
		{300,440},
		{420,440},
		{540,440}
	};

	//テキストボックスの矩形
	CRectangle RecTextBox[15] =
	{
		{0,0,400,189},
		{400,0,800,189},
		{800,0,1200,189},
		{0,189,400,378},
		{400,189,800,378},
		{800,189,1200,378},
		{0,378,400,567},
		{400,378,800,567},
		{800,378,1200,567},
		{0,567,400,756},
		{400,567,800,756},
		{800,567,1200,756},
		{0,756,400,945},
		{400,756,800,945},
		{800,756,1200,945}
	};


	//最終容姿の台紙テクスチャ（ピックアップ用）
	CTexture	m_LastAppPic[15];

	//最終容姿台紙
	CTexture	m_PickUp;

	//解放済み最終容姿テキスト
	CTexture	m_PickUpText;

	//未解放最終容姿テキスト
	CTexture	m_NotPickUpText;

	//テキストボックス
	CTexture	m_Text;

	//戻るボタン
	CTexture	m_BackButton;

	int m_BakAlph;

	bool LastAddFlag[15] =
	{
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
		true,
	};

public:
	CGallery();
	~CGallery();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

