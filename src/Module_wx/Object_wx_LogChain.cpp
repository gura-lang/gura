//----------------------------------------------------------------------------
// wxLogChain
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogChain: public wxLogChain, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogChain *_pObj;
public:
	inline wx_LogChain(wxLog * logger) : wxLogChain(logger), _sig(NULL), _pObj(NULL) {}
	~wx_LogChain();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogChain *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogChain::~wx_LogChain()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LogChain::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogChain
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogChain)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogChain));
	DeclareArg(env, "logger", VTYPE_wx_Log, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogChain)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog *logger = Object_wx_Log::GetObject(args, 0)->GetEntity();
	wx_LogChain *pEntity = new wx_LogChain(logger);
	Object_wx_LogChain *pObj = Object_wx_LogChain::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LogChain(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_LogChain, DetachOldLog)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, DetachOldLog)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DetachOldLog();
	return Value::Null;
}

Gura_DeclareMethod(wx_LogChain, GetOldLog)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogChain, GetOldLog)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLog *rtn = (wxLog *)pThis->GetEntity()->GetOldLog();
	return ReturnValue(env, sig, args, Value(new Object_wx_Log(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_LogChain, IsPassingMessages)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogChain, IsPassingMessages)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPassingMessages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_LogChain, PassMessages)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "passMessages", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, PassMessages)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool passMessages = args.GetBoolean(0);
	pThis->GetEntity()->PassMessages(passMessages);
	return Value::Null;
}

Gura_DeclareMethod(wx_LogChain, SetLog)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "logger", VTYPE_wx_Log, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, SetLog)
{
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLog *logger = Object_wx_Log::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLog(logger);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxLogChain
//----------------------------------------------------------------------------
Object_wx_LogChain::~Object_wx_LogChain()
{
}

Object *Object_wx_LogChain::Clone() const
{
	return NULL;
}

String Object_wx_LogChain::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LogChain:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LogChain::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(LogChain);
}

//----------------------------------------------------------------------------
// Class implementation for wxLogChain
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogChain)
{
	Gura_AssignMethod(wx_LogChain, DetachOldLog);
	Gura_AssignMethod(wx_LogChain, GetOldLog);
	Gura_AssignMethod(wx_LogChain, IsPassingMessages);
	Gura_AssignMethod(wx_LogChain, PassMessages);
	Gura_AssignMethod(wx_LogChain, SetLog);
}

Gura_ImplementDescendantCreator(wx_LogChain)
{
	return new Object_wx_LogChain((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
