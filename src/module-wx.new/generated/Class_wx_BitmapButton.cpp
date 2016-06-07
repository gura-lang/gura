//----------------------------------------------------------------------------
// wxBitmapButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapButton
//----------------------------------------------------------------------------
Object_wx_BitmapButton::~Object_wx_BitmapButton()
{
}

Object *Object_wx_BitmapButton::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapButton::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapButton:");
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
Gura_DeclareFunctionAlias(__BitmapButton, "BitmapButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BitmapButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapButton)
{
	//wxBitmapButton();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BitmapButton_1, "BitmapButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BitmapButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BitmapButton_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxBitmapButton(parent, id, bitmap, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BitmapButton, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, __Create)
{
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, bitmap, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BitmapButton, __NewCloseButton, "NewCloseButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, __NewCloseButton)
{
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//wxBitmapButton* _rtn = pThis->GetEntity()->NewCloseButton(parent, winid);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapButton)
{
	// Constructor assignment
	Gura_AssignFunction(__BitmapButton);
	Gura_AssignFunction(__BitmapButton_1);
	// Method assignment
	Gura_AssignMethod(wx_BitmapButton, __Create);
	Gura_AssignMethod(wx_BitmapButton, __NewCloseButton);
}

Gura_ImplementDescendantCreator(wx_BitmapButton)
{
	return new Object_wx_BitmapButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
