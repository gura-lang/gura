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
Gura_DeclareFunctionAlias(__BufferedDC, "BufferedDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedDC)
{
	//wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BufferedDC_1, "BufferedDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "area", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedDC_1)
{
	//wxDC* dc = arg.GetNumber(0)
	//const wxSize& area = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxBufferedDC(dc, area, style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BufferedDC_2, "BufferedDC_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedDC_2)
{
	//wxDC* dc = arg.GetNumber(0)
	//wxBitmap& buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxBufferedDC(dc, buffer, style);
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
	//wxDC* dc = arg.GetNumber(0)
	//const wxSize& area = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->Init(dc, area, style);
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
	//wxDC* dc = arg.GetNumber(0)
	//wxBitmap& buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->Init(dc, buffer, style);
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
	//pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BufferedDC, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, __GetStyle)
{
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedDC)
{
	// Constructor assignment
	Gura_AssignFunction(__BufferedDC);
	Gura_AssignFunction(__BufferedDC_1);
	Gura_AssignFunction(__BufferedDC_2);
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
