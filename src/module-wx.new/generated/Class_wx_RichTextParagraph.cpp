//----------------------------------------------------------------------------
// wxRichTextParagraph
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraph
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraph
//----------------------------------------------------------------------------
Object_wx_RichTextParagraph::~Object_wx_RichTextParagraph()
{
}

Object *Object_wx_RichTextParagraph::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextParagraph::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraph:");
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
Gura_DeclareMethod(wx_RichTextParagraph, wxRichTextParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, wxRichTextParagraph)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, wxRichTextParagraph_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "charStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, wxRichTextParagraph_1)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int paraStyle = arg.GetNumber(2)
	//int charStyle = arg.GetNumber(3)
	//pThis->GetEntity()->wxRichTextParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, wxRichTextParagraph_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, wxRichTextParagraph_2)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, Init)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, Draw)
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

Gura_ImplementMethod(wx_RichTextParagraph, Draw)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraph, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, Layout)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetRangeSize)
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

Gura_ImplementMethod(wx_RichTextParagraph, GetRangeSize)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraph, FindPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, FindPosition)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraph, HitTest)
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

Gura_ImplementMethod(wx_RichTextParagraph, HitTest)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextParagraph, CalculateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, CalculateRange)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetXMLNodeName)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetLines)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, Copy)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, Clone)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, ClearLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, ClearLines)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, ApplyParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, ApplyParagraphStyle)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//pThis->GetEntity()->ApplyParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, InsertText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, InsertText)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->InsertText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, SplitAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previousObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, SplitAt)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int previousObject = arg.GetNumber(1)
	//pThis->GetEntity()->SplitAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, MoveToList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "list", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, MoveToList)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int list = arg.GetNumber(1)
	//pThis->GetEntity()->MoveToList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, MoveFromList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "list", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, MoveFromList)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int list = arg.GetNumber(0)
	//pThis->GetEntity()->MoveFromList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetContiguousPlainText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetContiguousPlainText)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int fromStart = arg.GetNumber(2)
	//pThis->GetEntity()->GetContiguousPlainText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, FindWrapPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableSpace", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wrapPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, FindWrapPosition)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int context = arg.GetNumber(2)
	//int availableSpace = arg.GetNumber(3)
	//int wrapPosition = arg.GetNumber(4)
	//int partialExtents = arg.GetNumber(5)
	//pThis->GetEntity()->FindWrapPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, FindObjectAtPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, FindObjectAtPosition)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->FindObjectAtPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetBulletText)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBulletText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, AllocateLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, AllocateLine)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->AllocateLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, ClearUnusedLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, ClearUnusedLines)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineCount = arg.GetNumber(0)
	//pThis->GetEntity()->ClearUnusedLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetCombinedAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contentStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "includingBoxAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetCombinedAttributes)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int contentStyle = arg.GetNumber(0)
	//int includingBoxAttr = arg.GetNumber(1)
	//pThis->GetEntity()->GetCombinedAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetCombinedAttributes_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "includingBoxAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetCombinedAttributes_1)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int includingBoxAttr = arg.GetNumber(0)
	//pThis->GetEntity()->GetCombinedAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetFirstLineBreakPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetFirstLineBreakPosition)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstLineBreakPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, InitDefaultTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, InitDefaultTabs)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitDefaultTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, ClearDefaultTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, ClearDefaultTabs)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearDefaultTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetDefaultTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetDefaultTabs)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, LayoutFloat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "floatCollector", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, LayoutFloat)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int floatCollector = arg.GetNumber(5)
	//pThis->GetEntity()->LayoutFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, GetImpactedByFloatingObjects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, GetImpactedByFloatingObjects)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImpactedByFloatingObjects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraph, SetImpactedByFloatingObjects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, SetImpactedByFloatingObjects)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->SetImpactedByFloatingObjects();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextParagraph
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraph)
{
	Gura_AssignMethod(wx_RichTextParagraph, wxRichTextParagraph);
	Gura_AssignMethod(wx_RichTextParagraph, wxRichTextParagraph_1);
	Gura_AssignMethod(wx_RichTextParagraph, wxRichTextParagraph_2);
	Gura_AssignMethod(wx_RichTextParagraph, Init);
	Gura_AssignMethod(wx_RichTextParagraph, Draw);
	Gura_AssignMethod(wx_RichTextParagraph, Layout);
	Gura_AssignMethod(wx_RichTextParagraph, GetRangeSize);
	Gura_AssignMethod(wx_RichTextParagraph, FindPosition);
	Gura_AssignMethod(wx_RichTextParagraph, HitTest);
	Gura_AssignMethod(wx_RichTextParagraph, CalculateRange);
	Gura_AssignMethod(wx_RichTextParagraph, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextParagraph, GetLines);
	Gura_AssignMethod(wx_RichTextParagraph, Copy);
	Gura_AssignMethod(wx_RichTextParagraph, Clone);
	Gura_AssignMethod(wx_RichTextParagraph, ClearLines);
	Gura_AssignMethod(wx_RichTextParagraph, ApplyParagraphStyle);
	Gura_AssignMethod(wx_RichTextParagraph, InsertText);
	Gura_AssignMethod(wx_RichTextParagraph, SplitAt);
	Gura_AssignMethod(wx_RichTextParagraph, MoveToList);
	Gura_AssignMethod(wx_RichTextParagraph, MoveFromList);
	Gura_AssignMethod(wx_RichTextParagraph, GetContiguousPlainText);
	Gura_AssignMethod(wx_RichTextParagraph, FindWrapPosition);
	Gura_AssignMethod(wx_RichTextParagraph, FindObjectAtPosition);
	Gura_AssignMethod(wx_RichTextParagraph, GetBulletText);
	Gura_AssignMethod(wx_RichTextParagraph, AllocateLine);
	Gura_AssignMethod(wx_RichTextParagraph, ClearUnusedLines);
	Gura_AssignMethod(wx_RichTextParagraph, GetCombinedAttributes);
	Gura_AssignMethod(wx_RichTextParagraph, GetCombinedAttributes_1);
	Gura_AssignMethod(wx_RichTextParagraph, GetFirstLineBreakPosition);
	Gura_AssignMethod(wx_RichTextParagraph, InitDefaultTabs);
	Gura_AssignMethod(wx_RichTextParagraph, ClearDefaultTabs);
	Gura_AssignMethod(wx_RichTextParagraph, GetDefaultTabs);
	Gura_AssignMethod(wx_RichTextParagraph, LayoutFloat);
	Gura_AssignMethod(wx_RichTextParagraph, GetImpactedByFloatingObjects);
	Gura_AssignMethod(wx_RichTextParagraph, SetImpactedByFloatingObjects);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraph)
{
	return new Object_wx_RichTextParagraph((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
