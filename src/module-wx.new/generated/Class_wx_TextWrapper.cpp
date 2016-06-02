//----------------------------------------------------------------------------
// wxTextWrapper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextWrapper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextWrapper
//----------------------------------------------------------------------------
Object_wx_TextWrapper::~Object_wx_TextWrapper()
{
}

Object *Object_wx_TextWrapper::Clone() const
{
	return nullptr;
}

String Object_wx_TextWrapper::ToString(bool exprFlag)
{
	String rtn("<wx.TextWrapper:");
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
Gura_DeclareMethod(wx_TextWrapper, wxTextWrapper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextWrapper, wxTextWrapper)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextWrapper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextWrapper, Wrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widthMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextWrapper, Wrap)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int widthMax = arg.GetNumber(2)
	//pThis->GetEntity()->Wrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextWrapper, OnOutputLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextWrapper, OnOutputLine)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->OnOutputLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextWrapper, OnNewLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextWrapper, OnNewLine)
{
	Object_wx_TextWrapper *pThis = Object_wx_TextWrapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnNewLine();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextWrapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextWrapper)
{
	Gura_AssignMethod(wx_TextWrapper, wxTextWrapper);
	Gura_AssignMethod(wx_TextWrapper, Wrap);
	Gura_AssignMethod(wx_TextWrapper, OnOutputLine);
	Gura_AssignMethod(wx_TextWrapper, OnNewLine);
}

Gura_ImplementDescendantCreator(wx_TextWrapper)
{
	return new Object_wx_TextWrapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
