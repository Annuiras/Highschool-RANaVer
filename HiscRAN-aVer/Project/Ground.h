#pragma once
#include "Mof.h"
#include "Define.h"

class Ground
{

private:


	float g_PosX;
	float g_PosY;


public:

	Ground();
	~Ground();

	void Initialize(void);
	void Render(void);
	void RenderDebugging(void);

	//�n�ʋ�`�擾
	CRectangle GetRect() {
		return CRectangle(g_PosX, g_PosY,
			g_PosX + g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetWidth());
	}

	//�n��Y���W�擾
	float GetPosY() { return g_PosY; }

};
