//----------------------------------------------------------------------------
// wxVarVScrollHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarVScrollHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarVScrollHelper
//----------------------------------------------------------------------------
Object_wx_VarVScrollHelper::~Object_wx_VarVScrollHelper()
{
}

Object *Object_wx_VarVScrollHelper::Clone() const
{
	return nullptr;
}

String Object_wx_VarVScrollHelper::ToString(bool exprFlag)
{
	String rtn("<wx.VarVScrollHelper:");
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
Gura_DeclareMethod(wx_VarVScrollHelper, wxVarVScrollHelper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToScroll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, wxVarVScrollHelper)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int winToScroll = arg.GetNumber(0)
	//pThis->GetEntity()->wxVarVScrollHelper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, GetRowCount)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, GetVisibleRowsBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, GetVisibleRowsBegin)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleRowsBegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, GetVisibleRowsEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, GetVisibleRowsEnd)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleRowsEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, IsRowVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, IsRowVisible)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->IsRowVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, RefreshRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, RefreshRow)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, RefreshRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, RefreshRows)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, ScrollRowPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, ScrollRowPages)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollRowPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, ScrollRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, ScrollRows)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, ScrollToRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, ScrollToRow)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, SetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, SetRowCount)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowCount = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, OnGetRowsHeightHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, OnGetRowsHeightHint)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowMin = arg.GetNumber(0)
	//int rowMax = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetRowsHeightHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, EstimateTotalHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, EstimateTotalHeight)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EstimateTotalHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarVScrollHelper, OnGetRowHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, OnGetRowHeight)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetRowHeight();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVarVScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarVScrollHelper)
{
	Gura_AssignMethod(wx_VarVScrollHelper, wxVarVScrollHelper);
	Gura_AssignMethod(wx_VarVScrollHelper, GetRowCount);
	Gura_AssignMethod(wx_VarVScrollHelper, GetVisibleRowsBegin);
	Gura_AssignMethod(wx_VarVScrollHelper, GetVisibleRowsEnd);
	Gura_AssignMethod(wx_VarVScrollHelper, IsRowVisible);
	Gura_AssignMethod(wx_VarVScrollHelper, RefreshRow);
	Gura_AssignMethod(wx_VarVScrollHelper, RefreshRows);
	Gura_AssignMethod(wx_VarVScrollHelper, ScrollRowPages);
	Gura_AssignMethod(wx_VarVScrollHelper, ScrollRows);
	Gura_AssignMethod(wx_VarVScrollHelper, ScrollToRow);
	Gura_AssignMethod(wx_VarVScrollHelper, SetRowCount);
	Gura_AssignMethod(wx_VarVScrollHelper, OnGetRowsHeightHint);
	Gura_AssignMethod(wx_VarVScrollHelper, EstimateTotalHeight);
	Gura_AssignMethod(wx_VarVScrollHelper, OnGetRowHeight);
}

Gura_ImplementDescendantCreator(wx_VarVScrollHelper)
{
	return new Object_wx_VarVScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
