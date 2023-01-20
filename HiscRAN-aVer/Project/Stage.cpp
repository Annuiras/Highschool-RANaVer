//////////////////////////////////////////////
//	�X�e�[�W�Ǘ��̃v���O�����ł�			//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "Stage.h"
#include "ctime"
#include "string"
#include "Stage_DP.h"
#include "Stage_Bar.h"
#include "Stage_Obstacle.h"
#include "Stage_Enemy.h"

CStage::CStage() :

	m_countbak(0),
	m_BakStart(),
	m_SPBak_Start(),
	m_SPBak_1(),
	m_SPBak_2(),
	m_SPBak_End(),
	m_dpcount(0),
	m_barcount(0),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f), 
	m_BakAVal(0),
	m_AdoptCount(0),
	m_AlreadyUsedArray(),
	SP_flg(),
	m_bClear(false),
	m_Scroll_Speed(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

#pragma region �X�e�[�W�w�i���[�h

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("StageBak");

	if (!m_BakStart.Load("HallStart.png")) {
		return false;
	}

	if (!m_BakRdoor.Load("Door_R.png")) {
		return false;
	}

	if (!m_BakRwall.Load("Wall_R.png")) {
		return false;
	}

	if (!m_Bakldoor.Load("Door_L.png")) {
		return false;
	}

	if (!m_Baklwall.Load("Wall_L.png")) {
		return false;
	}

	if (!m_BakStairs.Load("Stairs.png")) {
		return false;
	}

	if (!m_BakWindow.Load("Window_2.png")) {
		return false;
	}

	if (!m_BakEnd.Load("HallEnd.png")) {
		return false;
	}

	//SP�ŏ��̔w�i
	if (!m_SPBak_Start.Load("SPStart.png")) {
		return false;
	}

	//SP�X�e�[�W���̔w�i
	if (!m_SPBak_1.Load("SP1.png")) {
		return false;
	}

	//SP�X�e�[�W���̔w�i
	if (!m_SPBak_2.Load("SP2.png")) {
		return false;
	}

	//SP�Ō�̂̔w�i
	if (!m_SPBak_End.Load("SPEnd.png")) {
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

#pragma endregion

#pragma region DP�e�N�X�`�����[�h

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("DetailPoint");

	//���e�N�X�`���F�w��
	if (!dp_Textuer_Scholastic.Load("DPScholastic.png")) {
		return false;
	}

	//���e�N�X�`���F�s����
	if (!dp_Textuer_Action.Load("DPAction.png")) {
		return false;
	}

	//���e�N�X�`���F�z����
	if (!dp_Textuer_Imagination.Load("DPImagination.png")) {
		return false;
	}

	//���e�N�X�`���F�R�~����
	if (!dp_Textuer_Communication.Load("DPCommunication.png")) {
		return false;
	}

	//���e�N�X�`���F����
	if (!dp_Textuer_Charm.Load("DPCharm.png")) {
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

#pragma endregion

#pragma region ��Q���e�N�X�`�����[�h

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Obstacle");

	//�e�N�X�`���F��
	if (!ob_Textuer_Desk.Load("Desk.png")) {
		return false;
	}

	//�e�N�X�`���F���ݔ�
	if (!ob_Textuer_TrachCan.Load("TrachCan.png")) {
		return false;
	}

	//�e�N�X�`���F���b�J�[
	if (!ob_Textuer_Locker.Load("Locker.png")) {
		return false;
	}

	//�e�N�X�`���F���ȏ�_����
	if (!ob_Textuer_TextBookNL.Load("TextBookNL.png")) {
		return false;
	}

	//�e�N�X�`���F���ȏ�_���w
	if (!ob_Textuer_TextBookMATH.Load("TextBookMATH.png")) {
		return false;
	}

	//�e�N�X�`���F���ȏ�_����
	if (!ob_Textuer_TextBookCHEM.Load("TextBookCHEM.png")) {
		return false;
	}

	//�e�N�X�`���F���ȏ�_�Љ�
	if (!ob_Textuer_TextBookSOC.Load("TextBookSOC.png")) {
		return false;
	}

	//�e�N�X�`���F���ȏ�_�p��
	if (!ob_Textuer_TextBookENG.Load("TextBookENG.png")) {
		return false;
	}

	//�e�N�X�`���F���є�
	if (!ob_Textuer_VaultingHorse.Load("VaultingHorse.png")) {
		return false;
	}

	//�e�N�X�`���F�Z���n���e�[�v
	if (!ob_Textuer_ScotchTape.Load("ScotchTape.png")) {
		return false;
	}

	//�e�N�X�`���F������
	if (!ob_Textuer_BloackboardEraser.Load("BloackboardEraser.png")) {
		return false;
	}

	//�e�N�X�`���F�X�e�B�b�N�̂�
	if (!ob_Seaweed.Load("Seaweed.png")) {
		return false;
	}

	//�e�N�X�`���F�X�}�z��
	if (!ob_Smartphone1.Load("Smartphone1.png")) {
		return false;
	}

	//�e�N�X�`���F�����S��
	if (!ob_Eraser.Load("Eraser.png")) {
		return false;
	}

	//�e�N�X�`���F�X�}�z�c
	if (!ob_SmartphoneVertical.Load("SmartphoneVertical.png")) {
		return false;
	}


	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

#pragma endregion

#pragma region ����e�N�X�`�����[�h

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Bar");

	//���e�N�X�`���F�����
	if (!bar_Textuer_Big.Load("Big.png")) {
		return false;
	}

	//���e�N�X�`���F���ꒆ
	if (!bar_Textuer_Medium.Load("Medium.png")) {
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

#pragma endregion

	//�i�s�x�o�[�A�i�s�x���A�C�R���A�A�C�R���̕\��
	if (!m_BarTextuer.Load("Game_Bar.png")) {
		return false;
	}
	if (!m_CharaProgressTextuer.Load("Game_CharaProgress.png")) {
		return false;
	}


#pragma region �G

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Character");

	//�G1
	if (!ene_Texture_1.Load("Motion.png"))
	{
		return false;
	}
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//�G�A�j���[�V������p��
	//���u��
	float Encoma = 4;
	MofS32 Enedan = 3;
	//�A�j���[�V����
	SpriteAnimationCreate EneAnim[] =
	{
		{
			"�G�ړ�",
			0, 370,
			160, 185,
			TRUE,{ {Encoma,0,Enedan},{Encoma,1,Enedan},{Encoma,2,Enedan},{Encoma,3,Enedan},{Encoma,4,Enedan},{Encoma,5,Enedan},{Encoma,6,Enedan},{Encoma,7,Enedan},{Encoma,8,Enedan},{Encoma,9,Enedan},{Encoma,10,Enedan}
			,{Encoma,11,Enedan},{Encoma,12,Enedan},{Encoma,13,Enedan},{Encoma,14,Enedan}}

		},
	};
	Enemy_Motion.Create(EneAnim, ENEMY_MOTION_COUNT);
	return true;

#pragma endregion

		return true;
}

//������
//spflg:SP����t���O
void CStage::Initialize(bool spflg, int dptype) {

	//SP����t���O�Z�b�g
	SP_flg = spflg;

	//DP�ڕW�ݒ��ʂőI��DP�ԍ��Z�b�g
	DP_Deci_Type = dptype;

	//�i�s�x�o�[�A�C�R���̏�����
	m_BarProgress = 0;

	//�w�N�\���̕\���ʒu�̏�����
	m_GradeOffset = g_pGraphics->GetTargetWidth();

	//�X�N���[���l������
	m_BakScroll = 1.0f;

	//�X�e�[�W�X�N���[���l������
	m_StageScroll = g_pGraphics->GetTargetWidth()*2;

	//�w�i�J�E���g������
	m_countbak = 0;

	//���l������
	m_BakAVal = 255;

	//�X�e�[�W�ω��t���O
	v_StageChangeflg = false;		

	//SP�X�e�[�W��ԗp
	m_SPSitua = tag_StageSituation::STAGE_SP_YET;

	//SP�w�i�J�E���g
	m_SPcountbak = 0;


	//�}�b�v�p�^�[���������_����
	for (int i = 0; i < 15; i++)
	{
		m_StageComposition[i] = RandmuBak.GetRandomNumbe(0, 0);
	}

	//�}�b�v�p�^�[���Y����
	m_MapNo = 0;


	//������
	m_AdoptCount = 0;

	//�X�e�[�W�\�����Z�b�g
	//��m���œ����X�e�[�W���I������Ă��܂����ߎ��s�񐔂͑���
	for (int z = 1; z < 1000; z++)
	{
		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (m_AlreadyUsedArray[x] == 1)
			{
				//�ǂ��܂ō̗p�ς݂��J�E���g
				m_AdoptCount += 1;
			}
		}

		//1�Q�[�����̃X�e�[�W���p�ӏo������I��
		if (m_AdoptCount >= SATAGE_MAP_PATTERN) {
			break;
		}

		//SP�}�b�v���̗p
		if (m_AdoptCount == MAP_SP_START_PATTERN && SP_flg)
		{
			int SPAdopCount = 0;

			//SP�}�b�v�p�^�[�����Z�b�g
			for (int i = 0; i < 100; i++)
			{
				int SPrandmu = RandmuBak.GetRandomNumbe(15, 16);
				if (m_AlreadyUsedArray[SPrandmu] == 0) {

					m_StageComposition[m_AdoptCount+ SPAdopCount] = SPrandmu;
					SPAdopCount++;
					//�g�p�����p�^�[���̏ꏊ�ɂP���Z�b�g
					m_AlreadyUsedArray[SPrandmu] = 1;

				}
				//1SP�X�e�[�W���̃X�e�[�W���p�ӏo������I��
				if (m_AdoptCount+ MAP_SP_LENGTH <= m_AdoptCount+ SPAdopCount) {
					break;
				}

			}
		}
		else 
		{
			//�����_���p�^�[�����Z�b�g
			int randam= RandmuBak.GetRandomNumbe(0, 14);

			//�܂��g�p���Ă��Ȃ��ꍇ�̂ݍ̗p(1=�g�p�ς�)
			if (m_AlreadyUsedArray[randam] == 0)
			{

				//�̗p
				m_StageComposition[m_AdoptCount] = randam;

				//�g�p�����p�^�[���̏ꏊ�ɂP���Z�b�g
				m_AlreadyUsedArray[randam] = 1;
			
			}			

		}

		//�̗p�σJ�E���g
		m_AdoptCount = 0;
	}

	//�w�i�\�������߂鏈��
	for (int i = 0; i < SATAGE_MAP_PATTERN*2; i++)
	{
		//�����_���Ŏ�ނ����肷��
		int randamu=RandmuBak.GetRandomNumbe(1, 6);

		//��ԍŏ��ȊO�ŁA�����w�i�̏ꍇ
		//�Ⴄ�w�i�ɂ��鏈��
		if (i != 0&&randamu == m_BakComposition[i - 1]) {

			if (randamu == 6) {
				randamu = 1;
			}
			else
			{
				randamu++;
			}
		}

		//�������w�i���A�����Ȃ��悤�ɂ�����̂Ȃ��Ă��悵
		m_BakComposition[i] = randamu;

	}

	//�w�i�\���̈�ԍŌ�p�̕���K�p����
	m_BakComposition[SATAGE_MAP_PATTERN * 2] = 8;

	//�E������w�i�\����ǂނ��߂̏�����
	m_RandamuBakRight = 7;
	m_RandamuBakLeft = m_BakComposition[0];

	//�X�y�V�����X�e�[�W����������ꍇ
	//�w�i���X�y�V�����X�e�[�W�ɕύX����
	if (SP_flg) {

		m_BakComposition[(MAP_SP_START_PATTERN * 2)] = 9;

		for (int i = 1; i < MAP_SP_LENGTH*2; i++)
		{
			m_BakComposition[(MAP_SP_START_PATTERN * 2) + i] = RandmuBak.GetRandomNumbe(10, 11);
		}
		m_BakComposition[(MAP_SP_START_PATTERN * 2)+(MAP_SP_LENGTH*2)-1] = 13;
	}

	//������
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		m_AlreadyUsedArray[i] = 0;
	}


	//�f�o�b�O�p�̎w��R�}���h�A�K�v�ɉ����Ă������Ă�������
	//m_StageComposition[0] = 14;
	//m_StageComposition[1] = 1;
	//m_StageComposition[2] = 2;
	//m_StageComposition[3] = 3;
	//m_StageComposition[4] = 4;
	//m_StageComposition[5] = 5;
	//m_StageComposition[6] = 6;
	//m_StageComposition[7] = 7;
	//m_StageComposition[8] = 8;
	//m_StageComposition[9] = 9;
	//m_StageComposition[10] = 10;
	//m_StageComposition[11] = 0;
	//m_StageComposition[12] = 8;
	//m_StageComposition[13] = 8;
	//m_StageComposition[14] = 2;


	//�\���ς݃J�E���g������
	m_barcount = 0;
	m_dpcount = 0;
	m_obcount = 0;
	m_enecount = 0;

	//�N���A�t���O������
	m_bClear = false;

	//�X�e�[�W�X�N���[�����x
	m_Scroll_Speed = 0;

	//�J�n�t���O
	m_Startflg = false;

	//�w�i�p�����_�����l������
	//m_RandamuBakLeft = RandmuBak.GetRandomNumbe(1, 6); 
	//m_RandamuBakRight = 0;

	//����
	for (int i = 0; i < BAR_VOLUME; i++)
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

	//�G
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		//������
		ene_array[i].Initialize();
	}

}

