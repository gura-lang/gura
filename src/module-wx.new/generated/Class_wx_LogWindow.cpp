//----------------------------------------------------------------------------
// wxLogWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogWindow
//----------------------------------------------------------------------------
Object_wx_LogWindow::~Object_wx_LogWindow()
{
}

Object *Object_wx_LogWindow::Clone() const
{
	return nullptr;
}

String Object_wx_LogWindow::ToString(bool exprFlag)
{
	String rtn("<wx.LogWindow:");
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
Gura_DeclareMethod(wx_LogWindow, wxLogWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "szTitle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "passToOld", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, wxLogWindow)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pParent = arg.GetNumber(0)
	//int szTitle = arg.GetNumber(1)
	//int show = arg.GetNumber(2)
	//int passToOld = arg.GetNumber(3)
	//pThis->GetEntity()->wxLogWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogWindow, GetFrame)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, OnFrameClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, OnFrameClose)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnFrameClose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, OnFrameDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, OnFrameDelete)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnFrameDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, Show)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogWindow)
{
	Gura_AssignMethod(wx_LogWindow, wxLogWindow);
	Gura_AssignMethod(wx_LogWindow, GetFrame);
	Gura_AssignMethod(wx_LogWindow, OnFrameClose);
	Gura_AssignMethod(wx_LogWindow, OnFrameDelete);
	Gura_AssignMethod(wx_LogWindow, Show);
}

Gura_ImplementDescendantCreator(wx_LogWindow)
{
	return new Object_wx_LogWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
