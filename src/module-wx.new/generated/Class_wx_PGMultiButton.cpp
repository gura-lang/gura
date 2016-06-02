//----------------------------------------------------------------------------
// wxPGMultiButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGMultiButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGMultiButton
//----------------------------------------------------------------------------
Object_wx_PGMultiButton::~Object_wx_PGMultiButton()
{
}

Object *Object_wx_PGMultiButton::Clone() const
{
	return nullptr;
}

String Object_wx_PGMultiButton::ToString(bool exprFlag)
{
	String rtn("<wx.PGMultiButton:");
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
Gura_DeclareMethod(wx_PGMultiButton, wxPGMultiButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, wxPGMultiButton)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pg = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//pThis->GetEntity()->wxPGMultiButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, Add)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, Add_1)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, Finalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propGrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, Finalize)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int propGrid = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->Finalize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, GetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, GetButton)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, GetButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, GetButtonId)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetButtonId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGMultiButton, GetCount)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGMultiButton, GetPrimarySize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGMultiButton, GetPrimarySize)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrimarySize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGMultiButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGMultiButton)
{
	Gura_AssignMethod(wx_PGMultiButton, wxPGMultiButton);
	Gura_AssignMethod(wx_PGMultiButton, Add);
	Gura_AssignMethod(wx_PGMultiButton, Add_1);
	Gura_AssignMethod(wx_PGMultiButton, Finalize);
	Gura_AssignMethod(wx_PGMultiButton, GetButton);
	Gura_AssignMethod(wx_PGMultiButton, GetButtonId);
	Gura_AssignMethod(wx_PGMultiButton, GetCount);
	Gura_AssignMethod(wx_PGMultiButton, GetPrimarySize);
}

Gura_ImplementDescendantCreator(wx_PGMultiButton)
{
	return new Object_wx_PGMultiButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
