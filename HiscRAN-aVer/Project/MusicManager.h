#pragma once
#include "Music.h"

//管理エフェクトの数
#define		SE_COUNT						5

class CMusicMgmt
{
private:

	//SE読み込み
	CSoundBuffer m_SE[SET_TYPE_COUNT];

	//SE用クラス
	CMusic	m_Music_SE[SET_TYPE_COUNT][SE_COUNT];

	//todo:BGM用に作成予定
	//BGM用クラス
	//CMusic m_Music_BGM[][]
public:
	CMusicMgmt();
	~CMusicMgmt();

	bool Load(void);
	void Initialize(float sev/*,float bgnv*/);

	CMusic* Start(int type);
	void Release(void);

};

