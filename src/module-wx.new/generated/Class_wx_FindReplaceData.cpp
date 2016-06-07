//----------------------------------------------------------------------------
// wxFindReplaceData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Object_wx_FindReplaceData::~Object_wx_FindReplaceData()
{
}

Object *Object_wx_FindReplaceData::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceData::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceData:");
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
Gura_DeclareFunctionAlias(__FindReplaceData, "FindReplaceData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FindReplaceData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FindReplaceData)
{
	//wxUint32 flags = arg.GetNumber(0)
	//wxFindReplaceData(flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FindReplaceData, __GetFindString, "GetFindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceData, __GetFindString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFindString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceData, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceData, __GetFlags)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceData, __GetReplaceString, "GetReplaceString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceData, __GetReplaceString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetReplaceString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceData, __SetFindString, "SetFindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, __SetFindString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->SetFindString(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceData, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, __SetFlags)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FindReplaceData, __SetReplaceString, "SetReplaceString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, __SetReplaceString)
{
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->SetReplaceString(str);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceData)
{
	// Constructor assignment
	Gura_AssignFunction(__FindReplaceData);
	// Method assignment
	Gura_AssignMethod(wx_FindReplaceData, __GetFindString);
	Gura_AssignMethod(wx_FindReplaceData, __GetFlags);
	Gura_AssignMethod(wx_FindReplaceData, __GetReplaceString);
	Gura_AssignMethod(wx_FindReplaceData, __SetFindString);
	Gura_AssignMethod(wx_FindReplaceData, __SetFlags);
	Gura_AssignMethod(wx_FindReplaceData, __SetReplaceString);
}

Gura_ImplementDescendantCreator(wx_FindReplaceData)
{
	return new Object_wx_FindReplaceData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
