//----------------------------------------------------------------------------
// wxSortedArrayString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSortedArrayString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSortedArrayString
//----------------------------------------------------------------------------
Object_wx_SortedArrayString::~Object_wx_SortedArrayString()
{
}

Object *Object_wx_SortedArrayString::Clone() const
{
	return nullptr;
}

String Object_wx_SortedArrayString::ToString(bool exprFlag)
{
	String rtn("<wx.SortedArrayString:");
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
Gura_DeclareMethod(wx_SortedArrayString, wxSortedArrayString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SortedArrayString, wxSortedArrayString)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSortedArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, wxSortedArrayString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, wxSortedArrayString_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int compareFunction = arg.GetNumber(0)
	//pThis->GetEntity()->wxSortedArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, wxSortedArrayString_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, wxSortedArrayString_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxSortedArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bFromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, Index)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//int bFromEnd = arg.GetNumber(2)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int nIndex = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, Sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reverseOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, Sort)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int reverseOrder = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SortedArrayString, Sort_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SortedArrayString, Sort_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SortedArrayString *pThis = Object_wx_SortedArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int compareFunction = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSortedArrayString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SortedArrayString)
{
	Gura_AssignMethod(wx_SortedArrayString, wxSortedArrayString);
	Gura_AssignMethod(wx_SortedArrayString, wxSortedArrayString_1);
	Gura_AssignMethod(wx_SortedArrayString, wxSortedArrayString_2);
	Gura_AssignMethod(wx_SortedArrayString, Add);
	Gura_AssignMethod(wx_SortedArrayString, Index);
	Gura_AssignMethod(wx_SortedArrayString, Insert);
	Gura_AssignMethod(wx_SortedArrayString, Sort);
	Gura_AssignMethod(wx_SortedArrayString, Sort_1);
}

Gura_ImplementDescendantCreator(wx_SortedArrayString)
{
	return new Object_wx_SortedArrayString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
