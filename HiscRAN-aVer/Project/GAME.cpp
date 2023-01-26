//////////////////////////////////////////////
//	�Q�[���Ǘ��̃v���O�����ł��@�@�@�@�@�@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "GAME.h"


CGAME::CGAME():
	m_StartCount(),
	m_GameOverflg(),
	m_GameClearflg(),
	m_StartTime(),
	m_DPDeci(),
	m_DPNum(),
	m_SP_DPNum(),
	m_ClearTexture(),
	m_ClearScale(),
	m_BlackBakAlph(),
	m_StartScale(),
	m_WhiteBakAlph()
{}

CGAME::~CGAME()
{

}


void CGAME::UpdateDebug(void)
{

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
		Initialize(b_GameProgMamt, b_MusicManager, b_EffectManeger, b_MenuMamt);
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

	g_Player.UpdateDebug();
	g_Stage.UpdateDebug();
}

//�f�ޓǂݍ���
void CGAME::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Game");

	if (!g_Player.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}
	if (!g_Stage.Load()) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}


	//�J�E���g�_�E���摜�̓ǂݍ���
	if (!m_StartThreeTexture.Load("Countdown_3.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_StartTwoTexture.Load("Countdown_2.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_StartOneTexture.Load("Countdown_1.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_StartGoTexture.Load("Countdown_Go.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	if (!m_ClearTexture.Load("GameClear.png")) {
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���[�h����
	b_LoadSitu = LOAD_COMP;

}

//������
//�����F�Q�[���i���Ǘ��N���X
void CGAME::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{

	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;
	b_MenuMamt = menu;

	//�v���C���[������
	g_Player.Initialize();
	g_Player.SetMusicManager(musi);
	g_Player.SetEffectManager(effec);

	//�X�e�[�W������
	g_Stage.Initialize(b_GameProgMamt->GetDPdec_SPflg(),b_GameProgMamt->GetDPdec_type());
	g_Stage.SetMusicManager(musi);
	g_Stage.SetEffectManager(effec);

	//�J�E���g�_�E���p�J�E���^������
	m_StartCount = 0;

	m_Stopflg = true;
	//��Ԃ�ݒ�
	b_Fadein = FADE_IN;

	//DP�ڕW���Z�b�g
	m_DPDeci = b_GameProgMamt->GetDPdec_type();

	//�t�F�[�h�C���p
	m_BlackBakAlph = 0;
	m_WhiteBakAlph = 255;

	//�N���A�A�I�[�o�[�t���O������
	m_GameClearflg = false;
	m_GameOverflg = false;

	//�X�e�[�W���Ŏ擾����DP�̐�������
	for (int i = 0; i < DP_COUNT; i++)
	{
		m_DPNum[i] = 0;
	}
	//SODP������
	m_SP_DPNum = 0;

	
	m_StartScale = 0.0f;

	//�f�o�b�N�p

	//���݂̃V�[��
	m_NowScene = SCENENO_GAME;
}

//�X�V
void CGAME::Update(void)
{

	//�Q�[���I�[�o�[�t���O���󂯎��
	m_GameOverflg = g_Player.GetOver();

	//�N���A�t���O���󂯎��
	m_GameClearflg = g_Stage.GetClear();
	

	//�q�b�g�X�g�b�v�̏���
	if (m_GameOverflg && m_Stopflg)
	{
		m_Stopflg = false;
		m_StopCount = 30;
	}
	if (m_StopCount > 0)
	{
		m_StopCount--;
		return;
	}



	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph, true);

		//�t�F�[�h�C���I��莟��J�E���g�J�n
		if (!g_Stage.GetClear())
		{
			//�J�n����
			m_StartTime = timeGetTime()+1000;
		}
		return;
	}

	//BGM�J�n
	b_MusicManager->BGMStart(BGMT_STAGE);

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {

		//SE�����ׂĒ�~
		b_MusicManager->SEALLStop();

		//�N���A���
		if (m_GameClearflg) {

			//DP�̎擾����ۑ�
			b_GameProgMamt->SetGame_DPNum(m_DPNum);
			b_GameProgMamt->SetGame_SP_DPNum(m_SP_DPNum);
			m_bEnd = true;
			m_NextScene = SCENENO_GAMECLEAR;

		}
		//�Q�[���I�[�o�[���
		else if(m_GameOverflg)
		{
			b_MusicManager->SEStart(SE_T_GAMEOVER);
			m_bEnd = true;
			m_NextScene = SCENENO_GAMEOVER;
		}
		//���j���[���烂�[�h�Z���N�g��
		else
		{
			//���j���[���\��
			b_MenuMamt->Hide();
			m_bEnd = true;
			m_NextScene = SCENENO_SELECTMODE;
		}

		return;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {

		//�N���A��
		if (m_GameClearflg) {
			//��
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true,1.0f);

			//�\���{�����Z
			m_ClearScale += 0.01f;
			if (m_ClearScale >= 0.25f) {
				m_ClearScale = 0.25f;
			}

			//�N���A���̃L�����N�^�[����
			g_Player.UpdateClear();

		}
		//�Q�[���I�[�o�[��
		else if(m_GameOverflg)
		{
			//��
			m_BlackBakAlph = FadeOut(m_BlackBakAlph, true);
		}
		//���j���[�Ŗ߂�ꍇ
		else
		{
			
			m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		}
		return;
	}

	//���j���[�\����
	if (b_MenuMamt->IsShow()) {

		//�X�V
		b_MenuMamt->Update();

		//�I����
		if (b_MenuMamt->IsEnter())
		{
			//�I�����̔ԍ��ɂ���ď���
			if (b_MenuMamt->GetSelect() == 0)
			{
				//���[�h�Z���N�g��ʂ�
				b_Fadein = FADE_OUT;
			}
			else
			{
				//���j���[���\��
				b_MenuMamt->Hide();

				//�J�E���g�_�E���J�n
				m_StartCount = 0;
				m_StartTime = timeGetTime() + 1000;

				//��~
				g_Stage.GameStopPlayChange();
			}
		}
		return;
	}
	else if(g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		//�Q�[�����f���j���[�\��
		b_MenuMamt->Show(MENUT_GAME_END);

		//SE��~
		b_MusicManager->SEALLStop();
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


	//�Q�[���I�[�o�[���̏ꍇ�t�F�[�h�A�E�g
	if (m_GameOverflg) {

		//�Q�[���I�[�o�[�����t���O��ۑ�(HP)
		if (g_Player.GetOver()) {
			b_GameProgMamt->SetGame_Over_HP(true);
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
		//�t�F�[�h�A�E�g
		b_Fadein = FADE_OUT;

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
			//��\���̂��͔̂��肵�Ȃ�
			if (!g_Stage.ene_array[e].Getshow())
				continue;

			if (g_Stage.ene_array[e].GetRect().CollisionRect(g_Stage.ob_array[i].GetTopBarRect())) {

				//��Q���̍����ɒ���
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
	b_EffectManeger->Update(g_Player.GetRect());

}

//DP�Ɠ��������ꍇ
//dpt->DP�̎��
void CGAME::UPdeteCollisionDP(int dpt) {

	//SE�Đ�
	b_MusicManager->SEStart(SE_T_DP_HIT);


	switch (dpt)
	{
		//�w��
	case DP_SCHOLASTIC:

		//�ǉ�
		m_DPNum[DP_SCHOLASTIC]++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC_AROOW);
		break;

		//�s����
	case DP_ACTION:

		//�ǉ�
		m_DPNum[DP_ACTION]++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION_AROOW);
		break;

		//�z����
	case DP_IMAGINATION:

		//�ǉ�
		m_DPNum[DP_IMAGINATION]++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION_AROOW);
		break;

		//�R�~����
	case DP_COMMUNICATION:

		//�ǉ�
		m_DPNum[DP_COMMUNICATION]++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION_AROOW);
		break;

		//����
	case DP_CHARM:

		//�ǉ�
		m_DPNum[DP_CHARM]++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM_AROOW);
		break;

	case DP_SP_SCHOLASTIC:

		//�ǉ�
		m_SP_DPNum++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC);
		b_EffectManeger->Start(0, 0, EFC_GET_SCHOLASTIC_AROOW);
		break;

	case DP_SP_ACTION:

		//�ǉ�
		m_SP_DPNum++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION);
		b_EffectManeger->Start(0, 0, EFC_GET_ACTION_AROOW);
		break;

	case DP_SP_IMAGINATION:

		//�ǉ�
		m_SP_DPNum++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION);
		b_EffectManeger->Start(0, 0, EFC_GET_IMAGINATION_AROOW);
		break;

	case DP_SP_COMMUNICATION:

		//�ǉ�
		m_SP_DPNum++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION);
		b_EffectManeger->Start(0, 0, EFC_GET_COMMUNICATION_AROOW);
		break;

	case DP_SP_CHARM:

		//�ǉ�
		m_SP_DPNum++;

		//�G�t�F�N�g�Đ�
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM);
		b_EffectManeger->Start(0, 0, EFC_GET_CHARM_AROOW);
		break;


	default:
		break;
	}
}

