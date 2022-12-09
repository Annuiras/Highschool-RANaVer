#pragma once
#include "GAME.h"



//DP�Ɠ��������ꍇ
//dpt->DP�̎��
void CGAME::UPdeteCollisionDP(int dpt) {

	g_MusicManager->SEStart(SE_T_DP_HIT);

	switch (dpt)
	{
		//�w��
	case DP_SCHOLASTIC:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		m_Scholastic += 1;
		if (m_Scholastic > 100) {
			m_Scholastic = 100;
		}
		break;

		//�s����
	case DP_ACTION:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		m_Action += 1;
		if (m_Action > 100) {
			m_Action = 100;
		}
		break;

		//�z����
	case DP_IMAGINATION:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		m_Imagination += 1;
		if (m_Imagination > 100) {
			m_Imagination = 100;
		}
		break;

		//�R�~����
	case DP_COMMUNICATION:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		m_Communication += 1;
		if (m_Communication > 100) {
			m_Communication = 100;
		}
		break;

		//����
	case DP_CHARM:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		m_Charm += 1;
		if (m_Charm > 100) {
			m_Charm = 100;
		}
		break;

		//SP�A�C�e���擾���A�J�E���g�X�^�[�g
	case DP_SP_ITEM:
		g_Stage.SetSPSitua(tag_StageSituation::STAGE_SP_START);

		//SP���̃X�e�[�W�ɕύX
		g_Stage.SPInitialize();
		break;

	default:
		m_Scholastic = -100;
		break;
	}
}

