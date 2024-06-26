//////////////////////////////////////////////
//	操作キャラクターのプログラムです　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#pragma once
#include "MusicManager.h"
#include "EffectManager.h"
#include "Define.h"
#include "Define_Game.h"

//プレイヤークラス
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

	//ジャンプフラグ     上昇中フラグ
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
		MOTION_MOVE,			//移動
		MOTION_JUMP,			//ジャンプ中
		MOTION_FALL,			//落下時
		MOTION_MOVE_DAMAGE,		//移動中のダメージ
		MOTION_JUMP_DAMAGE,		//ジャンプ中ダメージ
		MOTION_FALL_DAMAGE,		//落下中ダメージ
		MOTION_COUNT,			//総数
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
	
	//デバック更新
	void UpdateDebug(void);

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
