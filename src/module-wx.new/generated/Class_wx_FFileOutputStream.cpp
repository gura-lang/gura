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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FFileOutputStream, "FFileOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileOutputStream)
{
	//const wxString& filename = arg.GetNumber(0)
	//const wxString& mode = arg.GetNumber(1)
	//wxFFileOutputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FFileOutputStream_1, "FFileOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileOutputStream_1)
{
	//wxFFile& file = arg.GetNumber(0)
	//wxFFileOutputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FFileOutputStream_2, "FFileOutputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FFileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FFileOutputStream_2)
{
	//FILE* fp = arg.GetNumber(0)
	//wxFFileOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FFileOutputStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileOutputStream, __IsOk)
{
	Object_wx_FFileOutputStream *pThis = Object_wx_FFileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFileOutputStream, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFileOutputStream, __GetFile)
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
	// Constructor assignment
	Gura_AssignFunction(__FFileOutputStream);
	Gura_AssignFunction(__FFileOutputStream_1);
	Gura_AssignFunction(__FFileOutputStream_2);
	// Method assignment
	Gura_AssignMethod(wx_FFileOutputStream, __IsOk);
	Gura_AssignMethod(wx_FFileOutputStream, __GetFile);
}

Gura_ImplementDescendantCreator(wx_FFileOutputStream)
{
	return new Object_wx_FFileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
