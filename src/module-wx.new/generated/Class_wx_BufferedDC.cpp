//----------------------------------------------------------------------------
// wxBufferedDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedDC
//----------------------------------------------------------------------------
Object_wx_BufferedDC::~Object_wx_BufferedDC()
{
}

Object *Object_wx_BufferedDC::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedDC::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedDC:");
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
Gura_DeclareFunctionAlias(__wxBufferedDC, "wxBufferedDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxBufferedDC)
{
	//wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxBufferedDC_1, "wxBufferedDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "area", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxBufferedDC_1)
{
	//int dc = arg.GetNumber(0)
	//int area = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxBufferedDC_2, "wxBufferedDC_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxBufferedDC_2)
{
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxBufferedDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BufferedDC, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "area", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, __Init)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int area = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedDC, __Init_1, "Init_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, __Init_1)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedDC, __UnMask, "UnMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, __UnMask)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedDC, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, __SetStyle)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedDC, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, __GetStyle)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedDC)
{
	// Constructor assignment
	Gura_AssignFunction(__wxBufferedDC);
	Gura_AssignFunction(__wxBufferedDC_1);
	Gura_AssignFunction(__wxBufferedDC_2);
	// Method assignment
	Gura_AssignMethod(wx_BufferedDC, __Init);
	Gura_AssignMethod(wx_BufferedDC, __Init_1);
	Gura_AssignMethod(wx_BufferedDC, __UnMask);
	Gura_AssignMethod(wx_BufferedDC, __SetStyle);
	Gura_AssignMethod(wx_BufferedDC, __GetStyle);
}

Gura_ImplementDescendantCreator(wx_BufferedDC)
{
	return new Object_wx_BufferedDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
