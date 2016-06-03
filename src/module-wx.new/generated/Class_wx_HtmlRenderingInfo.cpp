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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlRenderingInfo, "HtmlRenderingInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlRenderingInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlRenderingInfo)
{
	//wxHtmlRenderingInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlRenderingInfo, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, __SetSelection)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingInfo, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, __GetSelection)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingInfo, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, __SetStyle)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingInfo, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, __GetStyle)
{
	Object_wx_HtmlRenderingInfo *pThis = Object_wx_HtmlRenderingInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingInfo, __GetState, "GetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingInfo, __GetState)
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
	// Constructor assignment
	Gura_AssignFunction(__HtmlRenderingInfo);
	// Method assignment
	Gura_AssignMethod(wx_HtmlRenderingInfo, __SetSelection);
	Gura_AssignMethod(wx_HtmlRenderingInfo, __GetSelection);
	Gura_AssignMethod(wx_HtmlRenderingInfo, __SetStyle);
	Gura_AssignMethod(wx_HtmlRenderingInfo, __GetStyle);
	Gura_AssignMethod(wx_HtmlRenderingInfo, __GetState);
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingInfo)
{
	return new Object_wx_HtmlRenderingInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
