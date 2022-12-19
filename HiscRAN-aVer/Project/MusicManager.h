#pragma once
#include "Define.h"


class CMusicMgmt
{
private:

	//SE用クラス
	CSoundBuffer m_Music_SE[SE_TYPE_COUNT];

	//BGM用クラス
	CSoundBuffer m_Music_BGM[BGM_TYPE_COUNT];

public:
	CMusicMgmt();
	~CMusicMgmt();

	//素材ロード
	tag_LoadSituation Load(void);

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
	//SEが再生されているか取得
	//true :再生中
	bool SEisPlay(tag_SE_TYPE type);

	//BGM再生
	CSoundBuffer* BGMStart(tag_BGM_TYPE type);
	//BGM停止
	void BGMStop(tag_BGM_TYPE type);
	//BGMボリュームセット
	void BGMSetVolume(float bgmv);

	//SEをすべて停止
	void SEALLStop(void);

	//ループ設定
	void BGMLoop(tag_BGM_TYPE type,bool b);

	//SEボリュームゲット
	float GetSEVolume();

	//BGMボリュームゲット
	float GetBGMVolume();

	//解放
	void Release(void);

};

