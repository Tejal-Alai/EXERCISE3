// EXERCISE3.h : main header file for the EXERCISE3 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>



// CEXERCISE3App
// See EXERCISE3.cpp for the implementation of this class
//

class CEXERCISE3App : public CWinApp
{
public:
	CEXERCISE3App();

// Overrides
public:
	virtual BOOL InitInstance();

static void MyCommand();
	DECLARE_MESSAGE_MAP()
};

//Entry point function
static int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);