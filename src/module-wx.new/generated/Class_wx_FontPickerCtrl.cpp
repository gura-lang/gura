//----------------------------------------------------------------------------
// wxFontPickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Object_wx_FontPickerCtrl::~Object_wx_FontPickerCtrl()
{
}

Object *Object_wx_FontPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FontPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerCtrl:");
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
Gura_DeclareMethod(wx_FontPickerCtrl, wxFontPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, wxFontPickerCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFontPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, wxFontPickerCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, wxFontPickerCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int font = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxFontPickerCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int font = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetMaxPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetMaxPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetSelectedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetSelectedColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, GetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, GetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetMaxPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetMaxPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int max = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetSelectedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetSelectedColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontPickerCtrl, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, SetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerCtrl)
{
	Gura_AssignMethod(wx_FontPickerCtrl, wxFontPickerCtrl);
	Gura_AssignMethod(wx_FontPickerCtrl, wxFontPickerCtrl_1);
	Gura_AssignMethod(wx_FontPickerCtrl, Create);
	Gura_AssignMethod(wx_FontPickerCtrl, GetMaxPointSize);
	Gura_AssignMethod(wx_FontPickerCtrl, GetSelectedColour);
	Gura_AssignMethod(wx_FontPickerCtrl, GetSelectedFont);
	Gura_AssignMethod(wx_FontPickerCtrl, SetMaxPointSize);
	Gura_AssignMethod(wx_FontPickerCtrl, SetSelectedColour);
	Gura_AssignMethod(wx_FontPickerCtrl, SetSelectedFont);
}

Gura_ImplementDescendantCreator(wx_FontPickerCtrl)
{
	return new Object_wx_FontPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
