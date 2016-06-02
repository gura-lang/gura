//----------------------------------------------------------------------------
// wxFFileOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Object_wx_FFileOutputStream::~Object_wx_FFileOutputStream()
{
}

Object *Object_wx_FFileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileOutputStream:");
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
Gura_DeclareMethod(wx_FFileOutputStream, wxFFileOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileOutputStream, wxFFileOutputStream)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->wxFFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileOutputStream, wxFFileOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileOutputStream, wxFFileOutputStream_1)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->wxFFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileOutputStream, wxFFileOutputStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileOutputStream, wxFFileOutputStream_2)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//pThis->GetEntity()->wxFFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileOutputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileOutputStream, IsOk)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileOutputStream, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileOutputStream, GetFile)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileOutputStream)
{
	Gura_AssignMethod(wx_FFileOutputStream, wxFFileOutputStream);
	Gura_AssignMethod(wx_FFileOutputStream, wxFFileOutputStream_1);
	Gura_AssignMethod(wx_FFileOutputStream, wxFFileOutputStream_2);
	Gura_AssignMethod(wx_FFileOutputStream, IsOk);
	Gura_AssignMethod(wx_FFileOutputStream, GetFile);
}

Gura_ImplementDescendantCreator(wx_FFileOutputStream)
{
	return new Object_wx_FFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
