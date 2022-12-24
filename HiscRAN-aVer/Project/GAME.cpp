#pragma once
#include "GAME.h"




CGAME::CGAME():
	m_Menu(),
	m_MenuItemCount(),
	m_StartCount(),
	m_GameOverflg(),
	m_GameClearflg(),
	m_StartTime(),
	m_DPDeci(),
	m_DPNum(),
	m_SchoolYear()
{}

CGAME::~CGAME()
{

}

//DP�Ɠ��������ꍇ
//dpt->DP�̎��
void CGAME::UPdeteCollisionDP(int dpt) {

	g_MusicManager->SEStart(SE_T_DP_HIT);

	m_DPNum[m_SchoolYear][dpt]++;
	m_DPNum[3][dpt]++;

	switch (dpt)
	{
		//�w��
	case DP_SCHOLASTIC:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		break;

		//�s����
	case DP_ACTION:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		break;

		//�z����
	case DP_IMAGINATION:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		break;

		//�R�~����
	case DP_COMMUNICATION:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		break;

		//����
	case DP_CHARM:
		//�G�t�F�N�g�Đ�
		g_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		break;
	default:
		break;
	}
}

//�f�ޓǂݍ���
void CGAME::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Game");

	//�v���C���[�f�ރ��[�h
	if (!g_Player.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	//�X�e�[�W�f�ރ��[�h
	if (!g_Stage.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	//���U���g�f�ރ��[�h
	if (!g_Result.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//�J�E���g�_�E���摜�̓ǂݍ���
	m_StartThreeTexture.Load("�n�C�X�N�@�J�E���g�_�E�����S�����@�R.png");
	m_StartTwoTexture.Load("�n�C�X�N�@�J�E���g�_�E�����S�����@�Q.png");
	m_StartOneTexture.Load("�n�C�X�N�@�J�E���g�_�E�����S�����@�P.png");
	m_StartGoTexture.Load("�n�C�X�N_�J�n�J�E���g�_�E��_GO.png");

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���[�h����
	b_LoadSitu = LOAD_COMP;

}

//������
//�����F�Q�[���i���Ǘ��N���X
void CGAME::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{

	//�e�}�l�[�W���[�Z�b�g
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;


	//�v���C���[������
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//�X�e�[�W������
	g_Stage.Initialize();
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);

	//���ԃ��U���g������
	g_Result.Initialize();
	g_Result.SetMusicManager(musi);
	g_Result.SetEffectManager(effec);

	//�J�E���g�_�E���p�J�E���^������
	m_StartCount = 0;

	//���݂̊w�N��
	//��N����
	m_SchoolYear = 0;

	//��Ԃ�ݒ�
	b_Fadein = FADE_IN;

	//DP�ڕW���Z�b�g
	m_DPDeci = m_GameProgMamt->GetDPdec_type();

	//�t�F�[�h�C���p
	m_BlackBakAlph = 0;
	m_WhiteBakAlph = 255;

	//�f�o�b�O�p
	m_GameClearflg = false;
	m_GameOverflg = false;

	//�X�e�[�W���Ŏ擾����DP�̐�������
	for (int year = 0; year < 4; year++)
	{
		for (int i = 0; i < DP_COUNT; i++)
		{
			m_DPNum[year][i] = 0;
		}
	}
	m_StartScale = 0.0f;

	//���݂̃V�[��
	m_NowScene = SCENENO_GAME;

}

//�X�V
void CGAME::Update(void)
{

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph, FADE_OUT_SPEED);
		return;
	}

	//BGM�J�n
	g_MusicManager->BGMStart(BGMT_STAGE);

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		//SE�����ׂĒ�~
		g_MusicManager->SEALLStop();

		if (m_GameClearflg) {

			//�N���A
			//DP�̎擾����ۑ��FDP���v�擾���̍��v��n��
			m_GameProgMamt->SetGame_DPNum(m_DPNum[3]);
			m_bEnd = true;
			m_NextScene = SCENENO_GAMECLEAR;

		}
		else
		{
			//�Q�[���I�[�o�[
			g_MusicManager->SEStart(SE_T_GAMEOVER);
			m_bEnd = true;
			m_NextScene = SCENENO_GAMEOVER;

		}
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {

		//�N���A��
		if (m_GameClearflg) {
			//��
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph,false, FADE_OUT_SPEED-2.8f);
			//�N���A���̃L�����N�^�[����
			g_Player.UpdateClear();

			//�N���A���̃��U���g
			g_Result.Update();

			//�\�����Ă�����X�V
			if (g_Result.GetShow())
			{
				//���ԕ񍐍X�V
				g_Result.Update();
			}
			else
			{
				//�\��
				g_Result.Start();
			}

			//���ԕ񍐏I���t���O
			if (g_Result.GetEndflg()) {

				b_Fadein = FADE_NEXT;
			}
		}
		else
		{
			//�Q�[���I�[�o�[��
			//��
			m_BlackBakAlph = FadeOut(m_BlackBakAlph, FADE_OUT_SPEED);
		}

		return;
	}


	//�Q�[���J�n�؂�ւ�
	//�J�n���ɃJ�E���g�_�E���J�n
	if (g_pInput->IsKeyPush(MOFKEY_RETURN) && !g_Stage.GetClear())
	{
		//�J�n����
		m_StartTime = timeGetTime();
	}

	//�J�E���g�_�E������
	if (m_StartCount < 5&&timeGetTime() - m_StartTime > 1000) {
		//�J�n����
		m_StartTime = timeGetTime();
		//�J�E���g����
		m_StartCount++;

		//�Y�[���C�����Z�b�g
		m_StartScale = 0.0f;

		
		if (m_StartCount == 4) {
			//�Q�[���J�n
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

	//C�ŃQ�[���N���A���
	if (g_pInput->IsKeyPush(MOFKEY_C))
	{
		m_GameClearflg = true;
	}

	//V�ŃQ�[���I�[�o�[���
	else if (g_pInput->IsKeyPush(MOFKEY_V))
	{
		m_GameOverflg = true;
	}

	//�ꎞ�I�Ȓǉ��ł�
	//���X�^�[�g
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {

		//������
		Initialize(m_GameProgMamt, g_MusicManager, g_EffectManeger);
	}

	//�f�o�b�O�p
	if (g_pInput->IsKeyPush(MOFKEY_1)) {
		//DP
		UPdeteCollisionDP(DP_SCHOLASTIC);
	}
	if (g_pInput->IsKeyPush(MOFKEY_2)) {
		//DP
		UPdeteCollisionDP(DP_ACTION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_3)) {
		//DP
		UPdeteCollisionDP(DP_IMAGINATION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_4)) {
		//DP
		UPdeteCollisionDP(DP_COMMUNICATION);
	}
	if (g_pInput->IsKeyPush(MOFKEY_5)) {
		//DP
		UPdeteCollisionDP(DP_CHARM);
	}


	//���j���[�̍X�V
	if (m_Menu.IsShow())
	{
		//�J�E���g�_�E�����~���邽��
		m_StartTime = timeGetTime();

		m_Menu.Update();
		if (m_Menu.IsEnter())
		{
			//��߂�
			if (m_Menu.GetSelect() == 0)
			{
				//���[�h�Z���N�g��
				m_bEnd = true;
				m_NextScene = SCENENO_SELECTMODE;
			}
			//���j���[���\��
			m_Menu.Hide();
		}
	}
	//�G�X�P�[�v�L�[�ŏI�����j���[��\��
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//�v���C���ł���Β�~
		if (g_Stage.GetGameStopPlay())
			g_Stage.GameStopPlayChange();

		m_Menu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}


	//�Q�[���I�[�o�[���̏ꍇ�t�F�[�h�A�E�g�t���O�X�V
	if (m_GameOverflg) {

		//�Q�[���I�[�o�[�����t���O��ۑ�(HP)
		if (g_Player.GetOver()) {
			m_GameProgMamt->SetGame_Over_HP(true);
		}

		b_Fadein = FADE_OUT;
	}

	//�Q�[���X�g�b�v��,�Q�[���I�[�o�[���͈ȉ��̏��������s���Ȃ�
	if (!g_Stage.GetGameStopPlay()||m_GameOverflg) {
		return;
	}

	//�N���A���̏���
	if (m_GameClearflg)
	{
		b_Fadein = FADE_OUT;

		//�N���A����DP����萔����Ă��Ȃ��ꍇ
		//�S�w�N�ł̍��v�Ɣ�r
		if (m_DPNum[3][m_DPDeci] < DP_SHOR_NUM) {
			//�Q�[���I�[�o�[�t���O���Z�b�g
			m_GameOverflg = true;
			m_GameClearflg = false;
		}
		return;
	}

	//�N���A�t���O���󂯎��
	if (g_Stage.GetClear()) {

		//�Z�b�g
		m_GameClearflg = true;
	}

	//�Q�[���I�[�o�[�t���O���󂯎��
	if (g_Player.GetOver()) {

		//�Z�b�g
		m_GameOverflg = true;
	}
	
	//�v���C���[�X�V
	g_Player.Update();

	//�X�e�[�W�X�V
	g_Stage.Update(g_Player.GetRect());	

	//���ԕ񍐒�
	if (g_Stage.GetResultShow()) {

		//���ԕ񍐂��I�����Ă���ꍇ
		if (g_Stage.GetResultEndflg()) {

			//������
			g_Result.Initialize();
		}
		//�\�����Ă�����X�V
		else if (g_Result.GetShow())
		{
			//���ԕ񍐍X�V
			g_Result.Update();
		}
		else
		{
			//�\��
			g_Result.Start();
		}

		//���ԕ񍐏I���t���O
		if (g_Result.GetEndflg()) {

			//�I�����X�V
			g_Stage.SetResultEndflg(true);
			m_SchoolYear++;
		}

	}

	//����Ƃ̓����蔻��
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		if (!g_Stage.b_bar[i].Getshow()) {
			continue;
		}

		if (g_Player.GetLegsRect().CollisionRect((g_Stage.b_bar[i].GetRect()))){

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

	//DP�ڕW�\���i���j
	switch (m_DPDeci)
	{

	case 0:
		CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP�ڕW:�w��");
		break;
	case 1:
		CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP�ڕW:�s����");
		break;

	case 2:
		CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP�ڕW:�z����");
		break;

	case 3:
		CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP�ڕW:�R�~����");
		break;

	case 4:
		CGraphicsUtilities::RenderString(0, 210, MOF_XRGB(80, 80, 80), "DP�ڕW:����");
		break;

	default:
		break;
	}

	//���ԕ񍐕`��
	if (!m_GameClearflg)
	{
		g_Result.RenderMiddleResult();
	}

	//���j���[�̕`��
	m_Menu.Render(2);

	//�Q�[���J�n���̃J�E���g�_�E���̕\��
	//��ʒ����ɔz�u
	if (m_StartCount == 1) {
		m_StartThreeTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartThreeTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartThreeTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 2) {
		m_StartTwoTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartTwoTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartTwoTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 3) {
		m_StartOneTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartOneTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartOneTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}
	else if (m_StartCount == 4) {
		m_StartGoTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_StartGoTexture.GetWidth() / 2 * m_StartScale,
			g_pGraphics->GetTargetHeight() / 2 - m_StartGoTexture.GetHeight() / 2 * m_StartScale, m_StartScale);
	}


	//�G�t�F�N�g�̕`��
	g_EffectManeger->Render();

	//�t�F�[�h�A�E�g�Ó]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),MOF_ARGB(m_BlackBakAlph,0,0,0));

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

	if (m_GameClearflg) {
		g_Result.RenderLastResult();
	}
}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	g_Result.Release();

	m_Menu.Release();

	//�J�E���g�_�E���摜�̊J��
	m_StartThreeTexture.Release();
	m_StartTwoTexture.Release();
	m_StartOneTexture.Release();
	m_StartGoTexture.Release();

	//BGM��~
	g_MusicManager->BGMStop(BGMT_STAGE);

}

void CGAME::RenderDebug(void)
{
	for (int year = 0; year < 4; year++)
	{		
		for (int x = 0; x < DP_COUNT; x++)
		{
			CGraphicsUtilities::RenderString(200 + x * 30, 0 + year * 30 , 
				MOF_COLOR_BLACK, "%d", m_DPNum[year][x]);
		}
	}

	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();
	g_Result.RenderDebugging();
}
	
