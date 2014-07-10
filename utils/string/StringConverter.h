//***********************************************************
// File		: StringConverter.h
// Time		: 2013-1-14
// Author	: clma
// Desc		: �ַ���ת����char*��CString��std::string��wstring��
//			  stringstream��StringArray�ȼ��ת��
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

/// �ַ���ת������
class CXXUTILS_EXT_CLASS CStringConverter
{
public:
	/**
	*	\brief	��ָ����UTF8�ַ���ת��ΪUnicode�����
	*	\param[in]	pszSource	Դ�ַ���(UTF8)
	*/
	static CString UTF8ToUnicode(const char* pszSource);

	/**
	*	\brief	��ָ����Unicode�ַ���ת��ΪUTF8 string�����
	*	\param[in]	strSource	Դ�ַ���(Unicode)
	*	\return		UTF8 string
	*/
	static string  UnicodeToUTF8(CString strSource);

	///	��CString�ַ���ת��Ϊstd::string�ַ���
	static string CStringTostring(CString &strSource);

	///	��CString�ַ���ת��Ϊstd::wstring�ַ���
	static wstring CStringTowstring(CString const &strSource);

	///	��std::string�ַ���ת��ΪCString�ַ���
	static CString stringToCString(string const &strSource);

	///	��std::wstring�ַ���ת��ΪCString�ַ���
	static CString wstringToCString(wstring const &strSource);
	
	///	��wstring�ַ���ת��Ϊstring�ַ���
	static string wstringTostring(wstring const &strSource);

	///	��string�ַ���ת��Ϊwstring�ַ���
	static wstring stringTowstring(string const &strSource);

	/// ��CString�ַ��������stringstream
	static void CStringTostringstream(CString &strSource, stringstream &ss);

	/// ��wstring�ַ��������stringstream
	static void wstringTostringstream(wstring const &strSource, stringstream &ss);

	/// ��string�ַ��������stringstream
	static void stringTostringstream(string const &strSource, stringstream &ss);

	///	��std::stringstream�ַ������ΪCString�ַ���
	static CString stringstreamToCString(stringstream const &ss);

	///	��std::stringstream�ַ������Ϊwstring�ַ���
	static wstring stringstreamTowstring(stringstream const &ss);

	///	��std::stringstream�ַ������Ϊstring�ַ���
	static string stringstreamTostring(stringstream const &ss);

	/// ת������������ΪBase64�ַ���
	static CString BytesToBase64Str(IN  DWORD nSizeInByte, IN  PBYTE pData);

	/// ת��Base64�ַ���Ϊ���������ݣ��ڴ���Ҫ�ⲿ�ͷ�
	static PBYTE Base64StrToBytes(IN CString strBase64, OUT int& nDestLen);

	/// ���ַ�������ת��������ַ���
	static CString SAToStr(const CStringArray& saTransed, CString strSeparator = _T(";"));

	/// @brief ���ַ�����ֳ��ַ������顪�������Կ��ַ��������ÿ����ֳ��ķ���������TrimLeftRight
	///
	/// ��������@& abc@&de @&������@&���Ĳ�ֽ��Ϊ\n
	///	(1)���Կ��ַ�����abc,de(��ֺ����鳤��Ϊ2)\n
	///	(2)���Կ��ַ�����, abc,de ,(��ֺ����鳤��Ϊ4)\n
	static void StrToSA(const CString& inpStrSplited, CStringArray& oupStrArray, CString strSeparator = _T(";"), BOOL bIgnoreEmptyStr = TRUE);
};

};