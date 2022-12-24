#pragma once
#include "MusicManager.h"
#include "EffectManager.h"
#include "Define.h"

//�Q�[����ʒ��̃��U���g�N���X
class CResult
{
private:

	//���Ԍ��ʈʒu
	float m_PosX_Bak;
	float m_PosY_Bak;

	//�t�F�[�h�󋵂��L�^
	tag_SceneSituation m_FadeSitu;

	//�\���t���O
	//true:�\����
	bool m_Show;

	//���U���g�I���t���O
	//true:�I��
	bool m_Endflg;

	//�������σt���O
	bool m_Initializeflg;

	//���Ԍ��ʔw�i
	CTexture m_Bak_MiddleResult;

	//3�N�����ʔw�i
	CTexture m_Bak_LastResult;

	//SE�EBGM�}�l�[�W���[
	CMusicMgmt* m_MusicMgmt;

	//�G�t�F�N�g�}�l�[�W���[
	CEffectMgmt* m_pEffectMgmt;


public:

	CResult();
	~CResult();

	//�f�ރ��[�h
	bool Load(void);

	//������
	void Initialize(void);

	//�\���J�n
	void Start(void);

	//�X�V
	void Update(void);

	//���ԕ񍐕`��
	void RenderMiddleResult(void);

	//�ŏI�񍐕`��
	void RenderLastResult(void);

	//�f�o�b�O�\��
	void RenderDebugging(void);

	//���
	void Release(void);

	//SE�EBGM�}�l�[�W���[�Z�b�g
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//�G�t�F�N�g�}�l�[�W���[�Z�b�g
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }

	//�\�����t���O
	bool GetShow(void) { return m_Show; }

	//�I���t���O��n��
	bool GetEndflg(void) { return m_Endflg; }
};

