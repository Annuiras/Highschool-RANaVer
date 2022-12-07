#include "Enemy.h"

//todo �G

CEnemy::CEnemy() :
	ene_PosX(0),
	ene_PosY(0),
	ene_Show(false) {
}

CEnemy::~CEnemy()
{
}

//�e�N�X�`�����Z�b�g
void CEnemy::SetTexture(CTexture* enetex) {

	ene_Texture = enetex;

}

void CEnemy::SetAnime(CSpriteMotionController* eneanim)
{

	m_Motion = eneanim;
}

void CEnemy::Initialize()
{
	ene_PosX = 0;
	ene_PosY = 0;
	ene_SpeedY = 0;
	ene_Type = 0;
	ene_Show = false;
}

void CEnemy::Start(float posy, int type)
{
	//��ʉE�[�ɐ���
	ene_PosX = g_pGraphics->GetTargetWidth();

	ene_PosY = posy;

	ene_Type = type;

	ene_Show = true;

}

void CEnemy::Update(float over)
{
	//todo �G����ʏ�ɂ��鎞�A����
	if (!ene_Show)
		return;
	
	if (m_Motion->GetMotionNo() != MOTION_MOVE) {
		m_Motion->ChangeMotion(MOTION_MOVE);
	}
	ene_PosX -= over * 1.5;		//*1.5�͑����̒l�ł�

	//�A�j���[�V�����Đ�
	m_Motion->AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion->GetSrcRect();

	//�G�𔽓]������
	float r = m_SrcRect.Right;
	m_SrcRect.Right = m_SrcRect.Left;
	m_SrcRect.Left = r;

	//�d�͔��f
	ene_SpeedY += GRAVITY;

	//���~���x�N���b�v�ǉ�
	if (ene_SpeedY >= 10) {
		ene_SpeedY = 10 - 0.1f;
	}

	//�X�s�[�h���f
	ene_PosY += ene_SpeedY;

	//�n�ʂ��������H
	if (ene_PosY + m_SrcRect.GetHeight() >= GROUND_Y) {
		//�n�ʂ������ɍs���Ȃ��悤�ɒ���
		SetPosY(GROUND_Y);
	}

	//��ʍ��[�ŏ���
	if (ene_PosX + ENEMY_SIZE_WIDTH < 0) {
		ene_Show = false;
	}

}

void CEnemy::Render()
{
	if (!ene_Show) {
		return;
	}


	ene_Texture->Render(ene_PosX, ene_PosY, m_SrcRect);
}

void CEnemy::RenderDebug()
{
	if (!ene_Show) {
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_RED);
}

CRectangle CEnemy::GetRect(void)
{
	//�^�C�v�ʂő傫����ύX
	switch (ene_Type)
	{
	case ENEMY_1://�G1		
		return CRectangle(ene_PosX, ene_PosY,
			ene_PosX + ENEMY_SIZE_WIDTH, ene_PosY + ENEMY_SIZE_HEIGHT);
		break;

	default:
		//�G���[�̏ꍇ
		return CRectangle(ene_PosX, ene_PosY,
			ene_PosX + ENEMY_SIZE_WIDTH, ene_PosY + ENEMY_SIZE_HEIGHT);
		break;
	}
}

void CEnemy::SetPosY(float y)
{
	ene_PosY = y - ENEMY_SIZE_HEIGHT;
	ene_SpeedY = 0;
}

void CEnemy::Release()
{
	ene_Texture->Release();
}