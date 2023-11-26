
#include "pch.h"
#include "framework.h"
#include "EXERCISE3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <tchar.h>
#include "rxregsvc.h"
#include "acutads.h"
#include "accmd.h"
#pragma comment(linker,"/EXPORT:acrxEntryPoint")
#pragma comment(linker,"/EXPORT:acrxGetApiVersion")

#include "rxregsvc.h"
#include "acutads.h"
#include "aced.h"
#include "acdb.h"
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <aced.h>
#include <dbents.h>
#include <dbsymtb.h>
#include <adslib.h>
#include <geassign.h>
#include <dbidmap.h>
#include <dbapserv.h>
#include <acgi.h>
#include "tchar.h"


void CEXERCISE3App::MyCommand() {
	acutPrintf(_T("\n Hello in the World of AutoCAD 2024!!!"));
}

//entry point function
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
	switch (Msg) {
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		//below line for registering new command
		acedRegCmds->addCommand(L"MyGroup", _T("MYGLOBALCOMMAND"), _T("MYCOMMAND"), ACRX_CMD_MODAL, &CEXERCISE3App::MyCommand);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\n Command Unloaded"));
		break;
	}
	return AcRx::kRetOK;

}

// CObjectintroApp

BEGIN_MESSAGE_MAP(CEXERCISE3App, CWinApp)
END_MESSAGE_MAP()


// CObjectintroApp construction

CEXERCISE3App::CEXERCISE3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectintroApp object

CEXERCISE3App theApp;


// CObjectintroApp initialization

BOOL CEXERCISE3App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}