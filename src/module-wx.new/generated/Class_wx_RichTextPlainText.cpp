//----------------------------------------------------------------------------
// wxRichTextPlainText
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPlainText
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPlainText
//----------------------------------------------------------------------------
Object_wx_RichTextPlainText::~Object_wx_RichTextPlainText()
{
}

Object *Object_wx_RichTextPlainText::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPlainText::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPlainText:");
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
Gura_DeclareFunctionAlias(__RichTextPlainText, "RichTextPlainText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPlainText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextPlainText)
{
	//const wxString& text = arg.GetNumber(0)
	//wxRichTextObject* parent = arg.GetNumber(1)
	//wxRichTextAttr* style = arg.GetNumber(2)
	//wxRichTextPlainText(text, parent, style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextPlainText_1, "RichTextPlainText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPlainText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextPlainText_1)
{
	//const wxRichTextPlainText& obj = arg.GetNumber(0)
	//wxRichTextPlainText(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextPlainText, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextPlainText, __Draw)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Layout)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//const wxRect& parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Layout(dc, context, rect, parentRect, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetRangeSize, "GetRangeSize")
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

Gura_ImplementMethod(wx_RichTextPlainText, __GetRangeSize)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetTextForRange)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetTextForRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __DoSplit, "DoSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __DoSplit)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->DoSplit(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __CalculateRange, "CalculateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __CalculateRange)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long& end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange(start, end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __DeleteRange)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __IsEmpty)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __CanMerge, "CanMerge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __CanMerge)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* object = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CanMerge(object, context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Merge, "Merge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Merge)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* object = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Merge(object, context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __CanSplit, "CanSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __CanSplit)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextDrawingContext& context = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanSplit(context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Split, "Split")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Split)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextDrawingContext& context = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->Split(context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Dump, "Dump")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Dump)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextOutputStream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetFirstLineBreakPosition, "GetFirstLineBreakPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetFirstLineBreakPosition)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//long _rtn = pThis->GetEntity()->GetFirstLineBreakPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __UsesParagraphAttributes, "UsesParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __UsesParagraphAttributes)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __ImportFromXML)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxXmlNode* node = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool* recurse = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->ImportFromXML(buffer, node, handler, recurse);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __ExportXML)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->ExportXML(stream, indent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __ExportXML_1)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* parent = arg.GetNumber(0)
	//wxRichTextXMLHandler* handler = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ExportXML(parent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetXMLNodeName)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetText)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __SetText)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText(text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Copy)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextPlainText& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Clone)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __DrawTabbedString, "DrawTabbedString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selected", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __DrawTabbedString)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRichTextAttr& attr = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//wxString& str = arg.GetNumber(3)
	//wxCoord& x = arg.GetNumber(4)
	//wxCoord& y = arg.GetNumber(5)
	//bool selected = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->DrawTabbedString(dc, attr, rect, str, x, y, selected);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPlainText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPlainText)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextPlainText);
	Gura_AssignFunction(__RichTextPlainText_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextPlainText, __Draw);
	Gura_AssignMethod(wx_RichTextPlainText, __Layout);
	Gura_AssignMethod(wx_RichTextPlainText, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextPlainText, __GetTextForRange);
	Gura_AssignMethod(wx_RichTextPlainText, __DoSplit);
	Gura_AssignMethod(wx_RichTextPlainText, __CalculateRange);
	Gura_AssignMethod(wx_RichTextPlainText, __DeleteRange);
	Gura_AssignMethod(wx_RichTextPlainText, __IsEmpty);
	Gura_AssignMethod(wx_RichTextPlainText, __CanMerge);
	Gura_AssignMethod(wx_RichTextPlainText, __Merge);
	Gura_AssignMethod(wx_RichTextPlainText, __CanSplit);
	Gura_AssignMethod(wx_RichTextPlainText, __Split);
	Gura_AssignMethod(wx_RichTextPlainText, __Dump);
	Gura_AssignMethod(wx_RichTextPlainText, __GetFirstLineBreakPosition);
	Gura_AssignMethod(wx_RichTextPlainText, __UsesParagraphAttributes);
	Gura_AssignMethod(wx_RichTextPlainText, __ImportFromXML);
	Gura_AssignMethod(wx_RichTextPlainText, __ExportXML);
	Gura_AssignMethod(wx_RichTextPlainText, __ExportXML_1);
	Gura_AssignMethod(wx_RichTextPlainText, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextPlainText, __GetText);
	Gura_AssignMethod(wx_RichTextPlainText, __SetText);
	Gura_AssignMethod(wx_RichTextPlainText, __Copy);
	Gura_AssignMethod(wx_RichTextPlainText, __Clone);
	Gura_AssignMethod(wx_RichTextPlainText, __DrawTabbedString);
}

Gura_ImplementDescendantCreator(wx_RichTextPlainText)
{
	return new Object_wx_RichTextPlainText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
