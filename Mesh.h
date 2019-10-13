#pragma once
class CMesh
{
public:
	CMesh();
	virtual ~CMesh();
protected:
	LPD3DXMESH				m_pMesh;//�Ž�����
	LPD3DXBUFFER			m_pSubSetbuffer;//����
	DWORD					m_dwSubSetCnt;

	LPD3DXMATERIAL			m_pSubSets;//���͸��� ����
	LPDIRECT3DTEXTURE9*		m_pTextures;//�ؽ�ó ����	
	D3DMATERIAL9*			m_pMtrls;

public:
	virtual void			GetBonMatrix(const CHAR* pBoneName, D3DXMATRIX* pOut) {};
public:
	virtual void			InvalidateMesh(D3DXMATRIX* pMatWorld) {}
public:
	virtual HRESULT			CreateMesh(LPDIRECT3DDEVICE9 pDevice
										, const TCHAR* pPath
										, const TCHAR* pFileName)PURE;

	virtual HRESULT			CloneMesh(LPDIRECT3DDEVICE9 pDevice
									 ,CAnimationCtrl** ppAniCtrl) {return S_OK;}

	virtual void			Render(LPDIRECT3DDEVICE9 pDevice, const BONE* pRootBone = NULL) PURE;
	virtual void			Release();
	LPD3DXMESH				GetMesh() { return m_pMesh; }




};

