//----------------------------------------------------------------------------
// wxHtmlWinParser
// extracted from htwinprs.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(CreateCurrentFont);
Gura_DeclarePrivUserSymbol(SetDC);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlWinParser: public wxHtmlWinParser, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlWinParser *_pObj;
public:
	inline wx_HtmlWinParser() : wxHtmlWinParser(), _sig(NULL), _pObj(NULL) {}
	//inline wx_HtmlWinParser(wxHtmlWindowInterface *wndIface) : wxHtmlWinParser(*wndIface), _sig(NULL), _pObj(NULL) {}
	//virtual wxFont* CreateCurrentFont();
	//virtual void SetDC(wxDC *dc, double pixel_scale);
	~wx_HtmlWinParser();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlWinParser *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWinParser::~wx_HtmlWinParser()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlWinParser::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlWinParserEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWinParser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlWinParserEmpty)
{
	wx_HtmlWinParser *pEntity = new wx_HtmlWinParser();
	Object_wx_HtmlWinParser *pObj = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlWinParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(HtmlWinParser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlWinParser));
	DeclareArg(env, "*wndIface", VTYPE_wx_HtmlWindowInterface, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlWinParser)
{
#if 0
	wxHtmlWindowInterface **wndIface = Object_wx_HtmlWindowInterface::GetObject(args, 0)->GetEntity();
	wx_HtmlWinParser *pEntity = new wx_HtmlWinParser(**wndIface);
	Object_wx_HtmlWinParser *pObj = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlWinParser(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_HtmlWinParser, AddModule)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*module", VTYPE_wx_HtmlTagsModule, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_HtmlWinParser, AddModule)
{
#if 0
	wxHtmlTagsModule **module = Object_wx_HtmlTagsModule::GetObject(args, 0)->GetEntity();
	wxHtmlWinParser::AddModule(**module);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, CloseContainer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, CloseContainer)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pSelf->GetEntity()->CloseContainer();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlContainerCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, CreateCurrentFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, CreateCurrentFont)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *rtn = (wxFont *)pSelf->GetEntity()->CreateCurrentFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetActualColor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetActualColor)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetActualColor();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetAlign)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetAlign)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetAlign();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetCharHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetCharHeight)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCharHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetCharWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetCharWidth)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCharWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetContainer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetContainer)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pSelf->GetEntity()->GetContainer();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlContainerCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetDC)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetDC)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *rtn = (wxDC *)pSelf->GetEntity()->GetDC();
	return ReturnValue(env, sig, args, Value(new Object_wx_DC(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetEncodingConverter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetEncodingConverter)
{
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEncodingConverter *rtn = (wxEncodingConverter *)pSelf->GetEntity()->GetEncodingConverter();
	return ReturnValue(env, sig, args, Value(new Object_wx_EncodingConverter(rtn, NULL, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontBold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontBold)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontBold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontFace)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontFace)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFontFace();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontFixed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontFixed)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontFixed();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontItalic)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontItalic)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontItalic();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontSize)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetFontUnderlined)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetFontUnderlined)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontUnderlined();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetInputEncoding)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetInputEncoding)
{
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontEncoding rtn = pSelf->GetEntity()->GetInputEncoding();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_HtmlWinParser, GetLink)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetLink)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxHtmlLinkInfo &rtn = pSelf->GetEntity()->GetLink();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlLinkInfo(new wxHtmlLinkInfo(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetLinkColor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetLinkColor)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetLinkColor();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlWinParser, GetOutputEncoding)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetOutputEncoding)
{
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontEncoding rtn = pSelf->GetEntity()->GetOutputEncoding();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_HtmlWinParser, GetWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, GetWindow)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlWindow *rtn = (wxHtmlWindow *)pSelf->GetEntity()->GetWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlWindow(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, OpenContainer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, OpenContainer)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pSelf->GetEntity()->OpenContainer();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlContainerCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, SetActualColor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetActualColor)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *clr = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetActualColor(*clr);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetAlign)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetAlign)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int a = args.GetInt(0);
	pSelf->GetEntity()->SetAlign(a);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetContainer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_HtmlContainerCell, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetContainer)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlContainerCell *c = Object_wx_HtmlContainerCell::GetObject(args, 0)->GetEntity();
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pSelf->GetEntity()->SetContainer(c);
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlContainerCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWinParser, SetDC)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlWinParser, SetDC)
{
#if 0
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC **dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	double pixel_scale = 1.0;
	if (args.IsValid(1)) pixel_scale = args.GetDouble(1);
	pSelf->GetEntity()->SetDC(**dc, pixel_scale);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontBold)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontBold)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	pSelf->GetEntity()->SetFontBold(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontFace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "face", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontFace)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString face = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetFontFace(face);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontFixed)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontFixed)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	pSelf->GetEntity()->SetFontFixed(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontItalic)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontItalic)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	pSelf->GetEntity()->SetFontItalic(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontSize)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int s = args.GetInt(0);
	pSelf->GetEntity()->SetFontSize(s);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFontUnderlined)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFontUnderlined)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	pSelf->GetEntity()->SetFontUnderlined(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetFonts)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*sizes", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlWinParser, SetFonts)
{
#if 0
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString normal_face = wxString::FromUTF8(args.GetString(0));
	wxString fixed_face = wxString::FromUTF8(args.GetString(1));
	int *sizes = NULL;
	if (args.IsValid(2)) *sizes = args.GetInt(2);
	pSelf->GetEntity()->SetFonts(normal_face, fixed_face, *sizes);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetInputEncoding)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetInputEncoding)
{
#if defined(__WXMSW__)
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFontEncoding enc = static_cast<wxFontEncoding>(args.GetInt(0));
	pSelf->GetEntity()->SetInputEncoding(enc);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_HtmlWinParser, SetLink)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "link", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetLink)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlLinkInfo *link = Object_wx_HtmlLinkInfo::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetLink(*link);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlWinParser, SetLinkColor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "clr", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWinParser, SetLinkColor)
{
	Object_wx_HtmlWinParser *pSelf = Object_wx_HtmlWinParser::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *clr = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetLinkColor(*clr);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWinParser
//----------------------------------------------------------------------------
Object_wx_HtmlWinParser::~Object_wx_HtmlWinParser()
{
}

Object *Object_wx_HtmlWinParser::Clone() const
{
	return NULL;
}

String Object_wx_HtmlWinParser::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlWinParser:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlWinParser::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(CreateCurrentFont);
	Gura_RealizeUserSymbol(SetDC);
	Gura_AssignFunction(HtmlWinParserEmpty);
	Gura_AssignFunction(HtmlWinParser);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinParser)
{
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
	Gura_AssignMethod(wx_HtmlWinParser, GetWindow);
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
	return new Object_wx_HtmlWinParser((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
