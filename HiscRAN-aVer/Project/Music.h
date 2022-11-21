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

	//再生
	void Start(void);

	//停止
	void Stop(void);

	//再生中かtrue:再生中
	bool IsPlay() { return m_SoundBou->IsPlay(); }

	//音声セット
	void SetMusic(CSoundBuffer* music) { m_SoundBou = music; }

	//ループ設定
	void SetLoop(bool b);

	//音量設定
	void SetVolume(float volume);

	//ボリュームゲット
	float GetVolume(void);

	void Release(void);

};

