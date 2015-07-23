//----------------------------------------------------------------------------
// wxSashWindow
// extracted from sashwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SashWindow: public wxSashWindow, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_SashWindow *_pObj;
public:
	inline wx_SashWindow() : wxSashWindow(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_SashWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxSashWindow(parent, id, pos, size, style, name), _pSig(nullptr), _pObj(nullptr) {}
	~wx_SashWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SashWindow *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SashWindow::~wx_SashWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SashWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSashWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(SashWindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SashWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashWindowEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SashWindow *pEntity = new wx_SashWindow();
	Object_wx_SashWindow *pObj = Object_wx_SashWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SashWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(SashWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SashWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashWindow)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxCLIP_CHILDREN | wxSW_3D;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("sashWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_SashWindow *pEntity = new wx_SashWindow(parent, id, *pos, *size, style, name);
	Object_wx_SashWindow *pObj = Object_wx_SashWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SashWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_SashWindow, GetSashVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetSashVisible)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSashEdgePosition edge = static_cast<wxSashEdgePosition>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->GetSashVisible(edge);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, GetMaximumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetMaximumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMaximumSizeX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, GetMaximumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetMaximumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMaximumSizeY();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, GetMinimumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetMinimumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMinimumSizeX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, GetMinimumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetMinimumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMinimumSizeY();
	return ReturnValue(env, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_SashWindow, HasBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, HasBorder)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSashEdgePosition edge = static_cast<wxSashEdgePosition>(args.GetInt(0));
	bool rtn = pThis->GetEntity()->HasBorder(edge);
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_SashWindow, SetMaximumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMaximumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	pThis->GetEntity()->SetMaximumSizeX(min);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashWindow, SetMaximumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMaximumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	pThis->GetEntity()->SetMaximumSizeY(min);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashWindow, SetMinimumSizeX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMinimumSizeX)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	pThis->GetEntity()->SetMinimumSizeX(min);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashWindow, SetMinimumSizeY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetMinimumSizeY)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	pThis->GetEntity()->SetMinimumSizeY(min);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashWindow, SetSashVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "visible", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetSashVisible)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSashEdgePosition edge = static_cast<wxSashEdgePosition>(args.GetInt(0));
	bool visible = args.GetBoolean(1);
	pThis->GetEntity()->SetSashVisible(edge, visible);
	return Value::Null;
}

#if 0
Gura_DeclareMethod(wx_SashWindow, SetSashBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "hasBorder", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetSashBorder)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSashEdgePosition edge = static_cast<wxSashEdgePosition>(args.GetInt(0));
	bool hasBorder = args.GetBoolean(1);
	pThis->GetEntity()->SetSashBorder(edge, hasBorder);
	return Value::Null;
}
#endif

Gura_DeclareMethod(wx_SashWindow, GetEdgeMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetEdgeMargin)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSashEdgePosition edge = static_cast<wxSashEdgePosition>(args.GetInt(0));
	int rtn = pThis->GetEntity()->GetEdgeMargin(edge);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, GetDefaultBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetDefaultBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDefaultBorderSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, GetExtraBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashWindow, GetExtraBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDefaultBorderSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashWindow, SetDefaultBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetDefaultBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetDefaultBorderSize(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashWindow, SetExtraBorderSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashWindow, SetExtraBorderSize)
{
	Object_wx_SashWindow *pThis = Object_wx_SashWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetExtraBorderSize(width);
	return Value::Null;
}


//----------------------------------------------------------------------------
// Object implementation for wxSashWindow
//----------------------------------------------------------------------------
Object_wx_SashWindow::~Object_wx_SashWindow()
{
}

Object *Object_wx_SashWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SashWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SashWindow:");
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
// Class implementation for wxSashWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashWindow)
{
	Gura_AssignFunction(SashWindowEmpty);
	Gura_AssignFunction(SashWindow);
	Gura_AssignMethod(wx_SashWindow, GetSashVisible);
	Gura_AssignMethod(wx_SashWindow, GetMaximumSizeX);
	Gura_AssignMethod(wx_SashWindow, GetMaximumSizeY);
	Gura_AssignMethod(wx_SashWindow, GetMinimumSizeX);
	Gura_AssignMethod(wx_SashWindow, GetMinimumSizeY);
	//Gura_AssignMethod(wx_SashWindow, HasBorder);
	Gura_AssignMethod(wx_SashWindow, SetMaximumSizeX);
	Gura_AssignMethod(wx_SashWindow, SetMaximumSizeY);
	Gura_AssignMethod(wx_SashWindow, SetMinimumSizeX);
	Gura_AssignMethod(wx_SashWindow, SetMinimumSizeY);
	Gura_AssignMethod(wx_SashWindow, SetSashVisible);
	//Gura_AssignMethod(wx_SashWindow, SetSashBorder);
	Gura_AssignMethod(wx_SashWindow, GetEdgeMargin);
	Gura_AssignMethod(wx_SashWindow, GetDefaultBorderSize);
	Gura_AssignMethod(wx_SashWindow, GetExtraBorderSize);
	Gura_AssignMethod(wx_SashWindow, SetDefaultBorderSize);
	Gura_AssignMethod(wx_SashWindow, SetExtraBorderSize);
}

Gura_ImplementDescendantCreator(wx_SashWindow)
{
	return new Object_wx_SashWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
