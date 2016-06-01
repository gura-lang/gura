//----------------------------------------------------------------------------
// wxColourDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourDialog
//----------------------------------------------------------------------------
Object_wx_ColourDialog::~Object_wx_ColourDialog()
{
}

Object *Object_wx_ColourDialog::Clone() const
{
	return nullptr;
}

String Object_wx_ColourDialog::ToString(bool exprFlag)
{
	String rtn("<wx.ColourDialog:");
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
Gura_DeclareMethod(wx_ColourDialog, wxColourDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDialog, wxColourDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->wxColourDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDialog, ~wxColourDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourDialog, ~wxColourDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxColourDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDialog, GetColourData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourDialog, GetColourData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColourData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxColourDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDialog)
{
	Gura_AssignMethod(wx_ColourDialog, wxColourDialog);
	Gura_AssignMethod(wx_ColourDialog, ~wxColourDialog);
	Gura_AssignMethod(wx_ColourDialog, Create);
	Gura_AssignMethod(wx_ColourDialog, GetColourData);
	Gura_AssignMethod(wx_ColourDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_ColourDialog)
{
	return new Object_wx_ColourDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
