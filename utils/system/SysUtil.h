//***********************************************************
// File		: SysUtil.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: ϵͳ���ò�����װ
//***********************************************************

#pragma once

#if !defined CXXUTILS_EXT_CLASS
	#define CXXUTILS_EXT_CLASS
#endif

#if !defined CXXUTILS_EXT_API
	#define CXXUTILS_EXT_API
#endif

#if !defined CXXUTILS_EXT_DATA
	#define CXXUTILS_EXT_DATA
#endif

namespace ns_cxxutils
{

class CXXUTILS_EXT_CLASS CSysUtil
{
public:
	// �ߴ��С�ַ�����ת��Ϊ��Ӧ��λ�������KB��MB��GB
	static CString SizeString( LONGLONG llSize );

	// ��ȡ��ǰ��������
	static CString GetMachineName();
};

};
