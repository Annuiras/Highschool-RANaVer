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
	m_BakStart(),
	m_SPBak(),
	m_dpinfo(),
	m_dpcount(0),
	m_barinfo(),
	m_barvolume(0),
	m_barcount(0),
	m_obinfo(),
	m_obcount(0),
	m_BakScroll(0.0f),
	m_StageScroll(0.0f),
	m_spflg(false),
	m_gaku(0),
	m_sou(0),
	m_kou(0),
	m_komyu(0),
	m_miryoku(0),
	m_bClear(false),
	m_baklineX(0.0f)
{}

CStage::~CStage() {

}

bool CStage::Load() {

	//�w�i�摜�̓ǂݍ���
	if (!m_BakStart.Load("�L���n�܂�.png")) {
		return false;
	}

	if (!m_BakRdoor.Load("�E��.png")) {
		return false;
	}

	if (!m_BakRwall.Load("�E��.png")) {
		return false;
	}

	if (!m_Bakldoor.Load("����.png")) {
		return false;
	}

	if (!m_Baklwall.Load("����.png")) {
		return false;
	}

	if (!m_BakStairs.Load("�K�i.png")) {
		return false;
	}

	if (!m_BakWindow.Load("��.png")) {
		return false;
	}

	if (!m_BakEnd.Load("�L���I���.png")) {
		return false;
	}

	if (!m_SPBak.Load("SPbak.png")) {
		return false;
	}


	for (int i = 0; i < DP_VOLUME; i++)
	{
		if (!dp_array[i].Load()) {

			return false;
		}
	}

	return true;
}


