//----------------------------------------------------------------------------
// wxHtmlWinParser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWinParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWinParser
//----------------------------------------------------------------------------
Object_wx_HtmlWinParser::~Object_wx_HtmlWinParser()
{
}

Object *Object_wx_HtmlWinParser::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWinParser::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWinParser:");
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
Gura_DeclareMethod(wx_HtmlWinParser, wxHtmlWinParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wndIface", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, wxHtmlWinParser)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wndIface = arg.GetNumber(0)
	//pThis->GetEntity()->wxHtmlWinParser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, AddModule)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "module", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, AddModule)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int module = arg.GetNumber(0)
	//pThis->GetEntity()->AddModule();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, CloseContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, CloseContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CloseContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, CreateCurrentFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, CreateCurrentFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateCurrentFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetActualColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetActualColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetActualColor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetAlign)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAlign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetCharHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetCharHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCharHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetCharWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetCharWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCharWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetEncodingConverter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetEncodingConverter)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEncodingConverter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontFace)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontFace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontFixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontFixed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetInputEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetInputEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInputEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetLinkColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetLinkColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLinkColor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetOutputEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetOutputEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOutputEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, GetWindowInterface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetWindowInterface)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWindowInterface();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, OpenContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, OpenContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OpenContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetActualColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetActualColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetActualColor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetAlign)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pixel_scale = arg.GetNumber(1)
	//pThis->GetEntity()->SetDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontFace)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int face = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontFixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFixed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFonts)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetInputEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetInputEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//pThis->GetEntity()->SetInputEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->SetLink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetLinkColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetLinkColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinkColor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinParser)
{
	Gura_AssignMethod(wx_HtmlWinParser, wxHtmlWinParser);
	Gura_AssignMethod(wx_HtmlWinParser, AddModule);
	Gura_AssignMethod(wx_HtmlWinParser, CloseContainer);
	Gura_AssignMethod(wx_HtmlWinParser, CreateCurrentFont);
	Gura_AssignMethod(wx_HtmlWinParser, GetActualColor);
	Gura_AssignMethod(wx_HtmlWinParser, GetAlign);
	Gura_AssignMethod(wx_HtmlWinParser, GetCharHeight);
	Gura_AssignMethod(wx_HtmlWinParser, GetCharWidth);
	Gura_AssignMethod(wx_HtmlWinParser, GetContainer);
	Gura_AssignMethod(wx_HtmlWinParser, GetDC);
	Gura_AssignMethod(wx_HtmlWinParser, GetEncodingConverter);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontBold);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontFace);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontFixed);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontItalic);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontSize);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontUnderlined);
	Gura_AssignMethod(wx_HtmlWinParser, GetInputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, GetLink);
	Gura_AssignMethod(wx_HtmlWinParser, GetLinkColor);
	Gura_AssignMethod(wx_HtmlWinParser, GetOutputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, GetWindowInterface);
	Gura_AssignMethod(wx_HtmlWinParser, OpenContainer);
	Gura_AssignMethod(wx_HtmlWinParser, SetActualColor);
	Gura_AssignMethod(wx_HtmlWinParser, SetAlign);
	Gura_AssignMethod(wx_HtmlWinParser, SetContainer);
	Gura_AssignMethod(wx_HtmlWinParser, SetDC);
	Gura_AssignMethod(wx_HtmlWinParser, SetFontBold);
	Gura_AssignMethod(wx_HtmlWinParser, SetFontFace);
	Gura_AssignMethod(wx_HtmlWinParser, SetFontFixed);
	Gura_AssignMethod(wx_HtmlWinParser, SetFontItalic);
	Gura_AssignMethod(wx_HtmlWinParser, SetFontSize);
	Gura_AssignMethod(wx_HtmlWinParser, SetFontUnderlined);
	Gura_AssignMethod(wx_HtmlWinParser, SetFonts);
	Gura_AssignMethod(wx_HtmlWinParser, SetInputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, SetLink);
	Gura_AssignMethod(wx_HtmlWinParser, SetLinkColor);
}

Gura_ImplementDescendantCreator(wx_HtmlWinParser)
{
	return new Object_wx_HtmlWinParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
