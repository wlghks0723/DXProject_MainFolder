#pragma once
class CTexture
{
public:
	CTexture();
	virtual ~CTexture();
protected:
	map<const TCHAR*, vector<TEXINFO*>> m_MapTexture;
public:


	//Ű������ �ؽ�Ʈ�� �����������´�.
	const TEXINFO* GetTexture(const TCHAR* pStateKey, const int& iCnt = 0);
	//����̽� ,�ؽ��� ���,Ű��
	virtual HRESULT InsertTexture(LPDIRECT3DDEVICE9 pDevice, 
		const TCHAR* pFileName
		, const TCHAR*pStateKey
		, const int&iCnt = 1,TERRIAN_INSERTTYPE = INSERTTYPE_NUMBER) PURE;
public:
	virtual void Release();


};

