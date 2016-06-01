//----------------------------------------------------------------------------
// wxVarHVScrollHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarHVScrollHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarHVScrollHelper
//----------------------------------------------------------------------------
Object_wx_VarHVScrollHelper::~Object_wx_VarHVScrollHelper()
{
}

Object *Object_wx_VarHVScrollHelper::Clone() const
{
	return nullptr;
}

String Object_wx_VarHVScrollHelper::ToString(bool exprFlag)
{
	String rtn("<wx.VarHVScrollHelper:");
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
Gura_DeclareMethod(wx_VarHVScrollHelper, wxVarHVScrollHelper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToScroll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, wxVarHVScrollHelper)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int winToScroll = arg.GetNumber(0)
	//pThis->GetEntity()->wxVarHVScrollHelper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, EnablePhysicalScrolling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vscrolling", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hscrolling", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, EnablePhysicalScrolling)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int vscrolling = arg.GetNumber(0)
	//int hscrolling = arg.GetNumber(1)
	//pThis->GetEntity()->EnablePhysicalScrolling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, GetRowColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, GetRowColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRowColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, GetVisibleBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, GetVisibleBegin)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleBegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, GetVisibleEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, GetVisibleEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVisibleEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, IsVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, IsVisible_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, IsVisible_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, RefreshRowColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, RefreshRowColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshRowColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, RefreshRowColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, RefreshRowColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshRowColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, RefreshRowsColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fromRow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toRow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromColumn", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toColumn", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, RefreshRowsColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fromRow = arg.GetNumber(0)
	//int toRow = arg.GetNumber(1)
	//int fromColumn = arg.GetNumber(2)
	//int toColumn = arg.GetNumber(3)
	//pThis->GetEntity()->RefreshRowsColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, RefreshRowsColumns_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, RefreshRowsColumns_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshRowsColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, ScrollToRowColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, ScrollToRowColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollToRowColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, ScrollToRowColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, ScrollToRowColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToRowColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, SetRowColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowCount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "columnCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, SetRowColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rowCount = arg.GetNumber(0)
	//int columnCount = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, VirtualHitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, VirtualHitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->VirtualHitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VarHVScrollHelper, VirtualHitTest_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VarHVScrollHelper, VirtualHitTest_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VarHVScrollHelper *pThis = Object_wx_VarHVScrollHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->VirtualHitTest();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVarHVScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarHVScrollHelper)
{
	Gura_AssignMethod(wx_VarHVScrollHelper, wxVarHVScrollHelper);
	Gura_AssignMethod(wx_VarHVScrollHelper, EnablePhysicalScrolling);
	Gura_AssignMethod(wx_VarHVScrollHelper, GetRowColumnCount);
	Gura_AssignMethod(wx_VarHVScrollHelper, GetVisibleBegin);
	Gura_AssignMethod(wx_VarHVScrollHelper, GetVisibleEnd);
	Gura_AssignMethod(wx_VarHVScrollHelper, IsVisible);
	Gura_AssignMethod(wx_VarHVScrollHelper, IsVisible_1);
	Gura_AssignMethod(wx_VarHVScrollHelper, RefreshRowColumn);
	Gura_AssignMethod(wx_VarHVScrollHelper, RefreshRowColumn_1);
	Gura_AssignMethod(wx_VarHVScrollHelper, RefreshRowsColumns);
	Gura_AssignMethod(wx_VarHVScrollHelper, RefreshRowsColumns_1);
	Gura_AssignMethod(wx_VarHVScrollHelper, ScrollToRowColumn);
	Gura_AssignMethod(wx_VarHVScrollHelper, ScrollToRowColumn_1);
	Gura_AssignMethod(wx_VarHVScrollHelper, SetRowColumnCount);
	Gura_AssignMethod(wx_VarHVScrollHelper, VirtualHitTest);
	Gura_AssignMethod(wx_VarHVScrollHelper, VirtualHitTest_1);
}

Gura_ImplementDescendantCreator(wx_VarHVScrollHelper)
{
	return new Object_wx_VarHVScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
