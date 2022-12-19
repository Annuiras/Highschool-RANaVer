#pragma once
#include "Define.h"
#include <thread>

using namespace std;

//���[�h��ʃN���X
class CLoad
{
private:

	//���[�h�w�i
	CTexture m_Bak;

	//�G���[�w�i
	CTexture m_ErBak;

	//���[�h��ʍŒ�ҋ@����
	int m_WaitingTime;

	//���[�h��ʑҋ@���ԏI���t���O
	bool m_LoadTimeEnd;

	//���]�p�w�i���l
	int m_WhiteAlpha;

	//���ڊJ�n�t���O
	bool m_Fadein;


public:

	CLoad();
	~CLoad();
	

	//������
	void Initialize(void);

	//�f�ރ��[�h
	bool Load(void);

	//�X�V
	void Update();
	void RenderLoad(void);
	void RenderError(void);
	void RenderDebug(); 
	void Release();

	//�f�ރ��[�h�X���b�h
	thread Thread_Load;

	//���[�h��ʏI��?
	//true:�I��
	bool IsLoadEnd(void) { return m_LoadTimeEnd; }


};

