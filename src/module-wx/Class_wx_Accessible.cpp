//----------------------------------------------------------------------------
// wxAccessible
// extracted from accessible.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(DoDefaultAction);
Gura_DeclarePrivUserSymbol(GetChild);
Gura_DeclarePrivUserSymbol(GetChildCount);
Gura_DeclarePrivUserSymbol(GetDefaultAction);
Gura_DeclarePrivUserSymbol(GetDescription);
Gura_DeclarePrivUserSymbol(GetFocus);
Gura_DeclarePrivUserSymbol(GetHelpText);
Gura_DeclarePrivUserSymbol(GetKeyboardShortcut);
Gura_DeclarePrivUserSymbol(GetLocation);
Gura_DeclarePrivUserSymbol(GetName);
Gura_DeclarePrivUserSymbol(GetParent);
Gura_DeclarePrivUserSymbol(GetRole);
Gura_DeclarePrivUserSymbol(GetSelections);
Gura_DeclarePrivUserSymbol(GetState);
Gura_DeclarePrivUserSymbol(GetValue);
Gura_DeclarePrivUserSymbol(HitTest);
Gura_DeclarePrivUserSymbol(Navigate);
Gura_DeclarePrivUserSymbol(NotifyEvent);
Gura_DeclarePrivUserSymbol(Select);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Accessible: public wxAccessible, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Accessible *_pObj;
public:
	inline wx_Accessible(wxWindow* win) : wxAccessible(win), _pSig(nullptr), _pObj(nullptr) {}
	//virtual wxAccStatus DoDefaultAction(int childId);
	//virtual wxAccStatus GetChild(int childId, wxAccessible** child);
	//virtual wxAccStatus GetChildCount(int* childCount);
	//virtual wxAccStatus GetDefaultAction(int childId, wxString* actionName);
	//virtual wxAccStatus GetDescription(int childId, wxString* description);
	//virtual wxAccStatus GetFocus(int* childId, wxAccessible** child);
	//virtual wxAccStatus GetHelpText(int childId, wxString* helpText);
	//virtual wxAccStatus GetKeyboardShortcut(int childId, wxString* shortcut);
	//virtual wxAccStatus GetLocation(wxRect& rect, int elementId);
	//virtual wxAccStatus GetName(int childId, wxString* name);
	//virtual wxAccStatus GetParent(wxAccessible** parent);
	//virtual wxAccStatus GetRole(int childId, wxAccRole* role);
	//virtual wxAccStatus GetSelections(wxVariant* selections);
	//virtual wxAccStatus GetState(int childId, long* state);
	//virtual wxAccStatus GetValue(int childId, wxString* strValue);
	//virtual wxAccStatus HitTest(const wxPoint& pt, int* childId, wxAccessible** childObject);
	//virtual wxAccStatus Navigate(wxNavDir navDir, int fromId, int* toId, wxAccessible** toObject);
	//virtual static void NotifyEvent(int eventType, wxWindow* window, wxAccObject objectType, int objectType);
	//virtual wxAccStatus Select(int childId, wxAccSelectionFlags selectFlags);
	~wx_Accessible();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Accessible *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Accessible::~wx_Accessible()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Accessible::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAccessible
//----------------------------------------------------------------------------
Gura_DeclareFunction(Accessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Accessible));
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Accessible)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = (wxWindow *)(nullptr);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_Accessible *pEntity = new wx_Accessible(win);
	Object_wx_Accessible *pObj = Object_wx_Accessible::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Accessible(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Accessible, DoDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, DoDefaultAction)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxAccStatus rtn = pThis->GetEntity()->DoDefaultAction(childId);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "child", VTYPE_wx_Accessible, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetChild)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxAccessible *child = Object_wx_Accessible::GetObject(args, 1)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->GetChild(childId, *child);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childCount", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetChildCount)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childCount = args.GetInt(0);
	wxAccStatus rtn = pThis->GetEntity()->GetChildCount(childCount);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "actionName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetDefaultAction)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxString actionName = wxString::FromUTF8(args.GetString(1));
	wxAccStatus rtn = pThis->GetEntity()->GetDefaultAction(childId, actionName);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "description", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetDescription)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxString description = wxString::FromUTF8(args.GetString(1));
	wxAccStatus rtn = pThis->GetEntity()->GetDescription(childId, description);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "child", VTYPE_wx_Accessible, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetFocus)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxAccessible *child = Object_wx_Accessible::GetObject(args, 1)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->GetFocus(childId, *child);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "helpText", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetHelpText)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxString helpText = wxString::FromUTF8(args.GetString(1));
	wxAccStatus rtn = pThis->GetEntity()->GetHelpText(childId, helpText);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetKeyboardShortcut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "shortcut", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetKeyboardShortcut)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxString shortcut = wxString::FromUTF8(args.GetString(1));
	wxAccStatus rtn = pThis->GetEntity()->GetKeyboardShortcut(childId, shortcut);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "elementId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetLocation)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int elementId = args.GetInt(1);
	wxAccStatus rtn = pThis->GetEntity()->GetLocation(*rect, elementId);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetName)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxAccStatus rtn = pThis->GetEntity()->GetName(childId, name);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Accessible, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetParent)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAccessible *parent = Object_wx_Accessible::GetObject(args, 0)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->GetParent(*parent);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetRole)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "role", VTYPE_wx_AccRole, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetRole)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxAccRole *role = Object_wx_AccRole::GetObject(args, 1)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->GetRole(childId, role);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "selections", VTYPE_wx_Variant, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetSelections)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVariant *selections = Object_wx_Variant::GetObject(args, 0)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->GetSelections(selections);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetState)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	long state = args.GetLong(1);
	wxAccStatus rtn = pThis->GetEntity()->GetState(childId, state);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "strValue", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetValue)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxString strValue = wxString::FromUTF8(args.GetString(1));
	wxAccStatus rtn = pThis->GetEntity()->GetValue(childId, strValue);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, GetWindow)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Accessible, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "childObject", VTYPE_wx_Accessible, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, HitTest)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int childId = args.GetInt(1);
	wxAccessible *childObject = Object_wx_Accessible::GetObject(args, 2)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->HitTest(*pt, childId, *childObject);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, Navigate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "navDir", VTYPE_wx_NavDir, OCCUR_Once);
	DeclareArg(env, "fromId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "toId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "toObject", VTYPE_wx_Accessible, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, Navigate)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxNavDir *navDir = Object_wx_NavDir::GetObject(args, 0)->GetEntity();
	int fromId = args.GetInt(1);
	int toId = args.GetInt(2);
	wxAccessible *toObject = Object_wx_Accessible::GetObject(args, 3)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->Navigate(*navDir, fromId, toId, *toObject);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, NotifyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "objectType", VTYPE_wx_AccObject, OCCUR_Once);
	DeclareArg(env, "objectType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, NotifyEvent)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int eventType = args.GetInt(0);
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxAccObject *objectType = Object_wx_AccObject::GetObject(args, 2)->GetEntity();
	int objectType = args.GetInt(3);
	pThis->GetEntity()->NotifyEvent(eventType, window, *objectType, objectType);
	return Value::Null;
}

