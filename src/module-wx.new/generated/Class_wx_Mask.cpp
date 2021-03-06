//----------------------------------------------------------------------------
// wxMask
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMask
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMask
//----------------------------------------------------------------------------
Object_wx_Mask::~Object_wx_Mask()
{
}

Object *Object_wx_Mask::Clone() const
{
	return nullptr;
}

String Object_wx_Mask::ToString(bool exprFlag)
{
	String rtn("<wx.Mask:");
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
Gura_DeclareFunctionAlias(__Mask, "Mask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Mask)
{
	//wxMask();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Mask_1, "Mask_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Mask_1)
{
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//wxMask(bitmap, index);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Mask_2, "Mask_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Mask_2)
{
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//wxMask(bitmap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Mask_3, "Mask_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Mask));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Mask_3)
{
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//const wxColour& colour = arg.GetNumber(1)
	//wxMask(bitmap, colour);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Mask, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, __Create)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Create(bitmap, index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Mask, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, __Create_1)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Create(bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Mask, __Create_2, "Create_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mask, __Create_2)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//const wxColour& colour = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Create(bitmap, colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Mask, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Mask, __GetBitmap)
{
	Object_wx_Mask *pThis = Object_wx_Mask::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap _rtn = pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMask
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mask)
{
	// Constructor assignment
	Gura_AssignFunction(__Mask);
	Gura_AssignFunction(__Mask_1);
	Gura_AssignFunction(__Mask_2);
	Gura_AssignFunction(__Mask_3);
	// Method assignment
	Gura_AssignMethod(wx_Mask, __Create);
	Gura_AssignMethod(wx_Mask, __Create_1);
	Gura_AssignMethod(wx_Mask, __Create_2);
	Gura_AssignMethod(wx_Mask, __GetBitmap);
}

Gura_ImplementDescendantCreator(wx_Mask)
{
	return new Object_wx_Mask((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
