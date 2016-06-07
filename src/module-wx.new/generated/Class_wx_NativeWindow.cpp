//----------------------------------------------------------------------------
// wxNativeWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeWindow
//----------------------------------------------------------------------------
Object_wx_NativeWindow::~Object_wx_NativeWindow()
{
}

Object *Object_wx_NativeWindow::Clone() const
{
	return nullptr;
}

String Object_wx_NativeWindow::ToString(bool exprFlag)
{
	String rtn("<wx.NativeWindow:");
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
Gura_DeclareFunctionAlias(__NativeWindow, "NativeWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_NativeWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__NativeWindow)
{
	//wxNativeWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__NativeWindow_1, "NativeWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_NativeWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__NativeWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//wxNativeWindowHandle handle)  bool Create(wxWindow* parent = arg.GetNumber(2)
	//wxWindowID winid = arg.GetNumber(3)
	//wxNativeWindowHandle handle = arg.GetNumber(4)
	//wxNativeWindow(parent, winid, parent, winid, handle);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_NativeWindow, __Disown, "Disown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeWindow, __Disown)
{
	Object_wx_NativeWindow *pThis = Object_wx_NativeWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Disown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNativeWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__NativeWindow);
	Gura_AssignFunction(__NativeWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_NativeWindow, __Disown);
}

Gura_ImplementDescendantCreator(wx_NativeWindow)
{
	return new Object_wx_NativeWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
