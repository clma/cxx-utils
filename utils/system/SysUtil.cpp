#include "StdAfx.h"
#include "SysUtil.h"

namespace ns_cxxutils
{

CString CSysUtil::SizeString( LONGLONG llSize )
{
	CString retStr;
	if( llSize <= 1024 )
		retStr.Format( _T("%d Byte"), llSize );
	else if( llSize <= 1024*1024 )
		retStr.Format( _T("%d KB"), llSize/1024 );
	else if( llSize <= 1024*1024*1024 )
		retStr.Format( _T("%5.1f MB"), (double)llSize/(1024.0*1024.0));
	else if( llSize <= (LONGLONG)1024*(LONGLONG)1024*(LONGLONG)1024*(LONGLONG)1024 )
		retStr.Format( _T("%5.1f GB"), (double)llSize/((double)1024.0*(double)1024.0*(double)1024.0));
	else
		retStr.Format( _T("%5.1f TB"), (double)llSize/((double)1024.0*(double)1024.0*(double)1024.0*(double)1024.0 ));
	return retStr;
}

CString CSysUtil::GetMachineName()
{
	WORD wVersion = MAKEWORD(2, 0);
	WSADATA wsadata;
	int nRet = WSAStartup(wVersion, &wsadata);
	if(nRet != 0) 
	{
		return _T("");
	}

	USES_CONVERSION;
	char szhost[_MAX_PATH];
	if( gethostname((char*)szhost, _MAX_PATH) != 0 )
	{
		WSACleanup();
		return _T("");
	}

	WSACleanup();

	return CString(szhost);
}
}