void CGAME::Render(void)
{

	//�X�e�[�W�`��
	g_Stage.Render();

	//�v���C���[�`��
	g_Player.Render();


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

	//�N���A�e�L�X�g�\��
	if (m_GameClearflg) {
		m_ClearTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - m_ClearTexture.GetWidth() / 2 * m_ClearScale,
			g_pGraphics->GetTargetHeight() / 2 - m_ClearTexture.GetHeight() / 2 * m_ClearScale, m_ClearScale);

	}

	//�G�t�F�N�g�̕`��
	b_EffectManeger->Render();

	//���j���[�̕`��
	b_MenuMamt->Render();

	//�t�F�[�h�A�E�g�Ó]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),MOF_ARGB(m_BlackBakAlph,0,0,0));

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

}


void CGAME::Release(void)
{
	g_Player.Release();

	g_Stage.Release();

	//�J�E���g�_�E���摜�̊J��
	m_StartThreeTexture.Release();
	m_StartTwoTexture.Release();
	m_StartOneTexture.Release();
	m_StartGoTexture.Release();

	m_ClearTexture.Release();

	//BGM��~
	b_MusicManager->BGMStop(BGMT_STAGE);

}

void CGAME::RenderDebug(void)
{
	for (int i = 0; i < DP_COUNT; i++)
	{
		CGraphicsUtilities::RenderString(200 + i * 30, 0, MOF_COLOR_BLACK,"%d", m_DPNum[i]);
	}

	CGraphicsUtilities::RenderString(200, 30, MOF_COLOR_BLACK, "%d", m_SP_DPNum);
	

	//FPS�\��
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "FPS�F%d", CUtilities::GetFPS());

	g_Stage.RenderDebugging();
	g_Player.RenderDebugging();

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

}
	
