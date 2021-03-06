//----------------------------------------------------------------------------
// wxLogChain
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogChain: public wxLogChain, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LogChain *_pObj;
public:
	inline wx_LogChain(wxLog * logger) : wxLogChain(logger), _pObj(nullptr) {}
	~wx_LogChain();
	inline void AssocWithGura(Object_wx_LogChain *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogChain::~wx_LogChain()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LogChain::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogChain
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogChain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_LogChain));
	DeclareArg(env, "logger", VTYPE_wx_Log, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LogChain)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxLog *logger = Object_wx_Log::GetObject(arg, 0)->GetEntity();
	wx_LogChain *pEntity = new wx_LogChain(logger);
	Object_wx_LogChain *pObj = Object_wx_LogChain::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_LogChain(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_LogChain, DetachOldLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogChain, DetachOldLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DetachOldLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, GetOldLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogChain, GetOldLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLog *rtn = (wxLog *)pThis->GetEntity()->GetOldLog();
	return ReturnValue(env, arg, Value(new Object_wx_Log(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_LogChain, IsPassingMessages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogChain, IsPassingMessages)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsPassingMessages();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_LogChain, PassMessages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "passMessages", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, PassMessages)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool passMessages = arg.GetBoolean(0);
	pThis->GetEntity()->PassMessages(passMessages);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogChain, SetLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "logger", VTYPE_wx_Log, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogChain, SetLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogChain *pThis = Object_wx_LogChain::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLog *logger = Object_wx_Log::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetLog(logger);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxLogChain
//----------------------------------------------------------------------------
Object_wx_LogChain::~Object_wx_LogChain()
{
}

Object *Object_wx_LogChain::Clone() const
{
	return nullptr;
}

String Object_wx_LogChain::ToString(bool exprFlag)
{
	String rtn("<wx.LogChain:");
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
// Class implementation for wxLogChain
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogChain)
{
	Gura_AssignFunction(LogChain);
	Gura_AssignMethod(wx_LogChain, DetachOldLog);
	Gura_AssignMethod(wx_LogChain, GetOldLog);
	Gura_AssignMethod(wx_LogChain, IsPassingMessages);
	Gura_AssignMethod(wx_LogChain, PassMessages);
	Gura_AssignMethod(wx_LogChain, SetLog);
}

Gura_ImplementDescendantCreator(wx_LogChain)
{
	return new Object_wx_LogChain((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
