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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextBuffer, wxRichTextBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, wxRichTextBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, wxRichTextBuffer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, wxRichTextBuffer_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, ~wxRichTextBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, ~wxRichTextBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetCommandProcessor)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetStyleSheetAndNotify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetStyleSheetAndNotify)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheetAndNotify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, PushStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, PushStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->PushStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, PopStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, PopStyleSheet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PopStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetFontTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetFontTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetFontTable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetFontTable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetFontTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetFontTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetFontScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetFontScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fontScale = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetFontScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetFontScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetDimensionScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dimScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetDimensionScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dimScale = arg.GetNumber(0)
	//pThis->GetEntity()->SetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetDimensionScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetDimensionScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, ResetAndClearCommands)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, ResetAndClearCommands)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ResetAndClearCommands();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, LoadFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, LoadFile_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SaveFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SaveFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SaveFile_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetHandlerFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetHandlerFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetHandlerFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetHandlerFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, AddParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddParagraph)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int paraStyle = arg.GetNumber(1)
	//pThis->GetEntity()->AddParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginBatchUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginBatchUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cmdName = arg.GetNumber(0)
	//pThis->GetEntity()->BeginBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndBatchUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndBatchUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BatchingUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, BatchingUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BatchingUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SubmitAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SubmitAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->SubmitAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetBatchedCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetBatchedCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBatchedCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginSuppressUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginSuppressUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BeginSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndSuppressUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndSuppressUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SuppressingUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, SuppressingUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SuppressingUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, CopyToClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, CopyToClipboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->CopyToClipboard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, PasteFromClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, PasteFromClipboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->PasteFromClipboard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, CanPasteFromClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, CanPasteFromClipboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanPasteFromClipboard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->BeginStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndAllStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndAllStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndAllStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, ClearStyleStack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, ClearStyleStack)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearStyleStack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetStyleStackSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetStyleStackSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyleStackSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BeginBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BeginItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginUnderline)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BeginUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndUnderline)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->BeginTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->BeginAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int leftIndent = arg.GetNumber(0)
	//int leftSubIndent = arg.GetNumber(1)
	//pThis->GetEntity()->BeginLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rightIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rightIndent = arg.GetNumber(0)
	//pThis->GetEntity()->BeginRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginParagraphSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "after", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginParagraphSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//int after = arg.GetNumber(1)
	//pThis->GetEntity()->BeginParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndParagraphSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndParagraphSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineSpacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int lineSpacing = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginNumberedBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginNumberedBullet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bulletNumber = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndNumberedBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndNumberedBullet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginSymbolBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginSymbolBullet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndSymbolBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndSymbolBullet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginStandardBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginStandardBullet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bulletName = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndStandardBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndStandardBullet)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int characterStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int paragraphStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginListStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int listStyle = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int number = arg.GetNumber(2)
	//pThis->GetEntity()->BeginListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndListStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, BeginURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, BeginURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//int characterStyle = arg.GetNumber(1)
	//pThis->GetEntity()->BeginURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, EndURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, EndURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EndURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, AddEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddEventHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, RemoveEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteHandler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, RemoveEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//int deleteHandler = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveEventHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, ClearEventHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, ClearEventHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearEventHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SendEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sendToAll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SendEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//int sendToAll = arg.GetNumber(1)
	//pThis->GetEntity()->SendEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, HitTest)
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

