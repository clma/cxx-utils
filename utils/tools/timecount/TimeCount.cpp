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

// ���ÿ�ʼʱ��
void CTimeCount::SetStartTime()
{
	QueryPerformanceFrequency(&m_frequency);
	// ��¼����ʱ��
	QueryPerformanceCounter(&m_startTime);

	CString strStartTime;
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	strStartTime.Format(_T("CTimeCount::SetStartTime() -- Start��%02d:%02d:%02d.%03d"), sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds);
	OutputDebugString(strStartTime);

}

// ���ý���ʱ��
void CTimeCount::SetEndTime()
{
	// ��¼����ʱ��
	QueryPerformanceCounter(&m_endTime);

	CString strEndTime;
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	strEndTime.Format(_T("CTimeCount::SetEndTime() -- End�� %02d:%02d:%02d.%03d"), sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds);
	OutputDebugString(strEndTime);
}

// ��ȡ��ʱ
// BOOL bAccumulate -- [in] �Ƿ��ۼ�ʱ��
double CTimeCount::GetUseTime(BOOL bAccumulate/* = FALSE*/)
{
	// ������ʱ 
	double dInterval = (double)(m_endTime.QuadPart - m_startTime.QuadPart);  
	m_fUseTime = dInterval / (double)m_frequency.QuadPart * 1000.0;

	CString strUseTime;
	strUseTime.Format(_T("CTimeCount::GetUseTime() -- Use Time�� %.3f ms"), m_fUseTime);
	OutputDebugString(strUseTime);

	if(bAccumulate)
	{
		m_fTotalTime += m_fUseTime;
	}

	return m_fUseTime;
}

// ��ȡ��ʱ��
double CTimeCount::GetTotalTime()
{
	CString strTotalTime;
	strTotalTime.Format(_T("CTimeCount::GetTotalTime() -- Total Time�� %.3f ms"), m_fTotalTime);
	OutputDebugString(strTotalTime);

	return m_fTotalTime;
}

// ����ʱ������
void CTimeCount::ResetTime()
{
	m_fUseTime = 0.0f;
	m_fTotalTime = 0.0f;
}

}