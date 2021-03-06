//----------------------------------------------------------------------------
// wxIcon
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIcon
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIcon
//----------------------------------------------------------------------------
Object_wx_Icon::~Object_wx_Icon()
{
}

Object *Object_wx_Icon::Clone() const
{
	return nullptr;
}

String Object_wx_Icon::ToString(bool exprFlag)
{
	String rtn("<wx.Icon:");
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
Gura_DeclareFunctionAlias(__Icon, "Icon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Icon)
{
	//wxIcon();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Icon_1, "Icon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Icon_1)
{
	//const wxIcon& icon = arg.GetNumber(0)
	//wxIcon(icon);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Icon_2, "Icon_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Icon_2)
{
	//const char bits = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//wxIcon(bits, width, height);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Icon_3, "Icon_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Icon_3)
{
	//const char* const* bits = arg.GetNumber(0)
	//wxIcon(bits);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Icon_4, "Icon_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredHeight", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Icon_4)
{
	//const wxString& name = arg.GetNumber(0)
	//wxBitmapType type = arg.GetNumber(1)
	//int desiredWidth = arg.GetNumber(2)
	//int desiredHeight = arg.GetNumber(3)
	//wxIcon(name, type, desiredWidth, desiredHeight);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Icon_5, "Icon_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "loc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Icon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Icon_5)
{
	//const wxIconLocation& loc = arg.GetNumber(0)
	//wxIcon(loc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Icon, __CreateFromHICON, "CreateFromHICON")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __CreateFromHICON)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//WXHICON icon = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CreateFromHICON(icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __ConvertToDisabled, "ConvertToDisabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __ConvertToDisabled)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned char brightness = arg.GetNumber(0)
	//wxIcon _rtn = pThis->GetEntity()->ConvertToDisabled(brightness);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __CopyFromBitmap, "CopyFromBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __CopyFromBitmap)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->CopyFromBitmap(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __GetDepth, "GetDepth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, __GetDepth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, __GetHeight)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, __GetWidth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, __IsOk)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __LoadFile)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxBitmapType type = arg.GetNumber(1)
	//int desiredWidth = arg.GetNumber(2)
	//int desiredHeight = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->LoadFile(name, type, desiredWidth, desiredHeight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __SetDepth, "SetDepth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __SetDepth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int depth = arg.GetNumber(0)
	//pThis->GetEntity()->SetDepth(depth);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __SetHeight, "SetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __SetHeight)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight(height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Icon, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, __SetWidth)
{
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth(width);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIcon
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Icon)
{
	// Constructor assignment
	Gura_AssignFunction(__Icon);
	Gura_AssignFunction(__Icon_1);
	Gura_AssignFunction(__Icon_2);
	Gura_AssignFunction(__Icon_3);
	Gura_AssignFunction(__Icon_4);
	Gura_AssignFunction(__Icon_5);
	// Method assignment
	Gura_AssignMethod(wx_Icon, __CreateFromHICON);
	Gura_AssignMethod(wx_Icon, __ConvertToDisabled);
	Gura_AssignMethod(wx_Icon, __CopyFromBitmap);
	Gura_AssignMethod(wx_Icon, __GetDepth);
	Gura_AssignMethod(wx_Icon, __GetHeight);
	Gura_AssignMethod(wx_Icon, __GetWidth);
	Gura_AssignMethod(wx_Icon, __IsOk);
	Gura_AssignMethod(wx_Icon, __LoadFile);
	Gura_AssignMethod(wx_Icon, __SetDepth);
	Gura_AssignMethod(wx_Icon, __SetHeight);
	Gura_AssignMethod(wx_Icon, __SetWidth);
}

Gura_ImplementDescendantCreator(wx_Icon)
{
	return new Object_wx_Icon((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
