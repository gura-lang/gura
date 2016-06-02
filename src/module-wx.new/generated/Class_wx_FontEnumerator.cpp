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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FontEnumerator, wxFontEnumerator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontEnumerator, wxFontEnumerator)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFontEnumerator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, EnumerateEncodings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, EnumerateEncodings)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->EnumerateEncodings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, EnumerateFacenames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixedWidthOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, EnumerateFacenames)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//int fixedWidthOnly = arg.GetNumber(1)
	//pThis->GetEntity()->EnumerateFacenames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, GetEncodings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, GetEncodings)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int facename = arg.GetNumber(0)
	//pThis->GetEntity()->GetEncodings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, GetFacenames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixedWidthOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, GetFacenames)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//int fixedWidthOnly = arg.GetNumber(1)
	//pThis->GetEntity()->GetFacenames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, IsValidFacename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "facename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, IsValidFacename)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int facename = arg.GetNumber(0)
	//pThis->GetEntity()->IsValidFacename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, OnFacename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, OnFacename)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->OnFacename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontEnumerator, OnFontEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontEnumerator, OnFontEncoding)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//pThis->GetEntity()->OnFontEncoding();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontEnumerator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontEnumerator)
{
	Gura_AssignMethod(wx_FontEnumerator, wxFontEnumerator);
	Gura_AssignMethod(wx_FontEnumerator, EnumerateEncodings);
	Gura_AssignMethod(wx_FontEnumerator, EnumerateFacenames);
	Gura_AssignMethod(wx_FontEnumerator, GetEncodings);
	Gura_AssignMethod(wx_FontEnumerator, GetFacenames);
	Gura_AssignMethod(wx_FontEnumerator, IsValidFacename);
	Gura_AssignMethod(wx_FontEnumerator, OnFacename);
	Gura_AssignMethod(wx_FontEnumerator, OnFontEncoding);
}

Gura_ImplementDescendantCreator(wx_FontEnumerator)
{
	return new Object_wx_FontEnumerator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
