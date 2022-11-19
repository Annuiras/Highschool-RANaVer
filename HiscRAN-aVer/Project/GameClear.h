#pragma once
#include "Mof.h"
#include "SceneBase.h"

#define CHART_SIZE 248			// �`���[�g���a
#define CHART_CENTER_X 325	    // �`���[�g���S���W X
#define CHART_CENTER_Y 478	    // �`���[�g���S���W Y

#define MAX_STATUS 100			// �X�e�[�^�X�ő�l
#define ITEM_NUM 5				// �X�e�[�^�X��

class CGameClear:public CSceneBase
{
private:
	CTexture	m_BackTexture;
	CTexture	m_UITexture;

	int gAlpha = 0;
	bool isStop = false;

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
	void Initialize(void);
	void buildChart(int* Status, Vector2* PointsStatus);
	void drawChart(Vector2* PointsStatus, MofU32 cl);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};
