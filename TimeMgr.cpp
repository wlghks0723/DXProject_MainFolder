#include "BaseInclude.h"
#include "TimeMgr.h"

CTimeMgr::CTimeMgr()
{
}


CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::SetTime()
{
	QueryPerformanceCounter(&m_InvaliTime);

	if (m_InvaliTime.QuadPart - m_LastTime.QuadPart > m_CpuTick.QuadPart)
	{
		QueryPerformanceFrequency(&m_CpuTick);
		m_LastTime = m_InvaliTime;
	}

	m_fTime = float(m_InvaliTime.QuadPart - m_FixTime.QuadPart) / m_CpuTick.QuadPart;
	m_FixTime = m_InvaliTime;
}

void CTimeMgr::InitTimeMgr()
{
	// 1�ʿ� cpu�� ī�����ϴ� ����
	QueryPerformanceFrequency(&m_CpuTick);

	// ���� cpu�� ī������ ����
	QueryPerformanceCounter(&m_LastTime);
	QueryPerformanceCounter(&m_InvaliTime);
	QueryPerformanceCounter(&m_FixTime);
	// ���� ���� ����	
	QueryPerformanceCounter(&m_NowTime);
	m_nFPS = 0;
	m_fDeltaTime = 0.f;
	m_fPileDeltaTime = 0.f;
}

bool CTimeMgr::UpdateTimeMgr()
{
	LARGE_INTEGER tTime;
	QueryPerformanceCounter(&tTime);
	m_fDeltaTime = (tTime.QuadPart - m_NowTime.QuadPart) / (float)m_CpuTick.QuadPart;

	if (m_fDeltaTime < SEC_PER_FRAME) // frame ����
		return false;

	m_NowTime = tTime;
	static int nCountFPS = 0;
	nCountFPS++;
	m_fPileDeltaTime += m_fDeltaTime;
	if (m_fPileDeltaTime >= 1.f) {
		m_fPileDeltaTime = 0.f;
		m_nFPS = nCountFPS;
		nCountFPS = 0;
	}
	g_fDeltaTime = m_fDeltaTime;
	return true;
}
