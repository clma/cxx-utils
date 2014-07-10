//*********************************************************
// File		：TimeCount.h
// Time		：2011-08-10
// Author	：clma
// Desc		：精确计时类 ——头文件
//*********************************************************

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
/// @brief 精确计时类
///
/// 使用说明：\n
/// SetStartTime()和SetEndTime()需要成对使用，看作一次操作计时，GetUseTime()返回该次操作的精确计时（毫秒）\n
/// 同时，GetUseTime()传参为TRUE的话，可以累计多次操作的总时间，使用GetTotalTime()得到。\n
class CXXUTILS_EXT_CLASS CTimeCount
{
public:
	CTimeCount(void);
	~CTimeCount(void);

	/// 设置开始时间
	static void SetStartTime();

	/// 设置结束时间
	static void SetEndTime();

	/// 获取用时
	static double GetUseTime(BOOL bAccumulate = FALSE);

	/// 获取总时间
	static double GetTotalTime();

	/// 所有时间重置
	static void ResetTime();

private:
	static LARGE_INTEGER	m_startTime;	///< 启动时间
	static LARGE_INTEGER	m_endTime;		///< 结束时间
	static LARGE_INTEGER	m_frequency;	///< CPU时钟频率
	
	static double		m_fUseTime;		///< 每次用时(毫秒)
	static double		m_fTotalTime;	///< 总计用时(毫秒)
};

}
