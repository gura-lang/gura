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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridCellAttrProvider, "GridCellAttrProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAttrProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridCellAttrProvider)
{
	//wxGridCellAttrProvider();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __GetAttr, "GetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __GetAttr)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxGridCellAttr::wxAttrKind kind = arg.GetNumber(2)
	//wxGridCellAttr* _rtn = pThis->GetEntity()->GetAttr(row, col, kind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __SetAttr, "SetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __SetAttr)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttr* attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetAttr(attr, row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __SetRowAttr, "SetRowAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __SetRowAttr)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttr* attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowAttr(attr, row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __SetColAttr, "SetColAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __SetColAttr)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttr* attr = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetColAttr(attr, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __GetColumnHeaderRenderer, "GetColumnHeaderRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __GetColumnHeaderRenderer)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//const wxGridColumnHeaderRenderer& _rtn = pThis->GetEntity()->GetColumnHeaderRenderer(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __GetRowHeaderRenderer, "GetRowHeaderRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __GetRowHeaderRenderer)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//const wxGridRowHeaderRenderer& _rtn = pThis->GetEntity()->GetRowHeaderRenderer(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellAttrProvider, __GetCornerRenderer, "GetCornerRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellAttrProvider, __GetCornerRenderer)
{
	Object_wx_GridCellAttrProvider *pThis = Object_wx_GridCellAttrProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGridCornerHeaderRenderer& _rtn = pThis->GetEntity()->GetCornerRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAttrProvider)
{
	// Constructor assignment
	Gura_AssignFunction(__GridCellAttrProvider);
	// Method assignment
	Gura_AssignMethod(wx_GridCellAttrProvider, __GetAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, __SetAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, __SetRowAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, __SetColAttr);
	Gura_AssignMethod(wx_GridCellAttrProvider, __GetColumnHeaderRenderer);
	Gura_AssignMethod(wx_GridCellAttrProvider, __GetRowHeaderRenderer);
	Gura_AssignMethod(wx_GridCellAttrProvider, __GetCornerRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellAttrProvider)
{
	return new Object_wx_GridCellAttrProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
