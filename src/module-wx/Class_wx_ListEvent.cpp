//----------------------------------------------------------------------------
// wxListEvent
// extracted from listevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListEvent: public wxListEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ListEvent *_pObj;
public:
	inline wx_ListEvent(WXTYPE commandType, int id) : wxListEvent(commandType, id), _sig(nullptr), _pObj(nullptr) {}
	~wx_ListEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ListEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListEvent::~wx_ListEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ListEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ListEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE commandType = 0;
	if (args.IsValid(0)) commandType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_ListEvent *pEntity = new wx_ListEvent(commandType, id);
	Object_wx_ListEvent *pObj = Object_wx_ListEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ListEvent, GetCacheFrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetCacheFrom)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetCacheFrom();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetCacheTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetCacheTo)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetCacheTo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetKeyCode)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetIndex)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetIndex();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetColumn)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColumn();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetPoint)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPoint();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListEvent, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetLabel)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListEvent, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetText)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetText();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListEvent, GetImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetImage)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetImage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetData)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetData();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetMask)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetMask();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetItem)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxListItem &rtn = pThis->GetEntity()->GetItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_ListItem(new wxListItem(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListEvent, IsEditCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, IsEditCancelled)
{
	Object_wx_ListEvent *pThis = Object_wx_ListEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEditCancelled();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxListEvent
//----------------------------------------------------------------------------
Object_wx_ListEvent::~Object_wx_ListEvent()
{
}

Object *Object_wx_ListEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ListEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ListEvent:");
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
// Class implementation for wxListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListEvent)
{
	Gura_AssignFunction(ListEvent);
	Gura_AssignMethod(wx_ListEvent, GetCacheFrom);
	Gura_AssignMethod(wx_ListEvent, GetCacheTo);
	Gura_AssignMethod(wx_ListEvent, GetKeyCode);
	Gura_AssignMethod(wx_ListEvent, GetIndex);
	Gura_AssignMethod(wx_ListEvent, GetColumn);
	Gura_AssignMethod(wx_ListEvent, GetPoint);
	Gura_AssignMethod(wx_ListEvent, GetLabel);
	Gura_AssignMethod(wx_ListEvent, GetText);
	Gura_AssignMethod(wx_ListEvent, GetImage);
	Gura_AssignMethod(wx_ListEvent, GetData);
	Gura_AssignMethod(wx_ListEvent, GetMask);
	Gura_AssignMethod(wx_ListEvent, GetItem);
	Gura_AssignMethod(wx_ListEvent, IsEditCancelled);
}

Gura_ImplementDescendantCreator(wx_ListEvent)
{
	return new Object_wx_ListEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
