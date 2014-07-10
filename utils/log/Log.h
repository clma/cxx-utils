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

/// 简单日志输出类
class CXXUTILS_EXT_CLASS CLog
{
public:
	/// 普通输出
	static void Output(CString str);
	/// 格式化输出
	static void OutputFormat(LPCTSTR lpszFormat, ...);
};

};
