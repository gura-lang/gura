//----------------------------------------------------------------------------
// wxHyperlinkCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Object_wx_HyperlinkCtrl::~Object_wx_HyperlinkCtrl()
{
}

Object *Object_wx_HyperlinkCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_HyperlinkCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.HyperlinkCtrl:");
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
Gura_DeclareMethod(wx_HyperlinkCtrl, wxHyperlinkCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, wxHyperlinkCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxHyperlinkCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, wxHyperlinkCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, wxHyperlinkCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int url = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxHyperlinkCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int url = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetHoverColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetHoverColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHoverColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetNormalColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetNormalColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNormalColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetVisited)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetVisited)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisited();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, GetVisitedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, GetVisitedColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisitedColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetHoverColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetHoverColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoverColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetNormalColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetNormalColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetVisited)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visited", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetVisited)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int visited = arg.GetNumber(0)
	//pThis->GetEntity()->SetVisited();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HyperlinkCtrl, SetVisitedColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkCtrl, SetVisitedColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HyperlinkCtrl *pThis = Object_wx_HyperlinkCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetVisitedColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkCtrl)
{
	Gura_AssignMethod(wx_HyperlinkCtrl, wxHyperlinkCtrl);
	Gura_AssignMethod(wx_HyperlinkCtrl, wxHyperlinkCtrl_1);
	Gura_AssignMethod(wx_HyperlinkCtrl, Create);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetHoverColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetNormalColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetURL);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetVisited);
	Gura_AssignMethod(wx_HyperlinkCtrl, GetVisitedColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetHoverColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetNormalColour);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetURL);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetVisited);
	Gura_AssignMethod(wx_HyperlinkCtrl, SetVisitedColour);
}

Gura_ImplementDescendantCreator(wx_HyperlinkCtrl)
{
	return new Object_wx_HyperlinkCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
