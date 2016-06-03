//----------------------------------------------------------------------------
// wxRichTextBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextBuffer
//----------------------------------------------------------------------------
Object_wx_RichTextBuffer::~Object_wx_RichTextBuffer()
{
}

Object *Object_wx_RichTextBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextBuffer:");
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
Gura_DeclareFunctionAlias(__wxRichTextBuffer, "wxRichTextBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextBuffer)
{
	//wxRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextBuffer_1, "wxRichTextBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextBuffer_1)
{
	//wxRichTextBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetCommandProcessor, "GetCommandProcessor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetCommandProcessor)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetStyleSheet, "SetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetStyleSheet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetStyleSheet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetStyleSheetAndNotify, "SetStyleSheetAndNotify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetStyleSheetAndNotify)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheetAndNotify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __PushStyleSheet, "PushStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __PushStyleSheet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->PushStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __PopStyleSheet, "PopStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __PopStyleSheet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PopStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetFontTable, "GetFontTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetFontTable)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetFontTable_1, "GetFontTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetFontTable_1)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetFontTable, "SetFontTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetFontTable)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetFontScale, "SetFontScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetFontScale)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fontScale = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetFontScale, "GetFontScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetFontScale)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetDimensionScale, "SetDimensionScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dimScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetDimensionScale)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dimScale = arg.GetNumber(0)
	//pThis->GetEntity()->SetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetDimensionScale, "GetDimensionScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetDimensionScale)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __Init)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __ResetAndClearCommands, "ResetAndClearCommands")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __ResetAndClearCommands)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetAndClearCommands();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __LoadFile)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __LoadFile_1, "LoadFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __LoadFile_1)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SaveFile)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SaveFile_1, "SaveFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SaveFile_1)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetHandlerFlags, "SetHandlerFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetHandlerFlags)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetHandlerFlags, "GetHandlerFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetHandlerFlags)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __AddParagraph, "AddParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __AddParagraph)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int paraStyle = arg.GetNumber(1)
	//pThis->GetEntity()->AddParagraph();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginBatchUndo, "BeginBatchUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginBatchUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmdName = arg.GetNumber(0)
	//pThis->GetEntity()->BeginBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndBatchUndo, "EndBatchUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndBatchUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BatchingUndo, "BatchingUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BatchingUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BatchingUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SubmitAction, "SubmitAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SubmitAction)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->SubmitAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetBatchedCommand, "GetBatchedCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetBatchedCommand)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBatchedCommand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginSuppressUndo, "BeginSuppressUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginSuppressUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndSuppressUndo, "EndSuppressUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndSuppressUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SuppressingUndo, "SuppressingUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SuppressingUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SuppressingUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __CopyToClipboard, "CopyToClipboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __CopyToClipboard)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->CopyToClipboard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __PasteFromClipboard, "PasteFromClipboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __PasteFromClipboard)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->PasteFromClipboard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __CanPasteFromClipboard, "CanPasteFromClipboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __CanPasteFromClipboard)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPasteFromClipboard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginStyle, "BeginStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->BeginStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndStyle, "EndStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndAllStyles, "EndAllStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndAllStyles)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndAllStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __ClearStyleStack, "ClearStyleStack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __ClearStyleStack)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearStyleStack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetStyleStackSize, "GetStyleStackSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetStyleStackSize)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleStackSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginBold, "BeginBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginBold)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndBold, "EndBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndBold)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginItalic, "BeginItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginItalic)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndItalic, "EndItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndItalic)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginUnderline, "BeginUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginUnderline)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndUnderline, "EndUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndUnderline)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginFontSize, "BeginFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginFontSize)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndFontSize, "EndFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndFontSize)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginFont, "BeginFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginFont)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndFont, "EndFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndFont)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginTextColour, "BeginTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginTextColour)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->BeginTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndTextColour, "EndTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndTextColour)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginAlignment, "BeginAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginAlignment)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->BeginAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndAlignment, "EndAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndAlignment)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginLeftIndent, "BeginLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginLeftIndent)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int leftIndent = arg.GetNumber(0)
	//int leftSubIndent = arg.GetNumber(1)
	//pThis->GetEntity()->BeginLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndLeftIndent, "EndLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndLeftIndent)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginRightIndent, "BeginRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rightIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginRightIndent)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rightIndent = arg.GetNumber(0)
	//pThis->GetEntity()->BeginRightIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndRightIndent, "EndRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndRightIndent)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndRightIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginParagraphSpacing, "BeginParagraphSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "after", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginParagraphSpacing)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//int after = arg.GetNumber(1)
	//pThis->GetEntity()->BeginParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndParagraphSpacing, "EndParagraphSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndParagraphSpacing)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginLineSpacing, "BeginLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineSpacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginLineSpacing)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineSpacing = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndLineSpacing, "EndLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndLineSpacing)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginNumberedBullet, "BeginNumberedBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginNumberedBullet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bulletNumber = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndNumberedBullet, "EndNumberedBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndNumberedBullet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginSymbolBullet, "BeginSymbolBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginSymbolBullet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndSymbolBullet, "EndSymbolBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndSymbolBullet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginStandardBullet, "BeginStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginStandardBullet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bulletName = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndStandardBullet, "EndStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndStandardBullet)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginCharacterStyle, "BeginCharacterStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginCharacterStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndCharacterStyle, "EndCharacterStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndCharacterStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginParagraphStyle, "BeginParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginParagraphStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraphStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndParagraphStyle, "EndParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndParagraphStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginListStyle, "BeginListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginListStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listStyle = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int number = arg.GetNumber(2)
	//pThis->GetEntity()->BeginListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndListStyle, "EndListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndListStyle)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __BeginURL, "BeginURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __BeginURL)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//int characterStyle = arg.GetNumber(1)
	//pThis->GetEntity()->BeginURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __EndURL, "EndURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __EndURL)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __AddEventHandler, "AddEventHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __AddEventHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddEventHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __RemoveEventHandler, "RemoveEventHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteHandler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __RemoveEventHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//int deleteHandler = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveEventHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __ClearEventHandlers, "ClearEventHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __ClearEventHandlers)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearEventHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SendEvent, "SendEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sendToAll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SendEvent)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//int sendToAll = arg.GetNumber(1)
	//pThis->GetEntity()->SendEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "contextObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __HitTest)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int pt = arg.GetNumber(2)
	//int textPosition = arg.GetNumber(3)
	//int obj = arg.GetNumber(4)
	//int contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __Copy)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __Clone)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertParagraphsWithUndo, "InsertParagraphsWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paragraphs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertParagraphsWithUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int paragraphs = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertParagraphsWithUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertTextWithUndo, "InsertTextWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertTextWithUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertTextWithUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertNewlineWithUndo, "InsertNewlineWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertNewlineWithUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->InsertNewlineWithUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertImageWithUndo, "InsertImageWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertImageWithUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int imageBlock = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int textAttr = arg.GetNumber(4)
	//pThis->GetEntity()->InsertImageWithUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertObjectWithUndo, "InsertObjectWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertObjectWithUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int object = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertObjectWithUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __DeleteRangeWithUndo, "DeleteRangeWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __DeleteRangeWithUndo)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRangeWithUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __Modify, "Modify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modify", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __Modify)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modify = arg.GetNumber(0)
	//pThis->GetEntity()->Modify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __IsModified, "IsModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __IsModified)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __Dump, "Dump")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __Dump)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __Dump_1, "Dump_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __Dump_1)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetHandlers, "GetHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetHandlers)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __AddHandler, "AddHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __AddHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertHandler, "InsertHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __RemoveHandler, "RemoveHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __RemoveHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __FindHandler, "FindHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __FindHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __FindHandler_1, "FindHandler_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __FindHandler_1)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __FindHandlerFilenameOrType, "FindHandlerFilenameOrType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __FindHandlerFilenameOrType)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->FindHandlerFilenameOrType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __FindHandler_2, "FindHandler_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __FindHandler_2)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageType = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetExtWildcard, "GetExtWildcard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "combine", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "save", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "types", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetExtWildcard)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int combine = arg.GetNumber(0)
	//int save = arg.GetNumber(1)
	//int types = arg.GetNumber(2)
	//pThis->GetEntity()->GetExtWildcard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __CleanUpHandlers, "CleanUpHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __CleanUpHandlers)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CleanUpHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InitStandardHandlers, "InitStandardHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InitStandardHandlers)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitStandardHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetDrawingHandlers, "GetDrawingHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetDrawingHandlers)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDrawingHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __AddDrawingHandler, "AddDrawingHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __AddDrawingHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __InsertDrawingHandler, "InsertDrawingHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __InsertDrawingHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __RemoveDrawingHandler, "RemoveDrawingHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __RemoveDrawingHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __FindDrawingHandler, "FindDrawingHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __FindDrawingHandler)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __CleanUpDrawingHandlers, "CleanUpDrawingHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __CleanUpDrawingHandlers)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CleanUpDrawingHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetFieldTypes, "GetFieldTypes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetFieldTypes)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFieldTypes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __AddFieldType, "AddFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __AddFieldType)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->AddFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __RemoveFieldType, "RemoveFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __RemoveFieldType)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __FindFieldType, "FindFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __FindFieldType)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __CleanUpFieldTypes, "CleanUpFieldTypes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __CleanUpFieldTypes)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CleanUpFieldTypes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetRenderer, "GetRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetRenderer)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRenderer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetRenderer, "SetRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "renderer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetRenderer)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int renderer = arg.GetNumber(0)
	//pThis->GetEntity()->SetRenderer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetBulletRightMargin, "GetBulletRightMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetBulletRightMargin)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBulletRightMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetBulletRightMargin, "SetBulletRightMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetBulletRightMargin)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletRightMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetBulletProportion, "GetBulletProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetBulletProportion)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBulletProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetBulletProportion, "SetBulletProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetBulletProportion)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetScale, "GetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetScale)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetScale, "SetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetScale)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scale = arg.GetNumber(0)
	//pThis->GetEntity()->SetScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __GetFloatingLayoutMode, "GetFloatingLayoutMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, __GetFloatingLayoutMode)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFloatingLayoutMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBuffer, __SetFloatingLayoutMode, "SetFloatingLayoutMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, __SetFloatingLayoutMode)
{
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetFloatingLayoutMode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextBuffer);
	Gura_AssignFunction(__wxRichTextBuffer_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextBuffer, __GetCommandProcessor);
	Gura_AssignMethod(wx_RichTextBuffer, __SetStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, __GetStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, __SetStyleSheetAndNotify);
	Gura_AssignMethod(wx_RichTextBuffer, __PushStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, __PopStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, __GetFontTable);
	Gura_AssignMethod(wx_RichTextBuffer, __GetFontTable_1);
	Gura_AssignMethod(wx_RichTextBuffer, __SetFontTable);
	Gura_AssignMethod(wx_RichTextBuffer, __SetFontScale);
	Gura_AssignMethod(wx_RichTextBuffer, __GetFontScale);
	Gura_AssignMethod(wx_RichTextBuffer, __SetDimensionScale);
	Gura_AssignMethod(wx_RichTextBuffer, __GetDimensionScale);
	Gura_AssignMethod(wx_RichTextBuffer, __Init);
	Gura_AssignMethod(wx_RichTextBuffer, __ResetAndClearCommands);
	Gura_AssignMethod(wx_RichTextBuffer, __LoadFile);
	Gura_AssignMethod(wx_RichTextBuffer, __LoadFile_1);
	Gura_AssignMethod(wx_RichTextBuffer, __SaveFile);
	Gura_AssignMethod(wx_RichTextBuffer, __SaveFile_1);
	Gura_AssignMethod(wx_RichTextBuffer, __SetHandlerFlags);
	Gura_AssignMethod(wx_RichTextBuffer, __GetHandlerFlags);
	Gura_AssignMethod(wx_RichTextBuffer, __AddParagraph);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginBatchUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __EndBatchUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __BatchingUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __SubmitAction);
	Gura_AssignMethod(wx_RichTextBuffer, __GetBatchedCommand);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginSuppressUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __EndSuppressUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __SuppressingUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __CopyToClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, __PasteFromClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, __CanPasteFromClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __EndStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __EndAllStyles);
	Gura_AssignMethod(wx_RichTextBuffer, __ClearStyleStack);
	Gura_AssignMethod(wx_RichTextBuffer, __GetStyleStackSize);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginBold);
	Gura_AssignMethod(wx_RichTextBuffer, __EndBold);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginItalic);
	Gura_AssignMethod(wx_RichTextBuffer, __EndItalic);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginUnderline);
	Gura_AssignMethod(wx_RichTextBuffer, __EndUnderline);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginFontSize);
	Gura_AssignMethod(wx_RichTextBuffer, __EndFontSize);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginFont);
	Gura_AssignMethod(wx_RichTextBuffer, __EndFont);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginTextColour);
	Gura_AssignMethod(wx_RichTextBuffer, __EndTextColour);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginAlignment);
	Gura_AssignMethod(wx_RichTextBuffer, __EndAlignment);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginLeftIndent);
	Gura_AssignMethod(wx_RichTextBuffer, __EndLeftIndent);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginRightIndent);
	Gura_AssignMethod(wx_RichTextBuffer, __EndRightIndent);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginParagraphSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, __EndParagraphSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginLineSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, __EndLineSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginNumberedBullet);
	Gura_AssignMethod(wx_RichTextBuffer, __EndNumberedBullet);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginSymbolBullet);
	Gura_AssignMethod(wx_RichTextBuffer, __EndSymbolBullet);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginStandardBullet);
	Gura_AssignMethod(wx_RichTextBuffer, __EndStandardBullet);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginCharacterStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __EndCharacterStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginParagraphStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __EndParagraphStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __EndListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, __BeginURL);
	Gura_AssignMethod(wx_RichTextBuffer, __EndURL);
	Gura_AssignMethod(wx_RichTextBuffer, __AddEventHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __RemoveEventHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __ClearEventHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, __SendEvent);
	Gura_AssignMethod(wx_RichTextBuffer, __HitTest);
	Gura_AssignMethod(wx_RichTextBuffer, __Copy);
	Gura_AssignMethod(wx_RichTextBuffer, __Clone);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertParagraphsWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertTextWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertNewlineWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertImageWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertObjectWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __DeleteRangeWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, __Modify);
	Gura_AssignMethod(wx_RichTextBuffer, __IsModified);
	Gura_AssignMethod(wx_RichTextBuffer, __Dump);
	Gura_AssignMethod(wx_RichTextBuffer, __Dump_1);
	Gura_AssignMethod(wx_RichTextBuffer, __GetHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, __AddHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __RemoveHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __FindHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __FindHandler_1);
	Gura_AssignMethod(wx_RichTextBuffer, __FindHandlerFilenameOrType);
	Gura_AssignMethod(wx_RichTextBuffer, __FindHandler_2);
	Gura_AssignMethod(wx_RichTextBuffer, __GetExtWildcard);
	Gura_AssignMethod(wx_RichTextBuffer, __CleanUpHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, __InitStandardHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, __GetDrawingHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, __AddDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __InsertDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __RemoveDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __FindDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, __CleanUpDrawingHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, __GetFieldTypes);
	Gura_AssignMethod(wx_RichTextBuffer, __AddFieldType);
	Gura_AssignMethod(wx_RichTextBuffer, __RemoveFieldType);
	Gura_AssignMethod(wx_RichTextBuffer, __FindFieldType);
	Gura_AssignMethod(wx_RichTextBuffer, __CleanUpFieldTypes);
	Gura_AssignMethod(wx_RichTextBuffer, __GetRenderer);
	Gura_AssignMethod(wx_RichTextBuffer, __SetRenderer);
	Gura_AssignMethod(wx_RichTextBuffer, __GetBulletRightMargin);
	Gura_AssignMethod(wx_RichTextBuffer, __SetBulletRightMargin);
	Gura_AssignMethod(wx_RichTextBuffer, __GetBulletProportion);
	Gura_AssignMethod(wx_RichTextBuffer, __SetBulletProportion);
	Gura_AssignMethod(wx_RichTextBuffer, __GetScale);
	Gura_AssignMethod(wx_RichTextBuffer, __SetScale);
	Gura_AssignMethod(wx_RichTextBuffer, __GetFloatingLayoutMode);
	Gura_AssignMethod(wx_RichTextBuffer, __SetFloatingLayoutMode);
}

Gura_ImplementDescendantCreator(wx_RichTextBuffer)
{
	return new Object_wx_RichTextBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
