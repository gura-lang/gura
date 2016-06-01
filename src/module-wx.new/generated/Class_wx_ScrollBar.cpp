//----------------------------------------------------------------------------
// wxScrollBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrollBar
//----------------------------------------------------------------------------
Object_wx_ScrollBar::~Object_wx_ScrollBar()
{
}

Object *Object_wx_ScrollBar::Clone() const
{
	return nullptr;
}

String Object_wx_ScrollBar::ToString(bool exprFlag)
{
	String rtn("<wx.ScrollBar:");
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
Gura_DeclareMethod(wx_ScrollBar, wxScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, wxScrollBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, wxScrollBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, wxScrollBar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, ~wxScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, ~wxScrollBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, GetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, GetPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, GetThumbPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, GetThumbPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetThumbPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, GetThumbSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, GetThumbSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetThumbSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, SetScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, SetScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int thumbSize = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int pageSize = arg.GetNumber(3)
	//int refresh = arg.GetNumber(4)
	//pThis->GetEntity()->SetScrollbar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, SetThumbPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, SetThumbPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int viewStart = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, IsVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, IsVertical)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsVertical();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScrollBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollBar)
{
	Gura_AssignMethod(wx_ScrollBar, wxScrollBar);
	Gura_AssignMethod(wx_ScrollBar, wxScrollBar_1);
	Gura_AssignMethod(wx_ScrollBar, ~wxScrollBar);
	Gura_AssignMethod(wx_ScrollBar, Create);
	Gura_AssignMethod(wx_ScrollBar, GetPageSize);
	Gura_AssignMethod(wx_ScrollBar, GetRange);
	Gura_AssignMethod(wx_ScrollBar, GetThumbPosition);
	Gura_AssignMethod(wx_ScrollBar, GetThumbSize);
	Gura_AssignMethod(wx_ScrollBar, SetScrollbar);
	Gura_AssignMethod(wx_ScrollBar, SetThumbPosition);
	Gura_AssignMethod(wx_ScrollBar, IsVertical);
}

Gura_ImplementDescendantCreator(wx_ScrollBar)
{
	return new Object_wx_ScrollBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