//dpin:DP�z�u���
//dpco:DP�z�u���
//barin:����̔z�u���
//barco:����̏��
//obin:��Q���̔z�u���
//obco:��Q���̏��
void CStage::Initialize(DP_info dpin[][DP_INFO_STRUCT], BAR_info barin[][BAR_INFO_STRUCT], OB_info obin[][OB_INFO_STRUCT]) {
	//�X�N���[���l������
	m_BakScroll = 0.0f;

	//todo:�X�e�[�W�X�N���[���l�������v���X�̒l�ɕύX���܂���
	//todo:����F�O����X�^�[�g
	m_StageScroll = g_pGraphics->GetTargetWidth()*2;

	//�w�i�J�E���g������
	m_countbak = 0;

	//todo:�N���A�p�X�N���[���l������
	m_Scroll_Clear = 0;


	//todo:�}�b�vDP�p�^�[�������_���ɏ�����
	for (int y = 0; y < DP_INFO_PATTERN; y++)
	{
		m_StageDPConstitution[y] = RandmuBak.GetRandomNumbe(0, 14);
	}

	//todo:�f�o�b�O�p�̎w��R�}���h�A�K�v�ɉ����Ă������Ă�������
	m_StageDPConstitution[0] = 0;
	m_StageDPConstitution[1] = 1;
	m_StageDPConstitution[2] = 2;
	m_StageDPConstitution[3] = 3;
	m_StageDPConstitution[4] = 4;
	m_StageDPConstitution[5] = 5;
	m_StageDPConstitution[6] = 6;
	m_StageDPConstitution[7] = 7;
	m_StageDPConstitution[8] = 8;
	m_StageDPConstitution[9] = 9;
	m_StageDPConstitution[10] = 10;
	m_StageDPConstitution[11] = 11;
	m_StageDPConstitution[12] = 12;
	m_StageDPConstitution[13] = 13;
	m_StageDPConstitution[14] = 14;

	//todo:�}�b�vDP�p�^�[���Y����������
	m_MapNo_DP = 0;

	//todo:DP�z�u���R�s�[�����Ŏ󂯎��ꍇ�̏����Ȃ̂łȂ��Ȃ�\������
	//�}�b�v�ꖇ�̏��
	for (int y = 0; y < DP_INFO_PATTERN; y++)
	{
		//�}�b�v�ꖇ���̏��ɍ\����
		for (int x = 0; x < DP_INFO_STRUCT; x++) {


			m_dpinfo[y][x] = dpin[y][x];
		}
	}


	//todo:�}�b�vOB�p�^�[�������_���ɏ�����
	for (int y = 0; y < OB_INFO_PATTERN; y++)
	{
		m_StageOBConstitution[y] = RandmuBak.GetRandomNumbe(0, 14);
	}

	//todo:�f�o�b�O�p�̎w��R�}���h�A�K�v�ɉ����Ă������Ă�������
	m_StageOBConstitution[0] = 0;
	m_StageOBConstitution[1] = 1;
	m_StageOBConstitution[2] = 2;
	m_StageOBConstitution[3] = 3;
	m_StageOBConstitution[4] = 4;
	m_StageOBConstitution[5] = 5;
	m_StageOBConstitution[6] = 6;
	m_StageOBConstitution[7] = 7;
	m_StageOBConstitution[8] = 8;
	m_StageOBConstitution[9] = 9;
	m_StageOBConstitution[10] = 10;
	m_StageOBConstitution[11] = 11;
	m_StageOBConstitution[12] = 12;
	m_StageOBConstitution[13] = 13;
	m_StageOBConstitution[14] = 14;

	//todo:�}�b�vOB�p�^�[���Y����������
	m_MapNo_OB = 0;

	//��Q���z�u���
	//todo:��Q���z�u���R�s�[�����Ŏ󂯎��ꍇ�̏����Ȃ̂łȂ��Ȃ�\������
	//�}�b�v�ꖇ�̏��
	for (int y = 0; y < OB_INFO_PATTERN; y++)
	{
		//�}�b�v�ꖇ���̏��ɍ\����
		for (int x = 0; x < OB_INFO_STRUCT; x++) {


			m_obinfo[y][x] = obin[y][x];
		}
	}


	//todo:�}�b�v����p�^�[�������_���ɏ�����
	for (int y = 0; y < BAR_INFO_PATTERN; y++)
	{
		m_StageBarConstitution[y] = RandmuBak.GetRandomNumbe(0, 14);
	}

	//todo:�f�o�b�O�p�̎w��R�}���h�A�K�v�ɉ����Ă������Ă�������
	m_StageBarConstitution[0] = 0;
	m_StageBarConstitution[1] = 1;
	m_StageBarConstitution[2] = 2;
	m_StageBarConstitution[3] = 3;
	m_StageBarConstitution[4] = 4;
	m_StageBarConstitution[5] = 5;
	m_StageBarConstitution[6] = 6;
	m_StageBarConstitution[7] = 7;
	m_StageBarConstitution[8] = 8;
	m_StageBarConstitution[9] = 9;
	m_StageBarConstitution[10] = 10;
	m_StageBarConstitution[11] = 11;
	m_StageBarConstitution[12] = 12;
	m_StageBarConstitution[13] = 13;
	m_StageBarConstitution[14] = 14;

	//todo:�}�b�vOB�p�^�[���Y����������
	m_MapNo_Bar = 0;


	//todo:����z�u���R�s�[�����Ŏ󂯎��ꍇ�̏����Ȃ̂łȂ��Ȃ�\������
	//�}�b�v�ꖇ�̏��
	for (int y = 0; y < BAR_INFO_PATTERN; y++)
	{
		//�}�b�v�ꖇ���̏��ɍ\����
		for (int x = 0; x < BAR_INFO_STRUCT; x++) {

			m_barinfo[y][x] = barin[y][x];
		}
	}



	//�\���ς݃J�E���g������
	m_barcount = 0;
	m_dpcount = 0;
	m_obcount = 0;

	//�N���A�t���O������
	m_bClear = false;

	//�w�i�p�����_�����l������
	m_RandamuBakLeft = RandmuBak.GetRandomNumbe(1, 6); 
	m_RandamuBakRight = 0;

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

	g_ground.Initialize();

}

