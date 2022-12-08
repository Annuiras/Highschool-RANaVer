#pragma once
#include "Bar.h"

Bar::Bar() :
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_HitWidth(0.0f),
	m_Show(true),
	m_Type(0),
	m_Texture()
{};


Bar::~Bar() {


};

//������
void Bar::Initialize() {

	m_PosX = 0;
	m_PosY = 0;
	m_Type = 0;
	m_HitWidth = 0.0f;
	m_Show = false;
	m_Texture = NULL;
}

//�\���̂��ߏ���
//posy:Y���W
void Bar::Start(float posy, int type) {

	m_PosX = g_pGraphics->GetTargetWidth();
	m_PosY = posy;

	//�^�C�v������
	m_Type = type;

	m_Show = true;

	switch (type)
	{
	case BAR_BIG://��
		m_HitWidth = BAR_BIG_WIDTH;
		break;

	case BAR_MEDIUM://��
		m_HitWidth = BAR_MEDIUM_WIDTH;
		break;

	default:
		break;
	}

}

void Bar::Update(float over) {

	//�\�����̂�
	if (m_Show)
	{
		m_PosX -= over;

		//��ʊO�Ŕ�\��
		if (m_PosX + m_HitWidth < 0) {
			m_Show = false;
		}
	}
}

//�`��
void Bar::Render(void) {

	if (!m_Show) {
		return;
	}

	//�`��
	m_Texture->Render(m_PosX, m_PosY);
}

void Bar::RenderDebugging(void)
{	
	if (!m_Show) {
		return;
	}

	//����`��
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_GREEN);
}

CRectangle Bar::GetRect(void) {
	

	//�^�C�v�ʂő傫����ύX
	//����̑傫�����������m�肵�Ă��Ȃ��̂ŉ��u��
	switch (m_Type)
	{

	case BAR_BIG://��
		return CRectangle(m_PosX, m_PosY,
			m_PosX + BAR_BIG_WIDTH, m_PosY + BAR_BIG_HEIGHT);
		break;

	case BAR_MEDIUM://��
		return CRectangle(m_PosX, m_PosY,
			m_PosX + BAR_MEDIUM_WIDTH, m_PosY + BAR_MEDIUM_HEIGHT);
		break;

	default:
		//�G���[�̏ꍇ
		return CRectangle(m_PosX, m_PosY,
			m_PosX + BAR_BIG_WIDTH, m_PosY + BAR_BIG_HEIGHT);

		break;
	}
	
}

//�e�N�X�`�����Z�b�g
void Bar::SetTexture(CTexture* bartex)
{
	m_Texture = bartex;
}






