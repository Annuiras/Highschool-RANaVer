#pragma once
#include	"Mof.h"
#include	"Define.h"

#define		ENEMY_VOLUME	10

#define		ENEMY_SIZE_WIDTH	60
#define		ENEMY_SIZE_HEIGHT	60

//todo 敵

class CEnemy
{
	//モーションクラス
	CSpriteMotionController	m_Motion;

	//描画矩形
	CRectangle				m_SrcRect;

	//敵座標
	float	ene_PosX;
	float	ene_PosY;

	bool	ene_Show;

	//敵テクスチャ
	CTexture* ene_Texture;

	int		ene_Type;

	//スピード
	float	ene_SpeedX;
	float	ene_SpeedY;

	//モーション種類定義
	enum tag_MOTION {
		MOTION_MOVE,

		MOTION_COUNT,
	};

public:
	CEnemy();
	~CEnemy();

	bool Load();
	void Initialize();
	void Start(float posy, int type);
	void Update(float over);
	void Render();
	void RenderDebug();
	void Release();

	//敵テクスチャをセット
	void SetTexture(CTexture* enetex);

	//敵の判定
	CRectangle GetRect(int type);
	//ステージの表示中での問いで使用
	bool Getshow(void) { return ene_Show; }

	int GetType(void) { return ene_Type; }
};

