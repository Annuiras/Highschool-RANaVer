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


/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Resource");

	//�ŏ��Ɏ��s�����V�[���̏����� 
	gpScene = new CTitle();
	g_GameProgMamt.Initialize();
	g_EffectManeger.Initialize();
	g_MusicManager.Initialize(0.2,0.2);
	gpScene->Initialize(&g_GameProgMamt,&g_MusicManager,&g_EffectManeger);


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

	//�X�V
	gpScene->Update();

	//��ʑJ�ڂ����ꍇ
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
		case SCENENO_TITLE:
			gpScene = new CTitle();
			break;
		case SCENENO_SELECTMODE:
			gpScene = new CModeSelect();
			break;
		case SCENENO_TUTORIAL:
			gpScene = new CTutorial();
			break;
		case SCENENO_GAME:
			gpScene = new CGAME();
			break;
		case SCENENO_GAMEOVER:
			gpScene = new CGameOver();
			break;
		case SCENENO_GAMECLEAR:
			gpScene = new CGameClear();
			break;
		case SCENENO_GALLERY:
			gpScene = new CGallery();
			break;
		case SCENENO_OPTION:
			gpScene = new COption();
			break;

		}
		//������
		g_EffectManeger.InitializeIn_middle();
		gpScene->Initialize(&g_GameProgMamt,&g_MusicManager,&g_EffectManeger);

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
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

	//�`��
	gpScene->Render();

	if (gDebagflag)
	{
		//�f�o�b�O�`��
		gpScene->RenderDebug();
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
		g_EffectManeger.Release();
		g_MusicManager.Release();
	}

	return TRUE;
}