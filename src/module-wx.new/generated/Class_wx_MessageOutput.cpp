//----------------------------------------------------------------------------
// wxMessageOutput
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutput
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutput
//----------------------------------------------------------------------------
Object_wx_MessageOutput::~Object_wx_MessageOutput()
{
}

Object *Object_wx_MessageOutput::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutput::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutput:");
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
Gura_DeclareMethodAlias(wx_MessageOutput, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MessageOutput, __Get)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMessageOutput* _rtn = pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageOutput, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "msgout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, __Set)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMessageOutput* msgout = arg.GetNumber(0)
	//wxMessageOutput* _rtn = pThis->GetEntity()->Set(msgout);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageOutput, __Output, "Output")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutput, __Output)
{
	Object_wx_MessageOutput *pThis = Object_wx_MessageOutput::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->Output(str);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutput
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutput)
{
	// Class assignment
	Gura_AssignValueEx("MessageOutput", Reference());
	// Method assignment
	Gura_AssignMethod(wx_MessageOutput, __Get);
	Gura_AssignMethod(wx_MessageOutput, __Set);
	Gura_AssignMethod(wx_MessageOutput, __Output);
}

Gura_ImplementDescendantCreator(wx_MessageOutput)
{
	return new Object_wx_MessageOutput((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
