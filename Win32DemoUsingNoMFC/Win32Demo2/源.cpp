// Win32Demo2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
#include <shellapi.h>
extern "C"

BOOL WINAPI aHandlerFunction(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_DROPFILES: {
		wchar_t fileNameC[_MAX_PATH];
		HDROP hdrop = (HDROP)wParam;
		CString fileName;
		fileName.Format(L"%s", fileNameC);
		DragQueryFile(hdrop, 0, fileNameC, _MAX_FNAME);
		MessageBox(hwnd, fileNameC, L"test", 0);
		::SetDlgItemText(hwnd, IDC_S111, fileNameC);
	}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK: {
			CString test;
			test.Format(L"OK is clicked \n %d", 100);
			MessageBox(hwnd, test, L"Title", 0);
			DestroyWindow(hwnd);
		}
			break;
		case IDC_BTNC: {
			//ShellExecute(hwnd, L"open", L"explorer", NULL, NULL, SW_NORMAL);
			MessageBox(hwnd, L"Hello, World from custom button!", L"Custom Button", 0);
		} 
					   break;
		}
		break;
	case WM_CLOSE: {
		DestroyWindow(hwnd);
	}
				   break;
	}
	return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	   lpCmdLine,
	int	   nCmdShow)
{
	// TODO: Place code here.
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, aHandlerFunction, NULL);
	return 0;
}