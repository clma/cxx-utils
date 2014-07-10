//***********************************************************
// File		: IniTool.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: ini文件读写工具类
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
	 * 设置文件路径(绝对路径)
	 * @return 文件是否存在
	 */
	bool SetFilePath(CString sFilePath);

	/**
	 * 获取配置值
	 */	
	CString GetValueString(CString sSection, CString sKey, CString sDefault=_T(""));
	long GetValueLong(CString sSection, CString sKey, long lDefault=0);
	int GetValueInt(CString sSection, CString sKey, int iDefault=0);
	bool GetValueBoolean(CString sSection, CString sKey, bool bDefault=false);
	float GetValueFloat(CString sSection, CString sKey, float fDefault=0.0f);

	/**
	 * 写入配置值
	 */
	void SetValue(CString sSection, CString sKey, CString sValue);

	/**
	 * 删除区段
	 */
	void DeleteSection(CString sSection);

private:
	CString m_sFilePath;
};

};