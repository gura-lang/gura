//----------------------------------------------------------------------------
// wxProcessEvent
// extracted from procevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ProcessEvent: public wxProcessEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ProcessEvent *_pObj;
public:
	inline wx_ProcessEvent(int id, int pid, int exitcode) : wxProcessEvent(id, pid, exitcode), _sig(NULL), _pObj(NULL) {}
	~wx_ProcessEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ProcessEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ProcessEvent::~wx_ProcessEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ProcessEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxProcessEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ProcessEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ProcessEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pid", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "exitcode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ProcessEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	int pid = 0;
	if (args.IsValid(1)) pid = args.GetInt(1);
	int exitcode = 0;
	if (args.IsValid(2)) exitcode = args.GetInt(2);
	wx_ProcessEvent *pEntity = new wx_ProcessEvent(id, pid, exitcode);
	Object_wx_ProcessEvent *pObj = Object_wx_ProcessEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ProcessEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ProcessEvent, GetPid)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProcessEvent, GetPid)
{
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPid();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ProcessEvent, GetExitCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProcessEvent, GetExitCode)
{
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetExitCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxProcessEvent
//----------------------------------------------------------------------------
Object_wx_ProcessEvent::~Object_wx_ProcessEvent()
{
}

Object *Object_wx_ProcessEvent::Clone() const
{
	return NULL;
}

String Object_wx_ProcessEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ProcessEvent:");
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
// Class implementation for wxProcessEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProcessEvent)
{
	Gura_AssignFunction(ProcessEvent);
	Gura_AssignMethod(wx_ProcessEvent, GetPid);
	Gura_AssignMethod(wx_ProcessEvent, GetExitCode);
}

Gura_ImplementDescendantCreator(wx_ProcessEvent)
{
	return new Object_wx_ProcessEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
