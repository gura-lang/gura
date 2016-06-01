//----------------------------------------------------------------------------
// wxRichTextObjectAddress
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextObjectAddress
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextObjectAddress
//----------------------------------------------------------------------------
Object_wx_RichTextObjectAddress::~Object_wx_RichTextObjectAddress()
{
}

Object *Object_wx_RichTextObjectAddress::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextObjectAddress::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextObjectAddress:");
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
Gura_DeclareMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLevelContainer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topLevelContainer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextObjectAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextObjectAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextObjectAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, operator=)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLevelContainer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, GetObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topLevelContainer = arg.GetNumber(0)
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLevelContainer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topLevelContainer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, GetAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, GetAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, GetAddress_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, GetAddress_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObjectAddress, SetAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, SetAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->SetAddress();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextObjectAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObjectAddress)
{
	Gura_AssignMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress);
	Gura_AssignMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress_1);
	Gura_AssignMethod(wx_RichTextObjectAddress, wxRichTextObjectAddress_2);
	Gura_AssignMethod(wx_RichTextObjectAddress, Init);
	Gura_AssignMethod(wx_RichTextObjectAddress, Copy);
	Gura_AssignMethod(wx_RichTextObjectAddress, operator=);
	Gura_AssignMethod(wx_RichTextObjectAddress, GetObject);
	Gura_AssignMethod(wx_RichTextObjectAddress, Create);
	Gura_AssignMethod(wx_RichTextObjectAddress, GetAddress);
	Gura_AssignMethod(wx_RichTextObjectAddress, GetAddress_1);
	Gura_AssignMethod(wx_RichTextObjectAddress, SetAddress);
}

Gura_ImplementDescendantCreator(wx_RichTextObjectAddress)
{
	return new Object_wx_RichTextObjectAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
