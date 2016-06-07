//----------------------------------------------------------------------------
// wxHTMLDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHTMLDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHTMLDataObject
//----------------------------------------------------------------------------
Object_wx_HTMLDataObject::~Object_wx_HTMLDataObject()
{
}

Object *Object_wx_HTMLDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_HTMLDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.HTMLDataObject:");
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
Gura_DeclareFunctionAlias(__HTMLDataObject, "HTMLDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HTMLDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HTMLDataObject)
{
	//const wxString& html = arg.GetNumber(0)
	//wxHTMLDataObject(html);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HTMLDataObject, __GetHTML, "GetHTML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTMLDataObject, __GetHTML)
{
	Object_wx_HTMLDataObject *pThis = Object_wx_HTMLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHTML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTMLDataObject, __SetHTML, "SetHTML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTMLDataObject, __SetHTML)
{
	Object_wx_HTMLDataObject *pThis = Object_wx_HTMLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& html = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTML(html);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHTMLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTMLDataObject)
{
	// Constructor assignment
	Gura_AssignFunction(__HTMLDataObject);
	// Method assignment
	Gura_AssignMethod(wx_HTMLDataObject, __GetHTML);
	Gura_AssignMethod(wx_HTMLDataObject, __SetHTML);
}

Gura_ImplementDescendantCreator(wx_HTMLDataObject)
{
	return new Object_wx_HTMLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
