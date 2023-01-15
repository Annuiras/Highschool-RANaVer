#include "GameClear.h"


//�R���X�g���N�^
CGameClear::CGameClear() :
	RandmuBak(),
	m_BackTexture(),
	m_UITexture(),
	gAlpha(0.0f),
	m_BlackBakAlph(0),
	m_WhiteBakAlph(0),
	Memory1(),
	Memory2(),
	Status(),
	StatusSame(),
	StatusRender(),
	LastDetailNo(),
	isStop(false)
{}

//�f�X�g���N�^
CGameClear::~CGameClear()
{

}

//�X�e�[�^�X����ŏI�e�p�𔻒肷��
void CGameClear::StatusJudgement(void)
{
	//�X�e�[�^�X��ʂQ�̓Y����,�����J�E���g
	int m_Status_1 = 0, m_Status_2 = 0, m_Samecont = 0;

	//�X�e�[�^�X�̑傫����Ԗڂ̓Y�����ۑ�
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (Status[i] > Status[m_Status_1])
		{
			m_Status_1 = i;
		}
	}

	//�傫����ԖڂƓ����̐��������邩
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (Status[m_Status_1] == Status[i])
		{
			//�Y������ۑ�
			StatusSame[m_Samecont] = i;

			//�J�E���g
			m_Samecont++;
		}
	}

	//�����̃X�e�[�^�X�����݂���ꍇ
	if (m_Samecont > 0) {

		//�����_���ň�ԑ傫���X�e�[�^�X�����߂�
		m_Status_1 = StatusSame[RandmuBak.GetRandomNumbe(0, m_Samecont - 1)];

		//���Z�b�g
		m_Samecont = 0;
	}

	//��Ԗڂ̏����l
	m_Status_2 = m_Status_1 + 1;
	if (m_Status_2 >= DP_COUNT)
		m_Status_2 = 0;

	//�X�e�[�^�X�̑傫����Ԗڂ̓Y�����ۑ�
	for (int i = 0; i < DP_COUNT; i++)
	{
		//��Ԃɍ̗p����Ă�����̂̓X���[
		if (m_Status_1 == i) {
			continue;
		}

		if (Status[i] > Status[m_Status_2])
		{
			m_Status_2 = i;
		}
	}

	//�傫����ԖڂƓ����̐��������邩
	for (int i = 0; i < DP_COUNT; i++)
	{
		//��Ԃɍ̗p����Ă�����̂̓X���[
		if (m_Status_1 == i) {
			continue;
		}

		if (Status[m_Status_2] == Status[i])
		{
			//�Y������ۑ�
			StatusSame[m_Samecont] = i;

			//�J�E���g
			m_Samecont++;
		}
	}

	//�����̃X�e�[�^�X�����݂���ꍇ
	if (m_Samecont > 0) {

		//�����_���ň�ԑ傫���X�e�[�^�X�����߂�
		m_Status_2 = StatusSame[RandmuBak.GetRandomNumbe(0, m_Samecont - 1)];

		//���Z�b�g
		m_Samecont = 0;
	}


	//��ԂƓ�Ԃ̍����Z�o
	int m_StatusDiff = Status[m_Status_1] - Status[m_Status_2];

	//�w�͈�_�˔j
	if (m_Status_1 == DP_SCHOLASTIC && m_StatusDiff >= DIFFERENCE_NUM) {
		//���w����
		LastDetailNo = LT_BUNGAKU;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//�s���͈�_�˔j
	if (m_Status_1 == DP_ACTION&& m_StatusDiff >= DIFFERENCE_NUM) {
		//�����q��
		LastDetailNo = LT_OTYOUSI;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//�z���͈�_�˔j
	if (m_Status_1 == DP_IMAGINATION && m_StatusDiff >= DIFFERENCE_NUM) {
		//�~��a
		LastDetailNo = LT_TYUNI;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//�R�~���͈�_�˔j
	if (m_Status_1 == DP_COMMUNICATION && m_StatusDiff >= DIFFERENCE_NUM) {
		//�_�Ή�
		LastDetailNo = LT_KAMITAIOU;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}
	//���͈�_�˔j
	if (m_Status_1 == DP_CHARM && m_StatusDiff >= DIFFERENCE_NUM) {
		//�X�[�p�[���f�B
		LastDetailNo = LT_SUPERLADY;
		b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
		return;
	}

	//�ȉ���_�Q��
	//�w��
	if (m_Status_1 == DP_SCHOLASTIC || m_Status_2 == DP_SCHOLASTIC) {

		//�ƍs����
		if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {
			//�ψ���
			LastDetailNo = LT_IINTYOU;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//�Ƒz����
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//�}�����̒�
			LastDetailNo = LT_TOSYO;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//�ƃR�~����
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//�l�C��
			LastDetailNo = LT_NINKIMONO;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//����̉�
			LastDetailNo = LT_TAKANE;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

	//�s����
	if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {

		//�Ƒz����
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//�I�^�N
			LastDetailNo = LT_OTAKU;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//�ƃR�~����
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//�����c��
			LastDetailNo = LT_OUEN;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//�����L�[
			LastDetailNo = LT_YABKI;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

	//�z����
	if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {

		//�ƃR�~����
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//�o��
			LastDetailNo = LT_ANEGO;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//�C���t���G���T�[
			LastDetailNo = LT_INFLUENCER;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

	//�R�~����
	if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {

		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//�M����
			LastDetailNo = LT_GYARU;
			b_GameProgMamt->SetGallery_flg(LastDetailNo, true);
			return;
		}
	}

}

//�`���[�g�y��쐬
void CGameClear::buildChart(int* Status, Vector2* PointsStatus)
{
	double kosu = ((double)360.0 / ITEM_NUM);


	// ���ڂ��Ƃ̉�]�p�x
	double radian = MOF_ToRadian(kosu);

	// �J�n�p�x
	double startRadian = (double)MOF_ToRadian(-90.0f);

	for (int i = 0; i < ITEM_NUM; i++) {

		// ���S����̋��������߂�
		double length = CHART_SIZE * ((double)Status[i] / MAX_STATUS);

		// �P�ʃx�N�g���ɋ�������Z
		double cos_X = cosf(startRadian + radian * i);
		double x = cos_X * length;
		double y = sinf(startRadian + radian * i) * length;

		PointsStatus[i].x = (float)x;
		PointsStatus[i].y = (float)y;

	}
}

//���̕`����s��
void CGameClear::drawChart(Vector2* PointsStatus, MofU32 cl)
{
	for (int i = 0; i < ITEM_NUM; i++) {

		int x1 = (int)PointsStatus[i].x;
		int y1 = (int)PointsStatus[i].y;

		int x2 = (int)PointsStatus[(i + 1) % ITEM_NUM].x;
		int y2 = (int)PointsStatus[(i + 1) % ITEM_NUM].y;



		//���̕`��
		CGraphicsUtilities::RenderLine((int)(x1 + CHART_CENTER_X),
			(int)(y1 + CHART_CENTER_Y),
			(int)(x2 + CHART_CENTER_X),
			(int)(y2 + CHART_CENTER_Y),
			cl);
	}
}

//�f�ރ��[�h
void CGameClear::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("GameClear");

	char* name[15] =
	{
		"GameClearBG_OlderSister.png",	 //�o��
		"GameClearBG_ClassFavorite.png", //�l�C��
		"GameClearBG_Gal.png",			 //�M����
		"GameClearBG_CheerLeader.png",	 //�����c��
		"GameClearBG_LibraryManager.png",//�}�����̒�
		"GameClearBG_Otaku.png",		 //�I�^�N
		"GameClearBG_Infulencer.png",	 //�C���t���G���T�[
		"GameClearBG_Chairman.png",		 //�ψ���
		"GameClearBG_LoftyDream.png",	 //����̉�
		"GameClearBG_Yankee.png",		 //�����L�[
		"GameClearBG_SuperLady.png",	 //�X�[�p�[���f�B
		"GameClearBG_FussyPerson.png",	 //�����q��
		"GameClearBG_LiteratureGirl.png",//���w����
		"GameClearBG_Chu-nibyou.png",	 //�~��a
		"GameClearBG_GodSupport.png",	 //�_�Ή�
		
	};

	for (int i = 0; i < 15; i++)
	{
		if (!m_BackTexture[i].Load(name[i])) {
			b_LoadSitu = LOAD_ERROR;
			return;
		}
	}

	if (!m_UITexture.Load("GameClearUI.png"))
	{
		b_LoadSitu = LOAD_ERROR;
		return;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	//���[�h����
	b_LoadSitu = LOAD_COMP;
}

//������
void CGameClear::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu)
{

	//�e�}�l�[�W���[�Z�b�g
	b_GameProgMamt = mamt;
	b_MusicManager = musi;
	b_EffectManeger = effec;


	//�ŏI�e�p�ԍ�
	LastDetailNo = LT_ANEGO;


	//�����p�A���t�@�l
	gAlpha = 0;

	//�t�F�[�h�C���p�A���t�@�l
	m_WhiteBakAlph = 255;
	m_BlackBakAlph = 0;
	b_Fadein = FADE_IN;

	isStop = false;

	//�f�ރ��[�h
	Load();

	//�G���[��ԂłȂ��ꍇ
	if (b_LoadSitu != LOAD_ERROR) {
		//����������
		b_LoadSitu = LOAD_DONE;
	}

	//�ő�l�������p
	for (int i = 0; i < ITEM_NUM; i++)
	{
		Memory1[i] = MAX_STATUS;

	}

	//�O���t�����l�������p
	for (int i = 0; i < ITEM_NUM; i++)
	{
		Memory2[i] = MAX_STATUS / 2;

	}

	//���I�ȃX�e�[�^�X������
	for (int i = 0; i < ITEM_NUM; i++)
	{
		StatusRender[i] = 0;
	}

	//�Q�[����ʂ���X�e�[�^�X���󂯂Ƃ�
	for (int i = 0; i < DP_COUNT; i++)
	{
		Status[i] = *(b_GameProgMamt->GetCal_Status()+i);
	}


	//�X�e�[�^�X����ŏI�e�p�𔻒肷��
	StatusJudgement();

}

//�X�V
void CGameClear::Update(void)
{

	//BGM�Đ�
	b_MusicManager->BGMStart(BGMT_CLEAR);

	//�t�F�[�h�C������
	if (b_Fadein == FADE_IN) {
		m_WhiteBakAlph = FadeIn(m_WhiteBakAlph, true);
		return;
	}

	//�t�F�[�h�A�E�g������
	if (b_Fadein == FADE_NEXT) {
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//�t�F�[�h�A�E�g����
	if (b_Fadein == FADE_OUT) {
		m_WhiteBakAlph = FadeOut(m_WhiteBakAlph, true);
		return;
	}

	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		b_Fadein = FADE_OUT;
	}


	//���l�ύX����
	//�������������Ă�
	if (!isStop)
	{
		gAlpha += 3;

		if (gAlpha >= 255)
		{
			isStop = true;
		}
	}
	else
	{
		gAlpha -= 3;
		if (gAlpha <= 0)
		{
			isStop = false;
		}
	}



	//�f�o�b�O�p
	if (g_pInput->IsKeyHold(MOFKEY_RCONTROL)) {

		if (g_pInput->IsKeyPull(MOFKEY_1)) {

			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[0] -= 1;

			}
			else
			{
				//DP
				Status[0] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_2)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[1] -= 1;

			}
			else
			{
				//DP
				Status[1] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_3)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[2] -= 1;

			}
			else
			{
				//DP
				Status[2] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_4)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[3] -= 1;

			}
			else
			{
				//DP
				Status[3] += 1;

			}
		}
		if (g_pInput->IsKeyPull(MOFKEY_5)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[4] -= 1;

			}
			else
			{
				//DP
				Status[4] += 1;

			}
		}

	}
	else
	{
		if (g_pInput->IsKeyHold(MOFKEY_1)) {

			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[0] -= 1;

			}
			else 
			{
				//DP
				Status[0] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_2)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[1] -= 1;

			}
			else
			{
				//DP
				Status[1] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_3)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[2] -= 1;

			}
			else
			{
				//DP
				Status[2] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_4)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[3] -= 1;

			}
			else
			{
				//DP
				Status[3] += 1;

			}
		}
		if (g_pInput->IsKeyHold(MOFKEY_5)) {
			//DP
			if (g_pInput->IsKeyHold(MOFKEY_RSHIFT)) {
				//DP
				Status[4] -= 1;

			}
			else
			{
				//DP
				Status[4] += 1;

			}
		}

	}

	//�f�o�b�O�p
	if (g_pInput->IsKeyHold(MOFKEY_0)) {
		for (int i = 0; i < ITEM_NUM; i++)
		{
			StatusRender[i] = 0;
		}
	}

	if (g_pInput->IsKeyPull(MOFKEY_SPACE)) {

		StatusJudgement();
		for (int i = 0; i < ITEM_NUM; i++)
		{
			StatusRender[i] = 0;
		}

	}


	//�O���t�����킶�퓮��
	for (int i = 0; i < ITEM_NUM; i++)
	{
		if (Status[i]>= StatusRender[i])
		{
			if (Status[i] >= 100) {
				StatusRender[i]+=5;
			}
			StatusRender[i]++;
		}
	}


	// �`���[�g�𐶐�
	buildChart(StatusRender, PointsStatus);
	buildChart(Memory1, MemoryPoints1);
	buildChart(Memory2, MemoryPoints2);
}

