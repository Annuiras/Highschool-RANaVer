#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "RandomValue.h"


class CGameClear:public CSceneBase
{
private:

	//��������
	RandomValue RandmuBak;

	//�w�i
	CTexture	m_BackTexture[15];

	//�O���t�h��Ԃ��J���[
	MofU32 Chartcol[15] =
	{
		MOF_XRGB(250, 157, 185),
		MOF_XRGB(255, 232, 87),
		MOF_XRGB(233, 255, 111),
		MOF_XRGB(210, 54, 43),
		MOF_XRGB(69, 101, 87),
		MOF_XRGB(106,106, 106),
		MOF_XRGB(248, 54, 141),
		MOF_XRGB(255, 156, 123),
		MOF_XRGB(255, 232, 87),
		MOF_XRGB(53, 78, 177),
		MOF_XRGB(255, 89, 0),
		MOF_XRGB(255, 123, 41),
		MOF_XRGB(80, 132, 93),
		MOF_XRGB(95, 59, 116),
		MOF_XRGB(255, 209, 46)
	};

	//�����e�N�X�`��
	CTexture	m_UITexture;


	//�X�e�[�^�X����ŏI�e�p�𔻒肷��
	void StatusJudgement(void);


	//�����p�A���t�@�l
	int gAlpha;
	//�����p�t���O
	bool isStop = false;

	//�t�F�[�h�C���p�A���t�@�l
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	// �X�e�[�^�X�����[����z��
	int Status[DP_COUNT];

	//�����̃X�e�[�^�X��ۑ�
	int StatusSame[DP_COUNT];

	//�O���t�`��p�z��
	int StatusRender[ITEM_NUM];

	//�ŏI�e�p�ԍ�
	int LastDetailNo;

	// �X�e�[�^�X�p�`���[�g�̃|���S�����W�����[����z��
	Vector2 PointsStatus[ITEM_NUM];

	//�O���t�������p�z��
	int Memory1[ITEM_NUM];
	// �X�e�[�^�X�p�`���[�g�̃|���S�����W�����[����z��
	Vector2 MemoryPoints1[ITEM_NUM];

	//�O���t�������p�z��
	int Memory2[ITEM_NUM];
	// �X�e�[�^�X�p�`���[�g�̃|���S�����W�����[����z��
	Vector2 MemoryPoints2[ITEM_NUM];

	char* StatusName[ITEM_NUM] = { "1�w��:%d","2�s����:%d","3�z����:%d","4�R�~����:%d","5����:%d" };

public:
	CGameClear();
	~CGameClear();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void buildChart(int* Status, Vector2* PointsStatus);
	void drawChart(Vector2* PointsStatus, MofU32 cl);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

