#include "EffectManager.h"

#include	"EffectManager.h"

/**
 * �R���X�g���N�^
 *
 */
CEffectManager::CEffectManager() {
}

/**
 * �f�X�g���N�^
 *
 */
CEffectManager::~CEffectManager() {
}

/**
 * �ǂݍ���
 * ���p����e�N�X�`����ǂݍ��ށB
 */
bool CEffectManager::Load(void) {
	//�e�N�X�`���̓ǂݍ���
	char* name[] = {
		"�G�t�F�N�g��.png"
	};


	for (int i = 0; i < EFC_TYPECOUNT; i++)
	{
		if (!m_Texture[i].Load(name[i]))
		{
			return false;
		}
	}
	return true;
}

/**
 * ������
 * �p�����[�^�[����W������������B
 */
void CEffectManager::Initialize(void) {
	//�G�t�F�N�g�̊�b�ݒ�
	for (int type = 0; type < EFC_TYPECOUNT; type++)
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
CEffect* CEffectManager::Start(float px, float py, int type) {
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
void CEffectManager::Update(CRectangle plrec) {
	for (int type = 0; type < EFC_TYPECOUNT; type++)
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
void CEffectManager::Render(void) {
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Render();
		}
	}
}

//�f�o�b�O�\��
void CEffectManager::RenderDebugging(void)
{
	for (int type = 0; type < EFC_TYPECOUNT; type++)
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
void CEffectManager::Release(void) {
	for (int type = 0; type < EFC_TYPECOUNT; type++)
	{
		for (int mgmt = 0; mgmt < EFFECT_MGMT_COUNT; mgmt++)
		{
			m_Effect[type][mgmt].Release();
		}
		m_Texture[type].Release();
	}
}
