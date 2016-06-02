//----------------------------------------------------------------------------
// wxHtmlRenderingInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlRenderingInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlRenderingInfo
//----------------------------------------------------------------------------
Object_wx_HtmlRenderingInfo::~Object_wx_HtmlRenderingInfo()
{
}

Object *Object_wx_HtmlRenderingInfo::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlRenderingInfo::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlRenderingInfo:");
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
Gura_DeclareMethod(wx_HtmlRenderingInfo, wxHtmlRenderingInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, wxHtmlRenderingInfo)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlRenderingInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingInfo, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, SetSelection)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingInfo, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, GetSelection)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingInfo, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, SetStyle)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingInfo, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, GetStyle)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingInfo, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, GetState)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlRenderingInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingInfo)
{
	Gura_AssignMethod(wx_HtmlRenderingInfo, wxHtmlRenderingInfo);
	Gura_AssignMethod(wx_HtmlRenderingInfo, SetSelection);
	Gura_AssignMethod(wx_HtmlRenderingInfo, GetSelection);
	Gura_AssignMethod(wx_HtmlRenderingInfo, SetStyle);
	Gura_AssignMethod(wx_HtmlRenderingInfo, GetStyle);
	Gura_AssignMethod(wx_HtmlRenderingInfo, GetState);
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingInfo)
{
	return new Object_wx_HtmlRenderingInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
