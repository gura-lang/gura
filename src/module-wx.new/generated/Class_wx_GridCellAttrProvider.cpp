//----------------------------------------------------------------------------
// wxGridCellAttrProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAttrProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Object_wx_GridCellAttrProvider::~Object_wx_GridCellAttrProvider()
{
}

Object *Object_wx_GridCellAttrProvider::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAttrProvider::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAttrProvider:");
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
Gura_DeclareMethod(wx_GridCellAttrProvider, wxGridCellAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, wxGridCellAttrProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellAttrProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, ~wxGridCellAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, ~wxGridCellAttrProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxGridCellAttrProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, GetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int kind = arg.GetNumber(2)
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, SetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, SetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, SetRowAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, SetRowAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, SetColAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, SetColAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetColAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, GetColumnHeaderRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, GetColumnHeaderRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnHeaderRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, GetRowHeaderRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, GetRowHeaderRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetRowHeaderRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellAttrProvider, GetCornerRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, GetCornerRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCornerRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttrProvider)
{
	Gura_AssignMethod(wx_GridCellAttrProvider, wxGridCellAttrProvider);
	Gura_AssignMethod(wx_GridCellAttrProvider, ~wxGridCellAttrProvider);
	Gura_AssignMethod(wx_GridCellAttrProvider, GetAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, SetAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, SetRowAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, SetColAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, GetColumnHeaderRenderer);
	Gura_AssignMethod(wx_GridCellAttrProvider, GetRowHeaderRenderer);
	Gura_AssignMethod(wx_GridCellAttrProvider, GetCornerRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellAttrProvider)
{
	return new Object_wx_GridCellAttrProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
