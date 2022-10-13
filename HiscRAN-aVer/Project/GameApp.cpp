/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

#include	"Title.h"
#include	"ModeSelect.h"
#include	"Tutorial.h"
#include	"GAME.h"
#include	"Gallery.h"
#include	"Option.h"

//���݂̃V�[��
int			gScene = SCENENO_TITLE;

//�ύX����V�[��
int			gChangeScene = SCENENO_TITLE;

//�e�V�[���N���X
Title		gTitleScene;
ModeSelect	gModeSelectScene;
Tutorial	gTutorialScene;
GAME		gGAMEScene;
Gallery		gGalleryScene;
Option		gOptionScene;

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
	gTutorialScene.Road();
	gGAMEScene.Load();
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
	case SCENENO_GALLERY:
		gGalleryScene.Render();
		break;
	case SCENENO_OPTION:
		gOptionScene.Render();
		break;
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
	gGalleryScene.Release();
	gOptionScene.Release();

	return TRUE;
}