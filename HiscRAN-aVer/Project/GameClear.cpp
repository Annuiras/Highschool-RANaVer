#include "GameClear.h"

//�X�e�[�^�X����ŏI�e�p�𔻒肷��
void CGameClear::StatusJudgement(void)
{
	//�X�e�[�^�X��ʂQ�̓Y����
	int m_Status_1=0, m_Status_2=0;

	//todo:�����̏�������
	//�X�e�[�^�X�̑傫����Ԗڂ̓Y�����ۑ�
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (Status[i] > Status[m_Status_1])
		{
			m_Status_1 = i;
		}
	}

	//��Ԗڂ̏����l
	m_Status_2 = m_Status_1 + 1;
	if (m_Status_2 >= DP_COUNT)
		m_Status_2 = 0;

	//�X�e�[�^�X�̑傫����Ԗڂ̓Y�����ۑ�
	for (int i = 0; i < DP_COUNT; i++)
	{
		if (m_Status_1 == i) {
			continue;
		}

		if (Status[i] > Status[m_Status_2])
		{
			m_Status_2 = i;
		}
	}

	//�w�͈�_�˔j
	if (m_Status_1 == DP_SCHOLASTIC && Status[m_Status_1]>= 100) {
		//���w����
		LastDetailNo = 0;
		return;
	}
	//�s���͈�_�˔j
	if (m_Status_1 == DP_ACTION&& Status[m_Status_1] >= 100) {
		//�����q��
		LastDetailNo = 1;
		return;
	}
	//�z���͈�_�˔j
	if (m_Status_1 == DP_IMAGINATION && Status[m_Status_1] >= 100) {
		//����a
		LastDetailNo = 2;
		return;
	}
	//�R�~���͈�_�˔j
	if (m_Status_1 == DP_COMMUNICATION && Status[m_Status_1] >= 100) {
		//�_�Ή�
		LastDetailNo = 3;
		return;
	}
	//���͈�_�˔j
	if (m_Status_1 == DP_CHARM && Status[m_Status_1] >= 100) {
		//�X�[�p�[���f�B
		LastDetailNo = 4;
		return;
	}

	//�ȉ���_�Q��
	//�w��
	if (m_Status_1 == DP_SCHOLASTIC || m_Status_2 == DP_SCHOLASTIC) {

		//�ƍs����
		if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {
			//�ψ���
			LastDetailNo = 5;
			return;
		}
		//�Ƒz����
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//�}�����̒�
			LastDetailNo = 6;
			return;
		}
		//�ƃR�~����
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//�l�C��
			LastDetailNo = 7;
			return;
		}
		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//����̉�
			LastDetailNo = 8;
			return;
		}
	}

	//�s����
	if (m_Status_1 == DP_ACTION || m_Status_2 == DP_ACTION) {

		//�Ƒz����
		if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {
			//�I�^�N
			LastDetailNo = 9;
			return;
		}
		//�ƃR�~����
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//�����c��
			LastDetailNo = 10;
			return;
		}
		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//�����L�[
			LastDetailNo = 11;
			return;
		}
	}

	//�z����
	if (m_Status_1 == DP_IMAGINATION || m_Status_2 == DP_IMAGINATION) {

		//�ƃR�~����
		if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {
			//�o��
			LastDetailNo = 12;
			return;
		}
		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//�C���t���G���T�[
			LastDetailNo = 13;
			return;
		}
	}

	//�R�~����
	if (m_Status_1 == DP_COMMUNICATION || m_Status_2 == DP_COMMUNICATION) {

		//�Ɩ���
		if (m_Status_1 == DP_CHARM || m_Status_2 == DP_CHARM) {
			//�M����
			LastDetailNo = 14;
			return;
		}
	}

}

//�R���X�g���N�^
CGameClear::CGameClear() :
	m_BackTexture(),
	m_UITexture(),
	gAlpha(0.0f),
	m_WhiteAlpha(0),
	m_FadeOut(),
	Memory1(),
	Memory2(),
	Status(),
	StatusRender(),
	LastDetailNo(),
	isStop(false)
{}

