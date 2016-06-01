//----------------------------------------------------------------------------
// wxOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxOutputStream
//----------------------------------------------------------------------------
Object_wx_OutputStream::~Object_wx_OutputStream()
{
}

Object *Object_wx_OutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_OutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.OutputStream:");
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
Gura_DeclareMethod(wx_OutputStream, wxOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, wxOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, ~wxOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, ~wxOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, LastWrite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, LastWrite)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LastWrite();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, PutC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, PutC)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->PutC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, SeekO)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, SeekO)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->SeekO();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, TellO)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, TellO)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->TellO();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, Write)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream_in", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, Write_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream_in = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, WriteAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, WriteAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->WriteAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_OutputStream, OnSysWrite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, OnSysWrite)
{
	Signal &sig = env.GetSignal();
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int bufsize = arg.GetNumber(1)
	//pThis->GetEntity()->OnSysWrite();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OutputStream)
{
	Gura_AssignMethod(wx_OutputStream, wxOutputStream);
	Gura_AssignMethod(wx_OutputStream, ~wxOutputStream);
	Gura_AssignMethod(wx_OutputStream, Close);
	Gura_AssignMethod(wx_OutputStream, LastWrite);
	Gura_AssignMethod(wx_OutputStream, PutC);
	Gura_AssignMethod(wx_OutputStream, SeekO);
	Gura_AssignMethod(wx_OutputStream, TellO);
	Gura_AssignMethod(wx_OutputStream, Write);
	Gura_AssignMethod(wx_OutputStream, Write_1);
	Gura_AssignMethod(wx_OutputStream, WriteAll);
	Gura_AssignMethod(wx_OutputStream, OnSysWrite);
}

Gura_ImplementDescendantCreator(wx_OutputStream)
{
	return new Object_wx_OutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
