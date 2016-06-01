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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BitmapDataObject, wxBitmapDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapDataObject, wxBitmapDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->wxBitmapDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapDataObject, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapDataObject, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapDataObject, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapDataObject, SetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapDataObject *pThis = Object_wx_BitmapDataObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapDataObject)
{
	Gura_AssignMethod(wx_BitmapDataObject, wxBitmapDataObject);
	Gura_AssignMethod(wx_BitmapDataObject, GetBitmap);
	Gura_AssignMethod(wx_BitmapDataObject, SetBitmap);
}

Gura_ImplementDescendantCreator(wx_BitmapDataObject)
{
	return new Object_wx_BitmapDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
