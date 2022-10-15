#pragma once
#include "Stage.h"
#include "ctime"
#include "string"


CStage::CStage() :

	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_Over(0.0f),
	m_countbak(0),
	m_Bak(),
	m_SPBak(),
	m_dpinfo(NULL),
	m_dpvolume(0),
	m_dpcount(0),
	m_barinfo(NULL),
	m_barvolume(0),
	m_barcount(0),
	m_obinfo(NULL),
	m_obvolume(0),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f),
	m_spflg(false),
	m_bClear(false)
{}

CStage::~CStage() {

}

bool CStage::Load() {

	//�w�i�摜�̓ǂݍ���
	if (!m_Bak.Load("rouka3-k.png")) {
		return false;
	}

	if (!m_SPBak.Load("SPbak.png")) {
		return false;
	}

	return true;
}


//dpin:DP�z�u���
//dpco:DP�z�u���
//barin:����̔z�u���
//barco:����̏��
//obin:��Q���̔z�u���
//obco:��Q���̏��
void CStage::Initialize(DP_info* dpin, int dpco, BAR_info* barin, int barco, OB_info* obin, int obco) {
	//�X�N���[���l������
	m_BakScroll = 0.0f;
	m_StageScroll = 0.0f;

	m_countbak = 0;

	//DP�z�u���
	m_dpinfo = dpin;

	//DP�z�u���
	m_dpvolume = dpco;


	//����z�u���
	m_barinfo = barin;

	//����z�u���
	m_barvolume = barco;


	//��Q���z�u���
	m_obinfo = obin;

	//��Q���z�u���
	m_obvolume = obco;

	m_barcount = 0;
	m_dpcount = 0;
	m_obcount = 0;

	//�N���A�t���O������
	m_bClear = false;

	//����
	for (int i = 0; i < BAR_MAX; i++)
	{
		//�����z�u
		b_bar[i].Initialize();
	}

	//DP
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//������
		dp_array[i].Initialize();
	}

	//��Q��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		//������
		ob_array[i].Initialize();
	}

	g_ground.Initialize();

}

//�X�V
//over:�L�����N�^�[�̃I�[�o�[�l
//
void CStage::Update(float over, CRectangle plrect) {


	//�v���C���[�̃I�[�o�[�������������ɉ�����
	m_BakScroll -= over;
	m_StageScroll -= over;


	//�w�i�J�E���g
	if (m_BakScroll <= 0) {
		m_BakScroll = m_Bak.GetWidth();
		m_countbak += 1;

		m_spflg = false;

		//SP�t���O�n�m
		if (m_countbak == 2) {
			m_spflg = true;
		}

	}

	//�\���ςݑ��ꐔ�������񐔈ȉ��ŃX�N���[�����o���ʒu�����������Ȃ�����
	//��m_StageScroll�̓}�C�i�X�l�ł�
	if (m_barcount < m_barvolume && m_StageScroll < m_barinfo[m_barcount].Scroll)
	{
		for (int i = 0; i < BAR_MAX; i++)
		{
			//�\�����Ȃ�X���[
			if (b_bar[i].Getshow()) {
				continue;
			}

			//�\������
			b_bar[i].Start(m_barinfo[m_barcount].Pos_y);
			break;
		}

		//�\���ςݑ�������Z
		m_barcount++;

	}

	//�\���ς�DP����DP��񐔈ȉ��ŃX�N���[�����o���ʒu�����������Ȃ�����
	//��m_StageScroll�̓}�C�i�X�l�ł�
	if (m_dpcount < m_dpvolume && m_StageScroll < m_dpinfo[m_dpcount].Scroll)
	{
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (dp_array[i].Getshow()) {
				continue;
			}

			//�\������
			dp_array[i].Start(m_dpinfo[m_dpcount].Pos_y, m_dpinfo[m_dpcount].Type);
			break;
		}

		//�\���ς�DP�����Z
		m_dpcount++;
	}

	//�\���ςݏ�Q��������Q����񐔈ȉ��ŃX�N���[�����o���ʒu�����������Ȃ�����
	//��m_StageScroll�̓}�C�i�X�l�ł�
	if (m_obcount < m_obvolume && m_StageScroll < m_obinfo[m_obcount].Scroll)
	{
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (ob_array[i].Getshow()) {
				continue;
			}

			//�\������
			ob_array[i].Start(m_obinfo[m_obcount].Pos_y);
			break;
		}

		//�\���ςݏ�Q�������Z
		m_obcount++;
	}

	//����
	for (int i = 0; i < BAR_MAX; i++)
	{
		b_bar[i].Update(over);
	}

	//DP
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Update(over);
	}

	//��Q��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Update(over);
	}

	//DP�Ƃ̓����蔻��
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//��\���̏ꍇ�͔��肵�Ȃ�
		if (!dp_array[i].Getshow()) {
			continue;
		}

		if (dp_array[i].CollosopnDP(plrect)) {

			//DP�ƐڐG�����ꍇ
			UPdeteCollisionDP(dp_array[i].Gettype());
			dp_array[i].Setshow(false);
		}

	}

	//�N���A�t���O�ύX
	if (m_StageScroll <= -37000||g_pInput->IsKeyPush(MOFKEY_0)) {

		m_bClear = true;

	}

}

