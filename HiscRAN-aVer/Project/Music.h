#pragma once
#include "Mof.h"

//SE��ޗ�
enum tag_SETYPE {
	SET_EXPLOSION01,//�Ԕ���
	SET_EXPLOSION02,				//����

	SET_KANE,//��

	SET_PAWANN,//�ۂ�[��
	SET_TYPE_COUNT,//����
};

class CMusic
{

private:

	CSoundBuffer* m_SoundBou;


public:

	CMusic();
	~CMusic();

	bool Initialize(void);
	void Start(int ty);

	//�Đ�����true:�Đ���
	bool IsPlay() { return m_SoundBou->IsPlay(); }

	void SetSE(CSoundBuffer* se) { m_SoundBou = se; }

	//���ʐݒ�
	void SetVolume(float volume);
	void Release(void);

};

