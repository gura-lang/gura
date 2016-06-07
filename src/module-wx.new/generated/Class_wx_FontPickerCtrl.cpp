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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FontPickerCtrl, "FontPickerCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontPickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontPickerCtrl)
{
	//wxFontPickerCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FontPickerCtrl_1, "FontPickerCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_FontPickerCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontPickerCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxFont& font = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxFontPickerCtrl(parent, id, font, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontPickerCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_FontPickerCtrl, __Create)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxFont& font = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create(parent, id, font, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerCtrl, __GetMaxPointSize, "GetMaxPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, __GetMaxPointSize)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxPointSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerCtrl, __GetSelectedColour, "GetSelectedColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, __GetSelectedColour)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerCtrl, __GetSelectedFont, "GetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontPickerCtrl, __GetSelectedFont)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerCtrl, __SetMaxPointSize, "SetMaxPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, __SetMaxPointSize)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int max = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxPointSize(max);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerCtrl, __SetSelectedColour, "SetSelectedColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, __SetSelectedColour)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontPickerCtrl, __SetSelectedFont, "SetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontPickerCtrl, __SetSelectedFont)
{
	Object_wx_FontPickerCtrl *pThis = Object_wx_FontPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont(font);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__FontPickerCtrl);
	Gura_AssignFunction(__FontPickerCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_FontPickerCtrl, __Create);
	Gura_AssignMethod(wx_FontPickerCtrl, __GetMaxPointSize);
	Gura_AssignMethod(wx_FontPickerCtrl, __GetSelectedColour);
	Gura_AssignMethod(wx_FontPickerCtrl, __GetSelectedFont);
	Gura_AssignMethod(wx_FontPickerCtrl, __SetMaxPointSize);
	Gura_AssignMethod(wx_FontPickerCtrl, __SetSelectedColour);
	Gura_AssignMethod(wx_FontPickerCtrl, __SetSelectedFont);
}

Gura_ImplementDescendantCreator(wx_FontPickerCtrl)
{
	return new Object_wx_FontPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
