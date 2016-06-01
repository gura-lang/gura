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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_XmlAttribute, wxXmlAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, wxXmlAttribute)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxXmlAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, wxXmlAttribute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, wxXmlAttribute_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//int next = arg.GetNumber(2)
	//pThis->GetEntity()->wxXmlAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, ~wxXmlAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, ~wxXmlAttribute)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxXmlAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlAttribute, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int next = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlAttribute, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlAttribute, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlAttribute *pThis = Object_wx_XmlAttribute::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlAttribute
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlAttribute)
{
	Gura_AssignMethod(wx_XmlAttribute, wxXmlAttribute);
	Gura_AssignMethod(wx_XmlAttribute, wxXmlAttribute_1);
	Gura_AssignMethod(wx_XmlAttribute, ~wxXmlAttribute);
	Gura_AssignMethod(wx_XmlAttribute, GetName);
	Gura_AssignMethod(wx_XmlAttribute, GetNext);
	Gura_AssignMethod(wx_XmlAttribute, GetValue);
	Gura_AssignMethod(wx_XmlAttribute, SetName);
	Gura_AssignMethod(wx_XmlAttribute, SetNext);
	Gura_AssignMethod(wx_XmlAttribute, SetValue);
}

Gura_ImplementDescendantCreator(wx_XmlAttribute)
{
	return new Object_wx_XmlAttribute((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
