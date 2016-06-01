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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextPlainText, wxRichTextPlainText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, wxRichTextPlainText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextPlainText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, wxRichTextPlainText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, wxRichTextPlainText_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextPlainText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, Draw)
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

Gura_ImplementMethod(wx_RichTextPlainText, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextPlainText, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, GetRangeSize)
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

Gura_ImplementMethod(wx_RichTextPlainText, GetRangeSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextPlainText, GetTextForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, GetTextForRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, DoSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, DoSplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DoSplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, CalculateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, CalculateRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, DeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, DeleteRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, CanMerge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, CanMerge)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->CanMerge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, Merge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, Merge)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//pThis->GetEntity()->Merge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, CanSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, CanSplit)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->CanSplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, Split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, Split)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->Split();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, Dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, Dump)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->Dump();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, GetFirstLineBreakPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, GetFirstLineBreakPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstLineBreakPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, UsesParagraphAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, UsesParagraphAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UsesParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, ImportFromXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, ImportFromXML)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, ExportXML)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, ExportXML_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, ExportXML_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, GetXMLNodeName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPlainText, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPlainText, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPlainText, DrawTabbedString)
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

Gura_ImplementMethod(wx_RichTextPlainText, DrawTabbedString)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPlainText *pThis = Object_wx_RichTextPlainText::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextPlainText, wxRichTextPlainText);
	Gura_AssignMethod(wx_RichTextPlainText, wxRichTextPlainText_1);
	Gura_AssignMethod(wx_RichTextPlainText, Draw);
	Gura_AssignMethod(wx_RichTextPlainText, Layout);
	Gura_AssignMethod(wx_RichTextPlainText, GetRangeSize);
	Gura_AssignMethod(wx_RichTextPlainText, GetTextForRange);
	Gura_AssignMethod(wx_RichTextPlainText, DoSplit);
	Gura_AssignMethod(wx_RichTextPlainText, CalculateRange);
	Gura_AssignMethod(wx_RichTextPlainText, DeleteRange);
	Gura_AssignMethod(wx_RichTextPlainText, IsEmpty);
	Gura_AssignMethod(wx_RichTextPlainText, CanMerge);
	Gura_AssignMethod(wx_RichTextPlainText, Merge);
	Gura_AssignMethod(wx_RichTextPlainText, CanSplit);
	Gura_AssignMethod(wx_RichTextPlainText, Split);
	Gura_AssignMethod(wx_RichTextPlainText, Dump);
	Gura_AssignMethod(wx_RichTextPlainText, GetFirstLineBreakPosition);
	Gura_AssignMethod(wx_RichTextPlainText, UsesParagraphAttributes);
	Gura_AssignMethod(wx_RichTextPlainText, ImportFromXML);
	Gura_AssignMethod(wx_RichTextPlainText, ExportXML);
	Gura_AssignMethod(wx_RichTextPlainText, ExportXML_1);
	Gura_AssignMethod(wx_RichTextPlainText, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextPlainText, GetText);
	Gura_AssignMethod(wx_RichTextPlainText, SetText);
	Gura_AssignMethod(wx_RichTextPlainText, Copy);
	Gura_AssignMethod(wx_RichTextPlainText, Clone);
	Gura_AssignMethod(wx_RichTextPlainText, DrawTabbedString);
}

Gura_ImplementDescendantCreator(wx_RichTextPlainText)
{
	return new Object_wx_RichTextPlainText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
