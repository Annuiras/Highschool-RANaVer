#pragma once
#include	"Define.h"

//敵クラス
class CEnemy
{
	//モーションクラス
	CSpriteMotionController* m_Motion;

	//描画矩形
	CRectangle				m_SrcRect;

	//敵座標
	float	m_PosX;
	float	m_PosY;

	//表示フラグ
	//ture:表示中
	bool	m_Show;

	//敵テクスチャ
	CTexture* m_Texture;

	//スピード
	float	m_MoveY;

	//モーション種類定義
	enum tag_MOTION {
		MOTION_MOVE,

		MOTION_COUNT,
	};

public:
	CEnemy();
	~CEnemy();

	//初期化
	void Initialize();

	//生成
	void Start(float posy, int type);

	//更新
	void Update(float scroll);

	//描画
	void Render();
	void RenderDebug();

	//解放
	void Release();

	//敵テクスチャをセット
	void SetTexture(CTexture* enetex);

	//敵アニメーションをセット
	void SetAnime(CSpriteMotionController* eneanim);

	//敵の判定
	CRectangle GetRect(void);

	//表示中フラグを渡す
	bool Getshow(void) { return m_Show; }

	//Y座標調整
	//y:合わせたいｙ座標
	void SetPosY(float y);
};

