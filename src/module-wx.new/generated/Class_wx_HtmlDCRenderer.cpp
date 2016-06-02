//----------------------------------------------------------------------------
// wxHtmlDCRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlDCRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Object_wx_HtmlDCRenderer::~Object_wx_HtmlDCRenderer()
{
}

Object *Object_wx_HtmlDCRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlDCRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlDCRenderer:");
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
Gura_DeclareMethod(wx_HtmlDCRenderer, wxHtmlDCRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, wxHtmlDCRenderer)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlDCRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, GetTotalWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, GetTotalWidth)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, GetTotalHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, GetTotalHeight)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, Render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "known_pagebreaks", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dont_render", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, Render)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int known_pagebreaks = arg.GetNumber(2)
	//int from = arg.GetNumber(3)
	//int dont_render = arg.GetNumber(4)
	//int to = arg.GetNumber(5)
	//pThis->GetEntity()->Render();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetDC)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pixel_scale = arg.GetNumber(1)
	//pThis->GetEntity()->SetDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetFonts)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetStandardFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetStandardFonts)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int normal_face = arg.GetNumber(1)
	//int fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetHtmlText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isdir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetHtmlText)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int html = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//int isdir = arg.GetNumber(2)
	//pThis->GetEntity()->SetHtmlText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlDCRenderer, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, SetSize)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlDCRenderer)
{
	Gura_AssignMethod(wx_HtmlDCRenderer, wxHtmlDCRenderer);
	Gura_AssignMethod(wx_HtmlDCRenderer, GetTotalWidth);
	Gura_AssignMethod(wx_HtmlDCRenderer, GetTotalHeight);
	Gura_AssignMethod(wx_HtmlDCRenderer, Render);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetDC);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetFonts);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetStandardFonts);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetHtmlText);
	Gura_AssignMethod(wx_HtmlDCRenderer, SetSize);
}

Gura_ImplementDescendantCreator(wx_HtmlDCRenderer)
{
	return new Object_wx_HtmlDCRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
