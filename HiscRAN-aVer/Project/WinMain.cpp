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

	//画面のサイズ変更
	Info.WindowCreateInfo.Width = 1280;
	Info.WindowCreateInfo.Height = 720;

	//左上に表示されるアイコンと、名称を変更
	Info.WindowCreateInfo.hIcon = LoadIconA(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	Info.WindowCreateInfo.Title = "ハイスクールRUN";

	pFrame->Initialize(&Info);
	pFrame->Run();
	MOF_SAFE_DELETE(pFrame);
	return 0;
}