//SP���̃X�e�[�W���Z�b�g�z�u
void CStage::SPInitialize(void)
{
	//��̃X�e�[�W����DP�z�u�Ɠ�������
	for (int z = 1; z < 100; z++)
	{
		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (m_AlreadyUsedArray[x] == 1)
			{
				//�ǂ��܂ō̗p�ς݂��J�E���g
				m_AdoptCount += 1;
			}
		}
		//SP����DP�p�̏���  SP����DP�z�u��2��������
		int randam = RandmuBak.GetRandomNumbe(16, 17);

		//���̗p�������ꍇ
		if (m_AlreadyUsedArray[randam] == 0)
		{
			//SP�̏o���ʒu�ɍ��킹��SP�X�e�[�W���������炵�Ă܂�
			m_StageComposition[m_AdoptCount + MAP_SP_START_PATTERN + 1] = randam;
			//�g�p�����p�^�[���̏ꏊ�ɂP���Z�b�g
			m_AlreadyUsedArray[randam] = 1;
		}
		//�̗p�σJ�E���g
		m_AdoptCount = 0;
	}

	//������
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		m_AlreadyUsedArray[i] = 0;
	}

}

//�X�V
//plrect:�v���C���[�̓����蔻���`
void CStage::Update(CRectangle plrect) {


	//�w�i�J�E���g
	if (m_BakScroll <= 0) {

		if (m_BakScroll == 0) {

			//todo�F�O�̎��ɒ�~����Ɣw�i���ꖇ���ς���Ă��܂��̂������
			//�o�V�o�V��N����Ȃ�����
			//return;
		}
		//�w�i�J�E���g
		m_countbak += 1;


		//������
		m_BakScroll = m_BakStart.GetWidth();

	}

	if (m_countbak == (MAP_SP_START_PATTERN*2)+1&& SP_flg) {
		m_SPSitua = tag_StageSituation::STAGE_SP_STILL;
	}

	//�ꎞ�I�Ȓǉ��ł�
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT)) {
		m_Scroll_Speed +=10;
	}

	//�ꎞ�I�Ȓǉ��ł�
	if (g_pInput->IsKeyPush(MOFKEY_LEFT)) {
		m_Scroll_Speed -= 10;
	}

	//�X�N���[���l����萔������ƁA�A�C�R���̈ړ��ʂ����Z����
	int i = m_StageScroll;
	if (i % 9 == 0)
	{
		m_BarProgress++;
	}

	//�N���A�t���O�ύX
	if (m_countbak == 32) {
		m_bClear = true;
	}
	else
	{

		//���ɉ�����
		m_BakScroll -= m_Scroll_Speed;

	}

	//�X�e�[�W�����p�X�N���[���l
	m_StageScroll += m_Scroll_Speed;

	//�X�e�[�W�X�N���[���l
	if (m_StageScroll >=g_pGraphics->GetTargetWidth()*2)
	{
		//�X�N���[���l���Z�b�g

		m_StageScroll = 0;

	}

	//�}�b�v�p�^�[���̐؂�ւ�
	MapChange();

	//����X���W�̏ꍇ�̔���
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		//���ꐶ��
		OccurrenceBar();
	}

	//����X���W�̏ꍇ�̔���
	for (int i = 0; i < DP_VOLUME; i++)
	{
		//�f�B�e�[���|�C���g����
		OccurrenceDP();
	}

	//����X���W�̏ꍇ�̔���
	for (int i = 0; i < OB_VOLUME; i++)
	{
		//��Q��OB����
		OccurrenceOB();
	}

	//����X���W�̏ꍇ�̔���
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		//�G����
		OccurrenceENE();
	}

	//����X�V
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].Update(m_Scroll_Speed);
	}

	//DP�X�V
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Update(m_Scroll_Speed);
	}

	//��Q���X�V
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Update(m_Scroll_Speed);
	}
	
	//�G�X�V
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].Update(m_Scroll_Speed);
	}

	//SP���̏���
	if (m_SPSitua == tag_StageSituation::STAGE_SP_STILL)
	{
		//SP�̔w�i�J�E���g
		if (m_BakScroll <= 0)
		{
			//SP�w�i�J�E���g
			m_SPcountbak += 1;
		}
		//SP�w�i�J�E���g
		if (m_SPcountbak == (MAP_SP_LENGTH*2))
		{
 			m_SPSitua = tag_StageSituation::STAGE_SP_YET;
		}

	}

}





