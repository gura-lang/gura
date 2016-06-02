//----------------------------------------------------------------------------
// wxImage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxImage
//----------------------------------------------------------------------------
Object_wx_Image::~Object_wx_Image()
{
}

Object *Object_wx_Image::Clone() const
{
	return nullptr;
}

String Object_wx_Image::ToString(bool exprFlag)
{
	String rtn("<wx.Image:");
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
Gura_DeclareMethod(wx_Image, RGBValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Image, RGBValue)
{
	Object_wx_Image *pThis = Object_wx_Image::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//pThis->GetEntity()->RGBValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Image)
{
	Gura_AssignMethod(wx_Image, RGBValue);
}

Gura_ImplementDescendantCreator(wx_Image)
{
	return new Object_wx_Image((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
