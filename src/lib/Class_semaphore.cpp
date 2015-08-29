//=============================================================================
// Gura class: semaphore
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_semaphore
//-----------------------------------------------------------------------------
Object_semaphore::Object_semaphore(Environment &env) : 
							Object(env.LookupClass(VTYPE_semaphore))
{
}

Object_semaphore::Object_semaphore(Class *pClass) : Object(pClass)
{
}

Object *Object_semaphore::Clone() const
{
	return nullptr;
}

String Object_semaphore::ToString(bool exprFlag)
{
	String str;
	str += "<semaphore:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// semaphore()
Gura_DeclareFunction(semaphore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(env.LookupClass(VTYPE_semaphore));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(semaphore)
{
	Object *pObj = new Object_semaphore(env);
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// semaphore#release()
Gura_DeclareMethod(semaphore, release)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Releases the owership of the semaphore that is grabbed by semaphore#wait().");
}

Gura_ImplementMethod(semaphore, release)
{
	Object_semaphore *pThis = Object_semaphore::GetObjectThis(arg);
	pThis->GetSemaphore().Release();
	return Value::Nil;
}

// semaphore#session()
Gura_DeclareMethod(semaphore, session)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Forms a critical session by grabbing the semaphore's ownership, executing\n"
		"the block and releasing that ownership. It internally proccesses the same\n"
		"job as semaphore#wait() and semaphore#release() before and after the block\n"
		"execution");
}

Gura_ImplementMethod(semaphore, session)
{
	Signal &sig = env.GetSignal();
	Object_semaphore *pThis = Object_semaphore::GetObjectThis(arg);
	const Function *pFuncBlock =
						arg.GetBlockFunc(env, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Nil;
	pThis->GetSemaphore().Wait();
	AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
	AutoPtr<Argument> pArgSub(new Argument(pFuncBlock));
	Value result = pFuncBlock->Eval(*pEnvBlock, *pArgSub);
	pThis->GetSemaphore().Release();
	return result;
}

// semaphore#wait()
Gura_DeclareMethod(semaphore, wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Watis for the semaphore being released by other threads, and ghen grabs\n"
		"that ownership.");
}

Gura_ImplementMethod(semaphore, wait)
{
	Object_semaphore *pThis = Object_semaphore::GetObjectThis(arg);
	pThis->GetSemaphore().Wait();
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_semaphore::Class_semaphore(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_semaphore)
{
}

void Class_semaphore::Prepare(Environment &env)
{
	Gura_AssignFunction(semaphore);
	Gura_AssignMethod(semaphore, release);
	Gura_AssignMethod(semaphore, session);
	Gura_AssignMethod(semaphore, wait);
}

Object *Class_semaphore::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
