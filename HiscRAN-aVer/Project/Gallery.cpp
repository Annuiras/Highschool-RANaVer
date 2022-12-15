#include "Gallery.h"


#define MenuCnt (16)

int galleryCnt = 0;



CGallery::CGallery() :
	m_BackTexture(),
	m_LastApp(),
	m_NotLastApp(),
	m_SelectTexture(),
	m_SelectTexture_s(),
	m_BackButton(),
	m_PickUp(),
	m_Text(),
	gFont1(),
	gFont2()
{

}

CGallery::~CGallery()
{

}

//ロード
bool CGallery::Load(void)
{

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("Gallery");

	//背景テクスチャの読み込み
	if (!m_BackTexture.Load("CollectionBG.png"))
	{
		return false;
	}

	//最終容姿選択画像読み込み
	if (!m_LastApp.Load("collection.png"))
	{
		return false;
	}

	//未解放最終容姿選択画像読み込み
	if (!m_NotLastApp[0].Load("collection_NotFound_00.png"))
	{
		return false;
	}

	if (!m_NotLastApp[1].Load("collection_NotFound_01.png"))
	{
		return false;
	}

	if (!m_NotLastApp[2].Load("collection_NotFound_02.png"))
	{
		return false;
	}

	if (!m_NotLastApp[3].Load("collection_NotFound_03.png"))
	{
		return false;
	}

	if (!m_NotLastApp[4].Load("collection_NotFound_04.png"))
	{
		return false;
	}

	if (!m_NotLastApp[5].Load("collection_NotFound_05.png"))
	{
		return false;
	}

	if (!m_NotLastApp[6].Load("collection_NotFound_06.png"))
	{
		return false;
	}

	if (!m_NotLastApp[7].Load("collection_NotFound_07.png"))
	{
		return false;
	}

	if (!m_NotLastApp[8].Load("collection_NotFound_08.png"))
	{
		return false;
	}

	if (!m_NotLastApp[9].Load("collection_NotFound_09.png"))
	{
		return false;
	}

	if (!m_NotLastApp[10].Load("collection_NotFound_10.png"))
	{
		return false;
	}

	if (!m_NotLastApp[11].Load("collection_NotFound_11.png"))
	{
		return false;
	}

	if (!m_NotLastApp[12].Load("collection_NotFound_12.png"))
	{
		return false;
	}

	if (!m_NotLastApp[13].Load("collection_NotFound_13.png"))
	{
		return false;
	}

	if (!m_NotLastApp[14].Load("collection_NotFound_14.png"))
	{
		return false;
	}


	//選択時の四角形
	if (!m_SelectTexture.Load("Select.png"))
	{
		return false;
	}



	//最終容姿の台紙テクスチャ(バラ&ピックアップ用)
	if (!m_LastAppPic[0].Load("Picup1.png"))
	{
		return false;
	}

	if (!m_LastAppPic[1].Load("Picup2.png"))
	{
		return false;
	}

	if (!m_LastAppPic[2].Load("Picup3.png"))
	{
		return false;
	}

	if (!m_LastAppPic[3].Load("Picup4.png"))
	{
		return false;
	}

	if (!m_LastAppPic[4].Load("Picup5.png"))
	{
		return false;
	}

	if (!m_LastAppPic[5].Load("Picup6.png"))
	{
		return false;
	}

	if (!m_LastAppPic[6].Load("Picup7.png"))
	{
		return false;
	}

	if (!m_LastAppPic[7].Load("Picup8.png"))
	{
		return false;
	}

	if (!m_LastAppPic[8].Load("Picup9.png"))
	{
		return false;
	}

	if (!m_LastAppPic[9].Load("Picup10.png"))
	{
		return false;
	}

	if (!m_LastAppPic[10].Load("Picup11.png"))
	{
		return false;
	}

	if (!m_LastAppPic[11].Load("Picup12.png"))
	{
		return false;
	}

	if (!m_LastAppPic[12].Load("Picup13.png"))
	{
		return false;
	}

	if (!m_LastAppPic[13].Load("Picup14.png"))
	{
		return false;
	}

	if (!m_LastAppPic[14].Load("Picup15.png"))
	{
		return false;
	}


	if (!m_PickUp.Load("Picup.png"))
	{
		return false;
	}

	if (!m_Text.Load("Text.png"))
	{
		return false;
	}

	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectoryA("../");

	if (!m_SelectTexture_s.Load("Select_s.png"))
	{
		return false;
	}

	//戻るボタン
	if (!m_BackButton.Load("BackButton.png"))
	{
		return false;
	}

	return true;
}

