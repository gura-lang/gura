//----------------------------------------------------------------------------
// wxRichTextRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Object_wx_RichTextRenderer::~Object_wx_RichTextRenderer()
{
}

Object *Object_wx_RichTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRenderer:");
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
Gura_DeclareFunctionAlias(__RichTextRenderer, "RichTextRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextRenderer)
{
	//wxRichTextRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextRenderer, __DrawStandardBullet, "DrawStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __DrawStandardBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawStandardBullet(paragraph, dc, attr, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __DrawTextBullet, "DrawTextBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __DrawTextBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//const wxString& text = arg.GetNumber(4)
	//pThis->GetEntity()->DrawTextBullet(paragraph, dc, attr, rect, text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __DrawBitmapBullet, "DrawBitmapBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __DrawBitmapBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawBitmapBullet(paragraph, dc, attr, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __EnumerateStandardBulletNames, "EnumerateStandardBulletNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletNames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __EnumerateStandardBulletNames)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& bulletNames = arg.GetNumber(0)
	//pThis->GetEntity()->EnumerateStandardBulletNames(bulletNames);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRenderer, __MeasureBullet, "MeasureBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraph", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRenderer, __MeasureBullet)
{
	Object_wx_RichTextRenderer *pThis = Object_wx_RichTextRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraph* paragraph = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//wxSize& sz = arg.GetNumber(3)
	//pThis->GetEntity()->MeasureBullet(paragraph, dc, attr, sz);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextRenderer);
	// Method assignment
	Gura_AssignMethod(wx_RichTextRenderer, __DrawStandardBullet);
	Gura_AssignMethod(wx_RichTextRenderer, __DrawTextBullet);
	Gura_AssignMethod(wx_RichTextRenderer, __DrawBitmapBullet);
	Gura_AssignMethod(wx_RichTextRenderer, __EnumerateStandardBulletNames);
	Gura_AssignMethod(wx_RichTextRenderer, __MeasureBullet);
}

Gura_ImplementDescendantCreator(wx_RichTextRenderer)
{
	return new Object_wx_RichTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