//�`��
void CStage::Render(void) {


	//�e�N�X�`���̕`��
	//�����g���Ă邯�ǔz��Ƃ��ł���������
	//�����e�N�X�`�����J��Ԃ��ŉ�ʒ[�𒴂���܂ōs��
	int h = m_BakStart.GetWidth();
	int sch = g_pGraphics->GetTargetWidth();

	//���̔w�i��p��
	if (m_BakScroll <= 0) {

		//�E���ŕ\�����Ă������̂Ɠ������̂������ŕ\��
		m_RandamuBakLeft = m_RandamuBakRight;

		//�E���̓����_���ɐ��l������
		m_RandamuBakRight = m_BakComposition[m_countbak];

	}

	//�w�i�X�N���[���l���w�i�摜�̉����F���񂾂񌸂�
	//�����lX:�w�i�X�N���[���l/�w�i�����̂��܂�����w�i���� 
	//����	�FX����ʉ��������������ꍇ
	//�����ʁFX�{���w�i����
	for (float x = ((int)m_BakScroll % h) - h; x < sch; x += h) {

		//�����Ă����摜
		if (x <= 0)
		{
			//�ŏ��ƍŌ�ȊO�̒��Ԃ𖄂߂�w�i
			switch (m_RandamuBakLeft)
			{

				case 1:
					m_BakRdoor.Render(x, 0.0f,MOF_ARGB(m_BakAVal,255,255,255));
					break;

				case 2:
					m_BakRwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 3:
					m_Bakldoor.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 4:
					m_Baklwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 5:
					m_BakWindow.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 6:
					m_BakStairs.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 7:
					m_BakStart.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 8:
					m_BakEnd.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 9:
					m_SPBak_Start.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 10:
					m_SPBak_1.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 11:
					m_SPBak_2.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				case 13:
					m_SPBak_End.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
					break;

				default:
					break;

			}

		}
		else//�o�Ă���摜
		{
			
			//�ŏ��ƍŌ�ȊO�̒��Ԃ𖄂߂�w�i
			switch (m_RandamuBakRight)
			{

			case 1:
				m_BakRdoor.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 2:
				m_BakRwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 3:
				m_Bakldoor.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 4:
				m_Baklwall.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 5:
				m_BakWindow.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 6:
				m_BakStairs.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 7:
				m_BakStart.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 8:
				m_BakEnd.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 9:
				m_SPBak_Start.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 10:
				m_SPBak_1.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 11:
				m_SPBak_2.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			case 13:
				m_SPBak_End.Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
				break;

			default:
				break;

			}

		}
	}


	//����`��
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].Render();
	}


	//��Q��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].Render();
	}

	//�|�C���g�`��
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Render();
	}

	//�G�`��
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].Render();
	}


	//�w�N�̃J�b�g�C��
	m_GradeOneTexture.Render(0 + m_GradeOffset, 50);
	m_GradeTwoTexture.Render(0 + m_GradeOffset, 50);
	m_GradeThreeTexture.Render(0 + m_GradeOffset, 50);


	//�i�s�x�o�[�A�i�s�x���A�C�R���A�A�C�R���̕\��
	m_BarTextuer.Render(270, 25);
	m_CharaProgressTextuer.Render(285 + m_BarProgress, 45);

}

