#pragma once
#include	"Menu.h"

class CGAME
{

private:
	CMenu			gMenu;
	bool			Menuflag = false;
	int				gMenuItemCount = 2;

public:
	CGAME();
	~CGAME();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Load(void);
	void Release(void);
	void RenderDebug(void);


};

