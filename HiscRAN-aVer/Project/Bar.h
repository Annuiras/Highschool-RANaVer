#pragma once
#include "Define.h"
//////////////////////////////////////////////
//	����̃o�[�i����҂j�̃v���O�����ł��@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

class Bar
{
private:

	//����̃e�N�X�`����ǉ�
	//����e�N�X�`��
	CTexture* m_Texture;


	//���W
	float m_PosX;
	float m_PosY;

	//����^�C�v�ʉ���
	float m_HitWidth;

	//�\���t���O:true�F�\��
	bool m_Show;

	//�^�C�v
	int m_Type;

public:

	Bar();
	~Bar();

	//������
	void Initialize(void);

	//�X�V
	void Update(float over);

	//����
	void Start(float posy, int type);

	//�`��
	void Render(void);
	void RenderDebugging(void);

	//�����蔻��n��
	CRectangle GetRect(void);

	//Y���W��n��
	float GetY(void) { return m_PosY; }

	//�\�����H
	//true:�\����
	bool Getshow(void) { return m_Show; }

	//�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* bartex);

	//����̎�ނ��擾
	int Gettype(void) { return m_Type; }


};

