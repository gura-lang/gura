//----------------------------------------------------------------------------
// wxGridCellNumberEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellNumberEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Object_wx_GridCellNumberEditor::~Object_wx_GridCellNumberEditor()
{
}

Object *Object_wx_GridCellNumberEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellNumberEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberEditor:");
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
Gura_DeclareFunctionAlias(__GridCellNumberEditor, "GridCellNumberEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridCellNumberEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridCellNumberEditor)
{
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//wxGridCellNumberEditor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellNumberEditor, __SetParameters, "SetParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, __SetParameters)
{
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellNumberEditor, __HasRange, "HasRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, __HasRange)
{
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellNumberEditor, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, __GetString)
{
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberEditor)
{
	// Constructor assignment
	Gura_AssignFunction(__GridCellNumberEditor);
	// Method assignment
	Gura_AssignMethod(wx_GridCellNumberEditor, __SetParameters);
	Gura_AssignMethod(wx_GridCellNumberEditor, __HasRange);
	Gura_AssignMethod(wx_GridCellNumberEditor, __GetString);
}

Gura_ImplementDescendantCreator(wx_GridCellNumberEditor)
{
	return new Object_wx_GridCellNumberEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