//�X�V
//over:�L�����N�^�[�̃I�[�o�[�l
//plrect:�v���C���[�̓����蔻���`
//pl2:�X�L���G�z���񂹔͈͋�`
//suckingX,suckingY:�v���C���[��XY���W
void CStage::Update(float over, CRectangle plrect,CRectangle pl2, float suckingX, float suckingY) {

	//�w�i�J�E���g
	if (m_BakScroll <= 0) {

		//������
		m_BakScroll = m_BakStart.GetWidth();

		//�w�i�J�E���g
		m_countbak += 1;

		m_spflg = false;

		//SP�t���O�n�m
		if (m_countbak == 2) {
			m_spflg = true;
		}
	}


	//�v���C���[�̃I�[�o�[�������������ɉ�����
	m_BakScroll -= over;

	//todo:����X�e�[�W�����p�X�N���[���l
	m_StageScroll += over;


	m_Scroll_Clear += over;

	//�X�e�[�W�X�N���[���l
	if (m_StageScroll >=g_pGraphics->GetTargetWidth()*2)
	{
		//todo:����X�N���[���l���Z�b�g

		m_StageScroll = 0;

	}

	//���ꐶ��
	OccurrenceBar();

	//�f�B�e�[���|�C���g����
	OccurrenceDP();

	//��Q��OB����
	OccurrenceOB();

	//����
	for (int i = 0; i < BAR_VOLUME; i++)
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

		//DP�Ƌz�����ݔ����`
		if (dp_array[i].CollosopnDP(pl2)) {

			dp_array[i].UpdateAtraction(suckingX, suckingY);
		}

		if (dp_array[i].CollosopnDP(plrect)) {
			//DP�ƐڐG�����ꍇ
			UPdeteCollisionDP(dp_array[i].Gettype());
			dp_array[i].Setshow(false);

		}
	}

	//todo:�t���O���{�l�ɕύX
	//�N���A�t���O�ύX
	if (m_Scroll_Clear >= 38400||g_pInput->IsKeyPush(MOFKEY_0)) {

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
	//�����g���Ă邯�ǔz��Ƃ��ł���������
	//�����e�N�X�`�����J��Ԃ��ŉ�ʒ[�𒴂���܂ōs��
	int h = m_BakStart.GetWidth();
	int sch = g_pGraphics->GetTargetWidth();


	if (m_BakScroll <= 0) {
		
		//�E���ŕ\�����Ă������̂Ɠ������̂������ŕ\��
		m_RandamuBakLeft = m_RandamuBakRight;

		//�E���̓����_���ɐ��l������
		m_RandamuBakRight = RandmuBak.GetRandomNumbe(1,6);

		//��ԏ��߂̔w�i
		if (m_countbak == 0) {
			m_RandamuBakLeft = 7;
		}

		//��ԍŌ�̔w�i
		if (m_countbak + 1 == 30 ) {
			m_RandamuBakRight = 8;
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
			switch (m_RandamuBakLeft)
			{

				case 1:
					m_BakRdoor.Render(x, 0.0f);
					break;

				case 2:
					m_BakRwall.Render(x, 0.0f);
					break;

				case 3:
					m_Bakldoor.Render(x, 0.0f);
					break;

				case 4:
					m_Baklwall.Render(x, 0.0f);
					break;

				case 5:
					m_BakWindow.Render(x, 0.0f);
					break;

				case 6:
					m_BakStairs.Render(x, 0.0f);
					break;

				case 7:
					m_BakStart.Render(x, 0.0f);
					break;

				case 8:
					m_BakEnd.Render(x, 0.0f);
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
				m_BakRdoor.Render(x, 0.0f);
				break;

			case 2:
				m_BakRwall.Render(x, 0.0f);
				break;

			case 3:
				m_Bakldoor.Render(x, 0.0f);
				break;

			case 4:
				m_Baklwall.Render(x, 0.0f);
				break;

			case 5:
				m_BakWindow.Render(x, 0.0f);
				break;

			case 6:
				m_BakStairs.Render(x, 0.0f);
				break;

			case 8:
				m_BakEnd.Render(x, 0.0f);
				break;

			default:
				break;

			}

		}
	}

	//�n�ʕ`��
	g_ground.Render();

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

}

//���
void CStage::Release(void) {

	m_BakStart.Release();
	m_BakRdoor.Release();
	m_BakRwall.Release();
	m_Bakldoor.Release();
	m_Baklwall.Release();
	m_BakWindow.Release();
	m_BakStairs.Release();
	m_BakEnd.Release();
	m_SPBak.Release();

	//DP�̉��
	for (int i = 0; i < DP_VOLUME; i++)
	{
		dp_array[i].Release();
	}
}

