//-----------------------------------------------------------------------------
// Gura tester module
//-----------------------------------------------------------------------------
#include "Module_tester.h"

Gura_BeginModule(tester)

//-----------------------------------------------------------------------------
// Thread1
//-----------------------------------------------------------------------------
class Thread1 : public OAL::Thread {
private:
	Signal _sig;
	AutoPtr<StreamFIFO> _pStreamFIFO;
public:
	inline Thread1(Signal sig, StreamFIFO *pStreamFIFO) :
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
// tester.run()
Gura_DeclareFunction(run)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), "run tester.");
}

Gura_ImplementFunction(run)
{
	RandomGenerator::Initialize(0);
	UChar buff[1024];
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, sig, 256));
	OAL::Thread *pThread1 = new Thread1(sig,
			dynamic_cast<StreamFIFO *>(Stream::Reference(pStreamFIFO.get())));
	pThread1->Start();
	int num = 0;
	int cntRound = 0;
	for (;;) {
		size_t bytesToWrite = static_cast<int>(RandomGenerator::Real2() * 1024) + 1;
		for (size_t i = 0; i < bytesToWrite; i++, num++) {
			buff[i] = static_cast<UChar>(num);
		}
		size_t bytesWritten = pStreamFIFO->Write(sig, buff, bytesToWrite);
		//::printf("Write(%d) .. %d bytes written\n", bytesToWrite, bytesWritten);
		pStreamFIFO->SetWriteDoneFlag();
		cntRound++;
		if (cntRound > 10000) {
			::printf("offsetWrite:%-5d offsetRead:%-5d bytesAvail:%-5d\n",
								pStreamFIFO->GetOffsetWrite(),
								pStreamFIFO->GetOffsetRead(),
								pStreamFIFO->GetBytesAvail());
			cntRound = 0;
		}
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(run);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(tester, tester)

Gura_RegisterModule(tester)
