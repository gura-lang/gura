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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRichTextObjectAddress, "wxRichTextObjectAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLevelContainer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextObjectAddress));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextObjectAddress)
{
	//int topLevelContainer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//wxRichTextObjectAddress();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextObjectAddress_1, "wxRichTextObjectAddress_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextObjectAddress));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextObjectAddress_1)
{
	//wxRichTextObjectAddress();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextObjectAddress_2, "wxRichTextObjectAddress_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextObjectAddress));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextObjectAddress_2)
{
	//int address = arg.GetNumber(0)
	//wxRichTextObjectAddress();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __Init)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __Copy)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLevelContainer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __GetObject)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topLevelContainer = arg.GetNumber(0)
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLevelContainer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __Create)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topLevelContainer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __GetAddress, "GetAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __GetAddress)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __GetAddress_1, "GetAddress_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __GetAddress_1)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObjectAddress, __SetAddress, "SetAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObjectAddress, __SetAddress)
{
	Object_wx_RichTextObjectAddress *pThis = Object_wx_RichTextObjectAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->SetAddress();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextObjectAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObjectAddress)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextObjectAddress);
	Gura_AssignFunction(__wxRichTextObjectAddress_1);
	Gura_AssignFunction(__wxRichTextObjectAddress_2);
	// Method assignment
	Gura_AssignMethod(wx_RichTextObjectAddress, __Init);
	Gura_AssignMethod(wx_RichTextObjectAddress, __Copy);
	Gura_AssignMethod(wx_RichTextObjectAddress, __GetObject);
	Gura_AssignMethod(wx_RichTextObjectAddress, __Create);
	Gura_AssignMethod(wx_RichTextObjectAddress, __GetAddress);
	Gura_AssignMethod(wx_RichTextObjectAddress, __GetAddress_1);
	Gura_AssignMethod(wx_RichTextObjectAddress, __SetAddress);
}

Gura_ImplementDescendantCreator(wx_RichTextObjectAddress)
{
	return new Object_wx_RichTextObjectAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
