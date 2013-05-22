//----------------------------------------------------------------------------
// wxPopupWindow
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PopupWindow: public wxPopupWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PopupWindow *_pObj;
public:
	~wx_PopupWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PopupWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PopupWindow::~wx_PopupWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PopupWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPopupWindow
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PopupWindow, Position)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ptOrigin", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_PopupWindow, Position)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *ptOrigin = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->wxPopupWindow::Position(*ptOrigin, *size);
	return Value::Null;
}

Gura_DeclareMethod(wx_PopupWindow, IsTopLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PopupWindow, IsTopLevel)
{
	Object_wx_PopupTransientWindow *pThis = Object_wx_PopupTransientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxPopupWindow::IsTopLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPopupWindow
//----------------------------------------------------------------------------
Object_wx_PopupWindow::~Object_wx_PopupWindow()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_PopupWindow::Clone() const
{
	return NULL;
}

String Object_wx_PopupWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PopupWindow:");
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
// Class implementation for wxPopupWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PopupWindow)
{
	Gura_AssignMethod(wx_PopupWindow, Position);
	Gura_AssignMethod(wx_PopupWindow, IsTopLevel);
}

Gura_ImplementDescendantCreator(wx_PopupWindow)
{
	return new Object_wx_PopupWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
