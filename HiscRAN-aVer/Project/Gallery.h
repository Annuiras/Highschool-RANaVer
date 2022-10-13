#pragma once
class Gallery
{
private:
	//最終容姿のテクスチャ(纏めて)
	CTexture	m_BackTexture;

	//選択時の四角形
	CTexture	m_SelectTexture;

	//最終容姿の台紙テクスチャ（バラ）
	CTexture	m_LastApp[15];

	//フォント読み込み
	CFont		gFont1;
	CFont		gFont2;

	//最終容姿の台紙テクスチャ（バラ）座標格納
	Vector2		pos[15] =
	{
		{60,60},
		{180,60},
		{300,60},
		{420,60},
		{540,60},
		{60,260},
		{180,260},
		{300,260},
		{420,260},
		{540,260},
		{60,460},
		{180,460},
		{300,460},
		{420,460},
		{540,460}
	};

	//最終容姿の台紙テクスチャ（ピックアップ用）
	CTexture	m_LastAppPic[15];

	CTexture	m_PickUp;
	CTexture	m_Text;

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

