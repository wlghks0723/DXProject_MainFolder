#include"BaseInclude.h"
#include "AppMain.h"
#include "Device.h"
//EXTERN���� ���ǵ� ������ �ڵ鷯
HWND g_hWnd;
HINSTANCE g_hInst;

// �ܼ�â ���� (�� ���α׷��� _MBCS �� Main�� ����ȴ�.)
#ifdef _DEBUG
//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
//#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
//#endif
#endif // _DEBUG include �κ�

AppMain::AppMain()
{
}


AppMain::~AppMain()
{
}
//�޼��� ���ν���
LRESULT WINAPI AppMain::MsgProc(HWND hWnd, UINT msg, WPARAM wParm, LPARAM lParam)
{
	m_MainGame.WndProc(hWnd, msg, wParm, lParam);
	switch (msg)
	{
	case WM_DESTROY:
		System_Release();
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		ValidateRect(hWnd, NULL);
		return 0;
	}
	return DefWindowProc(hWnd,msg,wParm,lParam);
}
//wINDOW ���� �� �ʱ�ȭ �ǵ��� ����!
void AppMain::WinMainInit(HINSTANCE hInst, HINSTANCE,LPSTR,INT)
{
	m_wc =
	{
		sizeof(WNDCLASSEX),CS_CLASSDC,(WNDPROC)MsgProc,0L,0L,
		GetModuleHandle(NULL),NULL,NULL,NULL,NULL,
		L"League of Legend",NULL
	};

	RegisterClassEx(&m_wc);
	RECT rc = {0,0, WINSIZEX,WINSIZEY};
	m_hWnd = CreateWindow(L"League of Legend", L"League of Legend 1.0", 
		WS_OVERLAPPEDWINDOW,100, 100, rc.right-rc.left, rc.bottom-rc.top,
		GetDesktopWindow(), NULL, m_wc.hInstance, NULL);
	g_hInst = hInst;
	g_hWnd = m_hWnd;
}
//���� ���� �ǵ����� ��!!
int AppMain::WinMainLoop()
{
		ShowWindow(m_hWnd, SW_SHOWDEFAULT);
		UpdateWindow(m_hWnd);

		MSG msg;
		msg.message = NULL;
		m_MainGame.Init();

		while (msg.message != WM_QUIT) {
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				m_MainGame.Progress();
				m_MainGame.Render();
			}
		}
	
	UnregisterClass(L"FrameWork", m_wc.hInstance);
	return 0;
}
//�޸�����
void AppMain::Release()
{

}




