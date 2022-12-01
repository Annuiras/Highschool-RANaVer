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

bool CEnemy::Load()
{
	//���u��
	int n = 2;
	//�A�j���[�V����
	SpriteAnimationCreate anim[] =
	{
		{
			//"�ړ�",
			//0,70,
			//60,64,
			//TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}

			//�����[�V�����p
			"�ړ�",
			0, 0,
			160, 185,
			TRUE,{ {n,0,0},{n,1,0},{n,2,0},{n,3,0},{n,4,0},{n,5,0},{n,6,0},{n,7,0},{n,8,0},{n,9,0},{n,10,0}
			,{n,11,0},{n,12,0},{n,13,0},{n,14,0},{n,15,0},{n,16,0} }

		},
	};
	m_Motion.Create(anim, MOTION_COUNT);
	return true;
}

void CEnemy::Initialize()
{
	ene_PosX = 0;
	ene_PosY = 0;
	ene_Type = 0;
	ene_Show = false;
}

void CEnemy::Start(float posy, int type)
{
	ene_PosX = g_pGraphics->GetTargetWidth();

	ene_PosY = posy;

	ene_Type = type;

	ene_Show = true;

}

void CEnemy::Update(float over)
{
	//todo �G����ʏ�ɂ��鎞�A����
	if (ene_Show)
	{
		m_Motion.ChangeMotion(MOTION_MOVE);
		ene_PosX -= over * 1.5;		//*1.5�͑����̒l�ł�
	}
	//�A�j���[�V�����Đ�
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
}

void CEnemy::Render()
{
	if (!ene_Show) {
		return;
	}
	ene_Texture->Render(ene_PosX, ene_PosY);
}

void CEnemy::RenderDebug()
{
	if (!ene_Show) {
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(ene_Type), MOF_COLOR_RED);
}

CRectangle CEnemy::GetRect(int type)
{
	//�^�C�v�ʂő傫����ύX
	switch (type)
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

void CEnemy::Release()
{
	ene_Texture->Release();
}