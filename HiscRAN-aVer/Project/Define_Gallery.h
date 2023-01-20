#pragma once

///////////////////////////////////////////////////////////
//　ギャラリー画面で使用する定数を宣言している場所です　 //
//								   　　　　　　　　　　　//
//　作成者：田中環　  　　　　　　　　　  　　　　　 　　//
//								   　　　 　　　　　 　　//
//　リファクタリングした人：田中環 　　　 　　　　　 　　//
//								   　　　　　　　　  　　//
//　最終更新：2023/01/20		   　　　 　　　　　 　　//
///////////////////////////////////////////////////////////


//最終容姿番号
enum tag_LAST_TEXTURE_TYPE
{
	LT_ANEGO,		//姉御
	LT_NINKIMONO,	//クラスの人気者
	LT_GYARU,		//ギャル
	LT_OUEN,		//応援団長
	LT_TOSYO,		//図書室の長
	LT_OTAKU,		//オタク
	LT_INFLUENCER,	//インフルエンサー
	LT_IINTYOU,		//委員長
	LT_TAKANE,		//高嶺の花
	LT_YABKI,		//ヤンキー
	LT_SUPERLADY,	//スーパーレディ
	LT_OTYOUSI,		//お調子者
	LT_BUNGAKU,		//文学少女
	LT_TYUNI,		//厨二病
	LT_KAMITAIOU,	//神対応
};

//最終容姿背景種類
enum tag_BAKLAST_TYPE {

	//ノーマル
	BL_NORMAL,

	//スーパーレディ
	BL_SUPERLADY,

	//お調子者
	BL_OTYOUSI,

	//文学少女
	BL_BUNGAKU,

	//中二病
	BL_TYUNI,

	//神対応
	BL_KAMITAIOU,

	//総数
	BL_COUNT
};
