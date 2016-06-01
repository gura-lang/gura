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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Icon, wxIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, wxIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, wxIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, wxIcon_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, wxIcon_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, wxIcon_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//pThis->GetEntity()->wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, wxIcon_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, wxIcon_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//pThis->GetEntity()->wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, wxIcon_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, wxIcon_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int desiredWidth = arg.GetNumber(2)
	//int desiredHeight = arg.GetNumber(3)
	//pThis->GetEntity()->wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, wxIcon_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, wxIcon_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int loc = arg.GetNumber(0)
	//pThis->GetEntity()->wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, ~wxIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, ~wxIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, CreateFromHICON)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, CreateFromHICON)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->CreateFromHICON();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, ConvertToDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, ConvertToDisabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int brightness = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertToDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, CopyFromBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, CopyFromBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->CopyFromBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, GetDepth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Icon, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desiredHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int desiredWidth = arg.GetNumber(2)
	//int desiredHeight = arg.GetNumber(3)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, SetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "depth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, SetDepth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int depth = arg.GetNumber(0)
	//pThis->GetEntity()->SetDepth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, SetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Icon, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Icon, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Icon *pThis = Object_wx_Icon::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIcon
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Icon)
{
	Gura_AssignMethod(wx_Icon, wxIcon);
	Gura_AssignMethod(wx_Icon, wxIcon_1);
	Gura_AssignMethod(wx_Icon, wxIcon_2);
	Gura_AssignMethod(wx_Icon, wxIcon_3);
	Gura_AssignMethod(wx_Icon, wxIcon_4);
	Gura_AssignMethod(wx_Icon, wxIcon_5);
	Gura_AssignMethod(wx_Icon, ~wxIcon);
	Gura_AssignMethod(wx_Icon, CreateFromHICON);
	Gura_AssignMethod(wx_Icon, ConvertToDisabled);
	Gura_AssignMethod(wx_Icon, CopyFromBitmap);
	Gura_AssignMethod(wx_Icon, GetDepth);
	Gura_AssignMethod(wx_Icon, GetHeight);
	Gura_AssignMethod(wx_Icon, GetWidth);
	Gura_AssignMethod(wx_Icon, IsOk);
	Gura_AssignMethod(wx_Icon, LoadFile);
	Gura_AssignMethod(wx_Icon, SetDepth);
	Gura_AssignMethod(wx_Icon, SetHeight);
	Gura_AssignMethod(wx_Icon, SetWidth);
}

Gura_ImplementDescendantCreator(wx_Icon)
{
	return new Object_wx_Icon((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
