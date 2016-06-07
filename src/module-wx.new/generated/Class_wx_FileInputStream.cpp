//----------------------------------------------------------------------------
// wxFileInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileInputStream
//----------------------------------------------------------------------------
Object_wx_FileInputStream::~Object_wx_FileInputStream()
{
}

Object *Object_wx_FileInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileInputStream:");
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
Gura_DeclareFunctionAlias(__FileInputStream, "FileInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ifileName", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileInputStream)
{
	//const wxString& ifileName = arg.GetNumber(0)
	//wxFileInputStream(ifileName);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileInputStream_1, "FileInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileInputStream_1)
{
	//wxFile& file = arg.GetNumber(0)
	//wxFileInputStream(file);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileInputStream_2, "FileInputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileInputStream_2)
{
	//int fd = arg.GetNumber(0)
	//wxFileInputStream(fd);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileInputStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileInputStream, __IsOk)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileInputStream, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileInputStream, __GetFile)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFile* _rtn = pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__FileInputStream);
	Gura_AssignFunction(__FileInputStream_1);
	Gura_AssignFunction(__FileInputStream_2);
	// Method assignment
	Gura_AssignMethod(wx_FileInputStream, __IsOk);
	Gura_AssignMethod(wx_FileInputStream, __GetFile);
}

Gura_ImplementDescendantCreator(wx_FileInputStream)
{
	return new Object_wx_FileInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
