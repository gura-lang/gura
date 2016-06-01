//----------------------------------------------------------------------------
// wxStreamBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStreamBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStreamBase
//----------------------------------------------------------------------------
Object_wx_StreamBase::~Object_wx_StreamBase()
{
}

Object *Object_wx_StreamBase::Clone() const
{
	return nullptr;
}

String Object_wx_StreamBase::ToString(bool exprFlag)
{
	String rtn("<wx.StreamBase:");
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
Gura_DeclareMethod(wx_StreamBase, wxStreamBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, wxStreamBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxStreamBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, ~wxStreamBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, ~wxStreamBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxStreamBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, GetLastError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, GetLastError)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLastError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, GetLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, IsSeekable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, IsSeekable)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSeekable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "error", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBase, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int error = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, OnSysSeek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StreamBase, OnSysSeek)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->OnSysSeek();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StreamBase, OnSysTell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StreamBase, OnSysTell)
{
	Signal &sig = env.GetSignal();
	Object_wx_StreamBase *pThis = Object_wx_StreamBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnSysTell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStreamBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StreamBase)
{
	Gura_AssignMethod(wx_StreamBase, wxStreamBase);
	Gura_AssignMethod(wx_StreamBase, ~wxStreamBase);
	Gura_AssignMethod(wx_StreamBase, GetLastError);
	Gura_AssignMethod(wx_StreamBase, GetLength);
	Gura_AssignMethod(wx_StreamBase, GetSize);
	Gura_AssignMethod(wx_StreamBase, IsOk);
	Gura_AssignMethod(wx_StreamBase, IsSeekable);
	Gura_AssignMethod(wx_StreamBase, Reset);
	Gura_AssignMethod(wx_StreamBase, OnSysSeek);
	Gura_AssignMethod(wx_StreamBase, OnSysTell);
}

Gura_ImplementDescendantCreator(wx_StreamBase)
{
	return new Object_wx_StreamBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
