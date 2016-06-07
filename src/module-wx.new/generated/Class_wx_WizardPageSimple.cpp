//----------------------------------------------------------------------------
// wxWizardPageSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPageSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Object_wx_WizardPageSimple::~Object_wx_WizardPageSimple()
{
}

Object *Object_wx_WizardPageSimple::Clone() const
{
	return nullptr;
}

String Object_wx_WizardPageSimple::ToString(bool exprFlag)
{
	String rtn("<wx.WizardPageSimple:");
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
Gura_DeclareFunctionAlias(__WizardPageSimple, "WizardPageSimple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_WizardPageSimple));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WizardPageSimple)
{
	//wxWizardPageSimple();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WizardPageSimple_1, "WizardPageSimple_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prev", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WizardPageSimple));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WizardPageSimple_1)
{
	//wxWizard* parent = arg.GetNumber(0)
	//wxWizardPage* prev = arg.GetNumber(1)
	//wxWizardPage* next = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//wxWizardPageSimple(parent, prev, next, bitmap);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WizardPageSimple, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prev", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, __Create)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWizard* parent = arg.GetNumber(0)
	//wxWizardPage* prev = arg.GetNumber(1)
	//wxWizardPage* next = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->Create(parent, prev, next, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPageSimple, __Chain, "Chain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, __Chain)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWizardPageSimple* next = arg.GetNumber(0)
	//wxWizardPageSimple& _rtn = pThis->GetEntity()->Chain(next);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPageSimple, __Chain_1, "Chain_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "second", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, __Chain_1)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWizardPageSimple* first = arg.GetNumber(0)
	//wxWizardPageSimple* second = arg.GetNumber(1)
	//pThis->GetEntity()->Chain(first, second);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPageSimple, __SetNext, "SetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, __SetNext)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWizardPage* next = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext(next);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WizardPageSimple, __SetPrev, "SetPrev")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, __SetPrev)
{
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWizardPage* prev = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrev(prev);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPageSimple)
{
	// Constructor assignment
	Gura_AssignFunction(__WizardPageSimple);
	Gura_AssignFunction(__WizardPageSimple_1);
	// Method assignment
	Gura_AssignMethod(wx_WizardPageSimple, __Create);
	Gura_AssignMethod(wx_WizardPageSimple, __Chain);
	Gura_AssignMethod(wx_WizardPageSimple, __Chain_1);
	Gura_AssignMethod(wx_WizardPageSimple, __SetNext);
	Gura_AssignMethod(wx_WizardPageSimple, __SetPrev);
}

Gura_ImplementDescendantCreator(wx_WizardPageSimple)
{
	return new Object_wx_WizardPageSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
