//----------------------------------------------------------------------------
// wxXmlDoctype
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlDoctype
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlDoctype
//----------------------------------------------------------------------------
Object_wx_XmlDoctype::~Object_wx_XmlDoctype()
{
}

Object *Object_wx_XmlDoctype::Clone() const
{
	return nullptr;
}

String Object_wx_XmlDoctype::ToString(bool exprFlag)
{
	String rtn("<wx.XmlDoctype:");
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
Gura_DeclareMethod(wx_XmlDoctype, wxXmlDoctype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rootName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "systemId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "publicId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDoctype, wxXmlDoctype)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rootName = arg.GetNumber(0)
	//int systemId = arg.GetNumber(1)
	//int publicId = arg.GetNumber(2)
	//pThis->GetEntity()->wxXmlDoctype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDoctype, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDoctype, GetRootName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, GetRootName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRootName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDoctype, GetSystemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, GetSystemId)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSystemId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDoctype, GetPublicId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, GetPublicId)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPublicId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDoctype, GetFullString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, GetFullString)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFullString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDoctype, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlDoctype
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDoctype)
{
	Gura_AssignMethod(wx_XmlDoctype, wxXmlDoctype);
	Gura_AssignMethod(wx_XmlDoctype, Clear);
	Gura_AssignMethod(wx_XmlDoctype, GetRootName);
	Gura_AssignMethod(wx_XmlDoctype, GetSystemId);
	Gura_AssignMethod(wx_XmlDoctype, GetPublicId);
	Gura_AssignMethod(wx_XmlDoctype, GetFullString);
	Gura_AssignMethod(wx_XmlDoctype, IsValid);
}

Gura_ImplementDescendantCreator(wx_XmlDoctype)
{
	return new Object_wx_XmlDoctype((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
