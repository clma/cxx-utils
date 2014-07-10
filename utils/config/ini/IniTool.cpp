#include "StdAfx.h"
#include "IniTool.h"

namespace ns_cxxutils
{

IniTool::IniTool()
{
}

IniTool::~IniTool(void)
{
}

bool IniTool::SetFilePath(CString sFilePath)
{
	CFileFind finder;
	if(FALSE == finder.FindFile(sFilePath))
		return false;

	m_sFilePath = sFilePath;

	return true;
}

CString IniTool::GetValueString(CString sSection, CString sKey, CString sDefault)
{
	CString sValue;
	::GetPrivateProfileString(sSection, sKey, sDefault, sValue.GetBuffer(_MAX_PATH), _MAX_PATH, m_sFilePath);
	sValue.ReleaseBuffer();

	return sValue;
}

int IniTool::GetValueInt( CString sSection, CString sKey, int iDefault/*=0*/ )
{
	CString strDefault;
	strDefault.Format(_T("%d"), iDefault);
	CString sValue = this->GetValueString(sSection, sKey, strDefault);
	return _tstoi(sValue);
}

long IniTool::GetValueLong(CString sSection, CString sKey, long lDefault)
{
	CString strDefault;
	strDefault.Format(_T("%ld"), lDefault);
	CString sValue = this->GetValueString(sSection, sKey, strDefault);
	return _tstol(sValue);
}

bool IniTool::GetValueBoolean( CString sSection, CString sKey, bool bDefault/*=false*/ )
{
	CString strDefault;
	strDefault.Format(_T("%d"), bDefault ? 1 : 0);
	CString sValue = this->GetValueString(sSection, sKey, strDefault);
	return (1 == _tstoi(sValue));
}

float IniTool::GetValueFloat(CString sSection, CString sKey, float fDefault)
{
	CString strDefault;
	strDefault.Format(_T("%f"), fDefault);
	CString sValue = this->GetValueString(sSection, sKey, strDefault);
	return (float)_tstof(sValue);
}

void IniTool::SetValue(CString sSection, CString sKey, CString sValue)
{
	::WritePrivateProfileString(sSection, sKey, sValue, m_sFilePath);
}

void IniTool::DeleteSection(CString sSection)
{
	::WritePrivateProfileString(sSection, NULL, NULL, m_sFilePath);
}

}