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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__XmlDoctype, "XmlDoctype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rootName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "systemId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "publicId", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlDoctype));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlDoctype)
{
	//const wxString& rootName = arg.GetNumber(0)
	//const wxString& systemId = arg.GetNumber(1)
	//const wxString& publicId = arg.GetNumber(2)
	//wxXmlDoctype(rootName, systemId, publicId);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XmlDoctype, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, __Clear)
{
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDoctype, __GetRootName, "GetRootName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, __GetRootName)
{
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetRootName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDoctype, __GetSystemId, "GetSystemId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, __GetSystemId)
{
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetSystemId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDoctype, __GetPublicId, "GetPublicId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, __GetPublicId)
{
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetPublicId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDoctype, __GetFullString, "GetFullString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, __GetFullString)
{
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetFullString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDoctype, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDoctype, __IsValid)
{
	Object_wx_XmlDoctype *pThis = Object_wx_XmlDoctype::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlDoctype
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDoctype)
{
	// Constructor assignment
	Gura_AssignFunction(__XmlDoctype);
	// Method assignment
	Gura_AssignMethod(wx_XmlDoctype, __Clear);
	Gura_AssignMethod(wx_XmlDoctype, __GetRootName);
	Gura_AssignMethod(wx_XmlDoctype, __GetSystemId);
	Gura_AssignMethod(wx_XmlDoctype, __GetPublicId);
	Gura_AssignMethod(wx_XmlDoctype, __GetFullString);
	Gura_AssignMethod(wx_XmlDoctype, __IsValid);
}

Gura_ImplementDescendantCreator(wx_XmlDoctype)
{
	return new Object_wx_XmlDoctype((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
