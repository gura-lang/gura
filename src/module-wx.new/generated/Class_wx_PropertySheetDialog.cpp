//----------------------------------------------------------------------------
// wxPropertySheetDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertySheetDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Object_wx_PropertySheetDialog::~Object_wx_PropertySheetDialog()
{
}

Object *Object_wx_PropertySheetDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PropertySheetDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PropertySheetDialog:");
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
Gura_DeclareFunctionAlias(__wxPropertySheetDialog, "wxPropertySheetDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPropertySheetDialog)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxPropertySheetDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PropertySheetDialog, __AddBookCtrl, "AddBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __AddBookCtrl)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->AddBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __Create)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __CreateBookCtrl, "CreateBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __CreateBookCtrl)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __CreateButtons, "CreateButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __CreateButtons)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __GetBookCtrl, "GetBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __GetBookCtrl)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __GetInnerSizer, "GetInnerSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __GetInnerSizer)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInnerSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __GetSheetStyle, "GetSheetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __GetSheetStyle)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSheetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __LayoutDialog, "LayoutDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "centreFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __LayoutDialog)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int centreFlags = arg.GetNumber(0)
	//pThis->GetEntity()->LayoutDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __SetBookCtrl, "SetBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookCtrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __SetBookCtrl)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bookCtrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __SetSheetStyle, "SetSheetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __SetSheetStyle)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetSheetStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertySheetDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPropertySheetDialog);
	// Method assignment
	Gura_AssignMethod(wx_PropertySheetDialog, __AddBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, __Create);
	Gura_AssignMethod(wx_PropertySheetDialog, __CreateBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, __CreateButtons);
	Gura_AssignMethod(wx_PropertySheetDialog, __GetBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, __GetInnerSizer);
	Gura_AssignMethod(wx_PropertySheetDialog, __GetSheetStyle);
	Gura_AssignMethod(wx_PropertySheetDialog, __LayoutDialog);
	Gura_AssignMethod(wx_PropertySheetDialog, __SetBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, __SetSheetStyle);
}

Gura_ImplementDescendantCreator(wx_PropertySheetDialog)
{
	return new Object_wx_PropertySheetDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
