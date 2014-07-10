//***********************************************************
// File		: GuidUtil.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: Guid������װ
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

class CXXUTILS_EXT_CLASS CGuidUtil
{
public:
	/**
	 * @brief ����GUID�ַ���
	 * \param[in]	bIncludeJointSign	ָʾ������GUID�ַ����Ƿ�������ӷ���-����Ĭ��Ϊ������
	 */
	static CString CreateGuidString(BOOL includeJointSign = TRUE);

	/// ����GUID
	static void CreateGuid(GUID& guid);
};

};
