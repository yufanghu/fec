#include <mutex>
#include "ShareMemory.h"

CShareMemBase::CShareMemBase() : m_hSignal(NULL), m_hMemory(NULL), m_pMemory(NULL)
{

}

CShareMemBase::~CShareMemBase()
{

}



/********************CReadShareMemBegin********************/
CReadShareMem::CReadShareMem(const std::string & memName, const std::string & signalName) : m_bRunLoop(true)
{
	m_strMemoryName = memName;
	m_strSinalName = signalName;
	
}

CReadShareMem::~CReadShareMem()
{
	BreakLoop();
}

void CReadShareMem::Loop()
{
	while (m_bRunLoop)
	{
		WaitForSingleObject(m_hSignal, INFINITE);
		ResetEvent(m_hSignal);
		Read();

		if (!m_bRunLoop){
			/*::MessageBox(NULL, L"close loop"), NULL, MB_OK);*/
			return;
		}
			
	}
}

DWORD WINAPI CReadShareMem::ThreadProc(LPVOID lParam)
{
	CReadShareMem* p = (CReadShareMem*)lParam;

	p->Loop();
	return 0;
}

void CReadShareMem::Init()
{
	m_hMemory = ::OpenFileMappingA(FILE_MAP_ALL_ACCESS, 0, m_strMemoryName.c_str());
	m_hSignal = ::OpenEventA(EVENT_ALL_ACCESS, FALSE, m_strSinalName.c_str());
	if (m_hSignal && m_hMemory)
	{
		CreateThread(NULL, 0, CReadShareMem::ThreadProc, this, 0, 0);
	}	
}


void CReadShareMem::Read()
{
	if (m_hMemory)
	{
		char* pBuffer = (char*)::MapViewOfFile(m_hMemory, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		int size = *(int*)pBuffer;
		char* data = pBuffer + 4;
		if (1 == size && data[0] == 'c'){
			m_bRunLoop = false;
		}
		else{
			if (m_pFun){
				m_pFun(size, pBuffer + 4);
			}
		}
	}
}

void CReadShareMem::Run()
{
	Init();
}

void CReadShareMem::BreakLoop(){
	m_bRunLoop = false;
	SetEvent(m_hSignal);
}
/********************CReadShareMemEnd********************/


/********************CWriteShareMemBegin********************/
CWriteShareMem::CWriteShareMem()
{
	MakeUUID();
	Init();
}

CWriteShareMem::CWriteShareMem(const std::string & memName, const std::string & signalName)
{
	m_strSinalName = "trade_client_signal";
	m_strMemoryName = "trade_client_memname";
	Init();
}

int CWriteShareMem::Write(const int size, const char* const pBuf){
	std::lock_guard<std::mutex> lock(m_MemLock);
	if (!pBuf || size <= 0 || !m_pMemory)
		return 0;
	memset(m_pMemory, 0, memory_size);
	//4 byte head
	memcpy(m_pMemory, (void*)&size, sizeof(int));
	//copy data
	int dataLen = min(size, memory_size - 4);
	memcpy(m_pMemory + sizeof(int), pBuf, dataLen);
	return dataLen;
}

int CWriteShareMem::Signal(){
	SetEvent(m_hSignal);
	return 0;
}

void CWriteShareMem::Init()
{
	m_hMemory = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, memory_size, m_strMemoryName.c_str());
	if (!m_hMemory)
	{
		return;
	}
	m_pMemory = (char*)::MapViewOfFile(m_hMemory, FILE_MAP_WRITE, 0, 0, 0);
	if (!m_pMemory)
	{
		CloseHandle(m_hMemory);
	}
	//m_hSignal = CreateSemaphoreA(NULL, 0, 1, m_strSinalName.c_str());
	m_hSignal = CreateEventA(NULL, false, false, m_strSinalName.c_str());
	if (!m_hSignal)
	{
		CloseHandle(m_hMemory);
		::UnmapViewOfFile(m_pMemory);
	}
}

void CWriteShareMem::MakeUUID()
{
	time_t t;
	time(&t);
	char buf[64];
	memset(buf, 0, sizeof(buf));
	sprintf_s(buf, sizeof(buf), "%I64d", t);
	m_strUUID = buf;

	m_strSinalName = m_strUUID + "_signal";
	m_strMemoryName = m_strUUID + "_memory";
}

CWriteShareMem::~CWriteShareMem()
{
	char buf = 'c';
	Write(1, &buf);
	SetEvent(m_hSignal);

	//if (m_hMemory)
	//	CloseHandle(m_hMemory);
	//if (m_hSignal)
	//	CloseHandle(m_hSignal);
	
	//if (m_pMemory)
	//	::UnmapViewOfFile(m_pMemory);
}

/********************CWriteShareMemEnd********************/


