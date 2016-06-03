//----------------------------------------------------------------------------
// wxRichTextTableBlock
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextTableBlock
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextTableBlock
//----------------------------------------------------------------------------
Object_wx_RichTextTableBlock::~Object_wx_RichTextTableBlock()
{
}

Object *Object_wx_RichTextTableBlock::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextTableBlock::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextTableBlock:");
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
Gura_DeclareFunctionAlias(__RichTextTableBlock, "RichTextTableBlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextTableBlock));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextTableBlock)
{
	//wxRichTextTableBlock();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextTableBlock_1, "RichTextTableBlock_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowEnd", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextTableBlock));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextTableBlock_1)
{
	//int colStart = arg.GetNumber(0)
	//int colEnd = arg.GetNumber(1)
	//int rowStart = arg.GetNumber(2)
	//int rowEnd = arg.GetNumber(3)
	//wxRichTextTableBlock();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextTableBlock_2, "RichTextTableBlock_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextTableBlock));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextTableBlock_2)
{
	//const wxRichTextTableBlock& block = arg.GetNumber(0)
	//wxRichTextTableBlock();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextTableBlock, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __Init)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __Copy)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextTableBlock& block = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __ComputeBlockForSelection, "ComputeBlockForSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "requireCellSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __ComputeBlockForSelection)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextTable* table = arg.GetNumber(0)
	//wxRichTextCtrl* ctrl = arg.GetNumber(1)
	//bool requireCellSelection = arg.GetNumber(2)
	//pThis->GetEntity()->ComputeBlockForSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __IsWholeTable, "IsWholeTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __IsWholeTable)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextTable* table = arg.GetNumber(0)
	//pThis->GetEntity()->IsWholeTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __GetFocusedCell, "GetFocusedCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __GetFocusedCell)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextCtrl* ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->GetFocusedCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __ColStart, "ColStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __ColStart)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __ColStart_1, "ColStart_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __ColStart_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __ColEnd, "ColEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __ColEnd)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __ColEnd_1, "ColEnd_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __ColEnd_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __RowStart, "RowStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __RowStart)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __RowStart_1, "RowStart_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __RowStart_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __RowEnd, "RowEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __RowEnd)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTableBlock, __RowEnd_1, "RowEnd_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, __RowEnd_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowEnd();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextTableBlock
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextTableBlock)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextTableBlock);
	Gura_AssignFunction(__RichTextTableBlock_1);
	Gura_AssignFunction(__RichTextTableBlock_2);
	// Method assignment
	Gura_AssignMethod(wx_RichTextTableBlock, __Init);
	Gura_AssignMethod(wx_RichTextTableBlock, __Copy);
	Gura_AssignMethod(wx_RichTextTableBlock, __ComputeBlockForSelection);
	Gura_AssignMethod(wx_RichTextTableBlock, __IsWholeTable);
	Gura_AssignMethod(wx_RichTextTableBlock, __GetFocusedCell);
	Gura_AssignMethod(wx_RichTextTableBlock, __ColStart);
	Gura_AssignMethod(wx_RichTextTableBlock, __ColStart_1);
	Gura_AssignMethod(wx_RichTextTableBlock, __ColEnd);
	Gura_AssignMethod(wx_RichTextTableBlock, __ColEnd_1);
	Gura_AssignMethod(wx_RichTextTableBlock, __RowStart);
	Gura_AssignMethod(wx_RichTextTableBlock, __RowStart_1);
	Gura_AssignMethod(wx_RichTextTableBlock, __RowEnd);
	Gura_AssignMethod(wx_RichTextTableBlock, __RowEnd_1);
}

Gura_ImplementDescendantCreator(wx_RichTextTableBlock)
{
	return new Object_wx_RichTextTableBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
