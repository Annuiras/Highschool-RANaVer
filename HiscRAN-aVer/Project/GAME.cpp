#pragma once
#include "GAME.h"
#include "GameApp.h"
#include "Player.h"
#include "Stage.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
#include "StageA_DP.h"
#include "StageA_Bar.h"
#include "StageA_Obstacle.h"


//�ύX����V�[���i�O���Q�ƁB���Ԃ�GameApp.cpp�j
extern int			gChangeScene;

//�v���C���[�N���X
CPlayer g_Player;

//�X�e�[�W�N���X
CStage g_Stage;

GAME::GAME() {}

GAME::~GAME()
{

}

void GAME::Load(void)
{
	g_Player.Load();
	g_Stage.Load();
}

//������
void GAME::Initialize(void)
{
	g_Player.Initialize();

	g_Stage.Initialize(s_stageAdp, s_stageAdpcount, s_stageAbar, s_stageAbarcount, s_stageAob, s_stageAobcount);
}

//�X�V
void GAME::Update(void)
{

	g_Stage.Update(g_Player.GetOver(),g_Player.GetRect());

	g_Player.Update();

	//�n�ʂƂ̓����蔻��
	if (g_Player.CollosopnGround(g_Stage.g_ground.GetPosY())) {

		g_Player.UPdateCollisionGround(g_Stage.g_ground.GetPosY());
	}

	//����̍���
	for (int i = 0; i < BAR_MAX; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnBar(g_Stage.b_bar[i].GetRect())) {

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//��Q��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnOB(g_Stage.ob_array[i].GetRect())) {

			g_Player.UPdateCollisionOB();
		}
	}
	
	//�ꎞ�I�ȃR�����g�A�E�g�ł�
	////F1��Title��ʂ�
	//if (g_pInput->IsKeyPush(MOFKEY_F1))
	//{
	//	gChangeScene = SCENENO_TITLE;
	//}
	////�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	//else if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	//{
	//	gChangeScene = SCENENO_SELECTMODE;
	//}

	//�ꎞ�I�Ȓǉ��ł�
	//P�L�[�Ńt���X�N���[���ɐ؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_P)) {
		g_pGraphics->ChangeScreenMode();
	}

	//�ꎞ�I�Ȓǉ��ł�
	//���X�^�[�g
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//������
		g_Player.Initialize();

		g_Stage.Initialize(s_stageAdp, s_stageAdpcount, s_stageAbar, s_stageAbarcount, s_stageAob, s_stageAobcount);

	}

}

void GAME::Render(void)
{

	g_Stage.Render();


	//CGraphicsUtilities::RenderString(10, 10, "�Q�[�����");
	//CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	//CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");

	g_Player.Render();

	
	g_Stage.DebuggingRender();
	g_Player.DebuggingRender();
}


void GAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();
}
