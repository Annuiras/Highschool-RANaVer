#pragma once
class CGameProgMgmt
{

private:

	//BGM・SE音量
	float BGM_Volume, SE_Volume;

public:
	CGameProgMgmt(); 
	~CGameProgMgmt();

	//初期化
	void Initialize(void);

	//設定された音量をセット
	void SetBGMVolume(float volume);
	void SetSEVolume(float volume);

	//設定された音量を渡す
	float GetBGMVolume(void);
	float GetSEVolume(void);

};

