//----------------------------------------------------------------------------
// wxXmlAttribute
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlAttribute
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Object_wx_XmlAttribute::~Object_wx_XmlAttribute()
{
}

Object *Object_wx_XmlAttribute::Clone() const
{
	return nullptr;
}

String Object_wx_XmlAttribute::ToString(bool exprFlag)
{
	String rtn("<wx.XmlAttribute:");
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
Gura_DeclareFunctionAlias(__XmlAttribute, "XmlAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlAttribute));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlAttribute)
{
	//wxXmlAttribute();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__XmlAttribute_1, "XmlAttribute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlAttribute));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlAttribute_1)
{
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//int next = arg.GetNumber(2)
	//wxXmlAttribute();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XmlAttribute, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, __GetName)
{
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlAttribute, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, __GetNext)
{
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlAttribute, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, __GetValue)
{
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlAttribute, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, __SetName)
{
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlAttribute, __SetNext, "SetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, __SetNext)
{
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int next = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlAttribute, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, __SetValue)
{
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlAttribute)
{
	// Constructor assignment
	Gura_AssignFunction(__XmlAttribute);
	Gura_AssignFunction(__XmlAttribute_1);
	// Method assignment
	Gura_AssignMethod(wx_XmlAttribute, __GetName);
	Gura_AssignMethod(wx_XmlAttribute, __GetNext);
	Gura_AssignMethod(wx_XmlAttribute, __GetValue);
	Gura_AssignMethod(wx_XmlAttribute, __SetName);
	Gura_AssignMethod(wx_XmlAttribute, __SetNext);
	Gura_AssignMethod(wx_XmlAttribute, __SetValue);
}

Gura_ImplementDescendantCreator(wx_XmlAttribute)
{
	return new Object_wx_XmlAttribute((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
