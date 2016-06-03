//----------------------------------------------------------------------------
// wxGridCellFloatEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Object_wx_GridCellFloatEditor::~Object_wx_GridCellFloatEditor()
{
}

Object *Object_wx_GridCellFloatEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellFloatEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellFloatEditor:");
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
Gura_DeclareMethodAlias(wx_GridCellFloatEditor, __wxGridCellFloatEditor, "wxGridCellFloatEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatEditor, __wxGridCellFloatEditor)
{
	Object_wx_GridCellFloatEditor *pThis = Object_wx_GridCellFloatEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->wxGridCellFloatEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellFloatEditor, __SetParameters, "SetParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatEditor, __SetParameters)
{
	Object_wx_GridCellFloatEditor *pThis = Object_wx_GridCellFloatEditor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellFloatEditor)
{
	Gura_AssignMethod(wx_GridCellFloatEditor, __wxGridCellFloatEditor);
	Gura_AssignMethod(wx_GridCellFloatEditor, __SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellFloatEditor)
{
	return new Object_wx_GridCellFloatEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