//���
void CStage::Release(void) {

	//�i�s�x�o�[�A�i�s�x���A�C�R���A�A�C�R���̉��
	m_BarTextuer.Release();
	m_CharaProgressTextuer.Release();
	m_CharaIconTexture.Release();
	//�w�N�摜�̊J��
	m_GradeOneTexture.Release();
	m_GradeTwoTexture.Release();
	m_GradeThreeTexture.Release();

	//�X�e�[�W�w�i
	m_BakStart.Release();
	m_BakRdoor.Release();
	m_BakRwall.Release();
	m_Bakldoor.Release();
	m_Baklwall.Release();
	m_BakWindow.Release();
	m_BakStairs.Release();
	m_BakEnd.Release();
	m_SPBak_Start.Release();
	m_SPBak_1.Release();
	m_SPBak_2.Release();
	m_SPBak_End.Release();

	//DP�e�N�X�`��
	dp_Textuer_Scholastic.Release();
	dp_Textuer_Action.Release();
	dp_Textuer_Imagination.Release();
	dp_Textuer_Communication.Release();
	dp_Textuer_Charm.Release();

	//��Q���e�N�X�`��
	ob_Textuer_Desk.Release();
	ob_Textuer_TwoDesk.Release();
	ob_Textuer_TrachCan.Release();
	ob_Textuer_Locker.Release();
	ob_Textuer_TextBookNL.Release();
	ob_Textuer_TextBookMATH.Release();
	ob_Textuer_TextBookCHEM.Release();
	ob_Textuer_TextBookSOC.Release();
	ob_Textuer_TextBookENG.Release();
	ob_Textuer_VaultingHorse.Release();
	ob_Textuer_ScotchTape.Release();
	ob_Textuer_BloackboardEraser.Release();
	ob_Seaweed.Release();
	ob_Smartphone1.Release();
	ob_Eraser.Release();
	ob_SmartphoneVertical.Release();

	//����e�N�X�`��
	bar_Textuer_Medium.Release();
	bar_Textuer_Big.Release();

	//�G�e�N�X�`��
	ene_Texture_1.Release();
	ene_Texture_2.Release();

}

