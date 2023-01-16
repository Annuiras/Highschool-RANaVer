#include "Effect.h"
//����ҁF�c�� �A���c ����

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

	float DP_coma = 2.8;

	switch (type)
	{
		//�eDP
		case EFC_GET_SCHOLASTIC:		
		case EFC_GET_ACTION:
		case EFC_GET_IMAGINATION:
		case EFC_GET_COMMUNICATION:
		case EFC_GET_CHARM:

		case EFC_GET_SCHOLASTIC_AROOW:
		case EFC_GET_ACTION_AROOW:
		case EFC_GET_IMAGINATION_AROOW:
		case EFC_GET_COMMUNICATION_AROOW:
		case EFC_GET_CHARM_AROOW:
		{
			//�A�j���[�V�������쐬
			SpriteAnimationCreate anim[] = {

				//DP�擾�G�t�F�N�g
				{
					"�G�t�F�N�g",
					0,0,
					200,200,
					FALSE,{{DP_coma,0,0},{DP_coma,1,0},{DP_coma,2,0},{DP_coma,3,0},{DP_coma,4,0},{DP_coma,0,1},{DP_coma,1,1},{DP_coma,2,1},{DP_coma,3,1},{DP_coma,4,1},{DP_coma,0,2},{DP_coma,1,2},}
				},
			};
			m_Motion.Create(anim, 1);
			break;
		}
	}
}

//��ʐ��ڎ��̏�����
void CEffect::InitializeIn_middle(void)
{
	m_PosX = 0.0f;
	m_PosY = 0.0f;
	m_bShow = false;
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
	m_PosX = px;
	m_PosY = py;
	m_bShow = true;
	m_Motion.ChangeMotion(0);
}

/**
 * �X�V
 *
 */
void CEffect::UpdateDP(CRectangle plrec) {

	m_PosX = plrec.Left-80;
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

