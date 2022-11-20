#include "Effect.h"

/**
 * �R���X�g���N�^
 *
 */
CEffect::CEffect() :
	m_pTexture(NULL),
	m_Motion(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_bShow(false),
	m_SrcRect() {
}

/**
 * �f�X�g���N�^
 *
 */
CEffect::~CEffect() {
}

/**
 * �J�n
 * �p�����[�^�[����W������������B
 *
 * ����
 * [in]			type				�^�C�v
 */
void CEffect::Initialize(int type) {
	m_PosX = 0.0f;
	m_PosY = 0.0f;
	m_bShow = false;
	switch (type)
	{
	case EFC_GET_DP:
	{
		//�A�j���[�V�������쐬
		SpriteAnimationCreate anim[] = {
			//�_���[�W
			{
				"�G�t�F�N�g",
				0,0,
				200,200,
				FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,0,1},{2,1,1},{2,2,1},{2,3,1},{2,4,1},{2,0,2},{2,1,2},}
			},
		};
		m_Motion.Create(anim, 1);
		break;
	}
	//case EFC_EXPLOSION01:
	//{
	//	//�A�j���[�V�������쐬
	//	SpriteAnimationCreate anim[] = {
	//		//�_���[�W
	//		{
	//			"�G�t�F�N�g",
	//			0,0,
	//			120,120,
	//			FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},{3,11,0},{3,12,0},{3,13,0},{3,14,0},{3,15,0}}
	//		},
	//	};
	//	m_Motion.Create(anim, 1);
	//	break;
	//}
	//case EFC_EXPLOSION02:
	//{
	//	//�A�j���[�V�������쐬
	//	SpriteAnimationCreate anim[] = {
	//		//�_���[�W
	//		{
	//			"�G�t�F�N�g",
	//			0,0,
	//			180,180,
	//			FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},
	//					{3,0,1},{3,1,1},{3,2,1},{3,3,1},{3,4,1},{3,5,1},{3,6,1},{3,7,1},{3,8,1},{3,9,1},{3,10,1}}
	//		},
	//	};
	//	m_Motion.Create(anim, 1);
	//	break;
	//}
	}
}

/**
 * �J�n
 * ���W��ݒ肵�ă��[�V�������J�n����B
 *
 * ����
 * [in]			px					X���W
 * [in]			py					Y���W
 */
void CEffect::Start(float px, float py) {
	m_SrcRect = m_Motion.GetSrcRect();
	m_PosX = px /*- m_SrcRect.GetWidth() * 0.5f*/;
	m_PosY = py /*- m_SrcRect.GetHeight() * 0.5f*/;
	m_bShow = true;
	m_Motion.ChangeMotion(0);
}

/**
 * �X�V
 *
 */
void CEffect::Update(CRectangle plrec) {
	//��\��
	if (!m_bShow)
	{
		return;
	}

	m_PosX = plrec.Left-30;
	m_PosY = plrec.Top;

	//�A�j���[�V�����̍X�V
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
	//�A�j���[�V�����̏I���Ŕ�\���ɂ���
	if (m_Motion.IsEndMotion())
	{
		m_bShow = false;
	}
}

/**
 * �`��
 *
 */
void CEffect::Render() {
	//��\��
	if (!m_bShow)
	{
		return;
	}
	//�e�N�X�`���̕`��
	m_pTexture->Render(m_PosX, m_PosY, m_SrcRect);
}

//�f�o�b�O�\��
void CEffect::RenderDebugging(void)
{
	if (!m_bShow)
	{
		return;
	}
	CGraphicsUtilities::RenderRect(GetRect(), MOF_COLOR_HGREEN);
}


/**
 * ���
 *
 */
void CEffect::Release(void) {
	m_Motion.Release();
}

CRectangle CEffect::GetRect(void)
{
	
	return CRectangle(m_PosX, m_PosY,
		m_PosX + 200, m_PosY + 200);
	
}

