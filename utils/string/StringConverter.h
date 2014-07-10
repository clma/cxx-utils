//***********************************************************
// File		: StringConverter.h
// Time		: 2013-1-14
// Author	: clma
// Desc		: 字符串转换，char*，CString，std::string，wstring，
//			  stringstream，StringArray等间的转换
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

#include <string>
#include <sstream>
using namespace std;

namespace ns_cxxutils
{

/// 字符串转换函数
class CXXUTILS_EXT_CLASS CStringConverter
{
public:
	/**
	*	\brief	将指定的UTF8字符串转换为Unicode后输出
	*	\param[in]	pszSource	源字符串(UTF8)
	*/
	static CString UTF8ToUnicode(const char* pszSource);

	/**
	*	\brief	将指定的Unicode字符串转换为UTF8 string后输出
	*	\param[in]	strSource	源字符串(Unicode)
	*	\return		UTF8 string
	*/
	static string  UnicodeToUTF8(CString strSource);

	///	将CString字符串转换为std::string字符串
	static string CStringTostring(CString &strSource);

	///	将CString字符串转换为std::wstring字符串
	static wstring CStringTowstring(CString const &strSource);

	///	将std::string字符串转换为CString字符串
	static CString stringToCString(string const &strSource);

	///	将std::wstring字符串转换为CString字符串
	static CString wstringToCString(wstring const &strSource);
	
	///	将wstring字符串转换为string字符串
	static string wstringTostring(wstring const &strSource);

	///	将string字符串转换为wstring字符串
	static wstring stringTowstring(string const &strSource);

	/// 将CString字符串输出至stringstream
	static void CStringTostringstream(CString &strSource, stringstream &ss);

	/// 将wstring字符串输出至stringstream
	static void wstringTostringstream(wstring const &strSource, stringstream &ss);

	/// 将string字符串输出至stringstream
	static void stringTostringstream(string const &strSource, stringstream &ss);

	///	将std::stringstream字符串输出为CString字符串
	static CString stringstreamToCString(stringstream const &ss);

	///	将std::stringstream字符串输出为wstring字符串
	static wstring stringstreamTowstring(stringstream const &ss);

	///	将std::stringstream字符串输出为string字符串
	static string stringstreamTostring(stringstream const &ss);

	/// 转换二进制数据为Base64字符串
	static CString BytesToBase64Str(IN  DWORD nSizeInByte, IN  PBYTE pData);

	/// 转换Base64字符串为二进制数据，内存需要外部释放
	static PBYTE Base64StrToBytes(IN CString strBase64, OUT int& nDestLen);

	/// 将字符串数组转换成输出字符串
	static CString SAToStr(const CStringArray& saTransed, CString strSeparator = _T(";"));

	/// @brief 将字符串拆分成字符串数组——若忽略空字符串，则对每个拆分出的分量调用了TrimLeftRight
	///
	/// 【例】“@& abc@&de @&”按“@&”的拆分结果为\n
	///	(1)忽略空字符串：abc,de(拆分后数组长度为2)\n
	///	(2)不略空字符串：, abc,de ,(拆分后数组长度为4)\n
	static void StrToSA(const CString& inpStrSplited, CStringArray& oupStrArray, CString strSeparator = _T(";"), BOOL bIgnoreEmptyStr = TRUE);
};

};