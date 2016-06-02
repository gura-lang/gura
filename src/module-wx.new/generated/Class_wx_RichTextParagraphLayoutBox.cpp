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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, wxRichTextParagraphLayoutBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, wxRichTextParagraphLayoutBox)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextParagraphLayoutBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, wxRichTextParagraphLayoutBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, wxRichTextParagraphLayoutBox_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextParagraphLayoutBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, HitTest)
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

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, HitTest)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Draw)
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

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Draw)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Layout)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetRangeSize)
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

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetRangeSize)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, DeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, DeleteRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetTextForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetTextForRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, ImportFromXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, ImportFromXML)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, ExportXML)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, ExportXML_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, ExportXML_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetXMLNodeName)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, AcceptsFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, AcceptsFocus)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetRichTextCtrl)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetRichTextCtrl)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetPartialParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "partialPara", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetPartialParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int partialPara = arg.GetNumber(0)
	//pThis->GetEntity()->SetPartialParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetPartialParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetPartialParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPartialParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetStyleSheet)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, IsTopLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, IsTopLevel)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertParagraphsWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paragraphs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertParagraphsWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int paragraphs = arg.GetNumber(2)
	//int ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->InsertParagraphsWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertTextWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertTextWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->InsertTextWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertNewlineWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertNewlineWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->InsertNewlineWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertImageWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertImageWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int imageBlock = arg.GetNumber(2)
	//int ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//int textAttr = arg.GetNumber(5)
	//pThis->GetEntity()->InsertImageWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertFieldWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertFieldWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int fieldType = arg.GetNumber(2)
	//int properties = arg.GetNumber(3)
	//int ctrl = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int textAttr = arg.GetNumber(6)
	//pThis->GetEntity()->InsertFieldWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetStyleForNewParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lookUpNewParaStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetStyleForNewParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int caretPosition = arg.GetNumber(2)
	//int lookUpNewParaStyle = arg.GetNumber(3)
	//pThis->GetEntity()->GetStyleForNewParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertObjectWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertObjectWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int object = arg.GetNumber(2)
	//int ctrl = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->InsertObjectWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, DeleteRangeWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, DeleteRangeWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int ctrl = arg.GetNumber(1)
	//int buffer = arg.GetNumber(2)
	//pThis->GetEntity()->DeleteRangeWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, DrawFloats)
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

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, DrawFloats)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int selection = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->DrawFloats();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, MoveAnchoredObjectToParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, MoveAnchoredObjectToParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//pThis->GetEntity()->MoveAnchoredObjectToParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Init)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Clear)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Reset)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, AddParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, AddParagraph)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int paraStyle = arg.GetNumber(1)
	//pThis->GetEntity()->AddParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, AddImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, AddImage)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int paraStyle = arg.GetNumber(1)
	//pThis->GetEntity()->AddImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, AddParagraphs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, AddParagraphs)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int paraStyle = arg.GetNumber(1)
	//pThis->GetEntity()->AddParagraphs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetLineAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetLineAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int caretPosition = arg.GetNumber(1)
	//pThis->GetEntity()->GetLineAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetLineAtYPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetLineAtYPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineAtYPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetParagraphAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetParagraphAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int caretPosition = arg.GetNumber(1)
	//pThis->GetEntity()->GetParagraphAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetLineSizeAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetLineSizeAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int caretPosition = arg.GetNumber(1)
	//pThis->GetEntity()->GetLineSizeAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetVisibleLineNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startOfLine", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetVisibleLineNumber)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int caretPosition = arg.GetNumber(1)
	//int startOfLine = arg.GetNumber(2)
	//pThis->GetEntity()->GetVisibleLineNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetLineForVisibleLineNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetLineForVisibleLineNumber)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineForVisibleLineNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetLeafObjectAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetLeafObjectAtPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->GetLeafObjectAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetParagraphAtLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetParagraphAtLine)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraphNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetParagraphAtLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetParagraphForLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetParagraphForLine)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetParagraphForLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetParagraphLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetParagraphLength)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraphNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetParagraphLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetParagraphCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetParagraphCount)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParagraphCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetLineCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetLineCount)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetParagraphText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetParagraphText)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraphNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetParagraphText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, XYToPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, XYToPosition)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, PositionToXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, PositionToXY)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetStyle_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int textAttr = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetUncombinedStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetUncombinedStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetUncombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, DoGetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "combineStyles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, DoGetStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int combineStyles = arg.GetNumber(2)
	//pThis->GetEntity()->DoGetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetStyleForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetStyleForRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, CollectStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "currentStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, CollectStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int currentStyle = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int clashingAttr = arg.GetNumber(2)
	//int absentAttr = arg.GetNumber(3)
	//pThis->GetEntity()->CollectStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetListStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int def = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->SetListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetListStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetListStyle_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int defName = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->SetListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, ClearListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, ClearListStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ClearListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, NumberList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, NumberList)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int def = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->NumberList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, NumberList_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, NumberList_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int defName = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->NumberList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, PromoteList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, PromoteList)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int promoteBy = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int def = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->PromoteList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, PromoteList_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, PromoteList_1)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int promoteBy = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int defName = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->PromoteList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, DoNumberList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "promotionRange", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, DoNumberList)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int promotionRange = arg.GetNumber(1)
	//int promoteBy = arg.GetNumber(2)
	//int def = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//int startFrom = arg.GetNumber(5)
	//int specifiedLevel = arg.GetNumber(6)
	//pThis->GetEntity()->DoNumberList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, FindNextParagraphNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "previousParagraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, FindNextParagraphNumber)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int previousParagraph = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//pThis->GetEntity()->FindNextParagraphNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetProperties)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int properties = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetObjectPropertiesWithUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "objToSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetObjectPropertiesWithUndo)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int properties = arg.GetNumber(1)
	//int objToSet = arg.GetNumber(2)
	//pThis->GetEntity()->SetObjectPropertiesWithUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, HasCharacterAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, HasCharacterAttributes)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->HasCharacterAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, HasParagraphAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, HasParagraphAttributes)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->HasParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Clone)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, PrepareContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, PrepareContent)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->PrepareContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InsertFragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fragment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InsertFragment)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int fragment = arg.GetNumber(1)
	//pThis->GetEntity()->InsertFragment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, CopyFragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fragment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, CopyFragment)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int fragment = arg.GetNumber(1)
	//pThis->GetEntity()->CopyFragment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, ApplyStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, ApplyStyleSheet)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Copy)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, operator=)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, UpdateRanges)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, UpdateRanges)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateRanges();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetText)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetDefaultStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetDefaultStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, SetBasicStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, SetBasicStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetBasicStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetBasicStyle)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, Invalidate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, Invalidate)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, DoInvalidate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, DoInvalidate)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->DoInvalidate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, InvalidateHierarchy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "invalidRange", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, InvalidateHierarchy)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int invalidRange = arg.GetNumber(0)
	//pThis->GetEntity()->InvalidateHierarchy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, UpdateFloatingObjects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "availableRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "untilObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, UpdateFloatingObjects)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int availableRect = arg.GetNumber(0)
	//int untilObj = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateFloatingObjects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetInvalidRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wholeParagraphs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetInvalidRange)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wholeParagraphs = arg.GetNumber(0)
	//pThis->GetEntity()->GetInvalidRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, IsDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, IsDirty)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetFloatCollector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetFloatCollector)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFloatCollector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetFloatingObjectCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetFloatingObjectCount)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFloatingObjectCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphLayoutBox, GetFloatingObjects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "objects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphLayoutBox, GetFloatingObjects)
{
	Object_wx_RichTextParagraphLayoutBox *pThis = Object_wx_RichTextParagraphLayoutBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int objects = arg.GetNumber(0)
	//pThis->GetEntity()->GetFloatingObjects();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphLayoutBox)
{
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, wxRichTextParagraphLayoutBox);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, wxRichTextParagraphLayoutBox_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, HitTest);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Draw);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Layout);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetRangeSize);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, DeleteRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetTextForRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, ImportFromXML);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, ExportXML);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, ExportXML_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, AcceptsFocus);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetPartialParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetPartialParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, IsTopLevel);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertParagraphsWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertTextWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertNewlineWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertImageWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertFieldWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetStyleForNewParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertObjectWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, DeleteRangeWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, DrawFloats);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, MoveAnchoredObjectToParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Init);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Clear);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Reset);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, AddParagraph);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, AddImage);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, AddParagraphs);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetLineAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetLineAtYPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetParagraphAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetLineSizeAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetVisibleLineNumber);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetLineForVisibleLineNumber);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetLeafObjectAtPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetParagraphAtLine);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetParagraphForLine);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetParagraphLength);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetParagraphCount);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetLineCount);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetParagraphText);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, XYToPosition);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, PositionToXY);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetStyle_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetUncombinedStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, DoGetStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetStyleForRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, CollectStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetListStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetListStyle_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, ClearListStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, NumberList);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, NumberList_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, PromoteList);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, PromoteList_1);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, DoNumberList);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, FindNextParagraphNumber);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetProperties);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetObjectPropertiesWithUndo);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, HasCharacterAttributes);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, HasParagraphAttributes);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Clone);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, PrepareContent);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InsertFragment);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, CopyFragment);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, ApplyStyleSheet);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Copy);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, operator=);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, UpdateRanges);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetText);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetDefaultStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetDefaultStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, SetBasicStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetBasicStyle);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, Invalidate);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, DoInvalidate);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, InvalidateHierarchy);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, UpdateFloatingObjects);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetInvalidRange);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, IsDirty);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetFloatCollector);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetFloatingObjectCount);
	Gura_AssignMethod(wx_RichTextParagraphLayoutBox, GetFloatingObjects);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphLayoutBox)
{
	return new Object_wx_RichTextParagraphLayoutBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
