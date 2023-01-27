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
	m_BakTex(),
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
	m_RandamuBakRightSave(),
	m_Scroll_Speed(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

	//�X�e�[�W�w�i���[�h
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("StageBak");

	char* Bakname[STAGE_BAKT_COUNT] =
	{
		"HallStart.png",
		"Door_R.png",
		"Wall_R.png",
		"Door_L.png",
		"Wall_L.png",
		"Stairs.png",
		"Window_2.png",
		"HallEnd.png",
		"SPStart.png",
		"SP1.png",
		"SP2.png",
		"SPEnd.png",
	};

	//�X�e�[�W�w�i���[�h
	for (int i = 0; i < STAGE_BAKT_COUNT; i++)
	{
		if (!m_BakTex[i].Load(Bakname[i])) {
			return false;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");


	//DP�e�N�X�`�����[�h
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("DetailPoint");

	char* DPname[DP_COUNT] =
	{
		"DPScholastic.png",
		"DPAction.png",
		"DPImagination.png",
		"DPCommunication.png",
		"DPCharm.png",
	};

	for (int i = 0; i < DP_COUNT; i++)
	{
		if (!m_DPTex[i].Load(DPname[i])) {
			return false;
		}
	}
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");


	//��Q���e�N�X�`�����[�h
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Obstacle");

	char* OBname[OB_COUNT] =
	{
		"TrachCan.png",
		"Locker.png",
		"TextBookNL.png",
		"TextBookMATH.png",
		"TextBookCHEM.png",
		"TextBookSOC.png",
		"TextBookENG.png",
		"VaultingHorse.png",
		"ScotchTape.png",
		"BloackboardEraser.png",
		"Seaweed.png",
		"Smartphone1.png",
		"Eraser.png",
		"SmartphoneVertical.png",
	};

	for (int i = 0; i < OB_COUNT; i++)
	{
		ob_Textuer[i].Load(OBname[i]);
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

	//�R�}��
	float Encoma = 4;
	//�i��
	MofS32 Enedan = 4;
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

#pragma endregion

	//todo���[�h
	if (!m_DPDEcisionTexture.Load("mokuhixyou_souzourixyoku.png")) {
		return false;
	}

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

	//�}�b�v�p�^�[���Y����
	m_MapNo = 0;

	//������
	m_AdoptCount = 0;

	//�X�e�[�W�\�����Z�b�g
	//��m���œ����X�e�[�W���I������Ă��܂����ߎ��s�񐔂͑���
	for (int z = 1; z < 1000; z++)
	{
		//1�Q�[�����̃X�e�[�W���p�ӏo������I��
		if (m_AdoptCount >= SATAGE_MAP_PATTERN) {
			break;
		}

		for (int x = 0; x < MAP_INFO_PATTERN; x++)
		{
			if (m_AlreadyUsedArray[x] == 1)
			{
				//�ǂ��܂ō̗p�ς݂��J�E���g
				m_AdoptCount += 1;
			}
		}

		//SP�}�b�v���̗p
		if (m_AdoptCount == MAP_SP_START_PATTERN && SP_flg)
		{
			//SP�̗p��
			int SPAdopCount = 0;

			//SP�}�b�v�p�^�[�����Z�b�g
			for (int i = 0; i < 100; i++)
			{
				//�����_������
				int SPrandmu = RandmuBak.GetRandomNumbe(15, 16);

				//�d�l�ς݂łȂ��ꍇ
				if (m_AlreadyUsedArray[SPrandmu] == 0) {

					//SP�X�e�[�W�Z�b�g
					m_StageComposition[m_AdoptCount+ SPAdopCount] = SPrandmu;
					//����
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
			//�ʏ�X�e�[�W�̒����烉���_���p�^�[�����Z�b�g
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

	//�Ō�̃}�b�v�ԍ�
	m_StageComposition[15] = MAP_INFO_PATTERN-1;

	//�w�i�\�������߂鏈��
	for (int i = 0; i < SATAGE_MAP_PATTERN*2; i++)
	{
		//�����_���Ŏ�ނ����肷��
		int randamu=RandmuBak.GetRandomNumbe(STAGE_BAKT_RDOOR, STAGE_BAKT_SRAIRS);

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
	m_BakComposition[SATAGE_MAP_PATTERN * 2] = STAGE_BAKT_END;

	//�E������w�i�\����ǂނ��߂̏�����
	//��ԍŏ��̔w�i
	m_RandamuBakRight = STAGE_BAKT_START;
	m_RandamuBakLeft = m_BakComposition[0];

	//�X�y�V�����X�e�[�W����������ꍇ
	//�w�i���X�y�V�����X�e�[�W�ɕύX����
	if (SP_flg) {

		//SP�J�n�ʒu��SP�X�e�[�W�J�n�w�i���Z�b�g
		m_BakComposition[(MAP_SP_START_PATTERN * 2)] = STAGE_BAKT_SPSTART;

		for (int i = 1; i < MAP_SP_LENGTH * 2; i++)
		{
			//SP�X�e�[�W�w�i�������_���ŃZ�b�g
			m_BakComposition[(MAP_SP_START_PATTERN * 2) + i] = RandmuBak.GetRandomNumbe(STAGE_BAKT_SP1, STAGE_BAKT_SP2);
		}

		//SP�X�e�[�W�I���w�i���Z�b�g
		m_BakComposition[(MAP_SP_START_PATTERN * 2)+(MAP_SP_LENGTH*2)-1] = STAGE_BAKT_SPEND;
	}

	//�g�p�ςݔw�i�L�^��������
	for (int i = 0; i < MAP_INFO_PATTERN; i++)
	{
		m_AlreadyUsedArray[i] = 0;
	}


	//�f�o�b�O�p�̃X�e�[�W�w��R�}���h�A�K�v�ɉ����Ă������Ă�������
	//m_StageComposition[0] = 0;
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

//�X�V
//plrect:�v���C���[�̓����蔻���`
void CStage::Update(CRectangle plrect) {


	//�w�i�J�E���g
	if (m_BakScroll <= 0) {

		//�w�i�J�E���g
		m_countbak += 1;

		//������
		m_BakScroll = m_BakTex[0].GetWidth();

	}

	//�X�e�[�W���x�ύX
	//��N�J�n��
	if (m_countbak == 10) {
		m_Scroll_Speed = STAGE_SPEED2;
	}

	//�O�N�J�n��
	if (m_countbak == 20) {
		m_Scroll_Speed = STAGE_SPEED3;
	}

	//SP�X�e�[�W�J�n
	if (m_countbak == (MAP_SP_START_PATTERN * 2) + 1 && SP_flg) {
		m_SPSitua = tag_StageSituation::STAGE_SP_STILL;
	}


	//�摜��:1280 ����:31 �i�s�o�[:680   1280*31/680=58
	if (m_BarProgressCount + 58 < m_StageScroll) {
		m_BarProgress++;
		m_BarProgressCount = m_StageScroll;
	}
	//m_StageScroll�����Z�b�g���ꂽ�Ƃ�
	else if (m_BarProgressCount >= m_StageScroll) {
		m_BarProgressCount = 0;
	}									//2560�͉摜����2
	else if (m_BarProgressCount + 58 >= 2560) {
		m_BarProgressCount = m_BarProgressCount + 58 - 2560;
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

	//����X���W�̏ꍇ�̕����񔻒�
	for (int i = 0; i < 3; i++)
	{
		//���ꐶ��
		OccurrenceBar();
	}


	//����X���W�̏ꍇ�̕����񔻒�
	for (int i = 0; i < 10; i++)
	{
		//�f�B�e�[���|�C���g����
		OccurrenceDP();
	}

	//����X���W�̏ꍇ�̕����񔻒�
	for (int i = 0; i < 5; i++)
	{
		//��Q��OB����
		OccurrenceOB();
	}

	//����X���W�̏ꍇ�̕����񔻒�
	for (int i = 0; i < 3; i++)
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

void CStage::UpdateDebug(void)
{
	//�ꎞ�I�Ȓǉ��ł�
	if (g_pInput->IsKeyPush(MOFKEY_RIGHT)) {
		m_Scroll_Speed += 10;
	}

	//�ꎞ�I�Ȓǉ��ł�
	if (g_pInput->IsKeyPush(MOFKEY_LEFT)) {
		m_Scroll_Speed -= 10;
	}

}





//�`��
void CStage::Render(void) {


	//�e�N�X�`���̕`��
	//�����g���Ă邯�ǔz��Ƃ��ł���������
	//�����e�N�X�`�����J��Ԃ��ŉ�ʒ[�𒴂���܂ōs��
	int h = m_BakTex[0].GetWidth();
	int sch = g_pGraphics->GetTargetWidth();

	//���̔w�i��p��
	if (m_BakScroll <= 0) {

		//�E���ŕ\�����Ă������̂Ɠ������̂������ŕ\��
		m_RandamuBakLeft = m_RandamuBakRight;

		//�ꎞ�ۑ�
		m_RandamuBakRightSave = m_RandamuBakRight;

		//�E���Ɏ��̔w�i�ԍ�������
		m_RandamuBakRight = m_BakComposition[m_countbak];

		//0�Œ�~�����ꍇ�̔w�i�o�O�̌y��
		//0�Ŏ~�܂���,
		//�Ō�̔w�i�ȊO
		if (m_BakScroll == 0 && m_countbak < 30) {

			//�ۑ��������̂��̗p
			m_RandamuBakRight = m_RandamuBakRightSave;

		}
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
			m_BakTex[m_RandamuBakLeft].Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));
		}
		else//�o�Ă���摜
		{			
			//�ŏ��ƍŌ�ȊO�̒��Ԃ𖄂߂�w�i
			m_BakTex[m_RandamuBakRight].Render(x, 0.0f, MOF_ARGB(m_BakAVal, 255, 255, 255));		
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

	//todo�\��
	m_DPDEcisionTexture.Render(0, 0);

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

	for (int i = 0; i < STAGE_BAKT_COUNT; i++)
	{
		m_BakTex[i].Release();
	}

	//DP�e�N�X�`��
	for (int i = 0; i < DP_COUNT; i++)
	{
		m_DPTex[i].Release();
	}

	//��Q���e�N�X�`��
	for (int i = 0; i < OB_COUNT; i++)
	{
		ob_Textuer[i].Release();
	}

	//����e�N�X�`��
	bar_Textuer_Medium.Release();
	bar_Textuer_Big.Release();

	//�G�e�N�X�`��
	ene_Texture_1.Release();

	//todo ���
	m_DPDEcisionTexture.Release();
}

//�f�o�b�N�`��
void CStage::RenderDebugging() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "�w�i�F%d����", m_countbak);
	//CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "�w�i�X�N���[���l%f", m_BakScroll);
	//CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "�X�e�[�W�X�N���[���l%f", m_StageScroll);

	//�S�̂̃p�^�[���\��
	for (int i = 0; i < SATAGE_MAP_PATTERN+1; i++)
	{
		CGraphicsUtilities::RenderString(40*i, 680, "%d", m_StageComposition[i]);
	}

	//��Q���f�o�b�O�\��
	for (int i = 0; i < OB_VOLUME; i++)
	{
		ob_array[i].RenderDebugging();
	}

	//DP�f�o�b�N�\��
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
		//�\���ς݃J�E���g������
		m_barcount = 0;
		m_dpcount = 0;
		m_obcount = 0;
		m_enecount = 0;

		//�}�b�v�ԍ�������
		m_MapNo += 1;

		//�Ō�̃}�b�v����p�^�[�����̏ꍇ
		if (m_MapNo >= 15)
		{
			m_MapNo = 15;
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

			//������
			int type= DP_SCHOLASTIC;
			if (SP_flg && m_SPSitua == tag_StageSituation::STAGE_SP_STILL) {

				//SP����DP�I����ʂɕϊ�
				type = DP_Deci_Type;
			}
			else
			{
				//�\�����̃^�C�v���Q��
				type = s_stageDP[m_StageComposition[m_MapNo]][m_dpcount].Type;
			}

			

			//�\���e�N�X�`������
			//�o���ʒu�ƃ^�C�v��n��
			dp_array[i].SetTexture(&m_DPTex[type]);
			if (SP_flg && m_SPSitua == tag_StageSituation::STAGE_SP_STILL) {

				//SP����SPDP�ɕϊ�
				type = DP_Deci_Type + 6;
			}

			//����
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
			ob_array[i].SetTexture(&ob_Textuer[s_stageOB[m_StageComposition[m_MapNo]][m_obcount].Type]);


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
		m_Scroll_Speed = STAGE_SPEED1;
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

