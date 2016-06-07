//----------------------------------------------------------------------------
// wxFontEnumerator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontEnumerator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontEnumerator
//----------------------------------------------------------------------------
Object_wx_FontEnumerator::~Object_wx_FontEnumerator()
{
}

Object *Object_wx_FontEnumerator::Clone() const
{
	return nullptr;
}

String Object_wx_FontEnumerator::ToString(bool exprFlag)
{
	String rtn("<wx.FontEnumerator:");
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
Gura_DeclareFunctionAlias(__FontEnumerator, "FontEnumerator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontEnumerator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontEnumerator)
{
	//wxFontEnumerator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontEnumerator, __EnumerateEncodings, "EnumerateEncodings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __EnumerateEncodings)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& font = arg.GetNumber(0)
	//pThis->GetEntity()->EnumerateEncodings(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontEnumerator, __EnumerateFacenames, "EnumerateFacenames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixedWidthOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __EnumerateFacenames)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//bool fixedWidthOnly = arg.GetNumber(1)
	//pThis->GetEntity()->EnumerateFacenames(encoding, fixedWidthOnly);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontEnumerator, __GetEncodings, "GetEncodings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __GetEncodings)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& facename = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodings(facename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontEnumerator, __GetFacenames, "GetFacenames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixedWidthOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __GetFacenames)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//bool fixedWidthOnly = arg.GetNumber(1)
	//pThis->GetEntity()->GetFacenames(encoding, fixedWidthOnly);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontEnumerator, __IsValidFacename, "IsValidFacename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __IsValidFacename)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& facename = arg.GetNumber(0)
	//pThis->GetEntity()->IsValidFacename(facename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontEnumerator, __OnFacename, "OnFacename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __OnFacename)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& font = arg.GetNumber(0)
	//pThis->GetEntity()->OnFacename(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontEnumerator, __OnFontEncoding, "OnFontEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, __OnFontEncoding)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& font = arg.GetNumber(0)
	//const wxString& encoding = arg.GetNumber(1)
	//pThis->GetEntity()->OnFontEncoding(font, encoding);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontEnumerator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontEnumerator)
{
	// Constructor assignment
	Gura_AssignFunction(__FontEnumerator);
	// Method assignment
	Gura_AssignMethod(wx_FontEnumerator, __EnumerateEncodings);
	Gura_AssignMethod(wx_FontEnumerator, __EnumerateFacenames);
	Gura_AssignMethod(wx_FontEnumerator, __GetEncodings);
	Gura_AssignMethod(wx_FontEnumerator, __GetFacenames);
	Gura_AssignMethod(wx_FontEnumerator, __IsValidFacename);
	Gura_AssignMethod(wx_FontEnumerator, __OnFacename);
	Gura_AssignMethod(wx_FontEnumerator, __OnFontEncoding);
}

Gura_ImplementDescendantCreator(wx_FontEnumerator)
{
	return new Object_wx_FontEnumerator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
