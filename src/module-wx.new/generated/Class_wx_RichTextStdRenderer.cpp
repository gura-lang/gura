//----------------------------------------------------------------------------
// wxRichTextStdRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStdRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStdRenderer
//----------------------------------------------------------------------------
Object_wx_RichTextStdRenderer::~Object_wx_RichTextStdRenderer()
{
}

Object *Object_wx_RichTextStdRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStdRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStdRenderer:");
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
Gura_DeclareFunctionAlias(__RichTextStdRenderer, "RichTextStdRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStdRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextStdRenderer)
{
	//wxRichTextStdRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextStdRenderer, __DrawStandardBullet, "DrawStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStdRenderer, __DrawStandardBullet)
{
	Object_wx_RichTextStdRenderer *pThis = Object_wx_RichTextStdRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->DrawStandardBullet(paragraph, dc, attr, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStdRenderer, __DrawTextBullet, "DrawTextBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStdRenderer, __DrawTextBullet)
{
	Object_wx_RichTextStdRenderer *pThis = Object_wx_RichTextStdRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//const wxString& text = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->DrawTextBullet(paragraph, dc, attr, rect, text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStdRenderer, __DrawBitmapBullet, "DrawBitmapBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStdRenderer, __DrawBitmapBullet)
{
	Object_wx_RichTextStdRenderer *pThis = Object_wx_RichTextStdRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->DrawBitmapBullet(paragraph, dc, attr, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStdRenderer, __EnumerateStandardBulletNames, "EnumerateStandardBulletNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bulletNames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStdRenderer, __EnumerateStandardBulletNames)
{
	Object_wx_RichTextStdRenderer *pThis = Object_wx_RichTextStdRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& bulletNames = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->EnumerateStandardBulletNames(bulletNames);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStdRenderer, __MeasureBullet, "MeasureBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStdRenderer, __MeasureBullet)
{
	Object_wx_RichTextStdRenderer *pThis = Object_wx_RichTextStdRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//wxSize& sz = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->MeasureBullet(paragraph, dc, attr, sz);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStdRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStdRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextStdRenderer);
	// Method assignment
	Gura_AssignMethod(wx_RichTextStdRenderer, __DrawStandardBullet);
	Gura_AssignMethod(wx_RichTextStdRenderer, __DrawTextBullet);
	Gura_AssignMethod(wx_RichTextStdRenderer, __DrawBitmapBullet);
	Gura_AssignMethod(wx_RichTextStdRenderer, __EnumerateStandardBulletNames);
	Gura_AssignMethod(wx_RichTextStdRenderer, __MeasureBullet);
}

Gura_ImplementDescendantCreator(wx_RichTextStdRenderer)
{
	return new Object_wx_RichTextStdRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