//�f�o�b�N�`��
void CStage::RenderDebugging() {

	CGraphicsUtilities::RenderString(0, 120, MOF_XRGB(80, 80, 80), "�w�i�F%d����", m_countbak);
	CGraphicsUtilities::RenderString(0, 150, MOF_XRGB(80, 80, 80), "�w�i�X�N���[���l%f", m_BakScroll);
	CGraphicsUtilities::RenderString(0, 180, MOF_XRGB(80, 80, 80), "�X�e�[�W�X�N���[���l%f", m_StageScroll);
	CGraphicsUtilities::RenderString(880, 690, MOF_XRGB(80, 80, 80), "P�L�[�Ńt���X�N���[���ɐ؂�ւ�");
	CGraphicsUtilities::RenderString(250, 0, MOF_COLOR_BLACK, "���̃X�e�[�W���ł̎擾��  �w�́F%d�@�s���́F%d�@�z���́F%d�@�R�~���́F%d�@���́F%d",
		m_gaku, m_kou, m_sou, m_komyu, m_miryoku);

	//�n�ʃf�o�b�N�\��
	g_ground.RenderDebugging();


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


	CGraphicsUtilities::RenderLine(m_BakScroll,0, m_BakScroll,g_pGraphics->GetTargetHeight(), MOF_COLOR_BLUE);

	////todo:����f�o�b�N�\��
	////todo:����}�b�v�p�^�[�����ݕ\��
	//CGraphicsUtilities::RenderString(0, 700, "�}�b�v����p�^�[��:%d", m_StageBarConstitution[m_MapNo_Bar]);

	////todo:����}�b�v�p�^�[���S�̕\��
	//for (int i = 0; i < 15; i++)
	//{
	//	CGraphicsUtilities::RenderString(40 * i, 680, "%d", m_StageBarConstitution[i]);

	//}

	////todo:�\���ςݑ���J�E���g
	//CGraphicsUtilities::RenderString(0, 650, "����J�E���g%d", m_barcount);

	//todo�F���ꍂ���̑Ή�
	//CGraphicsUtilities::RenderString(500, 50, MOF_XRGB(80, 80, 80), "50Y�p�^�[��10�`14");
	//CGraphicsUtilities::RenderString(500, 250, MOF_XRGB(80, 80, 80), "250Y�p�^�[��5�`9");
	//CGraphicsUtilities::RenderString(500, 450, MOF_XRGB(80, 80, 80), "450Y�p�^�[��0�`4");



	////todo:OB�f�o�b�N�\��
	////todo:OB�}�b�v�p�^�[�����ݕ\��
	//CGraphicsUtilities::RenderString(0, 700, "�}�b�vOB�p�^�[��:%d", m_StageOBConstitution[m_MapNo_OB]);

	////todo:OB�}�b�v�p�^�[���S�̕\��
	//for (int i = 0; i < 15; i++)
	//{
	//	CGraphicsUtilities::RenderString(40 * i, 680, "%d", m_StageOBConstitution[i]);

	//}

	////todo:�\���ς�OB�J�E���g
	//CGraphicsUtilities::RenderString(0, 650, "OB�J�E���g%d", m_obcount);

	////todo:�FOB�Ή���\��
	//CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(80, 80, 80), "1:�֎q,    �p�^�[��0,3,6,9,12");
	//CGraphicsUtilities::RenderString(0, 430, MOF_XRGB(80, 80, 80), "2:������,�p�^�[��1,4,7,10,13");
	//CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(80, 80, 80), "3:�{�[��,  �p�^�[��2,5,8,11,14");
	////CGraphicsUtilities::RenderString(0, 550, "m_Scroll_Clear%f", m_Scroll_Clear);


	////todo�FOB�����̑Ή�
	//CGraphicsUtilities::RenderString(500, 144, MOF_XRGB(80, 80, 80), "144Y�p�^�[��0�`2");
	//CGraphicsUtilities::RenderString(500, 288, MOF_XRGB(80, 80, 80), "288Y�p�^�[��3�`5");
	//CGraphicsUtilities::RenderString(500, 432, MOF_XRGB(80, 80, 80), "432Y�p�^�[��6�`8");
	//CGraphicsUtilities::RenderString(500, 576, MOF_XRGB(80, 80, 80), "556Y�p�^�[��9�`11");
	//CGraphicsUtilities::RenderString(500, 720, MOF_XRGB(80, 80, 80), "720Y�p�^�[��12�`14");


	//todo:DP�f�o�b�N�\��
	//todo:DP�}�b�v�p�^�[�����ݕ\��
	CGraphicsUtilities::RenderString(0, 700, MOF_XRGB(80, 80, 80), "�}�b�vDP�p�^�[��:%d", m_StageDPConstitution[m_MapNo_DP]);

	//todo:DP�}�b�v�p�^�[���S�̕\��
	for (int i = 0; i < 15; i++)
	{
		CGraphicsUtilities::RenderString(40 * i, 680, MOF_XRGB(80, 80, 80), "%d", m_StageDPConstitution[i]);

	}

	//todo:�\���ς�DP�J�E���g
	CGraphicsUtilities::RenderString(0, 650, MOF_XRGB(80, 80, 80), "DP�J�E���g%d", m_dpcount);

	//todo:�FDP�Ή���\��
	CGraphicsUtilities::RenderString(0, 400, MOF_XRGB(222, 184, 135), "1:�w��,    �p�^�[��0,5,10");
	CGraphicsUtilities::RenderString(0, 430, MOF_COLOR_YELLOW, "2:�s����,  �p�^�[��1,6,11");
	CGraphicsUtilities::RenderString(0, 460, MOF_XRGB(0, 191, 255), "3:�z����,  �p�^�[��2,7,12");
	CGraphicsUtilities::RenderString(0, 490, MOF_XRGB(255, 99, 71), "4:�R�~����,�p�^�[��3,8,13");
	CGraphicsUtilities::RenderString(0, 520, MOF_XRGB(186, 85, 211), "5:����,    �p�^�[��4,9,14");
	CGraphicsUtilities::RenderString(0, 550, MOF_XRGB(80, 80, 80), "m_Scroll_Clear%f", m_Scroll_Clear);


	////todo�FDP�����̑Ή�
	//CGraphicsUtilities::RenderString(500, 50, MOF_XRGB(80, 80, 80), "50Y�p�^�[��10�`14");
	//CGraphicsUtilities::RenderString(500, 250, MOF_XRGB(80, 80, 80), "250Y�p�^�[��5�`9");
	//CGraphicsUtilities::RenderString(500, 450, MOF_XRGB(80, 80, 80), "450Y�p�^�[��0�`4");



}

