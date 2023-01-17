#pragma once
#include "SceneBase.h"

////////////////////////////////////////////////////
//　フェードインとフェードアウトのプログラムです　//
//								   　　         　//
//　作成者：田中環  　　　　　　　　　　          //
//								   　　　         //
//　リファクタリングした人：田中環 　　　         //
//								   　　　         //
//　最終更新：2023/01/17		   　　　         //
////////////////////////////////////////////////////

//フェードイン処理
float CSceneBase::FadeIn(float A, bool b)
{
	if (A >= 0) {

		A -= FADE_OUT_SPEED;
		if (A < 0) {
			A = 0;
			if (b) {
				b_Fadein = FADE_NOT;
			}
		}
	}
	return A;
}

//フェードアウト処理
float CSceneBase::FadeOut(float A, bool b)
{
	if (A <= 255) {

		A += FADE_OUT_SPEED;
		if (A > 255) {
			A = 255;
			if (b) {
				b_Fadein = FADE_NEXT;
			}
		}
	}
	return A;
}


