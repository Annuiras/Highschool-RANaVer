#pragma once
#include "SceneBase.h"

//�t�F�[�h�C������
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

//�t�F�[�h�A�E�g����
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
