//----------------------------------------------------------------------------
// wxFindDialogEvent
// extracted from fdrepdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FindDialogEvent: public wxFindDialogEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FindDialogEvent *_pObj;
public:
	inline wx_FindDialogEvent(wxEventType commandType, int id) : wxFindDialogEvent(commandType, id), _pObj(nullptr) {}
	~wx_FindDialogEvent();
	inline void AssocWithGura(Object_wx_FindDialogEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FindDialogEvent::~wx_FindDialogEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FindDialogEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFindDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(FindDialogEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FindDialogEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindDialogEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxEventType commandType = wxEVT_NULL;
	if (args.IsValid(0)) commandType = static_cast<wxEventType>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_FindDialogEvent *pEntity = new wx_FindDialogEvent(commandType, id);
	Object_wx_FindDialogEvent *pObj = Object_wx_FindDialogEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FindDialogEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FindDialogEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindDialogEvent, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FindDialogEvent, GetFindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindDialogEvent, GetFindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFindString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FindDialogEvent, GetReplaceString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindDialogEvent, GetReplaceString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetReplaceString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FindDialogEvent, GetDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindDialogEvent, GetDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindDialogEvent *pThis = Object_wx_FindDialogEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFindReplaceDialog *rtn = (wxFindReplaceDialog *)pThis->GetEntity()->GetDialog();
	return ReturnValue(env, args, Value(new Object_wx_FindReplaceDialog(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFindDialogEvent
//----------------------------------------------------------------------------
Object_wx_FindDialogEvent::~Object_wx_FindDialogEvent()
{
}

Object *Object_wx_FindDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FindDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FindDialogEvent:");
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
// Class implementation for wxFindDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindDialogEvent)
{
	Gura_AssignFunction(FindDialogEvent);
	Gura_AssignMethod(wx_FindDialogEvent, GetFlags);
	Gura_AssignMethod(wx_FindDialogEvent, GetFindString);
	Gura_AssignMethod(wx_FindDialogEvent, GetReplaceString);
	Gura_AssignMethod(wx_FindDialogEvent, GetDialog);
}

Gura_ImplementDescendantCreator(wx_FindDialogEvent)
{
	return new Object_wx_FindDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
