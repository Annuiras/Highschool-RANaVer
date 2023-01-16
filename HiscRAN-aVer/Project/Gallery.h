#pragma once

#include "Define.h"
#include "SceneBase.h"
//制作者：松浦 未羽 、田中 環

//ギャラリー画面クラス
class CGallery :public CSceneBase
{
private:

	//最終容姿背景種類
	enum tag_BAKLAST_TYPE {

		//ノーマル
		BL_NORMAL,

		//スーパーレディ
		BL_SUPERLADY,

		//お調子者
		BL_OTYOUSI,

		//文学少女
		BL_BUNGAKU,

		//中二病
		BL_TYUNI,

		//神対応
		BL_KAMITAIOU,

		//総数
		BL_COUNT
	}; 

	//コレクション画面背景テクスチャ
	CTexture	m_BackTexture;

	//解放済み最終容姿選択:本棚テクスチャ
	CTexture	m_LastApp;

	//選択時の四角形（最終容姿）
	CTexture	m_SelectTexture;

	//選択時の四角形（戻るボタン）
	CTexture	m_SelectTexture_s;

	//最終容姿背景
	CTexture m_BakLastAp;

	//最終容姿パラメータ構造体
	//構造体定義
	typedef struct LastTexture
	{
		//最終容姿テクスチャ（ピックアップ用）
		CTexture s_LastAppPic;

		//未開放フラグ
		bool s_LastAddFlag;

		//未解放本テクスチャ
		CTexture s_NotLastApp;
	};

	//最終容姿パラメータ構造体
	LastTexture S_LastParameter[16];

	//最終容姿背景表示矩形
	CRectangle m_BakLastRect[BL_COUNT];

	//解放済み最終容姿テキスト
	CTexture	m_PickUpText;

	//未解放最終容姿テキスト
	CTexture	m_NotPickUpText;

	//テキストボックス背景
	CTexture	m_Text;

	//戻るボタン
	CTexture	m_BackButton;

	//フェードアウト用アルファ値
	int m_BakAlph;

	//カーソル番号
	int galleryCnt = 0;

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

