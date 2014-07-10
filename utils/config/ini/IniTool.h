//***********************************************************
// File		: IniTool.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: ini�ļ���д������
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

class CXXUTILS_EXT_CLASS IniTool
{
public:
	IniTool();
	~IniTool();

	/**
	 * �����ļ�·��(����·��)
	 * @return �ļ��Ƿ����
	 */
	bool SetFilePath(CString sFilePath);

	/**
	 * ��ȡ����ֵ
	 */	
	CString GetValueString(CString sSection, CString sKey, CString sDefault=_T(""));
	long GetValueLong(CString sSection, CString sKey, long lDefault=0);
	int GetValueInt(CString sSection, CString sKey, int iDefault=0);
	bool GetValueBoolean(CString sSection, CString sKey, bool bDefault=false);
	float GetValueFloat(CString sSection, CString sKey, float fDefault=0.0f);

	/**
	 * д������ֵ
	 */
	void SetValue(CString sSection, CString sKey, CString sValue);

	/**
	 * ɾ������
	 */
	void DeleteSection(CString sSection);

private:
	CString m_sFilePath;
};

};