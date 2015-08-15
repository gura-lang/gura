//----------------------------------------------------------------------------
// wxAuiPaneInfo
// extracted from auipaneinfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiPaneInfo: public wxAuiPaneInfo, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AuiPaneInfo *_pObj;
public:
	inline wx_AuiPaneInfo() : wxAuiPaneInfo(), _pObj(nullptr) {}
	inline wx_AuiPaneInfo(const wxAuiPaneInfo& c) : wxAuiPaneInfo(c), _pObj(nullptr) {}
	~wx_AuiPaneInfo();
	inline void AssocWithGura(Object_wx_AuiPaneInfo *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiPaneInfo::~wx_AuiPaneInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AuiPaneInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiPaneInfoEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiPaneInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiPaneInfoEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_AuiPaneInfo *pEntity = new wx_AuiPaneInfo();
	Object_wx_AuiPaneInfo *pObj = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_AuiPaneInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(AuiPaneInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AuiPaneInfo));
	DeclareArg(env, "c", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiPaneInfo)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxAuiPaneInfo *c = Object_wx_AuiPaneInfo::GetObject(args, 0)->GetEntity();
	wx_AuiPaneInfo *pEntity = new wx_AuiPaneInfo(*c);
	Object_wx_AuiPaneInfo *pObj = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_AuiPaneInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_AuiPaneInfo, BestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->BestSize(*size);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, BestSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BestSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->BestSize(x, y);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Bottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Bottom)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Bottom();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, BottomDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BottomDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->BottomDockable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Caption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Caption)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString c = wxString::FromUTF8(args.GetString(0));
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Caption(c);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CaptionVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CaptionVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->CaptionVisible(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Centre)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Centre();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Center)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Center)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Center();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CentrePane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CentrePane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->CentrePane();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CenterPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CenterPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->CenterPane();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CloseButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->CloseButton(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, DefaultPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DefaultPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->DefaultPane();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, DestroyOnClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DestroyOnClose)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->DestroyOnClose(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Direction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Direction)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int direction = args.GetInt(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Direction(direction);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Dock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Dock)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Dock();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, DockFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DockFixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->DockFixed(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Dockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Dockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Dockable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Fixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Fixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Fixed();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Float)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Float)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Float();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Floatable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Floatable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Floatable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pos = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->FloatingPosition(*pos);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->FloatingPosition(x, y);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->FloatingSize(*size);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->FloatingSize(x, y);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Gripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Gripper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Gripper(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, GripperTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "attop", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, GripperTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool attop = true;
	if (args.IsValid(0)) attop = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->GripperTop(attop);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasBorder();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasCaption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasCaption)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasCaption();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasCloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasCloseButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasCloseButton();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned flag = args.GetInt(0);
	bool rtn = pThis->GetEntity()->HasFlag(flag);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasGripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasGripper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasGripper();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasGripperTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasGripperTop)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasGripperTop();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasMaximizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasMaximizeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasMaximizeButton();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasMinimizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasMinimizeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasMinimizeButton();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasPinButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasPinButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasPinButton();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Hide();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsBottomDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsBottomDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsBottomDockable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsDocked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsDocked)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDocked();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFixed();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFloatable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFloatable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFloatable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFloating)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFloating)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsFloating();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsLeftDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsLeftDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsLeftDockable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsMovable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsMovable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsMovable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsResizable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsResizable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsResizable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsRightDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsRightDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsRightDockable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsShown();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsToolbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsToolbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsToolbar();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsTopDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsTopDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsTopDockable();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Layer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "layer", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Layer)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int layer = args.GetInt(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Layer(layer);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Left)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Left();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, LeftDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, LeftDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->LeftDockable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaxSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->MaxSize(*size);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaxSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaxSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->MaxSize(x, y);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaximizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaximizeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->MaximizeButton(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->MinSize(*size);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->MinSize(x, y);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinimizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinimizeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->MinimizeButton(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Movable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Movable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Movable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Name)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Name)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString n = wxString::FromUTF8(args.GetString(0));
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Name(n);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, PaneBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, PaneBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->PaneBorder(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, PinButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, PinButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->PinButton(visible);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Position)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Position)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = args.GetInt(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Position(pos);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Resizable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "resizable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Resizable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool resizable = true;
	if (args.IsValid(0)) resizable = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Resizable(resizable);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Right)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Right();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, RightDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, RightDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->RightDockable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Row)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Row)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = args.GetInt(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Row(row);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, SafeSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "source", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, SafeSet)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo *source = Object_wx_AuiPaneInfo::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SafeSet(*source);
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, SetFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "option_state", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, SetFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned flag = args.GetInt(0);
	bool option_state = args.GetBoolean(1);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->SetFlag(flag, option_state);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Show(show);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, ToolbarPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, ToolbarPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->ToolbarPane();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Top)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Top)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Top();
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, TopDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, TopDockable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pThis->GetEntity()->TopDockable(b);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Window)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "w", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Window)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *w = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pThis->GetEntity()->Window(w);
	return ReturnValue(env, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Object_wx_AuiPaneInfo::~Object_wx_AuiPaneInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_AuiPaneInfo::Clone() const
{
	return nullptr;
}

String Object_wx_AuiPaneInfo::ToString(bool exprFlag)
{
	String rtn("<wx.AuiPaneInfo:");
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
// Class implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiPaneInfo)
{
	Gura_AssignFunction(AuiPaneInfoEmpty);
	Gura_AssignFunction(AuiPaneInfo);
	Gura_AssignMethod(wx_AuiPaneInfo, BestSize);
	Gura_AssignMethod(wx_AuiPaneInfo, BestSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, Bottom);
	Gura_AssignMethod(wx_AuiPaneInfo, BottomDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Caption);
	Gura_AssignMethod(wx_AuiPaneInfo, CaptionVisible);
	Gura_AssignMethod(wx_AuiPaneInfo, Centre);
	Gura_AssignMethod(wx_AuiPaneInfo, Center);
	Gura_AssignMethod(wx_AuiPaneInfo, CentrePane);
	Gura_AssignMethod(wx_AuiPaneInfo, CenterPane);
	Gura_AssignMethod(wx_AuiPaneInfo, CloseButton);
	Gura_AssignMethod(wx_AuiPaneInfo, DefaultPane);
	Gura_AssignMethod(wx_AuiPaneInfo, DestroyOnClose);
	Gura_AssignMethod(wx_AuiPaneInfo, Direction);
	Gura_AssignMethod(wx_AuiPaneInfo, Dock);
	Gura_AssignMethod(wx_AuiPaneInfo, DockFixed);
	Gura_AssignMethod(wx_AuiPaneInfo, Dockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Fixed);
	Gura_AssignMethod(wx_AuiPaneInfo, Float);
	Gura_AssignMethod(wx_AuiPaneInfo, Floatable);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingPosition);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingPosition_1);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingSize);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, Gripper);
	Gura_AssignMethod(wx_AuiPaneInfo, GripperTop);
	Gura_AssignMethod(wx_AuiPaneInfo, HasBorder);
	Gura_AssignMethod(wx_AuiPaneInfo, HasCaption);
	Gura_AssignMethod(wx_AuiPaneInfo, HasCloseButton);
	Gura_AssignMethod(wx_AuiPaneInfo, HasFlag);
	Gura_AssignMethod(wx_AuiPaneInfo, HasGripper);
	Gura_AssignMethod(wx_AuiPaneInfo, HasGripperTop);
	Gura_AssignMethod(wx_AuiPaneInfo, HasMaximizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, HasMinimizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, HasPinButton);
	Gura_AssignMethod(wx_AuiPaneInfo, Hide);
	Gura_AssignMethod(wx_AuiPaneInfo, IsBottomDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsDocked);
	Gura_AssignMethod(wx_AuiPaneInfo, IsFixed);
	Gura_AssignMethod(wx_AuiPaneInfo, IsFloatable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsFloating);
	Gura_AssignMethod(wx_AuiPaneInfo, IsLeftDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsMovable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsOk);
	Gura_AssignMethod(wx_AuiPaneInfo, IsResizable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsRightDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsShown);
	Gura_AssignMethod(wx_AuiPaneInfo, IsToolbar);
	Gura_AssignMethod(wx_AuiPaneInfo, IsTopDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Layer);
	Gura_AssignMethod(wx_AuiPaneInfo, Left);
	Gura_AssignMethod(wx_AuiPaneInfo, LeftDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, MaxSize);
	Gura_AssignMethod(wx_AuiPaneInfo, MaxSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, MaximizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, MinSize);
	Gura_AssignMethod(wx_AuiPaneInfo, MinSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, MinimizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, Movable);
	Gura_AssignMethod(wx_AuiPaneInfo, Name);
	Gura_AssignMethod(wx_AuiPaneInfo, PaneBorder);
	Gura_AssignMethod(wx_AuiPaneInfo, PinButton);
	Gura_AssignMethod(wx_AuiPaneInfo, Position);
	Gura_AssignMethod(wx_AuiPaneInfo, Resizable);
	Gura_AssignMethod(wx_AuiPaneInfo, Right);
	Gura_AssignMethod(wx_AuiPaneInfo, RightDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Row);
	Gura_AssignMethod(wx_AuiPaneInfo, SafeSet);
	Gura_AssignMethod(wx_AuiPaneInfo, SetFlag);
	Gura_AssignMethod(wx_AuiPaneInfo, Show);
	Gura_AssignMethod(wx_AuiPaneInfo, ToolbarPane);
	Gura_AssignMethod(wx_AuiPaneInfo, Top);
	Gura_AssignMethod(wx_AuiPaneInfo, TopDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Window);
}

Gura_ImplementDescendantCreator(wx_AuiPaneInfo)
{
	return new Object_wx_AuiPaneInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
