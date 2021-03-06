//----------------------------------------------------------------------------
// wxSashLayoutWindow
// extracted from sashlayw.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SashLayoutWindow: public wxSashLayoutWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SashLayoutWindow *_pObj;
public:
	inline wx_SashLayoutWindow() : wxSashLayoutWindow(), _pObj(nullptr) {}
	inline wx_SashLayoutWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxSashLayoutWindow(parent, id, pos, size, style, name), _pObj(nullptr) {}
	~wx_SashLayoutWindow();
	inline void AssocWithGura(Object_wx_SashLayoutWindow *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SashLayoutWindow::~wx_SashLayoutWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SashLayoutWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(SashLayoutWindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SashLayoutWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashLayoutWindowEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SashLayoutWindow *pEntity = new wx_SashLayoutWindow();
	Object_wx_SashLayoutWindow *pObj = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SashLayoutWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(SashLayoutWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SashLayoutWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashLayoutWindow)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxCLIP_CHILDREN | wxSW_3D;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxT("layoutWindow");
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	wx_SashLayoutWindow *pEntity = new wx_SashLayoutWindow(parent, id, *pos, *size, style, name);
	Object_wx_SashLayoutWindow *pObj = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SashLayoutWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SashLayoutWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashLayoutWindow, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxCLIP_CHILDREN | wxSW_3D;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxT("layoutWindow");
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SashLayoutWindow, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashLayoutWindow, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutAlignment rtn = pThis->GetEntity()->GetAlignment();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SashLayoutWindow, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashLayoutWindow, GetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutOrientation rtn = pThis->GetEntity()->GetOrientation();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SashLayoutWindow, OnCalculateLayout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CalculateLayoutEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, OnCalculateLayout)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCalculateLayoutEvent *event = Object_wx_CalculateLayoutEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnCalculateLayout(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, OnQueryLayoutInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_QueryLayoutInfoEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, OnQueryLayoutInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxQueryLayoutInfoEvent *event = Object_wx_QueryLayoutInfoEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnQueryLayoutInfo(*event);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutAlignment alignment = static_cast<wxLayoutAlignment>(arg.GetInt(0));
	pThis->GetEntity()->SetAlignment(alignment);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetDefaultSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetDefaultSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutOrientation orientation = static_cast<wxLayoutOrientation>(arg.GetInt(0));
	pThis->GetEntity()->SetOrientation(orientation);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Object_wx_SashLayoutWindow::~Object_wx_SashLayoutWindow()
{
}

Object *Object_wx_SashLayoutWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SashLayoutWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SashLayoutWindow:");
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
// Class implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashLayoutWindow)
{
	Gura_AssignFunction(SashLayoutWindowEmpty);
	Gura_AssignFunction(SashLayoutWindow);
	Gura_AssignMethod(wx_SashLayoutWindow, Create);
	Gura_AssignMethod(wx_SashLayoutWindow, GetAlignment);
	Gura_AssignMethod(wx_SashLayoutWindow, GetOrientation);
	Gura_AssignMethod(wx_SashLayoutWindow, OnCalculateLayout);
	Gura_AssignMethod(wx_SashLayoutWindow, OnQueryLayoutInfo);
	Gura_AssignMethod(wx_SashLayoutWindow, SetAlignment);
	Gura_AssignMethod(wx_SashLayoutWindow, SetDefaultSize);
	Gura_AssignMethod(wx_SashLayoutWindow, SetOrientation);
}

Gura_ImplementDescendantCreator(wx_SashLayoutWindow)
{
	return new Object_wx_SashLayoutWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
