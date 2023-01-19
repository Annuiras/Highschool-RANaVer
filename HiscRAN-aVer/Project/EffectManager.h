////////////////////////////////////////
//	�G�t�F�N�g�Ǘ��v���O�����ł��@�@�@//
//									�@//
//�@�쐬�ҁF�c�� �A���c ����		�@//
//									�@//
//�@���t�@�N�^�����O�����l�F�c���@�@//
//									�@//
//�@�ŏI�X�V�F2023/01/17			�@//
////////////////////////////////////////

#pragma once
#include "Effect.h"

//�G�t�F�N�g�Ǘ��N���X
class CEffectMgmt
{

private:
	//�G�t�F�N�g�N���X
	CEffect		m_Effect[EFC_TYPE_COUNT][EFFECT_MGMT_COUNT];

	//�G�t�F�N�g�摜
	CTexture	m_Texture[EFC_TYPE_COUNT];

public:
	CEffectMgmt();
	~CEffectMgmt();
	//�f�ރ��[�h
	tag_LoadSituation Load(void);

	//����������
	void Initialize(void);
	//��ʐ��ڎ��̏���������
	void InitializeIn_middle(void);

	//�J�n����
	CEffect* Start(float px, float py, tag_EFFECTTYPE type);

	//�X�V
	void Update(CRectangle plrec);

	//�`��
	void Render(void);
	//�f�o�b�O�\��
	void RenderDebugging(void);

	//���
	void Release(void);
	
};

