//----------------------------------------------------------------------------
// wxActiveXEvent
// extracted from activexevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ActiveXEvent: public wxActiveXEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ActiveXEvent *_pObj;
public:
	~wx_ActiveXEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ActiveXEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ActiveXEvent::~wx_ActiveXEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ActiveXEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ActiveXEvent, ParamCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ActiveXEvent, ParamCount)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->ParamCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ActiveXEvent, ParamType)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ActiveXEvent, ParamType)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t idx = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->ParamType(idx);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ActiveXEvent, ParamName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ActiveXEvent, ParamName)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t idx = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->ParamName(idx);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ActiveXEvent, GetDispatchId)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ActiveXEvent, GetDispatchId)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int idx = args.GetInt(0);
}

//----------------------------------------------------------------------------
// Object implementation for wxActiveXEvent
//----------------------------------------------------------------------------
Object_wx_ActiveXEvent::~Object_wx_ActiveXEvent()
{
}

Object *Object_wx_ActiveXEvent::Clone() const
{
	return NULL;
}

String Object_wx_ActiveXEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ActiveXEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ActiveXEvent::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxActiveXEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXEvent)
{
	Gura_AssignMethod(wx_ActiveXEvent, ParamCount);
	Gura_AssignMethod(wx_ActiveXEvent, ParamType);
	Gura_AssignMethod(wx_ActiveXEvent, ParamName);
	Gura_AssignMethod(wx_ActiveXEvent, GetDispatchId);
}

Gura_ImplementDescendantCreator(wx_ActiveXEvent)
{
	return new Object_wx_ActiveXEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
