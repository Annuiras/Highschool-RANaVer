#pragma once
#include "Music.h"

//管理エフェクトの数
#define		SE_COUNT						5

class CMusicManager
{
private:

	//SE読み込み
	CSoundBuffer m_SE[SET_TYPECOUNT];

	//クラス
	CMusic	m_Music[SE_COUNT][SET_TYPECOUNT];

public:
	CMusicManager();
	~CMusicManager();

	bool Load(void);
	void Initialize(void);

	CMusic* Start(int type);
	void Release(void);

};

