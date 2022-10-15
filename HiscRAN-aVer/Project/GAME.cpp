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

	//�Q�[���J�n�؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN)&&!g_Stage.GetClear())
	{
		g_Player.GameStopPlayChange();
	}

	//�X�e�[�W�X�V
	g_Stage.Update(g_Player.GetOver(),g_Player.GetRect());


	//�v���C���[�X�V
	g_Player.Update();

	//�X�e�[�W�N���A���J�n��Ԃ̎����s
	if (g_Stage.GetClear()&&g_Player.GetGameStopPlay()) {

		g_Player.GameStopPlayChange();

	}

	//�n�ʂƂ̓����蔻��
	if (g_Player.CollosopnGround(g_Stage.g_ground.GetPosY())) {

		g_Player.UPdateCollisionGround(g_Stage.g_ground.GetPosY());
	}

	//����Ƃ̓����蔻��
	for (int i = 0; i < BAR_MAX; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnBar(g_Stage.b_bar[i].GetRect())) {

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//��Q���Ƃ̓����蔻��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnOB(g_Stage.ob_array[i].GetRect())) {

			g_Player.UPdateCollisionOB();
		}
	}
	
	//F2��Title��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		gChangeScene = SCENENO_TITLE;
	}
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	else if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}

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
