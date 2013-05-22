//
// Object_semaphore
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_semaphore
//-----------------------------------------------------------------------------
Object_semaphore::~Object_semaphore()
{
}

Object *Object_semaphore::Clone() const
{
	return new Object_semaphore(*this);
}

String Object_semaphore::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<semaphore:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// semaphore()
Gura_DeclareFunction(semaphore)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(env.LookupClass(VTYPE_semaphore));
}

Gura_ImplementFunction(semaphore)
{
	Object *pObj = new Object_semaphore(env);
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_semaphore
//-----------------------------------------------------------------------------
// semaphore#wait()
Gura_DeclareMethod(semaphore, wait)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), 
	"Watis for the semaphore being released by other threads, and ghen grabs\n"
	"that ownership.");
}

Gura_ImplementMethod(semaphore, wait)
{
	Object_semaphore *pThis = Object_semaphore::GetThisObj(args);
	pThis->GetSemaphore().Wait();
	return Value::Null;
}

// semaphore#release()
Gura_DeclareMethod(semaphore, release)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), "Releases the owership of the semaphore that is grabbed by semaphore#wait().");
}

Gura_ImplementMethod(semaphore, release)
{
	Object_semaphore *pThis = Object_semaphore::GetThisObj(args);
	pThis->GetSemaphore().Release();
	return Value::Null;
}

// semaphore#session()
Gura_DeclareMethod(semaphore, session)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(Gura_Symbol(en), 
	"Forms a critical session by grabbing the semaphore's ownership, executing\n"
	"the block and releasing that ownership. It internally proccesses the same\n"
	"job as semaphore#wait() and semaphore#release() before and after the block\n"
	"execution");
}

Gura_ImplementMethod(semaphore, session)
{
	Object_semaphore *pThis = Object_semaphore::GetThisObj(args);
	const Function *pFuncBlock =
						args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Null;
	pThis->GetSemaphore().Wait();
	Environment envBlock(&env, ENVTYPE_block);
	Args argsSub(ValueList::Null);
	Value result = pFuncBlock->Eval(envBlock, sig, argsSub);
	pThis->GetSemaphore().Release();
	return result;
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_semaphore::Class_semaphore(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_semaphore)
{
	Gura_AssignMethod(semaphore, wait);
	Gura_AssignMethod(semaphore, release);
	Gura_AssignMethod(semaphore, session);
}

Object *Class_semaphore::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_semaphore::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(semaphore);
}

}
