#pragma once

#include	"Mof.h"
#include "Define.h"

class CEffect
{	
private:
	CTexture* m_pTexture;
	CSpriteMotionController	m_Motion;
	float					m_PosX;
	float					m_PosY;
	bool					m_bShow;
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
	void Update(CRectangle plrec);

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

