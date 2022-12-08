#pragma once
#include "Obstacle.h"


CObstacle::CObstacle() :

	m_PosX(0.0f),
	m_PosY(0.0f),
	m_Show(false),
	m_Type(0),
	m_HitWidth(0.0f),
	m_Textuer()

{};

CObstacle::~CObstacle() {

}


//������
void  CObstacle::Initialize() {

	m_PosX = 0;
	m_PosY = 0;
	m_Show = false;
	m_HitWidth = 0;
	m_Type = 0;

}

//����
void CObstacle::Start(float posy, int type) {

	m_PosX = g_pGraphics->GetTargetWidth();

	m_PosY = posy;

	m_Type = type;

	m_Show = true;

	m_HitWidth = m_Textuer->GetWidth();
}

void CObstacle::Update(float over) {

	//�\�����Ɏ��s
	if (m_Show)
	{
		m_PosX -= over;

		//��ʍ��[�ŏ���
		if (m_PosX + m_HitWidth < 0)
			m_Show = false;

	}
}

//OB�e�N�X�`�����Z�b�g
void CObstacle::SetTexture(CTexture* obtex) {
	m_Textuer = obtex;
}

//�`��
void CObstacle::Render() {

	//�\�����H
	if (!m_Show) {
		return;
	}
	m_Textuer->Render(m_PosX, m_PosY);
}

//�f�o�b�O�\��
void CObstacle::RenderDebugging(void) {

	if (!m_Show) {
		return;
	}

	//�_���[�W����
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_YELLOW);

	//��ɏ��锻��
	CGraphicsUtilities::RenderRect(GetTopBarRect(), MOF_COLOR_GREEN);
}


//�_���[�W��`�擾
CRectangle CObstacle::GetRect(void){

	//�^�C�v�ő傫���ύX����ꍇ
	switch (m_Type)
	{

	default:
		break;
	}

	//��{�͉摜�̑傫�����x
	return CRectangle(m_PosX, m_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y,
		m_PosX + m_Textuer->GetWidth(), m_PosY + m_Textuer->GetHeight());

}

//��Q����ɏ��铖���蔻��擾
CRectangle CObstacle::GetTopBarRect(void) {

	//�^�C�v�ʂő傫�����ꍇ
	switch (m_Type)
	{

	default:
		break;
	}
	return CRectangle(m_PosX, m_PosY + OB_HITRECT_SPACE_Y,
		m_PosX + m_Textuer->GetWidth(), m_PosY + OB_TOPBAR_HEIGHT + OB_HITRECT_SPACE_Y);

}
