//----------------------------------------------------------------------------
// wxHtmlLinkInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlLinkInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Object_wx_HtmlLinkInfo::~Object_wx_HtmlLinkInfo()
{
}

Object *Object_wx_HtmlLinkInfo::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlLinkInfo::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlLinkInfo:");
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
Gura_DeclareMethodAlias(wx_HtmlLinkInfo, __wxHtmlLinkInfo, "wxHtmlLinkInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, __wxHtmlLinkInfo)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlLinkInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlLinkInfo, __wxHtmlLinkInfo_1, "wxHtmlLinkInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "href", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, __wxHtmlLinkInfo_1)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int href = arg.GetNumber(0)
	//int target = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlLinkInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlLinkInfo, __GetEvent, "GetEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, __GetEvent)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlLinkInfo, __GetHref, "GetHref")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, __GetHref)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHref();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlLinkInfo, __GetHtmlCell, "GetHtmlCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, __GetHtmlCell)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHtmlCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlLinkInfo, __GetTarget, "GetTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, __GetTarget)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTarget();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlLinkInfo)
{
	Gura_AssignMethod(wx_HtmlLinkInfo, __wxHtmlLinkInfo);
	Gura_AssignMethod(wx_HtmlLinkInfo, __wxHtmlLinkInfo_1);
	Gura_AssignMethod(wx_HtmlLinkInfo, __GetEvent);
	Gura_AssignMethod(wx_HtmlLinkInfo, __GetHref);
	Gura_AssignMethod(wx_HtmlLinkInfo, __GetHtmlCell);
	Gura_AssignMethod(wx_HtmlLinkInfo, __GetTarget);
}

Gura_ImplementDescendantCreator(wx_HtmlLinkInfo)
{
	return new Object_wx_HtmlLinkInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
