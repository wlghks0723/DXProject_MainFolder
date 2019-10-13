#pragma once
class CAnimationCtrl
{
public:
	CAnimationCtrl();
	CAnimationCtrl(const CAnimationCtrl& Ani);
	~CAnimationCtrl();
private:
	LPD3DXANIMATIONCONTROLLER m_pAniCtrl;
	//���� �����ϰ� �ִ� �ִϸ��̼� Set
	//�ִϸ��̼� Set�̶� ? x���Ͽ��� �������ִ� ����, ���,�ٱ�,�ȱ���� ��ǵ��� �̾߱���
	//�� ��Ǵ� �� Set�̶�� �θ�, ���� ���� �װ��� ����� ������
	//x������ �װ��� �ִϸ��̼� set�� ���� ���̶�� �� �� ����
	
	DWORD m_dwCurrentTrack;//���� Ʈ��
	DWORD m_dwNewTrack;//���ο� ��
	DWORD m_dwCurrentAniSet;//���� �ִϸ��̼� set
	string m_strCurrentAniNameSet;
	//x���� ������ �������ִ� �ִϸ��̼� Set����
	int m_numAnimationSets;
	int m_fCurrentTime;

public:
	//�ִϸ��̼� ���� �Լ�
	// �ش� �Լ����� �ִϸ��̼��� �鸮�����ϴ� ��ü�� Progres�Լ����� �ݺ� ȣ��
	// Ư���ִϸ��̼��� �����ϱ� ���� �Լ�
	//���⿡�� �ε����� ��ü �ִϸ��̼��� � �κ��� ������ ������ �Ǵ��ϴ� ����
	void SetAnimationSet(int);
	void SetAnimationSet( string pName);
	void FrameMove(const TCHAR* pMeshKey, float fTime);

public:
	LPD3DXANIMATIONCONTROLLER* GetAniCtrl()
	{
		return &m_pAniCtrl;
	}
	CAnimationCtrl* Clone();
public:
	void Release();

};

