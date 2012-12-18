//----------------------------------------------------------------------------
// wxListEvent
// extracted from listevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListEvent: public wxListEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ListEvent *_pObj;
public:
	inline wx_ListEvent(WXTYPE commandType, int id) : wxListEvent(commandType, id), _sig(NULL), _pObj(NULL) {}
	~wx_ListEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ListEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListEvent::~wx_ListEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ListEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ListEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListEvent)
{
	WXTYPE commandType = 0;
	if (args.IsValid(0)) commandType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_ListEvent *pEntity = new wx_ListEvent(commandType, id);
	Object_wx_ListEvent *pObj = Object_wx_ListEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ListEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ListEvent, GetCacheFrom)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetCacheFrom)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetCacheFrom();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetCacheTo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetCacheTo)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetCacheTo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetKeyCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetKeyCode)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetKeyCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetIndex)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetIndex();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetColumn)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetColumn();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetPoint)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pSelf->GetEntity()->GetPoint();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListEvent, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetLabel)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListEvent, GetText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetText)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListEvent, GetImage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetImage)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetImage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetData)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetData();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetMask)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetMask)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetMask();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListEvent, GetItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, GetItem)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxListItem &rtn = pSelf->GetEntity()->GetItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_ListItem(new wxListItem(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListEvent, IsEditCancelled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListEvent, IsEditCancelled)
{
	Object_wx_ListEvent *pSelf = Object_wx_ListEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsEditCancelled();
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
	return NULL;
}

String Object_wx_ListEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ListEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ListEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ListEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListEvent)
{
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
	return new Object_wx_ListEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
