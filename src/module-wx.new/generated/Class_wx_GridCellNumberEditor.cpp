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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellNumberEditor, wxGridCellNumberEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, wxGridCellNumberEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridCellNumberEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellNumberEditor, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellNumberEditor, HasRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, HasRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellNumberEditor, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellNumberEditor, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellNumberEditor *pThis = Object_wx_GridCellNumberEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberEditor)
{
	Gura_AssignMethod(wx_GridCellNumberEditor, wxGridCellNumberEditor);
	Gura_AssignMethod(wx_GridCellNumberEditor, SetParameters);
	Gura_AssignMethod(wx_GridCellNumberEditor, HasRange);
	Gura_AssignMethod(wx_GridCellNumberEditor, GetString);
}

Gura_ImplementDescendantCreator(wx_GridCellNumberEditor)
{
	return new Object_wx_GridCellNumberEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
