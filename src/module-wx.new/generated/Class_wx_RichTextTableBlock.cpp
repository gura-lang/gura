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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextTableBlock, wxRichTextTableBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, wxRichTextTableBlock)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextTableBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, wxRichTextTableBlock_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, wxRichTextTableBlock_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colStart = arg.GetNumber(0)
	//int colEnd = arg.GetNumber(1)
	//int rowStart = arg.GetNumber(2)
	//int rowEnd = arg.GetNumber(3)
	//pThis->GetEntity()->wxRichTextTableBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, wxRichTextTableBlock_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, wxRichTextTableBlock_2)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int block = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextTableBlock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, Init)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, Copy)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int block = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "block", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, operator=)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int block = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, ComputeBlockForSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "requireCellSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, ComputeBlockForSelection)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int requireCellSelection = arg.GetNumber(2)
	//pThis->GetEntity()->ComputeBlockForSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, IsWholeTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, IsWholeTable)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//pThis->GetEntity()->IsWholeTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, GetFocusedCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTableBlock, GetFocusedCell)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->GetFocusedCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, ColStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, ColStart)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, ColStart_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, ColStart_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, ColEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, ColEnd)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, ColEnd_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, ColEnd_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ColEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, RowStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, RowStart)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, RowStart_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, RowStart_1)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, RowEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, RowEnd)
{
	Object_wx_RichTextTableBlock *pThis = Object_wx_RichTextTableBlock::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTableBlock, RowEnd_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTableBlock, RowEnd_1)
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
	Gura_AssignMethod(wx_RichTextTableBlock, wxRichTextTableBlock);
	Gura_AssignMethod(wx_RichTextTableBlock, wxRichTextTableBlock_1);
	Gura_AssignMethod(wx_RichTextTableBlock, wxRichTextTableBlock_2);
	Gura_AssignMethod(wx_RichTextTableBlock, Init);
	Gura_AssignMethod(wx_RichTextTableBlock, Copy);
	Gura_AssignMethod(wx_RichTextTableBlock, operator=);
	Gura_AssignMethod(wx_RichTextTableBlock, ComputeBlockForSelection);
	Gura_AssignMethod(wx_RichTextTableBlock, IsWholeTable);
	Gura_AssignMethod(wx_RichTextTableBlock, GetFocusedCell);
	Gura_AssignMethod(wx_RichTextTableBlock, ColStart);
	Gura_AssignMethod(wx_RichTextTableBlock, ColStart_1);
	Gura_AssignMethod(wx_RichTextTableBlock, ColEnd);
	Gura_AssignMethod(wx_RichTextTableBlock, ColEnd_1);
	Gura_AssignMethod(wx_RichTextTableBlock, RowStart);
	Gura_AssignMethod(wx_RichTextTableBlock, RowStart_1);
	Gura_AssignMethod(wx_RichTextTableBlock, RowEnd);
	Gura_AssignMethod(wx_RichTextTableBlock, RowEnd_1);
}

Gura_ImplementDescendantCreator(wx_RichTextTableBlock)
{
	return new Object_wx_RichTextTableBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
