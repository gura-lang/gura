//----------------------------------------------------------------------------
// wxHVScrolledWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHVScrolledWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHVScrolledWindow
//----------------------------------------------------------------------------
Object_wx_HVScrolledWindow::~Object_wx_HVScrolledWindow()
{
}

Object *Object_wx_HVScrolledWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HVScrolledWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HVScrolledWindow:");
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
Gura_DeclareMethod(wx_HVScrolledWindow, wxHVScrolledWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HVScrolledWindow, wxHVScrolledWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HVScrolledWindow *pThis = Object_wx_HVScrolledWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxHVScrolledWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HVScrolledWindow, wxHVScrolledWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HVScrolledWindow, wxHVScrolledWindow_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HVScrolledWindow *pThis = Object_wx_HVScrolledWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxHVScrolledWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HVScrolledWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HVScrolledWindow, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_HVScrolledWindow *pThis = Object_wx_HVScrolledWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHVScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HVScrolledWindow)
{
	Gura_AssignMethod(wx_HVScrolledWindow, wxHVScrolledWindow);
	Gura_AssignMethod(wx_HVScrolledWindow, wxHVScrolledWindow_1);
	Gura_AssignMethod(wx_HVScrolledWindow, Create);
}

Gura_ImplementDescendantCreator(wx_HVScrolledWindow)
{
	return new Object_wx_HVScrolledWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
