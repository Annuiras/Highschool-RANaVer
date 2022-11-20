#pragma once
#include "Menu.h"
#include "SceneBase.h"
#include "MusicManager.h"
#include "EffectManager.h"
#include "Define.h"
#include "GameApp.h"
#include "Player.h"
#include "Stage.h"


class CGAME :public CSceneBase
{

private:
	CMenu			gMenu;
	bool			Menuflag = false;
	int				gMenuItemCount = 2;

	//�G�t�F�N�g�}�l�[�W���[
	CEffectMgmt g_EffectManeger;

	//SE�EBGM�}�l�[�W���[
	CMusicMgmt g_MusicManager;

	//�v���C���[�N���X
	CPlayer g_Player;

	//�X�e�[�W�N���X
	CStage g_Stage;


	bool Clearflag = false;
	bool GameOverflag = false;



public:
	CGAME();
	~CGAME();
	void Initialize(CGameProgMgmt* mamt);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);


};