//�f�X�g���N�^
CGameClear::~CGameClear()
{

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
bool CGameClear::Load(void)
{
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Game/GameClear");

	char* name[15] =
	{
		"GameClearBG_LiteratureGirl.png",//0 ���w����
		"GameClearBG_FussyPerson.png",	 //1 �����q��
		"GameClearBG_Chu-nibyou.png",	 //2 ����a
		"GameClearBG_GodSupport.png",	 //3 �_�Ή�
		"GameClearBG_SuperLady.png",	 //4 �X�[�p�[���f�B
		"GameClearBG_Chairman.png",		 //5 �ψ���
		"GameClearBG_LibraryManager.png",//6 �}�����̒�
		"GameClearBG_ClassFavorite.png", //7 �l�C��
		"GameClearBG_LoftyDream.png",	 //8 ����̉�
		"GameClearBG_Otaku.png",		 //9 �I�^�N
		"GameClearBG_CheerLeader.png",	 //10�����c��
		"GameClearBG_Yankee.png",		 //11�����L�[
		"GameClearBG_OlderSister.png",	 //12�o��
		"GameClearBG_Infulencer.png",	 //13�C���t���G���T�[
		"GameClearBG_Gal.png",			 //14�M����
	};

	for (int i = 0; i < 15; i++)
	{
		if (!m_BackTexture[i].Load(name[i])) {
			return false;
		}
	}

	if (!m_UITexture.Load("GameClearUI.png"))
	{
		return false;
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../../");

	return true;
}

//������
void CGameClear::Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec)
{
	//�f�ރ��[�h
	Load();

	//�e�}�l�[�W���[�Z�b�g
	m_GameProgMamt = mamt;
	g_MusicManager = musi;
	g_EffectManeger = effec;

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

	//�Q�[����ʂ���DP�擾���󂯂Ƃ�
	for (int i = 0; i < DP_COUNT; i++)
	{
		Status[i] = *(m_GameProgMamt->GetGame_DPNum()+i);
	}

	//�����p�A���t�@�l
	gAlpha = 0;

	//�t�F�[�h�C���p�A���t�@�l
	m_WhiteAlpha = 255;

	//�t�F�[�h�C���t���O
	m_FadeOut = false;
	isStop = false;

	LastDetailNo = 0;

	//�X�e�[�^�X����ŏI�e�p�𔻒肷��
	StatusJudgement();


	//BGM�Đ�
	g_MusicManager->BGMStart(BGMT_CLEAR);
}



//�X�V
void CGameClear::Update(void)
{
	//�G���^�[�L�[�Ń��[�h�Z���N�g��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_SELECTMODE;
	}

	//���]����
	if (m_WhiteAlpha >= 0 && !m_FadeOut)
	{
		m_WhiteAlpha -= FADE_OUT_SPEED;
		if (m_WhiteAlpha == 0)
		{
			m_FadeOut = true;
		}
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

	if (!m_FadeOut) {
		return;
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
	m_BackTexture[LastDetailNo].Render(0, 0);

	// �`���[�g��`��
	drawChart(PointsStatus, MOF_COLOR_RED);
	drawChart(MemoryPoints1, MOF_COLOR_BLACK);
	drawChart(MemoryPoints2, MOF_COLOR_BLACK);

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


	//�������ɂ��Ă���
	g_pGraphics->SetBlending(BLEND_NORMAL);
	m_UITexture.Render(370, 2, MOF_ARGB(gAlpha, 255, 255, 255));

	//�t�F�[�h�A�E�g���]�p
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_WhiteAlpha, 255, 255, 255));

}

void CGameClear::RenderDebug(void)
{
	//CGraphicsUtilities::RenderString(10, 10, "�Q�[���N���A���");
	//CGraphicsUtilities::RenderString(10, 40, "�G���^�[�Ń��[�h�Z���N�g");

	//�����A���t�@�l�\��
	//CGraphicsUtilities::RenderString(10, 100, MOF_COLOR_BLACK, "%d", gAlpha);

	//���S�_
	CGraphicsUtilities::RenderFillCircle(CHART_CENTER_X, CHART_CENTER_Y, 2, MOF_COLOR_YELLOW);

	//�~�̕`��
	CGraphicsUtilities::RenderCircle(CHART_CENTER_X,
		CHART_CENTER_Y,
		CHART_SIZE,
		MOF_COLOR_BLACK);

	for (int i = 0; i < ITEM_NUM; i++)
	{
		//CGraphicsUtilities::RenderString(0, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].x);
		//CGraphicsUtilities::RenderString(150, 30 * i, MOF_COLOR_BLACK, "%f", PointsStatus[i].y);
		CGraphicsUtilities::RenderString(100, 40 * i + 450, MOF_COLOR_BLACK, StatusName[i], Status[i]);

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
	
	//BGM��~
	g_MusicManager->BGMStop(BGMT_CLEAR);

}
