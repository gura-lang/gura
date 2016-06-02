//----------------------------------------------------------------------------
// wxWizardPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizardPage
//----------------------------------------------------------------------------
Object_wx_WizardPage::~Object_wx_WizardPage()
{
}

Object *Object_wx_WizardPage::Clone() const
{
	return nullptr;
}

String Object_wx_WizardPage::ToString(bool exprFlag)
{
	String rtn("<wx.WizardPage:");
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
Gura_DeclareMethod(wx_WizardPage, wxWizardPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, wxWizardPage)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxWizardPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPage, wxWizardPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPage, wxWizardPage_1)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->wxWizardPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPage, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPage, Create)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPage, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, GetBitmap)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPage, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, GetNext)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPage, GetPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, GetPrev)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrev();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWizardPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPage)
{
	Gura_AssignMethod(wx_WizardPage, wxWizardPage);
	Gura_AssignMethod(wx_WizardPage, wxWizardPage_1);
	Gura_AssignMethod(wx_WizardPage, Create);
	Gura_AssignMethod(wx_WizardPage, GetBitmap);
	Gura_AssignMethod(wx_WizardPage, GetNext);
	Gura_AssignMethod(wx_WizardPage, GetPrev);
}

Gura_ImplementDescendantCreator(wx_WizardPage)
{
	return new Object_wx_WizardPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
