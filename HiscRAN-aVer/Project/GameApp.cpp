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

//�e�V�[���N���X
CTitle		gTitleScene;
CModeSelect	gModeSelectScene;
CTutorial	gTutorialScene;
CGAME		gGAMEScene;
CGameOver	gGameOverScene;
CGameClear	gGameClearScene;
CGallery		gGalleryScene;
COption		gOptionScene;

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	// ���\�[�X
	CUtilities::SetCurrentDirectoryA("Resource");

	gTitleScene.Load();
	gModeSelectScene.Load();
	gTutorialScene.Load();
	gGAMEScene.Load();
	gGameOverScene.Load();
	gGameClearScene.Load();
	gGalleryScene.Load();
	gOptionScene.Load();


	//�ŏ��Ɏ��s�����V�[���̏�����
	gTitleScene.Initialize();



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

	if (g_pInput->IsKeyPush(MOFKEY_BACKSPACE))
	{
		if (gDebagflag)
		{
			//�I���ς݂ɂȂ��Ă���ꍇ�͑I����������
			gDebagflag = false;
		}
		else
		{
			//�I�������ɂȂ��Ă���ꍇ�͑I���ς݂ɂ���
			gDebagflag = true;
		}
	}

	//�V�[���ԍ��ɂ���čX�V
	switch (gScene)
	{
	case SCENENO_TITLE:
		gTitleScene.Update();
		break;
	case SCENENO_SELECTMODE:
		gModeSelectScene.Update();
		break;
	case SCENENO_TUTORIAL:
		gTutorialScene.Update();
		break;
	case SCENENO_GAME:
		gGAMEScene.Update();
		break;
	case SCENENO_GAMEOVER:
		gGameOverScene.Update();
		break;
	case SCENENO_GAMECLEAR:
		gGameClearScene.Update();
		break;
	case SCENENO_GALLERY:
		gGalleryScene.Update();
		break;
	case SCENENO_OPTION:
		gOptionScene.Update();
		break;
	}

	//�V�[���ύX���������ꍇ�ύX��V�[���̏�����
	if (gChangeScene != gScene)
	{
		switch (gChangeScene)
		{
		case SCENENO_TITLE:
			gTitleScene.Initialize();
			break;
		case SCENENO_SELECTMODE:
			gModeSelectScene.Initialize();
			break;
		case SCENENO_TUTORIAL:
			gTutorialScene.Initialize();
			break;
		case SCENENO_GAME:
			gGAMEScene.Initialize();
			break;
		case SCENENO_GAMEOVER:
			gGameOverScene.Initialize();
			break;
		case SCENENO_GAMECLEAR:
			gGameClearScene.Initialize();
			break;
		case SCENENO_GALLERY:
			gGalleryScene.Initialize();
			break;
		case SCENENO_OPTION:
			gOptionScene.Initialize();
			break;
		}

		gScene = gChangeScene;
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

	//�V�[���ԍ��ɂ���ĕ`��
	switch (gScene)
	{
	case SCENENO_TITLE:
		gTitleScene.Render();
		break;
	case SCENENO_SELECTMODE:
		gModeSelectScene.Render();
		break;
	case SCENENO_TUTORIAL:
		gTutorialScene.Render();
		break;
	case SCENENO_GAME:
		gGAMEScene.Render();
		break;
	case SCENENO_GAMEOVER:
		gGameOverScene.Render();
		break;
	case SCENENO_GAMECLEAR:
		gGameClearScene.Render();
		break;
	case SCENENO_GALLERY:
		gGalleryScene.Render();
		break;
	case SCENENO_OPTION:
		gOptionScene.Render();
		break;
	}

	if (gDebagflag == true)
	{
		switch (gScene)
		{
		case SCENENO_TITLE:
			gTitleScene.RenderDebug();
			break;
		case SCENENO_SELECTMODE:
			gModeSelectScene.RenderDebug();
			break;
		case SCENENO_TUTORIAL:
			gTutorialScene.RenderDebug();
			break;
		case SCENENO_GAME:
			gGAMEScene.RenderDebug();
			break;
		case SCENENO_GAMEOVER:
			gGameOverScene.RenderDebug();
			break;
		case SCENENO_GAMECLEAR:
			gGameClearScene.RenderDebug();
			break;
		case SCENENO_GALLERY:
			gGalleryScene.RenderDebug();
			break;
		case SCENENO_OPTION:
			gOptionScene.RenderDebug();
			break;
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

	gTitleScene.Release();
	gModeSelectScene.Release();
	gTutorialScene.Release();
	gGAMEScene.Release();
	gGameOverScene.Release();
	gGameClearScene.Release();
	gGalleryScene.Release();
	gOptionScene.Release();

	return TRUE;
}