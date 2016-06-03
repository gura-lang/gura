//----------------------------------------------------------------------------
// wxDebugReportCompress
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportCompress
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Object_wx_DebugReportCompress::~Object_wx_DebugReportCompress()
{
}

Object *Object_wx_DebugReportCompress::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportCompress::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportCompress:");
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
Gura_DeclareFunctionAlias(__DebugReportCompress, "DebugReportCompress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportCompress));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DebugReportCompress)
{
	//wxDebugReportCompress();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DebugReportCompress, __SetCompressedFileDirectory, "SetCompressedFileDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportCompress, __SetCompressedFileDirectory)
{
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetCompressedFileDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugReportCompress, __SetCompressedFileBaseName, "SetCompressedFileBaseName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportCompress, __SetCompressedFileBaseName)
{
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetCompressedFileBaseName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DebugReportCompress, __GetCompressedFileName, "GetCompressedFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReportCompress, __GetCompressedFileName)
{
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCompressedFileName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportCompress)
{
	// Constructor assignment
	Gura_AssignFunction(__DebugReportCompress);
	// Method assignment
	Gura_AssignMethod(wx_DebugReportCompress, __SetCompressedFileDirectory);
	Gura_AssignMethod(wx_DebugReportCompress, __SetCompressedFileBaseName);
	Gura_AssignMethod(wx_DebugReportCompress, __GetCompressedFileName);
}

Gura_ImplementDescendantCreator(wx_DebugReportCompress)
{
	return new Object_wx_DebugReportCompress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
