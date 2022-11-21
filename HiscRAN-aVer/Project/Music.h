#pragma once
#include "Mof.h"
#include "Define.h"

class CMusic
{

private:

	CSoundBuffer* m_SoundBou;


public:

	CMusic();
	~CMusic();

	bool Initialize(void);

	//�Đ�
	void Start(void);

	//��~
	void Stop(void);

	//�Đ�����true:�Đ���
	bool IsPlay() { return m_SoundBou->IsPlay(); }

	//�����Z�b�g
	void SetMusic(CSoundBuffer* music) { m_SoundBou = music; }

	//���[�v�ݒ�
	void SetLoop(bool b);

	//���ʐݒ�
	void SetVolume(float volume);

	//�{�����[���Q�b�g
	float GetVolume(void);

	void Release(void);

};

