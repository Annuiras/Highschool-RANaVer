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

CMenu		geMenu;
int			gMenuItemCount = 2;


/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectoryA("Resource");

	//�ŏ��Ɏ��s�����V�[��,�}�l�[�W���[�̏����� 
	gpScene = new CTitle();
	g_GameProgMamt.Initialize();
	g_EffectManeger.Initialize();
	g_MusicManager.Initialize(0.2,0.2);
	geMenu.Create(gMenuItemCount);


	//�ŏ��̃V�[���Ƀ}�l�[�W���[�̃|�C���^��n��
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
	
	//todo:���j���[�\����
	//���j���[�N���X���V�[���x�[�X�ɃC���X�^���X�H
	//�|�C���^�n��������Ǝv��
	if (geMenu.IsShow())
	{
		//���j���[�X�V
		geMenu.Update();

		//�I�������ꍇ
		if (geMenu.IsEnter() && gpScene->IsNow() != SCENENO_GAME)
		{
			if (geMenu.GetSelect() == 0)
			{
				//�A�v���P�[�V�����I��
				PostQuitMessage(0);
			}
			geMenu.Hide();
		}
		else if (geMenu.IsEnter() && gpScene->IsNow() == SCENENO_GAME)
		{
			if (geMenu.GetSelect() == 0)
			{
				//���[�h�Z���N�g��ʂ�
				gpScene->SetEnd(true);
				gpScene->SetNextScene(SCENENO_SELECTMODE);
			}
			geMenu.Hide();
		}
	}

	//�G�X�P�[�v�L�[�ŏI�����j���[��\��
	else if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
	{
		geMenu.Show(g_pGraphics->GetTargetWidth() * 0.5f, g_pGraphics->GetTargetHeight() * 0.5f);
	}
	else
	{
		//�X�V
		gpScene->Update();
	}

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
		case SCENENO_DPDECISION:
			gpScene = new CDPDecision();
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
	if (gpScene->IsNow() == SCENENO_GAME) 
	{
		geMenu.Render(2);
	}
	else 
	{
		//���j���[�̕`��
		geMenu.Render(1);
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
		geMenu.Release();
	}

	return TRUE;
}