//----------------------------------------------------------------------------
// wxTarInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarInputStream
//----------------------------------------------------------------------------
Object_wx_TarInputStream::~Object_wx_TarInputStream()
{
}

Object *Object_wx_TarInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarInputStream:");
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
Gura_DeclareMethod(wx_TarInputStream, wxTarInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarInputStream, wxTarInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxTarInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarInputStream, wxTarInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarInputStream, wxTarInputStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxTarInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarInputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarInputStream, CloseEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarInputStream, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarInputStream, GetNextEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarInputStream, OpenEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarInputStream, OpenEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->OpenEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTarInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarInputStream)
{
	Gura_AssignMethod(wx_TarInputStream, wxTarInputStream);
	Gura_AssignMethod(wx_TarInputStream, wxTarInputStream_1);
	Gura_AssignMethod(wx_TarInputStream, CloseEntry);
	Gura_AssignMethod(wx_TarInputStream, GetNextEntry);
	Gura_AssignMethod(wx_TarInputStream, OpenEntry);
}

Gura_ImplementDescendantCreator(wx_TarInputStream)
{
	return new Object_wx_TarInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
