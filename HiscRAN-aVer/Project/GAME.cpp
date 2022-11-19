#pragma once
#include "GAME.h"
#include "Define.h"
#include "GameApp.h"
#include "Player.h"
#include "Stage.h"
#include "Ground.h"
#include "DetailPoint.h"
#include "Bar.h"
#include "Obstacle.h"
#include "MusicManager.h"
#include "EffectManager.h"
#include "StageA_DP.h"
#include "StageA_Bar.h"
#include "StageA_Obstacle.h"


//�ύX����V�[���i�O���Q�ƁB���Ԃ�GameApp.cpp�j
extern int			gChangeScene;

//�G�t�F�N�g�}�l�[�W���[
CEffectManager g_EffectManeger;

//�v���C���[�N���X
CPlayer g_Player;

CMusicManager g_MusicManager;

//�v���C���[�X�L���N���X
//CPlayerSkill g_PlayerSkill;

//�X�e�[�W�N���X
CStage g_Stage;

//�f�o�b�O�t���O
bool Debuggingflg = true;

bool Clearflag = false;
bool GameOverflag = false;


CGAME::CGAME() {}

CGAME::~CGAME()
{

}

void CGAME::Load(void)
{
	g_Player.Load();
	g_Stage.Load();
	g_MusicManager.Load();
	g_EffectManeger.Load();
}

//������
void CGAME::Initialize(void)
{

	gMenu.Create(gMenuItemCount);

	//�v���C���[������
	g_Player.Initialize();
	g_Player.SetMusicManager(&g_MusicManager);
	//�v���C���[�X�L��������
	//g_PlayerSkill.Initialize();

	//�X�e�[�W������
	g_Stage.Initialize(s_stageAdp,s_stageAbar, s_stageAOB);

	g_MusicManager.Initialize();
	g_EffectManeger.Initialize();

	g_Stage.SetEffectManager(&g_EffectManeger);
}

//�X�V
void CGAME::Update(void)
{

	//�Q�[���J�n�؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN)&&!g_Stage.GetClear()&&!Menuflag)
	{
		g_Stage.GameStopPlayChange();
	}

	//�ꎞ�I�Ȓǉ��ł�
	//F2��Title��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		gChangeScene = SCENENO_TITLE;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	else if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_F3))
	{
		gChangeScene = SCENENO_SELECTMODE;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//P�L�[�Ńt���X�N���[���ɐ؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_P)) {
		g_pGraphics->ChangeScreenMode();
	}

	//�ꎞ�I�Ȓǉ��ł�
	//�f�o�b�O�\����\���؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_9)) {
		if (Debuggingflg) {
			Debuggingflg = false;
		}
		else
		{
			Debuggingflg = true;
		}
	}

	//C�ŃQ�[���N���A��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		gChangeScene = SCENENO_GAMECLEAR;
	}

	//V�ŃQ�[���I�[�o�[���
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		gChangeScene = SCENENO_GAMEOVER;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//���X�^�[�g
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//������
		g_Player.Initialize();

		g_Stage.Initialize(s_stageAdp, s_stageAbar, s_stageAOB);

	}

	//���j���[�̍X�V
	if (gMenu.IsShow())
	{
		gMenu.Update();
		if (gMenu.IsEnter())
		{
			if (gMenu.GetSelect() == 0)
			{
				gChangeScene = SCENENO_SELECTMODE;
			}
			gMenu.Hide();
		}
	}
	//�G�X�P�[�v�L�[�ŏI�����j���[��\��
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//�v���C���ł���Β�~
		if (g_Stage.GetGameStopPlay())
			g_Stage.GameStopPlayChange();

		Menuflag = true;
		gMenu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else
	{
		Menuflag = false;
	}


	//�X�g�b�v���̓Q�[�����������s���Ȃ�
	if (!g_Stage.GetGameStopPlay()) {

		return;
	}


	//�X�e�[�W�X�V
	g_Stage.Update(g_Player.GetRect(),g_Player.SuckingRect(), g_Player.CircleX(), g_Player.CircleY());

	//�v���C���[�X�V
	g_Player.Update();
	g_Player.UpdateSkillShock();


	//�X���C�f�B���O����
	//�n�ʂ�����ɏ���Ă���ԉ����L�[�X���C�f�B���O
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}
		//����Ƃ̔���
		if (g_Player.CollosopnBar(g_Stage.b_bar[i].GetRect(g_Stage.b_bar[i].Gettype()))) {

			//�X���C�f�B���O����
			g_Player.UPdateSliding();

		}
	}
	//�n�ʂƂ̔���
	if (g_Player.CollosopnGround(g_Stage.g_ground.GetRect())) {

		//�X���C�f�B���O����
		g_Player.UPdateSliding();

	}


	//�X�e�[�W�N���A���J�n��Ԃ̎����s
	if (g_Stage.GetClear()&& g_Stage.GetGameStopPlay()) {

		g_Stage.GameStopPlayChange();

	}

	//�n�ʂƂ̓����蔻��
	if (g_Player.CollosopnGround(g_Stage.g_ground.GetRect())) {

		g_Player.UPdateCollisionGround(g_Stage.g_ground.GetPosY());
	}

	//����Ƃ̓����蔻��
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnBar(g_Stage.b_bar[i].GetRect(g_Stage.b_bar[i].Gettype()))) {

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//��Q���Ƃ̓����蔻��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		if (g_Player.CollosopnOB(g_Stage.ob_array[i].GetRect(g_Stage.ob_array[i].GetType())))
		{
 			g_Player.UPdateCollisionOB();
		}
		//��Q������̃_���[�W���󂯂Ă��Ȃ��ꍇ������̑��ꔻ��
		else if(g_Player.CollosopnBar(g_Stage.ob_array[i].GetTopBarRect(g_Stage.ob_array[i].GetType())))
		{
			g_Player.UPdateCollisionBra(g_Stage.ob_array[i].GetY(g_Stage.ob_array[i].GetType()));
		}
	}

	g_EffectManeger.Update();

	//�ꎞ�I�Ȓǉ��ł�
	//F2��Title��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		gChangeScene = SCENENO_TITLE;
	}

}

void CGAME::Render(void)
{


	//�X�e�[�W�`��
	g_Stage.Render();

	//�v���C���[�`��
	g_Player.Render();

	//���j���[�̕`��
	gMenu.Render(2);

	//CGraphicsUtilities::RenderString(10, 10, "�Q�[�����");
	//CGraphicsUtilities::RenderString(10, 40, "F1�L�[�Ń^�C�g����ʂ֑J��");
	//CGraphicsUtilities::RenderString(10, 70, "Enter�L�[�Ń��[�h�Z���N�g��ʂ֑J��");


	g_EffectManeger.Render();
	//�v���C���[�X�L���`��
	//g_PlayerSkill.Render();

	//�f�o�b�O�`��
	if (Debuggingflg) {
		g_Stage.RenderDebugging();
		g_Player.RenderDebugging();
		//g_PlayerSkill.RenderDebug();

	}

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	g_EffectManeger.Release();

	gMenu.Release();
	g_MusicManager.Release();

}

void CGAME::RenderDebug(void)
{

}
	
