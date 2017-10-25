// ������ڴ���̼�ͨ��
#pragma once
#include <windows.h>
#include <mutex>


typedef std::function<void(int , char* buf)> MemResponse;

class  CShareMemBase
{
public:
	CShareMemBase();
	~CShareMemBase();
	
protected:
	virtual void Init() = 0;

	std::mutex m_MemLock;

	HANDLE m_hSignal;
	HANDLE m_hMemory;
	char* m_pMemory;

	std::string m_strUUID;
	std::string m_strSinalName;
	std::string m_strMemoryName;

	enum{
		memory_size = 256
	};
};


//�����ڴ��ȡ
class CReadShareMem : public CShareMemBase
{
public:
	CReadShareMem(const std::string & memName, const std::string & signalName);
	~CReadShareMem();

	//ע��ص�����������ʱ��֪ͨ�ص�
	void RegisterCallBack(const MemResponse & fun){ this->m_pFun = fun; }
	//������ȡ�߳�
	void Run();
private:
	static DWORD WINAPI ThreadProc(LPVOID lParam);
	void BreakLoop();
	void Init();
	void Read();
	void Loop();

	bool CheckCloseFlag();
	MemResponse m_pFun;
	bool m_bRunLoop;
};


class CWriteShareMem : public CShareMemBase
{
public:
	CWriteShareMem();
	CWriteShareMem(const std::string & memName, const std::string & signalName);
	~CWriteShareMem();
	//�����ڴ�д����
	int Write(const int size, const char* const pBuf);
	//֪ͨ������������
	int Signal();

	std::string GetSignalName() const{ return m_strSinalName; }
	std::string GetMemoryName() const { return m_strMemoryName; }
	
private:
	void Init();
	virtual void MakeUUID();
};


