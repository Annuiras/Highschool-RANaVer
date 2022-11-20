#pragma once
#include "Mof.h"

//SEéÌóﬁóÒãì
enum tag_SETYPE {
	SET_EXPLOSION01,//ê‘îöî≠
	SET_EXPLOSION02,				//ê¬îöî≠

	SET_KANE,//è‡

	SET_PAWANN,//Ç€ÇÌÅ[ÇÒ
	SET_TYPE_COUNT,//ëçêî
};

class CMusic
{

private:

	CSoundBuffer* m_SoundBou;


public:

	CMusic();
	~CMusic();

	bool Initialize(void);
	void Start(int ty);

	//çƒê∂íÜÇ©true:çƒê∂íÜ
	bool IsPlay() { return m_SoundBou->IsPlay(); }

	void SetSE(CSoundBuffer* se) { m_SoundBou = se; }

	//âπó ê›íË
	void SetVolume(float volume);
	void Release(void);

};

