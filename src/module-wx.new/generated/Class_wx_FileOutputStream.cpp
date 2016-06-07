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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FileOutputStream, "FileOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ofileName", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileOutputStream)
{
	//const wxString& ofileName = arg.GetNumber(0)
	//wxFileOutputStream(ofileName);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileOutputStream_1, "FileOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileOutputStream_1)
{
	//wxFile& file = arg.GetNumber(0)
	//wxFileOutputStream(file);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileOutputStream_2, "FileOutputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileOutputStream_2)
{
	//int fd = arg.GetNumber(0)
	//wxFileOutputStream(fd);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileOutputStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileOutputStream, __IsOk)
{
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileOutputStream, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileOutputStream, __GetFile)
{
	Object_wx_FileOutputStream *pThis = Object_wx_FileOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFile* _rtn = pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__FileOutputStream);
	Gura_AssignFunction(__FileOutputStream_1);
	Gura_AssignFunction(__FileOutputStream_2);
	// Method assignment
	Gura_AssignMethod(wx_FileOutputStream, __IsOk);
	Gura_AssignMethod(wx_FileOutputStream, __GetFile);
}

Gura_ImplementDescendantCreator(wx_FileOutputStream)
{
	return new Object_wx_FileOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
