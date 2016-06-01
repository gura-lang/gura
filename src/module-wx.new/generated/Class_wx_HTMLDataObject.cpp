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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HTMLDataObject, wxHTMLDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTMLDataObject, wxHTMLDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_HTMLDataObject *pThis = Object_wx_HTMLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int html = arg.GetNumber(0)
	//pThis->GetEntity()->wxHTMLDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTMLDataObject, GetHTML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTMLDataObject, GetHTML)
{
	Signal &sig = env.GetSignal();
	Object_wx_HTMLDataObject *pThis = Object_wx_HTMLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHTML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTMLDataObject, SetHTML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTMLDataObject, SetHTML)
{
	Signal &sig = env.GetSignal();
	Object_wx_HTMLDataObject *pThis = Object_wx_HTMLDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int html = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTML();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHTMLDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTMLDataObject)
{
	Gura_AssignMethod(wx_HTMLDataObject, wxHTMLDataObject);
	Gura_AssignMethod(wx_HTMLDataObject, GetHTML);
	Gura_AssignMethod(wx_HTMLDataObject, SetHTML);
}

Gura_ImplementDescendantCreator(wx_HTMLDataObject)
{
	return new Object_wx_HTMLDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
