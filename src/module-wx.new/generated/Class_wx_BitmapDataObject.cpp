//----------------------------------------------------------------------------
// wxBitmapDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Object_wx_BitmapDataObject::~Object_wx_BitmapDataObject()
{
}

Object *Object_wx_BitmapDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapDataObject:");
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
Gura_DeclareFunctionAlias(__BitmapDataObject, "BitmapDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BitmapDataObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapDataObject)
{
	//int bitmap = arg.GetNumber(0)
	//wxBitmapDataObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BitmapDataObject, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapDataObject, __GetBitmap)
{
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapDataObject, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapDataObject, __SetBitmap)
{
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapDataObject)
{
	// Constructor assignment
	Gura_AssignFunction(__BitmapDataObject);
	// Method assignment
	Gura_AssignMethod(wx_BitmapDataObject, __GetBitmap);
	Gura_AssignMethod(wx_BitmapDataObject, __SetBitmap);
}

Gura_ImplementDescendantCreator(wx_BitmapDataObject)
{
	return new Object_wx_BitmapDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
