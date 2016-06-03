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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__URLDataObject, "URLDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_URLDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__URLDataObject)
{
	//const wxString& url = arg.GetNumber(0)
	//wxURLDataObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_URLDataObject, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_URLDataObject, __GetURL)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_URLDataObject, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_URLDataObject, __SetURL)
{
	Object_wx_URLDataObject *pThis = Object_wx_URLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxURLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URLDataObject)
{
	// Constructor assignment
	Gura_AssignFunction(__URLDataObject);
	// Method assignment
	Gura_AssignMethod(wx_URLDataObject, __GetURL);
	Gura_AssignMethod(wx_URLDataObject, __SetURL);
}

Gura_ImplementDescendantCreator(wx_URLDataObject)
{
	return new Object_wx_URLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
