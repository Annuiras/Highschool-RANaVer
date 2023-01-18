#pragma once
#include "Define.h"
//////////////////////////////////////////////
//	DP�̃v���O�����ł�			�@�@�@�@�@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

//���ʂɑ��݂���ő�DP
#define DP_VOLUME	40

class DetailPoint
{
private:

	//���W
	float m_PosX;
	float m_PosY;

	//�\���t���O
	//true:�\����
	bool m_Show;

	//DP�e�N�X�`��
	CTexture* m_Texture;

	//DP�^�C�v
	int m_Type;

	//�����蔻��
	float	m_HitboxX;
	float	m_HitboxY;

public:

	DetailPoint();
	~DetailPoint();

	//�`��
	void Render(void);

	//������
	void Initialize(void);

	//DP�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* dptex);

	//�\���J�n
	void Start(float posy, int type);

	//[scroll]�F�X�N���[���l
	void Update(float scroll);

	void RenderDebugging(void);

	CRectangle GetRect(void) {

		return CRectangle(m_PosX, m_PosY,
			m_PosX + m_HitboxX, m_PosY + m_HitboxY);
	}

	//DP�̎�ނ��擾
	int Gettype(void) { return m_Type; }

	//�\��true�F��\��false�t���O
	bool Getshow(void) { return m_Show; }

	//DP�̕\���؂�ւ�
	void Setshow(bool b) { m_Show = b; }

};

