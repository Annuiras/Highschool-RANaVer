#pragma once
#include "Music.h"

//�Ǘ��G�t�F�N�g�̐�
#define		SE_COUNT						5

class CMusicMgmt
{
private:

	//SE�ǂݍ���
	CSoundBuffer m_SE[SET_TYPE_COUNT];

	//SE�p�N���X
	CMusic	m_Music_SE[SET_TYPE_COUNT][SE_COUNT];

	//todo:BGM�p�ɍ쐬�\��
	//BGM�p�N���X
	//CMusic m_Music_BGM[][]
public:
	CMusicMgmt();
	~CMusicMgmt();

	bool Load(void);
	void Initialize(float sev/*,float bgnv*/);

	CMusic* Start(int type);
	void Release(void);

};

