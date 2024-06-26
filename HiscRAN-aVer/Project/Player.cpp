//////////////////////////////////////////////
//	操作キャラクターのプログラムです　　　　//
//									　　　　//
//　作成者：田中 環、石川 由妃、永井 悠太　 //
//									　　　　//
//　リファクタリングした人：田中環　　　　　//
//									　　　　//
//　最終更新：2023/01/17			　　　　//
//////////////////////////////////////////////

#include "Player.h"

CPlayer::CPlayer() :
	m_Texture(),
	m_SrcRect(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveY(0.0f),
	m_legsboxY(0.0f),
	m_HP(0),
	m_DamageWait(0),
	m_deathflg(false),
	m_Jumpflg(false),
	m_JumpCount(0.0f),
	m_BSflg(true),
	m_MusicMgmt(),
	m_pEffectMgmt(),
	_unrivaled(),
	_chare_A()
{
}

CPlayer::~CPlayer() {


}

//読み込み
bool CPlayer::Load(void) {


	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Character");

	//HPテクスチャ読み込み
	if (!m_HPTexture.Load("Game_HP.png")) {
		return false;
	}
	if (!m_HPFrame.Load("Game_HPFrame.png")) {
		return false;
	}

	//キャラクター読み込み
	if (!m_Texture.Load("Motion.png")) {
		return false;
	}

	//アニメーション矩形変数
	float AnimationSquare = 2;

	//アニメーション
	SpriteAnimationCreate anim[] = 
	{
		//移動モーション
		{
			"移動",
			0,0,
			160,185,
			TRUE,{{AnimationSquare,0,0},{AnimationSquare,1,0},{AnimationSquare,2,0},{AnimationSquare,3,0},{AnimationSquare,4,0},{AnimationSquare,5,0},{AnimationSquare,6,0},{AnimationSquare,7,0},{AnimationSquare,8,0},{AnimationSquare,9,0},{AnimationSquare,10,0}
			,{AnimationSquare,11,0},{AnimationSquare,12,0},{AnimationSquare,13,0},{AnimationSquare,14,0}}

		},

		//ジャンプ
		{
			"ジャンプ中",
			0,185,
			160,185,
			FALSE,{{5,0,0}}
		},

		//落下中
		{
			"落下",
			0,185,
			160,185,
			FALSE,{{5,1,0}}
		},
		
		//移動中ダメージモーション
		{
			"移動中ダメージ",
			0,555,
			160,185,
			TRUE,{{AnimationSquare,0,0},{AnimationSquare,1,0},{AnimationSquare,2,0},{AnimationSquare,3,0},{AnimationSquare,4,0},{AnimationSquare,5,0},{AnimationSquare,6,0},{AnimationSquare,7,0},{AnimationSquare,8,0},{AnimationSquare,9,0},{AnimationSquare,10,0}
			,{AnimationSquare,11,0},{AnimationSquare,12,0},{AnimationSquare,13,0},{AnimationSquare,14,0}}

		},

		//ジャンプ中ダメージ
		{
			"ジャンプ中ダメージ",
			0,185,
			160,185,
			FALSE,{{5,2,0}}
		},

		//落下中ダメージ
		{
			"落下",
			0,185,
			160,185,
			FALSE,{{5,3,0}}
		},

	};
	m_Motion.Create(anim, MOTION_COUNT);

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//初期化
void CPlayer::Initialize(void) {

	//初期位置
	m_PosX = PLAYER_START_POS_X;
	m_PosY = PLAYER_START_POS_Y;

	m_MoveY = 0.0f;
	m_legsboxY = PLAYER_LEGS_Y;
	m_Jumpflg = false;
	m_HP = START_HP;
	m_DamageWait = 0;
	m_deathflg = false;

	//無敵フラグ
	_unrivaled = false;
	_chare_A = 255;

	//モーション初期化
	m_Motion.ChangeMotion(MOTION_MOVE);
	m_SrcRect = m_Motion.GetSrcRect();

}

//更新
void CPlayer::Update(void) {

	//ジャンプ処理
	if (g_pInput->IsKeyHold(MOFKEY_SPACE) && m_BSflg) {

		//足音停止
		m_MusicMgmt->SEStop(SE_T_FOOTSTEPS);

		//SE再生
		m_MusicMgmt->SEStart(SE_T_JUMP);

		//ジャンプカウントを1増やす
		m_JumpCount++;

		//ジャンプフラグをFalseに
		m_Jumpflg = false;

		//モーションを変更する
		if (m_Motion.GetMotionNo() == MOTION_MOVE_DAMAGE|| m_Motion.GetMotionNo() == MOTION_JUMP_DAMAGE) {

			//ジャンプダメージモーション
 			m_Motion.ChangeMotion(MOTION_JUMP_DAMAGE);
			
		}
		else
		{
			//ジャンプモーション
			m_Motion.ChangeMotion(MOTION_JUMP);
			
		}

		//todo：ダメージ中の場合別処理

		//大小ジャンプ切り替え
		//スペースを押している間に一定時間超えれば大ジャンプ
		if (m_JumpCount >= 10&& m_BSflg) {
   			m_MoveY = BIGJUMP;
			m_BSflg = false;
			m_MusicMgmt->SEStart(SE_T_GREAT_JUMP);
		}
		else if (!m_Jumpflg)
		{
			//ジャンプ開始 
          	m_MoveY = SMALLJUMP;
		}
	}

	//小ジャン連続阻止
	if (g_pInput->IsKeyPull(MOFKEY_SPACE)) {
		m_BSflg = false;
	}

	//足音再生
	if (m_Motion.GetMotionNo()== MOTION_MOVE&& !m_MusicMgmt->SEisPlay(SE_T_FOOTSTEPS)) {
		m_MusicMgmt->SEStart(SE_T_FOOTSTEPS);
	}

	//重力反映
	m_MoveY += GRAVITY;

	//スピード反映
	m_PosY += m_MoveY;

	//ダメージのインターバルを減らす
	if (m_DamageWait > 0)
	{
		m_DamageWait--;
	}

	//下降速度クリップ
	if (m_MoveY >= 20) {
		m_MoveY = 20 - 0.1f;
	}

	//地面よりも下か？
	if (m_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {

		UPdateCollisionGround(GROUND_Y);

	}

	//落下時
	if (m_MoveY > 1) {

		//足場から降りた時に専用モーションに切り替え
		//ジャンプ時はしない
		if (m_Motion.GetMotionNo() == MOTION_MOVE_DAMAGE) {
			//落下ダメージモーション
			m_Motion.ChangeMotion(MOTION_FALL_DAMAGE);
		}

		if (m_Motion.GetMotionNo() == MOTION_MOVE) {
			//落下時モーション
 			m_Motion.ChangeMotion(MOTION_FALL);
		}
		
		//足場に乗るための処理
		m_Jumpflg = true;
		m_BSflg = false;

		//足音再生
		m_MusicMgmt->SEStop(SE_T_FOOTSTEPS);

	}


	//アニメーション再生
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();

}

void CPlayer::UpdateDebug(void)
{

	//デバッグ用
//無敵になる
	if (g_pInput->IsKeyPull(MOFKEY_M)) {
		//無敵化
		_unrivaled = _unrivaled ? !_unrivaled : !_unrivaled;

		//無敵中半透明に
		_chare_A = _unrivaled ? 125 : 255;
	}

	//デバック
	//ダメージ判定
	//＋左shiftでHPを減らす
	if (g_pInput->IsKeyPull(MOFKEY_D)) {

		if (g_pInput->IsKeyPull(MOFKEY_LSHIFT)) {
			//ダメージ処理
			m_HP--;

			//ゲームオーバー更新
			if (m_HP <= 0) {
				//死亡フラグセット
				m_deathflg = true;
				m_HP = 0;

				//無敵時間なし
				m_DamageWait = 0;
			}
		}
		else
		{
			UPdateCollisionOB();
		}

	}

	if (g_pInput->IsKeyPull(MOFKEY_F)) {

		//ダメージ処理
		m_HP++;
	}


}

//足場、障害物上と当たった場合
//引数：float		y		当たった障害物のＹ座標
void CPlayer::UPdateCollisionBra(float y) {

	if (m_Jumpflg) {

		//プレイヤーの位置を上に上げる
		//障害物上にプレイヤーの足元がくるようにしている
		m_PosY = y- PLAYER_HIT_Y;

		m_MoveY = 0;

		//ジャンプ終了後にクールタイム
		m_JumpCount--;

		//ジャンプカウントが10以上にならないようにする
		if (m_JumpCount > 10)
		{
			m_JumpCount = 10;
		}
		else if (m_JumpCount <= 0)
		{
			//大ジャンプフラグをtrueにする
			m_BSflg = true;

			//ジャンプカウントを0にする
			m_JumpCount = 0;
		}


		//着地時にモーション変更
		//無敵時間中
		if (m_DamageWait > 0) {

			if (m_Motion.GetMotionNo() != MOTION_MOVE_DAMAGE) {
				//ダメージモーション
				m_Motion.ChangeMotion(MOTION_MOVE_DAMAGE);
			}
		}
		else
		{
			if (m_Motion.GetMotionNo() != MOTION_MOVE) {
				//移動モーションに変更
				m_Motion.ChangeMotion(MOTION_MOVE);
			}
		}
	}

}

//地面と当たった場合
//float y:乗る高さ
void CPlayer::UPdateCollisionGround(float y) {

	//地面の高さに移動
	m_PosY = y - PLAYER_HIT_Y;

	//縦移動量
	m_MoveY = 0;

	//ジャンプしていない
	m_Jumpflg = false;

	//ジャンプ終了後にクールタイム
	m_JumpCount--;
	if (m_JumpCount > 10)
	{
		m_JumpCount = 10;
	}
	else if (m_JumpCount <= 0)
	{
		m_BSflg = true;
		m_JumpCount = 0;
	}

	//着地時にモーション変更
	//無敵時間中
	if (m_DamageWait > 0) {

		if (m_Motion.GetMotionNo() != MOTION_MOVE_DAMAGE) {
			//ダメージモーション
			m_Motion.ChangeMotion(MOTION_MOVE_DAMAGE);
		}
	}
	else
	{
		if (m_Motion.GetMotionNo() != MOTION_MOVE) {
			//移動モーションに変更
			m_Motion.ChangeMotion(MOTION_MOVE);
		}
	}
}

//障害物・敵と当たった場合
void CPlayer::UPdateCollisionOB() {

	//無敵時間中は判定しない
	if (m_DamageWait > 0|| _unrivaled)
	{
		return;
	}

	//SE再生
	m_MusicMgmt->SEStart(SE_T_HIT);

	//HP減らす
	m_HP -= 1;

	//ダメージモーションに変更
	switch (m_Motion.GetMotionNo())
	{
	case MOTION_MOVE:
		m_Motion.ChangeMotion(MOTION_MOVE_DAMAGE);
		break;

	case MOTION_JUMP:
		m_Motion.ChangeMotion(MOTION_JUMP_DAMAGE);
		break;

	case MOTION_FALL:
		m_Motion.ChangeMotion(MOTION_FALL_DAMAGE);
		break;
	}

	//ダメージエフェクト再生
	m_pEffectMgmt->Start(0,0,EFC_DAMAGE_HIT);

	//無敵時間
	m_DamageWait = INVINCIBLE_TIME;

	//ゲームオーバー更新
	if (m_HP <= 0) {

		//死亡フラグセット
		m_deathflg = true;
		m_HP = 0;

		//無敵時間なし
		m_DamageWait = 0;

		//汗エフェクト
		m_MusicMgmt->SEStop(SE_T_FOOTSTEPS);

		//ダメージモーションを適応
		m_SrcRect = m_Motion.GetSrcRect();

	}
}

//クリア時の更新
void CPlayer::UpdateClear(void)
{
	//重力反映
	m_MoveY += GRAVITY;

	//スピード反映
	m_PosY += m_MoveY;

	//横移動
	m_PosX += 7;

	//下降速度クリップ
	if (m_MoveY >= 20) {
		m_MoveY = 20 - 0.1f;

	}
	//地面よりも下か？
	if (m_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {
		UPdateCollisionGround(GROUND_Y);
	}

	//足音再生
	if (m_Motion.GetMotionNo() == MOTION_MOVE && !m_MusicMgmt->SEisPlay(SE_T_FOOTSTEPS)) {
		m_MusicMgmt->SEStart(SE_T_FOOTSTEPS);
	}

	//アニメーション再生
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
	//ダメージのインターバルを減らす
	if (m_DamageWait > 0)
	{
		m_DamageWait--;
	}

}

//描画
void CPlayer::Render()
{

	//画面端0　余白15　[4分の1-画像幅/2]　[4分の2-画像幅/2]　[4分の3-画像幅/2]　余白15　進行度画像280　（上の段）
	//画面端0　余白15　　　　　　　[3分の1-画像幅/2]　[3分の2-画像幅/2]　　　　 余白15　進行度画像280　（下の段）
	//HPのフレーム描画
	m_HPFrame.Render(15 + 265 / 4 - m_HPFrame.GetWidth() / 2, 20);
	m_HPFrame.Render(15 + 265 / 2 - m_HPFrame.GetWidth() / 2, 20);
	m_HPFrame.Render(15 + 265 / 4 * 3 - m_HPFrame.GetWidth() / 2, 20);
	m_HPFrame.Render(15 + 265 / 3 - m_HPFrame.GetWidth() / 2 + 10, 70);
	m_HPFrame.Render(15 + 265 / 3 * 2 - m_HPFrame.GetWidth() / 2 - 10, 70);

	//HPの描画
	// m_DamageWait（ダメージ）が発生中は m_HP を +1 したときの画像を点滅　m_DamageWait の値が 0 になれば点滅、表示の終了
	if (m_HP >= 1 || m_DamageWait % 5 == 1 && m_HP == 0) {
		m_HPTexture.Render(15 + 265 / 4 - m_HPTexture.GetWidth() / 2, 20);			//左上
	}
	if (m_HP >= 2 || m_DamageWait % 5 == 1 && m_HP == 1) {
		m_HPTexture.Render(15 + 265 / 3 - m_HPTexture.GetWidth() / 2 + 10, 70);		//左下
	}
	if (m_HP >= 3 || m_DamageWait % 5 == 1 && m_HP == 2) {
		m_HPTexture.Render(15 + 265 / 2 - m_HPTexture.GetWidth() / 2, 20);			//中上
	}
	if (m_HP >= 4 || m_DamageWait % 5 == 1 && m_HP == 3) {
		m_HPTexture.Render(15 + 265 / 3 * 2 - m_HPTexture.GetWidth() / 2 - 10, 70);	//右下
	}
	if (m_HP >= 5 || m_DamageWait % 5 == 1 && m_HP == 4) {
		m_HPTexture.Render(15 + 265 / 4 * 3 - m_HPTexture.GetWidth() / 2, 20);		//右上
	}

	//無敵時間2フレーム描画しない
	if (m_DamageWait % 4 >= 2)
	{
		return;
	}

	//描画矩形
	CRectangle br = m_SrcRect;

	//描画位置
	float px = m_PosX;
	float py = m_PosY;

	//キャラクター描画
	m_Texture.Render(px, py, br,MOF_ARGB(_chare_A,255,255,255));

}

//デバック表示
void CPlayer::RenderDebugging() {

	switch (m_Motion.GetMotionNo())
	{

		case MOTION_MOVE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_MOVE");
			break;

		case MOTION_JUMP:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_JUMP");
			break;

		case MOTION_FALL:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_FALL");
			break;

		case MOTION_MOVE_DAMAGE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_MOVE_DAMAGE");
			break;

		case MOTION_JUMP_DAMAGE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_JUMP_DAMAGE");
			break;

		case MOTION_FALL_DAMAGE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_FALL_DAMAGE");
			break;

	}

	//CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "m_MoveY=%f", m_MoveY);


	//キャラクターの判定矩形
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(GetLegsRect(), MOF_COLOR_GREEN);

#pragma region デバッグ用

	//CGraphicsUtilities::RenderString(500, 500, MOF_XRGB(80, 80, 80), "m_DamageWait%d", m_DamageWait);

	//if (m_Jumpflg) {
	//CGraphicsUtilities::RenderString(500, 500, MOF_XRGB(80, 80, 80), "m_Jumpflg=true");

	//}
	//else
	//{
	//	CGraphicsUtilities::RenderString(500, 500, MOF_XRGB(80, 80, 80), "m_Jumpflg=false");

	//}

	//if (m_BSflg) {
	//	CGraphicsUtilities::RenderString(500, 560, MOF_XRGB(80, 80, 80), "m_BSflg=true");

	//}
	//else
	//{
	//	CGraphicsUtilities::RenderString(500, 560, MOF_XRGB(80, 80, 80), "m_BSflg=false");

	//}


	////ジャンプフラグ表示
	//if (m_Jumpflg) {
	//	CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "m_Jumoflg=true");
	//}	
	//else
	//{
	//	CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "m_Jumoflg=false");
	//}


	////大ジャンプフラグ
	//if (m_BSflg) {
	//	CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "m_BSflg=true");
	//}
	//else
	//{
	//	CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "m_BSflg=false");
	//}



#pragma endregion

}

//解放
void CPlayer::Release(void) {
	m_Texture.Release();
	m_Motion.Release();

	//描画の解放
	m_HPTexture.Release();
	m_HPFrame.Release();

}
