//----------------------------------------------------------------------------
// wxHtmlLinkEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlLinkEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Object_wx_HtmlLinkEvent::~Object_wx_HtmlLinkEvent()
{
}

Object *Object_wx_HtmlLinkEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlLinkEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlLinkEvent:");
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
Gura_DeclareFunctionAlias(__wxHtmlLinkEvent, "wxHtmlLinkEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "linkinfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxHtmlLinkEvent)
{
	//int id = arg.GetNumber(0)
	//int linkinfo = arg.GetNumber(1)
	//wxHtmlLinkEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlLinkEvent, __GetLinkInfo, "GetLinkInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkEvent, __GetLinkInfo)
{
	Object_wx_HtmlLinkEvent *pThis = Object_wx_HtmlLinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLinkInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlLinkEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxHtmlLinkEvent);
	// Method assignment
	Gura_AssignMethod(wx_HtmlLinkEvent, __GetLinkInfo);
}

Gura_ImplementDescendantCreator(wx_HtmlLinkEvent)
{
	return new Object_wx_HtmlLinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
