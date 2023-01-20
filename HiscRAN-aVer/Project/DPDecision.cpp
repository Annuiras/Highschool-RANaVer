///////////////////////////////////////////
//　DP選択画面のプログラムです   　　  　//
//								   　　　//
//　作成者：松浦未羽  　　　　　　　　　 //
//								   　　　//
//　リファクタリングした人：田中環 　　　//
//								   　　　//
//　最終更新：2023/01/19		   　　　//
///////////////////////////////////////////

#include "DPDecision.h"

//コンストラクタ
CDPDecision::CDPDecision() :
	RandmuBak(),
	m_Back_BB(),
	m_BackChara_B(),
	m_Target_Text(),
	m_SelectTexture(),
	m_BackMagnet_Name(),
	m_WhiteBakAlph(),
	DPDecCnt(),
	flagD(true),
	SP_flg()
{

}

//デストラクタ
CDPDecision::~CDPDecision()
{

}

//素材ロード
void CDPDecision::Load(void)
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("DPDecision");

	//背景黒板
	if (!m_Back_BB.Load("DPDecision_new_2.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//選択枠
	if (!m_SelectTexture.Load("DPDecision_new_4.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//黒塗りキャラ
	if (!m_BackChara_B.Load("DPDecision_new_3.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//マグネット&名前
	if (!m_BackMagnet_Name.Load("DPDecision_new_1.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//目標文字
	if (!m_Target_Text.Load("DPDecision_Text.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//画面説明
	if (!m_Screen_Ex.Load("DPDecision_new_ExText.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	//ロード状況更新
	b_LoadSitu = LOAD_COMP;

}

//初期化
void CDPDecision::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{
	//各マネージャーセット
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//素材ロード
	Load();

	//エラー状態でない場合
	if (b_LoadSitu == LOAD_COMP) {
		//初期化完了
		b_LoadSitu = LOAD_DONE;
	}

	//選択肢初期化
	DPDecCnt = 0;

	//説明表示
	flagD = true;

	//フェードイン
	m_WhiteBakAlph = 255;
	b_Fadein = FADE_IN;

	//SPステージかどうかを判定
	SP_flg =false;
	if (RandmuBak.GetRandomNumbe(0, 5) == 50) {
		//五分の一の確率でSPステージ発生
		SP_flg = true;
	}

}

//更新
void CDPDecision::Update(void)
{
	//BGM再生
	b_MusicManager->BGMStart(BGMT_DPDECISION);

	//デバック更新
	UpdateDebug();

	//フェードイン処理
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph,true);
		return;
	}

	//フェードアウト完了時
	if (b_Fadein == FADE_NEXT) {

		//メニューのタイプ処理
		if (b_MenuMamt->GetMenuType()== MENUT_GAME_END) {
			m_bEnd = true;
			m_NextScene = SCENENO_SELECTMODE;
		}
		else
		{
			//項目を選んでいる
			m_bEnd = true;
			m_NextScene = SCENENO_GAME;
		}

	}

	//フェードアウト処理
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}


	//説明表示中
	if (flagD == true)
	{
		//エンターで非表示
		if (g_pInput->IsKeyPush(MOFKEY_RETURN)) {
			flagD = false;

			//SE再生：カーソル移動
			b_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		}		
		return;
	}

	if (b_MenuMamt->IsShow())
	{
		//メニューの更新
		b_MenuMamt->Update();

		//メニュー決定時
		if (b_MenuMamt->IsEnter())
		{
			//メニューのタイプ別処理
			switch (b_MenuMamt->GetMenuType())
			{
			case MENUT_DPCONFIRM:
				if (b_MenuMamt->GetSelect() == 0)
				{
					b_Fadein = FADE_OUT;
					//DPの選択を記録
					b_GameProgMamt->SetDPdec_type(DPDecCnt);
					//メニュー非表示
					b_MenuMamt->Hide();
				}
				else if (b_MenuMamt->GetSelect() == 1)
				{
					//メニュー非表示
					b_MenuMamt->Hide();
				}

				break;

			case MENUT_GAME_END:
				if (b_MenuMamt->GetSelect() == 0)
				{
					b_Fadein = FADE_OUT;
					//メニュー非表示
					b_MenuMamt->Hide();
				}
				else if (b_MenuMamt->GetSelect() == 1)
				{
					//メニュー非表示
					b_MenuMamt->Hide();
				}
				break;
			default:
				break;
			}

		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		//DP選択確定メニュー表示
		b_MenuMamt->Show(MENUT_DPCONFIRM);

		//SE再生：決定時
		b_MusicManager->SEStart(SE_T_DECISION);
	}
	else if(g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//終了メニュー表示
		b_MenuMamt->Show(MENUT_GAME_END);
	}
	else 
	{
		//矢印キー右で選択が右に行くようにする
		if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
		{
			if (DPDecCnt < DPDECISION_MENUCNT - 1)
			{
				DPDecCnt++;

				//SE再生：カーソル移動
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}
		//矢印キー左で選択が左に行くようにする
		else if (g_pInput->IsKeyPush(MOFKEY_LEFT))
		{
			if (DPDecCnt > 0)
			{
				DPDecCnt--;

				//SE再生：カーソル移動
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}
		//矢印キー下で選択が下がるようにする
		//下に下がる＝３つ先のものになる
		if (g_pInput->IsKeyPush(MOFKEY_DOWN))
		{
			if (DPDecCnt < DPDECISION_MENUCNT - 1 && DPDecCnt < 2)
			{
				DPDecCnt += 3;

				//SE再生：カーソル移動
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
			else if (DPDecCnt == 3)
			{
				DPDecCnt = 3;

				//SE再生：カーソル移動
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}

		//矢印キー上で選択が上がるようにする
		//上に上がる＝３つ前のものになる
		if (g_pInput->IsKeyPush(MOFKEY_UP))
		{
			if (DPDecCnt > 0 && DPDecCnt - 3 >= 0)
			{
				DPDecCnt -= 3;

				//SE再生：カーソル移動
				b_MusicManager->SEStart(SE_T_SE_DEC);
			}
		}

	}
}

void CDPDecision::UpdateDebug(void)
{

	//SPフラグの切り替え
	if (g_pInput->IsKeyPush(MOFKEY_P))
	{
		SP_flg = !SP_flg;
	}

}

//描画
void CDPDecision::Render(void)
{
	//背景黒板
	m_Back_BB.Render(0, 0);

	//黒塗りキャラ
	m_BackChara_B.Render(0, 0);

	//選択画像描画座標位置（X座標）
	int PosSelectX = 399;

	//選択画像描画座標位置（Y座標）
	int PosSelectY = 350;

	//表示位置、矩形を算出
	int addX = DPDecCnt % 3;
	int addY = DPDecCnt / 3;
	//画像矩形
	CRectangle recSelect(PosSelectX * addX, PosSelectY* addY, 
						 PosSelectX+(PosSelectX * addX), PosSelectY+(PosSelectY * addY));

	//選択枠
	m_SelectTexture.Render(recSelect.Left, recSelect.Top, recSelect);

	//マグネット&名前
	m_BackMagnet_Name.Render(0, 0);


	//配列の番号とDP名の対応は以下の通りです。
	//[0]→想像力
	//[1]→行動力
	//[2]→魅力
	//[3]→コミュ力
	//[4]→学力

	//説明文字表示位置X
	int	PosTextX[5] = { 867,867,867,867,856 };
	//説明文字表示位置Y
	int PosTextY = 397;
	//説明文字矩形
	CRectangle recExText[5] = { {0,0,343,259},{344,0,687,259},{688,0,1031,259},{0,259,344,518},{344,259,708,519} };

	//説明文字
	m_Target_Text.Render(PosTextX[DPDecCnt], PosTextY,recExText[DPDecCnt]);

	//初回表示時説明表示
	if (flagD == true)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(100, 0, 0, 0));
		m_Screen_Ex.Render(0, 124);
	}

	//メニューの描画
	if (b_MenuMamt->GetMenuType() == MENUT_DPCONFIRM){

		//DP選択決定メニュー画面
		b_MenuMamt->Render(DPDecCnt);

	}
	else
	{
		//ゲーム画面終了画面
		b_MenuMamt->Render();
	}

	//フェードアウト
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}

//デバック描画
void CDPDecision::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(10, 300, "DPDecCnt:%d", DPDecCnt);

	if (SP_flg) {
		CGraphicsUtilities::RenderString(10, 330, "SPあり");

	}
	else
	{
		CGraphicsUtilities::RenderString(10, 330, "SPなし");

	}

}

void CDPDecision::Release(void)
{
	//画像素材の解放
	m_Back_BB.Release();
	m_BackChara_B.Release();
	m_Target_Text.Release();
	m_SelectTexture.Release();
	m_Screen_Ex.Release();
	m_BackMagnet_Name.Release();

	//SPフラグを保存
	b_GameProgMamt->SetDPdec_SPflg(SP_flg);

	//BGMストップ
	b_MusicManager->BGMStop(BGMT_DPDECISION);
}