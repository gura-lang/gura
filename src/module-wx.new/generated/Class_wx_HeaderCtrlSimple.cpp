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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HeaderCtrlSimple, "HeaderCtrlSimple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HeaderCtrlSimple));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HeaderCtrlSimple)
{
	//wxHeaderCtrlSimple();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HeaderCtrlSimple_1, "HeaderCtrlSimple_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HeaderCtrlSimple));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HeaderCtrlSimple_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxHeaderCtrlSimple(parent, winid, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __InsertColumn, "InsertColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __InsertColumn)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHeaderColumnSimple& col = arg.GetNumber(0)
	//unsigned int idx = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn(col, idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __AppendColumn)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHeaderColumnSimple& col = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __DeleteColumn, "DeleteColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __DeleteColumn)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteColumn(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __ShowColumn, "ShowColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __ShowColumn)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//bool show = arg.GetNumber(1)
	//pThis->GetEntity()->ShowColumn(idx, show);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __HideColumn, "HideColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __HideColumn)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//pThis->GetEntity()->HideColumn(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __ShowSortIndicator, "ShowSortIndicator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __ShowSortIndicator)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//bool sortOrder = arg.GetNumber(1)
	//pThis->GetEntity()->ShowSortIndicator(idx, sortOrder);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __RemoveSortIndicator, "RemoveSortIndicator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __RemoveSortIndicator)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveSortIndicator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlSimple, __GetBestFittingWidth, "GetBestFittingWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlSimple, __GetBestFittingWidth)
{
	Object_wx_HeaderCtrlSimple *pThis = Object_wx_HeaderCtrlSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int idx = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetBestFittingWidth(idx);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrlSimple)
{
	// Constructor assignment
	Gura_AssignFunction(__HeaderCtrlSimple);
	Gura_AssignFunction(__HeaderCtrlSimple_1);
	// Method assignment
	Gura_AssignMethod(wx_HeaderCtrlSimple, __InsertColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __AppendColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __DeleteColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __ShowColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __HideColumn);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __ShowSortIndicator);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __RemoveSortIndicator);
	Gura_AssignMethod(wx_HeaderCtrlSimple, __GetBestFittingWidth);
}

Gura_ImplementDescendantCreator(wx_HeaderCtrlSimple)
{
	return new Object_wx_HeaderCtrlSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
