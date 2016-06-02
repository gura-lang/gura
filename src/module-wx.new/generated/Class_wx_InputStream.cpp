//----------------------------------------------------------------------------
// wxInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInputStream
//----------------------------------------------------------------------------
Object_wx_InputStream::~Object_wx_InputStream()
{
}

Object *Object_wx_InputStream::Clone() const
{
	return nullptr;
}

String Object_wx_InputStream::ToString(bool exprFlag)
{
	String rtn("<wx.InputStream:");
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
Gura_DeclareMethod(wx_InputStream, wxInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, wxInputStream)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, CanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, CanRead)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, Eof)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Eof();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, GetC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, GetC)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, LastRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, LastRead)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LastRead();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, Peek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, Peek)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Peek();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, Read)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, Read_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream_out", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, Read_1)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream_out = arg.GetNumber(0)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, ReadAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, ReadAll)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, SeekI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, SeekI)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->SeekI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, TellI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, TellI)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TellI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, Ungetch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, Ungetch)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Ungetch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, Ungetch_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, Ungetch_1)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->Ungetch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InputStream, OnSysRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, OnSysRead)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int bufsize = arg.GetNumber(1)
	//pThis->GetEntity()->OnSysRead();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InputStream)
{
	Gura_AssignMethod(wx_InputStream, wxInputStream);
	Gura_AssignMethod(wx_InputStream, CanRead);
	Gura_AssignMethod(wx_InputStream, Eof);
	Gura_AssignMethod(wx_InputStream, GetC);
	Gura_AssignMethod(wx_InputStream, LastRead);
	Gura_AssignMethod(wx_InputStream, Peek);
	Gura_AssignMethod(wx_InputStream, Read);
	Gura_AssignMethod(wx_InputStream, Read_1);
	Gura_AssignMethod(wx_InputStream, ReadAll);
	Gura_AssignMethod(wx_InputStream, SeekI);
	Gura_AssignMethod(wx_InputStream, TellI);
	Gura_AssignMethod(wx_InputStream, Ungetch);
	Gura_AssignMethod(wx_InputStream, Ungetch_1);
	Gura_AssignMethod(wx_InputStream, OnSysRead);
}

Gura_ImplementDescendantCreator(wx_InputStream)
{
	return new Object_wx_InputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
