#pragma once
#include "SceneBase.h"

////////////////////////////////////////////////////
//�@�t�F�[�h�C���ƃt�F�[�h�A�E�g�̃v���O�����ł��@//
//								   �@�@         �@//
//�@�쐬�ҁF�c����,���c���� �@�@�@�@�@�@          //
//								   �@�@�@         //
//�@���t�@�N�^�����O�����l�F�c���� �@�@�@         //
//								   �@�@�@         //
//�@�ŏI�X�V�F2023/01/17		   �@�@�@         //
////////////////////////////////////////////////////


//�t�F�[�h�C������
float CSceneBase::FadeIn(float A, bool b, float s)
{
	if (A >= 0) {

		A -= s;
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
float CSceneBase::FadeOut(float A, bool b, float s)
{
	if (A <= 255) {

		A += s;
		if (A > 255) {
			A = 255;
			if (b) {
				b_Fadein = FADE_NEXT;
			}
		}
	}
	return A;
}