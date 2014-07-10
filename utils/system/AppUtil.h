//***********************************************************
// File		: AppUtil.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: App应用常用操作封装
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

class CXXUTILS_EXT_CLASS CAppUtil
{
public:
	/// Determine if Outplay is already running by using a Mutex object -- returns\n
	/// TRUE if already running, FALSE otherwise.  Note that a mutex is created\n
	/// with the name of the application\n
	static bool IsCurAppAlreadyRunning();

	/// 获取当前模块所在路径，常用于获取当前应用运行路径
	static CString GetCurDirectory();
};

};