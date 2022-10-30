#pragma once
#include	"Mof.h"

//重力
#define  GRAVITY	0.5f

//大ジャンプ値
#define  BIGJUMP -16.0f
//小ジャンプ値
#define  SMALLJUMP	-15.0f

//最大スライディング値
#define  SLIDING	100
//スライディングクールタイム
#define  SLIDINGCOOL 60


class CPlayer
{
private:

	//モーションクラス
	CSpriteMotionController	m_Motion;

	//描画矩形
	CRectangle				m_SrcRect;

	//キャラクターテクスチャ
	CTexture				m_Texture;

	//仮キャラ
	CTexture m_TEX;

	//プレイヤー座標
	float					m_PosX;
	float					m_PosY;
	//スピード変数
	float					m_MoveX;
	float					m_MoveY;

	//当たり判定幅
	float m_hitboxX;
	float m_hitboxY;

	//当たり判定(足)
	float m_legsboxY;

	//当たり判定(スキル)
	float m_SkillA;
	float m_SkillB;


	//可動域オーバー値
	float	m_OverX;
	float	m_OverY;

	//X固定位置
	float m_StopX;

	//HP
	int				m_HP;

	//無敵時間
	int					m_DamageWait;

	//衝撃波時間
	int m_CircleWait;

	//ゲーム開始フラグ
	bool					m_Startflg;
	//死亡フラグ
	bool				m_deathflg;

	//ジャンプフラグ     上に加算されている間のフラグ
	bool					m_Jumpflg;

	//大小ジャンプフラグ 大ジャンプ:true
	bool					m_BSflg;
	//大小ジャンプカウント
	float					m_JumpCount;

	//スライディングフラグ
	float					m_Slidingflg;


	//モーション種類定義
	enum tag_MOTION {
		MOTION_WAIT,
		MOTION_MOVE,
		MOTION_JUMPSTART,
		MOTION_SLIDING,
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

	//わかんないこれ何?
	void UpdateSkillShock(void);

	//デバッグ表示
	void RenderDebugging(void);

	//足場当たり判定
	bool CollosopnBar(CRectangle r);
	void UPdateCollisionBra(float y);

	//地面の当たり判定
	bool CollosopnGround(CRectangle r);
	void UPdateCollisionGround(float y);

	//障害物当たり判定
	bool CollosopnOB(CRectangle r);
	//障害物・敵と当たった場合
	void UPdateCollisionOB(void);

	//スライディング処理
	void UPdateSliding(void);

	//敵当たり判定:未使用
	bool CollosopnEnemy(CRectangle r);
	
	//HP増加処理
	void UpdateHP(void);


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

	//プレイヤー吸い寄せ範囲
	CRectangle SuckingRect() {
		return CRectangle(m_PosX, m_PosY - 200,
			m_PosX + m_hitboxX + 100, m_PosY + m_hitboxY + 600);
	}
	//衝撃波当たり判定
	CRectangle m_CircleRect() {
		return CRectangle(m_PosX - m_SkillA, m_PosY - m_SkillA,
			m_PosX + m_SkillB, m_PosY + m_SkillA);
	}


	//ゲーム停止：再生切り替え
	void GameStopPlayChange();

	//キャラが動いているか取得
	bool GetGameStopPlay();

	//座標取得
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }


};