//�`��
void CGameClear::Render(void)
{
	//�ŏI�e�p�\��
	m_BackTexture[LastDetailNo].Render(0, 0);

	//���W�擾
	Vector2 center(CHART_CENTER_X, CHART_CENTER_Y);
	Vector2 point1(PointsStatus[0].x+ CHART_CENTER_X, PointsStatus[0].y+ CHART_CENTER_Y);
	Vector2 point2(PointsStatus[1].x+ CHART_CENTER_X, PointsStatus[1].y+ CHART_CENTER_Y);
	Vector2 point3(PointsStatus[2].x + CHART_CENTER_X, PointsStatus[2].y + CHART_CENTER_Y);
	Vector2 point4(PointsStatus[3].x + CHART_CENTER_X, PointsStatus[3].y + CHART_CENTER_Y);
	Vector2 point5(PointsStatus[4].x + CHART_CENTER_X, PointsStatus[4].y + CHART_CENTER_Y);

	//�O�p�`��`���ăO���t��h��Ԃ�
	CGraphicsUtilities::RenderFillTriangle(center, point1, point2, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point2, point3, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point3, point4, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point4, point5, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);

	CGraphicsUtilities::RenderFillTriangle(center, point5, point1, 
		Chartcol[LastDetailNo], Chartcol[LastDetailNo], Chartcol[LastDetailNo]);


	//�����������ɂ��Ă���
	g_pGraphics->SetBlending(BLEND_NORMAL);
	m_UITexture.Render(370, 2, MOF_ARGB(gAlpha, 255, 255, 255));

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteBakAlph, 255, 255, 255));

	//�t�F�[�h�A�E�g�Ó]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_BlackBakAlph, 0, 0, 0));

}

