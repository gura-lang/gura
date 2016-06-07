//----------------------------------------------------------------------------
// wxRichTextLine
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextLine
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextLine
//----------------------------------------------------------------------------
Object_wx_RichTextLine::~Object_wx_RichTextLine()
{
}

Object *Object_wx_RichTextLine::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextLine::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextLine:");
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
Gura_DeclareFunctionAlias(__RichTextLine, "RichTextLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextLine));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextLine)
{
	//wxRichTextParagraph* parent = arg.GetNumber(0)
	//wxRichTextLine(parent);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextLine_1, "RichTextLine_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextLine));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextLine_1)
{
	//const wxRichTextLine& obj = arg.GetNumber(0)
	//wxRichTextLine(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextLine, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __SetRange)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __SetRange_1, "SetRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __SetRange_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange(from, to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetParent)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetRange)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetRange_1, "GetRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetRange_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetAbsoluteRange, "GetAbsoluteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetAbsoluteRange)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbsoluteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetSize)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __SetSize)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetPosition)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __SetPosition)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetAbsolutePosition, "GetAbsolutePosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetAbsolutePosition)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbsolutePosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetRect)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __SetDescent, "SetDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __SetDescent)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int descent = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescent(descent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetDescent, "GetDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetDescent)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetObjectSizes, "GetObjectSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetObjectSizes)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObjectSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __GetObjectSizes_1, "GetObjectSizes_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __GetObjectSizes_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObjectSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __Init)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* parent = arg.GetNumber(0)
	//pThis->GetEntity()->Init(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, __Copy)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextLine& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextLine, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, __Clone)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextLine
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextLine)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextLine);
	Gura_AssignFunction(__RichTextLine_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextLine, __SetRange);
	Gura_AssignMethod(wx_RichTextLine, __SetRange_1);
	Gura_AssignMethod(wx_RichTextLine, __GetParent);
	Gura_AssignMethod(wx_RichTextLine, __GetRange);
	Gura_AssignMethod(wx_RichTextLine, __GetRange_1);
	Gura_AssignMethod(wx_RichTextLine, __GetAbsoluteRange);
	Gura_AssignMethod(wx_RichTextLine, __GetSize);
	Gura_AssignMethod(wx_RichTextLine, __SetSize);
	Gura_AssignMethod(wx_RichTextLine, __GetPosition);
	Gura_AssignMethod(wx_RichTextLine, __SetPosition);
	Gura_AssignMethod(wx_RichTextLine, __GetAbsolutePosition);
	Gura_AssignMethod(wx_RichTextLine, __GetRect);
	Gura_AssignMethod(wx_RichTextLine, __SetDescent);
	Gura_AssignMethod(wx_RichTextLine, __GetDescent);
	Gura_AssignMethod(wx_RichTextLine, __GetObjectSizes);
	Gura_AssignMethod(wx_RichTextLine, __GetObjectSizes_1);
	Gura_AssignMethod(wx_RichTextLine, __Init);
	Gura_AssignMethod(wx_RichTextLine, __Copy);
	Gura_AssignMethod(wx_RichTextLine, __Clone);
}

Gura_ImplementDescendantCreator(wx_RichTextLine)
{
	return new Object_wx_RichTextLine((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
