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
Gura_DeclareFunctionAlias(__PropertySheetDialog, "PropertySheetDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PropertySheetDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PropertySheetDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxPropertySheetDialog(parent, id, title, pos, size, style, name);
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
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->AddBookCtrl(sizer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, title, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __CreateBookCtrl, "CreateBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __CreateBookCtrl)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBookCtrlBase* _rtn = pThis->GetEntity()->CreateBookCtrl();
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
	//pThis->GetEntity()->CreateButtons(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __GetBookCtrl, "GetBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __GetBookCtrl)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBookCtrlBase* _rtn = pThis->GetEntity()->GetBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __GetInnerSizer, "GetInnerSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __GetInnerSizer)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* _rtn = pThis->GetEntity()->GetInnerSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertySheetDialog, __GetSheetStyle, "GetSheetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, __GetSheetStyle)
{
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetSheetStyle();
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
	//pThis->GetEntity()->LayoutDialog(centreFlags);
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
	//wxBookCtrlBase* bookCtrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetBookCtrl(bookCtrl);
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
	//long style = arg.GetNumber(0)
	//pThis->GetEntity()->SetSheetStyle(style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertySheetDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__PropertySheetDialog);
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
