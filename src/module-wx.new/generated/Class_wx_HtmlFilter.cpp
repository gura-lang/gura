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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlFilter, "HtmlFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlFilter));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlFilter)
{
	//wxHtmlFilter();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlFilter, __CanRead, "CanRead")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlFilter, __CanRead)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFSFile& file = arg.GetNumber(0)
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlFilter, __ReadFile, "ReadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlFilter, __ReadFile)
{
	Object_wx_HtmlFilter *pThis = Object_wx_HtmlFilter::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFSFile& file = arg.GetNumber(0)
	//pThis->GetEntity()->ReadFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlFilter)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlFilter);
	// Method assignment
	Gura_AssignMethod(wx_HtmlFilter, __CanRead);
	Gura_AssignMethod(wx_HtmlFilter, __ReadFile);
}

Gura_ImplementDescendantCreator(wx_HtmlFilter)
{
	return new Object_wx_HtmlFilter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
