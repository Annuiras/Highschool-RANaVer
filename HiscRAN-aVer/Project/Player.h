#pragma once
#include	"Mof.h"
#include "MusicManager.h"
#include "EffectManager.h"
#include "Define.h"


class CPlayer
{
private:

	//モーションクラス
	CSpriteMotionController	m_Motion;

	//SE・BGMマネージャー
	CMusicMgmt* m_MusicMgmt;

	//エフェクトマネージャー
	CEffectMgmt* m_pEffectMgmt;

	//描画矩形
	CRectangle				m_SrcRect;

	//キャラクターテクスチャ
	CTexture				m_Texture;

	//HP表示テクスチャ
	CTexture				m_HPTexture;
	CTexture				m_HPFrame;

	//プレイヤー座標
	float					m_PosX;
	float					m_PosY;

	//スピード変数
	float					m_MoveY;

	//当たり判定(足)
	float m_legsboxY;

	//HP
	int				m_HP;

	//無敵時間
	int					m_DamageWait;

	//死亡フラグ
	bool				m_deathflg;

	//ジャンプフラグ     上に加算されている間のフラグ
	bool					m_Jumpflg;

	//大小ジャンプフラグ 大ジャンプ:true
	bool					m_BSflg;
	//大小ジャンプカウント
	float					m_JumpCount;

	//モーション種類定義
	enum tag_MOTION {
		MOTION_MOVE,
		MOTION_JUMPSTART,
		MOTION_COUNT,
	};

public:
	CPlayer();
	~CPlayer();

	bool Load(void);
	void Initialize(void);

	void Update(void);

	//クリア時の更新
	void UpdateClear(void);

	void Render(void);
	void Release(void);

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


	//敵当たり判定
	bool CollosopnEnemy(CRectangle r);
	

	//SE・BGMマネージャーセット
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//エフェクトマネージャーセット
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }


	//プレイヤー矩形取得
	CRectangle GetRect(void) {
		return CRectangle(m_PosX + PLAYER_ADMENT_SPACE, m_PosY,
			m_PosX + PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//プレイヤー足だけ判定
	CRectangle legsGetRect() {
		return CRectangle(m_PosX+ PLAYER_ADMENT_SPACE,m_PosY + m_legsboxY,
			m_PosX + PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//座標取得
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }

	//ゲームオーバー判定を渡す
	//true: ゲームオーバー
	bool	GetOver(void) { return m_deathflg; }

};
