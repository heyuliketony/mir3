



#include "stdafx.h"


static CWHApp* g_pWHApp = NULL;

/******************************************************************************************************************

	CWHApp Functions.

*******************************************************************************************************************/


CWHApp::CWHApp()
{
	g_pWHApp	= this;
	m_hInstance = NULL;
}


CWHApp::~CWHApp()
{
}


LRESULT CWHApp::MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return g_pWHApp->MainWndProc(hWnd, uMsg, wParam, lParam);
}




/******************************************************************************************************************

	CWHWindow Functions.

*******************************************************************************************************************/


CWHWindow::CWHWindow()
{
	m_hWnd = NULL;
}


CWHWindow::~CWHWindow()
{
}


BOOL CWHWindow::RegisterClass(CHAR* pszMenuName, CHAR* pszIconName)
{
    WNDCLASSEX wc;

    wc.cbSize			= sizeof(wc);
    wc.lpszClassName	= _WINDHORN_CLASS;
    wc.lpfnWndProc		= WndProc;
    wc.style			= CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
    wc.hInstance		= m_hInstance;
    wc.hIcon			= LoadIcon(m_hInstance, pszIconName);
    wc.hIconSm			= LoadIcon(m_hInstance, pszIconName);
    wc.hCursor			= LoadCursor(m_hInstance, IDC_ARROW);
    wc.hbrBackground	= (HBRUSH)(GRAY_BRUSH);
    wc.lpszMenuName		= pszMenuName;
    wc.cbClsExtra		= 0;
    wc.cbWndExtra		= 0;

    if ( RegisterClassEx(&wc) == 0 )
	{
        return FALSE;
	}

	return TRUE;
}


BOOL CWHWindow::Create(HINSTANCE hInst, LPTSTR lpCaption, CHAR *pszMenuName, CHAR* pszIconName)
{
	SethInstance(hInst);
	if ( !RegisterClass(pszMenuName, pszIconName) ) 
	{
		MessageBox(NULL, TEXT("[CWHWindow::Create]") TEXT("Register class failed."), "MirDXG", MB_ICONERROR | MB_OK);
		return FALSE;
	}

    DWORD	dwFrameWidth    = GetSystemMetrics(SM_CXSIZEFRAME);
    DWORD	dwFrameHeight   = GetSystemMetrics(SM_CYSIZEFRAME);
	DWORD	dwMenuHeight;
	
	if ( pszMenuName != NULL )		
		dwMenuHeight = GetSystemMetrics(SM_CYMENU);
	else
		dwMenuHeight = 0;

    DWORD dwCaptionHeight = GetSystemMetrics(SM_CYCAPTION);
    DWORD dwWindowWidth   = _SCREEN_WIDTH  + dwFrameWidth * 2;
    DWORD dwWindowHeight  = _SCREEN_HEIGHT + dwFrameHeight * 2 + dwMenuHeight + dwCaptionHeight;

	DWORD dwStyle = WS_POPUPWINDOW;
    m_hWnd = CreateWindowEx(NULL, _WINDHORN_CLASS, lpCaption,
						    dwStyle, CW_USEDEFAULT, CW_USEDEFAULT,
  						    dwWindowWidth, dwWindowHeight, NULL, NULL, m_hInstance, NULL);

	if ( m_hWnd == NULL )
    	return FALSE;

//  ShowWindow(m_hWnd, SW_SHOW);
//  UpdateWindow(m_hWnd);

	return TRUE;
}


LRESULT CWHWindow::MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch (uMsg)
	{
		case WM_DESTROY:
			return OnDestroy();
	}

    return CWHApp::MainWndProc(hWnd, uMsg, wParam, lParam);
}


LRESULT CWHWindow::OnDestroy()
{
	PostQuitMessage(NULL);
	return 0L;
}
