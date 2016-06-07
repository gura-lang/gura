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
Gura_DeclareFunctionAlias(__PixelData, "PixelData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PixelData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PixelData)
{
	//Image& image = arg.GetNumber(0)
	//wxPixelData(image);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PixelData_1, "PixelData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PixelData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PixelData_1)
{
	//Image& i = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//wxPixelData(i, rect);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PixelData_2, "PixelData_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PixelData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PixelData_2)
{
	//Image& i = arg.GetNumber(0)
	//const wxPoint& pt = arg.GetNumber(1)
	//const wxSize& sz = arg.GetNumber(2)
	//wxPixelData(i, pt, sz);
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
	//const PixelData& data = arg.GetNumber(0)
	//pThis->GetEntity()->Reset(data);
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
	//PixelData& data = arg.GetNumber(0)
	//pThis->GetEntity()->Iterator(data);
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
	//wxBitmap& bmp = arg.GetNumber(0)
	//PixelData& data = arg.GetNumber(1)
	//pThis->GetEntity()->Iterator(bmp, data);
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
	//const PixelData& data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->Offset(data, x, y);
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
	//const PixelData& data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetX(data, x);
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
	//const PixelData& data = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetY(data, y);
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
	//const PixelData& data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->MoveTo(data, x, y);
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
	Gura_AssignFunction(__PixelData);
	Gura_AssignFunction(__PixelData_1);
	Gura_AssignFunction(__PixelData_2);
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
