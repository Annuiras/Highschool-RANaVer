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

//���݂̃V�[��
int			gScene = SCENENO_TITLE;

//�ύX����V�[��
int			gChangeScene = SCENENO_TITLE;

//�f�o�b�O
bool		gDebagflag = false;

CSceneBase* gpScene = NULL;

//�e�V�[���N���X
//CTitle		gTitleScene;
//CModeSelect	gModeSelectScene;
//CTutorial	gTutorialScene;
//CGAME		gGAMEScene;
//CGameOver	gGameOverScene;
//CGameClear	gGameClearScene;
//CGallery		gGalleryScene;
//COption		gOptionScene;

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Resource");

	//gTitleScene.Load();
	//gModeSelectScene.Load();
	//gTutorialScene.Load();
	//gGAMEScene.Load();
	//gGameOverScene.Load();
	//gGameClearScene.Load();
	//gGalleryScene.Load();
	//gOptionScene.Load();


	//�ŏ��Ɏ��s�����V�[���̏�����
	//gTitleScene.Initialize();

	//�ŏ��Ɏ��s�����V�[���̏����� 
	gpScene = new CTitle();
	gpScene->Initialize();


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

	gpScene->Update();

	if (gpScene->IsEnd()) {

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
		gpScene->Initialize();

	}
	////�V�[���ԍ��ɂ���čX�V
	//switch (gScene)
	//{
	//case SCENENO_TITLE:
	//	gTitleScene.Update();
	//	break;
	//case SCENENO_SELECTMODE:
	//	gModeSelectScene.Update();
	//	break;
	//case SCENENO_TUTORIAL:
	//	gTutorialScene.Update();
	//	break;
	//case SCENENO_GAME:
	//	gGAMEScene.Update();
	//	break;
	//case SCENENO_GAMEOVER:
	//	gGameOverScene.Update();
	//	break;
	//case SCENENO_GAMECLEAR:
	//	gGameClearScene.Update();
	//	break;
	//case SCENENO_GALLERY:
	//	gGalleryScene.Update();
	//	break;
	//case SCENENO_OPTION:
	//	gOptionScene.Update();
	//	break;
	//}

	////�V�[���ύX���������ꍇ�ύX��V�[���̏�����
	//if (gChangeScene != gScene)
	//{
	//	switch (gChangeScene)
	//	{
	//	case SCENENO_TITLE:
	//		gTitleScene.Initialize();
	//		break;
	//	case SCENENO_SELECTMODE:
	//		gModeSelectScene.Initialize();
	//		break;
	//	case SCENENO_TUTORIAL:
	//		gTutorialScene.Initialize();
	//		break;
	//	case SCENENO_GAME:
	//		gGAMEScene.Initialize();
	//		break;
	//	case SCENENO_GAMEOVER:
	//		gGameOverScene.Initialize();
	//		break;
	//	case SCENENO_GAMECLEAR:
	//		gGameClearScene.Initialize();
	//		break;
	//	case SCENENO_GALLERY:
	//		gGalleryScene.Initialize();
	//		break;
	//	case SCENENO_OPTION:
	//		gOptionScene.Initialize();
	//		break;
	//	}

	//	gScene = gChangeScene;
	//}

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


	gpScene->Render();

	////�V�[���ԍ��ɂ���ĕ`��
	//switch (gScene)
	//{
	//case SCENENO_TITLE:
	//	gTitleScene.Render();
	//	break;
	//case SCENENO_SELECTMODE:
	//	gModeSelectScene.Render();
	//	break;
	//case SCENENO_TUTORIAL:
	//	gTutorialScene.Render();
	//	break;
	//case SCENENO_GAME:
	//	gGAMEScene.Render();
	//	break;
	//case SCENENO_GAMEOVER:
	//	gGameOverScene.Render();
	//	break;
	//case SCENENO_GAMECLEAR:
	//	gGameClearScene.Render();
	//	break;
	//case SCENENO_GALLERY:
	//	gGalleryScene.Render();
	//	break;
	//case SCENENO_OPTION:
	//	gOptionScene.Render();
	//	break;
	//}

	//if (gDebagflag == true)
	//{
	//	switch (gScene)
	//	{
	//	case SCENENO_TITLE:
	//		gTitleScene.RenderDebug();
	//		break;
	//	case SCENENO_SELECTMODE:
	//		gModeSelectScene.RenderDebug();
	//		break;
	//	case SCENENO_TUTORIAL:
	//		gTutorialScene.RenderDebug();
	//		break;
	//	case SCENENO_GAME:
	//		gGAMEScene.RenderDebug();
	//		break;
	//	case SCENENO_GAMEOVER:
	//		gGameOverScene.RenderDebug();
	//		break;
	//	case SCENENO_GAMECLEAR:
	//		gGameClearScene.RenderDebug();
	//		break;
	//	case SCENENO_GALLERY:
	//		gGalleryScene.RenderDebug();
	//		break;
	//	case SCENENO_OPTION:
	//		gOptionScene.RenderDebug();
	//		break;
	//	}
	//}


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
	//gTitleScene.Release();
	//gModeSelectScene.Release();
	//gTutorialScene.Release();
	//gGAMEScene.Release();
	//gGameOverScene.Release();
	//gGameClearScene.Release();
	//gGalleryScene.Release();
	//gOptionScene.Release();

	return TRUE;
}