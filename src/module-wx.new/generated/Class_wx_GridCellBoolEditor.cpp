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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellBoolEditor, wxGridCellBoolEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellBoolEditor, wxGridCellBoolEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellBoolEditor *pThis = Object_wx_GridCellBoolEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellBoolEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellBoolEditor, IsTrueValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellBoolEditor, IsTrueValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellBoolEditor *pThis = Object_wx_GridCellBoolEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->IsTrueValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellBoolEditor, UseStringValues)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "valueTrue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "valueFalse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellBoolEditor, UseStringValues)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellBoolEditor *pThis = Object_wx_GridCellBoolEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int valueTrue = arg.GetNumber(0)
	//int valueFalse = arg.GetNumber(1)
	//pThis->GetEntity()->UseStringValues();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolEditor)
{
	Gura_AssignMethod(wx_GridCellBoolEditor, wxGridCellBoolEditor);
	Gura_AssignMethod(wx_GridCellBoolEditor, IsTrueValue);
	Gura_AssignMethod(wx_GridCellBoolEditor, UseStringValues);
}

Gura_ImplementDescendantCreator(wx_GridCellBoolEditor)
{
	return new Object_wx_GridCellBoolEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
