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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRichTextParagraph, "wxRichTextParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraph));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextParagraph)
{
	//int parent = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//wxRichTextParagraph();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextParagraph_1, "wxRichTextParagraph_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "charStyle", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraph));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextParagraph_1)
{
	//int text = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int paraStyle = arg.GetNumber(2)
	//int charStyle = arg.GetNumber(3)
	//wxRichTextParagraph();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextParagraph_2, "wxRichTextParagraph_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraph));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextParagraph_2)
{
	//wxRichTextParagraph();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextParagraph, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __Init)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextParagraph, __Draw)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __Layout)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetRangeSize, "GetRangeSize")
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

Gura_ImplementMethod(wx_RichTextParagraph, __GetRangeSize)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __FindPosition, "FindPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __FindPosition)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __HitTest, "HitTest")
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

Gura_ImplementMethod(wx_RichTextParagraph, __HitTest)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __CalculateRange, "CalculateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __CalculateRange)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetXMLNodeName)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetLines, "GetLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetLines)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __Copy)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __Clone)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __ClearLines, "ClearLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __ClearLines)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __ApplyParagraphStyle, "ApplyParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __ApplyParagraphStyle)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __InsertText, "InsertText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __InsertText)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->InsertText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __SplitAt, "SplitAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previousObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __SplitAt)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int previousObject = arg.GetNumber(1)
	//pThis->GetEntity()->SplitAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __MoveToList, "MoveToList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "list", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __MoveToList)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int list = arg.GetNumber(1)
	//pThis->GetEntity()->MoveToList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __MoveFromList, "MoveFromList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "list", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __MoveFromList)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int list = arg.GetNumber(0)
	//pThis->GetEntity()->MoveFromList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetContiguousPlainText, "GetContiguousPlainText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetContiguousPlainText)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int fromStart = arg.GetNumber(2)
	//pThis->GetEntity()->GetContiguousPlainText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __FindWrapPosition, "FindWrapPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableSpace", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wrapPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __FindWrapPosition)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __FindObjectAtPosition, "FindObjectAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __FindObjectAtPosition)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->FindObjectAtPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetBulletText, "GetBulletText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetBulletText)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBulletText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __AllocateLine, "AllocateLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __AllocateLine)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->AllocateLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __ClearUnusedLines, "ClearUnusedLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __ClearUnusedLines)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineCount = arg.GetNumber(0)
	//pThis->GetEntity()->ClearUnusedLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetCombinedAttributes, "GetCombinedAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "contentStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "includingBoxAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetCombinedAttributes)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int contentStyle = arg.GetNumber(0)
	//int includingBoxAttr = arg.GetNumber(1)
	//pThis->GetEntity()->GetCombinedAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetCombinedAttributes_1, "GetCombinedAttributes_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "includingBoxAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetCombinedAttributes_1)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int includingBoxAttr = arg.GetNumber(0)
	//pThis->GetEntity()->GetCombinedAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetFirstLineBreakPosition, "GetFirstLineBreakPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetFirstLineBreakPosition)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstLineBreakPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __InitDefaultTabs, "InitDefaultTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __InitDefaultTabs)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitDefaultTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __ClearDefaultTabs, "ClearDefaultTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __ClearDefaultTabs)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearDefaultTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetDefaultTabs, "GetDefaultTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetDefaultTabs)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __LayoutFloat, "LayoutFloat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "floatCollector", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __LayoutFloat)
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

Gura_DeclareMethodAlias(wx_RichTextParagraph, __GetImpactedByFloatingObjects, "GetImpactedByFloatingObjects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraph, __GetImpactedByFloatingObjects)
{
	Object_wx_RichTextParagraph *pThis = Object_wx_RichTextParagraph::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImpactedByFloatingObjects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraph, __SetImpactedByFloatingObjects, "SetImpactedByFloatingObjects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraph, __SetImpactedByFloatingObjects)
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
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextParagraph);
	Gura_AssignFunction(__wxRichTextParagraph_1);
	Gura_AssignFunction(__wxRichTextParagraph_2);
	// Method assignment
	Gura_AssignMethod(wx_RichTextParagraph, __Init);
	Gura_AssignMethod(wx_RichTextParagraph, __Draw);
	Gura_AssignMethod(wx_RichTextParagraph, __Layout);
	Gura_AssignMethod(wx_RichTextParagraph, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextParagraph, __FindPosition);
	Gura_AssignMethod(wx_RichTextParagraph, __HitTest);
	Gura_AssignMethod(wx_RichTextParagraph, __CalculateRange);
	Gura_AssignMethod(wx_RichTextParagraph, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextParagraph, __GetLines);
	Gura_AssignMethod(wx_RichTextParagraph, __Copy);
	Gura_AssignMethod(wx_RichTextParagraph, __Clone);
	Gura_AssignMethod(wx_RichTextParagraph, __ClearLines);
	Gura_AssignMethod(wx_RichTextParagraph, __ApplyParagraphStyle);
	Gura_AssignMethod(wx_RichTextParagraph, __InsertText);
	Gura_AssignMethod(wx_RichTextParagraph, __SplitAt);
	Gura_AssignMethod(wx_RichTextParagraph, __MoveToList);
	Gura_AssignMethod(wx_RichTextParagraph, __MoveFromList);
	Gura_AssignMethod(wx_RichTextParagraph, __GetContiguousPlainText);
	Gura_AssignMethod(wx_RichTextParagraph, __FindWrapPosition);
	Gura_AssignMethod(wx_RichTextParagraph, __FindObjectAtPosition);
	Gura_AssignMethod(wx_RichTextParagraph, __GetBulletText);
	Gura_AssignMethod(wx_RichTextParagraph, __AllocateLine);
	Gura_AssignMethod(wx_RichTextParagraph, __ClearUnusedLines);
	Gura_AssignMethod(wx_RichTextParagraph, __GetCombinedAttributes);
	Gura_AssignMethod(wx_RichTextParagraph, __GetCombinedAttributes_1);
	Gura_AssignMethod(wx_RichTextParagraph, __GetFirstLineBreakPosition);
	Gura_AssignMethod(wx_RichTextParagraph, __InitDefaultTabs);
	Gura_AssignMethod(wx_RichTextParagraph, __ClearDefaultTabs);
	Gura_AssignMethod(wx_RichTextParagraph, __GetDefaultTabs);
	Gura_AssignMethod(wx_RichTextParagraph, __LayoutFloat);
	Gura_AssignMethod(wx_RichTextParagraph, __GetImpactedByFloatingObjects);
	Gura_AssignMethod(wx_RichTextParagraph, __SetImpactedByFloatingObjects);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraph)
{
	return new Object_wx_RichTextParagraph((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
