//***********************************************************
// File		: macro.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: 常用宏定义封装
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
	// delete 替代宏
#ifndef	deleteC
	#define	deleteC(p) \
		do{ \
			if(p){ \
				delete (p); \
				(p) = NULL; \
			} \
		}while(0)
#endif	// !deleteC
};