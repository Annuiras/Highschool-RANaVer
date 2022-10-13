#include "Player.h"

CPlayer::CPlayer() :
	m_Texture(),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_OverX(0.0f),
	m_OverY(0.0f),
	m_hitboxX(0.0f),
	m_hitboxY(0.0f),
	m_JumpPower(0.0f),
	m_Jumpflg(false),
	m_HP(0),
	m_deathflg(false),
	m_Startflg(/*true*/ false) //stageに呼び出されてからtrueに変更される。後で変更
{

}

CPlayer::~CPlayer() {


}

//読み込み
bool CPlayer::Load(void) {

	//キャラクター読み込み
	if (!m_Texture.Load("player.png")) {
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
		//移動
		{
			"移動",
			0,70,
			60,64,
			TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
		},
		//ジャンプ
		{
			"ジャンプ開始",
			0,140,
			60,64,
			FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}}
		},
		{
			//使ってないですs
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
	m_PosY = 410;
	m_MoveX = 7.0f;
	m_MoveY = 0.0f;
	m_JumpPower = 0.0f;
	m_hitboxX = 100;
	m_hitboxY = 150;
	m_legsboxY = 140;
	m_StopX = 50;
	m_Jumpflg = false;
	m_HP = 3;
	m_DamageWait = 0;
	m_deathflg = false;
	m_standby = true;

	m_Motion.ChangeMotion(MOTION_WAIT);

}

//更新
void CPlayer::Update(void) {

	//待機中の場合の処理
	if (!m_Startflg) {

		m_OverX = 0;
		m_SrcRect = m_Motion.GetSrcRect();

		return;
	}

	//todo:ゲーム開始フラグの統一
	//ゲームスタート
	if (m_Startflg == true) {

		//todo:MOTION_DAMAGEをセットする処理の追加
		//セットしてないからこの処理の意味消えちゃってる
		//ダメージ中の動作
		if (m_Motion.GetMotionNo() == MOTION_DAMAGE)
		{
			//終了で待機に戻す
			if (m_Motion.IsEndMotion())
			{
				m_Motion.ChangeMotion(MOTION_WAIT);
			}
		}

		////Enter押した時走る
		//if (g_pInput->IsKeyPush(MOFKEY_RETURN))
		//{
		//	if (!m_deathflg)
		//	{
		//		m_standby = false;
		//	}
		//	m_Motion.ChangeMotion(MOTION_MOVE);
		//}


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

		//地面着地
		if (m_PosY >= 550)
		{
			if (m_Jumpflg) {
				m_JumpCount = 0;
			}
			m_PosY = 550;
			m_MoveY = 0;
			m_Jumpflg = false;

			//移動モーション
			if (m_Motion.GetMotionNo() == MOTION_JUMPSTART) {
				m_Motion.ChangeMotion(MOTION_MOVE);
			}
		}

		//todo:アニメーションの再生が重複しているバグの解消->おそらくここ
		//アニメーション再生
		m_Motion.AddTimer(CUtilities::GetFrameSecond());
		m_SrcRect = m_Motion.GetSrcRect();
	}
	else {
		m_Motion.ChangeMotion(MOTION_WAIT);
	}

	//オーバーした分初期化
	m_OverX = 0;
	//スピード反映
	m_PosX += m_MoveX;

	//画面上ではX位置動かないように調整
	if (m_PosX > m_StopX) {

		m_OverX += m_PosX - m_StopX;
		m_PosX = m_StopX;
	}

	//todo:アニメーションの再生が重複しているバグの解消->とここ
	//アニメーション再生
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
	//ダメージのインターバルを減らす
	if (m_DamageWait > 0)
	{
		m_DamageWait--;
	}
}
//todo:地面と接触した場合の関数の追加->
//プロトタイプが参考になると思う、引数：地面の高さ
//地面当たり判定
bool CPlayer::CollosopnObje(CRectangle r) {
	if (legsGetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}

//障害物と当たり判定
bool CPlayer::CollosopnOB(CRectangle r) {

	//無敵時間中は判定しない
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {

		//todo:ここの無敵時間処理をUPdeteCollisionOBに移動してくれると見やすくてうれしい
		m_DamageWait = 60;
		return true;
	}
	return false;
}

//敵当たり判定
bool CPlayer::CollosopnEnemy(CRectangle r) {

	//無敵時間中は判定しない
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {
		m_DamageWait = 60;
		return true;
	}
	return false;
}

//障害物・敵と当たった場合
void CPlayer::UPdeteCollisionOB() {

	m_HP -= 1;
	if (m_HP <= 0) {
		m_deathflg = true;
		m_HP = 0;
		m_standby = true;
	}
}

//todo:ゲームスタートの切り替えの追加->この処理呼び出されてないからフラグ切り替えられないです
//ゲームスタート切り替え
bool CPlayer::GameStart() {
	//待機モーションから移動モーションへ
	m_Motion.ChangeMotion(MOTION_MOVE);
	m_Startflg = true;
	return true;
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

	m_Texture.Render(px, py, br);
	//キャラクターの判定矩形
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(legsGetRect(), MOF_COLOR_GREEN);
}

//デバック表示
void CPlayer::DebuggingRender() {

}

//解放
void CPlayer::Release(void) {
	m_Texture.Release();
	m_Motion.Release();
}
