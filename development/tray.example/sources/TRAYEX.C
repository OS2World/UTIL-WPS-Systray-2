#define INCL_WINSTDDRAG
#define INCL_GPI
#include "trayapi.h" /* API library */

MRESULT EXPENTRY windowproc(HWND, ULONG, MPARAM, MPARAM) ;

HAB  hab ;
HWND hwndFrame, hwndClient ;
HPOINTER hIcon[5];

int main()
{
ULONG fl = FCF_SIZEBORDER | FCF_TASKLIST | FCF_ICON | FCF_TITLEBAR | FCF_SYSMENU | FCF_MINMAX | FCF_SHELLPOSITION;
static CHAR  szClass [] = "Tray Example" ;
HMQ          hmq ;
QMSG         qmsg ;
LONG i;

hab = WinInitialize (0) ;
hmq = WinCreateMsgQueue (hab, 0) ;

WinRegisterClass (hab, (PSZ)szClass, (PFNWP)windowproc, CS_SIZEREDRAW, 0) ;

hwndFrame = WinCreateStdWindow (HWND_DESKTOP, WS_VISIBLE,
                                &fl, (PSZ)szClass, (PSZ)szClass,
                                0L, NULL, 100, &hwndClient) ;

for(i=100;i<=104;i++)
hIcon[i-100] = WinLoadPointer(HWND_DESKTOP,NULLHANDLE,i);

while (WinGetMsg (hab, &qmsg, NULL, 0, 0))
       WinDispatchMsg (hab, &qmsg) ;

WinDestroyWindow (hwndFrame) ;
WinDestroyMsgQueue (hmq) ;
WinTerminate (hab) ;
return 0 ;

}

CHAR buf[256],cbuf[256];

MRESULT EXPENTRY windowproc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
HPS hps;
RECTL rcl;
DRAGITEM dit;
PDRAGINFO pdin;
HOBJECT hobj;
static a=0;

switch(msg)
{
/* control tray icon specific messages */
case DM_DROP:
pdin = (PDRAGINFO)mp1;
DrgAccessDraginfo(pdin);
DrgQueryDragitem(pdin,sizeof(DRAGITEM),&dit,0);
DrgQueryStrName(dit.hstrContainerName,256,cbuf);
DrgQueryStrName(dit.hstrSourceName,256,buf);
strcat(cbuf,buf);
hobj=WinQueryObject("<WP_DRIVES>");
if(hobj)DosBeep(1000,100);
//WinOpenObject(hobj,0,TRUE);
WinMessageBox(HWND_DESKTOP,hwnd,"Drag Succeed!",cbuf,0,MB_OK | MB_INFORMATION);
DrgFreeDraginfo(pdin);
break;
case DM_DRAGOVER:
return MPFROM2SHORT(DOR_DROP,DO_LINK);
case WM_TIMER:
a++;
a%=5;
WinSendMsg(hwndFrame,WM_SETICON,(MPARAM)hIcon[a],NULL);
ChangeTrayIcon(hwnd,NULLHANDLE);
break;
case WM_BUTTON1CLICK|0x2000:
case WM_BUTTON2CLICK|0x2000:
/* activate frame window */
WinSetWindowPos(hwndFrame,HWND_TOP,0,0,0,0,SWP_ACTIVATE | SWP_SHOW | SWP_ZORDER | SWP_RESTORE);
break;
case WM_CREATE:
/* initialize window */

/* initialize tray api */
InitializeTrayApi(hwnd);
break;

case WM_DDE_INITIATEACK:
/* aswer dde server */
AnswerTrayApiDdeAck(mp1);
AddTrayIcon(hwnd,WinSendMsg(hwndFrame,WM_QUERYICON,NULL,NULL));
WinStartTimer(hab,hwnd,1,500);

return (MRESULT)0L;

case WM_PAINT:
hps = WinBeginPaint(hwnd,NULL,NULL);
WinQueryWindowRect(hwnd, &rcl);
WinFillRect(hps, &rcl, CLR_CYAN);
GpiSetColor(hps, CLR_DARKBLUE);
GpiSetBackColor(hps, CLR_CYAN);
rcl.xLeft=(rcl.xLeft+rcl.xRight)/2-40;
rcl.yBottom=(rcl.yBottom+rcl.yTop)/2-7;
GpiCharStringAt(hps, (PPOINTL)&rcl, 13, "Hello, world!");
WinEndPaint(hps);
break;

case WM_DESTROY:
/* delete application icon from system tray */
return (MRESULT)DeleteTrayIcon(hwnd);
}

return WinDefWindowProc(hwnd, msg, mp1, mp2);
}