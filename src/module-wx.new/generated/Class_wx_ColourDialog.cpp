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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ColourDialog, "ColourDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ColourDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ColourDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxColourData* data = arg.GetNumber(1)
	//wxColourDialog(parent, data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ColourDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDialog, __Create)
{
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxColourData* data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Create(parent, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourDialog, __GetColourData, "GetColourData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ColourDialog, __GetColourData)
{
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColourData& _rtn = pThis->GetEntity()->GetColourData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ColourDialog, __ShowModal)
{
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxColourDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__ColourDialog);
	// Method assignment
	Gura_AssignMethod(wx_ColourDialog, __Create);
	Gura_AssignMethod(wx_ColourDialog, __GetColourData);
	Gura_AssignMethod(wx_ColourDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_ColourDialog)
{
	return new Object_wx_ColourDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
