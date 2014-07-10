#include "StdAfx.h"
#include "StringConverter.h"

#include "CharSetTransferMacro.h"
#include <atlenc.h>

namespace ns_cxxutils
{

CString CStringConverter::UTF8ToUnicode( const char* pszSource )
{
	USES_MYCP_CONVERSION;
	USES_CP_UTF8;
	return CP2W(pszSource, CP_UTF8);
}

std::string CStringConverter::UnicodeToUTF8( CString strSource )
{
	USES_MYCP_CONVERSION;
	USES_CP_UTF8;
	return W2CP(strSource.GetBuffer(0), CP_UTF8);
}

std::string CStringConverter::CStringTostring( CString &strSource )
{
	return UnicodeToUTF8( strSource );

	/*
	 * another method
	char* pString(NULL);	
	int iSize = ::WideCharToMultiByte(CP_ACP, 0, strSource, strSource.GetLength(), pString, 0, NULL, NULL);
	if(iSize > 0)
	{
		pString = new char[iSize + 1];
		iSize = ::WideCharToMultiByte(CP_ACP, 0, strSource, strSource.GetLength(), pString, iSize + 1, NULL, NULL);
		pString[iSize] = '\0';
		std::string sString(pString);
		delete[] pString;

		return sString;
	}
	return "";
	*/
}

std::wstring CStringConverter::CStringTowstring( CString const &strSource )
{
	return (LPCWSTR)strSource;
}

CString CStringConverter::stringToCString( string const &strSource )
{
	return UTF8ToUnicode( strSource.c_str() );

	/*
	 * another method
	wchar_t* pString(NULL);
	int iSize = ::MultiByteToWideChar(CP_ACP, 0, strSource.c_str(), -1, pString, 0);
	if(iSize > 0)
	{
		pString = new wchar_t[iSize + 1];
		iSize = ::MultiByteToWideChar(CP_ACP, 0, strSource.c_str(), -1, pString, iSize + 1);
		pString[iSize] = L'\0';
		CString strString = pString;
		delete[] pString;

		return strString;
	}
	return _T("");
	*/
}

CString CStringConverter::wstringToCString( wstring const &strSource )
{
	return (CString)strSource.c_str();
}

string CStringConverter::wstringTostring( wstring const &strSource )
{
	return CStringTostring(wstringToCString(strSource));
}

wstring CStringConverter::stringTowstring( string const &strSource )
{
	return CStringTowstring(stringToCString(strSource));
}

void CStringConverter::CStringTostringstream( CString &strSource, stringstream &ss )
{
	ss.str( CStringTostring(strSource) );
}

void CStringConverter::wstringTostringstream( wstring const &strSource, stringstream &ss )
{
	ss.str(wstringTostring(strSource));
}

void CStringConverter::stringTostringstream( string const &strSource, stringstream &ss )
{
	ss.str(strSource);
}

CString CStringConverter::stringstreamToCString( stringstream const &ss )
{
	string strTemp = ss.str();
	return stringToCString(strTemp);
}

wstring CStringConverter::stringstreamTowstring( stringstream const &ss )
{
	return CStringTowstring(stringstreamToCString(ss));
}

string CStringConverter::stringstreamTostring( stringstream const &ss )
{
	return (string)ss.str();
}

// 转换二进制数据为Base64字符串
CString CStringConverter::BytesToBase64Str( IN DWORD nSizeInByte, IN PBYTE pData )
{
	if ( 0 == nSizeInByte || NULL == pData )
	{
		return _T("");
	}

	TCHAR * pCharTemp = new TCHAR[nSizeInByte*2];
	memset(pCharTemp, 0, nSizeInByte*2); 

	int nDesLen = nSizeInByte*2;

	if ( !::Base64Encode( (BYTE*)pData, nSizeInByte, (LPSTR)pCharTemp, &nDesLen ) )
	{
		OutputDebugString(_T("Base64Encode Failed！"));

		delete [] pCharTemp;
		pCharTemp = NULL;

		return _T("");
	}

	CString strBase64 = pCharTemp;

	delete [] pCharTemp;
	pCharTemp = NULL;

	return strBase64;
}

/// 转换Base64字符串为二进制数据
PBYTE CStringConverter::Base64StrToBytes( IN CString strBase64, OUT int& nDestLen )
{
	if ( strBase64.IsEmpty() )
	{
		nDestLen = 0;
		return NULL;
	}

	int nSrcLen = strBase64.GetLength();
	nDestLen = nSrcLen;

	PBYTE pbDataNew = new BYTE[ nSrcLen];
	memset(pbDataNew, 0, nSrcLen);

	// 	USES_CONVERSION;
	// 	LPCSTR lpcs = NULL;    
	// 	lpcs = T2A(strBase64.GetBuffer(strBase64.GetLength())); 

	// Begin 解决堆栈溢出的问题 修改于2011-10-14
	// 原因分析：ATL中的字符串函数T2A使用的内存是在堆栈中的，容易造成溢出。修改为从堆中申请内存
	const int nLength = WideCharToMultiByte(CP_ACP, 0, strBase64.GetBuffer(), -1, NULL, 0, NULL, 0) + 1;
	char* pCharBuffer = new char[nLength]; 

	if (!pCharBuffer)
	{
		return NULL;
	}
	memset (pCharBuffer, 0x00, sizeof (char)*nLength);
	WideCharToMultiByte(CP_ACP, 0, strBase64.GetBuffer(), -1, pCharBuffer, nLength, NULL, 0);
	// End 解决堆栈溢出的问题 修改于2011-10-14

	if( ! ::Base64Decode( pCharBuffer, nSrcLen, pbDataNew, &nDestLen) )
	{
		OutputDebugString(_T("CDYEXMLHandler::GetNodeValueBinary--解码失败！"));
		nDestLen = 0;
		delete [] pbDataNew;
		return NULL;
	}

	return pbDataNew;
}

//	函数功能 : 将字符串数组转换成输出字符串
///////////////////////////////////////////////////////////////
CString CStringConverter::SAToStr(const CStringArray& saTransed, CString strSeparator /*= _T(";")*/)
{
	CString strResult = _T("");

	if(saTransed.GetSize() > 0)
	{
		strResult += saTransed[0];
	}

	for(int i = 1; i < saTransed.GetSize(); i++)
	{
		strResult += strSeparator + saTransed[i];
	}

	return strResult;
}


//	函数功能 : 将字符串拆分成字符串数组
///////////////////////////////////////////////////////////////
void CStringConverter::StrToSA(const CString& inpStrSplited, CStringArray& oupStrArray, CString strSeparator /*= _T(";")*/, BOOL bIgnoreEmptyStr /*= TRUE*/)
{
	oupStrArray.RemoveAll();	
	CString strSplited = inpStrSplited;

	// 依次拆分
	int nPos = strSplited.Find(strSeparator);
	CString strTemp;
	while(nPos != -1)
	{
		strTemp = strSplited.Left(nPos);
		if(bIgnoreEmptyStr)
			// 忽略空字符串
		{
			strTemp.TrimLeft();
			strTemp.TrimRight();
			if(!strTemp.IsEmpty())
			{
				oupStrArray.Add(strTemp);
			}			
		}
		else
			// 不忽略空字符串
		{
			oupStrArray.Add(strTemp);
		}		

		strSplited = strSplited.Mid(nPos + strSeparator.GetLength());
		nPos = strSplited.Find(strSeparator);
	}

	// 处理最后一截
	if(bIgnoreEmptyStr)
		// 忽略空字符串
	{
		strSplited.TrimLeft();
		strSplited.TrimRight();
		if(!strSplited.IsEmpty())
		{
			oupStrArray.Add(strSplited);
		}			
	}
	else
		// 不忽略空字符串
	{
		oupStrArray.Add(strSplited);
	}
}

}