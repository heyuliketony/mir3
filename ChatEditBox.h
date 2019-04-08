


#ifndef _CHATEDITBOX_H
#define _CHATEDITBOX_H


class CChatEdit
{
public:
	CChatEdit();
	~CChatEdit();
protected:
	HWND			m_hChatEdit;

	HFONT			m_hFontChatEdit;
	DWORD			m_dwFontColor;

	WNDPROC		 m_WndProcChatEdit;

public:
	CHAR	m_szInputMsg[MAX_PATH];


	
	BOOL		Create(HINSTANCE hInstance, HWND hWndParent, INT nX, INT nY, INT nXSize, INT nYSize);
	BOOL		DestroyDialog();
	BOOL		SetLimitText(INT nLimitText);

	__inline		VOID SetSelectAll() { SendMessage(m_hChatEdit, EM_SETSEL, 0, (LPARAM)-1); }
	__inline		HWND GetSafehWnd() { return m_hChatEdit; }

	LRESULT		CALLBACK ChatEditProc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
};


#endif