//�f�o�b�N�`��
void CStage::RenderDebugging() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "�w�i�F%d����", m_countbak);
	//CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "�w�i�X�N���[���l%f", m_BakScroll);
	//CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "�X�e�[�W�X�N���[���l%f", m_StageScroll);

	//�S�̂̃p�^�[���\��
	for (int i = 0; i < 15; i++)
	{
		CGraphicsUtilities::RenderString(40*i, 680, "%d", m_StageComposition[i]);
	}

	//��Q���f�o�b�O�\��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].RenderDebugging();
	}

	for (int i = 0; i < OB_VOLUME; i++)
	{
		dp_array[i].RenderDebugging();
	}


	//����`��
	for (int i = 0; i < BAR_VOLUME; i++)
	{
		b_bar[i].RenderDebugging();
	}

	//�G
	for (int i = 0; i < ENEMY_VOLUME; i++)
	{
		ene_array[i].RenderDebug();
	}


	CGraphicsUtilities::RenderLine(m_BakScroll,0, m_BakScroll,g_pGraphics->GetTargetHeight(), MOF_COLOR_BLUE);

#pragma region �p�^�[���f�o�b�O�p

	CGraphicsUtilities::RenderString(40, 650, "%d", m_StageComposition[m_MapNo]);

	if (SP_flg) {
	CGraphicsUtilities::RenderString(40, 620, "SP�F����");

	}
	else
	{
		CGraphicsUtilities::RenderString(40, 620, "SP�F�Ȃ�");

	}
	
	CGraphicsUtilities::RenderString(40, 590, "%d", m_SPcountbak);

