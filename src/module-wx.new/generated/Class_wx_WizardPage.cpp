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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxWizardPage, "wxWizardPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_WizardPage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWizardPage)
{
	//wxWizardPage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxWizardPage_1, "wxWizardPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WizardPage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWizardPage_1)
{
	//int parent = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//wxWizardPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WizardPage, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPage, __Create)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPage, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, __GetBitmap)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPage, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, __GetNext)
{
	Object_wx_WizardPage *pThis = Object_wx_WizardPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPage, __GetPrev, "GetPrev")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPage, __GetPrev)
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
	// Constructor assignment
	Gura_AssignFunction(__wxWizardPage);
	Gura_AssignFunction(__wxWizardPage_1);
	// Method assignment
	Gura_AssignMethod(wx_WizardPage, __Create);
	Gura_AssignMethod(wx_WizardPage, __GetBitmap);
	Gura_AssignMethod(wx_WizardPage, __GetNext);
	Gura_AssignMethod(wx_WizardPage, __GetPrev);
}

Gura_ImplementDescendantCreator(wx_WizardPage)
{
	return new Object_wx_WizardPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
