#pragma once

//����ҁF���Y ���H �A�c�� ��

#include "SceneBase.h"
#include	"Menu.h"
#include "Define.h"
#include <thread>
using namespace std;


//�X�N���[�����x
#define		SCROLL_SPEED	1;

class CModeSelect :public CSceneBase
{
private:

	//�f�ރ��[�h�X���b�h
	thread Thread_Load;

	CTexture		m_TutorialTextureSmall;
	CTexture		m_TutorialTextureBig;
	CTexture		m_TutorialBG[4];
	CTexture		m_TutorialTextBox;
	CTexture		m_TutorialTextTexture;
	float			m_Scroll;

	int m_BakAlph;

public:
	CModeSelect();
	~CModeSelect();
	void Initialize(CGameProgMgmt* mamt, CMusicMgmt* musi, CEffectMgmt* effecs, CMenu* menu);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Load(void);
	void Release(void);

};

