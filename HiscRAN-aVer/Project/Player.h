#pragma once
#include	"Mof.h"

//重力
#define  GRAVITY	0.3f

//大ジャンプ値
#define  BIGJUMP	-13.0f
//小ジャンプ値
#define  SMALLJUMP	-6.0f

class CPlayer
{
private:

	//モーションクラス
	CSpriteMotionController	m_Motion;

	CRectangle				m_SrcRect;

	CTexture				m_Texture;
	//プレイヤー座標
	float					m_PosX;
	float					m_PosY;
	//スピード変数
	float					m_MoveX;
	float					m_MoveY;

	float m_hitboxX;
	float m_hitboxY;

	//当たり判定(足)
	float m_legsboxY;

	//可動域オーバー値
	float	m_OverX;
	float	m_OverY;

	//X固定位置
	float m_StopX;

	//HP
	int m_HP;
	//無敵時間
	int					m_DamageWait;

	//待機中フラグ true:待機
	bool				m_standby;
	//死亡フラグ
	bool				m_deathflg;
	//ジャンプパワー
	float				m_JumpPower;
	//ジャンプフラグ
	bool				m_Jumpflg;
	//大小ジャンプカウント
	float				m_JumpCount;

	//ゲーム開始フラグ
	bool					m_Startflg;

	//モーション種類定義
	enum tag_MOTION {
		MOTION_WAIT,
		MOTION_MOVE,
		MOTION_JUMPSTART,
		MOTION_JUMPEND,
		MOTION_DAMAGE,

		MOTION_COUNT,
	};

public:
	CPlayer();
	~CPlayer();

	bool Load(void);
	void Initialize(void);

	void Update(void);
	void Render(void);
	void Release(void);
	void DebuggingRender(void);

	//足場当たり判定
	bool CollosopnObje(CRectangle r);
	void UPdeteCollisionObje(float y);

	//障害物当たり判定
	bool CollosopnOB(CRectangle r);

	//敵当たり判定
	bool CollosopnEnemy(CRectangle r);

	//HP減
	void UPdeteCollisionOB(void);

	//オーバー値取得
	float GetOver(void) { return m_OverX; }

	//プレイヤー矩形取得
	CRectangle GetRect(void) {
		return CRectangle(m_PosX, m_PosY,
			m_PosX + m_hitboxX, m_PosY + m_hitboxY);
	}

	//プレイヤー足だけ判定
	CRectangle legsGetRect() {
		return CRectangle(m_PosX, m_PosY + m_legsboxY,
			m_PosX + m_hitboxX, m_PosY + m_hitboxY);
	}

	//ゲームスタート切り替え
	bool GameStart();

};
