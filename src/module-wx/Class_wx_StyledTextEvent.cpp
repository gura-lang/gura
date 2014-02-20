//----------------------------------------------------------------------------
// wxStyledTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StyledTextEvent: public wxStyledTextEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StyledTextEvent *_pObj;
public:
	inline wx_StyledTextEvent(WXTYPE commandType, int id) : wxStyledTextEvent(commandType, id), _sig(NULL), _pObj(NULL) {}
	~wx_StyledTextEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StyledTextEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StyledTextEvent::~wx_StyledTextEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StyledTextEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStyledTextEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(StyledTextEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StyledTextEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StyledTextEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE commandType = 0;
	if (args.IsValid(0)) commandType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_StyledTextEvent *pEntity = new wx_StyledTextEvent(commandType, id);
	Object_wx_StyledTextEvent *pObj = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StyledTextEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

#if 0
Gura_DeclareMethod(wx_StyledTextEvent, GetOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetOrientation)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StyledTextEvent, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StyledTextEvent, GetPosition)
{
	Object_wx_StyledTextEvent *pThis = Object_wx_StyledTextEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}
#endif

//----------------------------------------------------------------------------
// Object implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Object_wx_StyledTextEvent::~Object_wx_StyledTextEvent()
{
}

Object *Object_wx_StyledTextEvent::Clone() const
{
	return NULL;
}

String Object_wx_StyledTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.StyledTextEvent:");
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
// Class implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextEvent)
{
	Gura_AssignFunction(StyledTextEvent);
	//Gura_AssignMethod(wx_StyledTextEvent, GetOrientation);
	//Gura_AssignMethod(wx_StyledTextEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_StyledTextEvent)
{
	return new Object_wx_StyledTextEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
