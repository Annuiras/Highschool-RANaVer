#pragma once
#include "Define.h"
#include "SceneBase.h"

class CTutorial:public CSceneBase
{
private:

	//�w�i�e�N�X�`��
	CTexture BGTexture;

	//�����w�i�e�N�X�`��
	CTexture ScreenBGTexture;

	//�J�[�e�������e�N�X�`���i����폜�j
	CTexture CurtainBGTexture;

	//�߂�{�^���e�N�X�`��
	CTexture BackButton;

	//�I��g
	CTexture ButtonSelect;

	//�X�N���[���l
	int m_Scroll;

	//���W�l�iX�������j
	int gPosX;

	//�摜�����J�E���g
	int count;

	//X�������ɂǂꂾ����������
	int MoveX;

	//�����Ă邩�����ĂȂ���
	bool bShow;

	//�߂�{�^���ɃJ�[�\�������邩�Ȃ���
	int TMenuCnt;

public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	bool Load(void);
	void Release(void);
};

