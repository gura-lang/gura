//----------------------------------------------------------------------------
// wxScreenDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScreenDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScreenDC
//----------------------------------------------------------------------------
Object_wx_ScreenDC::~Object_wx_ScreenDC()
{
}

Object *Object_wx_ScreenDC::Clone() const
{
	return nullptr;
}

String Object_wx_ScreenDC::ToString(bool exprFlag)
{
	String rtn("<wx.ScreenDC:");
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
Gura_DeclareMethod(wx_ScreenDC, wxScreenDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScreenDC, wxScreenDC)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxScreenDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScreenDC, EndDrawingOnTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScreenDC, EndDrawingOnTop)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDrawingOnTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScreenDC, StartDrawingOnTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScreenDC, StartDrawingOnTop)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->StartDrawingOnTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScreenDC, StartDrawingOnTop_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScreenDC, StartDrawingOnTop_1)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->StartDrawingOnTop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScreenDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScreenDC)
{
	Gura_AssignMethod(wx_ScreenDC, wxScreenDC);
	Gura_AssignMethod(wx_ScreenDC, EndDrawingOnTop);
	Gura_AssignMethod(wx_ScreenDC, StartDrawingOnTop);
	Gura_AssignMethod(wx_ScreenDC, StartDrawingOnTop_1);
}

Gura_ImplementDescendantCreator(wx_ScreenDC)
{
	return new Object_wx_ScreenDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
