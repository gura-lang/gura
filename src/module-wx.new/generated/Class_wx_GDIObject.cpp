//----------------------------------------------------------------------------
// wxGDIObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGDIObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGDIObject
//----------------------------------------------------------------------------
Object_wx_GDIObject::~Object_wx_GDIObject()
{
}

Object *Object_wx_GDIObject::Clone() const
{
	return nullptr;
}

String Object_wx_GDIObject::ToString(bool exprFlag)
{
	String rtn("<wx.GDIObject:");
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
Gura_DeclareMethod(wx_GDIObject, wxGDIObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GDIObject, wxGDIObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_GDIObject *pThis = Object_wx_GDIObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGDIObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGDIObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GDIObject)
{
	Gura_AssignMethod(wx_GDIObject, wxGDIObject);
}

Gura_ImplementDescendantCreator(wx_GDIObject)
{
	return new Object_wx_GDIObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
