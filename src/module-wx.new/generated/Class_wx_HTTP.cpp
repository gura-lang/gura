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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HTTP, "HTTP")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HTTP));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HTTP)
{
	//wxHTTP();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HTTP, __Connect, "Connect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __Connect)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& host = arg.GetNumber(0)
	//pThis->GetEntity()->Connect(host);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __Connect_1, "Connect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __Connect_1)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& host = arg.GetNumber(0)
	//unsigned short port = arg.GetNumber(1)
	//pThis->GetEntity()->Connect(host, port);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __Connect_2, "Connect_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __Connect_2)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSockAddress& addr = arg.GetNumber(0)
	//bool wait = arg.GetNumber(1)
	//pThis->GetEntity()->Connect(addr, wait);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __GetHeader, "GetHeader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __GetHeader)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& header = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeader(header);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __GetInputStream, "GetInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __GetInputStream)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->GetInputStream(path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __GetResponse, "GetResponse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTTP, __GetResponse)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetResponse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __SetMethod, "SetMethod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __SetMethod)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& method = arg.GetNumber(0)
	//pThis->GetEntity()->SetMethod(method);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __SetHeader, "SetHeader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h_data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __SetHeader)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& header = arg.GetNumber(0)
	//const wxString& h_data = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeader(header, h_data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __GetCookie, "GetCookie")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __GetCookie)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& cookie = arg.GetNumber(0)
	//pThis->GetEntity()->GetCookie(cookie);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __HasCookies, "HasCookies")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HTTP, __HasCookies)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCookies();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __SetPostBuffer, "SetPostBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contentType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __SetPostBuffer)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& contentType = arg.GetNumber(0)
	//const wxMemoryBuffer& data = arg.GetNumber(1)
	//pThis->GetEntity()->SetPostBuffer(contentType, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HTTP, __SetPostText, "SetPostText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contentType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HTTP, __SetPostText)
{
	Object_wx_HTTP *pThis = Object_wx_HTTP::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& contentType = arg.GetNumber(0)
	//const wxString& data = arg.GetNumber(1)
	//const wxMBConv& conv = arg.GetNumber(2)
	//pThis->GetEntity()->SetPostText(contentType, data, conv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHTTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTTP)
{
	// Constructor assignment
	Gura_AssignFunction(__HTTP);
	// Method assignment
	Gura_AssignMethod(wx_HTTP, __Connect);
	Gura_AssignMethod(wx_HTTP, __Connect_1);
	Gura_AssignMethod(wx_HTTP, __Connect_2);
	Gura_AssignMethod(wx_HTTP, __GetHeader);
	Gura_AssignMethod(wx_HTTP, __GetInputStream);
	Gura_AssignMethod(wx_HTTP, __GetResponse);
	Gura_AssignMethod(wx_HTTP, __SetMethod);
	Gura_AssignMethod(wx_HTTP, __SetHeader);
	Gura_AssignMethod(wx_HTTP, __GetCookie);
	Gura_AssignMethod(wx_HTTP, __HasCookies);
	Gura_AssignMethod(wx_HTTP, __SetPostBuffer);
	Gura_AssignMethod(wx_HTTP, __SetPostText);
}

Gura_ImplementDescendantCreator(wx_HTTP)
{
	return new Object_wx_HTTP((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
