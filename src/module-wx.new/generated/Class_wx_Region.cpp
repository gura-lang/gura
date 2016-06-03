//----------------------------------------------------------------------------
// wxRegion
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegion
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegion
//----------------------------------------------------------------------------
Object_wx_Region::~Object_wx_Region()
{
}

Object *Object_wx_Region::Clone() const
{
	return nullptr;
}

String Object_wx_Region::ToString(bool exprFlag)
{
	String rtn("<wx.Region:");
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
Gura_DeclareFunctionAlias(__wxRegion, "wxRegion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxRegion)
{
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_1, "wxRegion_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_1)
{
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_2, "wxRegion_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_2)
{
	//int topLeft = arg.GetNumber(0)
	//int bottomRight = arg.GetNumber(1)
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_3, "wxRegion_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_3)
{
	//int rect = arg.GetNumber(0)
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_4, "wxRegion_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_4)
{
	//int region = arg.GetNumber(0)
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_5, "wxRegion_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_5)
{
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//int fillStyle = arg.GetNumber(2)
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_6, "wxRegion_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_6)
{
	//int bmp = arg.GetNumber(0)
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRegion_7, "wxRegion_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "transColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRegion_7)
{
	//int bmp = arg.GetNumber(0)
	//int transColour = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//wxRegion();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Region, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, __Clear)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Contains)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Contains_1, "Contains_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Contains_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Contains_2, "Contains_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Contains_2)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Contains_3, "Contains_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Contains_3)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __ConvertToBitmap, "ConvertToBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, __ConvertToBitmap)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ConvertToBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __GetBox, "GetBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __GetBox)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __GetBox_1, "GetBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, __GetBox_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Intersect, "Intersect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Intersect)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Intersect_1, "Intersect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Intersect_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Intersect_2, "Intersect_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Intersect_2)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, __IsEmpty)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __IsEqual, "IsEqual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __IsEqual)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Offset, "Offset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Offset)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Offset_1, "Offset_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Offset_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Subtract, "Subtract")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Subtract)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Subtract_1, "Subtract_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Subtract_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Union, "Union")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Union)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Union_1, "Union_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Union_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Union_2, "Union_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Union_2)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Union_3, "Union_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Union_3)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Union_4, "Union_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "transColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Union_4)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int transColour = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Xor, "Xor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Xor)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Xor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Xor_1, "Xor_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Xor_1)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Xor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Region, __Xor_2, "Xor_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, __Xor_2)
{
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Xor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegion
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Region)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRegion);
	Gura_AssignFunction(__wxRegion_1);
	Gura_AssignFunction(__wxRegion_2);
	Gura_AssignFunction(__wxRegion_3);
	Gura_AssignFunction(__wxRegion_4);
	Gura_AssignFunction(__wxRegion_5);
	Gura_AssignFunction(__wxRegion_6);
	Gura_AssignFunction(__wxRegion_7);
	// Method assignment
	Gura_AssignMethod(wx_Region, __Clear);
	Gura_AssignMethod(wx_Region, __Contains);
	Gura_AssignMethod(wx_Region, __Contains_1);
	Gura_AssignMethod(wx_Region, __Contains_2);
	Gura_AssignMethod(wx_Region, __Contains_3);
	Gura_AssignMethod(wx_Region, __ConvertToBitmap);
	Gura_AssignMethod(wx_Region, __GetBox);
	Gura_AssignMethod(wx_Region, __GetBox_1);
	Gura_AssignMethod(wx_Region, __Intersect);
	Gura_AssignMethod(wx_Region, __Intersect_1);
	Gura_AssignMethod(wx_Region, __Intersect_2);
	Gura_AssignMethod(wx_Region, __IsEmpty);
	Gura_AssignMethod(wx_Region, __IsEqual);
	Gura_AssignMethod(wx_Region, __Offset);
	Gura_AssignMethod(wx_Region, __Offset_1);
	Gura_AssignMethod(wx_Region, __Subtract);
	Gura_AssignMethod(wx_Region, __Subtract_1);
	Gura_AssignMethod(wx_Region, __Union);
	Gura_AssignMethod(wx_Region, __Union_1);
	Gura_AssignMethod(wx_Region, __Union_2);
	Gura_AssignMethod(wx_Region, __Union_3);
	Gura_AssignMethod(wx_Region, __Union_4);
	Gura_AssignMethod(wx_Region, __Xor);
	Gura_AssignMethod(wx_Region, __Xor_1);
	Gura_AssignMethod(wx_Region, __Xor_2);
}

Gura_ImplementDescendantCreator(wx_Region)
{
	return new Object_wx_Region((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