//DP�Ɠ��������ꍇ
void CStage::UPdeteCollisionDP(int dpt) {

	switch (dpt)
	{

	case 1:
		m_gaku += 1;
		if (m_gaku > 100) {
			m_gaku = 100;
		}
		break;

	case 2:
		m_kou += 1;
		if (m_kou > 100) {
			m_kou = 100;
		}
		break;

	case 3:
		m_sou += 1;
		if (m_sou > 100) {
			m_sou = 100;
		}
		break;

	case 4:
		m_komyu += 1;
		if (m_komyu > 100) {
			m_komyu = 100;
		}
		break;

	case 5:
		m_miryoku += 1;
		if (m_miryoku > 100) {
			m_miryoku = 100;
		}
		break;

	default:
		m_gaku = -100;
		break;
	}
}


//�`��
void CStage::Render(void) {


	//�e�N�X�`���̕`��
	//�����e�N�X�`�����J��Ԃ��ŉ�ʒ[�𒴂���܂ōs��
	int h = m_Bak.GetWidth();
	int sch = g_pGraphics->GetTargetWidth();
	for (float x = ((int)m_BakScroll % h) - h; x < sch; x += h) {

		//������SP�X�e�[�W�p�̔w�i��\�������銴����Ǝv�����ǂ����킩���
		m_Bak.Render(x, 0.0f);

		if (m_spflg)
		{

		}
	}

	//�n�ʕ`��
	g_ground.Render();

	//����`��
	for (int i = 0; i < BAR_MAX; i++)
	{
		b_bar[i].Render();
	}

	//�|�C���g�`��
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Render();
	}

	//��Q��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Render();
	}

}

//���
void CStage::Release(void) {

	m_Bak.Release();
	m_SPBak.Release();
}

//�f�o�b�N�`��
void CStage::DebuggingRender() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "�w�i�F%d����", m_countbak);
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "�w�i�X�N���[���l%f", m_BakScroll);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "�X�e�[�W�X�N���[���l%f", m_StageScroll);
	CGraphicsUtilities::RenderString(880, 690, MOF_XRGB(80, 80, 80), "P�L�[�Ńt���X�N���[���ɐ؂�ւ�");
	CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "���̃X�e�[�W���ł̎擾��  �w�́F%d�@�s���́F%d�@�z���́F%d�@�R�~���́F%d�@���́F%d",
		m_gaku, m_kou, m_sou, m_komyu, m_miryoku);

	//�n�ʃf�o�b�N�\��
	g_ground.DebuggingRender();

	//DP�f�o�b�N�\��

	//�N���A�t���O�\��
	if (m_bClear)
	{
		CGraphicsUtilities::RenderString(500, 350, MOF_XRGB(255, 0, 0), "�N���A!\nF1�Ń��X�^�[�g");
		CGraphicsUtilities::RenderString(0, 350, MOF_XRGB(80, 80, 80), "�N���A�t���O:true");

	}
	else
	{
		CGraphicsUtilities::RenderString(0, 350, MOF_XRGB(80, 80, 80), "�N���A�t���O:false");
	}

}

bool CStage::GetClear(void) {

	return m_bClear;

}

