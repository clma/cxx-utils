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

/// ����־�����
class CXXUTILS_EXT_CLASS CLog
{
public:
	/// ��ͨ���
	static void Output(CString str);
	/// ��ʽ�����
	static void OutputFormat(LPCTSTR lpszFormat, ...);
};

};
