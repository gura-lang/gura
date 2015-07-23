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
	//Gura::Signal *_pSig;
	Object_wx_ProcessEvent *_pObj;
public:
	inline wx_ProcessEvent(int id, int pid, int exitcode) : wxProcessEvent(id, pid, exitcode), _pObj(nullptr) {}
	~wx_ProcessEvent();
	inline void AssocWithGura(Object_wx_ProcessEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ProcessEvent::~wx_ProcessEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ProcessEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxProcessEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ProcessEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == nullptr) {
		pObj = new Object_wx_ProcessEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ProcessEvent, GetPid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProcessEvent, GetPid)
{
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPid();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ProcessEvent, GetExitCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProcessEvent, GetExitCode)
{
	Object_wx_ProcessEvent *pThis = Object_wx_ProcessEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetExitCode();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxProcessEvent
//----------------------------------------------------------------------------
Object_wx_ProcessEvent::~Object_wx_ProcessEvent()
{
}

Object *Object_wx_ProcessEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ProcessEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ProcessEvent:");
	if (GetEntity() == nullptr) {
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
	return new Object_wx_ProcessEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
