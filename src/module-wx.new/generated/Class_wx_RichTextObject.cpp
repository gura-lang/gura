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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextObject, wxRichTextObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, wxRichTextObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ~wxRichTextObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, ~wxRichTextObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Draw)
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

Gura_ImplementMethod(wx_RichTextObject, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextObject, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, HitTest)
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

Gura_ImplementMethod(wx_RichTextObject, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextObject, FindPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, FindPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//int pt = arg.GetNumber(3)
	//int height = arg.GetNumber(4)
	//int forceLineStart = arg.GetNumber(5)
	//pThis->GetEntity()->FindPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetRangeSize)
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

Gura_ImplementMethod(wx_RichTextObject, GetRangeSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextObject, DoSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, DoSplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DoSplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, CalculateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, CalculateRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, DeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, DeleteRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsFloatable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsFloatable)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsFloating)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsFloating)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetFloatDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetFloatDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFloatDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetTextForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, GetTextForRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, CanMerge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, CanMerge)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->CanMerge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Merge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Merge)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->Merge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, CanSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, CanSplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->CanSplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Split)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->Split();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Dump)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, CanEditProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, EditProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetPropertiesMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, AcceptsFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, AcceptsFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ImportFromXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ImportFromXML)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ExportXML)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ExportXML_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ExportXML_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, UsesParagraphAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, UsesParagraphAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetXMLNodeName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Invalidate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Invalidate)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, HandlesChildSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, HandlesChildSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HandlesChildSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetCachedSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetCachedSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCachedSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetCachedSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetCachedSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetCachedSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetMaxSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetMaxSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetNaturalSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetNaturalSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNaturalSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetAbsolutePosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetAbsolutePosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAbsolutePosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetRange_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetOwnRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetOwnRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetOwnRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetOwnRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetOwnRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetOwnRange_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOwnRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetOwnRangeIfTopLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetOwnRangeIfTopLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOwnRangeIfTopLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsComposite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsComposite)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsComposite();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsAtomic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsAtomic)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetParentContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetParentContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParentContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "leftMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rightMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomMargin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetMargins_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int leftMargin = arg.GetNumber(0)
	//int rightMargin = arg.GetNumber(1)
	//int topMargin = arg.GetNumber(2)
	//int bottomMargin = arg.GetNumber(3)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetLeftMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetLeftMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetRightMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetRightMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetTopMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetTopMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetBottomMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetBottomMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetAvailableContentArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outerRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, GetAvailableContentArea)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int outerRect = arg.GetNumber(2)
	//pThis->GetEntity()->GetAvailableContentArea();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, LayoutToBestSize)
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

Gura_ImplementMethod(wx_RichTextObject, LayoutToBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextObject, AdjustAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, AdjustAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->AdjustAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetAttributes_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetAttributes_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetProperties_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetProperties_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetDescent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int descent = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetDescent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsTopLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsTopLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Reference)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, Reference)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reference();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Dereference)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextObject, Dereference)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dereference();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, Move)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->Move();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ConvertTenthsMMToPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ConvertTenthsMMToPixels)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->ConvertTenthsMMToPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ConvertTenthsMMToPixels_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ppi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ConvertTenthsMMToPixels_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ppi = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//int scale = arg.GetNumber(2)
	//pThis->GetEntity()->ConvertTenthsMMToPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ConvertPixelsToTenthsMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ConvertPixelsToTenthsMM)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//pThis->GetEntity()->ConvertPixelsToTenthsMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, ConvertPixelsToTenthsMM_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ppi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, ConvertPixelsToTenthsMM_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ppi = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//int scale = arg.GetNumber(2)
	//pThis->GetEntity()->ConvertPixelsToTenthsMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, DrawBoxAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "boxRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, DrawBoxAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int boxRect = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//int obj = arg.GetNumber(5)
	//pThis->GetEntity()->DrawBoxAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, DrawBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "borders", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, DrawBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//int borders = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->DrawBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextObject, GetBoxRects)
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

Gura_ImplementMethod(wx_RichTextObject, GetBoxRects)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextObject, GetTotalMargin)
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

