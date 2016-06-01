//----------------------------------------------------------------------------
// wxMemoryInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Object_wx_MemoryInputStream::~Object_wx_MemoryInputStream()
{
}

Object *Object_wx_MemoryInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryInputStream:");
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
Gura_DeclareMethod(wx_MemoryInputStream, wxMemoryInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryInputStream, wxMemoryInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryInputStream, wxMemoryInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryInputStream, wxMemoryInputStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryInputStream, wxMemoryInputStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryInputStream, wxMemoryInputStream_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryInputStream, ~wxMemoryInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryInputStream, ~wxMemoryInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryInputStream, GetInputStreamBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryInputStream, GetInputStreamBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInputStreamBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryInputStream)
{
	Gura_AssignMethod(wx_MemoryInputStream, wxMemoryInputStream);
	Gura_AssignMethod(wx_MemoryInputStream, wxMemoryInputStream_1);
	Gura_AssignMethod(wx_MemoryInputStream, wxMemoryInputStream_2);
	Gura_AssignMethod(wx_MemoryInputStream, ~wxMemoryInputStream);
	Gura_AssignMethod(wx_MemoryInputStream, GetInputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryInputStream)
{
	return new Object_wx_MemoryInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
