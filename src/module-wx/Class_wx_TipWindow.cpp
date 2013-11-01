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
	Gura::Signal _sig;
	Object_wx_TipWindow *_pObj;
public:
	//inline wx_TipWindow(wxWindow* parent, const wxString& text, wxCoord maxLength, wxTipWindow** windowPtr, wxRect * rectBounds) : wxTipWindow(parent, text, maxLength, windowPtr, rectBounds), _sig(NULL), _pObj(NULL) {}
	~wx_TipWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TipWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TipWindow::~wx_TipWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TipWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTipWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(TipWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxCoord maxLength = 100;
	if (args.IsValid(2)) maxLength = static_cast<wxCoord>(args.GetInt(2));
	wxTipWindow *windowPtr = Object_wx_TipWindow::GetObject(args, 3)->GetEntity();
	wxRect *rectBounds = (wxRect *)();
	if (args.IsValid(4)) rectBounds = Object_wx_Rect::GetObject(args, 4)->GetEntity();
	wx_TipWindow *pEntity = new wx_TipWindow(parent, text, maxLength, *windowPtr, rectBounds);
	Object_wx_TipWindow *pObj = Object_wx_TipWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TipWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TipWindow, SetTipWindowPtr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "windowPtr", VTYPE_wx_TipWindow, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TipWindow, SetTipWindowPtr)
{
#if 0
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTipWindow *windowPtr = Object_wx_TipWindow::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTipWindowPtr(*windowPtr);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TipWindow, SetBoundingRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rectBound", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipWindow, SetBoundingRect)
{
	Object_wx_TipWindow *pThis = Object_wx_TipWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rectBound = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBoundingRect(*rectBound);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTipWindow
//----------------------------------------------------------------------------
Object_wx_TipWindow::~Object_wx_TipWindow()
{
}

Object *Object_wx_TipWindow::Clone() const
{
	return NULL;
}

String Object_wx_TipWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TipWindow:");
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
	return new Object_wx_TipWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
