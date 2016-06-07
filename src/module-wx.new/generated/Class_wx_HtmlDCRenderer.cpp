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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlDCRenderer, "HtmlDCRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlDCRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlDCRenderer)
{
	//wxHtmlDCRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __GetTotalWidth, "GetTotalWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __GetTotalWidth)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __GetTotalHeight, "GetTotalHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __GetTotalHeight)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __Render, "Render")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "known_pagebreaks", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dont_render", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __Render)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxArrayInt& known_pagebreaks = arg.GetNumber(2)
	//int from = arg.GetNumber(3)
	//int dont_render = arg.GetNumber(4)
	//int to = arg.GetNumber(5)
	//pThis->GetEntity()->Render(x, y, known_pagebreaks, from, dont_render, to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __SetDC, "SetDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __SetDC)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC* dc = arg.GetNumber(0)
	//double pixel_scale = arg.GetNumber(1)
	//pThis->GetEntity()->SetDC(dc, pixel_scale);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __SetFonts, "SetFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __SetFonts)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& normal_face = arg.GetNumber(0)
	//const wxString& fixed_face = arg.GetNumber(1)
	//const int* sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts(normal_face, fixed_face, sizes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __SetStandardFonts, "SetStandardFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __SetStandardFonts)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//const wxString& normal_face = arg.GetNumber(1)
	//const wxString& fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts(size, normal_face, fixed_face);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __SetHtmlText, "SetHtmlText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isdir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __SetHtmlText)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& html = arg.GetNumber(0)
	//const wxString& basepath = arg.GetNumber(1)
	//bool isdir = arg.GetNumber(2)
	//pThis->GetEntity()->SetHtmlText(html, basepath, isdir);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlDCRenderer, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlDCRenderer, __SetSize)
{
	Object_wx_HtmlDCRenderer *pThis = Object_wx_HtmlDCRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetSize(width, height);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlDCRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlDCRenderer);
	// Method assignment
	Gura_AssignMethod(wx_HtmlDCRenderer, __GetTotalWidth);
	Gura_AssignMethod(wx_HtmlDCRenderer, __GetTotalHeight);
	Gura_AssignMethod(wx_HtmlDCRenderer, __Render);
	Gura_AssignMethod(wx_HtmlDCRenderer, __SetDC);
	Gura_AssignMethod(wx_HtmlDCRenderer, __SetFonts);
	Gura_AssignMethod(wx_HtmlDCRenderer, __SetStandardFonts);
	Gura_AssignMethod(wx_HtmlDCRenderer, __SetHtmlText);
	Gura_AssignMethod(wx_HtmlDCRenderer, __SetSize);
}

Gura_ImplementDescendantCreator(wx_HtmlDCRenderer)
{
	return new Object_wx_HtmlDCRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
