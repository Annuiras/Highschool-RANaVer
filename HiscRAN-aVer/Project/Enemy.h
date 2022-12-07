#pragma once
#include	"Define.h"

class CEnemy
{
	//モーションクラス
	CSpriteMotionController* m_Motion;

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

	void Initialize();
	void Start(float posy, int type);
	void Update(float over);
	void Render();
	void RenderDebug();
	void Release();

	//敵テクスチャをセット
	void SetTexture(CTexture* enetex);

	//敵アニメーションをセット
	void SetAnime(CSpriteMotionController* eneanim);

	//敵の判定
	CRectangle GetRect(void);
	//ステージの表示中での問いで使用
	bool Getshow(void) { return ene_Show; }

	//Y座標調整
	//y:合わせたいｙ座標
	void SetPosY(float y);

	int GetType(void) { return ene_Type; }
};