#pragma endregion

	//�N���A�t���O�\��
	if (m_bClear)
	{
		//CGraphicsUtilities::RenderString(500, 350, MOF_XRGB(255, 0, 0), "�N���A!\nF1�Ń��X�^�[�g");
	}

}

//�}�b�v�p�^�[���؂�ւ�
void CStage::MapChange(void) {

	//�X�N���[�����؂�ւ�鎞�����ꂼ��̃}�b�v�p�^�[�����ŏI�[�v�f�ɂ��ǂ蒅���Ă���Ȃ�
	if (m_StageScroll <= 0 &&
		s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Type >= BAR_COUNT &&
		s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Type == DP_COUNT &&
		s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type >= OB_COUNT&&
		s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Type >= ENEMY_COUNT)
	{
		m_barcount = 0;
		m_dpcount = 0;
		m_obcount = 0;
		m_enecount = 0;
		m_MapNo += 1;

		//�Ō�̃}�b�v����p�^�[�����̏ꍇ
		if (m_MapNo >= 15)
		{
			m_MapNo = 100;
		}
	}
}

//���ꐶ��
void CStage::OccurrenceBar(void) {


	//m_MapNo_Bar->�}�b�v�p�^�[���ԍ�
	//m_obcount->�\���ςݑ��ꐔ
	//�}�b�v�p�^�[���ԍ����p�ӂ��Ă��鐔�ȉ��̂Ƃ�����
	//�X�N���[���l���o���l�����������Ȃ����ꍇ�\��
	//�X�N���[���l���v���X�ɕύX���܂���
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�����N���X��T��
		for (int i = 0; i < BAR_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (b_bar[i].Getshow()) {
				continue;
			}

			//�\���e�N�X�`������
			//�o���ʒu�ƃ^�C�v��n��
			switch (s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Type)
			{

			case BAR_BIG:
				b_bar[i].SetTexture(&bar_Textuer_Big);
				break;

			case BAR_MEDIUM:
				b_bar[i].SetTexture(&bar_Textuer_Medium);
				break;
			default:
				break;
			}


			//�\������
			//�o���ʒu�ƃ^�C�v��n��
			b_bar[i].Start(s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Pos_y,
				s_stageBAR[m_StageComposition[m_MapNo]][m_barcount].Type);
			break;
		}

		//�\���ςݑ�������Z
		m_barcount++;

	}

}

