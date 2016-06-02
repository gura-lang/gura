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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PixelData, wxPixelData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, wxPixelData)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->wxPixelData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, wxPixelData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, wxPixelData_1)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->wxPixelData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, wxPixelData_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, wxPixelData_2)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int sz = arg.GetNumber(2)
	//pThis->GetEntity()->wxPixelData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, bool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, bool)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->bool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, GetPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, GetPixels)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, GetOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, GetOrigin)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, GetWidth)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, GetHeight)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, GetSize)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, GetRowStride)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, GetRowStride)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowStride();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, Reset)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Iterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, Iterator)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Iterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Iterator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, Iterator_1)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Iterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Iterator_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, Iterator_2)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Iterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, IsOk)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, Offset)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, OffsetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, OffsetX)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, OffsetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, OffsetY)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OffsetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, MoveTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PixelData, MoveTo)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->MoveTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Red)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, Red)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Red();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Green)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, Green)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Green();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Blue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, Blue)
{
	Object_wx_PixelData *pThis = Object_wx_PixelData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Blue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PixelData, Alpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PixelData, Alpha)
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
	Gura_AssignMethod(wx_PixelData, wxPixelData);
	Gura_AssignMethod(wx_PixelData, wxPixelData_1);
	Gura_AssignMethod(wx_PixelData, wxPixelData_2);
	Gura_AssignMethod(wx_PixelData, bool);
	Gura_AssignMethod(wx_PixelData, GetPixels);
	Gura_AssignMethod(wx_PixelData, GetOrigin);
	Gura_AssignMethod(wx_PixelData, GetWidth);
	Gura_AssignMethod(wx_PixelData, GetHeight);
	Gura_AssignMethod(wx_PixelData, GetSize);
	Gura_AssignMethod(wx_PixelData, GetRowStride);
	Gura_AssignMethod(wx_PixelData, Reset);
	Gura_AssignMethod(wx_PixelData, Iterator);
	Gura_AssignMethod(wx_PixelData, Iterator_1);
	Gura_AssignMethod(wx_PixelData, Iterator_2);
	Gura_AssignMethod(wx_PixelData, IsOk);
	Gura_AssignMethod(wx_PixelData, Offset);
	Gura_AssignMethod(wx_PixelData, OffsetX);
	Gura_AssignMethod(wx_PixelData, OffsetY);
	Gura_AssignMethod(wx_PixelData, MoveTo);
	Gura_AssignMethod(wx_PixelData, Red);
	Gura_AssignMethod(wx_PixelData, Green);
	Gura_AssignMethod(wx_PixelData, Blue);
	Gura_AssignMethod(wx_PixelData, Alpha);
}

Gura_ImplementDescendantCreator(wx_PixelData)
{
	return new Object_wx_PixelData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
