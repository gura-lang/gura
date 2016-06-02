//----------------------------------------------------------------------------
// wxRichTextDrawingHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextDrawingHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
Object_wx_RichTextDrawingHandler::~Object_wx_RichTextDrawingHandler()
{
}

Object *Object_wx_RichTextDrawingHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextDrawingHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextDrawingHandler:");
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
Gura_DeclareMethod(wx_RichTextDrawingHandler, wxRichTextDrawingHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, wxRichTextDrawingHandler)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextDrawingHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, HasVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, HasVirtualAttributes)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->HasVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, GetVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, GetVirtualAttributes)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->GetVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, GetVirtualSubobjectAttributesCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, GetVirtualSubobjectAttributesCount)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetVirtualSubobjectAttributesCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, GetVirtualSubobjectAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "positions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attributes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, GetVirtualSubobjectAttributes)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int positions = arg.GetNumber(1)
	//int attributes = arg.GetNumber(2)
	//pThis->GetEntity()->GetVirtualSubobjectAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, HasVirtualText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, HasVirtualText)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->HasVirtualText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, GetVirtualText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, GetVirtualText)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->GetVirtualText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, SetName)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, GetName)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextDrawingHandler)
{
	Gura_AssignMethod(wx_RichTextDrawingHandler, wxRichTextDrawingHandler);
	Gura_AssignMethod(wx_RichTextDrawingHandler, HasVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingHandler, GetVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingHandler, GetVirtualSubobjectAttributesCount);
	Gura_AssignMethod(wx_RichTextDrawingHandler, GetVirtualSubobjectAttributes);
	Gura_AssignMethod(wx_RichTextDrawingHandler, HasVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingHandler, GetVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingHandler, SetName);
	Gura_AssignMethod(wx_RichTextDrawingHandler, GetName);
}

Gura_ImplementDescendantCreator(wx_RichTextDrawingHandler)
{
	return new Object_wx_RichTextDrawingHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
