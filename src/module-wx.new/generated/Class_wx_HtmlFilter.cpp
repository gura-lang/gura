//----------------------------------------------------------------------------
// wxHtmlFilter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlFilter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Object_wx_HtmlFilter::~Object_wx_HtmlFilter()
{
}

Object *Object_wx_HtmlFilter::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlFilter::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlFilter:");
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
Gura_DeclareMethod(wx_HtmlFilter, wxHtmlFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlFilter, wxHtmlFilter)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlFilter, CanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlFilter, CanRead)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlFilter, ReadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlFilter, ReadFile)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->ReadFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlFilter)
{
	Gura_AssignMethod(wx_HtmlFilter, wxHtmlFilter);
	Gura_AssignMethod(wx_HtmlFilter, CanRead);
	Gura_AssignMethod(wx_HtmlFilter, ReadFile);
}

Gura_ImplementDescendantCreator(wx_HtmlFilter)
{
	return new Object_wx_HtmlFilter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
