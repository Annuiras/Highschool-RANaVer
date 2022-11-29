#pragma once
//#include "Music.h"
#include "Define.h"


class CMusicMgmt
{
private:

	//SE格納
	//CSoundBuffer m_SE[SET_TYPE_COUNT];
	//SE用クラス
	CSoundBuffer m_Music_SE[SET_TYPE_COUNT];

	//BGM用クラス
	CSoundBuffer m_Music_BGM[BGMT_TYPE_COUNT];
	//BGM格納
	//CSoundBuffer m_BGM[BGMT_TYPE_COUNT];

public:
	CMusicMgmt();
	~CMusicMgmt();

	bool Load(void);
	//初期化
	void Initialize(float bgmv, float sev);

	//画面推移時の初期化命令
	void InitializeIn_middle(float bgmv, float sev);


	//SE再生
	CSoundBuffer* SEStart(tag_SE_TYPE type);
	//SE停止
	void SEStop(tag_SE_TYPE type);
	//SEボリュームセット
	void SESetVolume(float sev);

	//BGM再生
	CSoundBuffer* BGMStart(tag_BGM_TYPE type);
	//BGM停止
	void BGMStop(tag_BGM_TYPE type);
	//BGMボリュームセット
	void BGMSetVolume(float bgmv);

	//ループ設定
	void BGMLoop(tag_BGM_TYPE type,bool b);

	//SEボリュームゲット
	float GetSEVolume();

	//BGMボリュームゲット
	float GetBGMVolume();

	//解放
	void Release(void);

};

