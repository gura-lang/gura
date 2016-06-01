//----------------------------------------------------------------------------
// wxFFileInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Object_wx_FFileInputStream::~Object_wx_FFileInputStream()
{
}

Object *Object_wx_FFileInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileInputStream:");
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
Gura_DeclareMethod(wx_FFileInputStream, wxFFileInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileInputStream, wxFFileInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->wxFFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileInputStream, wxFFileInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileInputStream, wxFFileInputStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->wxFFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileInputStream, wxFFileInputStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFileInputStream, wxFFileInputStream_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//pThis->GetEntity()->wxFFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileInputStream, ~wxFFileInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileInputStream, ~wxFFileInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxFFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileInputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileInputStream, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFileInputStream, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileInputStream, GetFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileInputStream)
{
	Gura_AssignMethod(wx_FFileInputStream, wxFFileInputStream);
	Gura_AssignMethod(wx_FFileInputStream, wxFFileInputStream_1);
	Gura_AssignMethod(wx_FFileInputStream, wxFFileInputStream_2);
	Gura_AssignMethod(wx_FFileInputStream, ~wxFFileInputStream);
	Gura_AssignMethod(wx_FFileInputStream, IsOk);
	Gura_AssignMethod(wx_FFileInputStream, GetFile);
}

Gura_ImplementDescendantCreator(wx_FFileInputStream)
{
	return new Object_wx_FFileInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
