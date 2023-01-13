#pragma once
#include "Define.h"
#include "SceneBase.h"

//�y�[�W��
#define P_Z 3

//�������Ȃ��ʒu
#define R_Not 1043
//�������Ȃ��ʒu
#define L_Not -557

class CTutorial:public CSceneBase
{
private:

	//�����e�N�X�`��
	CTexture ExTextTexture[P_Z];

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
	int gPosX[P_Z];

	//�摜�����J�E���g
	int count;

	//�ړ����t���O
	bool Is_Move;

	//X�������ɂǂꂾ����������
	int MoveX;

	//�����Ă邩�����ĂȂ���
	bool bShow;

	//�߂�{�^���ɃJ�[�\�������邩�Ȃ���
	bool TMenuCnt;

	//�w�i���l
	int m_BakAlph;


public:
	CTutorial();
	~CTutorial();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

