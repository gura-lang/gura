//----------------------------------------------------------------------------
// wxRichTextObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextObject
//----------------------------------------------------------------------------
Object_wx_RichTextObject::~Object_wx_RichTextObject()
{
}

Object *Object_wx_RichTextObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextObject:");
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
Gura_DeclareFunctionAlias(__RichTextObject, "RichTextObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextObject)
{
	//wxRichTextObject* parent = arg.GetNumber(0)
	//wxRichTextObject(parent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextObject, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextObject, __Draw)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextObject, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Layout)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//const wxRect& parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Layout(dc, context, rect, parentRect, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __HitTest, "HitTest")
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

Gura_ImplementMethod(wx_RichTextObject, __HitTest)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextObject, __FindPosition, "FindPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __FindPosition)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//long index = arg.GetNumber(2)
	//wxPoint& pt = arg.GetNumber(3)
	//int* height = arg.GetNumber(4)
	//bool forceLineStart = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->FindPosition(dc, context, index, pt, height, forceLineStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBestSize, "GetBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBestSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRangeSize, "GetRangeSize")
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

Gura_ImplementMethod(wx_RichTextObject, __GetRangeSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextObject, __DoSplit, "DoSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __DoSplit)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->DoSplit(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CalculateRange, "CalculateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __CalculateRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long& end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange(start, end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __DeleteRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsEmpty)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsFloatable, "IsFloatable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsFloatable)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsFloating, "IsFloating")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsFloating)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetFloatDirection, "GetFloatDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetFloatDirection)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFloatDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetTextForRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetTextForRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CanMerge, "CanMerge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __CanMerge)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* object = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CanMerge(object, context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Merge, "Merge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Merge)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* object = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Merge(object, context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CanSplit, "CanSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __CanSplit)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextDrawingContext& context = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanSplit(context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Split, "Split")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Split)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextDrawingContext& context = arg.GetNumber(0)
	//wxRichTextObject* _rtn = pThis->GetEntity()->Split(context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Dump, "Dump")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Dump)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextOutputStream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __CanEditProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __EditProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->EditProperties(parent, buffer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __AcceptsFocus)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ImportFromXML)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxXmlNode* node = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool* recurse = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->ImportFromXML(buffer, node, handler, recurse);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ExportXML)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->ExportXML(stream, indent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ExportXML_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* parent = arg.GetNumber(0)
	//wxRichTextXMLHandler* handler = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ExportXML(parent, handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __UsesParagraphAttributes, "UsesParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __UsesParagraphAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetXMLNodeName)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Invalidate, "Invalidate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Invalidate)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate(invalidRange);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __HandlesChildSelections, "HandlesChildSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __HandlesChildSelections)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HandlesChildSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetSelection)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long end = arg.GetNumber(1)
	//wxRichTextSelection _rtn = pThis->GetEntity()->GetSelection(start, end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetCachedSize, "GetCachedSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetCachedSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetCachedSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetCachedSize, "SetCachedSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetCachedSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetCachedSize(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetMaxSize, "GetMaxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetMaxSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetMaxSize, "SetMaxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetMaxSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxSize(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetMinSize, "GetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetMinSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetMinSize, "SetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetMinSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetNaturalSize, "GetNaturalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetNaturalSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextAttrSize _rtn = pThis->GetEntity()->GetNaturalSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetPosition)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetPosition)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAbsolutePosition, "GetAbsolutePosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAbsolutePosition)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetAbsolutePosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRect)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRect _rtn = pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& _rtn = pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRange_1, "GetRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRange_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRange& _rtn = pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetOwnRange, "SetOwnRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetOwnRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwnRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetOwnRange, "GetOwnRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetOwnRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& _rtn = pThis->GetEntity()->GetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetOwnRange_1, "GetOwnRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetOwnRange_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRange& _rtn = pThis->GetEntity()->GetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetOwnRangeIfTopLevel, "GetOwnRangeIfTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetOwnRangeIfTopLevel)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRange _rtn = pThis->GetEntity()->GetOwnRangeIfTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsComposite, "IsComposite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsComposite)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsComposite();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsAtomic, "IsAtomic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsAtomic)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetParent)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* _rtn = pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetParent, "SetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetParent)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetContainer)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraphLayoutBox* _rtn = pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetParentContainer, "GetParentContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetParentContainer)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraphLayoutBox* _rtn = pThis->GetEntity()->GetParentContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetMargins)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins(margin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "leftMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rightMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomMargin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetMargins_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int leftMargin = arg.GetNumber(0)
	//int rightMargin = arg.GetNumber(1)
	//int topMargin = arg.GetNumber(2)
	//int bottomMargin = arg.GetNumber(3)
	//pThis->GetEntity()->SetMargins(leftMargin, rightMargin, topMargin, bottomMargin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetLeftMargin, "GetLeftMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetLeftMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRightMargin, "GetRightMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRightMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetTopMargin, "GetTopMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetTopMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBottomMargin, "GetBottomMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBottomMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAvailableContentArea, "GetAvailableContentArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outerRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAvailableContentArea)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRect& outerRect = arg.GetNumber(2)
	//wxRect _rtn = pThis->GetEntity()->GetAvailableContentArea(dc, context, outerRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __LayoutToBestSize, "LayoutToBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableParentSpace", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableContainerSpace", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __LayoutToBestSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//wxRichTextBuffer* buffer = arg.GetNumber(2)
	//const wxRichTextAttr& parentAttr = arg.GetNumber(3)
	//const wxRichTextAttr& attr = arg.GetNumber(4)
	//const wxRect& availableParentSpace = arg.GetNumber(5)
	//const wxRect& availableContainerSpace = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->LayoutToBestSize(dc, context, buffer, parentAttr, attr, availableParentSpace, availableContainerSpace, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __AdjustAttributes, "AdjustAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __AdjustAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextAttr& attr = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->AdjustAttributes(attr, context);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetAttributes, "SetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttributes(attr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAttributes, "GetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& _rtn = pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAttributes_1, "GetAttributes_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAttributes_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextAttr& _rtn = pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetProperties, "GetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextProperties& _rtn = pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetProperties_1, "GetProperties_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetProperties_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& _rtn = pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetProperties, "SetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties(props);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetDescent, "SetDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetDescent)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int descent = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescent(descent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetDescent, "GetDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetDescent)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetDescent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBuffer, "GetBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBuffer)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* _rtn = pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __SetName)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetName)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsTopLevel, "IsTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsTopLevel)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsShown, "IsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsShown)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Show)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->Show(show);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __Clone)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Copy)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextObject& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Reference, "Reference")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __Reference)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reference();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Dereference, "Dereference")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __Dereference)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dereference();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Move, "Move")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Move)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertTenthsMMToPixels, "ConvertTenthsMMToPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ConvertTenthsMMToPixels)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->ConvertTenthsMMToPixels(dc, units);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertTenthsMMToPixels_1, "ConvertTenthsMMToPixels_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ppi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ConvertTenthsMMToPixels_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ppi = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//double scale = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->ConvertTenthsMMToPixels(ppi, units, scale);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertPixelsToTenthsMM, "ConvertPixelsToTenthsMM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ConvertPixelsToTenthsMM)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->ConvertPixelsToTenthsMM(dc, pixels);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertPixelsToTenthsMM_1, "ConvertPixelsToTenthsMM_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ppi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ConvertPixelsToTenthsMM_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ppi = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//double scale = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->ConvertPixelsToTenthsMM(ppi, pixels, scale);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DrawBoxAttributes, "DrawBoxAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "boxRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __DrawBoxAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& boxRect = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//wxRichTextObject* obj = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->DrawBoxAttributes(dc, buffer, attr, boxRect, flags, obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DrawBorder, "DrawBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "borders", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __DrawBorder)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxTextAttrBorders& borders = arg.GetNumber(3)
	//const wxRect& rect = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->DrawBorder(dc, buffer, attr, borders, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBoxRects, "GetBoxRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "marginRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "borderRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "contentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paddingRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outlineRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBoxRects)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//wxRect& marginRect = arg.GetNumber(3)
	//wxRect& borderRect = arg.GetNumber(4)
	//wxRect& contentRect = arg.GetNumber(5)
	//wxRect& paddingRect = arg.GetNumber(6)
	//wxRect& outlineRect = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->GetBoxRects(dc, buffer, attr, marginRect, borderRect, contentRect, paddingRect, outlineRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetTotalMargin, "GetTotalMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rightMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomMargin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetTotalMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//int& leftMargin = arg.GetNumber(3)
	//int& rightMargin = arg.GetNumber(4)
	//int& topMargin = arg.GetNumber(5)
	//int& bottomMargin = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->GetTotalMargin(dc, buffer, attr, leftMargin, rightMargin, topMargin, bottomMargin);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __AdjustAvailableSpace, "AdjustAvailableSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableParentSpace", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableContainerSpace", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __AdjustAvailableSpace)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//const wxRichTextAttr& parentAttr = arg.GetNumber(2)
	//const wxRichTextAttr& childAttr = arg.GetNumber(3)
	//const wxRect& availableParentSpace = arg.GetNumber(4)
	//const wxRect& availableContainerSpace = arg.GetNumber(5)
	//wxRect _rtn = pThis->GetEntity()->AdjustAvailableSpace(dc, buffer, parentAttr, childAttr, availableParentSpace, availableContainerSpace);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObject)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextObject);
	// Method assignment
	Gura_AssignMethod(wx_RichTextObject, __Draw);
	Gura_AssignMethod(wx_RichTextObject, __Layout);
	Gura_AssignMethod(wx_RichTextObject, __HitTest);
	Gura_AssignMethod(wx_RichTextObject, __FindPosition);
	Gura_AssignMethod(wx_RichTextObject, __GetBestSize);
	Gura_AssignMethod(wx_RichTextObject, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextObject, __DoSplit);
	Gura_AssignMethod(wx_RichTextObject, __CalculateRange);
	Gura_AssignMethod(wx_RichTextObject, __DeleteRange);
	Gura_AssignMethod(wx_RichTextObject, __IsEmpty);
	Gura_AssignMethod(wx_RichTextObject, __IsFloatable);
	Gura_AssignMethod(wx_RichTextObject, __IsFloating);
	Gura_AssignMethod(wx_RichTextObject, __GetFloatDirection);
	Gura_AssignMethod(wx_RichTextObject, __GetTextForRange);
	Gura_AssignMethod(wx_RichTextObject, __CanMerge);
	Gura_AssignMethod(wx_RichTextObject, __Merge);
	Gura_AssignMethod(wx_RichTextObject, __CanSplit);
	Gura_AssignMethod(wx_RichTextObject, __Split);
	Gura_AssignMethod(wx_RichTextObject, __Dump);
	Gura_AssignMethod(wx_RichTextObject, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextObject, __EditProperties);
	Gura_AssignMethod(wx_RichTextObject, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextObject, __AcceptsFocus);
	Gura_AssignMethod(wx_RichTextObject, __ImportFromXML);
	Gura_AssignMethod(wx_RichTextObject, __ExportXML);
	Gura_AssignMethod(wx_RichTextObject, __ExportXML_1);
	Gura_AssignMethod(wx_RichTextObject, __UsesParagraphAttributes);
	Gura_AssignMethod(wx_RichTextObject, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextObject, __Invalidate);
	Gura_AssignMethod(wx_RichTextObject, __HandlesChildSelections);
	Gura_AssignMethod(wx_RichTextObject, __GetSelection);
	Gura_AssignMethod(wx_RichTextObject, __GetCachedSize);
	Gura_AssignMethod(wx_RichTextObject, __SetCachedSize);
	Gura_AssignMethod(wx_RichTextObject, __GetMaxSize);
	Gura_AssignMethod(wx_RichTextObject, __SetMaxSize);
	Gura_AssignMethod(wx_RichTextObject, __GetMinSize);
	Gura_AssignMethod(wx_RichTextObject, __SetMinSize);
	Gura_AssignMethod(wx_RichTextObject, __GetNaturalSize);
	Gura_AssignMethod(wx_RichTextObject, __GetPosition);
	Gura_AssignMethod(wx_RichTextObject, __SetPosition);
	Gura_AssignMethod(wx_RichTextObject, __GetAbsolutePosition);
	Gura_AssignMethod(wx_RichTextObject, __GetRect);
	Gura_AssignMethod(wx_RichTextObject, __SetRange);
	Gura_AssignMethod(wx_RichTextObject, __GetRange);
	Gura_AssignMethod(wx_RichTextObject, __GetRange_1);
	Gura_AssignMethod(wx_RichTextObject, __SetOwnRange);
	Gura_AssignMethod(wx_RichTextObject, __GetOwnRange);
	Gura_AssignMethod(wx_RichTextObject, __GetOwnRange_1);
	Gura_AssignMethod(wx_RichTextObject, __GetOwnRangeIfTopLevel);
	Gura_AssignMethod(wx_RichTextObject, __IsComposite);
	Gura_AssignMethod(wx_RichTextObject, __IsAtomic);
	Gura_AssignMethod(wx_RichTextObject, __GetParent);
	Gura_AssignMethod(wx_RichTextObject, __SetParent);
	Gura_AssignMethod(wx_RichTextObject, __GetContainer);
	Gura_AssignMethod(wx_RichTextObject, __GetParentContainer);
	Gura_AssignMethod(wx_RichTextObject, __SetMargins);
	Gura_AssignMethod(wx_RichTextObject, __SetMargins_1);
	Gura_AssignMethod(wx_RichTextObject, __GetLeftMargin);
	Gura_AssignMethod(wx_RichTextObject, __GetRightMargin);
	Gura_AssignMethod(wx_RichTextObject, __GetTopMargin);
	Gura_AssignMethod(wx_RichTextObject, __GetBottomMargin);
	Gura_AssignMethod(wx_RichTextObject, __GetAvailableContentArea);
	Gura_AssignMethod(wx_RichTextObject, __LayoutToBestSize);
	Gura_AssignMethod(wx_RichTextObject, __AdjustAttributes);
	Gura_AssignMethod(wx_RichTextObject, __SetAttributes);
	Gura_AssignMethod(wx_RichTextObject, __GetAttributes);
	Gura_AssignMethod(wx_RichTextObject, __GetAttributes_1);
	Gura_AssignMethod(wx_RichTextObject, __GetProperties);
	Gura_AssignMethod(wx_RichTextObject, __GetProperties_1);
	Gura_AssignMethod(wx_RichTextObject, __SetProperties);
	Gura_AssignMethod(wx_RichTextObject, __SetDescent);
	Gura_AssignMethod(wx_RichTextObject, __GetDescent);
	Gura_AssignMethod(wx_RichTextObject, __GetBuffer);
	Gura_AssignMethod(wx_RichTextObject, __SetName);
	Gura_AssignMethod(wx_RichTextObject, __GetName);
	Gura_AssignMethod(wx_RichTextObject, __IsTopLevel);
	Gura_AssignMethod(wx_RichTextObject, __IsShown);
	Gura_AssignMethod(wx_RichTextObject, __Show);
	Gura_AssignMethod(wx_RichTextObject, __Clone);
	Gura_AssignMethod(wx_RichTextObject, __Copy);
	Gura_AssignMethod(wx_RichTextObject, __Reference);
	Gura_AssignMethod(wx_RichTextObject, __Dereference);
	Gura_AssignMethod(wx_RichTextObject, __Move);
	Gura_AssignMethod(wx_RichTextObject, __ConvertTenthsMMToPixels);
	Gura_AssignMethod(wx_RichTextObject, __ConvertTenthsMMToPixels_1);
	Gura_AssignMethod(wx_RichTextObject, __ConvertPixelsToTenthsMM);
	Gura_AssignMethod(wx_RichTextObject, __ConvertPixelsToTenthsMM_1);
	Gura_AssignMethod(wx_RichTextObject, __DrawBoxAttributes);
	Gura_AssignMethod(wx_RichTextObject, __DrawBorder);
	Gura_AssignMethod(wx_RichTextObject, __GetBoxRects);
	Gura_AssignMethod(wx_RichTextObject, __GetTotalMargin);
	Gura_AssignMethod(wx_RichTextObject, __AdjustAvailableSpace);
}

Gura_ImplementDescendantCreator(wx_RichTextObject)
{
	return new Object_wx_RichTextObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
