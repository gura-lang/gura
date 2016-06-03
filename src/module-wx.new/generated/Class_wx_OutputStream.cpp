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
Gura_DeclareMethodAlias(wx_OutputStream, __wxOutputStream, "wxOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __wxOutputStream)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxOutputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __Close)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __LastWrite, "LastWrite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __LastWrite)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LastWrite();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __PutC, "PutC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __PutC)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->PutC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __SeekO, "SeekO")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __SeekO)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->SeekO();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __TellO, "TellO")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __TellO)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TellO();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __Write)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __Write_1, "Write_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream_in", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __Write_1)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream_in = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __WriteAll, "WriteAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __WriteAll)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->WriteAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __OnSysWrite, "OnSysWrite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __OnSysWrite)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	Gura_AssignMethod(wx_OutputStream, __wxOutputStream);
	Gura_AssignMethod(wx_OutputStream, __Close);
	Gura_AssignMethod(wx_OutputStream, __LastWrite);
	Gura_AssignMethod(wx_OutputStream, __PutC);
	Gura_AssignMethod(wx_OutputStream, __SeekO);
	Gura_AssignMethod(wx_OutputStream, __TellO);
	Gura_AssignMethod(wx_OutputStream, __Write);
	Gura_AssignMethod(wx_OutputStream, __Write_1);
	Gura_AssignMethod(wx_OutputStream, __WriteAll);
	Gura_AssignMethod(wx_OutputStream, __OnSysWrite);
}

Gura_ImplementDescendantCreator(wx_OutputStream)
{
	return new Object_wx_OutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
