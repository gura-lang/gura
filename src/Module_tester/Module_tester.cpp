//-----------------------------------------------------------------------------
// Gura tester module
//-----------------------------------------------------------------------------
#include "Module_tester.h"

Gura_BeginModule(tester)

//-----------------------------------------------------------------------------
// Thread1
//-----------------------------------------------------------------------------
class Thread1 : public OAL::Thread {
public:
	virtual void Run();
};

void Thread1::Run()
{
	::printf("Thread1\n");
	int i = 0;
	for ( ; ; i++) {
		::printf("Notify %d\n", i);
		OAL::Sleep(1);
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
	OAL::Thread *pThread1 = new Thread1();
	pThread1->Start();
	for (;;) {
		OAL::Sleep(3);
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
