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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlRenderingState, "HtmlRenderingState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlRenderingState));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlRenderingState)
{
	//wxHtmlRenderingState();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlRenderingState, __SetSelectionState, "SetSelectionState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __SetSelectionState)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlSelectionState s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionState(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __GetSelectionState, "GetSelectionState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __GetSelectionState)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlSelectionState _rtn = pThis->GetEntity()->GetSelectionState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __SetFgColour, "SetFgColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __SetFgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& c = arg.GetNumber(0)
	//pThis->GetEntity()->SetFgColour(c);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __GetFgColour, "GetFgColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __GetFgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetFgColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __SetBgColour, "SetBgColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __SetBgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& c = arg.GetNumber(0)
	//pThis->GetEntity()->SetBgColour(c);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __GetBgColour, "GetBgColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __GetBgColour)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetBgColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __SetBgMode, "SetBgMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "m", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __SetBgMode)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int m = arg.GetNumber(0)
	//pThis->GetEntity()->SetBgMode(m);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlRenderingState, __GetBgMode, "GetBgMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlRenderingState, __GetBgMode)
{
	Object_wx_HtmlRenderingState *pThis = Object_wx_HtmlRenderingState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetBgMode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlRenderingState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingState)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlRenderingState);
	// Method assignment
	Gura_AssignMethod(wx_HtmlRenderingState, __SetSelectionState);
	Gura_AssignMethod(wx_HtmlRenderingState, __GetSelectionState);
	Gura_AssignMethod(wx_HtmlRenderingState, __SetFgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, __GetFgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, __SetBgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, __GetBgColour);
	Gura_AssignMethod(wx_HtmlRenderingState, __SetBgMode);
	Gura_AssignMethod(wx_HtmlRenderingState, __GetBgMode);
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingState)
{
	return new Object_wx_HtmlRenderingState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
