/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"Define.h"
#include	"Title.h"
#include	"ModeSelect.h"
#include	"Tutorial.h"
#include	"GAME.h"
#include	"GameOver.h"
#include	"GameClear.h"
#include	"Gallery.h"
#include	"Option.h"
#include	"GameProgMgmt.h"
#include	"Menu.h"
#include	"DPDecision.h"
#include	"Load.h"

//�f�o�b�O
bool		gDebagflag = false;

//�V�[���x�[�X�N���X�|�C���^
CSceneBase* gpScene = NULL;

//�Q�[���Ǘ��N���X
CGameProgMgmt g_GameProgMamt;

//�G�t�F�N�g�}�l�[�W���[
CEffectMgmt g_EffectManeger;

//SE�EBGM�}�l�[�W���[
CMusicMgmt g_MusicManager;

//���j���[�N���X
CMenu		g_Menu;
int			gMenuItemCount = 2;

//���[�h��ʃN���X
CLoad gLoad;

//�G�t�F�N�g,�~���[�W�b�N,���j���[,���[�h�t���O
tag_LoadSituation Eff_Loadflg = LOAD_YET, Mu_Loadflg = LOAD_YET, Me_Loadflg = LOAD_YET;

//�ŏ��̃V�[���ɕK�v�ȃG�t�F�N�g�A�~���[�W�b�N,���j���[�����[�h�F�������o���Ă��邩
//true::���[�h�o���Ă���
bool LoadCheckInitial(void) {

	bool flg = true;
	if (Eff_Loadflg != LOAD_DONE|| Mu_Loadflg != LOAD_DONE|| Me_Loadflg != LOAD_DONE) {
		flg = false;
	}

	return flg;
}

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Resource");

	//�ŏ��Ɏ��s�����,�}�l�[�W���[�̏����� 
	g_GameProgMamt.Initialize();

	//���[�h��ʑf��
	gLoad.Load();

	//���[�h��ʏ�����
	gLoad.Initialize(0, 100);

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();

	//�f�o�b�O�؂�ւ�
	if(g_pInput->IsKeyPush(MOFKEY_BACKSPACE))
	gDebagflag = gDebagflag ? !gDebagflag : !gDebagflag;

	//���[�h��ʍX�V
	gLoad.Update();

	//�G�t�F�N�g�����[�h�O�̏ꍇ
	if (Eff_Loadflg == LOAD_YET && !gLoad.Thread_Load.joinable()) {
		//���[�h�������X���b�h�ɓn��
		//�߂�l���L�^����
		gLoad.Thread_Load = thread{ [] {Eff_Loadflg = g_EffectManeger.Load(); } };
	}
	//���������[�h�O�̏ꍇ
	else 
	if (Mu_Loadflg == LOAD_YET && !gLoad.Thread_Load.joinable())
	{
		//���[�h�������X���b�h�ɓn��
		//�߂�l���L�^����
		gLoad.Thread_Load = thread{ [] {Mu_Loadflg=g_MusicManager.Load(); } };
	}
	else
	//���j���[�����[�h�O�̏ꍇ
	if (Me_Loadflg == LOAD_YET && !gLoad.Thread_Load.joinable())
	{
		//���[�h�������X���b�h�ɓn��
		//�߂�l���L�^����
		gLoad.Thread_Load = thread{ [] {Me_Loadflg = g_Menu.Load(); } };

	}

	//�G�t�F�N�g�����[�h������Ԃ̏ꍇ
	if (Eff_Loadflg == LOAD_COMP) {
		//�X���b�h���
		gLoad.Thread_Load.join();
		//������
		g_EffectManeger.Initialize();
		//�t���O�X�V
		Eff_Loadflg = LOAD_DONE;
	}

	//�~���[�W�b�N�����[�h������Ԃ̏ꍇ
	if (Mu_Loadflg == LOAD_COMP) {
		//�X���b�h���
		gLoad.Thread_Load.join();
		//������
		g_MusicManager.Initialize(0.2,0.2);
		//�t���O�X�V
		Mu_Loadflg = LOAD_DONE;
	}

	//���j���[�����[�h������Ԃ̏ꍇ
	if (Me_Loadflg == LOAD_COMP) {
		//�X���b�h���
		gLoad.Thread_Load.join();

		//���j���[�Ƀ}�l�[�W���[���Z�b�g
		g_Menu.SetEffectManager(&g_EffectManeger);
		g_Menu.SetMusicManager(&g_MusicManager);

		//�t���O�X�V
		Me_Loadflg = LOAD_DONE;
	}


	//�G�t�F�N�g�A�~���[�W�b�N,���j���[�����[�h�F�������o���Ă��Ȃ��ꍇ�͍X�V�I��
	if (!LoadCheckInitial()) {
		return TRUE;
	}

	//�V�[�����܂��������Ă��Ȃ��ꍇ
	//�ŏ��̃V�[���𐶐�
	if (gpScene == nullptr) {

		gpScene = new CTutorial();
		gLoad.Thread_Load = thread{ [=] {gpScene->Load(); } };
		gLoad.Initialize(0,100);
	}


	//�V�[���̃��[�h������
	if (gpScene->GetLoadSitu() == LOAD_COMP)
	{
		//�X���b�h���
		gLoad.Thread_Load.join();

		//�V�[���̏�����
		gpScene->Initialize(&g_GameProgMamt, &g_MusicManager, &g_EffectManeger,&g_Menu);

		//�t���O�X�V
		gpScene->SetLoadSitu(LOAD_DONE);
	}
	else
	//���[�h�O���G���[���͍X�V�Ȃ�
	if ((gpScene->GetLoadSitu() == LOAD_YET || gpScene->GetLoadSitu() == LOAD_ERROR)||
		!gLoad.IsLoadEnd()){
		return TRUE;
	}
	
	//�V�[���̍X�V
	gpScene->Update();
	

	//��ʑJ�ڊ��������ꍇ
	if (gpScene->IsEnd()) {

		//���
		gpScene->Release();

		//���̃V�[�����擾 
		int change = gpScene->GetNextScene();

		//�Â��V�[������������ 
		delete gpScene;

		//���̃V�[���ԍ��ɉ����ăV�[��������ď��������� 
		switch (change)
		{
			//�^�C�g�����
		case SCENENO_TITLE:
			gpScene = new CTitle();
			break;

			//���[�h�Z���N�g���
		case SCENENO_SELECTMODE:
			gpScene = new CModeSelect();
			break;

			//�`���[�g���A�����
		case SCENENO_TUTORIAL:
			gpScene = new CTutorial();
			break;

			//DP�ڕW�ݒ���
		case SCENENO_DPDECISION:
			gpScene = new CDPDecision();
			break;

			//�Q�[�����
		case SCENENO_GAME:
			gpScene = new CGAME();
			//���[�h���X���b�h�n��
			gLoad.Thread_Load = thread{ [=] {gpScene->Load(); } };
			//���[�h��ʂ̏�����
			gLoad.Initialize(255,100);
			break;

			//�Q�[���I�[�o�[���
		case SCENENO_GAMEOVER:
			gpScene = new CGameOver();
			break;

			//�Q�[���N���A���
		case SCENENO_GAMECLEAR:
			gpScene = new CGameClear();
			break;

			//�M�������[���
		case SCENENO_GALLERY:
			gpScene = new CGallery();
			break;

			//�I�v�V�������
		case SCENENO_OPTION:
			gpScene = new COption();
			break;

		}
		//������
		g_EffectManeger.InitializeIn_middle();

		//�X���b�h�������ĂȂ��ꍇ������
		if (!gLoad.Thread_Load.joinable()) {
			gpScene->Initialize(&g_GameProgMamt, &g_MusicManager, &g_EffectManeger, &g_Menu);
		}

	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0);

	//�`��
	//�������[�h�ŃG���[���N�����ꍇ
	if (Eff_Loadflg == LOAD_ERROR || Mu_Loadflg == LOAD_ERROR) {
		gLoad.RenderError();
	}
	else
	//�V�[�������O
	//�V�[���̃��[�h�O
	//���[�h��ʏI���O�̏ꍇ
	if(gpScene == nullptr||gpScene->GetLoadSitu()== LOAD_YET||!gLoad.IsLoadEnd())
	{
		//���[�h���
		gLoad.RenderLoad();
	}
	else
	//�V�[���̃��[�h�ŃG���[���o���ꍇ
	if (gpScene->GetLoadSitu() == LOAD_ERROR) {
		gLoad.RenderError();
	}
	else
	{
		//�V�[�����
		gpScene->Render();

		if (gDebagflag)
		{
			if (gpScene != nullptr) {
				//�f�o�b�O�`��
				gpScene->RenderDebug();
			}
			else
			{
				gLoad.RenderDebug();
			}
		}

	}


	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){


	if (gpScene != nullptr) {
		gpScene->Release();
	}
	g_EffectManeger.Release();
	g_MusicManager.Release();
	g_Menu.Release();
	gLoad.Release();

	if (gLoad.Thread_Load.joinable()) {
		gLoad.Thread_Load.detach();
	}

	return TRUE;
}