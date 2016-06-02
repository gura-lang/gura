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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BitmapButton, wxBitmapButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapButton, wxBitmapButton)
{
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxBitmapButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapButton, wxBitmapButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, wxBitmapButton_1)
{
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxBitmapButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapButton, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, Create)
{
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapButton, NewCloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapButton, NewCloseButton)
{
	Object_wx_BitmapButton *pThis = Object_wx_BitmapButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->NewCloseButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapButton)
{
	Gura_AssignMethod(wx_BitmapButton, wxBitmapButton);
	Gura_AssignMethod(wx_BitmapButton, wxBitmapButton_1);
	Gura_AssignMethod(wx_BitmapButton, Create);
	Gura_AssignMethod(wx_BitmapButton, NewCloseButton);
}

Gura_ImplementDescendantCreator(wx_BitmapButton)
{
	return new Object_wx_BitmapButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