//初期化
void CGallery::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	gFont1.Create(44, "UD デジタル 教科書体 N-B");
	gFont2.Create(32, "UD デジタル 教科書体 N-B");
	Load();

	g_MusicManager->BGMStart(BGMT_GALLERY);

	m_NowScene = SCENENO_GALLERY;

}

//更新
void CGallery::Update(void)
{

	//Enterで戻るかは検討
	if (galleryCnt == 15 && g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}
	//F1キーでタイトル画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//矢印キー右で選択が右に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT))
	{
		//SE再生被りなし調整可
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1)
		{
			galleryCnt++;
		}
	}

	//矢印キー左で選択が左に行くようにする
	if (g_pInput->IsKeyPush(MOFKEY_LEFT))
	{
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0)
		{
			galleryCnt--;
		}
	}

	//矢印キー下で選択が下がるようにする
	//下に下がる＝5つ先のものになる
	if (g_pInput->IsKeyPush(MOFKEY_DOWN))
	{
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt < MenuCnt - 1 && galleryCnt <= 10)
		{
			galleryCnt += 5;
		}
		else if (galleryCnt > 10)
		{
			galleryCnt = 15;
		}
	}
	//矢印キー上で選択が上がるようにする
	//上に上がる＝5つ前のものになる
	if (g_pInput->IsKeyPush(MOFKEY_UP))
	{
		g_MusicManager->SEStart(SE_T_GALL_CURSORMOVE);
		if (galleryCnt > 0 && galleryCnt - 5 >= 0)
		{
			galleryCnt -= 5;
		}
	}


}

