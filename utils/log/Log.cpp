#include "StdAfx.h"
#include "Log.h"

namespace ns_cxxutils
{

void CLog::Output( CString str )
{
	OutputDebugString(str);
}

void CLog::OutputFormat( LPCTSTR lpszFormat, ... )
{
	CString strTemp;

	va_list args;
	va_start(args, lpszFormat);
	strTemp.FormatV(lpszFormat, args);
	va_end(args);
	
	CLog::Output( strTemp + _T("\n"));
}

}