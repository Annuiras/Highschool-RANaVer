#pragma once
#include "GAME.h"
#include "Stage_DP.h"
#include "Stage_Bar.h"
#include "Stage_Obstacle.h"
#include "Stage_Enemy.h"



bool CGAME::Collosopn(CRectangle r1, CRectangle r2)
{
	if (r1.CollisionRect(r2)) {
		return true;
	}
	return false;
}

CGAME::CGAME() {}

CGAME::~CGAME()
{

}

//�f�ޓǂݍ���
void CGAME::Load(void)
{
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


	//�v���C���[������
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//�X�e�[�W������
	g_Stage.Initialize(s_stageAdp,s_stageAbar, s_stageAOB, s_stageAEnemy);
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);

	//�J�E���g�_�E���p�J�E���^������
	gStartCount = 0;

	//ToDo	�Q�[���I�[�o���̃t�F�[�h�C���t�F�[�h�A�E�g�p
	m_BlackAlpha = 0;
	m_WhiteAlpha = 0;

	//�f�o�b�O�p
	_GameClear = false;
	_GameOver = false;
}

//�X�V
void CGAME::Update(void)
{

	//�Q�[���J�n�؂�ւ�
	//�J�n���ɃJ�E���g�_�E���J�n
	if (g_pInput->IsKeyPush(MOFKEY_RETURN) && !g_Stage.GetClear())
	{
		gStartTime = timeGetTime();
	}

	//�J�E���g�_�E������
	if (gStartCount < 5&&timeGetTime() - gStartTime > 1000  ) {
		gStartTime = timeGetTime();
		gStartCount++;
		if (gStartCount == 4) {
			g_Stage.GameStopPlayChange();
		}
	}

	//�ꎞ�I�Ȓǉ��ł�
	//�Q�[���ꎞ��~
	if (g_pInput->IsKeyPush(MOFKEY_RSHIFT)) {
		g_Stage.GameStopPlayChange();

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

	//C�ŃQ�[���N���A��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		_GameClear = true;
	}

	//V�ŃQ�[���I�[�o�[���
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		_GameOver = true;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//���X�^�[�g
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//������
		g_Player.Initialize();

		g_Stage.Initialize(s_stageAdp, s_stageAbar, s_stageAOB, s_stageAEnemy);

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


	//ToDo	�Q�[���I�[�o�[
	if (g_Player.GetOver()||_GameOver) {
		m_BlackAlpha += FADE_OUT_SPEED;
		if (m_BlackAlpha >= 255) {
			m_bEnd = true;
			m_NextScene = SCENENO_GAMEOVER;
		}
	}

	//�X�g�b�v��,�Q�[���I�[�o�[���̓Q�[�����������s���Ȃ�
	if (!g_Stage.GetGameStopPlay()||g_Player.GetOver()||_GameOver) {
		return;
	}

	//todo �N���A���̏���
	if (g_Stage.GetClear()|| _GameClear)
	{
		m_WhiteAlpha += 1;//���]

		//�N���A���̃L�����N�^�[����
		g_Player.UpdateClear();

		if (m_WhiteAlpha >= 255)
		{
			//��ʐ؂�ւ�
			m_bEnd = true;
			m_NextScene = SCENENO_GAMECLEAR;
		}
	}

	if (_GameClear) {

		return;
	}

	//�v���C���[�X�V
	g_Player.Update();

	//�X�e�[�W�X�V
	g_Stage.Update(g_Player.GetRect());

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

		//�v���C���[�Ɣ���
		if (g_Player.CollosopnOB(g_Stage.ob_array[i].GetRect(g_Stage.ob_array[i].GetType())))
		{
 			g_Player.UPdateCollisionOB();
		}
		//��Q������̃_���[�W���󂯂Ă��Ȃ��ꍇ������̑��ꔻ��
		else if(g_Player.CollosopnBar(g_Stage.ob_array[i].GetTopBarRect(g_Stage.ob_array[i].GetType())))
		{
			g_Player.UPdateCollisionBra(g_Stage.ob_array[i].GetY(g_Stage.ob_array[i].GetType()));
		}

		//�G
		for (int e = 0; e < ENEMY_VOLUME; e++)
		{
			if (!g_Stage.ene_array[e].Getshow())
				continue;

			if (Collosopn(g_Stage.ene_array[e].GetRect(), (g_Stage.ob_array[i].GetTopBarRect(g_Stage.ob_array[i].GetType())))) {
				g_Stage.ene_array[e].SetPosY(g_Stage.ob_array[i].GetY(g_Stage.ob_array[i].GetType()));
			}
		}
	}

	//�G�Ƃ̓����蔻��
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		if (!g_Stage.ene_array[i].Getshow()) {
			continue;
		}

		//�v���C���[�ƓG�̓����蔻��
		if (g_Player.CollosopnEnemy(g_Stage.ene_array[i].GetRect()))
		{
			g_Player.UPdateCollisionOB();
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

	//�Q�[���J�n���̃J�E���g�_�E���̕\��
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

	CGraphicsUtilities::RenderString(0, 150,MOF_XRGB(80, 80, 80), "FPS�F%d", CUtilities::GetFPS());

	//�G�t�F�N�g�̕`��
	g_EffectManeger->Render();

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteAlpha, 255, 255, 255));

	//�t�F�[�h�A�E�g�Ó]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),MOF_ARGB(m_BlackAlpha,0,0,0));

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	gMenu.Release();

	//�J�E���g�_�E���摜�̊J��
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
	