Gura_ImplementMethod(wx_RichTextObject, GetTotalMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_RichTextObject, AdjustAvailableSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableParentSpace", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableContainerSpace", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextObject, AdjustAvailableSpace)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextObject *pThis = Object_wx_RichTextObject::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextObject, wxRichTextObject);
	Gura_AssignMethod(wx_RichTextObject, ~wxRichTextObject);
	Gura_AssignMethod(wx_RichTextObject, Draw);
	Gura_AssignMethod(wx_RichTextObject, Layout);
	Gura_AssignMethod(wx_RichTextObject, HitTest);
	Gura_AssignMethod(wx_RichTextObject, FindPosition);
	Gura_AssignMethod(wx_RichTextObject, GetBestSize);
	Gura_AssignMethod(wx_RichTextObject, GetRangeSize);
	Gura_AssignMethod(wx_RichTextObject, DoSplit);
	Gura_AssignMethod(wx_RichTextObject, CalculateRange);
	Gura_AssignMethod(wx_RichTextObject, DeleteRange);
	Gura_AssignMethod(wx_RichTextObject, IsEmpty);
	Gura_AssignMethod(wx_RichTextObject, IsFloatable);
	Gura_AssignMethod(wx_RichTextObject, IsFloating);
	Gura_AssignMethod(wx_RichTextObject, GetFloatDirection);
	Gura_AssignMethod(wx_RichTextObject, GetTextForRange);
	Gura_AssignMethod(wx_RichTextObject, CanMerge);
	Gura_AssignMethod(wx_RichTextObject, Merge);
	Gura_AssignMethod(wx_RichTextObject, CanSplit);
	Gura_AssignMethod(wx_RichTextObject, Split);
	Gura_AssignMethod(wx_RichTextObject, Dump);
	Gura_AssignMethod(wx_RichTextObject, CanEditProperties);
	Gura_AssignMethod(wx_RichTextObject, EditProperties);
	Gura_AssignMethod(wx_RichTextObject, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextObject, AcceptsFocus);
	Gura_AssignMethod(wx_RichTextObject, ImportFromXML);
	Gura_AssignMethod(wx_RichTextObject, ExportXML);
	Gura_AssignMethod(wx_RichTextObject, ExportXML_1);
	Gura_AssignMethod(wx_RichTextObject, UsesParagraphAttributes);
	Gura_AssignMethod(wx_RichTextObject, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextObject, Invalidate);
	Gura_AssignMethod(wx_RichTextObject, HandlesChildSelections);
	Gura_AssignMethod(wx_RichTextObject, GetSelection);
	Gura_AssignMethod(wx_RichTextObject, GetCachedSize);
	Gura_AssignMethod(wx_RichTextObject, SetCachedSize);
	Gura_AssignMethod(wx_RichTextObject, GetMaxSize);
	Gura_AssignMethod(wx_RichTextObject, SetMaxSize);
	Gura_AssignMethod(wx_RichTextObject, GetMinSize);
	Gura_AssignMethod(wx_RichTextObject, SetMinSize);
	Gura_AssignMethod(wx_RichTextObject, GetNaturalSize);
	Gura_AssignMethod(wx_RichTextObject, GetPosition);
	Gura_AssignMethod(wx_RichTextObject, SetPosition);
	Gura_AssignMethod(wx_RichTextObject, GetAbsolutePosition);
	Gura_AssignMethod(wx_RichTextObject, GetRect);
	Gura_AssignMethod(wx_RichTextObject, SetRange);
	Gura_AssignMethod(wx_RichTextObject, GetRange);
	Gura_AssignMethod(wx_RichTextObject, GetRange_1);
	Gura_AssignMethod(wx_RichTextObject, SetOwnRange);
	Gura_AssignMethod(wx_RichTextObject, GetOwnRange);
	Gura_AssignMethod(wx_RichTextObject, GetOwnRange_1);
	Gura_AssignMethod(wx_RichTextObject, GetOwnRangeIfTopLevel);
	Gura_AssignMethod(wx_RichTextObject, IsComposite);
	Gura_AssignMethod(wx_RichTextObject, IsAtomic);
	Gura_AssignMethod(wx_RichTextObject, GetParent);
	Gura_AssignMethod(wx_RichTextObject, SetParent);
	Gura_AssignMethod(wx_RichTextObject, GetContainer);
	Gura_AssignMethod(wx_RichTextObject, GetParentContainer);
	Gura_AssignMethod(wx_RichTextObject, SetMargins);
	Gura_AssignMethod(wx_RichTextObject, SetMargins_1);
	Gura_AssignMethod(wx_RichTextObject, GetLeftMargin);
	Gura_AssignMethod(wx_RichTextObject, GetRightMargin);
	Gura_AssignMethod(wx_RichTextObject, GetTopMargin);
	Gura_AssignMethod(wx_RichTextObject, GetBottomMargin);
	Gura_AssignMethod(wx_RichTextObject, GetAvailableContentArea);
	Gura_AssignMethod(wx_RichTextObject, LayoutToBestSize);
	Gura_AssignMethod(wx_RichTextObject, AdjustAttributes);
	Gura_AssignMethod(wx_RichTextObject, SetAttributes);
	Gura_AssignMethod(wx_RichTextObject, GetAttributes);
	Gura_AssignMethod(wx_RichTextObject, GetAttributes_1);
	Gura_AssignMethod(wx_RichTextObject, GetProperties);
	Gura_AssignMethod(wx_RichTextObject, GetProperties_1);
	Gura_AssignMethod(wx_RichTextObject, SetProperties);
	Gura_AssignMethod(wx_RichTextObject, SetDescent);
	Gura_AssignMethod(wx_RichTextObject, GetDescent);
	Gura_AssignMethod(wx_RichTextObject, GetBuffer);
	Gura_AssignMethod(wx_RichTextObject, SetName);
	Gura_AssignMethod(wx_RichTextObject, GetName);
	Gura_AssignMethod(wx_RichTextObject, IsTopLevel);
	Gura_AssignMethod(wx_RichTextObject, IsShown);
	Gura_AssignMethod(wx_RichTextObject, Show);
	Gura_AssignMethod(wx_RichTextObject, Clone);
	Gura_AssignMethod(wx_RichTextObject, Copy);
	Gura_AssignMethod(wx_RichTextObject, Reference);
	Gura_AssignMethod(wx_RichTextObject, Dereference);
	Gura_AssignMethod(wx_RichTextObject, Move);
	Gura_AssignMethod(wx_RichTextObject, ConvertTenthsMMToPixels);
	Gura_AssignMethod(wx_RichTextObject, ConvertTenthsMMToPixels_1);
	Gura_AssignMethod(wx_RichTextObject, ConvertPixelsToTenthsMM);
	Gura_AssignMethod(wx_RichTextObject, ConvertPixelsToTenthsMM_1);
	Gura_AssignMethod(wx_RichTextObject, DrawBoxAttributes);
	Gura_AssignMethod(wx_RichTextObject, DrawBorder);
	Gura_AssignMethod(wx_RichTextObject, GetBoxRects);
	Gura_AssignMethod(wx_RichTextObject, GetTotalMargin);
	Gura_AssignMethod(wx_RichTextObject, AdjustAvailableSpace);
}

Gura_ImplementDescendantCreator(wx_RichTextObject)
{
	return new Object_wx_RichTextObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
