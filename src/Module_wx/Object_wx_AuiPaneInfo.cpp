//----------------------------------------------------------------------------
// wxAuiPaneInfo
// extracted from auipaneinfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiPaneInfo: public wxAuiPaneInfo, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AuiPaneInfo *_pObj;
public:
	inline wx_AuiPaneInfo() : wxAuiPaneInfo(), _sig(NULL), _pObj(NULL) {}
	inline wx_AuiPaneInfo(const wxAuiPaneInfo& c) : wxAuiPaneInfo(c), _sig(NULL), _pObj(NULL) {}
	~wx_AuiPaneInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AuiPaneInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiPaneInfo::~wx_AuiPaneInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AuiPaneInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiPaneInfoEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiPaneInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiPaneInfoEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_AuiPaneInfo *pEntity = new wx_AuiPaneInfo();
	Object_wx_AuiPaneInfo *pObj = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiPaneInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(AuiPaneInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AuiPaneInfo));
	DeclareArg(env, "c", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AuiPaneInfo)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxAuiPaneInfo *c = Object_wx_AuiPaneInfo::GetObject(args, 0)->GetEntity();
	wx_AuiPaneInfo *pEntity = new wx_AuiPaneInfo(*c);
	Object_wx_AuiPaneInfo *pObj = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiPaneInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_AuiPaneInfo, BestSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BestSize)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->BestSize(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, BestSize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BestSize_1)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->BestSize(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Bottom)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Bottom)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Bottom();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, BottomDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BottomDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->BottomDockable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Caption)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Caption)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString c = wxString::FromUTF8(args.GetString(0));
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Caption(c);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CaptionVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CaptionVisible)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->CaptionVisible(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Centre)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Centre)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Centre();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Center)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Center)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Center();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CentrePane)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CentrePane)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->CentrePane();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CenterPane)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CenterPane)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->CenterPane();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, CloseButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CloseButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->CloseButton(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, DefaultPane)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DefaultPane)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->DefaultPane();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, DestroyOnClose)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DestroyOnClose)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->DestroyOnClose(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Direction)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Direction)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int direction = args.GetInt(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Direction(direction);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Dock)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Dock)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Dock();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, DockFixed)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DockFixed)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->DockFixed(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Dockable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Dockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Dockable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Fixed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Fixed)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Fixed();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Float)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Float)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Float();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Floatable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Floatable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Floatable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingPosition)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *pos = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->FloatingPosition(*pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingPosition_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingPosition_1)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->FloatingPosition(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingSize)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->FloatingSize(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingSize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingSize_1)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->FloatingSize(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Gripper)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Gripper)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Gripper(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, GripperTop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "attop", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, GripperTop)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool attop = true;
	if (args.IsValid(0)) attop = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->GripperTop(attop);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasBorder)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasBorder)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBorder();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasCaption)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasCaption)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasCaption();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasCloseButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasCloseButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasCloseButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasFlag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasFlag)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned flag = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->HasFlag(flag);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasGripper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasGripper)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasGripper();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasGripperTop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasGripperTop)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasGripperTop();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasMaximizeButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasMaximizeButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasMaximizeButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasMinimizeButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasMinimizeButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasMinimizeButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasPinButton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasPinButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasPinButton();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Hide)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Hide)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Hide();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsBottomDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsBottomDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsBottomDockable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsDocked)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsDocked)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsDocked();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFixed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFixed)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsFixed();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFloatable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFloatable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsFloatable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFloating)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFloating)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsFloating();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsLeftDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsLeftDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsLeftDockable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsMovable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsMovable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsMovable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsOk)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsResizable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsResizable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsResizable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsRightDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsRightDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsRightDockable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsShown)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsShown)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsShown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsToolbar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsToolbar)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsToolbar();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsTopDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsTopDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsTopDockable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Layer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "layer", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Layer)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int layer = args.GetInt(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Layer(layer);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Left)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Left)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Left();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, LeftDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, LeftDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->LeftDockable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaxSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaxSize)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->MaxSize(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaxSize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaxSize_1)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->MaxSize(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaximizeButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaximizeButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->MaximizeButton(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinSize)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->MinSize(*size);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinSize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinSize_1)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->MinSize(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinimizeButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinimizeButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->MinimizeButton(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Movable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Movable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Movable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Name)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Name)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString n = wxString::FromUTF8(args.GetString(0));
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Name(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, PaneBorder)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, PaneBorder)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->PaneBorder(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, PinButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, PinButton)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool visible = true;
	if (args.IsValid(0)) visible = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->PinButton(visible);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Position)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Position)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pos = args.GetInt(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Position(pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Resizable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "resizable", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Resizable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool resizable = true;
	if (args.IsValid(0)) resizable = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Resizable(resizable);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Right)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Right)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Right();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, RightDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, RightDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->RightDockable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Row)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Row)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Row(row);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, SafeSet)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "source", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, SafeSet)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo *source = Object_wx_AuiPaneInfo::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SafeSet(*source);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiPaneInfo, SetFlag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "option_state", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, SetFlag)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned flag = args.GetInt(0);
	bool option_state = args.GetBoolean(1);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->SetFlag(flag, option_state);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Show)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Show)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Show(show);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, ToolbarPane)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, ToolbarPane)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->ToolbarPane();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Top)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Top)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Top();
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, TopDockable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, TopDockable)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool b = true;
	if (args.IsValid(0)) b = args.GetBoolean(0);
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->TopDockable(b);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiPaneInfo, Window)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "w", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Window)
{
	Object_wx_AuiPaneInfo *pSelf = Object_wx_AuiPaneInfo::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *w = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxAuiPaneInfo &rtn = pSelf->GetEntity()->Window(w);
	return ReturnValue(env, sig, args, Value(new Object_wx_AuiPaneInfo(new wxAuiPaneInfo(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Object_wx_AuiPaneInfo::~Object_wx_AuiPaneInfo()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AuiPaneInfo::Clone() const
{
	return NULL;
}

String Object_wx_AuiPaneInfo::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AuiPaneInfo:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AuiPaneInfo::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(AuiPaneInfoEmpty);
	Gura_AssignFunction(AuiPaneInfo);
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiPaneInfo)
{
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
	return new Object_wx_AuiPaneInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
