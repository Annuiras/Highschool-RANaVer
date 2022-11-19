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
	for (int j = 0; j < EFC_TYPECOUNT; j++)
	{
		for (int i = 0; i < EFFECTCOUNT; i++)
		{
			m_Effect[i][j].SetTexture(&m_Texture[j]);
			m_Effect[i][j].Initialize(j);
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
 * [in]			type				�G�t�F�N�g�^�C�v
 */
CEffect* CEffectManager::Start(float px, float py, int type) {
	for (int i = 0; i < EFFECTCOUNT; i++)
	{
		if (m_Effect[i][type].GetShow())
		{
			continue;
		}
		m_Effect[i][type].Start(px, py);
		return &m_Effect[i][type];
	}
	return NULL;
}

/**
 * �X�V
 *
 */
void CEffectManager::Update(void) {
	for (int j = 0; j < EFC_TYPECOUNT; j++)
	{
		for (int i = 0; i < EFFECTCOUNT; i++)
		{
			//todo;�^�C�v�ʂōX�V���e��ύX����H�v����
			m_Effect[i][j].Update();
		}
	}
}

/**
 * �`��
 *
 */
void CEffectManager::Render(void) {
	for (int j = 0; j < EFC_TYPECOUNT; j++)
	{
		for (int i = 0; i < EFFECTCOUNT; i++)
		{
			m_Effect[i][j].Render();
		}
	}
}


/**
 * ���
 *
 */
void CEffectManager::Release(void) {
	for (int j = 0; j < EFC_TYPECOUNT; j++)
	{
		for (int i = 0; i < EFFECTCOUNT; i++)
		{
			m_Effect[i][j].Release();
		}
		m_Texture[j].Release();
	}
}
