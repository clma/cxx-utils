//***********************************************************
// File		: macro.h
// Time		: 2014-7-10
// Author	: clma
// Desc		: ���ú궨���װ
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
	// delete �����
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