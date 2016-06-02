//----------------------------------------------------------------------------
// wxFontDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontDialog
//----------------------------------------------------------------------------
Object_wx_FontDialog::~Object_wx_FontDialog()
{
}

Object *Object_wx_FontDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FontDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FontDialog:");
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
Gura_DeclareMethod(wx_FontDialog, wxFontDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontDialog, wxFontDialog)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFontDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, wxFontDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontDialog, wxFontDialog_1)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxFontDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, wxFontDialog_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontDialog, wxFontDialog_2)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->wxFontDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontDialog, Create)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontDialog, Create_1)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, GetFontData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontDialog, GetFontData)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, GetFontData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontDialog, GetFontData_1)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontDialog, ShowModal)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontDialog)
{
	Gura_AssignMethod(wx_FontDialog, wxFontDialog);
	Gura_AssignMethod(wx_FontDialog, wxFontDialog_1);
	Gura_AssignMethod(wx_FontDialog, wxFontDialog_2);
	Gura_AssignMethod(wx_FontDialog, Create);
	Gura_AssignMethod(wx_FontDialog, Create_1);
	Gura_AssignMethod(wx_FontDialog, GetFontData);
	Gura_AssignMethod(wx_FontDialog, GetFontData_1);
	Gura_AssignMethod(wx_FontDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_FontDialog)
{
	return new Object_wx_FontDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
