//***********************************************************
// File		: SysUtil.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: 系统常用操作封装
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
	// 尺寸大小字符串，转换为对应单位输出，如KB、MB、GB
	static CString SizeString( LONGLONG llSize );

	// 获取当前机器名称
	static CString GetMachineName();
};

};
