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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PropertySheetDialog, wxPropertySheetDialog)
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

Gura_ImplementMethod(wx_PropertySheetDialog, wxPropertySheetDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxPropertySheetDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, AddBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, AddBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->AddBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, Create)
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

Gura_ImplementMethod(wx_PropertySheetDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_PropertySheetDialog, CreateBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, CreateBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, CreateButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, CreateButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetInnerSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetInnerSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInnerSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, GetSheetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertySheetDialog, GetSheetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSheetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, LayoutDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "centreFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, LayoutDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int centreFlags = arg.GetNumber(0)
	//pThis->GetEntity()->LayoutDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookCtrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetBookCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bookCtrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertySheetDialog, SetSheetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertySheetDialog, SetSheetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertySheetDialog *pThis = Object_wx_PropertySheetDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetSheetStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertySheetDialog)
{
	Gura_AssignMethod(wx_PropertySheetDialog, wxPropertySheetDialog);
	Gura_AssignMethod(wx_PropertySheetDialog, AddBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, Create);
	Gura_AssignMethod(wx_PropertySheetDialog, CreateBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, CreateButtons);
	Gura_AssignMethod(wx_PropertySheetDialog, GetBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, GetInnerSizer);
	Gura_AssignMethod(wx_PropertySheetDialog, GetSheetStyle);
	Gura_AssignMethod(wx_PropertySheetDialog, LayoutDialog);
	Gura_AssignMethod(wx_PropertySheetDialog, SetBookCtrl);
	Gura_AssignMethod(wx_PropertySheetDialog, SetSheetStyle);
}

Gura_ImplementDescendantCreator(wx_PropertySheetDialog)
{
	return new Object_wx_PropertySheetDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
