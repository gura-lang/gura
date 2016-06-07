//----------------------------------------------------------------------------
// wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Object_wx_RichTextParagraphLayoutBox::~Object_wx_RichTextParagraphLayoutBox()
{
}

Object *Object_wx_RichTextParagraphLayoutBox::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextParagraphLayoutBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraphLayoutBox:");
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
Gura_DeclareFunctionAlias(__RichTextParagraphLayoutBox, "RichTextParagraphLayoutBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraphLayoutBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextParagraphLayoutBox)
{
	//wxRichTextObject* parent = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox(parent);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextParagraphLayoutBox_1, "RichTextParagraphLayoutBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraphLayoutBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextParagraphLayoutBox_1)
{
	//const wxRichTextParagraphLayoutBox& obj = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "contextObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __HitTest)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxPoint& pt = arg.GetNumber(2)
	//long& textPosition = arg.GetNumber(3)
	//wxRichTextObject** obj = arg.GetNumber(4)
	//wxRichTextObject** contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//int _rtn = pThis->GetEntity()->HitTest(dc, context, pt, textPosition, obj, contextObj, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Draw, "Draw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Draw)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRichTextRange& range = arg.GetNumber(2)
	//const wxRichTextSelection& selection = arg.GetNumber(3)
	//const wxRect& rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Draw(dc, context, range, selection, rect, descent, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Layout)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//const wxRect& parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Layout(dc, context, rect, parentRect, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetRangeSize, "GetRangeSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetRangeSize)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxSize& size = arg.GetNumber(1)
	//int& descent = arg.GetNumber(2)
	//wxDC& dc = arg.GetNumber(3)
	//wxRichTextDrawingContext& context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//const wxPoint& position = arg.GetNumber(6)
	//const wxSize& parentSize = arg.GetNumber(7)
	//wxArrayInt* partialExtents = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->GetRangeSize(range, size, descent, dc, context, flags, position, parentSize, partialExtents);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __DeleteRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetTextForRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetTextForRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __ImportFromXML)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxXmlNode* node = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool* recurse = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->ImportFromXML(buffer, node, handler, recurse);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __ExportXML)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->ExportXML(stream, indent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __ExportXML_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* parent = arg.GetNumber(0)
	//wxRichTextXMLHandler* handler = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ExportXML(parent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetXMLNodeName)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __AcceptsFocus)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetRichTextCtrl, "SetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetRichTextCtrl)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextCtrl* ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl(ctrl);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetRichTextCtrl, "GetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetRichTextCtrl)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextCtrl* _rtn = pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetPartialParagraph, "SetPartialParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "partialPara", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetPartialParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool partialPara = arg.GetNumber(0)
	//pThis->GetEntity()->SetPartialParagraph(partialPara);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetPartialParagraph, "GetPartialParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetPartialParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetPartialParagraph();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetStyleSheet)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextStyleSheet* _rtn = pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __IsTopLevel, "IsTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __IsTopLevel)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertParagraphsWithUndo, "InsertParagraphsWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paragraphs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertParagraphsWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//const wxRichTextParagraphLayoutBox& paragraphs = arg.GetNumber(2)
	//wxRichTextCtrl* ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->InsertParagraphsWithUndo(buffer, pos, paragraphs, ctrl, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertTextWithUndo, "InsertTextWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertTextWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//wxRichTextCtrl* ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->InsertTextWithUndo(buffer, pos, text, ctrl, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertNewlineWithUndo, "InsertNewlineWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertNewlineWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//wxRichTextCtrl* ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->InsertNewlineWithUndo(buffer, pos, ctrl, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertImageWithUndo, "InsertImageWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertImageWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//const wxRichTextImageBlock& imageBlock = arg.GetNumber(2)
	//wxRichTextCtrl* ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//const wxRichTextAttr& textAttr = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->InsertImageWithUndo(buffer, pos, imageBlock, ctrl, flags, textAttr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertFieldWithUndo, "InsertFieldWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertFieldWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//const wxString& fieldType = arg.GetNumber(2)
	//const wxRichTextProperties& properties = arg.GetNumber(3)
	//wxRichTextCtrl* ctrl = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//const wxRichTextAttr& textAttr = arg.GetNumber(6)
	//wxRichTextField* _rtn = pThis->GetEntity()->InsertFieldWithUndo(buffer, pos, fieldType, properties, ctrl, flags, textAttr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetStyleForNewParagraph, "GetStyleForNewParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lookUpNewParaStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetStyleForNewParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//bool caretPosition = arg.GetNumber(2)
	//bool lookUpNewParaStyle = arg.GetNumber(3)
	//wxRichTextAttr _rtn = pThis->GetEntity()->GetStyleForNewParagraph(buffer, pos, caretPosition, lookUpNewParaStyle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertObjectWithUndo, "InsertObjectWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertObjectWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//long pos = arg.GetNumber(1)
	//wxRichTextObject* object = arg.GetNumber(2)
	//wxRichTextCtrl* ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//wxRichTextObject* _rtn = pThis->GetEntity()->InsertObjectWithUndo(buffer, pos, object, ctrl, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __DeleteRangeWithUndo, "DeleteRangeWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __DeleteRangeWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextCtrl* ctrl = arg.GetNumber(1)
	//wxRichTextBuffer* buffer = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->DeleteRangeWithUndo(range, ctrl, buffer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __DrawFloats, "DrawFloats")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __DrawFloats)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRichTextRange& range = arg.GetNumber(2)
	//const wxRichTextSelection& selection = arg.GetNumber(3)
	//const wxRect& rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->DrawFloats(dc, context, range, selection, rect, descent, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __MoveAnchoredObjectToParagraph, "MoveAnchoredObjectToParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __MoveAnchoredObjectToParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* from = arg.GetNumber(0)
	//wxRichTextParagraph* to = arg.GetNumber(1)
	//wxRichTextObject* obj = arg.GetNumber(2)
	//pThis->GetEntity()->MoveAnchoredObjectToParagraph(from, to, obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Init)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Clear)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Reset)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __AddParagraph, "AddParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __AddParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxRichTextAttr* paraStyle = arg.GetNumber(1)
	//wxRichTextRange _rtn = pThis->GetEntity()->AddParagraph(text, paraStyle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __AddImage, "AddImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __AddImage)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxImage& image = arg.GetNumber(0)
	//wxRichTextAttr* paraStyle = arg.GetNumber(1)
	//wxRichTextRange _rtn = pThis->GetEntity()->AddImage(image, paraStyle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __AddParagraphs, "AddParagraphs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __AddParagraphs)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxRichTextAttr* paraStyle = arg.GetNumber(1)
	//wxRichTextRange _rtn = pThis->GetEntity()->AddParagraphs(text, paraStyle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetLineAtPosition, "GetLineAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetLineAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//bool caretPosition = arg.GetNumber(1)
	//wxRichTextLine* _rtn = pThis->GetEntity()->GetLineAtPosition(pos, caretPosition);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetLineAtYPosition, "GetLineAtYPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetLineAtYPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//wxRichTextLine* _rtn = pThis->GetEntity()->GetLineAtYPosition(y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetParagraphAtPosition, "GetParagraphAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetParagraphAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//bool caretPosition = arg.GetNumber(1)
	//wxRichTextParagraph* _rtn = pThis->GetEntity()->GetParagraphAtPosition(pos, caretPosition);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetLineSizeAtPosition, "GetLineSizeAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetLineSizeAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//bool caretPosition = arg.GetNumber(1)
	//wxSize _rtn = pThis->GetEntity()->GetLineSizeAtPosition(pos, caretPosition);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetVisibleLineNumber, "GetVisibleLineNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startOfLine", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetVisibleLineNumber)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//bool caretPosition = arg.GetNumber(1)
	//bool startOfLine = arg.GetNumber(2)
	//long _rtn = pThis->GetEntity()->GetVisibleLineNumber(pos, caretPosition, startOfLine);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetLineForVisibleLineNumber, "GetLineForVisibleLineNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "lineNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetLineForVisibleLineNumber)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long lineNumber = arg.GetNumber(0)
	//wxRichTextLine* _rtn = pThis->GetEntity()->GetLineForVisibleLineNumber(lineNumber);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetLeafObjectAtPosition, "GetLeafObjectAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetLeafObjectAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->GetLeafObjectAtPosition(position);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetParagraphAtLine, "GetParagraphAtLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraphNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetParagraphAtLine)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long paragraphNumber = arg.GetNumber(0)
	//wxRichTextParagraph* _rtn = pThis->GetEntity()->GetParagraphAtLine(paragraphNumber);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetParagraphForLine, "GetParagraphForLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetParagraphForLine)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextLine* line = arg.GetNumber(0)
	//wxRichTextParagraph* _rtn = pThis->GetEntity()->GetParagraphForLine(line);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetParagraphLength, "GetParagraphLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraphNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetParagraphLength)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long paragraphNumber = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetParagraphLength(paragraphNumber);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetParagraphCount, "GetParagraphCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetParagraphCount)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetParagraphCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetLineCount, "GetLineCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetLineCount)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetLineCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetParagraphText, "GetParagraphText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraphNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetParagraphText)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long paragraphNumber = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetParagraphText(paragraphNumber);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __XYToPosition, "XYToPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __XYToPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long x = arg.GetNumber(0)
	//long y = arg.GetNumber(1)
	//long _rtn = pThis->GetEntity()->XYToPosition(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __PositionToXY, "PositionToXY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __PositionToXY)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//long* x = arg.GetNumber(1)
	//long* y = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->PositionToXY(pos, x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxRichTextAttr& style = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetStyle(range, style, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetStyle_1, "SetStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetStyle_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//const wxRichTextAttr& textAttr = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle(obj, textAttr, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxRichTextAttr& style = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetStyle(position, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetUncombinedStyle, "GetUncombinedStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetUncombinedStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxRichTextAttr& style = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetUncombinedStyle(position, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __DoGetStyle, "DoGetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "combineStyles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __DoGetStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxRichTextAttr& style = arg.GetNumber(1)
	//bool combineStyles = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->DoGetStyle(position, style, combineStyles);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetStyleForRange, "GetStyleForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetStyleForRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextAttr& style = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetStyleForRange(range, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __CollectStyle, "CollectStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "currentStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __CollectStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextAttr& currentStyle = arg.GetNumber(0)
	//const wxRichTextAttr& style = arg.GetNumber(1)
	//wxRichTextAttr& clashingAttr = arg.GetNumber(2)
	//wxRichTextAttr& absentAttr = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->CollectStyle(currentStyle, style, clashingAttr, absentAttr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetListStyle, "SetListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetListStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextListStyleDefinition* def = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->SetListStyle(range, def, flags, startFrom, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetListStyle_1, "SetListStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetListStyle_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxString& defName = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->SetListStyle(range, defName, flags, startFrom, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __ClearListStyle, "ClearListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __ClearListStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ClearListStyle(range, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __NumberList, "NumberList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __NumberList)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextListStyleDefinition* def = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->NumberList(range, def, flags, startFrom, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __NumberList_1, "NumberList_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __NumberList_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxString& defName = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->NumberList(range, defName, flags, startFrom, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __PromoteList, "PromoteList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __PromoteList)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int promoteBy = arg.GetNumber(0)
	//const wxRichTextRange& range = arg.GetNumber(1)
	//wxRichTextListStyleDefinition* def = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->PromoteList(promoteBy, range, def, flags, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __PromoteList_1, "PromoteList_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __PromoteList_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int promoteBy = arg.GetNumber(0)
	//const wxRichTextRange& range = arg.GetNumber(1)
	//const wxString& defName = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->PromoteList(promoteBy, range, defName, flags, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __DoNumberList, "DoNumberList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "promotionRange", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __DoNumberList)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxRichTextRange& promotionRange = arg.GetNumber(1)
	//int promoteBy = arg.GetNumber(2)
	//wxRichTextListStyleDefinition* def = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//int startFrom = arg.GetNumber(5)
	//int specifiedLevel = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->DoNumberList(range, promotionRange, promoteBy, def, flags, startFrom, specifiedLevel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __FindNextParagraphNumber, "FindNextParagraphNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "previousParagraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __FindNextParagraphNumber)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* previousParagraph = arg.GetNumber(0)
	//wxRichTextAttr& attr = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->FindNextParagraphNumber(previousParagraph, attr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetProperties, "SetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetProperties)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxRichTextProperties& properties = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetProperties(range, properties, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetObjectPropertiesWithUndo, "SetObjectPropertiesWithUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "objToSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetObjectPropertiesWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject& obj = arg.GetNumber(0)
	//const wxRichTextProperties& properties = arg.GetNumber(1)
	//wxRichTextObject* objToSet = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->SetObjectPropertiesWithUndo(obj, properties, objToSet);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __HasCharacterAttributes, "HasCharacterAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __HasCharacterAttributes)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxRichTextAttr& style = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->HasCharacterAttributes(range, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __HasParagraphAttributes, "HasParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __HasParagraphAttributes)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxRichTextAttr& style = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->HasParagraphAttributes(range, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Clone)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __PrepareContent, "PrepareContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __PrepareContent)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraphLayoutBox& container = arg.GetNumber(0)
	//pThis->GetEntity()->PrepareContent(container);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InsertFragment, "InsertFragment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fragment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InsertFragment)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox& fragment = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->InsertFragment(position, fragment);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __CopyFragment, "CopyFragment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fragment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __CopyFragment)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox& fragment = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CopyFragment(range, fragment);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __ApplyStyleSheet, "ApplyStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __ApplyStyleSheet)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextStyleSheet* styleSheet = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ApplyStyleSheet(styleSheet);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Copy)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextParagraphLayoutBox& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __UpdateRanges, "UpdateRanges")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __UpdateRanges)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateRanges();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetText)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetDefaultStyle, "SetDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetDefaultStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& style = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetDefaultStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetDefaultStyle, "GetDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetDefaultStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& _rtn = pThis->GetEntity()->GetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __SetBasicStyle, "SetBasicStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __SetBasicStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& style = arg.GetNumber(0)
	//pThis->GetEntity()->SetBasicStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetBasicStyle, "GetBasicStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetBasicStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& _rtn = pThis->GetEntity()->GetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __Invalidate, "Invalidate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __Invalidate)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate(invalidRange);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __DoInvalidate, "DoInvalidate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __DoInvalidate)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->DoInvalidate(invalidRange);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __InvalidateHierarchy, "InvalidateHierarchy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __InvalidateHierarchy)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->InvalidateHierarchy(invalidRange);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __UpdateFloatingObjects, "UpdateFloatingObjects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "availableRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "untilObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __UpdateFloatingObjects)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& availableRect = arg.GetNumber(0)
	//wxRichTextObject* untilObj = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->UpdateFloatingObjects(availableRect, untilObj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetInvalidRange, "GetInvalidRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "wholeParagraphs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetInvalidRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool wholeParagraphs = arg.GetNumber(0)
	//wxRichTextRange _rtn = pThis->GetEntity()->GetInvalidRange(wholeParagraphs);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __IsDirty, "IsDirty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __IsDirty)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsDirty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetFloatCollector, "GetFloatCollector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetFloatCollector)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextFloatCollector* _rtn = pThis->GetEntity()->GetFloatCollector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetFloatingObjectCount, "GetFloatingObjectCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetFloatingObjectCount)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFloatingObjectCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphLayoutBox, __GetFloatingObjects, "GetFloatingObjects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "objects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, __GetFloatingObjects)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObjectList& objects = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetFloatingObjects(objects);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphLayoutBox)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextParagraphLayoutBox);
	Gura_AssignFunction(__RichTextParagraphLayoutBox_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __HitTest);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Draw);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Layout);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __DeleteRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetTextForRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __ImportFromXML);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __ExportXML);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __ExportXML_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __AcceptsFocus);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetPartialParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetPartialParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetStyleSheet);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __IsTopLevel);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertParagraphsWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertTextWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertNewlineWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertImageWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertFieldWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetStyleForNewParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertObjectWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __DeleteRangeWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __DrawFloats);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __MoveAnchoredObjectToParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Init);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Clear);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Reset);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __AddParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __AddImage);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __AddParagraphs);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetLineAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetLineAtYPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetParagraphAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetLineSizeAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetVisibleLineNumber);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetLineForVisibleLineNumber);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetLeafObjectAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetParagraphAtLine);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetParagraphForLine);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetParagraphLength);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetParagraphCount);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetLineCount);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetParagraphText);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __XYToPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __PositionToXY);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetStyle_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetUncombinedStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __DoGetStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetStyleForRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __CollectStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetListStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetListStyle_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __ClearListStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __NumberList);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __NumberList_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __PromoteList);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __PromoteList_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __DoNumberList);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __FindNextParagraphNumber);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetProperties);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetObjectPropertiesWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __HasCharacterAttributes);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __HasParagraphAttributes);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Clone);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __PrepareContent);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InsertFragment);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __CopyFragment);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __ApplyStyleSheet);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Copy);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __UpdateRanges);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetText);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetDefaultStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetDefaultStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __SetBasicStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetBasicStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __Invalidate);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __DoInvalidate);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __InvalidateHierarchy);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __UpdateFloatingObjects);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetInvalidRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __IsDirty);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetFloatCollector);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetFloatingObjectCount);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, __GetFloatingObjects);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphLayoutBox)
{
	return new Object_wx_RichTextParagraphLayoutBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
