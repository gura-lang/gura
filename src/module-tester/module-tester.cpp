//-----------------------------------------------------------------------------
// Gura module: tester
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(tester)

//-----------------------------------------------------------------------------
// Thread1
//-----------------------------------------------------------------------------
class Thread1 : public OAL::Thread {
private:
	Signal &_sig;
	AutoPtr<StreamFIFO> _pStreamFIFO;
public:
	inline Thread1(Signal &sig, StreamFIFO *pStreamFIFO) :
								_sig(sig), _pStreamFIFO(pStreamFIFO) {}
	virtual void Run();
};

void Thread1::Run()
{
	UChar buff[1024];
	::printf("Thread1 starts\n");
	int num = 0;
	for (;;) {
		size_t bytesToRead = 1024;
		//size_t bytesToRead = static_cast<int>(RandomGenerator::Real2() * 1024) + 1;
		size_t bytesRead = _pStreamFIFO->Read(_sig, buff, bytesToRead);
		//::printf("Read(%d) .. %d bytes read\n", bytesToRead, bytesRead);
		for (size_t i = 0; i < bytesRead; i++, num++) {
			//::printf(" %02x", buff[i]);
			if (buff[i] != (num & 0xff)) {
				::printf("error\n");
			}
		}
		//::printf("\n");
	}
}

//-----------------------------------------------------------------------------
// Gura module functions: tester
//-----------------------------------------------------------------------------
// tester.test_thread()
Gura_DeclareFunction(test_thread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "run tester.");
}

Gura_ImplementFunction(test_thread)
{
	Signal &sig = env.GetSignal();
	Random::Initialize(0);
	UChar buff[1024];
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, 256));
	OAL::Thread *pThread1 = new Thread1(sig,
			dynamic_cast<StreamFIFO *>(Stream::Reference(pStreamFIFO.get())));
	pThread1->Start();
	int num = 0;
	int cntRound = 0;
	for (;;) {
		size_t bytesToWrite = static_cast<int>(Random::Real2() * 1024) + 1;
		for (size_t i = 0; i < bytesToWrite; i++, num++) {
			buff[i] = static_cast<UChar>(num);
		}
		size_t bytesWritten = pStreamFIFO->Write(sig, buff, bytesToWrite);
		//::printf("Write(%d) .. %d bytes written\n", bytesToWrite, bytesWritten);
		pStreamFIFO->SetWriteDoneFlag();
		cntRound++;
		if (cntRound > 10000) {
			::printf("offsetWrite:%-5ld offsetRead:%-5ld bytesAvail:%-5ld\n",
								pStreamFIFO->GetOffsetWrite(),
								pStreamFIFO->GetOffsetRead(),
								pStreamFIFO->GetBytesAvail());
			cntRound = 0;
		}
	}
	return Value::Nil;
}

// tester.test_allocator()
Gura_DeclareFunction(test_allocator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "run tester.");
}

typedef std::vector<Value, Allocator<Value> > ValueList2;

Gura_ImplementFunction(test_allocator)
{
	ValueList2 valList;
	//valList.reserve(100);
	for (int i = 0; i < 1000; i++) {
		valList.push_back(Value::Nil);
	}
#if 0
#if 0
	for (int i = 0; i < 1000000; i++) {
		void *p = MemoryPool::Allocate(100);
		::printf("%8d %p\n", i, p);
	}
#endif
	MemoryPool::Print();
	::printf("----\n");
	void *p1 = MemoryPool::Allocate(100);
	void *p2 = MemoryPool::Allocate(100);
	MemoryPool::Print();
	::printf("----\n");
	MemoryPool::Deallocate(p1);
	MemoryPool::Print();
	::printf("----\n");
	MemoryPool::Deallocate(p2);
	MemoryPool::Print();
	::printf("----\n");
	p1 = MemoryPool::Allocate(100);
	MemoryPool::Print();
	::printf("----\n");
	p2 = MemoryPool::Allocate(100);
	MemoryPool::Print();
	::printf("----\n");
	void *p3 = MemoryPool::Allocate(100);
	MemoryPool::Print();
#endif
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	Gura_AssignFunction(test_thread);
	Gura_AssignFunction(test_allocator);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(tester, tester)

Gura_RegisterModule(tester)
