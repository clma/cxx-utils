#include "StdAfx.h"
#include "AppUtil.h"

namespace ns_cxxutils
{

bool CAppUtil::IsCurAppAlreadyRunning()
{
	bool bFound = false;

	// Try to create a mutex with the app's name
	HANDLE hMutexOneInstance = ::CreateMutex(NULL, TRUE, AfxGetAppName());

	// Already there...means that we are already running an instance
	if( ::GetLastError() == ERROR_ALREADY_EXISTS )
	{
		bFound = true;
	}

	// Release the mutex
	if( hMutexOneInstance != NULL )
	{
		::ReleaseMutex(hMutexOneInstance);
	}

	return(bFound);
}

CString CAppUtil::GetCurDirectory()
{
	TCHAR chrModuleFileName[MAX_PATH];
	memset(chrModuleFileName, 0, sizeof(chrModuleFileName));
	GetModuleFileName(NULL, chrModuleFileName, MAX_PATH);

	CString strCurFullPath = chrModuleFileName;
	int nPos = strCurFullPath.ReverseFind('\\');
	if(nPos == -1)
		return _T("");

	return strCurFullPath.Left(nPos + 1); 
}

}