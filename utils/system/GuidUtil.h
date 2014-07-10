//***********************************************************
// File		: GuidUtil.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: Guid操作封装
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
	 * @brief 生成GUID字符串
	 * \param[in]	bIncludeJointSign	指示产生的GUID字符串是否包含连接符“-”。默认为包含！
	 */
	static CString CreateGuidString(BOOL includeJointSign = TRUE);

	/// 创建GUID
	static void CreateGuid(GUID& guid);
};

};
