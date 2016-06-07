//----------------------------------------------------------------------------
// wxMessageDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageDialog
//----------------------------------------------------------------------------
Object_wx_MessageDialog::~Object_wx_MessageDialog()
{
}

Object *Object_wx_MessageDialog::Clone() const
{
	return nullptr;
}

String Object_wx_MessageDialog::ToString(bool exprFlag)
{
	String rtn("<wx.MessageDialog:");
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
Gura_DeclareMethodAlias(wx_MessageDialog, __ButtonLabel, "ButtonLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stockId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageDialog, __ButtonLabel)
{
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stockId = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonLabel(stockId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageDialog, __ButtonLabel_1, "ButtonLabel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageDialog, __ButtonLabel_1)
{
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonLabel(label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageDialog, __GetAsString, "GetAsString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageDialog, __GetAsString)
{
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAsString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageDialog, __GetStockId, "GetStockId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageDialog, __GetStockId)
{
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStockId();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageDialog)
{
	// Class assignment
	Gura_AssignValueEx("MessageDialog", Reference());
	// Method assignment
	Gura_AssignMethod(wx_MessageDialog, __ButtonLabel);
	Gura_AssignMethod(wx_MessageDialog, __ButtonLabel_1);
	Gura_AssignMethod(wx_MessageDialog, __GetAsString);
	Gura_AssignMethod(wx_MessageDialog, __GetStockId);
}

Gura_ImplementDescendantCreator(wx_MessageDialog)
{
	return new Object_wx_MessageDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
