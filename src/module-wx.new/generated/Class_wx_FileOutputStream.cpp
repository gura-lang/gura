//----------------------------------------------------------------------------
// wxFileOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileOutputStream
//----------------------------------------------------------------------------
Object_wx_FileOutputStream::~Object_wx_FileOutputStream()
{
}

Object *Object_wx_FileOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileOutputStream:");
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
Gura_DeclareMethod(wx_FileOutputStream, wxFileOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ofileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileOutputStream, wxFileOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ofileName = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileOutputStream, wxFileOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileOutputStream, wxFileOutputStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileOutputStream, wxFileOutputStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileOutputStream, wxFileOutputStream_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fd = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileOutputStream, ~wxFileOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileOutputStream, ~wxFileOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxFileOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileOutputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileOutputStream, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileOutputStream, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileOutputStream, GetFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileOutputStream)
{
	Gura_AssignMethod(wx_FileOutputStream, wxFileOutputStream);
	Gura_AssignMethod(wx_FileOutputStream, wxFileOutputStream_1);
	Gura_AssignMethod(wx_FileOutputStream, wxFileOutputStream_2);
	Gura_AssignMethod(wx_FileOutputStream, ~wxFileOutputStream);
	Gura_AssignMethod(wx_FileOutputStream, IsOk);
	Gura_AssignMethod(wx_FileOutputStream, GetFile);
}

Gura_ImplementDescendantCreator(wx_FileOutputStream)
{
	return new Object_wx_FileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
