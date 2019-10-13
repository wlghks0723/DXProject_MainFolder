#pragma once
class CTexture;
class CTextureMgr
{

	DECLARE_SINGLETON(CTextureMgr)
	
private:
	//1. ��ü������ ���� KEY
	//2. ��ü�� ���¿� ���� ���� KEY
	map<const TCHAR*, CTexture*> m_MapTexture;
public:
	HRESULT InsertTexture(LPDIRECT3DDEVICE9 pDevice
		, TEXTYPE Type
		, const TCHAR* pFileName
		, const TCHAR* pObjectKey
		, const TCHAR* pStateKey
		, const int& iCnt = 1,TERRIAN_INSERTTYPE = INSERTTYPE_NUMBER);
public:
	const TEXINFO* GetTexture(const TCHAR* pObjectKey
		, const TCHAR * pStateKey
		, const int& iCnt = 0);
public:
	void Release();
private:
	CTextureMgr();
public:
	~CTextureMgr();
};

