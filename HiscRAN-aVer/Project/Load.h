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

	//���[�f�B���O����
	CTexture m_String;
	//�\����`
	CRectangle m_StringRec;

	//�G���[�w�i
	CTexture m_ErBak;

	//���[�h��ʍŒ�ҋ@����
	int m_WaitingTime;

	//�o�ߎ���
	int m_Time;

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
	//A		:�w�i���l
	//time	:�Œ�ҋ@����
	void Initialize(int A,int time);

	//�f�ރ��[�h
	bool Load(void);

	//�X�V
	void Update();
	void RenderLoad(void);
	void RenderError(void);
	void RenderDebug(void);

	void Release();

	//�f�ރ��[�h�X���b�h
	thread Thread_Load;

	//���[�h��ʏI��?
	//true:�I��
	bool IsLoadEnd(void) { return m_LoadTimeEnd; }


};

