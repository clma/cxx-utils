#pragma once

#undef	CXXUTILS_EXT_CLASS
#undef	CXXUTILS_EXT_API
#undef	CXXUTILS_EXT_DATA
#define CXXUTILS_EXT_CLASS		__declspec(dllimport)
#define CXXUTILS_EXT_API		__declspec(dllimport)
#define CXXUTILS_EXT_DATA		__declspec(dllimport)


// ����ӿ�ͷ�ļ�
#include "../utils/string/CharSetTransferMacro.h"
#include "../utils/string/StringConverter.h"

#include "../utils/log/Log.h"

#include "../utils/config/ini/IniTool.h"

#include "../utils/tools/timecount/TimeCount.h"

#include "../utils/xml/markup/Markup.h"

#include "../utils/system/AppUtil.h"
#include "../utils/system/SysUtil.h"
#include "../utils/system/GuidUtil.h"

// ���Lib����
#ifdef WIN64
	#ifdef _DEBUG
		#pragma message("******** cxxutils����ǰ���뻷�� = Win64_UnicodeDebug ********")
		#pragma comment(lib, __FILE__"\\..\\..\\lib\\x64\\cxxutilsUD.lib")
	#else
		#pragma message("******** cxxutils����ǰ���뻷�� = Win64_UnicodeRelease ********")
		#pragma comment(lib, __FILE__"\\..\\..\\lib\\x64\\cxxutilsU.lib")
	#endif	// _DEBUG
#else
	#ifdef _DEBUG
		#pragma message("******** cxxutils����ǰ���뻷�� = Win32_UnicodeDebug ********")
		#pragma comment(lib, __FILE__"\\..\\..\\lib\\x86\\cxxutilsUD.lib")
	#else
		#pragma message("******** cxxutils����ǰ���뻷�� = Win32_UnicodeRelease ********")
		#pragma comment(lib, __FILE__"\\..\\..\\lib\\x86\\cxxutilsU.lib")
	#endif	// _DEBUG
#endif	 //WIN64