#pragma once
#include "Define.h"
#include "SceneBase.h"
#include "RandomValue.h"

//����ҁF���Y ���H �A�c�� ��

//�Q�[���N���A���
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
		MOF_ARGB(200,201, 168, 212),	//�o��
		MOF_ARGB(200,251, 232, 124),	//�l�C��
		MOF_ARGB(200,233, 255, 111),	//�M����
		MOF_ARGB(200,210, 54, 43),		//�����c��
		MOF_ARGB(200,69, 101, 87),		//�}�����̒�
		MOF_ARGB(200,53, 78, 177),		//�I�^�N
		MOF_ARGB(200,248, 54, 141),		//�C���t���G���T�[
		MOF_ARGB(200,255, 156, 123),	//�ψ���
		MOF_ARGB(200,210, 60, 83),		//����̉�
		MOF_ARGB(200,106,106, 106),		//�����L�[
		MOF_ARGB(200,255, 89, 0),		//�X�[�p�[���f�B
		MOF_ARGB(200,255, 123, 41),		//�����q��
		MOF_ARGB(200,80, 132, 93),		//���w����
		MOF_ARGB(200,95, 59, 116),		//����a
		MOF_ARGB(200,255, 209, 46)		//�_�Ή�	
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

	//���Ԍv��
	int m_StartCount = 0;
	int m_StartTime = 0;


	// �X�e�[�^�X�����[����z��
	float Status[DP_COUNT];

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

	//�f�o�b�N�p����
	char* StatusName[ITEM_NUM] = { "1�w��:%f","2�s����:%f","3�z����:%f","4�R�~����:%f","5����:%f" };


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

