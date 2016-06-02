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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextDrawingContext, wxRichTextDrawingContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, wxRichTextDrawingContext)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextDrawingContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, Init)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, HasVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, HasVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->HasVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, ApplyVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, ApplyVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->ApplyVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetVirtualSubobjectAttributesCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetVirtualSubobjectAttributesCount)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetVirtualSubobjectAttributesCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetVirtualSubobjectAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "positions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attributes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetVirtualSubobjectAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int positions = arg.GetNumber(1)
	//int attributes = arg.GetNumber(2)
	//pThis->GetEntity()->GetVirtualSubobjectAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, HasVirtualText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, HasVirtualText)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->HasVirtualText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetVirtualText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetVirtualText)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->GetVirtualText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, EnableVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, EnableVirtualAttributes)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetVirtualAttributesEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetVirtualAttributesEnabled)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVirtualAttributesEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, EnableImages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, EnableImages)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableImages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetImagesEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetImagesEnabled)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImagesEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, SetLayingOut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, SetLayingOut)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayingOut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetLayingOut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetLayingOut)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayingOut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, EnableDelayedImageLoading)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, EnableDelayedImageLoading)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextDrawingContext, GetDelayedImageLoading)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextDrawingContext, GetDelayedImageLoading)
{
	Object_wx_RichTextDrawingContext *pThis = Object_wx_RichTextDrawingContext::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageLoading();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextDrawingContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextDrawingContext)
{
	Gura_AssignMethod(wx_RichTextDrawingContext, wxRichTextDrawingContext);
	Gura_AssignMethod(wx_RichTextDrawingContext, Init);
	Gura_AssignMethod(wx_RichTextDrawingContext, HasVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, ApplyVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetVirtualSubobjectAttributesCount);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetVirtualSubobjectAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, HasVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetVirtualText);
	Gura_AssignMethod(wx_RichTextDrawingContext, EnableVirtualAttributes);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetVirtualAttributesEnabled);
	Gura_AssignMethod(wx_RichTextDrawingContext, EnableImages);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetImagesEnabled);
	Gura_AssignMethod(wx_RichTextDrawingContext, SetLayingOut);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetLayingOut);
	Gura_AssignMethod(wx_RichTextDrawingContext, EnableDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextDrawingContext, GetDelayedImageLoading);
}

Gura_ImplementDescendantCreator(wx_RichTextDrawingContext)
{
	return new Object_wx_RichTextDrawingContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
