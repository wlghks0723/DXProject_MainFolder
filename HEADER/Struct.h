
#pragma once
typedef struct ST_PC_VERTEX
{
	D3DXVECTOR3 p;
	D3DCOLOR c;
	enum {FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE};
}CUSTOMVERTEX;


typedef struct tagBoneMesh : public D3DXMESHCONTAINER
{
	// �����̱� ������ �޽� ����.
	LPD3DXMESH					pOriMesh;
	
	std::vector<D3DMATERIAL9>		vecMtrl;
	std::vector<LPDIRECT3DTEXTURE9>	vecTexture;

	// ������ ����
	DWORD						dwAttCnt;

	// ����µ��� �迭���·� ��Ƶα����� ������
	D3DXATTRIBUTERANGE*			pAttTable;

	// �޽��� ������ ��ġ�� ������ ���յ� ����� ����Ű�� ������.
	D3DXMATRIX**				ppBoneMatrix;

	// �޽��� ������ ��ġ�� �������� ��ĵ� �� ���� �� ����� �ּ�
	D3DXMATRIX*					pBoneoffSetMatrix;

	// �޽��� ������ �ؾ��� �������.
	D3DXMATRIX*					pCurrentBoneMatrix;
}BONEMESH;

typedef struct tagBone : public _D3DXFRAME
{
	D3DXMATRIX			matWorld;
}BONE;



// �ؽ����� ����
typedef struct  tagTextureInfo
{
	D3DXIMAGE_INFO	TexInfo;

	union
	{
		LPDIRECT3DTEXTURE9				pTexture;
		LPDIRECT3DCUBETEXTURE9			pCubeTexture;
	};
}TEXINFO;

// �ﰢ���ϳ��� �׸��� ���� ���ؽ��� �ε�������
typedef struct tagIndex
{
	DWORD			_1, _2, _3;
}INDEX;

typedef struct tagCubeVtxTex
{
	D3DXVECTOR3		vPosition;
	D3DXVECTOR3		vTexture;
}CUBEVTXTEX;

const DWORD VTXFVF_CUBETEX = D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE3(0);

typedef struct tagVertexTexture
{
	D3DXVECTOR3		vPosition;

	D3DXVECTOR3		vNormal;

	// ���� ���ؽ��� �����ؾ��� �ؽ��� ���� ������ǥ
	D3DXVECTOR2		vTexture;
}VTXTEX;

const DWORD	VTXFVF_VTXTEX = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;


typedef struct tagVertexColor
{
	D3DXVECTOR3		vPosition;
	DWORD			dwDiffuse;
}VTXCOL;

const DWORD	VTXFVF_VTXCOL = D3DFVF_XYZ | D3DFVF_DIFFUSE;




typedef struct tagInfo
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vLook;
	D3DXVECTOR3		vDir;
	D3DXMATRIX		matWorld;
}INFO;


typedef struct tagRay
{
	D3DXVECTOR3 origin;
	D3DXVECTOR3 direction;
	tagRay(float x = 0.f, float y = 0.f, float z = 0.f)
		: origin(0, 0, 0), direction(x, y, z) {}
	tagRay(const D3DXVECTOR3& dir) : origin(0, 0, 0), direction(dir) {}
	tagRay(const tagRay& ray) : origin(ray.origin), direction(ray.direction) {}
}RAY;

typedef struct tagSphere
{
	float		fRadius;
	D3DXVECTOR3 vCenter;
	bool		isPicked = false;

	tagSphere() : fRadius(0.0f), vCenter(0, 0, 0) {}
	tagSphere(const float r, const D3DXVECTOR3 v) : fRadius(r), vCenter(v.x,v.y,v.z) {}
	tagSphere(const tagSphere& sph) 
		: fRadius(sph.fRadius), vCenter(sph.vCenter.x, sph.vCenter.y, sph.vCenter.z) {}
}SPHERE;