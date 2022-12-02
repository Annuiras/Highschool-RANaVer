#pragma once
#include "GAME.h"
#include "Stage_DP.h"
#include "Stage_Bar.h"
#include "Stage_Obstacle.h"



CGAME::CGAME() {}

CGAME::~CGAME()
{

}

//�f�ޓǂݍ���
void CGAME::Load(void)
{

	//g_MusicManager.Load();
	//g_EffectManeger.Load();
	g_Player.Load();
	g_Stage.Load();

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Game");

	//�J�E���g�_�E���摜�̓ǂݍ���
	gStartThreeTexture.Load("CountdownThree.png");
	gStartTwoTexture.Load("CountdownTwo.png");
	gStartOneTexture.Load("CountdownOne.png");
	gStartGoTexture.Load("CountdownGo.png");

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

}

//������
//�����F�Q�[���i���Ǘ��N���X
void CGAME::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	//�f�ޓǂݍ���
	Load();

	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

	//���j���[
	gMenu.Create(gMenuItemCount);

	//�}�l�[�W���[������
 //	g_MusicManager.Initialize(m_GameProgMamt->GetSEVolume(),m_GameProgMamt->GetBGMVolume());
	//g_EffectManeger.Initialize();

	//�v���C���[������
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//�X�e�[�W������
	g_Stage.Initialize(s_stageAdp,s_stageAbar, s_stageAOB);
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);
}

//�X�V
void CGAME::Update(void)
{

	//�Q�[���J�n�؂�ւ�
	//ToDo�@�J�n���ɃJ�E���g�_�E���J�n
	if (g_pInput->IsKeyPush(MOFKEY_RETURN) && !g_Stage.GetClear())
	{
		gStartTime = timeGetTime();
	}
	if (timeGetTime() - gStartTime > 1000 && gStartCount < 5) {
		gStartTime = timeGetTime();
		gStartCount++;
		if (gStartCount == 4) {
			g_Stage.GameStopPlayChange();
		}
	}
	//�ꎞ�I�Ȓǉ��ł�
	//F2��Title��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_TITLE;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	else if (Menuflag == false && g_pInput->IsKeyPush(MOFKEY_F3))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//P�L�[�Ńt���X�N���[���ɐ؂�ւ�
	if (g_pInput->IsKeyPush(MOFKEY_P)) {
		g_pGraphics->ChangeScreenMode();
	}

	//C�ŃQ�[���N���A��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMECLEAR;
	}

	//V�ŃQ�[���I�[�o�[���
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMEOVER;
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
				m_bEnd = true;
				m_NextScene = SCENENO_SELECTMODE;

				//gChangeScene = SCENENO_SELECTMODE;
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
	g_Stage.Update(g_Player.GetRect());

	//�v���C���[�X�V
	g_Player.Update();

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

		//����
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

	//�G�t�F�N�g�̍X�V
	g_EffectManeger->Update(g_Player.GetRect());


}

void CGAME::Render(void)
{

	//�X�e�[�W�`��
	g_Stage.Render();

	//�v���C���[�`��
	g_Player.Render();

	//���j���[�̕`��
	gMenu.Render(2);

	//ToDo�@�Q�[���J�n���̃J�E���g�_�E���̕\��
	if (gStartCount == 1) {
		gStartThreeTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartThreeTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartThreeTexture.GetHeight() / 2);
	}
	else if (gStartCount == 2) {
		gStartTwoTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartTwoTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartTwoTexture.GetHeight() / 2);
	}
	else if (gStartCount == 3) {
		gStartOneTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartOneTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartOneTexture.GetHeight() / 2);
	}
	else if (gStartCount == 4) {
		gStartGoTexture.Render(g_pGraphics->GetTargetWidth() / 2 - gStartGoTexture.GetWidth() / 2,
			g_pGraphics->GetTargetHeight() / 2 - gStartGoTexture.GetHeight() / 2);
	}

	//�G�t�F�N�g�̕`��
	g_EffectManeger->Render();

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	gMenu.Release();

	//ToDo	�J�E���g�_�E���摜�̊J��
	gStartThreeTexture.Release();
	gStartTwoTexture.Release();
	gStartOneTexture.Release();
	gStartGoTexture.Release();

}

void CGAME::RenderDebug(void)
{
	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();
}
	
