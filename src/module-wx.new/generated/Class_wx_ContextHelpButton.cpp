//----------------------------------------------------------------------------
// wxContextHelpButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelpButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Object_wx_ContextHelpButton::~Object_wx_ContextHelpButton()
{
}

Object *Object_wx_ContextHelpButton::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelpButton::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelpButton:");
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
Gura_DeclareMethod(wx_ContextHelpButton, wxContextHelpButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ContextHelpButton, wxContextHelpButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_ContextHelpButton *pThis = Object_wx_ContextHelpButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxContextHelpButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelpButton)
{
	Gura_AssignMethod(wx_ContextHelpButton, wxContextHelpButton);
}

Gura_ImplementDescendantCreator(wx_ContextHelpButton)
{
	return new Object_wx_ContextHelpButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
