/*

                    System tray Application Interface

			(C) 2000, Team OS/2 Russia

*/

#define  INCL_WIN

#include <os2.h>

#define WM_TRAYADDME WM_USER+1
#define WM_TRAYDELME WM_USER+2
#define WM_TRAYICON  WM_USER+3

HWND	hwndTrayServer = NULLHANDLE;

#define SZAPP	        "SystrayServer"
#define SZTOPIC		"TRAY"

BOOL	InitializeTrayApi(HWND hwnd)
{
WinDdeInitiate(hwnd,SZAPP,SZTOPIC,NULL);

return TRUE;
}

BOOL    AnswerTrayApiDdeAck(MPARAM mp1)
{
hwndTrayServer = (HWND)mp1;

return TRUE;
}

BOOL	AddTrayIcon(HWND hwnd,HPOINTER hptr)
{
if(!hwndTrayServer) return FALSE; // api not initialized

WinPostMsg(hwndTrayServer,WM_TRAYADDME,(MPARAM)hwnd,(MPARAM)hptr);

return TRUE;
}

BOOL	ChangeTrayIcon(HWND hwnd,HPOINTER hptr)
{
if(!hwndTrayServer) return FALSE; // api not initialized

WinPostMsg(hwndTrayServer,WM_TRAYICON,(MPARAM)hwnd,(MPARAM)hptr);

return TRUE;
}

BOOL	DeleteTrayIcon(HWND hwnd)
{
if(!hwndTrayServer) return FALSE; // api not initialized

WinPostMsg(hwndTrayServer,WM_TRAYDELME,(MPARAM)hwnd,(MPARAM)0L);

return TRUE;
}
