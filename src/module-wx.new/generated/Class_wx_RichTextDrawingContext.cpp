//----------------------------------------------------------------------------
// wxRichTextDrawingContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextDrawingContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextDrawingContext
//----------------------------------------------------------------------------
Object_wx_RichTextDrawingContext::~Object_wx_RichTextDrawingContext()
{
}

Object *Object_wx_RichTextDrawingContext::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextDrawingContext::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextDrawingContext:");
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
Gura_DeclareFunctionAlias(__RichTextDrawingContext, "RichTextDrawingContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextDrawingContext));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextDrawingContext)
{
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxRichTextDrawingContext(buffer);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __Init)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __HasVirtualAttributes, "HasVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __HasVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasVirtualAttributes(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetVirtualAttributes, "GetVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//wxRichTextAttr _rtn = pThis->GetEntity()->GetVirtualAttributes(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __ApplyVirtualAttributes, "ApplyVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __ApplyVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextAttr& attr = arg.GetNumber(0)
	//wxRichTextObject* obj = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->ApplyVirtualAttributes(attr, obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetVirtualSubobjectAttributesCount, "GetVirtualSubobjectAttributesCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetVirtualSubobjectAttributesCount)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetVirtualSubobjectAttributesCount(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetVirtualSubobjectAttributes, "GetVirtualSubobjectAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "positions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attributes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetVirtualSubobjectAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//wxArrayInt& positions = arg.GetNumber(1)
	//wxRichTextAttrArray& attributes = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->GetVirtualSubobjectAttributes(obj, positions, attributes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __HasVirtualText, "HasVirtualText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __HasVirtualText)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextPlainText* obj = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasVirtualText(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetVirtualText, "GetVirtualText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetVirtualText)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextPlainText* obj = arg.GetNumber(0)
	//wxString& text = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetVirtualText(obj, text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __EnableVirtualAttributes, "EnableVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __EnableVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableVirtualAttributes(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetVirtualAttributesEnabled, "GetVirtualAttributesEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetVirtualAttributesEnabled)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetVirtualAttributesEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __EnableImages, "EnableImages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __EnableImages)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableImages(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetImagesEnabled, "GetImagesEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetImagesEnabled)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetImagesEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __SetLayingOut, "SetLayingOut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __SetLayingOut)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayingOut(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetLayingOut, "GetLayingOut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetLayingOut)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetLayingOut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __EnableDelayedImageLoading, "EnableDelayedImageLoading")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __EnableDelayedImageLoading)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDelayedImageLoading(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextDrawingContext, __GetDelayedImageLoading, "GetDelayedImageLoading")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, __GetDelayedImageLoading)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetDelayedImageLoading();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextDrawingContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextDrawingContext)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextDrawingContext);
	// Method assignment
	Gura_AssignMethod(wx_RichTextDrawingContext, __Init);
	Gura_AssignMethod(wx_RichTextDrawingContext, __HasVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, __ApplyVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetVirtualSubobjectAttributesCount);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetVirtualSubobjectAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, __HasVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingContext, __EnableVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetVirtualAttributesEnabled);
	Gura_AssignMethod(wx_RichTextDrawingContext, __EnableImages);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetImagesEnabled);
	Gura_AssignMethod(wx_RichTextDrawingContext, __SetLayingOut);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetLayingOut);
	Gura_AssignMethod(wx_RichTextDrawingContext, __EnableDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextDrawingContext, __GetDelayedImageLoading);
}

Gura_ImplementDescendantCreator(wx_RichTextDrawingContext)
{
	return new Object_wx_RichTextDrawingContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