Gura_DeclareMethod(wx_Accessible, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "selectFlags", VTYPE_wx_AccSelectionFlags, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Accessible, Select)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int childId = args.GetInt(0);
	wxAccSelectionFlags *selectFlags = Object_wx_AccSelectionFlags::GetObject(args, 1)->GetEntity();
	wxAccStatus rtn = pThis->GetEntity()->Select(childId, *selectFlags);
	return ReturnValue(env, args, Value(new Object_wx_AccStatus(new wxAccStatus(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Accessible, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, SetWindow)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetWindow(window);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAccessible
//----------------------------------------------------------------------------
Object_wx_Accessible::~Object_wx_Accessible()
{
}

Object *Object_wx_Accessible::Clone() const
{
	return nullptr;
}

String Object_wx_Accessible::ToString(bool exprFlag)
{
	String rtn("<wx.Accessible:");
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
// Class implementation for wxAccessible
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Accessible)
{
	Gura_RealizeUserSymbol(DoDefaultAction);
	Gura_RealizeUserSymbol(GetChild);
	Gura_RealizeUserSymbol(GetChildCount);
	Gura_RealizeUserSymbol(GetDefaultAction);
	Gura_RealizeUserSymbol(GetDescription);
	Gura_RealizeUserSymbol(GetFocus);
	Gura_RealizeUserSymbol(GetHelpText);
	Gura_RealizeUserSymbol(GetKeyboardShortcut);
	Gura_RealizeUserSymbol(GetLocation);
	Gura_RealizeUserSymbol(GetName);
	Gura_RealizeUserSymbol(GetParent);
	Gura_RealizeUserSymbol(GetRole);
	Gura_RealizeUserSymbol(GetSelections);
	Gura_RealizeUserSymbol(GetState);
	Gura_RealizeUserSymbol(GetValue);
	Gura_RealizeUserSymbol(HitTest);
	Gura_RealizeUserSymbol(Navigate);
	Gura_RealizeUserSymbol(NotifyEvent);
	Gura_RealizeUserSymbol(Select);
	Gura_AssignFunction(Accessible);
	Gura_AssignMethod(wx_Accessible, DoDefaultAction);
	Gura_AssignMethod(wx_Accessible, GetChild);
	Gura_AssignMethod(wx_Accessible, GetChildCount);
	Gura_AssignMethod(wx_Accessible, GetDefaultAction);
	Gura_AssignMethod(wx_Accessible, GetDescription);
	Gura_AssignMethod(wx_Accessible, GetFocus);
	Gura_AssignMethod(wx_Accessible, GetHelpText);
	Gura_AssignMethod(wx_Accessible, GetKeyboardShortcut);
	Gura_AssignMethod(wx_Accessible, GetLocation);
	Gura_AssignMethod(wx_Accessible, GetName);
	Gura_AssignMethod(wx_Accessible, GetParent);
	Gura_AssignMethod(wx_Accessible, GetRole);
	Gura_AssignMethod(wx_Accessible, GetSelections);
	Gura_AssignMethod(wx_Accessible, GetState);
	Gura_AssignMethod(wx_Accessible, GetValue);
	Gura_AssignMethod(wx_Accessible, GetWindow);
	Gura_AssignMethod(wx_Accessible, HitTest);
	Gura_AssignMethod(wx_Accessible, Navigate);
	Gura_AssignMethod(wx_Accessible, NotifyEvent);
	Gura_AssignMethod(wx_Accessible, Select);
	Gura_AssignMethod(wx_Accessible, SetWindow);
}

Gura_ImplementDescendantCreator(wx_Accessible)
{
	return new Object_wx_Accessible((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
