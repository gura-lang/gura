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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BitmapToggleButton, wxBitmapToggleButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapToggleButton, wxBitmapToggleButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxBitmapToggleButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapToggleButton, wxBitmapToggleButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapToggleButton, wxBitmapToggleButton_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int val = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxBitmapToggleButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapToggleButton, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapToggleButton, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int val = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapToggleButton, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BitmapToggleButton, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BitmapToggleButton, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BitmapToggleButton, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_BitmapToggleButton *pThis = Object_wx_BitmapToggleButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBitmapToggleButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapToggleButton)
{
	Gura_AssignMethod(wx_BitmapToggleButton, wxBitmapToggleButton);
	Gura_AssignMethod(wx_BitmapToggleButton, wxBitmapToggleButton_1);
	Gura_AssignMethod(wx_BitmapToggleButton, Create);
	Gura_AssignMethod(wx_BitmapToggleButton, GetValue);
	Gura_AssignMethod(wx_BitmapToggleButton, SetValue);
}

Gura_ImplementDescendantCreator(wx_BitmapToggleButton)
{
	return new Object_wx_BitmapToggleButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
