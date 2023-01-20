#pragma once

//エフェクト定数

//管理エフェクトの数
#define		EFFECT_MGMT_COUNT 5

//エフェクト種類列挙
enum tag_EFFECTTYPE {

	EFC_GET_SCHOLASTIC,		//DP学力取得
	EFC_GET_ACTION,			//DP行動力取得
	EFC_GET_IMAGINATION,	//DP想像力取得
	EFC_GET_COMMUNICATION,	//DPコミュ力取得
	EFC_GET_CHARM,			//DP魅力取得

	EFC_GET_SCHOLASTIC_AROOW,		//DP学力取得↑矢印
	EFC_GET_ACTION_AROOW,			//DP行動力取得↑矢印
	EFC_GET_IMAGINATION_AROOW,		//DP想像力取得↑矢印
	EFC_GET_COMMUNICATION_AROOW,	//DPコミュ力取得↑矢印
	EFC_GET_CHARM_AROOW,			//DP魅力取得↑矢印

	EFC_DAMAGE_HIT,			//ダメージエフェクト

	EFC_TYPE_COUNT,
};
