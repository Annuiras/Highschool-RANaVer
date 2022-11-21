#include "EffectManager.h"

#include	"EffectManager.h"

/**
 * �R���X�g���N�^
 *
 */
CEffectMgmt::CEffectMgmt() {
}

/**
 * �f�X�g���N�^
 *
 */
CEffectMgmt::~CEffectMgmt() {
}

/**
 * �ǂݍ���
 * ���p����e�N�X�`����ǂݍ��ށB
 */
bool CEffectMgmt::Load(void) {
	//�e�N�X�`���̓ǂݍ���
	char* name[] = {
		"�G�t�F�N�g��.png"
	};

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Effect");


	for (int i = 0; i < EFC_TYPE_COUNT; i++)
	{
		if (!m_Texture[i].Load(name[i]))
		{
			return false;
		}
	}

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("../");

	return true;
}

/**
 * ������
 * �p�����[�^�[����W������������B
 */
void CEffectMgmt::Initialize(void) {
	//�G�t�F�N�g�̊�b�ݒ�
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].SetTexture(&m_Texture[type]);
			m_Effect[type][mgmt].Initialize(type);
		}
	}
}

/**
 * �J�n
 * ���W��ݒ肵�ă��[�V�������J�n����B
 *
 * ����
 * [in]			px					X���W
 * [in]			py					Y���W
 * [in]			mgmt				�G�t�F�N�g�^�C�v
 */
CEffect* CEffectMgmt::Start(float px, float py, tag_EFFECTTYPE type) {
	for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
	{
		if (m_Effect[type][mgmt].GetShow())
		{
			continue;
		}
		m_Effect[type][mgmt].Start(px, py);
		return &m_Effect[type][mgmt];
	}
	return NULL;
}

/**
 * �X�V
 *
 */
void CEffectMgmt::Update(CRectangle plrec) {
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			switch (type)
			{

			case EFC_GET_DP:
				m_Effect[type][mgmt].Update(plrec);

				break;
			default:
				break;
			}
		}
	}
}

/**
 * �`��
 *
 */
void CEffectMgmt::Render(void) {
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Render();
		}
	}
}

//�f�o�b�O�\��
void CEffectMgmt::RenderDebugging(void)
{
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].RenderDebugging();
		}
	}

}

/**
 * ���
 *
 */
void CEffectMgmt::Release(void) {
	for (int type = 0; type < EFC_TYPE_COUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Release();
		}
		m_Texture[type].Release();
	}
}