//描画
void CGallery::Render(void)
{

	//最終容姿台紙
	m_BackTexture.Render(0, 0);

	m_LastApp.Render(60, 40);

	//最終容姿表示位置
	m_PickUp.Render(766, 40);

	//テキストボックス
	m_Text.Render(766, 461);

	//戻るボタン
	m_BackButton.Render(60, 650);

	//フラグがfalseの場合、最終容姿を隠す処理
	//画像に差し替える
	if (LastAddFlag[0] == false)
	{
		m_NotLastApp[0].Render(60, 40);
	}

	if (LastAddFlag[1] == false)
	{
		m_NotLastApp[1].Render(180, 40);
	}

	if (LastAddFlag[2] == false)
	{
		m_NotLastApp[2].Render(300, 40);
	}

	if (LastAddFlag[3] == false)
	{
		m_NotLastApp[3].Render(420, 40);
	}

	if (LastAddFlag[4] == false)
	{
		m_NotLastApp[4].Render(540, 40);
	}


	//2段目
	if (LastAddFlag[5] == false)
	{
		m_NotLastApp[5].Render(60, 240);
	}

	if (LastAddFlag[6] == false)
	{
		m_NotLastApp[6].Render(180, 240);
	}

	if (LastAddFlag[7] == false)
	{
		m_NotLastApp[7].Render(300, 240);
	}

	if (LastAddFlag[8] == false)
	{
		m_NotLastApp[8].Render(420, 240);
	}

	if (LastAddFlag[9] == false)
	{
		m_NotLastApp[9].Render(540, 240);
	}




	//三段目
	if (LastAddFlag[10] == false)
	{
		m_NotLastApp[10].Render(60, 440);
	}

	if (LastAddFlag[11] == false)
	{
		m_NotLastApp[11].Render(180, 440);
	}

	if (LastAddFlag[12] == false)
	{
		m_NotLastApp[12].Render(300, 440);
	}

	if (LastAddFlag[13] == false)
	{
		m_NotLastApp[13].Render(420, 440);
	}

	if (LastAddFlag[14] == false)
	{
		m_NotLastApp[14].Render(540, 440);
	}

	//内容説明テキスト(最終容姿名)
	const char* MenuString[MenuCnt] =
	{
		"姉御",
		"クラスの人気者",
		"ギャル",
		"応援団長",
		"図書室の長",
		"オタク",
		"インフルエンサー",
		"委員長",
		"高嶺の花",
		"ヤンキー",
		"スーパーレディ",
		"お調子者",
		"文学少女",
		"中二病",
		"神対応",
		"戻る"
	};

	//内容説明テキスト（最終容姿説明）
	const char* ExString[MenuCnt] =
	{
		//姉御の説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//クラスの人気者の説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//ギャルの説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//応援団長
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//図書室の長説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//オタクの説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//インフルエンサーの説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//委員長の説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//高嶺の花の説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//ヤンキーの説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//スーパーレディの説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//お調子者の説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//文学少女説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//中二病の説明
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//神対応
		"容姿の説明をここに入力してく\nださい。容姿の説明をここに入\n力してください。容姿の説明を\nここに入力してください。容姿\nの説明をここに入力してくださ",

		//戻るボタン説明
		"エンターでメニュー画面に戻る\nもうちょいおしゃれな文章を考\nえてくださるとうれしいです！\nよろしくお願いしますね～。"
	};

	//内容説明テキスト（最終容姿説明）
	const char* NoOpenExString[15] =
	{
		//姉御未解放説明
		"コミュ力と想像力を上げると解\n放されるかも！頑張ってあげて\nみよう！",

		//クラスの人気者未解放説明
		"コミュ力と学力を上げると解放\nされるかも！頑張ってあげてみ\nよう！",

		//ギャル未解放説明
		"コミュ力と魅力を上げると解放\nされるかも！頑張ってあげてみ\nよう！",

		//応援団長未解放説明
		"コミュ力と行動力を上げると解\n放されるかも！頑張ってあげて\nみよう！",

		//図書室の長未解放説明
		"想像力と学力を上げると解放さ\nれるかも！頑張ってあげてみよ\nう！",

		//オタク未解放説明
		"想像力と行動力を上げると解放\nされるかも！頑張ってあげてみ\nよう！",

		//インフルエンサー未解放説明
		"想像力と魅力を上げると解放さ\nれるかも！頑張ってあげてみよ\nう！",

		//委員長未解放説明
		"学力と行動力を上げると解放さ\nれるかも！頑張ってあげてみよ\nう！",

		//高嶺の花未解放説明
		"学力と魅力を上げると解放され\nるかも！頑張ってあげてみよう\n！",

		//ヤンキー未解放説明
		"行動力と魅力を上げると解放さ\nれるかも！頑張ってあげてみよ\nう！",

		//スーパーレディ未解放説明
		"魅力をしっかり磨くと解放され\nるかも！頑張ってあげてみよう\n！",


		//お調子者未解放説明
		"行動力をしっかり見せつけると\n解放されるかも！頑張ってあげ\nてみよう！",

		//文学少女未解放説明
		"学力をしっかりあげると解放さ\nれるかも！頑張ってあげてみよ\nう！",

		//中二病未解放説明
		"想像力をすごく豊かにすると解\n放されるかも！頑張ってあげて\nみよう！",

		//神対応未解放説明
		"コミュ力をしっかり磨くと解放\nされるかも！頑張ってあげてみ\nよう！",

	};


	//現在選択矩形表示（黄色になる）
	//線が細いので画像で四角形作ったのを読み込む
	switch (galleryCnt)
	{
	case 0:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);


		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[0])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[0]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[0].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 1:

		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[1])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[1]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[1].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 2:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[2])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[2]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[2].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 3:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[3])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[3]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[3].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 4:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[4])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[4]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[4].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 5:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[5])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[5]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[5].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 6:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[6])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[6]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[6].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 7:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[7])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[7]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[7].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 8:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[8])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[8]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[8].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 9:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[9])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[9]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[9].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 10:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[10])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[10]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[10].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 11:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[11])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[11]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[11].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 12:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[12])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[12]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[12].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 13:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[13])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[13]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[13].Render(766, 50);
			//最終容姿名
			gFont1.RenderString(930, 471, MenuString[galleryCnt]);
			//最終容姿説明
			gFont2.RenderString(766, 520, ExString[galleryCnt]);
		}
		break;

	case 14:
		//選択時囲み枠を表示
		m_SelectTexture.Render(pos[galleryCnt].x, pos[galleryCnt].y);
		//最終容姿名
		gFont1.RenderString(930, 471, MenuString[galleryCnt]);
		//最終容姿説明
		gFont2.RenderString(766, 520, ExString[galleryCnt]);

		//もし最終容姿解放フラグがFalseだった場合
		if (!LastAddFlag[14])
		{
			//最終容姿を表示せず別画像を表示
			m_PickUp.Render(766, 50);
			//未解放時の表記にする
			gFont1.RenderString(930, 471, "未解放");
			gFont2.RenderString(766, 520, NoOpenExString[14]);
		}
		else
		{
			//最終容姿を表示
			m_LastAppPic[14].Render(766, 50);
		}
		break;

	case 15:
		m_SelectTexture_s.Render(60, 650);
		gFont1.RenderString(930, 471, MenuString[galleryCnt]);
		gFont2.RenderString(766, 520, ExString[galleryCnt]);

		m_PickUp.Render(766, 50);

		break;
	}



}

