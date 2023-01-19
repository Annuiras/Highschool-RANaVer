#pragma once
#include "Define.h"
#include "GameProgMgmt.h"
#include "MusicManager.h"
#include "EffectManager.h"
#include "Menu.h"

//����ҁF�c�� ��

class CSceneBase {
protected:

	//�V�[���I���t���O
	//true:�I��
	bool		m_bEnd;

	//���݂̃V�[��
	tag_SCENENO m_NowScene;

	//���̃V�[��
	tag_SCENENO		m_NextScene;

	//�}�l�[�W���[�|�C���^
	CGameProgMgmt* b_GameProgMamt;
	CMusicMgmt* b_MusicManager;
	CEffectMgmt* b_EffectManeger;
	CMenu* b_MenuMamt;

	//���ڃt���O
	tag_SceneSituation b_Fadein;

	//���[�h��
	tag_LoadSituation b_LoadSitu;


public:
	CSceneBase() :

		b_GameProgMamt(),
		b_MusicManager(),
		b_EffectManeger(),
		b_Fadein(),
		b_LoadSitu(LOAD_YET),
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE),
		m_NowScene(SCENENO_TITLE)
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize(CGameProgMgmt* mamt,CMusicMgmt* musi, 
							CEffectMgmt* effec,CMenu* menu) = 0;
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RenderDebug() = 0;
	virtual void Release() = 0;


	//���̃V�[���擾
	int GetNextScene(void) { return m_NextScene; }

	//�I���t���O�擾
	bool IsEnd(void) { return m_bEnd; }

	//���݂̃V�[���擾
	int IsNow(void) { return m_NowScene; }

	//�q�N���X�ȊO����V�[���J��
	void SetEnd(bool b) { m_bEnd = b; }
	void SetNextScene(tag_SCENENO i) { m_NextScene = i; }

	//���[�h�󋵃Z�b�g
	void SetLoadSitu(tag_LoadSituation l) { b_LoadSitu = l; }
	//���[�h�󋵎擾
	tag_LoadSituation GetLoadSitu(void) { return b_LoadSitu; }

	//�t�F�[�h�C������
	//A:����������ϐ�
	//b:false�̏ꍇ�t�F�[�h��Ԃ�ύX���Ȃ�
	//�l��255�ɂȂ�ƃt�F�[�h��Ԃ�FADE_NOT�Ɉڍs������
	//return:�����������l
	float FadeIn(float A, bool b);

	//�t�F�[�h�A�E�g����
	//A:����������ϐ�
	//b:false�̏ꍇ�t�F�[�h��Ԃ�ύX���Ȃ�
	//�l��255�ɂȂ�ƃt�F�[�h��Ԃ�FADE_NEXT�Ɉڍs������
	//return:�����������l
	float FadeOut(float A, bool b);

};