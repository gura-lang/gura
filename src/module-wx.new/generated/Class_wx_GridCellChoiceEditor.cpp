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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellChoiceEditor, wxGridCellChoiceEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allowOthers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellChoiceEditor, wxGridCellChoiceEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellChoiceEditor *pThis = Object_wx_GridCellChoiceEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//int choices = arg.GetNumber(1)
	//int allowOthers = arg.GetNumber(2)
	//pThis->GetEntity()->wxGridCellChoiceEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellChoiceEditor, wxGridCellChoiceEditor_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allowOthers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellChoiceEditor, wxGridCellChoiceEditor_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellChoiceEditor *pThis = Object_wx_GridCellChoiceEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int choices = arg.GetNumber(0)
	//int allowOthers = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridCellChoiceEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellChoiceEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellChoiceEditor, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellChoiceEditor *pThis = Object_wx_GridCellChoiceEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellChoiceEditor)
{
	Gura_AssignMethod(wx_GridCellChoiceEditor, wxGridCellChoiceEditor);
	Gura_AssignMethod(wx_GridCellChoiceEditor, wxGridCellChoiceEditor_1);
	Gura_AssignMethod(wx_GridCellChoiceEditor, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellChoiceEditor)
{
	return new Object_wx_GridCellChoiceEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
