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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FFileInputStream, "FFileInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileInputStream)
{
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//wxFFileInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FFileInputStream_1, "FFileInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileInputStream_1)
{
	//int file = arg.GetNumber(0)
	//wxFFileInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FFileInputStream_2, "FFileInputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileInputStream_2)
{
	//int fp = arg.GetNumber(0)
	//wxFFileInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FFileInputStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileInputStream, __IsOk)
{
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFileInputStream, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileInputStream, __GetFile)
{
	Object_wx_FFileInputStream *pThis = Object_wx_FFileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__FFileInputStream);
	Gura_AssignFunction(__FFileInputStream_1);
	Gura_AssignFunction(__FFileInputStream_2);
	// Method assignment
	Gura_AssignMethod(wx_FFileInputStream, __IsOk);
	Gura_AssignMethod(wx_FFileInputStream, __GetFile);
}

Gura_ImplementDescendantCreator(wx_FFileInputStream)
{
	return new Object_wx_FFileInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
