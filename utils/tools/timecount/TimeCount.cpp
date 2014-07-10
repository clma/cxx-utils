#include "StdAfx.h"
#include "TimeCount.h"

namespace ns_cxxutils
{

LARGE_INTEGER CTimeCount::m_startTime = {0};
LARGE_INTEGER CTimeCount::m_frequency = {0};
LARGE_INTEGER CTimeCount::m_endTime = {0};

double CTimeCount::m_fUseTime = 0.0f;
double CTimeCount::m_fTotalTime = 0.0f;

CTimeCount::CTimeCount(void)
{
}

CTimeCount::~CTimeCount(void)
{
}

// 设置开始时间
void CTimeCount::SetStartTime()
{
	QueryPerformanceFrequency(&m_frequency);
	// 记录启动时间
	QueryPerformanceCounter(&m_startTime);

	CString strStartTime;
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	strStartTime.Format(_T("CTimeCount::SetStartTime() -- Start：%02d:%02d:%02d.%03d"), sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds);
	OutputDebugString(strStartTime);

}

// 设置结束时间
void CTimeCount::SetEndTime()
{
	// 记录结束时间
	QueryPerformanceCounter(&m_endTime);

	CString strEndTime;
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	strEndTime.Format(_T("CTimeCount::SetEndTime() -- End： %02d:%02d:%02d.%03d"), sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds);
	OutputDebugString(strEndTime);
}

// 获取用时
// BOOL bAccumulate -- [in] 是否累加时间
double CTimeCount::GetUseTime(BOOL bAccumulate/* = FALSE*/)
{
	// 计算用时 
	double dInterval = (double)(m_endTime.QuadPart - m_startTime.QuadPart);  
	m_fUseTime = dInterval / (double)m_frequency.QuadPart * 1000.0;

	CString strUseTime;
	strUseTime.Format(_T("CTimeCount::GetUseTime() -- Use Time： %.3f ms"), m_fUseTime);
	OutputDebugString(strUseTime);

	if(bAccumulate)
	{
		m_fTotalTime += m_fUseTime;
	}

	return m_fUseTime;
}

// 获取总时间
double CTimeCount::GetTotalTime()
{
	CString strTotalTime;
	strTotalTime.Format(_T("CTimeCount::GetTotalTime() -- Total Time： %.3f ms"), m_fTotalTime);
	OutputDebugString(strTotalTime);

	return m_fTotalTime;
}

// 所有时间重置
void CTimeCount::ResetTime()
{
	m_fUseTime = 0.0f;
	m_fTotalTime = 0.0f;
}

}