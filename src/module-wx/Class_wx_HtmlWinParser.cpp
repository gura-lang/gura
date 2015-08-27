//----------------------------------------------------------------------------
// wxHtmlWinParser
// extracted from htwinprs.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(CreateCurrentFont);
Gura_DeclarePrivUserSymbol(SetDC);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlWinParser: public wxHtmlWinParser, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlWinParser *_pObj;
public:
	inline wx_HtmlWinParser() : wxHtmlWinParser(), _pObj(nullptr) {}
	//inline wx_HtmlWinParser(wxHtmlWindowInterface *wndIface) : wxHtmlWinParser(*wndIface), _pObj(nullptr) {}
	//virtual wxFont* CreateCurrentFont();
	//virtual void SetDC(wxDC *dc, double pixel_scale);
	~wx_HtmlWinParser();
	inline void AssocWithGura(Object_wx_HtmlWinParser *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWinParser::~wx_HtmlWinParser()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlWinParser::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlWinParserEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWinParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlWinParserEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HtmlWinParser *pEntity = new wx_HtmlWinParser();
	Object_wx_HtmlWinParser *pObj = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlWinParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(HtmlWinParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlWinParser));
	DeclareArg(env, "*wndIface", VTYPE_wx_HtmlWindowInterface, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlWinParser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxHtmlWindowInterface **wndIface = Object_wx_HtmlWindowInterface::GetObject(args, 0)->GetEntity();
	wx_HtmlWinParser *pEntity = new wx_HtmlWinParser(**wndIface);
	Object_wx_HtmlWinParser *pObj = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlWinParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_HtmlWinParser, AddModule)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*module", VTYPE_wx_HtmlTagsModule, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_HtmlWinParser, AddModule)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxHtmlTagsModule **module = Object_wx_HtmlTagsModule::GetObject(args, 0)->GetEntity();
	wxHtmlWinParser::AddModule(**module);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, CloseContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, CloseContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pThis->GetEntity()->CloseContainer();
	return ReturnValue(env, args, Value(new Object_wx_HtmlContainerCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, CreateCurrentFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, CreateCurrentFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *rtn = (wxFont *)pThis->GetEntity()->CreateCurrentFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetActualColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetActualColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetActualColor();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetAlign)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetAlign();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetCharHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetCharHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCharHeight();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetCharWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetCharWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCharWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pThis->GetEntity()->GetContainer();
	return ReturnValue(env, args, Value(new Object_wx_HtmlContainerCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *rtn = (wxDC *)pThis->GetEntity()->GetDC();
	return ReturnValue(env, args, Value(new Object_wx_DC(rtn, nullptr, OwnerFalse)));
}

#if 0
Gura_DeclareMethod(wx_HtmlWinParser, GetEncodingConverter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetEncodingConverter)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEncodingConverter *rtn = (wxEncodingConverter *)pThis->GetEntity()->GetEncodingConverter();
	return ReturnValue(env, args, Value(new Object_wx_EncodingConverter(rtn, nullptr, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}
#endif

Gura_DeclareMethod(wx_HtmlWinParser, GetFontBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFontBold();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontFace)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFontFace();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontFixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFontFixed();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFontItalic();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFontSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFontUnderlined();
	return ReturnValue(env, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_HtmlWinParser, GetInputEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetInputEncoding)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding rtn = pThis->GetEntity()->GetInputEncoding();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}
#endif

Gura_DeclareMethod(wx_HtmlWinParser, GetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxHtmlLinkInfo &rtn = pThis->GetEntity()->GetLink();
	return ReturnValue(env, args, Value(new Object_wx_HtmlLinkInfo(new wxHtmlLinkInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetLinkColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetLinkColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetLinkColor();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

#if 0
Gura_DeclareMethod(wx_HtmlWinParser, GetOutputEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetOutputEncoding)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding rtn = pThis->GetEntity()->GetOutputEncoding();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}
#endif

#if 0
Gura_DeclareMethod(wx_HtmlWinParser, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlWindow *rtn = (wxHtmlWindow *)pThis->GetEntity()->GetWindow();
	return ReturnValue(env, args, Value(new Object_wx_HtmlWindow(rtn, nullptr, OwnerFalse)));
}
#endif

Gura_DeclareMethod(wx_HtmlWinParser, OpenContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, OpenContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pThis->GetEntity()->OpenContainer();
	return ReturnValue(env, args, Value(new Object_wx_HtmlContainerCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, SetActualColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetActualColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *clr = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetActualColor(*clr);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetAlign)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int a = args.GetInt(0);
	pThis->GetEntity()->SetAlign(a);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_HtmlContainerCell, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *c = Object_wx_HtmlContainerCell::GetObject(args, 0)->GetEntity();
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pThis->GetEntity()->SetContainer(c);
	return ReturnValue(env, args, Value(new Object_wx_HtmlContainerCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, SetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlWinParser, SetDC)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC **dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	double pixel_scale = 1.0;
	if (args.IsValid(1)) pixel_scale = args.GetDouble(1);
	pThis->GetEntity()->SetDC(**dc, pixel_scale);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	pThis->GetEntity()->SetFontBold(x);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontFace)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString face = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFontFace(face);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontFixed)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	pThis->GetEntity()->SetFontFixed(x);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	pThis->GetEntity()->SetFontItalic(x);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int s = args.GetInt(0);
	pThis->GetEntity()->SetFontSize(s);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	pThis->GetEntity()->SetFontUnderlined(x);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*sizes", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFonts)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString normal_face = wxString::FromUTF8(args.GetString(0));
	wxString fixed_face = wxString::FromUTF8(args.GetString(1));
	int *sizes = nullptr;
	if (args.IsValid(2)) *sizes = args.GetInt(2);
	pThis->GetEntity()->SetFonts(normal_face, fixed_face, *sizes);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

#if 0
Gura_DeclareMethod(wx_HtmlWinParser, SetInputEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetInputEncoding)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding enc = static_cast<wxFontEncoding>(args.GetInt(0));
	pThis->GetEntity()->SetInputEncoding(enc);
	return Value::Nil;
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}
#endif

Gura_DeclareMethod(wx_HtmlWinParser, SetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "link", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlLinkInfo *link = Object_wx_HtmlLinkInfo::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLink(*link);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetLinkColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetLinkColor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWinParser *pThis = Object_wx_HtmlWinParser::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *clr = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLinkColor(*clr);
	return Value::Nil;
}

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
// Class implementation for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinParser)
{
	Gura_RealizeUserSymbol(CreateCurrentFont);
	Gura_RealizeUserSymbol(SetDC);
	Gura_AssignFunction(HtmlWinParserEmpty);
	Gura_AssignFunction(HtmlWinParser);
	Gura_AssignMethod(wx_HtmlWinParser, AddModule);
	Gura_AssignMethod(wx_HtmlWinParser, CloseContainer);
	Gura_AssignMethod(wx_HtmlWinParser, CreateCurrentFont);
	Gura_AssignMethod(wx_HtmlWinParser, GetActualColor);
	Gura_AssignMethod(wx_HtmlWinParser, GetAlign);
	Gura_AssignMethod(wx_HtmlWinParser, GetCharHeight);
	Gura_AssignMethod(wx_HtmlWinParser, GetCharWidth);
	Gura_AssignMethod(wx_HtmlWinParser, GetContainer);
	Gura_AssignMethod(wx_HtmlWinParser, GetDC);
	//Gura_AssignMethod(wx_HtmlWinParser, GetEncodingConverter);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontBold);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontFace);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontFixed);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontItalic);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontSize);
	Gura_AssignMethod(wx_HtmlWinParser, GetFontUnderlined);
	//Gura_AssignMethod(wx_HtmlWinParser, GetInputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, GetLink);
	Gura_AssignMethod(wx_HtmlWinParser, GetLinkColor);
	//Gura_AssignMethod(wx_HtmlWinParser, GetOutputEncoding);
	//Gura_AssignMethod(wx_HtmlWinParser, GetWindow);
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
	//Gura_AssignMethod(wx_HtmlWinParser, SetInputEncoding);
	Gura_AssignMethod(wx_HtmlWinParser, SetLink);
	Gura_AssignMethod(wx_HtmlWinParser, SetLinkColor);
}

Gura_ImplementDescendantCreator(wx_HtmlWinParser)
{
	return new Object_wx_HtmlWinParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
