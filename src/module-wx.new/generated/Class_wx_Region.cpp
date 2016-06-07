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
Gura_DeclareFunctionAlias(__Region, "Region")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region)
{
	//wxRegion();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_1, "Region_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_1)
{
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//wxRegion(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_2, "Region_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_2)
{
	//const wxPoint& topLeft = arg.GetNumber(0)
	//const wxPoint& bottomRight = arg.GetNumber(1)
	//wxRegion(topLeft, bottomRight);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_3, "Region_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_3)
{
	//const wxRect& rect = arg.GetNumber(0)
	//wxRegion(rect);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_4, "Region_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_4)
{
	//const wxRegion& region = arg.GetNumber(0)
	//wxRegion(region);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_5, "Region_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_5)
{
	//size_t n = arg.GetNumber(0)
	//const wxPoint* points = arg.GetNumber(1)
	//wxPolygonFillMode fillStyle = arg.GetNumber(2)
	//wxRegion(n, points, fillStyle);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_6, "Region_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_6)
{
	//const wxBitmap& bmp = arg.GetNumber(0)
	//wxRegion(bmp);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Region_7, "Region_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "transColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Region_7)
{
	//const wxBitmap& bmp = arg.GetNumber(0)
	//const wxColour& transColour = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//wxRegion(bmp, transColour, tolerance);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->Contains(x, y);
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
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains(pt);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->Contains(x, y, width, height);
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
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains(rect);
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
	//wxCoord& x = arg.GetNumber(0)
	//wxCoord& y = arg.GetNumber(1)
	//wxCoord& width = arg.GetNumber(2)
	//wxCoord& height = arg.GetNumber(3)
	//pThis->GetEntity()->GetBox(x, y, width, height);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->Intersect(x, y, width, height);
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
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect(rect);
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
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect(region);
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
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual(region);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->Offset(x, y);
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
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset(pt);
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
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract(rect);
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
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract(region);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->Union(x, y, width, height);
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
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union(rect);
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
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->Union(region);
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
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->Union(bmp);
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
	//const wxBitmap& bmp = arg.GetNumber(0)
	//const wxColour& transColour = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//pThis->GetEntity()->Union(bmp, transColour, tolerance);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->Xor(x, y, width, height);
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
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->Xor(rect);
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
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->Xor(region);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegion
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Region)
{
	// Constructor assignment
	Gura_AssignFunction(__Region);
	Gura_AssignFunction(__Region_1);
	Gura_AssignFunction(__Region_2);
	Gura_AssignFunction(__Region_3);
	Gura_AssignFunction(__Region_4);
	Gura_AssignFunction(__Region_5);
	Gura_AssignFunction(__Region_6);
	Gura_AssignFunction(__Region_7);
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