CGAME::CGAME():
	gMenu(),
	gMenuItemCount(),
	m_StartCount(),
	m_BlackAlpha(),
	m_WhiteAlpha(),
	_GameOver(),
	_GameClear(),
	gStartTime(),
	m_Scholastic(),
	m_Action(),
	m_Imagination(),
	m_Communication(),
	m_Charm()
{}

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
	gStartThreeTexture.Load("�n�C�X�N�@�J�E���g�_�E�����S�����@�R.png");
	gStartTwoTexture.Load("�n�C�X�N�@�J�E���g�_�E�����S�����@�Q.png");
	gStartOneTexture.Load("�n�C�X�N�@�J�E���g�_�E�����S�����@�P.png");
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
	g_Stage.Initialize();
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);

	//�J�E���g�_�E���p�J�E���^������
	m_StartCount = 0;

	//�Q�[���I�[�o���̃t�F�[�h�C���t�F�[�h�A�E�g�p
	m_BlackAlpha = 0;
	m_WhiteAlpha = 0;

	//�f�o�b�O�p
	_GameClear = false;
	_GameOver = false;

	//�X�e�[�W���Ŏ擾����DP�̐�������
	m_Scholastic	= 0;	//�w��
	m_Action		= 0;	//�s����
	m_Imagination	= 0;	//�z����
	m_Communication = 0;	//�R�~����
	m_Charm			= 0;	//����

	m_StartScale = 0.0f;

	//BGM�J�n
	g_MusicManager->BGMStart(BGMT_STAGE);

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
	if (m_StartCount < 5&&timeGetTime() - gStartTime > 1000) {
		gStartTime = timeGetTime();
		m_StartCount++;

		//�Y�[���C�����Z�b�g
		m_StartScale = 0.0f;

		if (m_StartCount == 4) {
			g_Stage.GameStopPlayChange();
		}
	}

	//�Y�[���C�����l�X�V�@1.0f�ő�摜�T�C�Y�@0.0f�ŏ��摜�T�C�Y
	if (m_StartCount < 5) {
		m_StartScale += 0.08f;
		if (m_StartScale >= 1.0f) {
			m_StartScale = 1.0f;
		}
	}

	//�ꎞ�I�Ȓǉ��ł�
	//�Q�[���ꎞ��~
	if (g_pInput->IsKeyPush(MOFKEY_0)) {
		g_Stage.GameStopPlayChange();

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

		g_Stage.Initialize();

	}

	//���j���[�̍X�V
	if (gMenu.IsShow())
	{
		//�J�E���g�_�E�����~���邽��
		gStartTime = timeGetTime();

		gMenu.Update();
		if (gMenu.IsEnter())
		{
			//��߂�
			if (gMenu.GetSelect() == 0)
			{
				//���[�h�Z���N�g��
				m_bEnd = true;
				m_NextScene = SCENENO_SELECTMODE;
			}
			//���j���[���\��
			gMenu.Hide();
		}
	}
	//�G�X�P�[�v�L�[�ŏI�����j���[��\��
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//�v���C���ł���Β�~
		if (g_Stage.GetGameStopPlay())
			g_Stage.GameStopPlayChange();

		gMenu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}


	//�Q�[���I�[�o�[���̏ꍇ�t�F�[�h�A�E�g
	if (g_Player.GetOver()||_GameOver) {

		//�t�F�[�h�A�E�g
		m_BlackAlpha += FADE_OUT_SPEED;

		if (m_BlackAlpha >= 255) {
			//SE�����ׂĒ�~
			g_MusicManager->SEALLStop();

			//SE�Đ�
			g_MusicManager->SEStart(SE_T_GAMEOVER);

			//�Q�[���I�[�o�[��ʂ�
			m_bEnd = true;
			m_NextScene = SCENENO_GAMEOVER;
		}
	}

	//�X�g�b�v��,�Q�[���I�[�o�[���͈ȉ��̏��������s���Ȃ�
	if (!g_Stage.GetGameStopPlay()||g_Player.GetOver()||_GameOver) {
		return;
	}

	//�N���A���̏���
	if (g_Stage.GetClear()|| _GameClear)
	{
		m_WhiteAlpha += 1;//���]

		//�N���A���̃L�����N�^�[����
		g_Player.UpdateClear();

		if (m_WhiteAlpha >= 255)
		{
			//SE�����ׂĒ�~
			g_MusicManager->SEALLStop();

			//��ʐ؂�ւ�
			m_bEnd = true;
			m_NextScene = SCENENO_GAMECLEAR;
		}
	}

	//�N���A���͈ȉ��̏��������Ȃ�
	if (g_Stage.GetClear()||_GameClear) {
		return;
	}

	//�v���C���[�X�V
	g_Player.Update();

	//�X�e�[�W�X�V
	g_Stage.Update(g_Player.GetRect());	

	//����Ƃ̓����蔻��
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.GetRect().CollisionRect((g_Stage.b_bar[i].GetRect()))){

			g_Player.UPdateCollisionBra(g_Stage.b_bar[i].GetY());
		}

	}

	//��Q���Ƃ̓����蔻��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		//��\���̂��͔̂��肵�Ȃ�
		if (!g_Stage.ob_array[i].Getshow()) {
			continue;
		}

		//�v���C���[�Ɣ���
		if (g_Stage.ob_array[i].GetRect().CollisionRect(g_Player.GetRect()))
		{
 			g_Player.UPdateCollisionOB();
		}
		//��Q������̃_���[�W���󂯂Ă��Ȃ��ꍇ������̑��ꔻ��
		else if(g_Player.GetLegsRect().CollisionRect(g_Stage.ob_array[i].GetTopBarRect()))
		{
			g_Player.UPdateCollisionBra(g_Stage.ob_array[i].GetY());
		}

		//�G
		for (int e = 0; e < ENEMY_VOLUME; e++)
		{
			if (!g_Stage.ene_array[e].Getshow())
				continue;

			if (g_Stage.ene_array[e].GetRect().CollisionRect(g_Stage.ob_array[i].GetTopBarRect())) {
				g_Stage.ene_array[e].SetPosY(g_Stage.ob_array[i].GetY());
			}
		}
	}

	//�G�Ƃ̓����蔻��
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		//��\���̂��͔̂��肵�Ȃ�
		if (!g_Stage.ene_array[i].Getshow()) {
			continue;
		}
		//�v���C���[�ƓG�̓����蔻��
		if (g_Player.GetRect().CollisionRect(g_Stage.ene_array[i].GetRect()))
		{
			g_Player.UPdateCollisionOB();
		}
	}

	//DP�Ƃ̓����蔻��
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//��\���̏ꍇ�͔��肵�Ȃ�
		if (!g_Stage.dp_array[i].Getshow()) {
			continue;
		}

		if (g_Player.GetRect().CollisionRect(g_Stage.dp_array[i].GetRect())) {
			//DP�ƐڐG�����ꍇ
			UPdeteCollisionDP(g_Stage.dp_array[i].Gettype());
			g_Stage.dp_array[i].Setshow(false);
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
	if (m_StartCount == 1) {
		gStartThreeTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - gStartThreeTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - gStartThreeTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 2) {
		gStartTwoTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - gStartTwoTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - gStartTwoTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 3) {
		gStartOneTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - gStartOneTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - gStartOneTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 4) {
		gStartGoTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - gStartGoTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - gStartGoTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}

	//FPS�\��
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

	//BGM��~
	g_MusicManager->BGMStop(BGMT_STAGE);

}

void CGAME::RenderDebug(void)
{
	CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "���̃X�e�[�W���ł̎擾��  �w�́F%d�@�s���́F%d�@�z���́F%d�@�R�~���́F%d�@���́F%d",
	m_Scholastic, m_Action, m_Imagination, m_Communication, m_Charm);
CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "���̃X�e�[�W���ł̎擾��  �w�́F%d�@�s���́F%d�@�z���́F%d�@�R�~���́F%d�@���́F%d",
	m_Scholastic, m_Action, m_Imagination, m_Communication, m_Charm);

	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();
}
	
