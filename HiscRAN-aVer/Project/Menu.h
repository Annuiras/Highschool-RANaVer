#pragma once
#include "EffectManager.h"
#include "MusicManager.h"
#include "Define.h"

//����ҁF���Y ���H �A�c�� ��

//���j���[�Ǘ��N���X�ł�
class CMenu
{
private:

	//�}�l�[�W���[
	CMusicMgmt* m_MusicMamt;
	CEffectMgmt* m_EffectMamt;

	//�A�v���P�[�V�����I�����j���[
	CTexture	m_MenuEndTexture;

	//�Q�[���|�[�Y���j���[
	CTexture	m_MenuPauseTexture;

	//DP�I�����胁�j���[
	CTexture	m_MenuDPTexture;

	//DP�I�����莞��DP��ނ܂Ƃ�
	CTexture	m_MenuDPTexTexture;

	//���j���[�I���`�F�b�N�}�[�N
	CTexture	m_MenuCheck;

	float		m_cx;
	float		m_cy;

	//�I������
	int			m_Count;

	//�I�����ԍ�
	int			m_Select;

	//�\���t���O
	//true:�\����
	bool		m_bShow;

	//����t���O
	//true:����ς�
	bool		m_bEnter;

	//���
	tag_MenuType m_Type;

	CRectangle		m_Rect;

public:
	CMenu();
	~CMenu();
	
	//�f�ރ��[�h
	tag_LoadSituation Load(void);

	void Release(void);

	//�\��
	//Type�F���j���[���
	void Show(tag_MenuType Type);

	//��\������
	void Hide(void) { m_bShow = false; }

	//�X�V
	void Update(void);

	//�`��
	void Render(void);

	//DP�I���m��p�`��
	void Render(int Type);

	//�\����?
	//true�F�\����
	bool IsShow(void) { return m_bShow; }

	//���ڌ���?
	//true:����ς�
	bool IsEnter(void) { return m_bEnter; }

	//�I�����ԍ��擾
	int  GetSelect(void) { return m_Select; }

	//SE�EBGM�}�l�[�W���[�Z�b�g
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMamt = mgmt; }

	//�G�t�F�N�g�}�l�[�W���[�Z�b�g
	void SetEffectManager(CEffectMgmt* mgmt) { m_EffectMamt = mgmt; }

	//���j���[�̎�ނ��擾
	tag_MenuType GetMenuType(void) {return m_Type;}

	//�I�����̐����擾
	//int  GetCount(void) { return m_Count; }

};