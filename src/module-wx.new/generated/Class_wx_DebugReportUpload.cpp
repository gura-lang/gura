//----------------------------------------------------------------------------
// wxDebugReportUpload
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportUpload
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Object_wx_DebugReportUpload::~Object_wx_DebugReportUpload()
{
}

Object *Object_wx_DebugReportUpload::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportUpload::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportUpload:");
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
Gura_DeclareFunctionAlias(__DebugReportUpload, "DebugReportUpload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "curl", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportUpload));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DebugReportUpload)
{
	//const wxString& url = arg.GetNumber(0)
	//const wxString& input = arg.GetNumber(1)
	//const wxString& action = arg.GetNumber(2)
	//const wxString& curl = arg.GetNumber(3)
	//wxDebugReportUpload();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DebugReportUpload, __OnServerReply, "OnServerReply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reply", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportUpload, __OnServerReply)
{
	Object_wx_DebugReportUpload *pThis = Object_wx_DebugReportUpload::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& reply = arg.GetNumber(0)
	//pThis->GetEntity()->OnServerReply();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportUpload)
{
	// Constructor assignment
	Gura_AssignFunction(__DebugReportUpload);
	// Method assignment
	Gura_AssignMethod(wx_DebugReportUpload, __OnServerReply);
}

Gura_ImplementDescendantCreator(wx_DebugReportUpload)
{
	return new Object_wx_DebugReportUpload((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
