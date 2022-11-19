#pragma once
#include "Mof.h"

//SEŽí—Þ—ñ‹“
enum tag_SETYPE {
	SET_EXPLOSION01,//Ô”š”­
	SET_EXPLOSION02,				//Â”š”­

	SET_KANE,//à

	SET_PAWANN,//‚Û‚í[‚ñ
	SET_TYPECOUNT,//‘”
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

	//Ä¶’†‚©true:Ä¶’†
	bool IsPlay() { return m_SoundBou->IsPlay(); }

	void SetSE(CSoundBuffer* se) { m_SoundBou = se; }
	void Release(void);

};

