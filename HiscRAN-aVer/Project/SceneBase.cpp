#pragma once
#include "SceneBase.h"

//フェードイン処理
float CSceneBase::FadeIn(float A)
{
	if (A >= 0) {

		A -= FADE_OUT_SPEED;
		if (A < 0) {
			A = 0;
			b_Fadein = FADE_NOT;
		}
	}
	return A;
}

//フェードアウト処理
float CSceneBase::FadeOut(float A)
{
	if (A <= 255) {

		A += FADE_OUT_SPEED;
		if (A > 255) {
			A = 255;
			b_Fadein = FADE_NEXT;
		}
	}
	return A;
}
