#pragma once
#include "Define.h"
//����ҁF�c�� �A�ΐ� �R�܁A�i�� �I��

class CObstacle
{

private:

	//���e�N�X�`��
	CTexture*	m_Textuer;

	//���W
	float m_PosX;
	float m_PosY;

	//�\���t���O:true�F�\��
	bool m_Show;

	//��Q���^�C�v�ʉ���
	float m_HitWidth;

	//�^�C�v
	int m_Type;

public:

	CObstacle();
	~CObstacle();

	//������
	void Initialize(void);

	//�X�V
	void Update(float over);

	//����
	//[posy]:Y���W
	//[type]:���
	void Start(float posy,int type);

	//OB�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* obtex);

	//�`��
	void Render(void);
	void RenderDebugging(void);


	//�_���[�W��`�擾
	CRectangle GetRect(void);

	//��Q����ɏ��铖���蔻��擾
	CRectangle GetTopBarRect(void);


	//�\�����t���O�擾
	bool Getshow(void) { return m_Show; }

	//��Q���^�C�v�擾
	bool GetType(void) { return m_Type; }

	//Y���W�擾
	float GetY(void) { return GetTopBarRect().Top; }

	//�\���t���O�Z�b�g
	void Setshow(bool b) { m_Show = b; }

};

