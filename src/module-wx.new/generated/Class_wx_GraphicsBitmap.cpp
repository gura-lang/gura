//----------------------------------------------------------------------------
// wxGraphicsBitmap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsBitmap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsBitmap
//----------------------------------------------------------------------------
Object_wx_GraphicsBitmap::~Object_wx_GraphicsBitmap()
{
}

Object *Object_wx_GraphicsBitmap::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsBitmap::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsBitmap:");
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
Gura_DeclareMethod(wx_GraphicsBitmap, wxGraphicsBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsBitmap, wxGraphicsBitmap)
{
	Object_wx_GraphicsBitmap *pThis = Object_wx_GraphicsBitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGraphicsBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsBitmap, ConvertToImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsBitmap, ConvertToImage)
{
	Object_wx_GraphicsBitmap *pThis = Object_wx_GraphicsBitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ConvertToImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsBitmap, GetNativeBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsBitmap, GetNativeBitmap)
{
	Object_wx_GraphicsBitmap *pThis = Object_wx_GraphicsBitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativeBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsBitmap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsBitmap)
{
	Gura_AssignMethod(wx_GraphicsBitmap, wxGraphicsBitmap);
	Gura_AssignMethod(wx_GraphicsBitmap, ConvertToImage);
	Gura_AssignMethod(wx_GraphicsBitmap, GetNativeBitmap);
}

Gura_ImplementDescendantCreator(wx_GraphicsBitmap)
{
	return new Object_wx_GraphicsBitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
