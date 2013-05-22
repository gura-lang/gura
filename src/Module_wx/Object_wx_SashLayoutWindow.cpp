//----------------------------------------------------------------------------
// wxSashLayoutWindow
// extracted from sashlayw.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SashLayoutWindow: public wxSashLayoutWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SashLayoutWindow *_pObj;
public:
	inline wx_SashLayoutWindow() : wxSashLayoutWindow(), _sig(NULL), _pObj(NULL) {}
	inline wx_SashLayoutWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxSashLayoutWindow(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_SashLayoutWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SashLayoutWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SashLayoutWindow::~wx_SashLayoutWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SashLayoutWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(SashLayoutWindowEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SashLayoutWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SashLayoutWindowEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SashLayoutWindow *pEntity = new wx_SashLayoutWindow();
	Object_wx_SashLayoutWindow *pObj = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SashLayoutWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(SashLayoutWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxCLIP_CHILDREN | wxSW_3D;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("layoutWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_SashLayoutWindow *pEntity = new wx_SashLayoutWindow(parent, id, *pos, *size, style, name);
	Object_wx_SashLayoutWindow *pObj = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SashLayoutWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SashLayoutWindow, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxCLIP_CHILDREN | wxSW_3D;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("layoutWindow");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashLayoutWindow, GetAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashLayoutWindow, GetAlignment)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutAlignment rtn = pThis->GetEntity()->GetAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashLayoutWindow, GetOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SashLayoutWindow, GetOrientation)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutOrientation rtn = pThis->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SashLayoutWindow, OnCalculateLayout)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CalculateLayoutEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, OnCalculateLayout)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCalculateLayoutEvent *event = Object_wx_CalculateLayoutEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnCalculateLayout(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashLayoutWindow, OnQueryLayoutInfo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_QueryLayoutInfoEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, OnQueryLayoutInfo)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxQueryLayoutInfoEvent *event = Object_wx_QueryLayoutInfoEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnQueryLayoutInfo(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetAlignment)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetAlignment)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutAlignment alignment = static_cast<wxLayoutAlignment>(args.GetInt(0));
	pThis->GetEntity()->SetAlignment(alignment);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetDefaultSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetDefaultSize)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_SashLayoutWindow, SetOrientation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashLayoutWindow, SetOrientation)
{
	Object_wx_SashLayoutWindow *pThis = Object_wx_SashLayoutWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutOrientation orientation = static_cast<wxLayoutOrientation>(args.GetInt(0));
	pThis->GetEntity()->SetOrientation(orientation);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Object_wx_SashLayoutWindow::~Object_wx_SashLayoutWindow()
{
}

Object *Object_wx_SashLayoutWindow::Clone() const
{
	return NULL;
}

String Object_wx_SashLayoutWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SashLayoutWindow:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SashLayoutWindow::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(SashLayoutWindowEmpty);
	Gura_AssignFunction(SashLayoutWindow);
}

//----------------------------------------------------------------------------
// Class implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashLayoutWindow)
{
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
	return new Object_wx_SashLayoutWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