Gura_ImplementMethod(wx_RichTextBuffer, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextBuffer, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, operator=)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertParagraphsWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paragraphs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertParagraphsWithUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int paragraphs = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertParagraphsWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertTextWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertTextWithUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertTextWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertNewlineWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertNewlineWithUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->InsertNewlineWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertImageWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertImageWithUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int imageBlock = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int textAttr = arg.GetNumber(4)
	//pThis->GetEntity()->InsertImageWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertObjectWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertObjectWithUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int object = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertObjectWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, DeleteRangeWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, DeleteRangeWithUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRangeWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, Modify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modify", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, Modify)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int modify = arg.GetNumber(0)
	//pThis->GetEntity()->Modify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, IsModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, Dump)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, Dump_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, Dump_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, RemoveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, RemoveHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, FindHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, FindHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, FindHandler_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, FindHandler_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, FindHandlerFilenameOrType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, FindHandlerFilenameOrType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int imageType = arg.GetNumber(1)
	//pThis->GetEntity()->FindHandlerFilenameOrType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, FindHandler_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, FindHandler_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int imageType = arg.GetNumber(0)
	//pThis->GetEntity()->FindHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetExtWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "combine", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "save", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "types", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetExtWildcard)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int combine = arg.GetNumber(0)
	//int save = arg.GetNumber(1)
	//int types = arg.GetNumber(2)
	//pThis->GetEntity()->GetExtWildcard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, CleanUpHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, CleanUpHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CleanUpHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InitStandardHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, InitStandardHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->InitStandardHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetDrawingHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetDrawingHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDrawingHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, AddDrawingHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddDrawingHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, InsertDrawingHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, InsertDrawingHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, RemoveDrawingHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, RemoveDrawingHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, FindDrawingHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, FindDrawingHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, CleanUpDrawingHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, CleanUpDrawingHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CleanUpDrawingHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetFieldTypes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetFieldTypes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFieldTypes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, AddFieldType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, AddFieldType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->AddFieldType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, RemoveFieldType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, RemoveFieldType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFieldType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, FindFieldType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, FindFieldType)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindFieldType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, CleanUpFieldTypes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, CleanUpFieldTypes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CleanUpFieldTypes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "renderer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int renderer = arg.GetNumber(0)
	//pThis->GetEntity()->SetRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetBulletRightMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetBulletRightMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletRightMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetBulletRightMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetBulletRightMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletRightMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetBulletProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetBulletProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetBulletProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetBulletProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int scale = arg.GetNumber(0)
	//pThis->GetEntity()->SetScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, GetFloatingLayoutMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBuffer, GetFloatingLayoutMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFloatingLayoutMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBuffer, SetFloatingLayoutMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBuffer, SetFloatingLayoutMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBuffer *pThis = Object_wx_RichTextBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetFloatingLayoutMode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBuffer)
{
	Gura_AssignMethod(wx_RichTextBuffer, wxRichTextBuffer);
	Gura_AssignMethod(wx_RichTextBuffer, wxRichTextBuffer_1);
	Gura_AssignMethod(wx_RichTextBuffer, ~wxRichTextBuffer);
	Gura_AssignMethod(wx_RichTextBuffer, GetCommandProcessor);
	Gura_AssignMethod(wx_RichTextBuffer, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, SetStyleSheetAndNotify);
	Gura_AssignMethod(wx_RichTextBuffer, PushStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, PopStyleSheet);
	Gura_AssignMethod(wx_RichTextBuffer, GetFontTable);
	Gura_AssignMethod(wx_RichTextBuffer, GetFontTable_1);
	Gura_AssignMethod(wx_RichTextBuffer, SetFontTable);
	Gura_AssignMethod(wx_RichTextBuffer, SetFontScale);
	Gura_AssignMethod(wx_RichTextBuffer, GetFontScale);
	Gura_AssignMethod(wx_RichTextBuffer, SetDimensionScale);
	Gura_AssignMethod(wx_RichTextBuffer, GetDimensionScale);
	Gura_AssignMethod(wx_RichTextBuffer, Init);
	Gura_AssignMethod(wx_RichTextBuffer, ResetAndClearCommands);
	Gura_AssignMethod(wx_RichTextBuffer, LoadFile);
	Gura_AssignMethod(wx_RichTextBuffer, LoadFile_1);
	Gura_AssignMethod(wx_RichTextBuffer, SaveFile);
	Gura_AssignMethod(wx_RichTextBuffer, SaveFile_1);
	Gura_AssignMethod(wx_RichTextBuffer, SetHandlerFlags);
	Gura_AssignMethod(wx_RichTextBuffer, GetHandlerFlags);
	Gura_AssignMethod(wx_RichTextBuffer, AddParagraph);
	Gura_AssignMethod(wx_RichTextBuffer, BeginBatchUndo);
	Gura_AssignMethod(wx_RichTextBuffer, EndBatchUndo);
	Gura_AssignMethod(wx_RichTextBuffer, BatchingUndo);
	Gura_AssignMethod(wx_RichTextBuffer, SubmitAction);
	Gura_AssignMethod(wx_RichTextBuffer, GetBatchedCommand);
	Gura_AssignMethod(wx_RichTextBuffer, BeginSuppressUndo);
	Gura_AssignMethod(wx_RichTextBuffer, EndSuppressUndo);
	Gura_AssignMethod(wx_RichTextBuffer, SuppressingUndo);
	Gura_AssignMethod(wx_RichTextBuffer, CopyToClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, PasteFromClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, CanPasteFromClipboard);
	Gura_AssignMethod(wx_RichTextBuffer, BeginStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndAllStyles);
	Gura_AssignMethod(wx_RichTextBuffer, ClearStyleStack);
	Gura_AssignMethod(wx_RichTextBuffer, GetStyleStackSize);
	Gura_AssignMethod(wx_RichTextBuffer, BeginBold);
	Gura_AssignMethod(wx_RichTextBuffer, EndBold);
	Gura_AssignMethod(wx_RichTextBuffer, BeginItalic);
	Gura_AssignMethod(wx_RichTextBuffer, EndItalic);
	Gura_AssignMethod(wx_RichTextBuffer, BeginUnderline);
	Gura_AssignMethod(wx_RichTextBuffer, EndUnderline);
	Gura_AssignMethod(wx_RichTextBuffer, BeginFontSize);
	Gura_AssignMethod(wx_RichTextBuffer, EndFontSize);
	Gura_AssignMethod(wx_RichTextBuffer, BeginFont);
	Gura_AssignMethod(wx_RichTextBuffer, EndFont);
	Gura_AssignMethod(wx_RichTextBuffer, BeginTextColour);
	Gura_AssignMethod(wx_RichTextBuffer, EndTextColour);
	Gura_AssignMethod(wx_RichTextBuffer, BeginAlignment);
	Gura_AssignMethod(wx_RichTextBuffer, EndAlignment);
	Gura_AssignMethod(wx_RichTextBuffer, BeginLeftIndent);
	Gura_AssignMethod(wx_RichTextBuffer, EndLeftIndent);
	Gura_AssignMethod(wx_RichTextBuffer, BeginRightIndent);
	Gura_AssignMethod(wx_RichTextBuffer, EndRightIndent);
	Gura_AssignMethod(wx_RichTextBuffer, BeginParagraphSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, EndParagraphSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, BeginLineSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, EndLineSpacing);
	Gura_AssignMethod(wx_RichTextBuffer, BeginNumberedBullet);
	Gura_AssignMethod(wx_RichTextBuffer, EndNumberedBullet);
	Gura_AssignMethod(wx_RichTextBuffer, BeginSymbolBullet);
	Gura_AssignMethod(wx_RichTextBuffer, EndSymbolBullet);
	Gura_AssignMethod(wx_RichTextBuffer, BeginStandardBullet);
	Gura_AssignMethod(wx_RichTextBuffer, EndStandardBullet);
	Gura_AssignMethod(wx_RichTextBuffer, BeginCharacterStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndCharacterStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginParagraphStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndParagraphStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, EndListStyle);
	Gura_AssignMethod(wx_RichTextBuffer, BeginURL);
	Gura_AssignMethod(wx_RichTextBuffer, EndURL);
	Gura_AssignMethod(wx_RichTextBuffer, AddEventHandler);
	Gura_AssignMethod(wx_RichTextBuffer, RemoveEventHandler);
	Gura_AssignMethod(wx_RichTextBuffer, ClearEventHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, SendEvent);
	Gura_AssignMethod(wx_RichTextBuffer, HitTest);
	Gura_AssignMethod(wx_RichTextBuffer, Copy);
	Gura_AssignMethod(wx_RichTextBuffer, operator=);
	Gura_AssignMethod(wx_RichTextBuffer, Clone);
	Gura_AssignMethod(wx_RichTextBuffer, InsertParagraphsWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, InsertTextWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, InsertNewlineWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, InsertImageWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, InsertObjectWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, DeleteRangeWithUndo);
	Gura_AssignMethod(wx_RichTextBuffer, Modify);
	Gura_AssignMethod(wx_RichTextBuffer, IsModified);
	Gura_AssignMethod(wx_RichTextBuffer, Dump);
	Gura_AssignMethod(wx_RichTextBuffer, Dump_1);
	Gura_AssignMethod(wx_RichTextBuffer, GetHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, AddHandler);
	Gura_AssignMethod(wx_RichTextBuffer, InsertHandler);
	Gura_AssignMethod(wx_RichTextBuffer, RemoveHandler);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandler);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandler_1);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandlerFilenameOrType);
	Gura_AssignMethod(wx_RichTextBuffer, FindHandler_2);
	Gura_AssignMethod(wx_RichTextBuffer, GetExtWildcard);
	Gura_AssignMethod(wx_RichTextBuffer, CleanUpHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, InitStandardHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, GetDrawingHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, AddDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, InsertDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, RemoveDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, FindDrawingHandler);
	Gura_AssignMethod(wx_RichTextBuffer, CleanUpDrawingHandlers);
	Gura_AssignMethod(wx_RichTextBuffer, GetFieldTypes);
	Gura_AssignMethod(wx_RichTextBuffer, AddFieldType);
	Gura_AssignMethod(wx_RichTextBuffer, RemoveFieldType);
	Gura_AssignMethod(wx_RichTextBuffer, FindFieldType);
	Gura_AssignMethod(wx_RichTextBuffer, CleanUpFieldTypes);
	Gura_AssignMethod(wx_RichTextBuffer, GetRenderer);
	Gura_AssignMethod(wx_RichTextBuffer, SetRenderer);
	Gura_AssignMethod(wx_RichTextBuffer, GetBulletRightMargin);
	Gura_AssignMethod(wx_RichTextBuffer, SetBulletRightMargin);
	Gura_AssignMethod(wx_RichTextBuffer, GetBulletProportion);
	Gura_AssignMethod(wx_RichTextBuffer, SetBulletProportion);
	Gura_AssignMethod(wx_RichTextBuffer, GetScale);
	Gura_AssignMethod(wx_RichTextBuffer, SetScale);
	Gura_AssignMethod(wx_RichTextBuffer, GetFloatingLayoutMode);
	Gura_AssignMethod(wx_RichTextBuffer, SetFloatingLayoutMode);
}

Gura_ImplementDescendantCreator(wx_RichTextBuffer)
{
	return new Object_wx_RichTextBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
