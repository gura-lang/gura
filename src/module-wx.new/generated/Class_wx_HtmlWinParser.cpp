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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlWinParser, "HtmlWinParser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "wndIface", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWinParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWinParser)
{
	//wxHtmlWindowInterface* wndIface = arg.GetNumber(0)
	//wxHtmlWinParser(wndIface);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlWinParser, __AddModule, "AddModule")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "module", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __AddModule)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlTagsModule* module = arg.GetNumber(0)
	//pThis->GetEntity()->AddModule(module);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __CloseContainer, "CloseContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __CloseContainer)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlContainerCell* _rtn = pThis->GetEntity()->CloseContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __CreateCurrentFont, "CreateCurrentFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __CreateCurrentFont)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont* _rtn = pThis->GetEntity()->CreateCurrentFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetActualColor, "GetActualColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetActualColor)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetActualColor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetAlign, "GetAlign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetAlign)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetAlign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetCharHeight, "GetCharHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetCharHeight)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCharHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetCharWidth, "GetCharWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetCharWidth)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCharWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetContainer)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlContainerCell* _rtn = pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetDC, "GetDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetDC)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC* _rtn = pThis->GetEntity()->GetDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetEncodingConverter, "GetEncodingConverter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetEncodingConverter)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEncodingConverter* _rtn = pThis->GetEntity()->GetEncodingConverter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetFontBold, "GetFontBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetFontBold)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFontBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetFontFace, "GetFontFace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetFontFace)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetFontFace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetFontFixed, "GetFontFixed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetFontFixed)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFontFixed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetFontItalic, "GetFontItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetFontItalic)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFontItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetFontSize, "GetFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetFontSize)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetFontUnderlined, "GetFontUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetFontUnderlined)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetInputEncoding, "GetInputEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetInputEncoding)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding _rtn = pThis->GetEntity()->GetInputEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetLink, "GetLink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetLink)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlLinkInfo& _rtn = pThis->GetEntity()->GetLink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetLinkColor, "GetLinkColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetLinkColor)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetLinkColor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetOutputEncoding, "GetOutputEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetOutputEncoding)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding _rtn = pThis->GetEntity()->GetOutputEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __GetWindowInterface, "GetWindowInterface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __GetWindowInterface)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlWindowInterface* _rtn = pThis->GetEntity()->GetWindowInterface();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __OpenContainer, "OpenContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWinParser, __OpenContainer)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlContainerCell* _rtn = pThis->GetEntity()->OpenContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetActualColor, "SetActualColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetActualColor)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetActualColor(clr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetAlign, "SetAlign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetAlign)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int a = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlign(a);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetContainer, "SetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetContainer)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlContainerCell* c = arg.GetNumber(0)
	//wxHtmlContainerCell* _rtn = pThis->GetEntity()->SetContainer(c);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetDC, "SetDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetDC)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC* dc = arg.GetNumber(0)
	//double pixel_scale = arg.GetNumber(1)
	//pThis->GetEntity()->SetDC(dc, pixel_scale);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFontBold, "SetFontBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFontBold)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontBold(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFontFace, "SetFontFace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFontFace)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& face = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFace(face);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFontFixed, "SetFontFixed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFontFixed)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFixed(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFontItalic, "SetFontItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFontItalic)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontItalic(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFontSize, "SetFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFontSize)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSize(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFontUnderlined, "SetFontUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFontUnderlined)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontUnderlined(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetFonts, "SetFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetFonts)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& normal_face = arg.GetNumber(0)
	//const wxString& fixed_face = arg.GetNumber(1)
	//const int* sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts(normal_face, fixed_face, sizes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetInputEncoding, "SetInputEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetInputEncoding)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding enc = arg.GetNumber(0)
	//pThis->GetEntity()->SetInputEncoding(enc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetLink, "SetLink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetLink)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlLinkInfo& link = arg.GetNumber(0)
	//pThis->GetEntity()->SetLink(link);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWinParser, __SetLinkColor, "SetLinkColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, __SetLinkColor)
{
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinkColor(clr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinParser)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlWinParser);
	// Method assignment
	Gura_AssignMethod(wx_HtmlWinParser, __AddModule);
	Gura_AssignMethod(wx_HtmlWinParser, __CloseContainer);
	Gura_AssignMethod(wx_HtmlWinParser, __CreateCurrentFont);
	Gura_AssignMethod(wx_HtmlWinParser, __GetActualColor);
	Gura_AssignMethod(wx_HtmlWinParser, __GetAlign);
	Gura_AssignMethod(wx_HtmlWinParser, __GetCharHeight);
	Gura_AssignMethod(wx_HtmlWinParser, __GetCharWidth);
	Gura_AssignMethod(wx_HtmlWinParser, __GetContainer);
	Gura_AssignMethod(wx_HtmlWinParser, __GetDC);
	Gura_AssignMethod(wx_HtmlWinParser, __GetEncodingConverter);
	Gura_AssignMethod(wx_HtmlWinParser, __GetFontBold);
	Gura_AssignMethod(wx_HtmlWinParser, __GetFontFace);
	Gura_AssignMethod(wx_HtmlWinParser, __GetFontFixed);
	Gura_AssignMethod(wx_HtmlWinParser, __GetFontItalic);
	Gura_AssignMethod(wx_HtmlWinParser, __GetFontSize);
	Gura_AssignMethod(wx_HtmlWinParser, __GetFontUnderlined);
	Gura_AssignMethod(wx_HtmlWinParser, __GetInputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, __GetLink);
	Gura_AssignMethod(wx_HtmlWinParser, __GetLinkColor);
	Gura_AssignMethod(wx_HtmlWinParser, __GetOutputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, __GetWindowInterface);
	Gura_AssignMethod(wx_HtmlWinParser, __OpenContainer);
	Gura_AssignMethod(wx_HtmlWinParser, __SetActualColor);
	Gura_AssignMethod(wx_HtmlWinParser, __SetAlign);
	Gura_AssignMethod(wx_HtmlWinParser, __SetContainer);
	Gura_AssignMethod(wx_HtmlWinParser, __SetDC);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFontBold);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFontFace);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFontFixed);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFontItalic);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFontSize);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFontUnderlined);
	Gura_AssignMethod(wx_HtmlWinParser, __SetFonts);
	Gura_AssignMethod(wx_HtmlWinParser, __SetInputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, __SetLink);
	Gura_AssignMethod(wx_HtmlWinParser, __SetLinkColor);
}

Gura_ImplementDescendantCreator(wx_HtmlWinParser)
{
	return new Object_wx_HtmlWinParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
