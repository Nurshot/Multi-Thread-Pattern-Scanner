//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you

#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused
#include <windows.h>
//---------------------------------------------------------------------------
#include "frmMain.h"
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>


USEFORM("frmMain.cpp", MainForm);


DWORD WINAPI AnotherThread(void* ThreadParameter)
{
   try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		//TStyleManager::FindStyle("C:\\Users\\root\\Documents\\Embarcadero\\Studio\\22.0\\Styles\\Carbon.vsf") ;
		//TStyleManager::IsValidStyle("C:\Program Files (x86)\Embarcadero\Studio\22.0\Redist\styles\vcl\Carbon.vsf");
		//TStyleManager::LoadFromFile("C:\Program Files (x86)\Embarcadero\Studio\22.0\Redist\styles\vcl\Carbon.vsf");
		//TStyleManager::TrySetStyle("C:\\Users\\root\\Documents\\Embarcadero\\Studio\\22.0\\Styles\\Carbon.vsf");
		//TStyleManager::TrySetStyle("Carbon");

		Application->CreateForm(__classid(TMainForm), &MainForm);

		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}




BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(AnotherThread), hModule, 0, NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


