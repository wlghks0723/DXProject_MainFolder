
#include"BaseInclude.h"
#include "ResourceFunc.h"
#include "BufferMgr.h"
#include "TextureMgr.h"
#include "BoundingMgr.h"
#include "MeshMgr.h"
#include "AnimationCtrl.h"
//���� ����
extern  HRESULT Insert_Buffer(LPDIRECT3DDEVICE9 pDevice, const TCHAR* pBufferKey
	, BUFFERTYPE Type
	, const int& iVtxCntX/* = 0*/
	, const int& iVtxCntZ/* = 0*/
	, const float& fGap/* = 1.f*/)
{
	return (*(CBufferMgr::GetInstance()))->AddBuffers(pDevice, pBufferKey, Type
		, iVtxCntX, iVtxCntZ, fGap);
}
//��������(�ؽ�ó�� ���� ���ؽ� ������ �����´�.)
extern  void CopyVertexInfo(const TCHAR* pBufferKey
	, VTXTEX* pOriVtx)
{
	(*(CBufferMgr::GetInstance()))->CopyVertexInfo(pBufferKey, pOriVtx);
}
//�ε�������
extern  void CopyIndexBuffer(const TCHAR* pBufferKey
	, INDEX* pIndex, const int& iTriCnt)
{
	(*(CBufferMgr::GetInstance()))->CopyIndexBuffer(pBufferKey, pIndex, iTriCnt);
}

extern  void PasteVertexInfo(const TCHAR* pBufferKey
	, VTXTEX* pConVtx)
{
	(*(CBufferMgr::GetInstance()))->PasteVertexInfo(pBufferKey, pConVtx);
}
//Buffer�� �������ϴ°ſ� ���õ� �͵��� ��������
extern  void Buffer_Render(LPDIRECT3DDEVICE9 pDevice
	, const TCHAR* pBufferKey)
{
	(*(CBufferMgr::GetInstance()))->Buffer_Render(pDevice, pBufferKey);
}
//�ؽ��� ����
extern  HRESULT		InsertTexture(LPDIRECT3DDEVICE9 pDevice
	, TEXTYPE Type
	, const TCHAR* pFileName
	, const TCHAR* pObjectKey
	, const TCHAR* pStateKey
	, const int& iCnt/* = 1*/,TERRIAN_INSERTTYPE INSERType)

{
	return (*(CTextureMgr::GetInstance()))->InsertTexture(pDevice, Type, pFileName, pObjectKey, pStateKey, iCnt, INSERType);
}
//�ؽ��� �ҷ�����.
extern  const TEXINFO*	GetTexture(const TCHAR* pObjectKey
	, const TCHAR* pStateKey
	, const int& iCnt/* = 0*/)
{
	return (*(CTextureMgr::GetInstance()))->GetTexture(pObjectKey, pStateKey, iCnt);
}
//Bounding �߰�
extern  HRESULT AddBounding(LPDIRECT3DDEVICE9 pDevice
	, BOUNDTYPE Type)
{
	return (*(CBoundingMgr::GetInstance()))->AddBounding(pDevice, Type);
}

extern  void Bound_Render(BOUNDTYPE Type)
{
	(*(CBoundingMgr::GetInstance()))->Bound_Render(Type);
}
//bounding ��谪�� �ּҰ�
extern  const D3DXVECTOR3* GetMin(BOUNDTYPE Type)
{
	return (*(CBoundingMgr::GetInstance()))->GetMin(Type);
}
//bounding ��谪�� �ִ� ��
extern  const D3DXVECTOR3* GetMax(BOUNDTYPE Type)
{
	return (*(CBoundingMgr::GetInstance()))->GetMax(Type);
}
//=============== Mesh =============== //
extern  HRESULT AddMesh(LPDIRECT3DDEVICE9 pDevice
	, const TCHAR* pPath
	, const TCHAR* pFileName
	, const TCHAR* pMeshKey
	, MESHTYPE Type)
{
	return (*(CMeshMgr::GetInstance()))->AddMesh(pDevice, pPath, pFileName, pMeshKey, Type);
}
//INSERT�Ǿ� �ִ� Mesh�� �����Ͽ� �����´�.
extern  HRESULT CloneMesh(LPDIRECT3DDEVICE9 pDevice
	, const TCHAR* pMeshKey
	, CAnimationCtrl** ppAniCtrl)
{
	return (*(CMeshMgr::GetInstance()))->CloneMesh(pDevice, pMeshKey, ppAniCtrl);
}
//�Ž� ������
extern  void Mesh_Render(LPDIRECT3DDEVICE9 pDevice
	, const TCHAR* pMeshKey)
{
	(*(CMeshMgr::GetInstance()))->Mesh_Render(pDevice, pMeshKey);
}
//�� matrix�� �����´�.
extern  void GetBoneMatrix(const TCHAR* pMeshKey
	, const CHAR* pBoneName
	, D3DXMATRIX* pOut)
{
	(*(CMeshMgr::GetInstance()))->GetBonMatrix(pMeshKey, pBoneName, pOut);
}

LPD3DXMESH GetMesh(const TCHAR * pMeshKey)
{
	return (*(CMeshMgr::GetInstance()))->GetMesh(pMeshKey);
}


extern  void Resource_Release(void)
{
	(*(CBufferMgr::GetInstance()))->DestroyInstance();
	(*(CTextureMgr::GetInstance()))->DestroyInstance();
	(*(CBoundingMgr::GetInstance()))->DestroyInstance();
	(*(CMeshMgr::GetInstance()))->DestroyInstance();
}