//�f�B�e�[���|�C���g����
void CStage::OccurrenceDP(void) {


	//m_MapNo_DP->�}�b�v�p�^�[���ԍ�
	//m_dpcount->�\���ς�DP��
	//�}�b�vDP�p�^�[���ԍ����p�ӂ��Ă��鐔�ȉ��̂Ƃ�����
	//�X�N���[���l���o���l�����������Ȃ����ꍇ�\��
	//�X�N���[���l���v���X�ɕύX���܂���
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�DP�N���X��T��
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (dp_array[i].Getshow()) {
				continue;
			}

			int type= DP_SCHOLASTIC;

			if (SP_flg&&m_SPSitua== tag_StageSituation ::STAGE_SP_STILL) {

				//SP����SP����DP�ɕϊ�
				type = DP_Deci_Type + 6;
			}
			else
			{
				//�\�����̃^�C�v���Q��
				type = s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Type;
			}

			//�\���e�N�X�`������
			//�o���ʒu�ƃ^�C�v��n��
			switch (type)
			{

			case DP_SCHOLASTIC:
				dp_array[i].SetTexture(&dp_Textuer_Scholastic);
				break;

			case DP_ACTION:
				dp_array[i].SetTexture(&dp_Textuer_Action);
				break;

			case DP_IMAGINATION:
				dp_array[i].SetTexture(&dp_Textuer_Imagination);
				break;

			case DP_COMMUNICATION:
				dp_array[i].SetTexture(&dp_Textuer_Communication);
				break;

			case DP_CHARM:
				dp_array[i].SetTexture(&dp_Textuer_Charm);
				break;

			case DP_SP_SCHOLASTIC:
				dp_array[i].SetTexture(&dp_Textuer_Scholastic);
				break;

			case DP_SP_ACTION:
				dp_array[i].SetTexture(&dp_Textuer_Action);
				break;

			case DP_SP_IMAGINATION:
				dp_array[i].SetTexture(&dp_Textuer_Imagination);
				break;

			case DP_SP_COMMUNICATION:
				dp_array[i].SetTexture(&dp_Textuer_Communication);
				break;

			case DP_SP_CHARM:
				dp_array[i].SetTexture(&dp_Textuer_Charm);
				break;

			default:
				break;
			}
			dp_array[i].Start(s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Pos_y, type);
			break;
		}

		//�\���ς�DP�����Z
		m_dpcount++;

	}

}

