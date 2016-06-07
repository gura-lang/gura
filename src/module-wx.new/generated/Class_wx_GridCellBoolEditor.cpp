//----------------------------------------------------------------------------
// wxGridCellBoolEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellBoolEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Object_wx_GridCellBoolEditor::~Object_wx_GridCellBoolEditor()
{
}

Object *Object_wx_GridCellBoolEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellBoolEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellBoolEditor:");
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
Gura_DeclareFunctionAlias(__GridCellBoolEditor, "GridCellBoolEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellBoolEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridCellBoolEditor)
{
	//wxGridCellBoolEditor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellBoolEditor, __IsTrueValue, "IsTrueValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellBoolEditor, __IsTrueValue)
{
	Object_wx_GridCellBoolEditor *pThis = Object_wx_GridCellBoolEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& value = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsTrueValue(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellBoolEditor, __UseStringValues, "UseStringValues")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valueTrue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "valueFalse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellBoolEditor, __UseStringValues)
{
	Object_wx_GridCellBoolEditor *pThis = Object_wx_GridCellBoolEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& valueTrue = arg.GetNumber(0)
	//const wxString& valueFalse = arg.GetNumber(1)
	//pThis->GetEntity()->UseStringValues(valueTrue, valueFalse);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolEditor)
{
	// Constructor assignment
	Gura_AssignFunction(__GridCellBoolEditor);
	// Method assignment
	Gura_AssignMethod(wx_GridCellBoolEditor, __IsTrueValue);
	Gura_AssignMethod(wx_GridCellBoolEditor, __UseStringValues);
}

Gura_ImplementDescendantCreator(wx_GridCellBoolEditor)
{
	return new Object_wx_GridCellBoolEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
