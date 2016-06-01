//----------------------------------------------------------------------------
// wxVarHScrollHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarHScrollHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarHScrollHelper
//----------------------------------------------------------------------------
Object_wx_VarHScrollHelper::~Object_wx_VarHScrollHelper()
{
}

Object *Object_wx_VarHScrollHelper::Clone() const
{
	return nullptr;
}

String Object_wx_VarHScrollHelper::ToString(bool exprFlag)
{
	String rtn("<wx.VarHScrollHelper:");
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
Gura_DeclareMethod(wx_VarHScrollHelper, wxVarHScrollHelper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToScroll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, wxVarHScrollHelper)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int winToScroll = arg.GetNumber(0)
	//pThis->GetEntity()->wxVarHScrollHelper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHScrollHelper, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, GetVisibleColumnsBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHScrollHelper, GetVisibleColumnsBegin)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleColumnsBegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, GetVisibleColumnsEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHScrollHelper, GetVisibleColumnsEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleColumnsEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, IsColumnVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, IsColumnVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->IsColumnVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, RefreshColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, RefreshColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, RefreshColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, RefreshColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, ScrollColumnPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, ScrollColumnPages)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollColumnPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, ScrollColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "columns", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, ScrollColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int columns = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, ScrollToColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, ScrollToColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, SetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "columnCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, SetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int columnCount = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, EstimateTotalWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHScrollHelper, EstimateTotalWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EstimateTotalWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, OnGetColumnsWidthHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "columnMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "columnMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, OnGetColumnsWidthHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int columnMin = arg.GetNumber(0)
	//int columnMax = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetColumnsWidthHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHScrollHelper, OnGetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHScrollHelper, OnGetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHScrollHelper *pThis = Object_wx_VarHScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetColumnWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVarHScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarHScrollHelper)
{
	Gura_AssignMethod(wx_VarHScrollHelper, wxVarHScrollHelper);
	Gura_AssignMethod(wx_VarHScrollHelper, GetColumnCount);
	Gura_AssignMethod(wx_VarHScrollHelper, GetVisibleColumnsBegin);
	Gura_AssignMethod(wx_VarHScrollHelper, GetVisibleColumnsEnd);
	Gura_AssignMethod(wx_VarHScrollHelper, IsColumnVisible);
	Gura_AssignMethod(wx_VarHScrollHelper, RefreshColumn);
	Gura_AssignMethod(wx_VarHScrollHelper, RefreshColumns);
	Gura_AssignMethod(wx_VarHScrollHelper, ScrollColumnPages);
	Gura_AssignMethod(wx_VarHScrollHelper, ScrollColumns);
	Gura_AssignMethod(wx_VarHScrollHelper, ScrollToColumn);
	Gura_AssignMethod(wx_VarHScrollHelper, SetColumnCount);
	Gura_AssignMethod(wx_VarHScrollHelper, EstimateTotalWidth);
	Gura_AssignMethod(wx_VarHScrollHelper, OnGetColumnsWidthHint);
	Gura_AssignMethod(wx_VarHScrollHelper, OnGetColumnWidth);
}

Gura_ImplementDescendantCreator(wx_VarHScrollHelper)
{
	return new Object_wx_VarHScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
