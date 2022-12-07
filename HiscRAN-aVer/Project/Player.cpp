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
	m_BSflg(true)
{
}

CPlayer::~CPlayer() {


}

//読み込み
bool CPlayer::Load(void) {


	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("PlayerCharacter");

	//キャラクター読み込み
	if (!m_Texture.Load("走りとジャンプモーション2022_11_08.png")) {
		return false;
	}

	//仮置きです
	float n = 2;

	//アニメーション
	SpriteAnimationCreate anim[] = 
	{
		{
			//モーション
			"移動",
			0,0,
			160,185,
			TRUE,{{n,0,0},{n,1,0},{n,2,0},{n,3,0},{n,4,0},{n,5,0},{n,6,0},{n,7,0},{n,8,0},{n,9,0},{n,10,0}
			,{n,11,0},{n,12,0},{n,13,0},{n,14,0}}

		},
		//ジャンプ
		{
			"ジャンプ開始",
			0,185,
			160,185,
			FALSE,{{5,0,2}}
		}
	};
	m_Motion.Create(anim, MOTION_COUNT);

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

//初期化
void CPlayer::Initialize(void) {


	m_PosX = PLAYER_START_POS_X;
	m_PosY = PLAYER_START_POS_Y;
	m_MoveY = 0.0f;
	m_legsboxY = PLAYER_LEGS_Y;
	m_Jumpflg = false;
	m_HP = 3;
	m_DamageWait = 0;
	m_deathflg = false;


	m_Motion.ChangeMotion(MOTION_MOVE);

}

//更新
void CPlayer::Update(void) {

	//ジャンプ処理
	if (g_pInput->IsKeyHold(MOFKEY_SPACE) && m_BSflg) {

		//ジャンプ開始
		if (!m_Jumpflg) {
			m_MoveY = SMALLJUMP;
		}

		//SE再生
		m_MusicMgmt->SEStart(SET_PAWANN);

		m_JumpCount++;
		m_Jumpflg = true;
		m_Motion.ChangeMotion(MOTION_JUMPSTART);

		//大小ジャンプ切り替え
		//押している間に一定時間超えれば大ジャンプ
		if (m_JumpCount >= 10&& m_BSflg) {
   			m_MoveY = BIGJUMP;
			m_BSflg = false;
		}
		
	}

	//小ジャンプの何回もできるやつを阻止したやつ
	if (g_pInput->IsKeyPull(MOFKEY_SPACE)) {
		m_BSflg = false;
	}

	//重力反映
	m_MoveY += GRAVITY;

	//スピード反映
	m_PosY += m_MoveY;
	
	//下降速度クリップ
	if (m_MoveY >= 20) {
		m_MoveY = 20 - 0.1f;
	}

	//下降中
	if (m_MoveY >= 0) {
		m_Jumpflg = false;
		m_BSflg = false;
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

	//上昇中フラグがfalseになった時に上からバーに乗る
	if (!m_Jumpflg) {
		m_PosY = y;
		m_PosY -= PLAYER_HIT_Y;

		m_MoveY = 0;

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
	}

	//移動モーション
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}
}

//地面と当たり判定
//CRectangle 相手の矩形
bool CPlayer::CollosopnGround(CRectangle r) {

	//地面矩形と判定
	if (legsGetRect().CollisionRect(r))
	{
		return true;
	}
	return false;
}

//地面と当たった場合
//float y:地面の高さ
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

	//移動モーション
	if (m_Motion.GetMotionNo() != MOTION_MOVE) {
		m_Motion.ChangeMotion(MOTION_MOVE);
	}

}


//障害物と当たり判定
bool CPlayer::CollosopnOB(CRectangle r) {

	if (GetRect().CollisionRect(r))
	{

		return true;
	}
	return false;
}


//障害物・敵と当たった場合
void CPlayer::UPdateCollisionOB() {

	//無敵時間中は判定しない
	if (m_DamageWait > 0)
	{
		return;
	}
	m_HP -= 1;
	m_DamageWait = 60;

	if (m_HP <= 0) {
		m_deathflg = true;
		//m_HP = 0;
	}
}

//敵当たり判定
bool CPlayer::CollosopnEnemy(CRectangle r) {

	//無敵時間中は判定しない
	if (m_DamageWait > 0)
	{
		return false;
	}
	if (GetRect().CollisionRect(r)) {
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

	m_Texture.Render(px, py, br);

	//仮キャラ
	//m_TEX.Render(px, py);
		//HP表示
	CGraphicsUtilities::RenderString(0, 260, MOF_XRGB(80, 80, 80), "HP:%d", m_HP);

}

//デバック表示
void CPlayer::RenderDebugging() {

	switch (m_Motion.GetMotionNo())
	{


		case MOTION_MOVE:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_MOVE");
			break;

		case MOTION_JUMPSTART:
			CGraphicsUtilities::RenderString(0, 90, MOF_XRGB(80, 80, 80), "現在モーション：MOTION_JUMPSTART");
			break;
	}

	//キャラクターの判定矩形
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
	CGraphicsUtilities::RenderRect(legsGetRect(), MOF_COLOR_GREEN);

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
}
