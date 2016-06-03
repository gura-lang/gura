//----------------------------------------------------------------------------
// wxHtmlRenderingStyle
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlRenderingStyle
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlRenderingStyle
//----------------------------------------------------------------------------
Object_wx_HtmlRenderingStyle::~Object_wx_HtmlRenderingStyle()
{
}

Object *Object_wx_HtmlRenderingStyle::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlRenderingStyle::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlRenderingStyle:");
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
Gura_DeclareMethodAlias(wx_HtmlRenderingStyle, __GetSelectedTextColour, "GetSelectedTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingStyle, __GetSelectedTextColour)
{
	Object_wx_HtmlRenderingStyle *pThis = Object_wx_HtmlRenderingStyle::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectedTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingStyle, __GetSelectedTextBgColour, "GetSelectedTextBgColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingStyle, __GetSelectedTextBgColour)
{
	Object_wx_HtmlRenderingStyle *pThis = Object_wx_HtmlRenderingStyle::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectedTextBgColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlRenderingStyle
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingStyle)
{
	Gura_AssignMethod(wx_HtmlRenderingStyle, __GetSelectedTextColour);
	Gura_AssignMethod(wx_HtmlRenderingStyle, __GetSelectedTextBgColour);
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingStyle)
{
	return new Object_wx_HtmlRenderingStyle((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
