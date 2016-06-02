//----------------------------------------------------------------------------
// wxHtmlRenderingState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlRenderingState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlRenderingState
//----------------------------------------------------------------------------
Object_wx_HtmlRenderingState::~Object_wx_HtmlRenderingState()
{
}

Object *Object_wx_HtmlRenderingState::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlRenderingState::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlRenderingState:");
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
Gura_DeclareMethod(wx_HtmlRenderingState, wxHtmlRenderingState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, wxHtmlRenderingState)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlRenderingState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, SetSelectionState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, SetSelectionState)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, GetSelectionState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, GetSelectionState)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, SetFgColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, SetFgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->SetFgColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, GetFgColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, GetFgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFgColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, SetBgColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, SetBgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->SetBgColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, GetBgColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, GetBgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBgColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, SetBgMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, SetBgMode)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int m = arg.GetNumber(0)
	//pThis->GetEntity()->SetBgMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlRenderingState, GetBgMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, GetBgMode)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBgMode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlRenderingState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingState)
{
	Gura_AssignMethod(wx_HtmlRenderingState, wxHtmlRenderingState);
	Gura_AssignMethod(wx_HtmlRenderingState, SetSelectionState);
	Gura_AssignMethod(wx_HtmlRenderingState, GetSelectionState);
	Gura_AssignMethod(wx_HtmlRenderingState, SetFgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, GetFgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, SetBgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, GetBgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, SetBgMode);
	Gura_AssignMethod(wx_HtmlRenderingState, GetBgMode);
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingState)
{
	return new Object_wx_HtmlRenderingState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
