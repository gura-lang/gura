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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DebugReportCompress, wxDebugReportCompress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReportCompress, wxDebugReportCompress)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDebugReportCompress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReportCompress, SetCompressedFileDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportCompress, SetCompressedFileDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetCompressedFileDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReportCompress, SetCompressedFileBaseName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportCompress, SetCompressedFileBaseName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetCompressedFileBaseName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReportCompress, GetCompressedFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReportCompress, GetCompressedFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportCompress *pThis = Object_wx_DebugReportCompress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCompressedFileName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportCompress)
{
	Gura_AssignMethod(wx_DebugReportCompress, wxDebugReportCompress);
	Gura_AssignMethod(wx_DebugReportCompress, SetCompressedFileDirectory);
	Gura_AssignMethod(wx_DebugReportCompress, SetCompressedFileBaseName);
	Gura_AssignMethod(wx_DebugReportCompress, GetCompressedFileName);
}

Gura_ImplementDescendantCreator(wx_DebugReportCompress)
{
	return new Object_wx_DebugReportCompress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
