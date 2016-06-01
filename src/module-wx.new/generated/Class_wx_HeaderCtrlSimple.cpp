//----------------------------------------------------------------------------
// wxHeaderCtrlSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderCtrlSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
Object_wx_HeaderCtrlSimple::~Object_wx_HeaderCtrlSimple()
{
}

Object *Object_wx_HeaderCtrlSimple::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderCtrlSimple::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderCtrlSimple:");
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
Gura_DeclareMethod(wx_HeaderCtrlSimple, wxHeaderCtrlSimple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, wxHeaderCtrlSimple)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxHeaderCtrlSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, wxHeaderCtrlSimple_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, wxHeaderCtrlSimple_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxHeaderCtrlSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, InsertColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, InsertColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int idx = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, AppendColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, DeleteColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, DeleteColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, ShowColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, ShowColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->ShowColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, HideColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, HideColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->HideColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, ShowSortIndicator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, ShowSortIndicator)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int sortOrder = arg.GetNumber(1)
	//pThis->GetEntity()->ShowSortIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, RemoveSortIndicator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, RemoveSortIndicator)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RemoveSortIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlSimple, GetBestFittingWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, GetBestFittingWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetBestFittingWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrlSimple)
{
	Gura_AssignMethod(wx_HeaderCtrlSimple, wxHeaderCtrlSimple);
	Gura_AssignMethod(wx_HeaderCtrlSimple, wxHeaderCtrlSimple_1);
	Gura_AssignMethod(wx_HeaderCtrlSimple, InsertColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, AppendColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, DeleteColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, ShowColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, HideColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, ShowSortIndicator);
	Gura_AssignMethod(wx_HeaderCtrlSimple, RemoveSortIndicator);
	Gura_AssignMethod(wx_HeaderCtrlSimple, GetBestFittingWidth);
}

Gura_ImplementDescendantCreator(wx_HeaderCtrlSimple)
{
	return new Object_wx_HeaderCtrlSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
