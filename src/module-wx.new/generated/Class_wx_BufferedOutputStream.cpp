//----------------------------------------------------------------------------
// wxBufferedOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Object_wx_BufferedOutputStream::~Object_wx_BufferedOutputStream()
{
}

Object *Object_wx_BufferedOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedOutputStream:");
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
Gura_DeclareMethod(wx_BufferedOutputStream, wxBufferedOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedOutputStream, wxBufferedOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->wxBufferedOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedOutputStream, wxBufferedOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedOutputStream, wxBufferedOutputStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int bufsize = arg.GetNumber(1)
	//pThis->GetEntity()->wxBufferedOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedOutputStream, ~wxBufferedOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedOutputStream, ~wxBufferedOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxBufferedOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedOutputStream, SeekO)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BufferedOutputStream, SeekO)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->SeekO();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BufferedOutputStream, Sync)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BufferedOutputStream, Sync)
{
	Signal &sig = env.GetSignal();
	Object_wx_BufferedOutputStream *pThis = Object_wx_BufferedOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Sync();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedOutputStream)
{
	Gura_AssignMethod(wx_BufferedOutputStream, wxBufferedOutputStream);
	Gura_AssignMethod(wx_BufferedOutputStream, wxBufferedOutputStream_1);
	Gura_AssignMethod(wx_BufferedOutputStream, ~wxBufferedOutputStream);
	Gura_AssignMethod(wx_BufferedOutputStream, SeekO);
	Gura_AssignMethod(wx_BufferedOutputStream, Sync);
}

Gura_ImplementDescendantCreator(wx_BufferedOutputStream)
{
	return new Object_wx_BufferedOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
