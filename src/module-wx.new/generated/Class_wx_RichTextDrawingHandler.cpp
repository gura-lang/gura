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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextDrawingHandler, "RichTextDrawingHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextDrawingHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextDrawingHandler)
{
	//const wxString& name = arg.GetNumber(0)
	//wxRichTextDrawingHandler(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __HasVirtualAttributes, "HasVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __HasVirtualAttributes)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasVirtualAttributes(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __GetVirtualAttributes, "GetVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __GetVirtualAttributes)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextAttr& attr = arg.GetNumber(0)
	//wxRichTextObject* obj = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetVirtualAttributes(attr, obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __GetVirtualSubobjectAttributesCount, "GetVirtualSubobjectAttributesCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __GetVirtualSubobjectAttributesCount)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetVirtualSubobjectAttributesCount(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __GetVirtualSubobjectAttributes, "GetVirtualSubobjectAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "positions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attributes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __GetVirtualSubobjectAttributes)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//wxArrayInt& positions = arg.GetNumber(1)
	//wxRichTextAttrArray& attributes = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->GetVirtualSubobjectAttributes(obj, positions, attributes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __HasVirtualText, "HasVirtualText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __HasVirtualText)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextPlainText* obj = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasVirtualText(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __GetVirtualText, "GetVirtualText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __GetVirtualText)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextPlainText* obj = arg.GetNumber(0)
	//wxString& text = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetVirtualText(obj, text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __SetName)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingHandler, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingHandler, __GetName)
{
	Object_wx_RichTextDrawingHandler *pThis = Object_wx_RichTextDrawingHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextDrawingHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextDrawingHandler);
	// Method assignment
	Gura_AssignMethod(wx_RichTextDrawingHandler, __HasVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __GetVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __GetVirtualSubobjectAttributesCount);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __GetVirtualSubobjectAttributes);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __HasVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __GetVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __SetName);
	Gura_AssignMethod(wx_RichTextDrawingHandler, __GetName);
}

Gura_ImplementDescendantCreator(wx_RichTextDrawingHandler)
{
	return new Object_wx_RichTextDrawingHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
