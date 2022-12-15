#pragma once
#include	"Define.h"
#include	"GameProgMgmt.h"
#include "MusicManager.h"
#include "EffectManager.h"
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
	CGameProgMgmt* m_GameProgMamt;
	CMusicMgmt* g_MusicManager;
	CEffectMgmt* g_EffectManeger;

public:
	CSceneBase() :
		m_GameProgMamt(),
		g_MusicManager(),
		g_EffectManeger(),
		m_bEnd(false),
		m_NextScene(SCENENO_TITLE),
		m_NowScene()
	{
	}
	virtual ~CSceneBase() {};
	virtual void Initialize(CGameProgMgmt* mamt,CMusicMgmt* musi, CEffectMgmt* effec) = 0;
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
	
};