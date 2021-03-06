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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__OutputStream, "OutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_OutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__OutputStream)
{
	//wxOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_OutputStream, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __Close)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __LastWrite, "LastWrite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __LastWrite)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->LastWrite();
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
	//char c = arg.GetNumber(0)
	//pThis->GetEntity()->PutC(c);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __SeekO, "SeekO")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __SeekO)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileOffset pos = arg.GetNumber(0)
	//wxSeekMode mode = arg.GetNumber(1)
	//wxFileOffset _rtn = pThis->GetEntity()->SeekO(pos, mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __TellO, "TellO")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OutputStream, __TellO)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileOffset _rtn = pThis->GetEntity()->TellO();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __Write)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//wxOutputStream& _rtn = pThis->GetEntity()->Write(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __Write_1, "Write_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream_in", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __Write_1)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream& stream_in = arg.GetNumber(0)
	//wxOutputStream& _rtn = pThis->GetEntity()->Write(stream_in);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __WriteAll, "WriteAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __WriteAll)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->WriteAll(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OutputStream, __OnSysWrite, "OnSysWrite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OutputStream, __OnSysWrite)
{
	Object_wx_OutputStream *pThis = Object_wx_OutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* buffer = arg.GetNumber(0)
	//size_t bufsize = arg.GetNumber(1)
	//size_t _rtn = pThis->GetEntity()->OnSysWrite(buffer, bufsize);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__OutputStream);
	// Method assignment
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
