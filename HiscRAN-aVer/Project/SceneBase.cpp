#pragma once
#include "SceneBase.h"

//フェードイン処理
float CSceneBase::FadeIn(float A, float speed)
{
	if (A >= 0) {

		A -= speed;
		if (A < 0) {
			A = 0;
			b_Fadein = FADE_NOT;
		}
	}
	return A;
}

//フェードイン処理
float CSceneBase::FadeIn(float A, bool b, float speed)
{
	if (A >= 0) {

		A -= speed;
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
float CSceneBase::FadeOut(float A, float speed)
{
	if (A <= 255) {

		A += speed;
		if (A > 255) {
			A = 255;
			b_Fadein = FADE_NEXT;		
		}
	}
	return A;
}

//フェードアウト処理
float CSceneBase::FadeOut(float A, bool b, float speed)
{
	if (A <= 255) {

		A += speed;
		if (A > 255) {
			A = 255;
			if (b) {
				b_Fadein = FADE_NEXT;
			}
		}
	}
	return A;
}

