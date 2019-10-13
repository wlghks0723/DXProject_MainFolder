#pragma once
#include "StateObj.h"
class CObj : public CStateObj
{
public:
	CObj();
	virtual ~CObj();
protected:
	SORTID		m_SortID;//���� ���� ����
	
	INFO		m_Info;//������Ʈ ����
	float		m_fAngle[ANGLE_END];//����(x,y,z)
protected:
	VTXTEX*		m_pOriVtx;//���� ���ؽ�
	VTXTEX*		m_pConVtx;//��ȭ�� ���ؽ�
	int			m_FaceNum;// <- ��ȯ�� �����߰��� �ɹ�(Champion�� ���� ����)
	int			m_VtxNum;
protected:
	D3DXVECTOR3 m_vMin;//�ּ� �ִ밪
	D3DXVECTOR3 m_vMax;//�ּ� �ִ밪
	bool		m_bColl;//�浹���� �˻� ����
public:
	const D3DXVECTOR3* GetMinData() const {
		return &m_vMin;
	}
	const D3DXVECTOR3* GetMaxData() const
	{
		return &m_vMax;
	}
public:
	SORTID GetSortID(void) {
		return m_SortID;
	}
	const INFO* GetInfo() const
	{
		return &m_Info;
	}
	const VTXTEX* GetVtxInfo() const
	{
		return m_pOriVtx;
	}
	const int GetVtxNumber()
	{
		return m_FaceNum * 3;
	}
public:
	virtual void SetContantTable() {}
public:
	virtual HRESULT Initialize() PURE;
	virtual void Progress()PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	
};