#pragma once
#include "Music.h"

//�Ǘ��G�t�F�N�g�̐�
#define		SE_COUNT						5

class CMusicManager
{
private:

	//SE�ǂݍ���
	CSoundBuffer m_SE[SET_TYPECOUNT];

	//�N���X
	CMusic	m_Music[SE_COUNT][SET_TYPECOUNT];

public:
	CMusicManager();
	~CMusicManager();

	bool Load(void);
	void Initialize(void);

	CMusic* Start(int type);
	void Release(void);

};

