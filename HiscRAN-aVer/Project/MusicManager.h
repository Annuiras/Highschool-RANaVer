#pragma once
#include "Music.h"
#include "Define.h"


class CMusicMgmt
{
private:

	//SE格納
	CSoundBuffer m_SE[SET_TYPE_COUNT];
	//SE用クラス
	CMusic	m_Music_SE[SET_TYPE_COUNT][SE_MGMT_COUNT];

	//BGM用クラス
	CMusic m_Music_BGM[BGMT_TYPE_COUNT];
	//BGM格納
	CSoundBuffer m_BGM[BGMT_TYPE_COUNT];

public:
	CMusicMgmt();
	~CMusicMgmt();

	bool Load(void);
	void Initialize(float bgmv, float sev);

	//SE再生
	CMusic* SEStart(int type);
	//SE停止
	void SEStop(int type);
	//SEボリュームセット
	void SESetVolume(float sev);

	//BGM再生
	CMusic* BGMStart(int type);
	//BGM停止
	void BGMStop(int type);
	//BGMボリュームセット
	void BGMSetVolume(float bgmv);

	//ループ設定
	void BGMLoop(int type,bool b);

	//SEボリュームゲット
	float GetSEVolume();

	//BGMボリュームゲット
	float GetBGMVolume();

	void Release(void);

};

