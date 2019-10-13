#include "BaseInclude.h"
#include "VIBuffer.h"


CVIBuffer::CVIBuffer()
{
}


CVIBuffer::~CVIBuffer()
{
	Release();
}

HRESULT CVIBuffer::CreateVertexIndexBuffer(LPDIRECT3DDEVICE9 pDevice, const int & iVtCntX, const int & iVtxCntZ, const float & fGap)
{

	if (FAILED(pDevice->CreateVertexBuffer(m_iVtxCnt * m_iVtxSize, 0
		, m_dwVtxFVF, D3DPOOL_MANAGED, &m_pVB, NULL)))
	{
		ERR_MSG(g_hWnd,L"VertexBuffer Create Failed");
		return E_FAIL;
	}

	if (FAILED(pDevice->CreateIndexBuffer(m_iIdxSize * m_dwTriCnt, 0
		, m_IdxFmt, D3DPOOL_MANAGED, &m_pIB, NULL)))
	{
		ERR_MSG(g_hWnd,L"IndexBuffer Create Failed");
		return E_FAIL;
	}

	return S_OK;
}

void CVIBuffer::Buffer_Render(LPDIRECT3DDEVICE9 pDevice)
{
	// � ���ؽ����۸� �̿��ؼ� �������� ���̳�
	pDevice->SetStreamSource(0, m_pVB, 0, m_iVtxSize);

	// �� ���ؽ� ���ۿ��� � ���ؽ����� ����ִ���
	pDevice->SetFVF(m_dwVtxFVF);

	// ������ ������� �׷����� ���̳�
	pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, m_dwTriCnt);
}

void CVIBuffer::Release()
{
	m_pVB->Release();
	m_pIB->Release();
}
