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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GDIObject, "GDIObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GDIObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GDIObject)
{
	//wxGDIObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGDIObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GDIObject)
{
	// Constructor assignment
	Gura_AssignFunction(__GDIObject);
}

Gura_ImplementDescendantCreator(wx_GDIObject)
{
	return new Object_wx_GDIObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
