//----------------------------------------------------------------------------
// wxBitmapToggleButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapToggleButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapToggleButton
//----------------------------------------------------------------------------
Object_wx_BitmapToggleButton::~Object_wx_BitmapToggleButton()
{
}

Object *Object_wx_BitmapToggleButton::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapToggleButton::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapToggleButton:");
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
Gura_DeclareFunctionAlias(__BitmapToggleButton, "BitmapToggleButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BitmapToggleButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapToggleButton)
{
	//wxBitmapToggleButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BitmapToggleButton_1, "BitmapToggleButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BitmapToggleButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapToggleButton_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxBitmap& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& val = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxBitmapToggleButton(parent, id, label, pos, size, style, val, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BitmapToggleButton, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapToggleButton, __Create)
{
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxBitmap& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& val = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, pos, size, style, val, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapToggleButton, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapToggleButton, __GetValue)
{
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapToggleButton, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapToggleButton, __SetValue)
{
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool state = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(state);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapToggleButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapToggleButton)
{
	// Constructor assignment
	Gura_AssignFunction(__BitmapToggleButton);
	Gura_AssignFunction(__BitmapToggleButton_1);
	// Method assignment
	Gura_AssignMethod(wx_BitmapToggleButton, __Create);
	Gura_AssignMethod(wx_BitmapToggleButton, __GetValue);
	Gura_AssignMethod(wx_BitmapToggleButton, __SetValue);
}

Gura_ImplementDescendantCreator(wx_BitmapToggleButton)
{
	return new Object_wx_BitmapToggleButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
