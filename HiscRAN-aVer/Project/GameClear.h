#pragma once
#include "Define.h"
#include "SceneBase.h"


class CGameClear:public CSceneBase
{
private:
	CTexture	m_BackTexture;
	CTexture	m_UITexture;

	//�����p�A���t�@�l
	int gAlpha;
	//�����p�t���O
	bool isStop = false;

	//�t�F�[�h�C���p�A���t�@�l
	int m_WhiteAlpha;
	//�t���O
	bool m_FadeOut;

	// �X�e�[�^�X�����[����z��
	int Status[ITEM_NUM];

	//�O���t�`��p�z��
	int StatusRender[ITEM_NUM];


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

	char* StatusName[ITEM_NUM] = { "1����:%d","2�s����:%d","3�w��:%d","4�z����:%d","5�R�~����:%d" };

public:
	CGameClear();
	~CGameClear();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void buildChart(int* Status, Vector2* PointsStatus);
	void drawChart(Vector2* PointsStatus, MofU32 cl);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};

