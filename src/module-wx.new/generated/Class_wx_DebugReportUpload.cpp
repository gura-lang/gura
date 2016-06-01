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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DebugReportUpload, wxDebugReportUpload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "input", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "curl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportUpload, wxDebugReportUpload)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportUpload *pThis = Object_wx_DebugReportUpload::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//int input = arg.GetNumber(1)
	//int action = arg.GetNumber(2)
	//int curl = arg.GetNumber(3)
	//pThis->GetEntity()->wxDebugReportUpload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReportUpload, OnServerReply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reply", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportUpload, OnServerReply)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportUpload *pThis = Object_wx_DebugReportUpload::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int reply = arg.GetNumber(0)
	//pThis->GetEntity()->OnServerReply();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportUpload)
{
	Gura_AssignMethod(wx_DebugReportUpload, wxDebugReportUpload);
	Gura_AssignMethod(wx_DebugReportUpload, OnServerReply);
}

Gura_ImplementDescendantCreator(wx_DebugReportUpload)
{
	return new Object_wx_DebugReportUpload((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
