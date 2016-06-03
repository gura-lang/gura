//----------------------------------------------------------------------------
// wxPGMultiButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGMultiButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGMultiButton
//----------------------------------------------------------------------------
Object_wx_PGMultiButton::~Object_wx_PGMultiButton()
{
}

Object *Object_wx_PGMultiButton::Clone() const
{
	return nullptr;
}

String Object_wx_PGMultiButton::ToString(bool exprFlag)
{
	String rtn("<wx.PGMultiButton:");
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
Gura_DeclareFunctionAlias(__wxPGMultiButton, "wxPGMultiButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPGMultiButton)
{
	//int pg = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//wxPGMultiButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PGMultiButton, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, __Add)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGMultiButton, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, __Add_1)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGMultiButton, __Finalize, "Finalize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propGrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, __Finalize)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int propGrid = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->Finalize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGMultiButton, __GetButton, "GetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, __GetButton)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGMultiButton, __GetButtonId, "GetButtonId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGMultiButton, __GetButtonId)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetButtonId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGMultiButton, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGMultiButton, __GetCount)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGMultiButton, __GetPrimarySize, "GetPrimarySize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGMultiButton, __GetPrimarySize)
{
	Object_wx_PGMultiButton *pThis = Object_wx_PGMultiButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrimarySize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGMultiButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGMultiButton)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPGMultiButton);
	// Method assignment
	Gura_AssignMethod(wx_PGMultiButton, __Add);
	Gura_AssignMethod(wx_PGMultiButton, __Add_1);
	Gura_AssignMethod(wx_PGMultiButton, __Finalize);
	Gura_AssignMethod(wx_PGMultiButton, __GetButton);
	Gura_AssignMethod(wx_PGMultiButton, __GetButtonId);
	Gura_AssignMethod(wx_PGMultiButton, __GetCount);
	Gura_AssignMethod(wx_PGMultiButton, __GetPrimarySize);
}

Gura_ImplementDescendantCreator(wx_PGMultiButton)
{
	return new Object_wx_PGMultiButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
