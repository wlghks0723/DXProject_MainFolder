#pragma once
class CXFileUtil
{
public:
	CXFileUtil();
	virtual ~CXFileUtil();
private:
	LPD3DXMESH m_pMesh;//�Ž� ��ü
	D3DMATERIAL9* m_pMeshMaterials;//�Ž��� ���� ����
	LPDIRECT3DTEXTURE9* m_pMeshTexture;//�Ž� �ؽ���
	DWORD m_dwNumMaterials;//������ ��
	LPDIRECT3DDEVICE9 pD3DDevice;
public:
	int XFileRender();
	CXFileUtil* XFileLoad(const char * xFileName);
};

