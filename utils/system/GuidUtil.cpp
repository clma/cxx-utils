#include "StdAfx.h"
#include "GuidUtil.h"

#pragma comment(lib, "Rpcrt4.lib") 

namespace ns_cxxutils
{

CString CGuidUtil::CreateGuidString( BOOL includeJointSign /*= TRUE*/ )
{
	GUID guid = GUID_NULL;
	CoCreateGuid(&guid);

#ifdef UNICODE
	WCHAR* pUuidString;
#else
	BYTE* pUuidString;
#endif

	UuidToString(&guid, (RPC_WSTR*)&pUuidString);
	CString str = pUuidString;
	RpcStringFree((RPC_WSTR*)&pUuidString);

	if( !includeJointSign )
	{
		str.Replace(_T("-"), _T(""));
	}

	str.MakeUpper();
	return str;	
}

void CGuidUtil::CreateGuid( GUID& guid )
{
	CoCreateGuid(&guid);
}

}