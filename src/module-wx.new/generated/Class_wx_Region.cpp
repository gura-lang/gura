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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Region, wxRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, wxRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topLeft = arg.GetNumber(0)
	//int bottomRight = arg.GetNumber(1)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//int fillStyle = arg.GetNumber(2)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, wxRegion_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "transColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, wxRegion_7)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int transColour = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//pThis->GetEntity()->wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, ~wxRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, ~wxRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Contains)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Contains_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Contains_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Contains_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Contains_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Contains_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Contains_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, ConvertToBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, ConvertToBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ConvertToBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, GetBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, GetBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, GetBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, GetBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Intersect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Intersect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Intersect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Intersect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Intersect_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Intersect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, IsEqual)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Offset)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Offset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Offset_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Offset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Subtract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Subtract)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Subtract_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Subtract_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Union)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Union)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Union_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Union_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Union_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Union_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Union_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Union_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Union_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "transColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tolerance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Union_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int transColour = arg.GetNumber(1)
	//int tolerance = arg.GetNumber(2)
	//pThis->GetEntity()->Union();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Xor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Xor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->Xor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Xor_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Xor_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->Xor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Xor_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Region, Xor_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->Xor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegion
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Region)
{
	Gura_AssignMethod(wx_Region, wxRegion);
	Gura_AssignMethod(wx_Region, wxRegion_1);
	Gura_AssignMethod(wx_Region, wxRegion_2);
	Gura_AssignMethod(wx_Region, wxRegion_3);
	Gura_AssignMethod(wx_Region, wxRegion_4);
	Gura_AssignMethod(wx_Region, wxRegion_5);
	Gura_AssignMethod(wx_Region, wxRegion_6);
	Gura_AssignMethod(wx_Region, wxRegion_7);
	Gura_AssignMethod(wx_Region, ~wxRegion);
	Gura_AssignMethod(wx_Region, Clear);
	Gura_AssignMethod(wx_Region, Contains);
	Gura_AssignMethod(wx_Region, Contains_1);
	Gura_AssignMethod(wx_Region, Contains_2);
	Gura_AssignMethod(wx_Region, Contains_3);
	Gura_AssignMethod(wx_Region, ConvertToBitmap);
	Gura_AssignMethod(wx_Region, GetBox);
	Gura_AssignMethod(wx_Region, GetBox_1);
	Gura_AssignMethod(wx_Region, Intersect);
	Gura_AssignMethod(wx_Region, Intersect_1);
	Gura_AssignMethod(wx_Region, Intersect_2);
	Gura_AssignMethod(wx_Region, IsEmpty);
	Gura_AssignMethod(wx_Region, IsEqual);
	Gura_AssignMethod(wx_Region, Offset);
	Gura_AssignMethod(wx_Region, Offset_1);
	Gura_AssignMethod(wx_Region, Subtract);
	Gura_AssignMethod(wx_Region, Subtract_1);
	Gura_AssignMethod(wx_Region, Union);
	Gura_AssignMethod(wx_Region, Union_1);
	Gura_AssignMethod(wx_Region, Union_2);
	Gura_AssignMethod(wx_Region, Union_3);
	Gura_AssignMethod(wx_Region, Union_4);
	Gura_AssignMethod(wx_Region, Xor);
	Gura_AssignMethod(wx_Region, Xor_1);
	Gura_AssignMethod(wx_Region, Xor_2);
}

Gura_ImplementDescendantCreator(wx_Region)
{
	return new Object_wx_Region((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
