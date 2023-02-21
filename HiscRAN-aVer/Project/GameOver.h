//////////////////////////////////////////////
//	�Q�[���I�[�o�[��ʂ̃v���O�����ł��@�@  //
//									�@�@�@�@//
//�@�쐬�ҁF���Y���H�@�@�@�@�@�@�@�@�@�@ �@ //
//									�@�@�@�@//
//�@���t�@�N�^�����O�����l�F�c���@�@�@�@�@//
//									�@�@�@�@//
//�@�ŏI�X�V�F2023/01/17			�@�@�@�@//
//////////////////////////////////////////////

#pragma once
#include "Define.h"
#include "Define_Music.h"
#include "SceneBase.h"

//�I������
#define MenuCnt (2)

class CGameOver :public CSceneBase
{
private:
	//�w�i�e�N�X�`��
	CTexture	m_BackTexture;

	//���[�h�Z���N�g�ɖ߂�{�^��
	CTexture	m_BackButton;

	//1�N�̏��߂��炷��{�^��
	CTexture	m_StartButton;

	//���[�h�Z���N�g�ɖ߂镶��
	CTexture	m_TextBack;

	//�P�N�̏��߂��炷�镶��
	CTexture	m_TextStart;

	//�Q�[���I�[�o�[���ɏ�ɏo�Ă��镶��
	CTexture	m_ENDText;

	//�����_���ϐ��i�[�p
	int			Rondom;

	//�؂����`(HP�����Ȃ��Ď��񂾂Ƃ��̕���)
	CRectangle recENDText[5]={ {0,0,720,61} , {0,61,360,122},{0,122,841,195},{0,195,480,266},{0,266,1020,334} };

	//HP�����Ȃ��Ď��񂾂Ƃ��̕��͔z�u�T�iX���W�j
	int		   PosXENDText[5] = { 276,453,218,396,124 };
	
	//�Q�[���I�[�o���̃t�F�[�h�C���t�F�[�h�A�E�g�p
	//�A���t�@�l
	int m_BlackBakAlph;
	int m_WhiteBakAlph;

	//�I�����ԍ�
	int GameOverCount;

public:
	CGameOver();
	~CGameOver();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effec, CMenu* menu);
	void Update(void);

	void UpdateDebug(void);

	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);
};

