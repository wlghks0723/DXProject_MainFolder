#pragma once
//��ũ���Լ�

//TEMPLATE�� ���ǵ� �̱��� ���Ǹ� ���� ��ũ���Լ�
#define DECLARE_SINGLETON(type)public:\
		static type** GetInstance()\
		{\
			static type* pInstance = new type;\
			if(pInstance == NULL)\
				pInstance = new type;\
			return &pInstance;\
		}\
		static void DestroyInstance(void)\
		{\
			type** ppInstance = GetInstance();\
			if(*ppInstance != NULL)\
			{\
				delete *ppInstance;\
				*ppInstance = NULL;\
			}\
		}
#define SAFE_DELETE(p) {if(p) delete p;}
#define GET_SINGLE(type) (*type::GetInstance())
#define ERR_MSG(hWnd, sz) MessageBox(hWnd, sz, L"system err", MB_OK);//������ ���� �޽����ڽ� ��� ��ũ��