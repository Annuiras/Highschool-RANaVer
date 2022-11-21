#pragma once
#include "Music.h"
#include "Define.h"


class CMusicMgmt
{
private:

	//SE�i�[
	CSoundBuffer m_SE[SET_TYPE_COUNT];
	//SE�p�N���X
	CMusic	m_Music_SE[SET_TYPE_COUNT][SE_MGMT_COUNT];

	//BGM�p�N���X
	CMusic m_Music_BGM[BGMT_TYPE_COUNT];
	//BGM�i�[
	CSoundBuffer m_BGM[BGMT_TYPE_COUNT];

public:
	CMusicMgmt();
	~CMusicMgmt();

	bool Load(void);
	void Initialize(float bgmv, float sev);

	//SE�Đ�
	CMusic* SEStart(int type);
	//SE��~
	void SEStop(int type);
	//SE�{�����[���Z�b�g
	void SESetVolume(float sev);

	//BGM�Đ�
	CMusic* BGMStart(int type);
	//BGM��~
	void BGMStop(int type);
	//BGM�{�����[���Z�b�g
	void BGMSetVolume(float bgmv);

	//���[�v�ݒ�
	void BGMLoop(int type,bool b);

	//SE�{�����[���Q�b�g
	float GetSEVolume();

	//BGM�{�����[���Q�b�g
	float GetBGMVolume();

	void Release(void);

};

