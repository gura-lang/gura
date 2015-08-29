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
	//Gura::Signal *_pSig;
	Object_wx_TreeEvent *_pObj;
public:
	inline wx_TreeEvent(wxEventType commandType, wxTreeCtrl * tree, const wxTreeItemId& item) : wxTreeEvent(commandType, tree, item), _pObj(nullptr) {}
	~wx_TreeEvent();
	inline void AssocWithGura(Object_wx_TreeEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TreeEvent::~wx_TreeEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TreeEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TreeEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "tree", VTYPE_wx_TreeCtrl, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxEventType commandType = static_cast<wxEventType>(arg.GetInt(0));
	wxTreeCtrl *tree = Object_wx_TreeCtrl::GetObject(arg, 1)->GetEntity();
	wxTreeItemId item = wxTreeItemId();
	if (arg.IsValid(2)) item = *Object_wx_TreeItemId::GetObject(arg, 2)->GetEntity();
	wx_TreeEvent *pEntity = new wx_TreeEvent(commandType, tree, item);
	Object_wx_TreeEvent *pObj = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TreeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_TreeEvent, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetKeyCode();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TreeEvent, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTreeItemId rtn = pThis->GetEntity()->GetItem();
	return ReturnValue(env, arg, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, GetKeyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetKeyEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxKeyEvent &rtn = pThis->GetEntity()->GetKeyEvent();
	return ReturnValue(env, arg, Value(new Object_wx_KeyEvent(new wxKeyEvent(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLabel();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TreeEvent, GetOldItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetOldItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTreeItemId rtn = pThis->GetEntity()->GetOldItem();
	return ReturnValue(env, arg, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, GetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, GetPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPoint();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeEvent, IsEditCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeEvent, IsEditCancelled)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEditCancelled();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_TreeEvent, SetToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tooltip", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeEvent, SetToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString tooltip = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetToolTip(tooltip);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTreeEvent
//----------------------------------------------------------------------------
Object_wx_TreeEvent::~Object_wx_TreeEvent()
{
}

Object *Object_wx_TreeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TreeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TreeEvent:");
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
	return new Object_wx_TreeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
