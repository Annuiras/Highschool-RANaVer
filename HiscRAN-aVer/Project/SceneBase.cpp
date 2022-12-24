#pragma once
#include "SceneBase.h"

//�t�F�[�h�C������
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

//�t�F�[�h�C������
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

//�t�F�[�h�A�E�g����
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

//�t�F�[�h�A�E�g����
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

