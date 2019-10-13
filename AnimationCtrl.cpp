#include "BaseInclude.h"
#include "AnimationCtrl.h"
#include"MeshMgr.h"

CAnimationCtrl::CAnimationCtrl()
	: m_dwCurrentAniSet(0)
	, m_numAnimationSets(0)
	, m_fCurrentTime(0.f)
	, m_pAniCtrl(NULL)

{
}

CAnimationCtrl::CAnimationCtrl(const CAnimationCtrl & Ani)
	: m_dwCurrentAniSet(0)
	, m_numAnimationSets(0)
	, m_fCurrentTime(0.f)
	, m_pAniCtrl(NULL)
	,m_strCurrentAniNameSet("")
{
		Ani.m_pAniCtrl->CloneAnimationController(Ani.m_pAniCtrl->GetMaxNumAnimationOutputs()
			, Ani.m_pAniCtrl->GetMaxNumAnimationSets()
			, Ani.m_pAniCtrl->GetMaxNumTracks()
			, Ani.m_pAniCtrl->GetMaxNumEvents()
			, &m_pAniCtrl);
	
}


CAnimationCtrl::~CAnimationCtrl()
{
	Release();
}
//�ε����� �ִϸ��̼� set�� �ǹ�
const float kMoveTransitionTime = 0.25f;

void CAnimationCtrl::SetAnimationSet(int iIdx)
{
	//Ʈ�� 2���� �غ�
	//���� Ʈ���� 0 �̸� 1, 1�̸� 0����
	m_dwNewTrack = (m_dwCurrentTrack == 0 ? 1 : 0);
	LPD3DXANIMATIONSET pAs = NULL;
	//�ִϸ��̼� set ����
	if (m_pAniCtrl == NULL) return;
	
	m_pAniCtrl->GetAnimationSet(iIdx, &pAs);
	//�ִϸ��̼�  Ʈ���� �ִϸ��̼� ���� �ø�
	m_pAniCtrl->SetTrackAnimationSet(m_dwNewTrack, pAs);
	
	pAs->Release();
	
	//���� ���õǾ� �ִ� �ִϸ��̼� ���� �����ϰ����ϴ� �ִϸ��̼� �°� ������
	//�ٽ� ������ �ʿ䰡 ���� , �׷��Ƿ� ����������.
	if (m_dwCurrentAniSet == iIdx)
		return;

	//�� ������ �������� �ʤ����� ���� ���ο� �ִϸ��̼� ����
	//���� �ִϸ��̼� ���� �ε��� �����ϰ� �ִ� ������ �־���
	m_dwCurrentAniSet = iIdx;
	//�� Ʈ���� ó������ ���ư��� �ֵ��� �ʱ�ȭ
	m_pAniCtrl->UnkeyAllTrackEvents(m_dwNewTrack);
	m_pAniCtrl->UnkeyAllTrackEvents(m_dwCurrentTrack);
	
	//Ʈ���� ������ġ ����
	m_pAniCtrl->SetTrackPosition(m_dwNewTrack, 0.f);
	m_pAniCtrl->SetTrackPosition(m_dwCurrentTrack, 0.f);

	m_pAniCtrl->SetTrackEnable(m_dwNewTrack, TRUE);
	m_pAniCtrl->KeyTrackSpeed(m_dwNewTrack, 1.f, m_fCurrentTime, kMoveTransitionTime, D3DXTRANSITION_LINEAR);
	m_pAniCtrl->KeyTrackWeight(m_dwNewTrack, 1.f, m_fCurrentTime, kMoveTransitionTime, D3DXTRANSITION_LINEAR);
}

void CAnimationCtrl::SetAnimationSet(string pName)
{
	//Ʈ�� 2���� �غ�
	//���� Ʈ���� 0 �̸� 1, 1�̸� 0����
	m_dwNewTrack = (m_dwCurrentTrack == 0 ? 1 : 0);
	LPD3DXANIMATIONSET pAs = NULL;
	//�ִϸ��̼� set ����
	if (m_pAniCtrl == NULL) return;

	//�ִϸ��̼�  Ʈ���� �ִϸ��̼� ���� �ø�
	
	m_pAniCtrl->GetAnimationSetByName(pName.c_str(), &pAs);
	m_pAniCtrl->SetTrackAnimationSet(m_dwNewTrack, pAs);

	pAs->Release();

	//���� ���õǾ� �ִ� �ִϸ��̼� ���� �����ϰ����ϴ� �ִϸ��̼� �°� ������
	//�ٽ� ������ �ʿ䰡 ���� , �׷��Ƿ� ����������.
	if (m_strCurrentAniNameSet == pName)
		return;

	//�� ������ �������� �ʤ����� ���� ���ο� �ִϸ��̼� ����
	//���� �ִϸ��̼� ���� �ε��� �����ϰ� �ִ� ������ �־���
	m_strCurrentAniNameSet = pName;
	//�� Ʈ���� ó������ ���ư��� �ֵ��� �ʱ�ȭ
	m_pAniCtrl->UnkeyAllTrackEvents(m_dwNewTrack);
	m_pAniCtrl->UnkeyAllTrackEvents(m_dwCurrentTrack);
	//Ʈ���� ������ġ ����
	m_pAniCtrl->SetTrackPosition(m_dwNewTrack, 0.f);
	m_pAniCtrl->SetTrackPosition(m_dwCurrentTrack, 0.f);

	m_pAniCtrl->SetTrackEnable(m_dwNewTrack, TRUE);
	m_pAniCtrl->KeyTrackSpeed(m_dwNewTrack, 1.f, m_fCurrentTime, kMoveTransitionTime, D3DXTRANSITION_LINEAR);
	m_pAniCtrl->KeyTrackWeight(m_dwNewTrack, 1.f, m_fCurrentTime, kMoveTransitionTime, D3DXTRANSITION_LINEAR);

}

void CAnimationCtrl::FrameMove(const TCHAR * pMeshKey, float fTime)
{
	if (m_pAniCtrl != NULL)
		m_pAniCtrl->AdvanceTime(fTime, NULL);
	m_fCurrentTime += fTime;

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	(*(CMeshMgr::GetInstance()))->InvalidateMesh(pMeshKey, &matWorld);
}

CAnimationCtrl * CAnimationCtrl::Clone()
{
	return new CAnimationCtrl(*this);
}

void CAnimationCtrl::Release()
{
	if (m_pAniCtrl)
	{
		m_pAniCtrl->Release();
	}
}
