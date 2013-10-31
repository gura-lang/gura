//----------------------------------------------------------------------------
// wxTreeEvent
// extracted from treeevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TreeEvent: public wxTreeEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TreeEvent *_pObj;
public:
	inline wx_TreeEvent(wxEventType commandType, wxTreeCtrl * tree, const wxTreeItemId& item) : wxTreeEvent(commandType, tree, item), _sig(NULL), _pObj(NULL) {}
	~wx_TreeEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TreeEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TreeEvent::~wx_TreeEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TreeEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TreeEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "tree", VTYPE_wx_TreeCtrl, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType commandType = static_cast<wxEventType>(args.GetInt(0));
	wxTreeCtrl *tree = Object_wx_TreeCtrl::GetObject(args, 1)->GetEntity();
	wxTreeItemId item = wxTreeItemId();
	if (args.IsValid(2)) item = *Object_wx_TreeItemId::GetObject(args, 2)->GetEntity();
	wx_TreeEvent *pEntity = new wx_TreeEvent(commandType, tree, item);
	Object_wx_TreeEvent *pObj = Object_wx_TreeEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TreeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TreeEvent, GetKeyCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetKeyCode)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeEvent, GetItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetItem)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId rtn = pThis->GetEntity()->GetItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, GetKeyEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetKeyEvent)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxKeyEvent &rtn = pThis->GetEntity()->GetKeyEvent();
	return ReturnValue(env, sig, args, Value(new Object_wx_KeyEvent(new wxKeyEvent(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, GetLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetLabel)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TreeEvent, GetOldItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetOldItem)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId rtn = pThis->GetEntity()->GetOldItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, GetPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetPoint)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPoint();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, IsEditCancelled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, IsEditCancelled)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEditCancelled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeEvent, SetToolTip)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tooltip", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeEvent, SetToolTip)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString tooltip = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetToolTip(tooltip);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTreeEvent
//----------------------------------------------------------------------------
Object_wx_TreeEvent::~Object_wx_TreeEvent()
{
}

Object *Object_wx_TreeEvent::Clone() const
{
	return NULL;
}

String Object_wx_TreeEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TreeEvent:");
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
// Class implementation for wxTreeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeEvent)
{
	Gura_AssignFunction(TreeEvent);
	Gura_AssignMethod(wx_TreeEvent, GetKeyCode);
	Gura_AssignMethod(wx_TreeEvent, GetItem);
	Gura_AssignMethod(wx_TreeEvent, GetKeyEvent);
	Gura_AssignMethod(wx_TreeEvent, GetLabel);
	Gura_AssignMethod(wx_TreeEvent, GetOldItem);
	Gura_AssignMethod(wx_TreeEvent, GetPoint);
	Gura_AssignMethod(wx_TreeEvent, IsEditCancelled);
	Gura_AssignMethod(wx_TreeEvent, SetToolTip);
}

Gura_ImplementDescendantCreator(wx_TreeEvent)
{
	return new Object_wx_TreeEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
