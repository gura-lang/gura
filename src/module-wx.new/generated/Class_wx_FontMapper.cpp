//----------------------------------------------------------------------------
// wxFontMapper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontMapper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontMapper
//----------------------------------------------------------------------------
Object_wx_FontMapper::~Object_wx_FontMapper()
{
}

Object *Object_wx_FontMapper::Clone() const
{
	return nullptr;
}

String Object_wx_FontMapper::ToString(bool exprFlag)
{
	String rtn("<wx.FontMapper:");
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
Gura_DeclareMethod(wx_FontMapper, wxFontMapper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontMapper, wxFontMapper)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFontMapper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, ~wxFontMapper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontMapper, ~wxFontMapper)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxFontMapper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, CharsetToEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "charset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, CharsetToEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int charset = arg.GetNumber(0)
	//int interactive = arg.GetNumber(1)
	//pThis->GetEntity()->CharsetToEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontMapper, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetAllEncodingNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetAllEncodingNames)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetAllEncodingNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetAltForEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetAltForEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//int info = arg.GetNumber(1)
	//int facename = arg.GetNumber(2)
	//int interactive = arg.GetNumber(3)
	//pThis->GetEntity()->GetAltForEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetAltForEncoding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alt_encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetAltForEncoding_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//int alt_encoding = arg.GetNumber(1)
	//int facename = arg.GetNumber(2)
	//int interactive = arg.GetNumber(3)
	//pThis->GetEntity()->GetAltForEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetEncodingDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetEncodingDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodingDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetEncodingFromName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetEncodingFromName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodingFromName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetEncodingName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, GetEncodingName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodingName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, GetSupportedEncodingsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontMapper, GetSupportedEncodingsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSupportedEncodingsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, IsEncodingAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, IsEncodingAvailable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//int facename = arg.GetNumber(1)
	//pThis->GetEntity()->IsEncodingAvailable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mapper", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mapper = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, SetConfigPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetConfigPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->SetConfigPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, SetDialogParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetDialogParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetDialogParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, SetDialogTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetDialogTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetDialogTitle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontMapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontMapper)
{
	Gura_AssignMethod(wx_FontMapper, wxFontMapper);
	Gura_AssignMethod(wx_FontMapper, ~wxFontMapper);
	Gura_AssignMethod(wx_FontMapper, CharsetToEncoding);
	Gura_AssignMethod(wx_FontMapper, Get);
	Gura_AssignMethod(wx_FontMapper, GetAllEncodingNames);
	Gura_AssignMethod(wx_FontMapper, GetAltForEncoding);
	Gura_AssignMethod(wx_FontMapper, GetAltForEncoding_1);
	Gura_AssignMethod(wx_FontMapper, GetEncoding);
	Gura_AssignMethod(wx_FontMapper, GetEncodingDescription);
	Gura_AssignMethod(wx_FontMapper, GetEncodingFromName);
	Gura_AssignMethod(wx_FontMapper, GetEncodingName);
	Gura_AssignMethod(wx_FontMapper, GetSupportedEncodingsCount);
	Gura_AssignMethod(wx_FontMapper, IsEncodingAvailable);
	Gura_AssignMethod(wx_FontMapper, Set);
	Gura_AssignMethod(wx_FontMapper, SetConfigPath);
	Gura_AssignMethod(wx_FontMapper, SetDialogParent);
	Gura_AssignMethod(wx_FontMapper, SetDialogTitle);
}

Gura_ImplementDescendantCreator(wx_FontMapper)
{
	return new Object_wx_FontMapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
