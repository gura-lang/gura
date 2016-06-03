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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ScreenDC, "ScreenDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScreenDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScreenDC)
{
	//wxScreenDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ScreenDC, __EndDrawingOnTop, "EndDrawingOnTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScreenDC, __EndDrawingOnTop)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDrawingOnTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScreenDC, __StartDrawingOnTop, "StartDrawingOnTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScreenDC, __StartDrawingOnTop)
{
	Object_wx_ScreenDC *pThis = Object_wx_ScreenDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->StartDrawingOnTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScreenDC, __StartDrawingOnTop_1, "StartDrawingOnTop_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScreenDC, __StartDrawingOnTop_1)
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
	// Constructor assignment
	Gura_AssignFunction(__ScreenDC);
	// Method assignment
	Gura_AssignMethod(wx_ScreenDC, __EndDrawingOnTop);
	Gura_AssignMethod(wx_ScreenDC, __StartDrawingOnTop);
	Gura_AssignMethod(wx_ScreenDC, __StartDrawingOnTop_1);
}

Gura_ImplementDescendantCreator(wx_ScreenDC)
{
	return new Object_wx_ScreenDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
