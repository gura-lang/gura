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
Gura_DeclareFunctionAlias(__wxRichTextObject, "wxRichTextObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRichTextObject)
{
	//int parent = arg.GetNumber(0)
	//wxRichTextObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextObject, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextObject, __Draw)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int selection = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __HitTest, "HitTest")
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

Gura_ImplementMethod(wx_RichTextObject, __HitTest)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextObject, __FindPosition, "FindPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//int pt = arg.GetNumber(3)
	//int height = arg.GetNumber(4)
	//int forceLineStart = arg.GetNumber(5)
	//pThis->GetEntity()->FindPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBestSize, "GetBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBestSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRangeSize, "GetRangeSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int range = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int descent = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int position = arg.GetNumber(6)
	//int parentSize = arg.GetNumber(7)
	//int partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DoSplit, "DoSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __DoSplit)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DoSplit();
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
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __DeleteRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsEmpty)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsFloatable, "IsFloatable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsFloatable)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsFloating, "IsFloating")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsFloating)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetFloatDirection, "GetFloatDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetFloatDirection)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFloatDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetTextForRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CanMerge, "CanMerge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __CanMerge)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->CanMerge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Merge, "Merge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Merge)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->Merge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CanSplit, "CanSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __CanSplit)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->CanSplit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Split, "Split")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __Split)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->Split();
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
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __CanEditProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __EditProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __AcceptsFocus)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ImportFromXML)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ExportXML)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ExportXML_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __UsesParagraphAttributes, "UsesParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __UsesParagraphAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetXMLNodeName)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
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
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __HandlesChildSelections, "HandlesChildSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __HandlesChildSelections)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HandlesChildSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetSelection)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetCachedSize, "GetCachedSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetCachedSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCachedSize();
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
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetCachedSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetMaxSize, "GetMaxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetMaxSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxSize();
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
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetMinSize, "GetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetMinSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
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
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetNaturalSize, "GetNaturalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetNaturalSize)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNaturalSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetPosition)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
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
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAbsolutePosition, "GetAbsolutePosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAbsolutePosition)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbsolutePosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRect)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
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
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRange_1, "GetRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRange_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
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
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetOwnRange, "GetOwnRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetOwnRange)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetOwnRange_1, "GetOwnRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetOwnRange_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetOwnRangeIfTopLevel, "GetOwnRangeIfTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetOwnRangeIfTopLevel)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwnRangeIfTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsComposite, "IsComposite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsComposite)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsComposite();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsAtomic, "IsAtomic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsAtomic)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetParent)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
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
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetContainer)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetParentContainer, "GetParentContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetParentContainer)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParentContainer();
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
	//pThis->GetEntity()->SetMargins();
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
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetLeftMargin, "GetLeftMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetLeftMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetRightMargin, "GetRightMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetRightMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetTopMargin, "GetTopMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetTopMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBottomMargin, "GetBottomMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBottomMargin)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAvailableContentArea, "GetAvailableContentArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outerRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAvailableContentArea)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int outerRect = arg.GetNumber(2)
	//pThis->GetEntity()->GetAvailableContentArea();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __LayoutToBestSize, "LayoutToBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int buffer = arg.GetNumber(2)
	//int parentAttr = arg.GetNumber(3)
	//int attr = arg.GetNumber(4)
	//int availableParentSpace = arg.GetNumber(5)
	//int availableContainerSpace = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//pThis->GetEntity()->LayoutToBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __AdjustAttributes, "AdjustAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __AdjustAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->AdjustAttributes();
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
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAttributes, "GetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAttributes)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetAttributes_1, "GetAttributes_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetAttributes_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetProperties, "GetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetProperties)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetProperties_1, "GetProperties_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetProperties_1)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
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
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties();
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
	//pThis->GetEntity()->SetDescent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetDescent, "GetDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetDescent)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBuffer, "GetBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetBuffer)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBuffer();
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
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __GetName)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsTopLevel, "IsTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsTopLevel)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __IsShown, "IsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __IsShown)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
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
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, __Clone)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
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
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
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
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertTenthsMMToPixels, "ConvertTenthsMMToPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ConvertTenthsMMToPixels)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->ConvertTenthsMMToPixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertTenthsMMToPixels_1, "ConvertTenthsMMToPixels_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int scale = arg.GetNumber(2)
	//pThis->GetEntity()->ConvertTenthsMMToPixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertPixelsToTenthsMM, "ConvertPixelsToTenthsMM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, __ConvertPixelsToTenthsMM)
{
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//pThis->GetEntity()->ConvertPixelsToTenthsMM();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __ConvertPixelsToTenthsMM_1, "ConvertPixelsToTenthsMM_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int scale = arg.GetNumber(2)
	//pThis->GetEntity()->ConvertPixelsToTenthsMM();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DrawBoxAttributes, "DrawBoxAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int boxRect = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//int obj = arg.GetNumber(5)
	//pThis->GetEntity()->DrawBoxAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __DrawBorder, "DrawBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int borders = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->DrawBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetBoxRects, "GetBoxRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int marginRect = arg.GetNumber(3)
	//int borderRect = arg.GetNumber(4)
	//int contentRect = arg.GetNumber(5)
	//int paddingRect = arg.GetNumber(6)
	//int outlineRect = arg.GetNumber(7)
	//pThis->GetEntity()->GetBoxRects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __GetTotalMargin, "GetTotalMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int leftMargin = arg.GetNumber(3)
	//int rightMargin = arg.GetNumber(4)
	//int topMargin = arg.GetNumber(5)
	//int bottomMargin = arg.GetNumber(6)
	//pThis->GetEntity()->GetTotalMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextObject, __AdjustAvailableSpace, "AdjustAvailableSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int parentAttr = arg.GetNumber(2)
	//int childAttr = arg.GetNumber(3)
	//int availableParentSpace = arg.GetNumber(4)
	//int availableContainerSpace = arg.GetNumber(5)
	//pThis->GetEntity()->AdjustAvailableSpace();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObject)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextObject);
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
