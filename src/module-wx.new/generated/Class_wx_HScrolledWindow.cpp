//----------------------------------------------------------------------------
// wxHScrolledWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHScrolledWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHScrolledWindow
//----------------------------------------------------------------------------
Object_wx_HScrolledWindow::~Object_wx_HScrolledWindow()
{
}

Object *Object_wx_HScrolledWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HScrolledWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HScrolledWindow:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HScrolledWindow, "HScrolledWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HScrolledWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HScrolledWindow)
{
	//wxHScrolledWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HScrolledWindow_1, "HScrolledWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HScrolledWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HScrolledWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxHScrolledWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HScrolledWindow, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HScrolledWindow, __Create)
{
	Object_wx_HScrolledWindow *pThis = Object_wx_HScrolledWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HScrolledWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__HScrolledWindow);
	Gura_AssignFunction(__HScrolledWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_HScrolledWindow, __Create);
}

Gura_ImplementDescendantCreator(wx_HScrolledWindow)
{
	return new Object_wx_HScrolledWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
