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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_NativeWindow, wxNativeWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeWindow, wxNativeWindow)
{
	Object_wx_NativeWindow *pThis = Object_wx_NativeWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxNativeWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeWindow, wxNativeWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NativeWindow, wxNativeWindow_1)
{
	Object_wx_NativeWindow *pThis = Object_wx_NativeWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int parent = arg.GetNumber(2)
	//int winid = arg.GetNumber(3)
	//int handle = arg.GetNumber(4)
	//pThis->GetEntity()->wxNativeWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NativeWindow, Disown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NativeWindow, Disown)
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
	Gura_AssignMethod(wx_NativeWindow, wxNativeWindow);
	Gura_AssignMethod(wx_NativeWindow, wxNativeWindow_1);
	Gura_AssignMethod(wx_NativeWindow, Disown);
}

Gura_ImplementDescendantCreator(wx_NativeWindow)
{
	return new Object_wx_NativeWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