//���ꐶ��
void CStage::OccurrenceBar(void) {

	//todo:�}�b�v�̑����񂪏I�[�v�f���ǂ������o
	//todo:����X�N���[���l�̏����ύX
	if (m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Type > 10 && m_StageScroll <= 0)
	{
		//�}�b�vOB�p�^�[����ύX
		m_barcount = 0;
		m_MapNo_Bar += 1;


		//�Ō�̃}�b�v����p�^�[�����̏ꍇ
		if (m_MapNo_Bar >= BAR_INFO_PATTERN)
		{
			//todo:�Ō�̏ꍇ�Ō�܂ŕ`�悵���ꍇ�̏���
			//�ǂ����悤���Y�ݒ�
			m_MapNo_Bar = 0;
		}

	}


	//todo:������ύX���܂���
	//m_MapNo_Bar->�}�b�v�p�^�[���ԍ�
	//m_obcount->�\���ςݑ��ꐔ
	//�}�b�v�p�^�[���ԍ����p�ӂ��Ă��鐔�ȉ��̂Ƃ�����
	//�X�N���[���l���o���l�����������Ȃ����ꍇ�\��
	//�X�N���[���l���v���X�ɕύX���܂���
	if (m_MapNo_Bar < BAR_INFO_PATTERN && m_StageScroll > m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�����N���X��T��
		for (int i = 0; i < BAR_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (b_bar[i].Getshow()) {
				continue;
			}

			//�\������
			//�o���ʒu�ƃ^�C�v��n��
			b_bar[i].Start(m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Pos_y,
				m_barinfo[m_StageBarConstitution[m_MapNo_Bar]][m_barcount].Type);
			break;
		}

		//�\���ςݑ�������Z
		m_barcount++;

	}

}

