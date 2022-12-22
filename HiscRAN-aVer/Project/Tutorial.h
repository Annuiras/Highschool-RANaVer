#pragma once
#include "Define.h"
#include "SceneBase.h"

class CTutorial:public CSceneBase
{
private:

	//�����e�N�X�`��
	CTexture ExTextTexture;

	//�w�i�e�N�X�`��
	CTexture BGTexture;

	//�X�N���[���e�N�X�`��
	CTexture ScreenTexture;

	//�J�[�e�������e�N�X�`��
	CTexture CurtainBGTexture;

	//�J�[�e�������e�N�X�`����
	CTexture CurtainBGTextureLeft;

	//�J�[�e�������e�N�X�`���E
	CTexture CurtainBGTextureRight;

	//�J�[�e����
	CTexture CurtainBGTextureTop;

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

	//�w�i���l
	int m_BakAlph;


public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

