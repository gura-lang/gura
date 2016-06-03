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
Gura_DeclareMethodAlias(wx_InputStream, __wxInputStream, "wxInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __wxInputStream)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __CanRead, "CanRead")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __CanRead)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __Eof, "Eof")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __Eof)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Eof();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __GetC, "GetC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __GetC)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __LastRead, "LastRead")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __LastRead)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LastRead();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __Peek, "Peek")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __Peek)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Peek();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __Read, "Read")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __Read)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __Read_1, "Read_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream_out", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __Read_1)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream_out = arg.GetNumber(0)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __ReadAll, "ReadAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __ReadAll)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __SeekI, "SeekI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __SeekI)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->SeekI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __TellI, "TellI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InputStream, __TellI)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TellI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __Ungetch, "Ungetch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __Ungetch)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Ungetch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __Ungetch_1, "Ungetch_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __Ungetch_1)
{
	Object_wx_InputStream *pThis = Object_wx_InputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->Ungetch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InputStream, __OnSysRead, "OnSysRead")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InputStream, __OnSysRead)
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
	Gura_AssignMethod(wx_InputStream, __wxInputStream);
	Gura_AssignMethod(wx_InputStream, __CanRead);
	Gura_AssignMethod(wx_InputStream, __Eof);
	Gura_AssignMethod(wx_InputStream, __GetC);
	Gura_AssignMethod(wx_InputStream, __LastRead);
	Gura_AssignMethod(wx_InputStream, __Peek);
	Gura_AssignMethod(wx_InputStream, __Read);
	Gura_AssignMethod(wx_InputStream, __Read_1);
	Gura_AssignMethod(wx_InputStream, __ReadAll);
	Gura_AssignMethod(wx_InputStream, __SeekI);
	Gura_AssignMethod(wx_InputStream, __TellI);
	Gura_AssignMethod(wx_InputStream, __Ungetch);
	Gura_AssignMethod(wx_InputStream, __Ungetch_1);
	Gura_AssignMethod(wx_InputStream, __OnSysRead);
}

Gura_ImplementDescendantCreator(wx_InputStream)
{
	return new Object_wx_InputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
