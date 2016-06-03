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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FontMapper, "FontMapper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontMapper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontMapper)
{
	//wxFontMapper();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontMapper, __CharsetToEncoding, "CharsetToEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "charset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __CharsetToEncoding)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& charset = arg.GetNumber(0)
	//bool interactive = arg.GetNumber(1)
	//pThis->GetEntity()->CharsetToEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontMapper, __Get)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetAllEncodingNames, "GetAllEncodingNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetAllEncodingNames)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetAllEncodingNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetAltForEncoding, "GetAltForEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetAltForEncoding)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//wxNativeEncodingInfo* info = arg.GetNumber(1)
	//const wxString& facename = arg.GetNumber(2)
	//bool interactive = arg.GetNumber(3)
	//pThis->GetEntity()->GetAltForEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetAltForEncoding_1, "GetAltForEncoding_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alt_encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "interactive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetAltForEncoding_1)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//wxFontEncoding* alt_encoding = arg.GetNumber(1)
	//const wxString& facename = arg.GetNumber(2)
	//bool interactive = arg.GetNumber(3)
	//pThis->GetEntity()->GetAltForEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetEncoding, "GetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetEncoding)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetEncodingDescription, "GetEncodingDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetEncodingDescription)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodingDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetEncodingFromName, "GetEncodingFromName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetEncodingFromName)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodingFromName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetEncodingName, "GetEncodingName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __GetEncodingName)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodingName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __GetSupportedEncodingsCount, "GetSupportedEncodingsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontMapper, __GetSupportedEncodingsCount)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSupportedEncodingsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __IsEncodingAvailable, "IsEncodingAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __IsEncodingAvailable)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//const wxString& facename = arg.GetNumber(1)
	//pThis->GetEntity()->IsEncodingAvailable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mapper", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __Set)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontMapper* mapper = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __SetConfigPath, "SetConfigPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __SetConfigPath)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& prefix = arg.GetNumber(0)
	//pThis->GetEntity()->SetConfigPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __SetDialogParent, "SetDialogParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __SetDialogParent)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetDialogParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontMapper, __SetDialogTitle, "SetDialogTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, __SetDialogTitle)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->SetDialogTitle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontMapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontMapper)
{
	// Constructor assignment
	Gura_AssignFunction(__FontMapper);
	// Method assignment
	Gura_AssignMethod(wx_FontMapper, __CharsetToEncoding);
	Gura_AssignMethod(wx_FontMapper, __Get);
	Gura_AssignMethod(wx_FontMapper, __GetAllEncodingNames);
	Gura_AssignMethod(wx_FontMapper, __GetAltForEncoding);
	Gura_AssignMethod(wx_FontMapper, __GetAltForEncoding_1);
	Gura_AssignMethod(wx_FontMapper, __GetEncoding);
	Gura_AssignMethod(wx_FontMapper, __GetEncodingDescription);
	Gura_AssignMethod(wx_FontMapper, __GetEncodingFromName);
	Gura_AssignMethod(wx_FontMapper, __GetEncodingName);
	Gura_AssignMethod(wx_FontMapper, __GetSupportedEncodingsCount);
	Gura_AssignMethod(wx_FontMapper, __IsEncodingAvailable);
	Gura_AssignMethod(wx_FontMapper, __Set);
	Gura_AssignMethod(wx_FontMapper, __SetConfigPath);
	Gura_AssignMethod(wx_FontMapper, __SetDialogParent);
	Gura_AssignMethod(wx_FontMapper, __SetDialogTitle);
}

Gura_ImplementDescendantCreator(wx_FontMapper)
{
	return new Object_wx_FontMapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
