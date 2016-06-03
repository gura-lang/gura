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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__LogWindow, "LogWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pParent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "szTitle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "passToOld", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_LogWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LogWindow)
{
	//int pParent = arg.GetNumber(0)
	//int szTitle = arg.GetNumber(1)
	//int show = arg.GetNumber(2)
	//int passToOld = arg.GetNumber(3)
	//wxLogWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_LogWindow, __GetFrame, "GetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogWindow, __GetFrame)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogWindow, __OnFrameClose, "OnFrameClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, __OnFrameClose)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnFrameClose();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogWindow, __OnFrameDelete, "OnFrameDelete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, __OnFrameDelete)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//pThis->GetEntity()->OnFrameDelete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogWindow, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogWindow, __Show)
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
	// Constructor assignment
	Gura_AssignFunction(__LogWindow);
	// Method assignment
	Gura_AssignMethod(wx_LogWindow, __GetFrame);
	Gura_AssignMethod(wx_LogWindow, __OnFrameClose);
	Gura_AssignMethod(wx_LogWindow, __OnFrameDelete);
	Gura_AssignMethod(wx_LogWindow, __Show);
}

Gura_ImplementDescendantCreator(wx_LogWindow)
{
	return new Object_wx_LogWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
