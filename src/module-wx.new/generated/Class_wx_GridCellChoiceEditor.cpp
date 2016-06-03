//----------------------------------------------------------------------------
// wxGridCellChoiceEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellChoiceEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Object_wx_GridCellChoiceEditor::~Object_wx_GridCellChoiceEditor()
{
}

Object *Object_wx_GridCellChoiceEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellChoiceEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellChoiceEditor:");
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
Gura_DeclareFunctionAlias(__wxGridCellChoiceEditor, "wxGridCellChoiceEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allowOthers", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridCellChoiceEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxGridCellChoiceEditor)
{
	//int count = arg.GetNumber(0)
	//int choices = arg.GetNumber(1)
	//int allowOthers = arg.GetNumber(2)
	//wxGridCellChoiceEditor();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGridCellChoiceEditor_1, "wxGridCellChoiceEditor_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allowOthers", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridCellChoiceEditor));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxGridCellChoiceEditor_1)
{
	//int choices = arg.GetNumber(0)
	//int allowOthers = arg.GetNumber(1)
	//wxGridCellChoiceEditor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellChoiceEditor, __SetParameters, "SetParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellChoiceEditor, __SetParameters)
{
	Object_wx_GridCellChoiceEditor *pThis = Object_wx_GridCellChoiceEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellChoiceEditor)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGridCellChoiceEditor);
	Gura_AssignFunction(__wxGridCellChoiceEditor_1);
	// Method assignment
	Gura_AssignMethod(wx_GridCellChoiceEditor, __SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellChoiceEditor)
{
	return new Object_wx_GridCellChoiceEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
