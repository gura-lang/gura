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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ScrollBar, "ScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScrollBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScrollBar)
{
	//wxScrollBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ScrollBar_1, "ScrollBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ScrollBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScrollBar_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxScrollBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ScrollBar, __Create, "Create")
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

Gura_ImplementMethod(wx_ScrollBar, __Create)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_ScrollBar, __GetPageSize, "GetPageSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, __GetPageSize)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollBar, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, __GetRange)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollBar, __GetThumbPosition, "GetThumbPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, __GetThumbPosition)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetThumbPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollBar, __GetThumbSize, "GetThumbSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, __GetThumbSize)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetThumbSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollBar, __SetScrollbar, "SetScrollbar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, __SetScrollbar)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int thumbSize = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int pageSize = arg.GetNumber(3)
	//int refresh = arg.GetNumber(4)
	//pThis->GetEntity()->SetScrollbar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollBar, __SetThumbPosition, "SetThumbPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, __SetThumbPosition)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int viewStart = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollBar, __IsVertical, "IsVertical")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollBar, __IsVertical)
{
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVertical();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScrollBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollBar)
{
	// Constructor assignment
	Gura_AssignFunction(__ScrollBar);
	Gura_AssignFunction(__ScrollBar_1);
	// Method assignment
	Gura_AssignMethod(wx_ScrollBar, __Create);
	Gura_AssignMethod(wx_ScrollBar, __GetPageSize);
	Gura_AssignMethod(wx_ScrollBar, __GetRange);
	Gura_AssignMethod(wx_ScrollBar, __GetThumbPosition);
	Gura_AssignMethod(wx_ScrollBar, __GetThumbSize);
	Gura_AssignMethod(wx_ScrollBar, __SetScrollbar);
	Gura_AssignMethod(wx_ScrollBar, __SetThumbPosition);
	Gura_AssignMethod(wx_ScrollBar, __IsVertical);
}

Gura_ImplementDescendantCreator(wx_ScrollBar)
{
	return new Object_wx_ScrollBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
