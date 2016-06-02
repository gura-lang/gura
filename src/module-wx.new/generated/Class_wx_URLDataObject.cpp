//----------------------------------------------------------------------------
// wxURLDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxURLDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxURLDataObject
//----------------------------------------------------------------------------
Object_wx_URLDataObject::~Object_wx_URLDataObject()
{
}

Object *Object_wx_URLDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_URLDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.URLDataObject:");
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
Gura_DeclareMethod(wx_URLDataObject, wxURLDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URLDataObject, wxURLDataObject)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->wxURLDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URLDataObject, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URLDataObject, GetURL)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_URLDataObject, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URLDataObject, SetURL)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxURLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URLDataObject)
{
	Gura_AssignMethod(wx_URLDataObject, wxURLDataObject);
	Gura_AssignMethod(wx_URLDataObject, GetURL);
	Gura_AssignMethod(wx_URLDataObject, SetURL);
}

Gura_ImplementDescendantCreator(wx_URLDataObject)
{
	return new Object_wx_URLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
