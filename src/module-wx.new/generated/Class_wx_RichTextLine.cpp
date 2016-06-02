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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextLine, wxRichTextLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, wxRichTextLine)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, wxRichTextLine_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, wxRichTextLine_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, SetRange)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, SetRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, SetRange_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetParent)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetRange)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetRange_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetAbsoluteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetAbsoluteRange)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbsoluteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetSize)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, SetSize)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetPosition)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, SetPosition)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetAbsolutePosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetAbsolutePosition)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAbsolutePosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetRect)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, SetDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, SetDescent)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int descent = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetDescent)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetObjectSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetObjectSizes)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObjectSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, GetObjectSizes_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, GetObjectSizes_1)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObjectSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, Init)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextLine, Copy)
{
	Object_wx_RichTextLine *pThis = Object_wx_RichTextLine::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextLine, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextLine, Clone)
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
	Gura_AssignMethod(wx_RichTextLine, wxRichTextLine);
	Gura_AssignMethod(wx_RichTextLine, wxRichTextLine_1);
	Gura_AssignMethod(wx_RichTextLine, SetRange);
	Gura_AssignMethod(wx_RichTextLine, SetRange_1);
	Gura_AssignMethod(wx_RichTextLine, GetParent);
	Gura_AssignMethod(wx_RichTextLine, GetRange);
	Gura_AssignMethod(wx_RichTextLine, GetRange_1);
	Gura_AssignMethod(wx_RichTextLine, GetAbsoluteRange);
	Gura_AssignMethod(wx_RichTextLine, GetSize);
	Gura_AssignMethod(wx_RichTextLine, SetSize);
	Gura_AssignMethod(wx_RichTextLine, GetPosition);
	Gura_AssignMethod(wx_RichTextLine, SetPosition);
	Gura_AssignMethod(wx_RichTextLine, GetAbsolutePosition);
	Gura_AssignMethod(wx_RichTextLine, GetRect);
	Gura_AssignMethod(wx_RichTextLine, SetDescent);
	Gura_AssignMethod(wx_RichTextLine, GetDescent);
	Gura_AssignMethod(wx_RichTextLine, GetObjectSizes);
	Gura_AssignMethod(wx_RichTextLine, GetObjectSizes_1);
	Gura_AssignMethod(wx_RichTextLine, Init);
	Gura_AssignMethod(wx_RichTextLine, Copy);
	Gura_AssignMethod(wx_RichTextLine, Clone);
}

Gura_ImplementDescendantCreator(wx_RichTextLine)
{
	return new Object_wx_RichTextLine((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
