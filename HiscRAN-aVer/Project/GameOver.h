//////////////////////////////////////////////
//	ゲームオーバー画面のプログラムです　　  //
//									　　　　//
//　作成者：松浦未羽　　　　　　　　　　 　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Music.h"
#include "SceneBase.h"

//選択肢数
#define MenuCnt (2)

class CGameOver :public CSceneBase
{
private:
	//背景テクスチャ
	CTexture	m_BackTexture;

	//モードセレクトに戻るボタン
	CTexture	m_BackButton;

	//1年の初めからするボタン
	CTexture	m_StartButton;

	//モードセレクトに戻る文章
	CTexture	m_TextBack;

	//１年の初めからする文章
	CTexture	m_TextStart;

	//ゲームオーバー時に上に出てくる文章
	CTexture	m_ENDText;

	//ランダム変数格納用
	int			Rondom;

	//切り取り矩形(HP無くなって死んだときの文章)
	CRectangle recHPENDTex[5] = { {0,0,720,61} , {0,61,360,122},{0,122,841,195},{0,195,480,266},{0,266,1020,334} };
	CRectangle recDPENDTex[5] = { {0,334,664,403}, {0,403,600,471},{0,471,780,542},{0,542,360,612},{0,612,601,680} };

	//HP無くなって死んだときの文章配置Ⅰ（X座標）
	int		   PosXHPEND[5] = { 276,453,218,396,124 };

	//今後復活するかもしれないのでコメントアウト
	//int		   PosXDPEND[5] = { 304,337,259,458,350 };
	
	//ゲームオーバ時のフェードインフェードアウト用
	//アルファ値
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	//選択肢番号
	int GameOverCount;


	//ゲームオーバー原因フラグ
	bool HPEND = false;

	//今後復活するかもしれないのでコメントアウト
	//bool DPEND = false;

public:
	CGameOver();
	~CGameOver();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);

	void UpdateDebug(void);

	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

