////////////////////////////////////////
//	�G�t�F�N�g�̃v���O�����ł��@�@�@�@//
//									�@//
//�@�쐬�ҁF�c�� �A���c ����		�@//
//									�@//
//�@���t�@�N�^�����O�����l�F�c���@�@//
//									�@//
//�@�ŏI�X�V�F2023/01/17			�@//
////////////////////////////////////////
#pragma once
#include "Define.h"
#include "Define_Effect.h"

class CEffect
{	
private:

	//�G�t�F�N�g�̃e�N�X�`���p
	CTexture* m_pTexture;

	//�A�j���[�V����
	CSpriteMotionController	m_Motion;

	//�\��X,Y
	float					m_PosX;
	float					m_PosY;

	//�\���t���O
	//true:�\����
	bool					m_bShow;

	//�\����`
	CRectangle				m_SrcRect;

public:
	CEffect();
	~CEffect();

	//������
	void Initialize(int type);
	//��ʐ��ڎ��̏�����
	void InitializeIn_middle(void);

	//�G�t�F�N�g�J�n
	void Start(float px, float py);

	//�X�V
	void UpdateDP(CRectangle plrec);

	//�`��
	void Render(void);
	//�f�o�b�O�\��
	void RenderDebugging(void);

	//���
	void Release(void);

	//�e�N�X�`���̃|�C���^���󂯎��
	void SetTexture(CTexture* pt) { m_pTexture = pt; }

	//�v���C���[��`�擾
	CRectangle GetRect(void);

	//�\���������� true=�\����
	bool GetShow(void) { return m_bShow; }
	
};

