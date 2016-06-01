//----------------------------------------------------------------------------
// wxWizard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizard
//----------------------------------------------------------------------------
Object_wx_Wizard::~Object_wx_Wizard()
{
}

Object *Object_wx_Wizard::Clone() const
{
	return nullptr;
}

String Object_wx_Wizard::ToString(bool exprFlag)
{
	String rtn("<wx.Wizard:");
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
Gura_DeclareMethod(wx_Wizard, wxWizard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, wxWizard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxWizard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, wxWizard_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, wxWizard_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//pThis->GetEntity()->wxWizard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, FitToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "firstPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, FitToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int firstPage = arg.GetNumber(0)
	//pThis->GetEntity()->FitToPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetBitmapBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetBitmapBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetBitmapPlacement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetBitmapPlacement)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmapPlacement();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetMinimumBitmapWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetMinimumBitmapWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinimumBitmapWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetPageAreaSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetPageAreaSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageAreaSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, GetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Wizard, GetPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, HasNextPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, HasNextPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->HasNextPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, HasPrevPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, HasPrevPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->HasPrevPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, RunWizard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "firstPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, RunWizard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int firstPage = arg.GetNumber(0)
	//pThis->GetEntity()->RunWizard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, SetBitmapBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBitmapBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, SetBitmapPlacement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "placement", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBitmapPlacement)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int placement = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapPlacement();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, SetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, SetMinimumBitmapWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetMinimumBitmapWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinimumBitmapWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Wizard, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizePage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Wizard, SetPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Wizard *pThis = Object_wx_Wizard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizePage = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWizard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Wizard)
{
	Gura_AssignMethod(wx_Wizard, wxWizard);
	Gura_AssignMethod(wx_Wizard, wxWizard_1);
	Gura_AssignMethod(wx_Wizard, Create);
	Gura_AssignMethod(wx_Wizard, FitToPage);
	Gura_AssignMethod(wx_Wizard, GetBitmap);
	Gura_AssignMethod(wx_Wizard, GetBitmapBackgroundColour);
	Gura_AssignMethod(wx_Wizard, GetBitmapPlacement);
	Gura_AssignMethod(wx_Wizard, GetCurrentPage);
	Gura_AssignMethod(wx_Wizard, GetMinimumBitmapWidth);
	Gura_AssignMethod(wx_Wizard, GetPageAreaSizer);
	Gura_AssignMethod(wx_Wizard, GetPageSize);
	Gura_AssignMethod(wx_Wizard, HasNextPage);
	Gura_AssignMethod(wx_Wizard, HasPrevPage);
	Gura_AssignMethod(wx_Wizard, RunWizard);
	Gura_AssignMethod(wx_Wizard, SetBitmap);
	Gura_AssignMethod(wx_Wizard, SetBitmapBackgroundColour);
	Gura_AssignMethod(wx_Wizard, SetBitmapPlacement);
	Gura_AssignMethod(wx_Wizard, SetBorder);
	Gura_AssignMethod(wx_Wizard, SetMinimumBitmapWidth);
	Gura_AssignMethod(wx_Wizard, SetPageSize);
}

Gura_ImplementDescendantCreator(wx_Wizard)
{
	return new Object_wx_Wizard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
