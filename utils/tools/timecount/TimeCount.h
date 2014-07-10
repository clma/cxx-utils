//*********************************************************
// File		��TimeCount.h
// Time		��2011-08-10
// Author	��clma
// Desc		����ȷ��ʱ�� ����ͷ�ļ�
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
/// @brief ��ȷ��ʱ��
///
/// ʹ��˵����\n
/// SetStartTime()��SetEndTime()��Ҫ�ɶ�ʹ�ã�����һ�β�����ʱ��GetUseTime()���ظôβ����ľ�ȷ��ʱ�����룩\n
/// ͬʱ��GetUseTime()����ΪTRUE�Ļ��������ۼƶ�β�������ʱ�䣬ʹ��GetTotalTime()�õ���\n
class CXXUTILS_EXT_CLASS CTimeCount
{
public:
	CTimeCount(void);
	~CTimeCount(void);

	/// ���ÿ�ʼʱ��
	static void SetStartTime();

	/// ���ý���ʱ��
	static void SetEndTime();

	/// ��ȡ��ʱ
	static double GetUseTime(BOOL bAccumulate = FALSE);

	/// ��ȡ��ʱ��
	static double GetTotalTime();

	/// ����ʱ������
	static void ResetTime();

private:
	static LARGE_INTEGER	m_startTime;	///< ����ʱ��
	static LARGE_INTEGER	m_endTime;		///< ����ʱ��
	static LARGE_INTEGER	m_frequency;	///< CPUʱ��Ƶ��
	
	static double		m_fUseTime;		///< ÿ����ʱ(����)
	static double		m_fTotalTime;	///< �ܼ���ʱ(����)
};

}
