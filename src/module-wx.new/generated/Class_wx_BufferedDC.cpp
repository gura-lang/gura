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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BufferedDC, wxBufferedDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, wxBufferedDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, wxBufferedDC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "area", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, wxBufferedDC_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int area = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, wxBufferedDC_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, wxBufferedDC_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, ~wxBufferedDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, ~wxBufferedDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxBufferedDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "area", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int area = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, Init_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, Init_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, UnMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, UnMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedDC, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedDC, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedDC, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedDC *pThis = Object_wx_BufferedDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedDC)
{
	Gura_AssignMethod(wx_BufferedDC, wxBufferedDC);
	Gura_AssignMethod(wx_BufferedDC, wxBufferedDC_1);
	Gura_AssignMethod(wx_BufferedDC, wxBufferedDC_2);
	Gura_AssignMethod(wx_BufferedDC, ~wxBufferedDC);
	Gura_AssignMethod(wx_BufferedDC, Init);
	Gura_AssignMethod(wx_BufferedDC, Init_1);
	Gura_AssignMethod(wx_BufferedDC, UnMask);
	Gura_AssignMethod(wx_BufferedDC, SetStyle);
	Gura_AssignMethod(wx_BufferedDC, GetStyle);
}

Gura_ImplementDescendantCreator(wx_BufferedDC)
{
	return new Object_wx_BufferedDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
