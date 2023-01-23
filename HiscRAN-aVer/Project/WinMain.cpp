#include	"GameApp.h"
#include "resource.h"

#ifdef		UNICODE
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
#else
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
#endif
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Mof::LPFramework pFrame = new Mof::CDX11GameFramework(); 
	Mof::WINDOWSGAMEFRAMEWORKINITIALIZEINFO Info;
	Info.pApplication = new CGameApp();

	//��ʂ̃T�C�Y�ύX
	Info.WindowCreateInfo.Width = 1280;
	Info.WindowCreateInfo.Height = 720;

	//����ɕ\�������A�C�R���ƁA���̂�ύX
	Info.WindowCreateInfo.hIcon = LoadIconA(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	Info.WindowCreateInfo.Title = "�n�C�X�N�[��RUN";

	pFrame->Initialize(&Info);
	pFrame->Run();
	MOF_SAFE_DELETE(pFrame);
	return 0;
}