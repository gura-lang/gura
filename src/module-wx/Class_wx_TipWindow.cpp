//----------------------------------------------------------------------------
// wxTipWindow
// extracted from tipwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TipWindow: public wxTipWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TipWindow *_pObj;
public:
	//inline wx_TipWindow(wxWindow* parent, const wxString& text, wxCoord maxLength, wxTipWindow** windowPtr, wxRect * rectBounds) : wxTipWindow(parent, text, maxLength, windowPtr, rectBounds), _pObj(nullptr) {}
	~wx_TipWindow();
	inline void AssocWithGura(Object_wx_TipWindow *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TipWindow::~wx_TipWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TipWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTipWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(TipWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TipWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "maxLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "windowPtr", VTYPE_wx_TipWindow, OCCUR_Once);
	DeclareArg(env, "rectBounds", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TipWindow)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString text = wxString::FromUTF8(arg.GetString(1));
	wxCoord maxLength = 100;
	if (arg.IsValid(2)) maxLength = static_cast<wxCoord>(arg.GetInt(2));
	wxTipWindow *windowPtr = Object_wx_TipWindow::GetObject(arg, 3)->GetEntity();
	wxRect *rectBounds = (wxRect *)();
	if (arg.IsValid(4)) rectBounds = Object_wx_Rect::GetObject(arg, 4)->GetEntity();
	wx_TipWindow *pEntity = new wx_TipWindow(parent, text, maxLength, *windowPtr, rectBounds);
	Object_wx_TipWindow *pObj = Object_wx_TipWindow::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_TipWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipWindow, SetTipWindowPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "windowPtr", VTYPE_wx_TipWindow, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TipWindow, SetTipWindowPtr)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTipWindow *windowPtr = Object_wx_TipWindow::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetTipWindowPtr(*windowPtr);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipWindow, SetBoundingRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rectBound", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, SetBoundingRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rectBound = Object_wx_Rect::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetBoundingRect(*rectBound);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTipWindow
//----------------------------------------------------------------------------
Object_wx_TipWindow::~Object_wx_TipWindow()
{
}

Object *Object_wx_TipWindow::Clone() const
{
	return nullptr;
}

String Object_wx_TipWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TipWindow:");
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
// Class implementation for wxTipWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipWindow)
{
	Gura_AssignFunction(TipWindow);
	Gura_AssignMethod(wx_TipWindow, SetTipWindowPtr);
	Gura_AssignMethod(wx_TipWindow, SetBoundingRect);
}

Gura_ImplementDescendantCreator(wx_TipWindow)
{
	return new Object_wx_TipWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
