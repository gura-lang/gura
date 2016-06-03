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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxGraphicsBitmap, "wxGraphicsBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxGraphicsBitmap)
{
	//wxGraphicsBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GraphicsBitmap, __ConvertToImage, "ConvertToImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsBitmap, __ConvertToImage)
{
	Object_wx_GraphicsBitmap *pThis = Object_wx_GraphicsBitmap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ConvertToImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsBitmap, __GetNativeBitmap, "GetNativeBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsBitmap, __GetNativeBitmap)
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
	// Constructor assignment
	Gura_AssignFunction(__wxGraphicsBitmap);
	// Method assignment
	Gura_AssignMethod(wx_GraphicsBitmap, __ConvertToImage);
	Gura_AssignMethod(wx_GraphicsBitmap, __GetNativeBitmap);
}

Gura_ImplementDescendantCreator(wx_GraphicsBitmap)
{
	return new Object_wx_GraphicsBitmap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
