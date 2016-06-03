//----------------------------------------------------------------------------
// wxPixelData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPixelData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPixelData
//----------------------------------------------------------------------------
Object_wx_PixelData::~Object_wx_PixelData()
{
}

Object *Object_wx_PixelData::Clone() const
{
	return nullptr;
}

String Object_wx_PixelData::ToString(bool exprFlag)
{
	String rtn("<wx.PixelData:");
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
Gura_DeclareFunctionAlias(__wxPixelData, "wxPixelData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPixelData)
{
	//int image = arg.GetNumber(0)
	//wxPixelData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPixelData_1, "wxPixelData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPixelData_1)
{
	//int i = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//wxPixelData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPixelData_2, "wxPixelData_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPixelData_2)
{
	//int i = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int sz = arg.GetNumber(2)
	//wxPixelData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PixelData, __bool, "bool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __bool)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->bool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __GetPixels, "GetPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __GetPixels)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __GetOrigin, "GetOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __GetOrigin)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __GetWidth)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __GetHeight)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __GetSize)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __GetRowStride, "GetRowStride")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __GetRowStride)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowStride();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __Reset)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Iterator, "Iterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __Iterator)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Iterator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Iterator_1, "Iterator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __Iterator_1)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Iterator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Iterator_2, "Iterator_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __Iterator_2)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Iterator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __IsOk)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Offset, "Offset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __Offset)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __OffsetX, "OffsetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __OffsetX)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __OffsetY, "OffsetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __OffsetY)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __MoveTo, "MoveTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, __MoveTo)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->MoveTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Red, "Red")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __Red)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Red();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Green, "Green")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __Green)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Green();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Blue, "Blue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __Blue)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Blue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PixelData, __Alpha, "Alpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, __Alpha)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Alpha();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPixelData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PixelData)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPixelData);
	Gura_AssignFunction(__wxPixelData_1);
	Gura_AssignFunction(__wxPixelData_2);
	// Method assignment
	Gura_AssignMethod(wx_PixelData, __bool);
	Gura_AssignMethod(wx_PixelData, __GetPixels);
	Gura_AssignMethod(wx_PixelData, __GetOrigin);
	Gura_AssignMethod(wx_PixelData, __GetWidth);
	Gura_AssignMethod(wx_PixelData, __GetHeight);
	Gura_AssignMethod(wx_PixelData, __GetSize);
	Gura_AssignMethod(wx_PixelData, __GetRowStride);
	Gura_AssignMethod(wx_PixelData, __Reset);
	Gura_AssignMethod(wx_PixelData, __Iterator);
	Gura_AssignMethod(wx_PixelData, __Iterator_1);
	Gura_AssignMethod(wx_PixelData, __Iterator_2);
	Gura_AssignMethod(wx_PixelData, __IsOk);
	Gura_AssignMethod(wx_PixelData, __Offset);
	Gura_AssignMethod(wx_PixelData, __OffsetX);
	Gura_AssignMethod(wx_PixelData, __OffsetY);
	Gura_AssignMethod(wx_PixelData, __MoveTo);
	Gura_AssignMethod(wx_PixelData, __Red);
	Gura_AssignMethod(wx_PixelData, __Green);
	Gura_AssignMethod(wx_PixelData, __Blue);
	Gura_AssignMethod(wx_PixelData, __Alpha);
}

Gura_ImplementDescendantCreator(wx_PixelData)
{
	return new Object_wx_PixelData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
