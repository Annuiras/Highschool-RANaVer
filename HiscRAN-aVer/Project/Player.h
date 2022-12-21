#pragma once
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

	//デバッグ用
	//無敵フラグ
	bool _unrivaled;
	int _chare_A;

	//モーション種類定義
	enum tag_MOTION {
		MOTION_MOVE,		//移動
		MOTION_JUMPSTART,	//ジャンプ開始
		MOTION_COUNT,		//総数
	};

public:
	CPlayer();
	~CPlayer();

	//素材ロード
	bool Load(void);

	//初期化
	void Initialize(void);

	//更新
	void Update(void);

	//クリア時の更新
	void UpdateClear(void);

	//描画
	void Render(void);

	//解放
	void Release(void);

	//デバッグ表示
	void RenderDebugging(void);

	//乗れる物(上昇中すり抜け)と当たった場合
	void UPdateCollisionBra(float y);

	//地面と当たった場合
	void UPdateCollisionGround(float y);

	//障害物・敵と当たった場合
	void UPdateCollisionOB(void);

	//SE・BGMマネージャーセット
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//エフェクトマネージャーセット
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }


	//プレイヤー矩形取得
	CRectangle GetRect(void) {
		return CRectangle(m_PosX + PLAYER_ADMENT_SPACE, m_PosY,
			m_PosX + PLAYER_ADMENT_SPACE+ PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//プレイヤー足だけ判定
	CRectangle GetLegsRect() {
		return CRectangle(m_PosX+ PLAYER_ADMENT_SPACE,m_PosY + m_legsboxY,
			m_PosX+ PLAYER_ADMENT_SPACE + PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//座標取得
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }

	//ゲームオーバー判定を渡す
	//true: ゲームオーバー
	bool	GetOver(void) { return m_deathflg; }

};
