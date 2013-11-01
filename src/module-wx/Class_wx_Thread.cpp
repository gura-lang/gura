//----------------------------------------------------------------------------
// wxThread
// extracted from thread.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Entry);
Gura_DeclarePrivUserSymbol(TestDestroy);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Thread: public wxThread, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Thread *_pObj;
public:
	//inline wx_Thread(wxThreadKind kind) : wxThread(kind), _sig(NULL), _pObj(NULL) {}
	virtual ExitCode Entry();
	virtual bool TestDestroy();
	~wx_Thread();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Thread *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Thread::~wx_Thread()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Thread::GuraObjectDeleted()
{
	_pObj = NULL;
}

wxThread::ExitCode wx_Thread::Entry()
{
	return 0;
}

bool wx_Thread::TestDestroy()
{
	return true;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxThread
//----------------------------------------------------------------------------
Gura_DeclareFunction(Thread)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Thread));
	DeclareArg(env, "kind", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Thread)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxThreadKind kind = wxTHREAD_DETACHED;
	if (args.IsValid(0)) kind = static_cast<wxThreadKind>(args.GetInt(0));
	wx_Thread *pEntity = new wx_Thread(kind);
	Object_wx_Thread *pObj = Object_wx_Thread::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Thread(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Thread, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stackSize", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Create)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned stackSize = 0;
	if (args.IsValid(0)) stackSize = args.GetInt(0);
	wxThreadError rtn = pThis->GetEntity()->Create(stackSize);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, Delete)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Delete)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThreadError rtn = pThis->GetEntity()->Delete();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, Entry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Entry)
{
#if 0
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThread::ExitCode rtn = pThis->GetEntity()->wxThread::Entry();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Thread, Exit)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "exitcode", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_Thread, Exit)
{
#if 0
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThread::ExitCode exitcode = 0;
	if (args.IsValid(0)) exitcode = static_cast<wxThread::ExitCode>(args.GetInt(0));
	pThis->GetEntity()->Exit(exitcode);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Thread, GetCPUCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Thread, GetCPUCount)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxThread::GetCPUCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Thread, GetCurrentId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Thread, GetCurrentId)
{
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned rtn = wxThread::GetCurrentId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, GetId)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, GetPriority)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, GetPriority)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPriority();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, IsAlive)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, IsAlive)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsAlive();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, IsDetached)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, IsDetached)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDetached();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Thread, IsMain)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Thread, IsMain)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxThread::IsMain();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, IsPaused)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, IsPaused)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPaused();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, IsRunning)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, IsRunning)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsRunning();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, Kill)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Kill)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThreadError rtn = pThis->GetEntity()->Kill();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, OnExit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, OnExit)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnExit();
	return Value::Null;
}

Gura_DeclareMethod(wx_Thread, Pause)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Pause)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThreadError rtn = pThis->GetEntity()->Pause();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, Run)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Run)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThreadError rtn = pThis->GetEntity()->Run();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, SetPriority)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "priority", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, SetPriority)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int priority = args.GetInt(0);
	pThis->GetEntity()->SetPriority(priority);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Thread, Sleep)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Thread, Sleep)
{
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned milliseconds = args.GetInt(0);
	wxThread::Sleep(milliseconds);
	return Value::Null;
}

Gura_DeclareMethod(wx_Thread, Resume)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Resume)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThreadError rtn = pThis->GetEntity()->Resume();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Thread, SetConcurrency)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Thread, SetConcurrency)
{
	if (!CheckWxReady(sig)) return Value::Null;
	size_t level = args.GetSizeT(0);
	bool rtn = wxThread::SetConcurrency(level);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Thread, TestDestroy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, TestDestroy)
{
#if defined(__WXMSW__)
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxThread::TestDestroy();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif
}

Gura_DeclareClassMethod(wx_Thread, This)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Thread, This)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxThread *rtn = (wxThread *)wxThread::This();
	return ReturnValue(env, sig, args, Value(new Object_wx_Thread(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Thread, Yield)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Yield)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Yield();
	return Value::Null;
}

Gura_DeclareMethod(wx_Thread, Wait)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Thread, Wait)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxThread::ExitCode rtn = pThis->GetEntity()->Wait();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxThread
//----------------------------------------------------------------------------
Object_wx_Thread::~Object_wx_Thread()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Thread::Clone() const
{
	return NULL;
}

String Object_wx_Thread::ToString(bool exprFlag)
{
	String rtn("<wx.Thread:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxThread
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Thread)
{
	Gura_RealizeUserSymbol(Entry);
	Gura_RealizeUserSymbol(TestDestroy);
	Gura_AssignFunction(Thread);
	Gura_AssignMethod(wx_Thread, Create);
	Gura_AssignMethod(wx_Thread, Delete);
	Gura_AssignMethod(wx_Thread, Entry);
	Gura_AssignMethod(wx_Thread, Exit);
	Gura_AssignMethod(wx_Thread, GetCPUCount);
	Gura_AssignMethod(wx_Thread, GetCurrentId);
	Gura_AssignMethod(wx_Thread, GetId);
	Gura_AssignMethod(wx_Thread, GetPriority);
	Gura_AssignMethod(wx_Thread, IsAlive);
	Gura_AssignMethod(wx_Thread, IsDetached);
	Gura_AssignMethod(wx_Thread, IsMain);
	Gura_AssignMethod(wx_Thread, IsPaused);
	Gura_AssignMethod(wx_Thread, IsRunning);
	Gura_AssignMethod(wx_Thread, Kill);
	Gura_AssignMethod(wx_Thread, OnExit);
	Gura_AssignMethod(wx_Thread, Pause);
	Gura_AssignMethod(wx_Thread, Run);
	Gura_AssignMethod(wx_Thread, SetPriority);
	Gura_AssignMethod(wx_Thread, Sleep);
	Gura_AssignMethod(wx_Thread, Resume);
	Gura_AssignMethod(wx_Thread, SetConcurrency);
	Gura_AssignMethod(wx_Thread, TestDestroy);
	Gura_AssignMethod(wx_Thread, This);
	Gura_AssignMethod(wx_Thread, Yield);
	Gura_AssignMethod(wx_Thread, Wait);
}

Gura_ImplementDescendantCreator(wx_Thread)
{
	return new Object_wx_Thread((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
