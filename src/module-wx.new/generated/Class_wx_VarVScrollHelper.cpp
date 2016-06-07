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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__VarVScrollHelper, "VarVScrollHelper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToScroll", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VarVScrollHelper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VarVScrollHelper)
{
	//wxWindow* winToScroll = arg.GetNumber(0)
	//wxVarVScrollHelper(winToScroll);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VarVScrollHelper, __GetRowCount, "GetRowCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __GetRowCount)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __GetVisibleRowsBegin, "GetVisibleRowsBegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __GetVisibleRowsBegin)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleRowsBegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __GetVisibleRowsEnd, "GetVisibleRowsEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __GetVisibleRowsEnd)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleRowsEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __IsRowVisible, "IsRowVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __IsRowVisible)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t row = arg.GetNumber(0)
	//pThis->GetEntity()->IsRowVisible(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __RefreshRow, "RefreshRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __RefreshRow)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t row = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshRow(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __RefreshRows, "RefreshRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __RefreshRows)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t from = arg.GetNumber(0)
	//size_t to = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshRows(from, to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __ScrollRowPages, "ScrollRowPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __ScrollRowPages)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollRowPages(pages);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __ScrollRows, "ScrollRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __ScrollRows)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollRows(rows);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __ScrollToRow, "ScrollToRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __ScrollToRow)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t row = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToRow(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __SetRowCount, "SetRowCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __SetRowCount)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t rowCount = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowCount(rowCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __OnGetRowsHeightHint, "OnGetRowsHeightHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __OnGetRowsHeightHint)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t rowMin = arg.GetNumber(0)
	//size_t rowMax = arg.GetNumber(1)
	//pThis->GetEntity()->OnGetRowsHeightHint(rowMin, rowMax);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __EstimateTotalHeight, "EstimateTotalHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __EstimateTotalHeight)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EstimateTotalHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VarVScrollHelper, __OnGetRowHeight, "OnGetRowHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarVScrollHelper, __OnGetRowHeight)
{
	Object_wx_VarVScrollHelper *pThis = Object_wx_VarVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t row = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetRowHeight(row);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVarVScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarVScrollHelper)
{
	// Constructor assignment
	Gura_AssignFunction(__VarVScrollHelper);
	// Method assignment
	Gura_AssignMethod(wx_VarVScrollHelper, __GetRowCount);
	Gura_AssignMethod(wx_VarVScrollHelper, __GetVisibleRowsBegin);
	Gura_AssignMethod(wx_VarVScrollHelper, __GetVisibleRowsEnd);
	Gura_AssignMethod(wx_VarVScrollHelper, __IsRowVisible);
	Gura_AssignMethod(wx_VarVScrollHelper, __RefreshRow);
	Gura_AssignMethod(wx_VarVScrollHelper, __RefreshRows);
	Gura_AssignMethod(wx_VarVScrollHelper, __ScrollRowPages);
	Gura_AssignMethod(wx_VarVScrollHelper, __ScrollRows);
	Gura_AssignMethod(wx_VarVScrollHelper, __ScrollToRow);
	Gura_AssignMethod(wx_VarVScrollHelper, __SetRowCount);
	Gura_AssignMethod(wx_VarVScrollHelper, __OnGetRowsHeightHint);
	Gura_AssignMethod(wx_VarVScrollHelper, __EstimateTotalHeight);
	Gura_AssignMethod(wx_VarVScrollHelper, __OnGetRowHeight);
}

Gura_ImplementDescendantCreator(wx_VarVScrollHelper)
{
	return new Object_wx_VarVScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