//�f�B�e�[���|�C���g����
void CStage::OccurrenceDP(void) {

	//todo:�}�b�v��DP��񂪏I�[�v�f���ǂ������o
	//todo:����X�N���[���l�̏����ύX
	if (m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Type > 10 && m_StageScroll <=0)
	{
		//�}�b�v�p�^�[����ύX
		m_dpcount = 0;
		m_MapNo_DP += 1;


		//�Ō�̃}�b�v�p�^�[�����̏ꍇ
		if (m_MapNo_DP >= DP_INFO_PATTERN)
		{
			//todo:�Ō�̏ꍇ�Ō�܂ŕ`�悵���ꍇ�̏���
			//�ǂ����悤���Y�ݒ�
			m_MapNo_DP = 0;
		}

	}

	//todo:������ύX���܂���
	//m_MapNo_DP->�}�b�v�p�^�[���ԍ�
	//m_dpcount->�\���ς�DP��
	//�}�b�vDP�p�^�[���ԍ����p�ӂ��Ă��鐔�ȉ��̂Ƃ�����
	//�X�N���[���l���o���l�����������Ȃ����ꍇ�\��
	//�X�N���[���l���v���X�ɕύX���܂���
	if (m_MapNo_DP < DP_INFO_PATTERN && m_StageScroll > m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�DP�N���X��T��
		for (int i = 0; i < DP_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (dp_array[i].Getshow()) {
				continue;
			}

			//�\������
			//�o���ʒu�ƃ^�C�v��n��
			dp_array[i].Start(m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Pos_y, m_dpinfo[m_StageDPConstitution[m_MapNo_DP]][m_dpcount].Type);
			break;
		}

		//�\���ς�DP�����Z
		m_dpcount++;

	}

}

//��Q��OB����
void CStage::OccurrenceOB(void) {

	//todo:�}�b�v��OB��񂪏I�[�v�f���ǂ������o
	//todo:����X�N���[���l�̏����ύX
	if (m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Type > 10 && m_StageScroll <= 0)
	{
		//�}�b�vOB�p�^�[����ύX
		m_obcount = 0;
		m_MapNo_OB += 1;


		//�Ō�̃}�b�vOB�p�^�[�����̏ꍇ
		if (m_MapNo_OB >= OB_INFO_PATTERN)
		{
			//todo:�Ō�̏ꍇ�Ō�܂ŕ`�悵���ꍇ�̏���
			//�ǂ����悤���Y�ݒ�
			m_MapNo_OB = 0;
		}

	}


	//todo:������ύX���܂���
	//m_MapNo_OB->�}�b�v�p�^�[���ԍ�
	//m_obcount->�\���ς�DP��
	//�}�b�v�p�^�[���ԍ����p�ӂ��Ă��鐔�ȉ��̂Ƃ�����
	//�X�N���[���l���o���l�����������Ȃ����ꍇ�\��
	//�X�N���[���l���v���X�ɕύX���܂���
	if (m_MapNo_OB < OB_INFO_PATTERN && m_StageScroll > m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Scroll)
	{

		//���蓖�Ă��Ă��Ȃ�DP�N���X��T��
		for (int i = 0; i < OB_VOLUME; i++)
		{
			//�\�����Ȃ�X���[
			if (ob_array[i].Getshow()) {
				continue;
			}

			//�\������
			//�o���ʒu�ƃ^�C�v��n��
			ob_array[i].Start(m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Pos_y,
							m_obinfo[m_StageOBConstitution[m_MapNo_OB]][m_obcount].Type);
			break;
		}

		//�\���ς�DP�����Z
		m_obcount++;

	}

}
bool CStage::GetClear(void) {

	return m_bClear;

}