//��Q��OB����
void CStage::OccurrenceOB(void) {

	//m_MapNo_OB->�}�b�v�p�^�[���ԍ�
	//m_obcount->�\���ς�DP��
	//�}�b�v�p�^�[���ԍ����p�ӂ��Ă��鐔�ȉ��̂Ƃ�����
	//�X�N���[���l���o���l�����������Ȃ����ꍇ�\��
	//�X�N���[���l���v���X�ɕύX���܂���
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�DP�N���X��T��
		for (int i = 0; i < OB_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (ob_array[i].Getshow()) {
				continue;
			}

			//�\���e�N�X�`������
			//�o���ʒu�ƃ^�C�v��n��
			switch (s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type)
			{

			case OB_DESK:
				ob_array[i].SetTexture(&ob_Textuer_Desk);
				break;

			case OB_TWODESK:
 				ob_array[i].SetTexture(&ob_Textuer_TwoDesk);
				break;

			case OB_TRACHCAN:
				ob_array[i].SetTexture(&ob_Textuer_TrachCan);
				break;

			case OB_LOCKER:
				ob_array[i].SetTexture(&ob_Textuer_Locker);
				break;

			case OB_TEXTBOOKNL:
				ob_array[i].SetTexture(&ob_Textuer_TextBookNL);
				break;

			case OB_TEXTBOOKMATH:
				ob_array[i].SetTexture(&ob_Textuer_TextBookMATH);
				break;

			case OB_TEXTBOOKCHEM:
				ob_array[i].SetTexture(&ob_Textuer_TextBookCHEM);
				break;

			case OB_TEXTBOOKSOC:
				ob_array[i].SetTexture(&ob_Textuer_TextBookSOC);
				break;

			case OB_TEXTBOOKENG:
				ob_array[i].SetTexture(&ob_Textuer_TextBookENG);
				break;

			case OB_VAULTINGHORSE:
				ob_array[i].SetTexture(&ob_Textuer_VaultingHorse);
				break;

			case OB_SCOTCHTAPE:
				ob_array[i].SetTexture(&ob_Textuer_ScotchTape);
				break;

			case OB_BLOACKBOARDERASER:
				ob_array[i].SetTexture(&ob_Textuer_BloackboardEraser);
				break;

			case OB_SEAWEED:
				ob_array[i].SetTexture(&ob_Seaweed);
				break;

			case OB_SMARTPHONE1:
				ob_array[i].SetTexture(&ob_Smartphone1);
				break;

			case OB_ERASER:
				ob_array[i].SetTexture(&ob_Eraser);
				break;

			case OB_SMARTPHONEVERTICAL:
				ob_array[i].SetTexture(&ob_SmartphoneVertical);
				break;

			default:
				break;
			}


			//�\������
			//�o���ʒu�ƃ^�C�v��n��
			ob_array[i].Start(s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Pos_y,
				s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type);
			break;
		}

		//�\���ς�DP�����Z
		m_obcount++;

	}

}

//�G����
void CStage::OccurrenceENE(void)
{
	if (m_MapNo < SATAGE_MAP_PATTERN && m_StageScroll > s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�ENE�N���X��T��
		for (int i = 0; i < ENEMY_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (ene_array[i].Getshow()) {
				continue;
			}

			//�\���e�N�X�`������
			ene_array[i].SetTexture(&ene_Texture_1);
			ene_array[i].SetAnime(&Enemy_Motion);
			ene_array[i].Start(s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Pos_y, s_stageENEMY[m_StageComposition[m_MapNo]][m_enecount].Type);

			break;
		}

		//�\���ς�DP�����Z
		m_enecount++;

	}
}

//�Q�[���X�^�[�g�؂�ւ�
void CStage::GameStopPlayChange()
{
	if (m_Startflg) {

		m_Startflg = false;
		m_Scroll_Speed = 0;

	}
	else
	{
		m_Startflg = true;
		m_Scroll_Speed = STAGE_SPEED;
	}
}

//�L�����������Ă��邩�擾
bool CStage::GetGameStopPlay() {

	return m_Startflg;

}

//�N���A����̎擾
bool CStage::GetClear(void) {
	return m_bClear;
}

