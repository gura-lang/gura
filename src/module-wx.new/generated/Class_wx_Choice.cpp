//----------------------------------------------------------------------------
// wxChoice
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChoice
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChoice
//----------------------------------------------------------------------------
Object_wx_Choice::~Object_wx_Choice()
{
}

Object *Object_wx_Choice::Clone() const
{
	return nullptr;
}

String Object_wx_Choice::ToString(bool exprFlag)
{
	String rtn("<wx.Choice:");
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
Gura_DeclareFunctionAlias(__Choice, "Choice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Choice));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Choice)
{
	//wxChoice();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Choice_1, "Choice_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Choice));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Choice_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxChoice(parent, id, pos, size, n, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Choice_2, "Choice_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Choice));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Choice_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxChoice(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Choice, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __Create)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//int n = arg.GetNumber(4)
	//const wxString choices[] _arg5 = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, n, _arg5, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __Create_1)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayString& choices = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __GetColumns, "GetColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Choice, __GetColumns)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __GetCurrentSelection, "GetCurrentSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Choice, __GetCurrentSelection)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCurrentSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __SetColumns, "SetColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __SetColumns)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumns(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __IsSorted, "IsSorted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Choice, __IsSorted)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsSorted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Choice, __GetCount)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Choice, __GetSelection)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __SetSelection)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __FindString, "FindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __FindString)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//bool bCase = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->FindString(s, bCase);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __GetString)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetString(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Choice, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Choice, __SetString)
{
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int pos = arg.GetNumber(0)
	//const wxString& s = arg.GetNumber(1)
	//pThis->GetEntity()->SetString(pos, s);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxChoice
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choice)
{
	// Constructor assignment
	Gura_AssignFunction(__Choice);
	Gura_AssignFunction(__Choice_1);
	Gura_AssignFunction(__Choice_2);
	// Method assignment
	Gura_AssignMethod(wx_Choice, __Create);
	Gura_AssignMethod(wx_Choice, __Create_1);
	Gura_AssignMethod(wx_Choice, __GetColumns);
	Gura_AssignMethod(wx_Choice, __GetCurrentSelection);
	Gura_AssignMethod(wx_Choice, __SetColumns);
	Gura_AssignMethod(wx_Choice, __IsSorted);
	Gura_AssignMethod(wx_Choice, __GetCount);
	Gura_AssignMethod(wx_Choice, __GetSelection);
	Gura_AssignMethod(wx_Choice, __SetSelection);
	Gura_AssignMethod(wx_Choice, __FindString);
	Gura_AssignMethod(wx_Choice, __GetString);
	Gura_AssignMethod(wx_Choice, __SetString);
}

Gura_ImplementDescendantCreator(wx_Choice)
{
	return new Object_wx_Choice((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
