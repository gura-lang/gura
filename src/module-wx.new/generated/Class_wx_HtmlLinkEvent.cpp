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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlLinkEvent, wxHtmlLinkEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "linkinfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlLinkEvent, wxHtmlLinkEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkEvent *pThis = Object_wx_HtmlLinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int linkinfo = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlLinkEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlLinkEvent, GetLinkInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkEvent, GetLinkInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkEvent *pThis = Object_wx_HtmlLinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLinkInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlLinkEvent)
{
	Gura_AssignMethod(wx_HtmlLinkEvent, wxHtmlLinkEvent);
	Gura_AssignMethod(wx_HtmlLinkEvent, GetLinkInfo);
}

Gura_ImplementDescendantCreator(wx_HtmlLinkEvent)
{
	return new Object_wx_HtmlLinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
