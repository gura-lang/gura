//----------------------------------------------------------------------------
// wxHTTP
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHTTP
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHTTP
//----------------------------------------------------------------------------
Object_wx_HTTP::~Object_wx_HTTP()
{
}

Object *Object_wx_HTTP::Clone() const
{
	return nullptr;
}

String Object_wx_HTTP::ToString(bool exprFlag)
{
	String rtn("<wx.HTTP:");
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
Gura_DeclareMethod(wx_HTTP, wxHTTP)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTTP, wxHTTP)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHTTP();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, Connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, Connect)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, Connect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, Connect_1)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//int port = arg.GetNumber(1)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, Connect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, Connect_2)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int addr = arg.GetNumber(0)
	//int wait = arg.GetNumber(1)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, GetHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, GetHeader)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeader();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, GetInputStream)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, GetResponse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTTP, GetResponse)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetResponse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, SetMethod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, SetMethod)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int method = arg.GetNumber(0)
	//pThis->GetEntity()->SetMethod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, SetHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h_data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, SetHeader)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//int h_data = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeader();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, GetCookie)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, GetCookie)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cookie = arg.GetNumber(0)
	//pThis->GetEntity()->GetCookie();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, HasCookies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTTP, HasCookies)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCookies();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, SetPostBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contentType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, SetPostBuffer)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int contentType = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetPostBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HTTP, SetPostText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contentType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, SetPostText)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int contentType = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->SetPostText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHTTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTTP)
{
	Gura_AssignMethod(wx_HTTP, wxHTTP);
	Gura_AssignMethod(wx_HTTP, Connect);
	Gura_AssignMethod(wx_HTTP, Connect_1);
	Gura_AssignMethod(wx_HTTP, Connect_2);
	Gura_AssignMethod(wx_HTTP, GetHeader);
	Gura_AssignMethod(wx_HTTP, GetInputStream);
	Gura_AssignMethod(wx_HTTP, GetResponse);
	Gura_AssignMethod(wx_HTTP, SetMethod);
	Gura_AssignMethod(wx_HTTP, SetHeader);
	Gura_AssignMethod(wx_HTTP, GetCookie);
	Gura_AssignMethod(wx_HTTP, HasCookies);
	Gura_AssignMethod(wx_HTTP, SetPostBuffer);
	Gura_AssignMethod(wx_HTTP, SetPostText);
}

Gura_ImplementDescendantCreator(wx_HTTP)
{
	return new Object_wx_HTTP((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
