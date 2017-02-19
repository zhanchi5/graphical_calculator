#include <Windows.h>
#include "resource.h"
#include <stdio.h>



char Text[64];
double x, y, z;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),0,(DlgProc),0);
	return 0;
}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
	case WM_INITDIALOG: 
	{	
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(MAIN_ICON));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon1);

		break;
	}
	case WM_COMMAND: 
		switch (LOWORD(wParam))
		{
		case IDC_SUMM:
		{
			SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 255, (LPARAM)Text);
			if (sscanf_s(Text, "%lf", &x) < 1)
			{
				MessageBox(hwnd, "Wrong first operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 255, (LPARAM)Text);
			
			if (sscanf_s(Text, "%lf", &y) < 1)
			{
				MessageBox(hwnd, "Wrong second operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 255, (LPARAM)Text);
			char Sign;
			z = x + y; Sign = '+'; 
			sprintf_s(Text, "%f", z); 
			SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)Text);
			SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)Text);
			
			sprintf_s(Text, "%f %c %f = %f", x, Sign, y, z);
			SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)Text);
		}
			break;
		case IDC_DIFFERENCE:
		{
			SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 255, (LPARAM)Text);
			if (sscanf_s(Text, "%lf", &x) < 1)
			{
				MessageBox(hwnd, "Wrong first operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 255, (LPARAM)Text);
			
			if (sscanf_s(Text, "%lf", &y) < 1)
			{
				MessageBox(hwnd, "Wrong second operator format", "Format error", MB_OK | MB_ICONHAND);
				return TRUE;
			}
			SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 255, (LPARAM)Text);
			char Sign;
			z = x - y; Sign = '-';
			sprintf_s(Text, "%f", z);
			SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)Text);
			SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)Text);
			
			sprintf_s(Text, "%f %c %f = %f", x, Sign, y, z);
			SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)Text);
		}
			break;
		case IDC_CLEAR:
		{
			SendDlgItemMessage(hwnd, IDC_LIST1, LB_RESETCONTENT, 0, 0);
			return TRUE;
		}
			break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return FALSE;
		}
		break;
	case WM_CLOSE: 
		EndDialog(hwnd, 0);
		return FALSE;

	}
	return FALSE;
}
