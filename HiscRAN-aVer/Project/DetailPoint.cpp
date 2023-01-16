#pragma once
#include "DetailPoint.h"

//����ҁF�c�� �A�ΐ� �R�܁A�i�� �I��

DetailPoint::DetailPoint() :
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_Show(false),
	m_HitboxX(0.0f),
	m_HitboxY(0.0f),
	m_Texture(NULL),
	m_Type(0)
{};

DetailPoint::~DetailPoint() {



};

//�e�N�X�`�����Z�b�g
void DetailPoint::SetTexture(CTexture* dptex) {

	m_Texture = dptex;

}


//DP�̐��l������
void DetailPoint::Initialize(void) {

	m_PosX = 0;
	m_PosY = 0;
	m_Type = 0;
	m_HitboxX = 0;
	m_HitboxY = 0;
	m_Show = false;
}


//�\�����߂̏���
void DetailPoint::Start(float posy, int type) {

	m_PosX = g_pGraphics->GetTargetWidth();

	m_PosY = posy;

	//�R�C�����
	m_Type = type;

	//�\���t���O
	m_Show = true;

	//�摜�T�C�Y�ƍ��킹��
	m_HitboxX = m_Texture->GetWidth();
	m_HitboxY = m_Texture->GetHeight();
}


void DetailPoint::Update(float scroll) {

	//�\�����Ɏ��s
	if (m_Show)
	{
		m_PosX -= scroll;

		//��ʍ��[�ŏ���
		if (m_PosX + m_HitboxX < 0) {
			m_Show = false;
		}
	}
}

//�`��
void DetailPoint::Render(void) {

	if (!m_Show) {
		return;
	}

	m_Texture->Render(m_PosX, m_PosY);

}

void DetailPoint::RenderDebugging() {
	
	if (!m_Show) {
		return;
	}

	CGraphicsUtilities::RenderRect(m_PosX, m_PosY, m_PosX + m_HitboxX, m_PosY + m_HitboxY, MOF_COLOR_YELLOW);


}

