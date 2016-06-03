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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPlainText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextPlainText)
{
	//int text = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxRichTextPlainText();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextPlainText_1, "RichTextPlainText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextPlainText));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextPlainText_1)
{
	//int obj = arg.GetNumber(0)
	//wxRichTextPlainText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextPlainText, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextPlainText, __Draw)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetTextForRange)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __DoSplit, "DoSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __DoSplit)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DoSplit();
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
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __DeleteRange)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __IsEmpty)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __CanMerge, "CanMerge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __CanMerge)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->CanMerge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Merge, "Merge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Merge)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->Merge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __CanSplit, "CanSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __CanSplit)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->CanSplit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Split, "Split")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Split)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->Split();
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
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetFirstLineBreakPosition, "GetFirstLineBreakPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetFirstLineBreakPosition)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstLineBreakPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __UsesParagraphAttributes, "UsesParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __UsesParagraphAttributes)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __ImportFromXML)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __ExportXML)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, __ExportXML_1)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetXMLNodeName)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __GetText)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
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
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
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
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, __Clone)
{
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPlainText, __DrawTabbedString, "DrawTabbedString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int dc = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int str = arg.GetNumber(3)
	//int x = arg.GetNumber(4)
	//int y = arg.GetNumber(5)
	//int selected = arg.GetNumber(6)
	//pThis->GetEntity()->DrawTabbedString();
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
