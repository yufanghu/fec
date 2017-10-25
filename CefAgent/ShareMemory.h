// 单项共享内存进程间通信
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


//共享内存读取
class CReadShareMem : public CShareMemBase
{
public:
	CReadShareMem(const std::string & memName, const std::string & signalName);
	~CReadShareMem();

	//注册回调函数有数据时候通知回调
	void RegisterCallBack(const MemResponse & fun){ this->m_pFun = fun; }
	//启动读取线程
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
	//向共享内存写数据
	int Write(const int size, const char* const pBuf);
	//通知接收者有数据
	int Signal();

	std::string GetSignalName() const{ return m_strSinalName; }
	std::string GetMemoryName() const { return m_strMemoryName; }
	
private:
	void Init();
	virtual void MakeUUID();
};


