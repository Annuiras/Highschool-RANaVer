#pragma once

#include	"Mof.h"

class Gallery
{
private:
	//最終容姿のテクスチャ(纏めて)
	CTexture	m_BackTexture;

	//選択時の四角形
	CTexture	m_SelectTexture;
	CTexture	m_SelectTexture_s;


	//最終容姿の台紙テクスチャ（バラ）
	CTexture	m_LastApp[15];

	//フォント読み込み
	CFont		gFont1;
	CFont		gFont2;

	//最終容姿の台紙テクスチャ（バラ）座標格納
	Vector2		pos[15] =
	{
		{60,40},
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

	//最終容姿の台紙テクスチャ（ピックアップ用）
	CTexture	m_LastAppPic[15];

	CTexture	m_PickUp;
	CTexture	m_Text;
	CTexture	m_BackButton;

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
	Gallery();
	~Gallery();
	void Initialize(void);
	void Update(void);
	void Render(void);
	bool Load(void);
	void Release(void);
};