void CGallery::RenderDebug(void)
{
	//矩形数確認用
	CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "galleryCnt:%d", galleryCnt);

	CGraphicsUtilities::RenderString(10, 10, "ギャラリー画面");
	CGraphicsUtilities::RenderString(10, 40, "F1キーでタイトル画面へ遷移");
	CGraphicsUtilities::RenderString(10, 70, "Enterキーでモードセレクト画面へ遷移");

	//フラグ切り換え
	//後日デバックに書き写し
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		if (LastAddFlag[0] == false)
		{
			LastAddFlag[0] = true;
		}
		else
		{
			LastAddFlag[0] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		if (LastAddFlag[1] == false)
		{
			LastAddFlag[1] = true;
		}
		else
		{
			LastAddFlag[1] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_3))
	{
		if (LastAddFlag[2] == false)
		{
			LastAddFlag[2] = true;
		}
		else
		{
			LastAddFlag[2] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_4))
	{
		if (LastAddFlag[3] == false)
		{
			LastAddFlag[3] = true;
		}
		else
		{
			LastAddFlag[3] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_5))
	{
		if (LastAddFlag[4] == false)
		{
			LastAddFlag[4] = true;
		}
		else
		{
			LastAddFlag[4] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_6))
	{
		if (LastAddFlag[5] == false)
		{
			LastAddFlag[5] = true;
		}
		else
		{
			LastAddFlag[5] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_7))
	{
		if (LastAddFlag[6] == false)
		{
			LastAddFlag[6] = true;
		}
		else
		{
			LastAddFlag[6] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_8))
	{
		if (LastAddFlag[7] == false)
		{
			LastAddFlag[7] = true;
		}
		else
		{
			LastAddFlag[7] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_9))
	{
		if (LastAddFlag[8] == false)
		{
			LastAddFlag[8] = true;
		}
		else
		{
			LastAddFlag[8] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_0))
	{
		if (LastAddFlag[9] == false)
		{
			LastAddFlag[9] = true;
		}
		else
		{
			LastAddFlag[9] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_Q))
	{
		if (LastAddFlag[10] == false)
		{
			LastAddFlag[10] = true;
		}
		else
		{
			LastAddFlag[10] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_W))
	{
		if (LastAddFlag[11] == false)
		{
			LastAddFlag[11] = true;
		}
		else
		{
			LastAddFlag[11] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_E))
	{
		if (LastAddFlag[12] == false)
		{
			LastAddFlag[12] = true;
		}
		else
		{
			LastAddFlag[12] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_R))
	{
		if (LastAddFlag[13] == false)
		{
			LastAddFlag[13] = true;
		}
		else
		{
			LastAddFlag[13] = false;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_T))
	{
		if (LastAddFlag[14] == false)
		{
			LastAddFlag[14] = true;
		}
		else
		{
			LastAddFlag[14] = false;
		}
	}
}


//リリース
void CGallery::Release(void)
{
	m_BackTexture.Release();
	m_SelectTexture.Release();
	m_SelectTexture_s.Release();
	m_BackButton.Release();
	gFont1.Release();
	gFont2.Release();

	m_LastApp.Release();

	for (int i = 0; i < 15; i++)
	{
		m_NotLastApp[i].Release();
	}

	for (int i = 0; i < 15; i++)
	{
		m_LastAppPic[i].Release();
	}

	m_PickUp.Release();
	m_Text.Release();

	g_MusicManager->BGMStop(BGMT_GALLERY);

}