void CGameClear::RenderDebug(void)
{
	//CGraphicsUtilities::RenderString(10, 10, "�Q�[���N���A���");
	//CGraphicsUtilities::RenderString(10, 40, "�G���^�[�Ń��[�h�Z���N�g");

	//�����A���t�@�l�\��
	//CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "%d", gAlpha);

	//���S�_
	//CGraphicsUtilities::RenderFillCircle(CHART_CENTER_X, CHART_CENTER_Y, 2, MOF_COLOR_YELLOW);

	////�~�̕`��
	//CGraphicsUtilities::RenderCircle(CHART_CENTER_X,
	//	CHART_CENTER_Y,
	//	CHART_SIZE,
	//	MOF_COLOR_BLACK);

	for (int i = 0; i < ITEM_NUM; i++)
	{
		//CGraphicsUtilities::RenderString(0, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].x);
		//CGraphicsUtilities::RenderString(150, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].y);
		CGraphicsUtilities::RenderString(550, 40 * i + 450, MOF_COLOR_BLACK, StatusName[i], Status[i]);

		CGraphicsUtilities::RenderLine((int)(CHART_CENTER_X),
			(int)(CHART_CENTER_Y),
			(int)(MemoryPoints1[i].x + CHART_CENTER_X),
			(int)(MemoryPoints1[i].y + CHART_CENTER_Y),
			MOF_COLOR_BLACK);
	}

}

void CGameClear::Release(void)
{
	m_UITexture.Release();

	for (int i = 0; i < 15; i++)
	{
		m_BackTexture[i].Release();
	}
	
	//BGM��~
	b_MusicManager->BGMStop(BGMT_CLEAR);

	//�X�e�[�^�X��������
	b_GameProgMamt->InitializeStatus();

}
