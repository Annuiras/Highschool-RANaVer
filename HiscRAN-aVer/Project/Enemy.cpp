#include "Enemy.h"

//////////////////////////////////////////////
//	�G�̃v���O�����ł�			�@�@�@�@�@�@//
//									�@�@�@�@//
//�@�쐬�ҁF�c�� �A�ΐ� �R�܁A�i�� �I���@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

CEnemy::CEnemy() :
	m_PosX(0),
	m_PosY(0),
	m_MoveY(),
	m_Texture(),
	m_Motion(),
	m_Show(false) {
}

CEnemy::~CEnemy()
{
}

//�e�N�X�`�����Z�b�g
void CEnemy::SetTexture(CTexture* enetex) {

	m_Texture = enetex;

}

//�A�j���[�V�������Z�b�g
void CEnemy::SetAnime(CSpriteMotionController* eneanim)
{
	m_Motion = eneanim;
}

//������
void CEnemy::Initialize()
{
	m_PosX = 0;
	m_PosY = 0;
	m_MoveY = 0;
	m_Show = false;
}

//����
void CEnemy::Start(float posy, int type)
{
	//��ʉE�[�ɐ���
	m_PosX = g_pGraphics->GetTargetWidth();

	m_PosY = posy;

	m_Show = true;

}

//scroll:�X�e�[�W�X�N���[���l
void CEnemy::Update(float scroll)
{
	//�G����ʏ�ɂ��鎞�A����
	if (!m_Show)
		return;
	
	//�ړ����[�V����
	if (m_Motion->GetMotionNo() != MOTION_MOVE) {
		m_Motion->ChangeMotion(MOTION_MOVE);
	}

	//�G�����ɐi�܂���
	m_PosX -= scroll * 1.5;

	//�A�j���[�V�����Đ�
	m_Motion->AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion->GetSrcRect();

	//�G�𔽓]������
	float r = m_SrcRect.Right;
	m_SrcRect.Right = m_SrcRect.Left;
	m_SrcRect.Left = r;

	//�d�͔��f
	m_MoveY += GRAVITY;

	//���~���x�N���b�v�ǉ�
	if (m_MoveY >= 10) {
		m_MoveY = 10 - 0.1f;
	}

	//�X�s�[�h���f
	m_PosY += m_MoveY;

	//�n�ʂ��������H
	if (m_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {
		//�n�ʂ������ɍs���Ȃ��悤�ɒ���
		SetPosY(GROUND_Y);
	}

	//��ʍ��[�ŏ���
	if (m_PosX + ENEMY_SIZE_WIDTH < 0) {
		m_Show = false;
	}

}

void CEnemy::Render()
{
	if (!m_Show) {
		return;
	}

	m_Texture->Render(m_PosX, m_PosY, m_SrcRect);
}

void CEnemy::RenderDebug()
{
	if (!m_Show) {
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
}

CRectangle CEnemy::GetRect(void)
{
	return CRectangle(m_PosX, m_PosY,
		m_PosX + ENEMY_SIZE_WIDTH, m_PosY + ENEMY_SIZE_HEIGHT);
}

//Y���W�𒲐�
//y:��������x���W
void CEnemy::SetPosY(float y)
{
	m_PosY = y - ENEMY_SIZE_HEIGHT;
	m_MoveY = 0;
}

void CEnemy::Release()
{
	m_Texture->Release();
}