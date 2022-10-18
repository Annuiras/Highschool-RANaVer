#include "Player.h"

CPlayer::CPlayer() :
	m_Texture(),
	m_SrcRect(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_hitboxX(0.0f),
	m_hitboxY(0.0f),
	m_legsboxY(0.0f),
	m_OverX(0.0f),
	m_OverY(0.0f),
	m_StopX(0.0f),
	m_HP(0),
	m_DamageWait(0),
	m_Startflg(false),
	m_deathflg(false),
	m_JumpPower(0.0f),
	m_Jumpflg(false),
	m_JumpCount(0.0f)
{

}

CPlayer::~CPlayer() {


}

//読み込み
bool CPlayer::Load(void) {

	////キャラクター読み込み
	//if (!m_Texture.Load("player.png")) {
	//	return false;
	//}

	//キャラクター読み込み
	if (!m_Texture.Load("880×153RunMotion.png")) {
		return false;
	}

	if (!m_TEX.Load("880×153RunMotion.png")) {
		return false;
	}

	//アニメーション
	SpriteAnimationCreate anim[] = {

		{
			"待機",
			0,0,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
		},
		{
			//"移動",
			//0,70,
			//60,64,
			//TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}

			//仮モーション用
			"移動",
			0,0,
			110,153,
			TRUE,{{10,0,0},{10,1,0},{10,2,0},{10,3,0},{10,4,0},{10,5,0},{10,6,0},{10,7,0}}

		},
		//ジャンプ
		{
			"ジャンプ開始",
			0,140,
			60,64,
			FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}}
		},
		{
			//使ってないです
			"ジャンプ終了",
			240,140,
			60,64,
			FALSE,{{2,0,0},{2,1,0}}
		},
		//ダメージ
		{
			"ダメージ",
			480,0,
			60,64,
			FALSE,{{20,0,0}}
		},
	};
	m_Motion.Create(anim, MOTION_COUNT);
	return true;
}

//初期化
void CPlayer::Initialize(void) {


	m_PosX = 50;
	m_PosY = 300;
	m_MoveX = 7.0f;
	m_MoveY = 0.0f;
	m_JumpPower = 0.0f;
	m_hitboxX = 160;
	m_hitboxY = 185;
	m_legsboxY = 100;
	m_StopX = 50;
	m_Jumpflg = false;
	m_HP = 3;
	m_DamageWait = 0;
	m_deathflg = false;
	m_Startflg = false;
	m_OverX = 0;

	m_Motion.ChangeMotion(MOTION_WAIT);

}

//更新
void CPlayer::Update(void) {


	//待機中の場合の処理
	if (!m_Startflg)
	{
		//表示矩形をセット
		m_SrcRect = m_Motion.GetSrcRect();

		//オーバーした分初期化
		m_OverX = 0;

		return;
	}

	//オーバーした分初期化
	m_OverX = 0;

	//ダメージ中の動作
	if (m_Motion.GetMotionNo() == MOTION_DAMAGE)
	{
		//終了で待機に戻す
		if (m_Motion.IsEndMotion())
		{
			m_Motion.ChangeMotion(MOTION_WAIT);
		}
	}

	//ジャンプ処理
	if (g_pInput->IsKeyHold(MOFKEY_SPACE)) {
		m_JumpCount++;
	}
	//離したときにジャンプ処理
	if (g_pInput->IsKeyPull(MOFKEY_SPACE) && !m_Jumpflg) {
		//ジャンプ開始
		m_Jumpflg = true;

		if (m_JumpCount >= 15) {
			m_MoveY = BIGJUMP;
		}
		else {
			m_MoveY = SMALLJUMP;
		}

		m_Motion.ChangeMotion(MOTION_JUMPSTART);
	}

	//スライディング処理
	if (g_pInput->IsKeyHold(MOFKEY_DOWN)) {

	}


	//重力反映
	m_MoveY += GRAVITY;

	//スピード反映
	m_PosY += m_MoveY;
	m_PosX += m_MoveX;

	

	//画面上ではX位置動かないように調整
	if (m_PosX > m_StopX) {

		m_OverX += m_PosX - m_StopX;
		m_PosX = m_StopX;
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

//足場当たり判定
bool CPlayer::CollosopnBar(CRectangle r) {
	if (legsGetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}


//足場と当たった場合
void CPlayer::UPdateCollisionBra(float y) {

	m_PosY = y;
	m_PosY -= m_hitboxY;

	if (m_Jumpflg) {
		m_JumpCount = 0;
	}
	m_MoveY = 0;
	m_Jumpflg = false;

	//移動モーション
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}
}

//地面と当たり判定
//float y:地面の高さ
bool CPlayer::CollosopnGround(float y) {

	//キャラのY座標＋当たり判定が地面高さより下しになった場合
	if (m_PosY + m_hitboxY > y) {
		return true;
	}
	return false;
}

//地面と当たった場合
//float y:地面の高さ
void CPlayer::UPdateCollisionGround(float y) {

	m_PosY = y - m_hitboxY;

	if (m_Jumpflg) {
		m_JumpCount = 0;
	}
	m_MoveY = 0;
	m_Jumpflg = false;

	//移動モーション
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}

}


//障害物と当たり判定
bool CPlayer::CollosopnOB(CRectangle r) {

	//無敵時間中は判定しない
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r))
	{
		m_Motion.ChangeMotion(MOTION_DAMAGE);
		return true;
	}
	return false;
}


//障害物・敵と当たった場合
void CPlayer::UPdateCollisionOB() {

	m_HP -= 1;
	m_DamageWait = 60;
	if (m_HP <= 0) {
		m_deathflg = true;
		m_HP = 0;
	}
}

//ゲームスタート切り替え
void CPlayer::GameStopPlayChange()
{
	//待機モーションから移動モーションへ
	//m_Motion.ChangeMotion(MOTION_MOVE);
	if (m_Startflg) {

		m_Startflg = false;

	}
	else
	{
		m_Startflg = true;

	}
}

//キャラが動いているか取得
bool CPlayer::GetGameStopPlay() {

	return m_Startflg;

}

//未使用:敵当たり判定
bool CPlayer::CollosopnEnemy(CRectangle r) {

	//無敵時間中は判定しない
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {
		m_DamageWait = 60;
		m_Motion.ChangeMotion(MOTION_DAMAGE);
		return true;
	}
	return false;
}


//描画
void CPlayer::Render()
{
	if (m_DamageWait % 4 >= 2)
	{
		return;
	}

	CRectangle br = m_SrcRect;

	//描画位置
	float px = m_PosX;
	float py = m_PosY;

	//m_Texture.Render(px, py, br);

	//仮キャラ
	m_TEX.Render(px, py);
	//キャラクターの判定矩形
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(legsGetRect(), MOF_COLOR_GREEN);
}

//デバック表示
void CPlayer::DebuggingRender() {

	switch (m_Motion.GetMotionNo())
	{

		case MOTION_WAIT:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_WAIT");
			break;

		case MOTION_MOVE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_MOVE");
			break;

		case MOTION_JUMPSTART:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_JUMPSTART");
			break;

		case MOTION_JUMPEND:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_JUMPEND");
			break;
		case MOTION_DAMAGE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_DAMAGE");
			break;
	}

	//HP表示
	CGraphicsUtilities::RenderString(0, 260, MOF_XRGB(80, 80, 80), "HP:%d", m_HP);

}

//解放
void CPlayer::Release(void) {
	m_Texture.Release();
	m_Motion.Release();
	m_TEX.Release();
}
